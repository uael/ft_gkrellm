/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MONITOR_H
# define __MONITOR_H

#include "IMonitorModule.h"
#include "IMonitorDisplay.h"

#include <vector>

class Monitor {
private:
	std::vector<IMonitorModule> _modules;
public:
	Monitor(std::vector<IMonitorModule> const &modules);
	~Monitor();

	int init();
	int exit();
	int show();
};

#endif /* !__MONITOR_H */
