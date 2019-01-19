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

IMonitorDisplay::IMonitorDisplay(std::vector<IMonitorModule> const &modules)
	: _modules(modules) { }

IMonitorDisplay::~IMonitorDisplay() { }

int IMonitorDisplay::init() {
	for (size_t i = 0; i < _modules.size(); i++) {
		int const err = _modules[i].init();
		if (err) return err;
	}

	return 0;
}

int IMonitorDisplay::exit() {
	for (size_t i = 0; i < _modules.size(); i++) {
		int const err = _modules[i].exit();
		if (err) return err;
	}

	return 0;
}

int IMonitorDisplay::show() {
	throw std::logic_error("Function not yet implemented");
}

int IMonitorDisplay::draw(int line, int column, const char *fmt, ...) {
	(void)line;
	(void)column;
	(void)fmt;
	throw std::logic_error("Function not yet implemented");
}
