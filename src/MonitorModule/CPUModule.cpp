/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:17:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 17:58:56 by ygarrot          ###   ########.fr       */
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
// throw exception


std::string		CPUModule::getAvailableCPU(void) const
{
	uint64_t cpu = 0;
	    size_t size = sizeof(cpu);

	sysctlbyname("hw.physicalcpu", &cpu, &size, NULL, 0);
	return std::to_string(cpu);
}

std::string		CPUModule::getCPUNumber(void) const
{
	uint64_t cpu = 0;
	    size_t size = sizeof(cpu);

	sysctlbyname("hw.physicalcpu_max", &cpu, &size, NULL, 0);
	return std::to_string(cpu);
}

std::string		CPUModule::getCPUFrequ(void) const
{
	uint64_t freq = 0;
	    size_t size = sizeof(freq);

	sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0);
	return std::to_string(freq);
}

std::string CPUModule::getCPUName(void) const
{
	char buf[100];
	size_t buflen = 100;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	return buf;
}

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.
float CPUModule::GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	unsigned long long totalTicks = 0;

	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		for(int i=0; i<CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}

float CPUModule::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);

	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}
