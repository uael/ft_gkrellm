/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:17:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 14:04:09 by ygarrot          ###   ########.fr       */
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

//TODO : make a function that take a string and return buf
std::string		CPUModule::getAvailableCPU(void) const
{
	char buf[100];
	size_t buflen = 100;

	sysctlbyname("hw.physicalcpu", &buf, &buflen, NULL, 0);
	return buf;
}

std::string		CPUModule::getCPUNumber(void) const
{
	char buf[100];
	size_t buflen = 100;

	sysctlbyname("hw.physicalcpu_max", &buf, &buflen, NULL, 0);
	return std::string(buf);
}

std::string		CPUModule::getCPUFrequ(void) const
{
	char buf[100];
	size_t buflen = 100;

	sysctlbyname("hw.cpufrequency", &buf, &buflen, NULL, 0);
	return std::string(buf);
}

std::string CPUModule::getCPUName(void) const
{
	char buf[100];
	size_t buflen = 100;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	return buf;
}
