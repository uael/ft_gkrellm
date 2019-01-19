/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayModule/ImgUI.cc                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ImgUI.h"

ImgUI::ImgUI(std::vector<IMonitorModule> const &modules)
	: IMonitorDisplay(modules) {

}

ImgUI::~ImgUI() {

}

int ImgUI::init() {
	return IMonitorDisplay::init();
}

int ImgUI::exit() {
	return IMonitorDisplay::exit();
}

int ImgUI::show() {
	return 0;
}

int ImgUI::draw(const char *fmt, ...) {
	return IMonitorDisplay::draw(fmt);
}

int ImgUI::plot(const float *values, size_t nvalues) {
	return IMonitorDisplay::plot(values, nvalues);
}
