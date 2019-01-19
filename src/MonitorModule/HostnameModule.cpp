/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:21:36 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HostnameModule.hpp"

HostnameModule::HostnameModule(std::string target) 
{
}

HostnameModule::HostnameModule() 
{

}

HostnameModule::~HostnameModule() 
{

}

HostnameModule::HostnameModule(HostnameModule const &src)
{
	*this = src;
}

HostnameModule     &HostnameModule::operator=(HostnameModule const & src) 
{
	(void)src;
	return *this;
}

std::string HostnameModule::getHostName(void) const
{
	char hostname[_POSIX_HOST_NAME_MAX];
	gethostname(hostname, _POSIX_HOST_NAME_MAX);
	return hostname;
}

std::string HostnameModule::getUserName(void) const
{
	/* getlogin_r(username, _POSIX_LOGIN_NAME_MAX); */
	return getlogin(); 
}
