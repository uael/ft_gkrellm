/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMONITORDISPLAY_H
# define __IMONITORDISPLAY_H

#include "IMonitorModule.h"

#include <vector>

class IMonitorDisplay {
private:
	std::vector<IMonitorModule> const &_modules;

public:
	IMonitorDisplay(std::vector<IMonitorModule> const &modules);
	virtual ~IMonitorDisplay();

	virtual int init();
	virtual int exit();
	virtual int show();
	virtual int draw(int line, int column, const char *fmt, ...);
};

#endif /* !__IMONITORDISPLAY_H */
