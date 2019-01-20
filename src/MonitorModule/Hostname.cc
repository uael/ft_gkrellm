/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/Hostname.cc                          :+:      :+:    :+:   */
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

HostnameModule::HostnameModule() : IMonitorModule("Hostname") { }

HostnameModule::~HostnameModule() { }

int HostnameModule::pump(IMonitorDisplay &display) {
	char name[_POSIX_HOST_NAME_MAX];

	gethostname(name, _POSIX_HOST_NAME_MAX);
	display.draw("host: %s", name);
	getlogin_r(name, _POSIX_LOGIN_NAME_MAX);
	display.draw("name: %s", name);
	return 0;
}
