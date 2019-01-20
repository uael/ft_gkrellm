/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:03:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/20 14:21:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ncurses.hpp"

/* Ncurses::Ncurses(t_pos & winPos, t_pos & maxPos) :winPos(winPos), maxPos(maxPos) */
/* { */
/* 	return ; */
/* } */

/* Ncurses::Ncurses() :winPos((t_pos){0, 0}), maxPos((t_pos){.x=COLS, .y=LINES}) */
/* { */
/* 	return ; */
/* } */

/* Ncurses::Ncurses(Ncurses const &src) */
/* { */
/* 	*this = src; */
/* } */

Ncurses::Ncurses(std::vector<IMonitorModule *> const &modules) : IMonitorDisplay(modules) , winPos((t_pos){0, 0}), maxPos((t_pos){.x=COLS, .y=LINES}) , pos((t_pos){0, 0})
{
	

}

Ncurses     &Ncurses::operator=(Ncurses const & src) 
{
	(void)src;
	return *this;
}

Ncurses::~Ncurses() 
{

}

int Ncurses::plot(const float *values, size_t nvalues, float min, float max)
{
	this->pos.y += 5;

	for (size_t x =  0 ; x < nvalues; x++)
	{
		for (int y = (values[x] * 5) / max; y > 0 ; y--)
		{
			/* if (!(static_cast<int>(y) % static_cast<int>(static_cast<int>(values[x] - 5.0 * 0.25)))) */
				/* wattron(this->window, COLOR_PAIR(1)); */
			/* mvwprintw (this->window, 20, 20 ,"y%d  x%d nvalues%d", y, x, nvalues); */
			mvwaddch(this->window, this->pos.y + y,this->pos.x +  x, ACS_VLINE);
		}
	}
	return 0;
}


int Ncurses::draw(const char *fmt, ...)
{
	va_list args;
	va_start (args, fmt);

	vwprintw (this->window, fmt, args);
	this->pos.y++;
	va_end (args);
	return 0;
}

int Ncurses::init()
{
	initscr();
	cbreak();
	noecho();
	/* raw(); */
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	this->window = newwin(this->maxPos.y, this->maxPos.x , this->winPos.y, this->winPos.x);
	wrefresh(this->window);
	return 0;
}

int Ncurses::show()
{
	while (true)
	{
		for (unsigned int i = 0; i < this->_modules.size(); i++)
		{
			/* if (this->pos.y > this */
			if (_modules[i]->getName() == "CPU")
			{
					
			}
			wmove(this->window, this->pos.y, this->pos.x);
			_modules[i]->pump(*this);
		/* getch(); */
		}
			wrefresh(this->window);
		werase(this->window);
		this->pos = (t_pos){0, 0};
	}
	return 0;
}

int		Ncurses::exit()
{
	clear();
	endwin();
	return 0;
}
