/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/19 23:39:33 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMONITORMODULE_H
# define __IMONITORMODULE_H

#include <string>
#include <unistd.h>
#include <iostream>

class IMonitorDisplay;

class IMonitorModule {
private:
	const std::string _name;

public:
	IMonitorModule(std::string name);
	virtual ~IMonitorModule();

	const std::string getName() const;

	virtual int init();
	virtual int exit();
	virtual int pump(IMonitorDisplay &display);
	std::string getTopInfo();
	std::string getTopInfoByName();
};

#endif /* !__IMONITORMODULE_H */
