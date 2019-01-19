/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:21:21 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP

#include <iostream>

#define __USE_POSIX
#include <limits.h>

#include <unistd.h>

class 					HostnameModule
{
	public:
		~HostnameModule(void);
		HostnameModule(void);
		HostnameModule(std::string name);
		HostnameModule(HostnameModule const &src);
		HostnameModule 		&operator=(HostnameModule const & src);
		std::string getHostName(void) const;
		std::string getUserName(void) const;

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, HostnameModule const & src); */

#endif
