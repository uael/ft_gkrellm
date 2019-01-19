/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMONITORMODULE_H
# define __IMONITORMODULE_H

#include <string>

class IMonitorDisplay;

class IMonitorModule {
private:
	const std::string _name;

public:
	IMonitorModule(const std::string name);
	virtual ~IMonitorModule();

	const std::string getName() const;

	virtual int init();
	virtual int exit();
	virtual int pump(IMonitorDisplay &display);
};

#endif /* !__IMONITORMODULE_H */
