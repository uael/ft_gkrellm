/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayModule/ImgUI.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __DISPLAYMODULE_IMGUI_H
# define __DISPLAYMODULE_IMGUI_H

#include "IMonitorDisplay.h"

#include <imgui.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class ImgUIMonitorDisplay : public IMonitorDisplay {
private:
	ImGuiIO _io;
	ALLEGRO_DISPLAY *_display;
	ALLEGRO_EVENT_QUEUE *_queue;
	bool _running;
	bool *_wins;

public:
	ImgUIMonitorDisplay(std::vector<IMonitorModule *> const &modules);
	~ImgUIMonitorDisplay();

	ImgUIMonitorDisplay(ImgUIMonitorDisplay const &src);
	ImgUIMonitorDisplay &operator=(ImgUIMonitorDisplay const & src);

	int init();
	int exit();
	int show();
	int draw(const char *fmt, ...);
	int plot(const float *values, size_t nvalues, float min, float max);
};

#endif /* !__DISPLAYMODULE_IMGUI_H */
