/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/CPU.cc                               :+:      :+:    :+:   */
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

RAMModule::RAMModule() : IMonitorModule("Memory"), total_ram() { }

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

	display.draw("%s", "yay");
	return 0;
}
