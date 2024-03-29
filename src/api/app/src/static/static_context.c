//
// Created by dolphilia on 2022/12/25.
//

#include "static_context.h"

static duk_context* context;

void set_context(duk_context *ctx) {
    context = ctx;
}

void event_error_callback(int error, const char *message) {
    fprintf(stderr, "GLFW: %s\n", message);
    duk_get_global_string(context, "_glfw_error_callback");
    duk_push_int(context, error);
    duk_push_string(context, message);
    duk_pcall(context, 2);
    duk_pop(context);  /* pop result */
}

void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    duk_get_global_string(context, "_glfw_key_callback");
    duk_push_int(context, key);
    duk_push_int(context, scancode);
    duk_push_int(context, action);
    duk_push_int(context, mods);
    duk_pcall(context, 4);
    duk_pop(context);  /* pop result */
}

void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    duk_get_global_string(context, "_glfw_cursor_position_callback");
    duk_push_number(context, xpos);
    duk_push_number(context, ypos);
    duk_pcall(context, 2);
    duk_pop(context);  /* pop result */
}

void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    duk_get_global_string(context, "_glfw_mouse_button_callback");
    duk_push_int(context, button);
    duk_push_int(context, action);
    duk_push_int(context, mods);
    duk_pcall(context, 3);
    duk_pop(context);  /* pop result */
}

void event_character_callback(GLFWwindow* window, unsigned int codepoint) {
    duk_get_global_string(context, "_glfw_character_callback");
    duk_push_uint(context, codepoint);
    duk_pcall(context, 1);
    duk_pop(context);  /* pop result */
}

void event_cursor_enter_callback(GLFWwindow* window, int entered) {
    duk_get_global_string(context, "_glfw_corsor_enter_callback");
    duk_push_int(context, entered);
    duk_pcall(context, 1);
    duk_pop(context);  /* pop result */
}

void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    duk_get_global_string(context, "_glfw_scroll_callback");
    duk_push_number(context, xoffset);
    duk_push_number(context, yoffset);
    duk_pcall(context, 2);
    duk_pop(context);  /* pop result */
}

void event_joystick_callback(int jid, int event) {
    duk_get_global_string(context, "_glfw_joystick_callback");
    duk_push_number(context, jid);
    duk_push_number(context, event);
    duk_pcall(context, 2);
    duk_pop(context);  /* pop result */
}

void event_drop_callback(GLFWwindow* window, int count, const char** paths) {
    duk_get_global_string(context, "_glfw_drop_callback");
    duk_push_number(context, count);
    duk_push_string(context, paths); //TODO
    duk_pcall(context, 2);
    duk_pop(context);  /* pop result */
}

void event_update_callback(void) {
    duk_get_global_string(context, "_event_update_callback");
    duk_pcall(context, 0);
    duk_pop(context);  /* pop result */
}