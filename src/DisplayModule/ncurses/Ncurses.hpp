/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:01:03 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 21:55:56 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ncurses_HPP
#define Ncurses_HPP

#include <iostream>
#include <ncurses.h>


typedef struct s_pos
{
		size_t	y;
		size_t	x;
}             t_pos;

typedef t_pos max_pos;

class 					Ncurses
{
	public:
		~Ncurses(void);
		Ncurses(void);
		Ncurses(Ncurses const &src);
		Ncurses 		&operator=(Ncurses const & src);
		int plot(const float *values, size_t nvalues);
		void	setColor(t_pos pos);

		WINDOW		*window;
	private:
		max_pos		max_pos;
		t_pos			pos;
		t_pos			winPos;


};
/* std::ostream 		&operator<<(std::ostream & o, Ncurses const & src); */

#endif
