/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/19 22:59:23 by ygarrot          ###   ########.fr       */
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

int IMonitorDisplay::draw(const char *fmt, ...) {
	(void)fmt;
	throw std::logic_error("Function not yet implemented");
}

int IMonitorDisplay::plot(const float *values, size_t nvalues) {
	(void)values;
	(void)nvalues;
	throw std::logic_error("Function not yet implemented");
}
