/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/RAM.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
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
#include <mach/notify.h>
#include <mach/vm_statistics.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

RAMModule::RAMModule()
	: IMonitorModule("Memory"),
	  total_ram(), used_ram(), wired_ram(), free_ram(),
	  _used_plot(), _wired_plot(), _clock() { }

RAMModule::~RAMModule() { }

int RAMModule::init() {
	int mib[2];
	size_t length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	return sysctl(mib, 2, &total_ram, &length, nullptr, 0);
}

int RAMModule::pump(IMonitorDisplay &display) {
	clock_t now = clock();

	if (!_clock || ((double)(now - _clock) / CLOCKS_PER_SEC >= 0.1)) {
		vm_size_t page_size;
		mach_port_t mach_port;
		mach_msg_type_number_t count;
		vm_statistics64_data_t vm_stats = { };

		mach_port = mach_host_self();
		count = sizeof(vm_stats) / sizeof(natural_t);
		if (host_page_size(mach_port, &page_size) == KERN_SUCCESS &&
		    host_statistics64(mach_port, HOST_VM_INFO, reinterpret_cast<
			    host_info64_t>(&vm_stats), &count) == KERN_SUCCESS) {
			used_ram = (static_cast<int64_t>(vm_stats.active_count) +
			            static_cast<int64_t>(vm_stats.inactive_count)) *
			           static_cast<int64_t>(page_size);
			wired_ram = static_cast<int64_t>(vm_stats.wire_count) *
			            static_cast<int64_t>(page_size);
			free_ram = total_ram - used_ram;
		}

		_used_plot.push_back(used_ram);
		_wired_plot.push_back(wired_ram);

		_clock = now;
	}

	/* Pop value */
	if (_used_plot.size() > 50) {
		_used_plot.front() = std::move(_used_plot.back());
		_used_plot.pop_back();
	}

	display.draw("RAM : %.2lf/%.2lfGB",
		(double)used_ram / (1024*1024*1024),
		(double)total_ram / (1024*1024*1024));
	display.plot(_used_plot.data(), _used_plot.size());

	/* Pop value */
	if (_wired_plot.size() > 50) {
		_wired_plot.front() = std::move(_wired_plot.back());
		_wired_plot.pop_back();
	}

	display.draw("WIRED : %.2lf/%.2lfGB",
		(double)wired_ram / (1024*1024*1024),
		(double)total_ram / (1024*1024*1024));
	display.plot(_wired_plot.data(), _wired_plot.size());
	return 0;
}
