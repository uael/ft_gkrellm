/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.h"

#include <stdexcept>

IMonitorDisplay::IMonitorDisplay(enum MonitorDisplayType type)
	: _type(type) { }

IMonitorDisplay::~IMonitorDisplay() { }

enum MonitorDisplayType IMonitorDisplay::getType() const {
	return _type;
}

int IMonitorDisplay::init() {
	throw std::logic_error("Function not yet implemented");
}

int IMonitorDisplay::exit() {
	throw std::logic_error("Function not yet implemented");
}

int IMonitorDisplay::draw(int line, int column, const char *fmt, ...) {
	(void)line;
	(void)column;
	(void)fmt;
	throw std::logic_error("Function not yet implemented");
}
