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

#include <cstdarg>

class IMonitorDisplay;

enum MonitorDisplayType {
	MonitorDisplayTUI,
	MonitorDisplayGUI
};

class IMonitorDisplay {
private:
	const enum MonitorDisplayType _type;

public:
	IMonitorDisplay(enum MonitorDisplayType type);
	virtual ~IMonitorDisplay();

	enum MonitorDisplayType getType() const;

	virtual int init();
	virtual int exit();
	virtual int draw(int line, int column, const char *fmt, ...);
};

#endif /* !__IMONITORDISPLAY_H */
