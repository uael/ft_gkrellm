/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:37:15 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
#define TIMEMODULE_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

class 					TimeModule
{
	public:
		~TimeModule(void);
		TimeModule(void);
		TimeModule(std::string name);
		TimeModule(TimeModule const &src);
		TimeModule 		&operator=(TimeModule const & src);
		std::string currentDateTime(std::string format) const;
		std::string		getDate(void) const;
		std::string		getTime(void) const;

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, TimeModule const & src); */

#endif
