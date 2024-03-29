/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:23:38 by ygarrot          ###   ########.fr       */
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

	IMonitorModule(IMonitorModule const &src);
	IMonitorModule &operator=(IMonitorModule const & src);

	const std::string getName() const;

	virtual int init();
	virtual int exit();
	virtual int pump(IMonitorDisplay &display);
};

#endif /* !__IMONITORMODULE_H */
