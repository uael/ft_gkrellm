/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.h"

Monitor::Monitor(std::vector<IMonitorModule> const &modules)
	: _modules(modules) { }

Monitor::~Monitor() { }

int Monitor::init() {
	return 0;
}

int Monitor::exit() {
	return 0;
}

int Monitor::show() {
	return 0;
}
