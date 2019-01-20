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
#include "DisplayModule/ncurses/Ncurses.hpp"
#include "MonitorModule/Modules.h"

#include <iostream>

int real_main(int argc, char **argv) {
	std::vector<IMonitorModule *> modules = std::vector<IMonitorModule *>();

	HostnameModule Hostname = HostnameModule();
	modules.push_back(&Hostname);
	TimeModule Time = TimeModule();
	modules.push_back(&Time);
	OSInfoModule OSInfo = OSInfoModule();
	modules.push_back(&OSInfo);
	CPUModule CPU = CPUModule();
	modules.push_back(&CPU);
	RAMModule RAM = RAMModule();
	modules.push_back(&RAM);
	NetworkModule Network = NetworkModule();
	modules.push_back(&Network);

	IMonitorDisplay *display;
	ImgUIMonitorDisplay imgui = ImgUIMonitorDisplay(modules);
	Ncurses ncurses = Ncurses(modules);

	if (argc == 2 && strcmp(argv[1], "-g") == 0)
		display = &imgui;
	else if (argc >= 2)
		return std::cerr << "Unknown option: " << argv[1] << std::endl, 1;
	else
		display = &ncurses;

	if (display->init())
		return 1;
	if (display->show())
		return 1;
	if (display->exit())
		return 1;
	return 0;
}

int main(int argc, char **argv) {
	return al_run_main(argc, argv, real_main);
}
