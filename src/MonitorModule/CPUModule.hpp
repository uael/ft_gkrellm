/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:17:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 14:18:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include <iostream>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

class 					CPUModule
{
	public:
		~CPUModule(void);
		CPUModule(void);
		CPUModule(std::string name);
		CPUModule(CPUModule const &src);
		CPUModule 		&operator=(CPUModule const & src);
		std::string		getCPUFrequ(void) const;
		std::string		getCPUNumber(void) const;
		std::string		getAvailableCPU(void) const;
		std::string getCPUName(void) const;
		float GetCPULoad();
		float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, CPUModule const & src); */
/* getrusage */

#endif
