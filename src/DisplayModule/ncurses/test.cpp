/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:13:18 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 21:57:56 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.hpp"
#include <unistd.h>

int main()
{
	int max = 32;
	float *tab = new float[max];

	srand(time(0));
	initscr();
	cbreak();
	noecho();
	Ncurses win;
	start_color();			/* Start color 			*/
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	for (int i = 0; i < max; i++)
	{
		tab[i] = rand()%LINES;
	}
	win.plot(tab, max);
	wrefresh(win.window);
	refresh();
	getchar();
}
