/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:17:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 13:54:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CPUModule.hpp"

CPUModule::CPUModule(std::string target) 
{
}

CPUModule::CPUModule() 
{

}

CPUModule::~CPUModule() 
{

}

CPUModule::CPUModule(CPUModule const &src)
{
	*this = src;
}

CPUModule     &CPUModule::operator=(CPUModule const & src) 
{
	(void)src;
	return *this;
}


int		CPUModule::getAvailableCPU(void) const
{
	int mib[4];
	int numCPU;
	std::size_t len = sizeof(numCPU); 

	mib[0] = CTL_HW;
	mib[1] = HW_NCPU;
	sysctl(mib, 2, &numCPU, &len, NULL, 0);
	return numCPU;
}

int		CPUModule::getCPUNumber(void) const
{
	int mib[4];
	int numCPU;
	std::size_t len = sizeof(numCPU); 

	/* set the mib for hw.ncpu */
	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;
	/* get the number of CPUs from the system */
	sysctl(mib, 2, &numCPU, &len, NULL, 0);
	return numCPU;
}

int		CPUModule::getCPUFrequ(void) const
{

	int mib[4];
	int freq;
	std::size_t len = sizeof(freq); 

	mib[0] = CTL_HW;
	mib[1] = HW_CPU_FREQ;
	sysctl(mib, 2, &freq, &len, NULL, 0);
	return freq;
}

std::string CPUModule::getCPUName(void) const
{
	char buf[100];
	size_t buflen = 100;
		sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

		return buf;
}
