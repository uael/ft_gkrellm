/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/Modules.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MONITORMODULE_MODULES_H
# define __MONITORMODULE_MODULES_H

#include "IMonitorModule.h"
#include "IMonitorDisplay.h"

#include <vector>
#include <sys/utsname.h>

class HostnameModule : public IMonitorModule {
public:
	HostnameModule();
	~HostnameModule();

	int pump(IMonitorDisplay &display);
};

class CPUModule : public IMonitorModule {
private:
	std::vector<float> _plot;
	clock_t _clock;

public:
	CPUModule();
	~CPUModule();

	int pump(IMonitorDisplay &display);
};

class OSInfoModule : public IMonitorModule {
private:
	struct utsname _uts;

public:
	OSInfoModule();
	~OSInfoModule();

	int init();
	int pump(IMonitorDisplay &display);
};

class RAMModule : public IMonitorModule {
private:
	int64_t total_ram;
	int64_t used_ram;
	int64_t wired_ram;
	int64_t free_ram;
	std::vector<float> _used_plot;
	std::vector<float> _wired_plot;
	clock_t _clock;

public:
	RAMModule();
	~RAMModule();

	int init();
	int pump(IMonitorDisplay &display);
};

class TimeModule : public IMonitorModule {
public:
	TimeModule();
	~TimeModule();

	int pump(IMonitorDisplay &display);
};

class NetworkModule : public IMonitorModule {
private:
	clock_t _clock;
	std::string _data;

public:
	NetworkModule();
	~NetworkModule();

	int pump(IMonitorDisplay &display);
};

class DiskModule : public IMonitorModule {
private:
	clock_t _clock;
	std::string _data;

public:
	DiskModule();
	~DiskModule();

	int pump(IMonitorDisplay &display);
};

#endif /* !__MONITORMODULE_MODULES_H */
