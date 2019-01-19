/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"

#include <stdexcept>

IMonitorModule::IMonitorModule(const std::string name)
	: _name(name) { }

IMonitorModule::~IMonitorModule() { }

const std::string IMonitorModule::getName() const {
	return _name;
}

int IMonitorModule::init() {
	throw std::logic_error("Function not yet implemented");
}

int IMonitorModule::exit() {
	throw std::logic_error("Function not yet implemented");
}

int IMonitorModule::pump(IMonitorDisplay &display) {
	(void)display;
	throw std::logic_error("Function not yet implemented");
}
