/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/Network.cc                           :+:      :+:    :+:   */
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

DiskModule::DiskModule()
	: IMonitorModule("Disk"), _clock(), _data() { }

DiskModule::~DiskModule() { }

int DiskModule::pump(IMonitorDisplay &display) {
	clock_t now = clock();
	if (!_clock || ((double)(now - _clock) / CLOCKS_PER_SEC >= 1)) {
		FILE *fp;
		int status;
		char path[4096];

		fp = popen("top -l1 -n0 | grep -E \"^Disks\" | sed 's|Disks: ||g'",
		           "r");
		if (fp == nullptr)
			throw std::exception();
		while (fgets(path, sizeof path, fp) != NULL)
			;
		status = pclose(fp);
		if (status == -1)
			throw std::exception();
		_data = path;
		_clock = now;
	}
	display.draw(_data.c_str());
	return 0;
}
