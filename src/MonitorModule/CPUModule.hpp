/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:17:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 13:54:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include <iostream>
#include <sys/sysctl.h>

class 					CPUModule
{
	public:
		~CPUModule(void);
		CPUModule(void);
		CPUModule(std::string name);
		CPUModule(CPUModule const &src);
		CPUModule 		&operator=(CPUModule const & src);
		int		getCPUFrequ(void) const;
		int		getCPUNumber(void) const;
		int		getAvailableCPU(void) const;
		std::string getCPUName(void) const;

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, CPUModule const & src); */
/* getrusage */

#endif
