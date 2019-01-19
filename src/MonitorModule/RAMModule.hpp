/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:40:09 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 14:41:32 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

#include <iostream>

class 					RAMModule
{
	public:
		~RAMModule(void);
		RAMModule(void);
		RAMModule(std::string name);
		RAMModule(RAMModule const &src);
		RAMModule 		&operator=(RAMModule const & src);
		float GetSystemMemoryUsagePercentage() const;

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, RAMModule const & src); */

#endif



