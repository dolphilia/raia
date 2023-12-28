//
// Created by dolphilia on 2022/12/25.
//

#ifndef RAIA_APP_STATIC_CTX_H
#define RAIA_APP_STATIC_CTX_H

#include <stdio.h>
#include "GLFW/glfw3.h"
#include "../duktape/duktape.h"
#include "static_window.h"

void event_error_callback(int error, const char *message);
void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void event_update_callback(void);
void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void set_context(duk_context *ctx);

#endif //RAIA_APP_STATIC_CTX_H
