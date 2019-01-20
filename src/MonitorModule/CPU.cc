/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/CPU.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:13:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Modules.h"
#include "IMonitorDisplay.h"

#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

#include <sys/types.h>
#include <sys/sysctl.h>

CPUModule::CPUModule() : IMonitorModule("CPU"), _plot(), _clock() { }

CPUModule::~CPUModule() { }

CPUModule::CPUModule(CPUModule const &src): IMonitorModule("CPU"), _plot(), _clock()
{
	*this = src;
}

CPUModule     &CPUModule::operator=(CPUModule const & src) 
{
	(void)src;
	this->_plot = std::vector<float>(src._plot);
	this->_clock = src._clock;
	return *this;
}


int CPUModule::pump(IMonitorDisplay &display) {
	char cpu[256];
	size_t size = sizeof(cpu);

	if (sysctlbyname("machdep.cpu.brand_string", &cpu, &size, nullptr, 0) < 0) {
		display.draw("error");
		return 0;
	}

	int core_count;
	int thread_count;
	if (sysctlbyname("machdep.cpu.core_count",
	                 &core_count, &size, nullptr, 0) < 0)
		core_count = 0;
	if (sysctlbyname("machdep.cpu.thread_count",
	                 &thread_count, &size, nullptr, 0) < 0)
		thread_count = 0;

	display.draw("%s (%dC/%dT)", cpu, core_count, thread_count);

	double load[3] = { 0, 0, 0 };
	getloadavg(load, 3);

	clock_t now = clock();
	if (!_clock || ((double)(now - _clock) / CLOCKS_PER_SEC >= 0.05)) {
		_plot.push_back(static_cast<float const &>(load[0]));
		_clock = now;
	}

	/* Pop value */
	while (_plot.size() > 50)
		_plot.erase(_plot.begin());

	display.draw("Load : %.2f, %.2f, %.2f", load[0], load[1], load[2]);
	display.plot(_plot.data(), _plot.size(),
		*std::min_element(_plot.begin(), _plot.end()),
		*std::max_element(_plot.begin(), _plot.end()));

	return 0;
}
