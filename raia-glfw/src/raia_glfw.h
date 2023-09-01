//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GLFW_H
#define RAIA_GUI_RAIA_GLFW_H

#include <time.h>
#include "static/static_callback.h"
#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"
#include "platforms.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#ifdef __WINDOWS__
#include <windows.h>
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT const char *raia_glfw_get_error_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_framebuffer_size_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_key_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_joystick_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_pos_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_size_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_close_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_refresh_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_focus_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_iconify_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_cursor_pos_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_mouse_button_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_char_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_char_mods_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_cursor_enter_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_scroll_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_drop_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_init(const char *s);
RAIA_EXPORT const char *raia_glfw_window_hint(const char *s);
RAIA_EXPORT const char *raia_glfw_set_error_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_joystick_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_create_window(const char *s);
RAIA_EXPORT const char *raia_glfw_terminate(const char *s);
RAIA_EXPORT const char *raia_glfw_make_context_current(const char *s);
RAIA_EXPORT const char *raia_glfw_swap_interval(const char *s);
RAIA_EXPORT const char *raia_glfw_get_framebuffer_size(const char *s);
RAIA_EXPORT const char *raia_glfw_get_window_size(const char *s);
RAIA_EXPORT const char *raia_glfw_set_key_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_framebuffer_size_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_pos_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_size_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_close_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_refresh_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_focus_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_iconify_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_cursor_pos_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_mouse_button_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_char_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_char_mods_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_cursor_enter_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_scroll_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_set_drop_callback(const char *s);
RAIA_EXPORT const char *raia_glfw_get_timer_value(const char *s);
RAIA_EXPORT const char *raia_glfw_get_timer_frequency(const char *s);
RAIA_EXPORT const char *raia_glfw_get_time(const char *s);
RAIA_EXPORT const char *raia_glfw_set_time(const char *s);
RAIA_EXPORT const char *raia_glfw_wait_event_timeout(const char *s);
RAIA_EXPORT const char *raia_glfw_joystick_present(const char *s);
RAIA_EXPORT const char *raia_glfw_get_joystick_axes(const char *s);
RAIA_EXPORT const char *raia_glfw_get_joystick_buttons(const char *s);
RAIA_EXPORT const char *raia_glfw_get_joystick_name(const char *s);
RAIA_EXPORT const char *raia_glfw_swap_buffers(const char *s);
RAIA_EXPORT const char *raia_glfw_poll_events(const char *s);
RAIA_EXPORT const char *raia_glfw_window_should_close(const char *s);
RAIA_EXPORT const char *raia_glfw_set_window_title(const char *s);

#endif //RAIA_GUI_RAIA_GLFW_H
