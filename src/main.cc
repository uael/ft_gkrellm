/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayModule/ImgUI.h"

#include <iostream>

int main() {
	std::vector<IMonitorModule> modules = std::vector<IMonitorModule>();
	ImgUIMonitorDisplay display(modules);

	if (display.init())
		return 1;
	if (display.show())
		return 1;
	if (display.exit())
		return 1;
	return 0;
}
