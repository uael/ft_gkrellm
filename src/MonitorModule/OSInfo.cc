/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/OSInfo.cc                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:13:58 by ygarrot          ###   ########.fr       */
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

OSInfoModule::OSInfoModule() : IMonitorModule("OS"), _uts() { }

OSInfoModule::~OSInfoModule() { }

OSInfoModule::OSInfoModule(OSInfoModule const &src): IMonitorModule("OSInfo"), _uts()
{
	*this = src;
}

OSInfoModule     &OSInfoModule::operator=(OSInfoModule const & src) 
{
	(void)src;
	this->_uts = src._uts;
	return *this;
}

int OSInfoModule::init() {
	return uname(&_uts);
}

int OSInfoModule::pump(IMonitorDisplay &display) {
	char *str;

	str = strchr(_uts.version, ';');
	if (str)
		*str = 0;
	display.draw("%s", _uts.version);
	if (str)
		display.draw("%s", str + 2);
	return 0;
}
