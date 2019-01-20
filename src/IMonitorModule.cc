/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:06:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"

#include <stdexcept>
#include <cstdio>
#include <cerrno>

IMonitorModule::IMonitorModule(const std::string name)
	: _name(name) { }

IMonitorModule::~IMonitorModule() { }

const std::string IMonitorModule::getName() const {
	return _name;
}

IMonitorModule::IMonitorModule(IMonitorModule const &src)
{
	*this = src;
}

IMonitorModule     &IMonitorModule::operator=(IMonitorModule const & src) 
{
	(void)src;
	return *this;
}

int IMonitorModule::init() {
	return 0;
}

int IMonitorModule::exit() {
	return 0;
}

int IMonitorModule::pump(IMonitorDisplay &display) {
	(void)display;
	throw std::logic_error("Function not yet implemented");
}

IMonitorModule::IMonitorModule(IMonitorModule const &src)
	: _name(src._name) {
	*this = src;
}

IMonitorModule &IMonitorModule::operator=(IMonitorModule const &src) {
	(void)src;
	return *this;
}
