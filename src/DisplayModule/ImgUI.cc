/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayModule/ImgUI.cc                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ImgUI.h"

#include <stdint.h>
#include <err.h>
#include <thread>

#include "imgui_impl_allegro5.h"

ImgUIMonitorDisplay::ImgUIMonitorDisplay(
	std::vector<IMonitorModule *> const &modules)
	: IMonitorDisplay(modules),
	  _io(), _display(), _queue(), _running(), _wins() { }

ImgUIMonitorDisplay::~ImgUIMonitorDisplay() { }

int ImgUIMonitorDisplay::init() {
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	_display = al_create_display(1000, 1000);
	al_set_window_title(_display, "GKrellM");
	_queue = al_create_event_queue();
	al_register_event_source(_queue, al_get_display_event_source(_display));
	al_register_event_source(_queue, al_get_keyboard_event_source());
	al_register_event_source(_queue, al_get_mouse_event_source());

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	_io = ImGui::GetIO();
	// Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplAllegro5_Init(_display);

	_wins = new bool[_modules.size()];
	for (size_t i = 0; i < _modules.size(); i++) _wins[i] = true;

	return IMonitorDisplay::init();
}

int ImgUIMonitorDisplay::exit() {
	ImGui_ImplAllegro5_Shutdown();
	ImGui::DestroyContext();
	al_destroy_event_queue(_queue);
	al_destroy_display(_display);
	return IMonitorDisplay::exit();
}

int ImgUIMonitorDisplay::show() {
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	_running = true;
	while (_running) {
		ALLEGRO_EVENT ev;

		std::chrono::steady_clock::time_point end =
			std::chrono::steady_clock::now() +
			std::chrono::milliseconds(14);

		while (al_get_next_event(_queue, &ev)) {
			ImGui_ImplAllegro5_ProcessEvent(&ev);
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				_running = false;
			if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
				ImGui_ImplAllegro5_InvalidateDeviceObjects();
				al_acknowledge_resize(_display);
				ImGui_ImplAllegro5_CreateDeviceObjects();
			}
		}

		ImGui_ImplAllegro5_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("GKrellM");
		for (size_t i = 0; i < _modules.size(); i++) {
			ImGui::Checkbox(_modules[i]->getName().c_str(), &_wins[i]);
		}
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();

		for (size_t i = 0; i < _modules.size(); i++)
			if (_wins[i]) {
				ImGui::Begin(_modules[i]->getName().c_str(), _wins + i);
				_modules[i]->pump(*this);
				ImGui::End();
			}

		// Rendering
		ImGui::Render();
		al_clear_to_color(al_map_rgba_f(
			clear_color.x, clear_color.y, clear_color.z, clear_color.w));
		ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
		al_flip_display();

		std::this_thread::sleep_until(end);
	}

	return 0;
}

int ImgUIMonitorDisplay::draw(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	ImGui::TextV(fmt, ap);
	va_end(ap);
	return 0;
}

int ImgUIMonitorDisplay::plot(const float *values, size_t nvalues) {

	ImGui::PlotLines("##plot", values, (int)nvalues, 0,
		nullptr, 0, FLT_MAX, ImVec2(350, 150));
	return 0;
}
