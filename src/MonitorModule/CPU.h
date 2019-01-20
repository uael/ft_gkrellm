/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule/CPU.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MONITORMODULE_CPU_H
# define __MONITORMODULE_CPU_H

#include "IMonitorModule.h"

#include <vector>

class CPUModule : public IMonitorModule {
private:
	std::vector<float> _plot;
	clock_t _clock;

public:
	CPUModule();
	~CPUModule();

	int pump(IMonitorDisplay &display);
};

#endif /* !__MONITORMODULE_CPU_H */
