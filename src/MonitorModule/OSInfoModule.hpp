/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:16:54 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include <iostream>

class 					OSInfoModule
{
	public:
		~OSInfoModule(void);
		OSInfoModule(void);
		OSInfoModule(std::string name);
		OSInfoModule(OSInfoModule const &src);
		OSInfoModule 		&operator=(OSInfoModule const & src);

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, OSInfoModule const & src); */

#endif
