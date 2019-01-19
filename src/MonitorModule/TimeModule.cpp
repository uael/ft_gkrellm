/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:36:46 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 12:46:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TimeModule.hpp"

TimeModule::TimeModule(std::string target) 
{
}

TimeModule::TimeModule() 
{

}

TimeModule::~TimeModule() 
{

}

TimeModule::TimeModule(TimeModule const &src)
{
	*this = src;
}

TimeModule     &TimeModule::operator=(TimeModule const & src) 
{
	(void)src;
	return *this;
}


// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
std::string TimeModule::currentDateTime(std::string format) const
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), format.c_str(), &tstruct);
	return buf;
}

std::string		TimeModule::getDate(void) const
{
	return this->currentDateTime("%Y-%m-%d");
}

std::string		TimeModule::getTime(void) const
{
	return this->currentDateTime("%X");
}
