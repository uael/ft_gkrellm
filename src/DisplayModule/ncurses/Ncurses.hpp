/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:01:03 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/20 15:46:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ncurses_HPP
#define Ncurses_HPP

#include <iostream>
#include <ncurses.h>
#include "../../IMonitorDisplay.h"
#include <thread>

typedef struct s_pos
{
	size_t	y;
	size_t	x;
}             t_pos;

typedef t_pos max_pos;

class 					Ncurses : public IMonitorDisplay
{
	public:
		~Ncurses(void);
		Ncurses(void);
		Ncurses(std::vector<IMonitorModule *> const &modules);
		Ncurses(t_pos & winPos, t_pos & maxPos);
		Ncurses(Ncurses const &src);
		Ncurses 		&operator=(Ncurses const & src);
		int plot(const float *values, size_t nvalues, float min, float max);
		void	setColor(t_pos pos);
		int draw(const char *fmt, ...);
		int init();
		int exit();
		int show();

		WINDOW		*window;
	private:
		t_pos			winPos;
		max_pos		maxPos;
		t_pos			pos;
};
/* std::ostream 		&operator<<(std::ostream & o, Ncurses const & src); */

#endif
