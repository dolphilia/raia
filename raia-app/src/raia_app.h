#ifndef RAIA_WINDOW_RAIA_APP_H
#define RAIA_WINDOW_RAIA_APP_H

#include <time.h>
#include <stdio.h>
#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES
#include "GLFW/glfw3.h"
#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include "platforms.h"
#include "static/static_callback.h"
#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"

#include "platforms.h"
#ifdef __WINDOWS__
#include <windows.h>
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT const char * raia_app_init(const char *s);
RAIA_EXPORT const char * raia_app_window_create(const char *s);
RAIA_EXPORT const char * raia_app_get_error(const char *s);
RAIA_EXPORT const char * raia_app_get_key(const char *s);
RAIA_EXPORT const char * raia_app_get_framebuffer_size(const char *s);
RAIA_EXPORT const char * raia_app_get_joystick(const char *s);
RAIA_EXPORT const char * raia_app_get_window_pos(const char *s);
RAIA_EXPORT const char * raia_app_get_window_size(const char *s);
RAIA_EXPORT const char * raia_app_get_window_close(const char *s);
RAIA_EXPORT const char * raia_app_get_window_refresh(const char *s);
RAIA_EXPORT const char * raia_app_get_window_focus(const char *s);
RAIA_EXPORT const char * raia_app_get_window_iconify(const char *s);
RAIA_EXPORT const char * raia_app_get_cursor_position(const char *s);
RAIA_EXPORT const char * raia_app_get_mouse_button(const char *s);
RAIA_EXPORT const char * raia_app_get_character(const char *s);
RAIA_EXPORT const char * raia_app_get_character_mods(const char *s);
RAIA_EXPORT const char * raia_app_get_cursor_enter(const char *s);
RAIA_EXPORT const char * raia_app_get_scroll(const char *s);
RAIA_EXPORT const char * raia_app_get_drop(const char *s);
RAIA_EXPORT const char * raia_app_static_set_current_window(const char *s);
RAIA_EXPORT const char * raia_app_time_get_current_time(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_timer_value(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_timer_frequency(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_time(const char *s);
RAIA_EXPORT const char * raia_app_glfw_set_time(const char *s);
RAIA_EXPORT const char * raia_app_glfw_wait_event_timeout(const char *s);
RAIA_EXPORT const char * raia_app_glfw_joystick_present(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_joystick_present(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_joystick_axes(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_joystick_buttons(const char *s);
RAIA_EXPORT const char * raia_app_glfw_get_joystick_name(const char *s);
RAIA_EXPORT const char * raia_app_screen_redraw(const char *s);
RAIA_EXPORT const char * raia_app_window_poll_events(const char *s);
RAIA_EXPORT const char * raia_app_window_should_close(const char *s);
RAIA_EXPORT const char * raia_app_window_set_title(const char *s);
RAIA_EXPORT const char * raia_app_shader_init(const char *s);

#endif //RAIA_WINDOW_RAIA_APP_H
