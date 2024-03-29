/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/20 17:32:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMONITORDISPLAY_H
# define __IMONITORDISPLAY_H

#include "IMonitorModule.h"

#include <vector>

class IMonitorDisplay {
protected:
	std::vector<IMonitorModule *> const &_modules;
	IMonitorDisplay(void);

public:
	IMonitorDisplay(std::vector<IMonitorModule *> const &modules);
	virtual ~IMonitorDisplay();

	virtual int init();
	virtual int exit();
	virtual int show();
	virtual int draw(const char *fmt, ...);
	virtual int plot(const float *values, size_t nvalues, float min, float max);
	IMonitorDisplay(IMonitorDisplay const &src);
	IMonitorDisplay     &operator=(IMonitorDisplay const & src) ;
};

#endif /* !__IMONITORDISPLAY_H */
