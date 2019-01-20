/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:03:44 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/20 17:32:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ncurses.hpp"

Ncurses::Ncurses(t_pos & winPos, t_pos & maxPos) :winPos(winPos), maxPos(maxPos)
{
	return ;
}

Ncurses::Ncurses() :IMonitorDisplay(), winPos((t_pos){0, 0}), maxPos((t_pos){.x=COLS, .y=LINES}) 
{
	return ;
}

Ncurses::Ncurses(Ncurses const &src) : IMonitorDisplay(src)
{
	*this = src;
}

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
	(void)min;
	this->pos.y += 15;

	for (size_t x =  0 ; x < nvalues; x++)
	{
		for (int y = static_cast<int>(((values[x] -min)* 14.0) / (max - min)) ; y >= 0 ; y--)
		{
			mvwaddch(this->window, this->pos.y - y,this->pos.x +  x,
	(chtype)(COLOR_PAIR(1 +static_cast<int>(((values[x] -min)* 6.0) / (max - min)) ) | ' '));
		}
	}
	this->draw("\n");
	return 0;
}


int Ncurses::draw(const char *fmt, ...)
{
	va_list args;
	va_start (args, fmt);
	wmove(this->window, this->pos.y++, 0);
	vwprintw (this->window, fmt, args);
	va_end (args);
	return 0;
}

int Ncurses::init()
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(7, COLOR_RED, COLOR_RED);
	this->window = newwin(LINES, COLS , this->winPos.y, this->winPos.x);
	wrefresh(this->window);
	return IMonitorDisplay::init();
}

int Ncurses::show()
{
	while (true)
	{
		std::chrono::steady_clock::time_point end =
			std::chrono::steady_clock::now() +
			std::chrono::milliseconds(5);
		for (unsigned int i = 0; i < this->_modules.size(); i++)
		{
			wmove(this->window, this->pos.y, this->pos.x);
			this->draw("%s: \n", _modules[i]->getName().c_str());
			_modules[i]->pump(*this);
			++this->pos.y;
		}
		wrefresh(this->window);
		werase(this->window);
		this->pos = (t_pos){0, 0};
		if (getch() == 27)
			return 1;
		std::this_thread::sleep_until(end);
	}
	return 0;
}

int		Ncurses::exit()
{
	clear();
	endwin();
	return IMonitorDisplay::init();
}
