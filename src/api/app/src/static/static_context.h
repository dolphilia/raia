//
// Created by dolphilia on 2022/12/25.
//

#ifndef RAIA_APP_STATIC_CONTEXT_H
#define RAIA_APP_STATIC_CONTEXT_H

#include <stdio.h>
#include "GLFW/glfw3.h"
#include "../duktape/duktape.h"
#include "static_window.h"

void set_context(duk_context *ctx);
void event_error_callback(int error, const char *message);
void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void event_character_callback(GLFWwindow* window, unsigned int codepoint);
void event_cursor_enter_callback(GLFWwindow* window, int entered);
void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void event_joystick_callback(int jid, int event);
void event_drop_callback(GLFWwindow* window, int count, const char** paths);
void event_update_callback(void);

#endif //RAIA_APP_STATIC_CONTEXT_H
