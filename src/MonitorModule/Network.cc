/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/Network.cc                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:23:15 by ygarrot          ###   ########.fr       */
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

NetworkModule::NetworkModule()
	: IMonitorModule("Network"), _clock(), _data() { }

NetworkModule::~NetworkModule() { }


NetworkModule::NetworkModule(NetworkModule const &src): IMonitorModule("Network"), _clock(), _data() 
{
	*this = src;
}

NetworkModule     &NetworkModule::operator=(NetworkModule const & src) 
{
	(void)src;
	this->_clock = src._clock;
	this->_data = src._data;
	return *this;
}

int NetworkModule::pump(IMonitorDisplay &display) {
	clock_t now = clock();
	if (!_clock || ((double)(now - _clock) / CLOCKS_PER_SEC >= 1)) {
		FILE *fp;
		int status;
		char path[4096];

		fp = popen("top -l1 -n0 | grep -E \"^Networks\" | sed 's|Networks: ||g'",
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
