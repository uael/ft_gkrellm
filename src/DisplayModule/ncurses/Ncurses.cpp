/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:03:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 21:59:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ncurses.hpp"

Ncurses::Ncurses() :winPos((t_pos){0, 0}), max_pos((t_pos){.x=COLS, .y=LINES})
{
	this->window = subwin(stdscr, this->max_pos.y, this->max_pos.x , 0, 0);

}

Ncurses::~Ncurses() 
{

}

Ncurses::Ncurses(Ncurses const &src)
{
	*this = src;
}

Ncurses     &Ncurses::operator=(Ncurses const & src) 
{
	(void)src;
	return *this;
}

#include <unistd.h>
int Ncurses::plot(const float *values, size_t nvalues)
{

	box(this->window, ACS_VLINE, ACS_HLINE);
	for (size_t x = 0; x < nvalues; x++)
	{
		for (int y = 0;static_cast<int>(values[x]) > y && this->max_pos.y -y > this->winPos.y; y++)
		{
			if (!(static_cast<int>(this->max_pos.y -y) % static_cast<int>(this->max_pos.y /4)))
				wattron(this->window, COLOR_PAIR(1));

			mvwaddch(this->window, this->max_pos.y  - y -2, x, ACS_VLINE);
			wattroff(this->window, COLOR_PAIR(1));
		}
	}
	return 0;
}

