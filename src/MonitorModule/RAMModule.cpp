/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:22:38 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 14:41:30 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"

RAMModule::RAMModule(std::string target) 
{
}

RAMModule::RAMModule() 
{

}

RAMModule::~RAMModule() 
{

}

RAMModule::RAMModule(RAMModule const &src)
{
	*this = src;
}

RAMModule     &RAMModule::operator=(RAMModule const & src) 
{
	(void)src;
	return *this;
}

static double ParseMemValue(const char * b)
{
	while((*b)&&(isdigit(*b) == false)) b++;
	return isdigit(*b) ? atof(b) : -1.0;
}

// Returns a number between 0.0f and 1.0f, with 0.0f meaning all RAM is available, and 1.0f meaning all RAM is currently in use
float RAMModule::GetSystemMemoryUsagePercentage() const
{
	double pagesUsed = 0.0, totalPages = 0.0;
	char buf[512];
	FILE * fpIn = popen("/usr/bin/vm_stat", "r");

	if (fpIn)
	{
		while(fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;  // Stop at "Translation Faults", we don't care about anything at or below that
		}
		pclose(fpIn);

		if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
	}
	return -1.0f;  // indicate failure
}
