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

#define ALLEGRO_NO_MAGIC_MAIN
#include "DisplayModule/ImgUI.h"
#include "MonitorModule/Modules.h"

#include <iostream>

int real_main(int argc, char **argv) {
	std::vector<IMonitorModule *> modules = std::vector<IMonitorModule *>();
	HostnameModule hostname = HostnameModule();
	modules.push_back(&hostname);
	CPUModule CPU = CPUModule();
	modules.push_back(&CPU);
	ImgUIMonitorDisplay display(modules);

	(void)argc;
	(void)argv;
	if (display.init())
		return 1;
	if (display.show())
		return 1;
	if (display.exit())
		return 1;
	return 0;
}

int main(int argc, char **argv) {
	return al_run_main(argc, argv, real_main);
}
