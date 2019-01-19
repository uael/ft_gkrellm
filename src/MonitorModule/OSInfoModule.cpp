/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:16:46 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(std::string target) 
{
}

OSInfoModule::OSInfoModule() 
{

}

OSInfoModule::~OSInfoModule() 
{

}

OSInfoModule::OSInfoModule(OSInfoModule const &src)
{
	*this = src;
}

OSInfoModule     &OSInfoModule::operator=(OSInfoModule const & src) 
{
	(void)src;
	return *this;
}

std::string getOsName()
{
#ifdef _WIN32
	return "Windows 32-bit";
#elif _WIN64
	return "Windows 64-bit";
#elif __unix || __unix__
	return "Unix";
#elif __APPLE__ || __MACH__
	return "Mac OSX";
#elif __linux__
	return "Linux";
#elif __FreeBSD__
	return "FreeBSD";
#else
	return "Other";
#endif
}       
