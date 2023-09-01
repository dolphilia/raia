//
// Created by dolphilia on 2022/12/25.
//

#include "static_callback.h"

static raia_callback_t *raia_callback;

void init_callback(void) {
    raia_callback = (raia_callback_t *)malloc(sizeof(raia_callback_t));
}

void event_error_callback(int error, const char *message) {
    raia_callback->error_callback_error = error;
    raia_callback->error_callback_message = message;
}

char *get_error_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "error", raia_callback->error_callback_error);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "message", raia_callback->error_callback_message);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_joystick_callback(int jid, int event) {
    raia_callback->joystick_callback_jid = jid;
    raia_callback->joystick_callback_event = event;
}

char *get_joystick_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "jid", raia_callback->joystick_callback_jid);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "event", raia_callback->joystick_callback_event);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_window_pos_callback(GLFWwindow *window, int x, int y) {
    raia_callback->window_pos_callback_window = window;
    raia_callback->window_pos_callback_x = x;
    raia_callback->window_pos_callback_y = y;
}

char *get_window_pos_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_pos_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "x", raia_callback->window_pos_callback_x);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "y", raia_callback->window_pos_callback_y);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_window_size_callback(GLFWwindow *window, int width, int height) {
    raia_callback->window_size_callback_window = window;
    raia_callback->window_size_callback_width = width;
    raia_callback->window_size_callback_height = height;
}

char *get_window_size_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_size_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", raia_callback->window_size_callback_width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", raia_callback->window_size_callback_height);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_window_close_callback(GLFWwindow *window) {
    raia_callback->window_close_callback_window = window;
}

char *get_window_close_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_close_callback_window);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

// TODO check refresh callback is actually called
void event_window_refresh_callback(GLFWwindow *window) {
    raia_callback->window_refresh_callback_window = window;
}

char *get_window_refresh_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_refresh_callback_window);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_window_focus_callback(GLFWwindow* window, int focused) {
    raia_callback->window_focus_callback_window = window;
    raia_callback->window_focus_callback_focused = focused;
}

char *get_window_focus_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_focus_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "focused", raia_callback->window_focus_callback_focused);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_window_iconify_callback(GLFWwindow *window, int iconified) {
    raia_callback->window_iconify_callback_window = window;
    raia_callback->window_iconify_callback_iconified = iconified;
}

char *get_window_iconify_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->window_iconify_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "iconified", raia_callback->window_iconify_callback_iconified);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    raia_callback->framebuffer_size_callback_window = window;
    raia_callback->framebuffer_size_callback_width = width;
    raia_callback->framebuffer_size_callback_height = height;
}

char *get_framebuffer_size_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->framebuffer_size_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", raia_callback->framebuffer_size_callback_width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", raia_callback->framebuffer_size_callback_height);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    raia_callback->key_callback_window = window;
    raia_callback->key_callback_key = key;
    raia_callback->key_callback_scancode = scancode;
    raia_callback->key_callback_action = action;
    raia_callback->key_callback_mods = mods;
}

char *get_key_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->key_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "key", raia_callback->key_callback_key);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "scancode", raia_callback->key_callback_scancode);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "action", raia_callback->key_callback_action);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "mods", raia_callback->key_callback_mods);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    raia_callback->cursor_position_callback_window = window;
    raia_callback->cursor_position_callback_xpos = xpos;
    raia_callback->cursor_position_callback_ypos = ypos;
}

char *get_cursor_pos_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->cursor_position_callback_window);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "xpos", raia_callback->cursor_position_callback_xpos);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "ypos", raia_callback->cursor_position_callback_ypos);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    raia_callback->mouse_button_callback_window = window;
    raia_callback->mouse_button_callback_button = button;
    raia_callback->mouse_button_callback_action = action;
    raia_callback->mouse_button_callback_mods = mods;
}

char *get_mouse_button_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->mouse_button_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "button", raia_callback->mouse_button_callback_button);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "action", raia_callback->mouse_button_callback_action);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "mods", raia_callback->mouse_button_callback_mods);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_char_callback(GLFWwindow* window, unsigned int codepoint) {
    raia_callback->character_callback_window = window;
    raia_callback->character_callback_codepoint = codepoint;
}

char *get_char_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->character_callback_window);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "codepoint", raia_callback->character_callback_codepoint);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods) {
    raia_callback->character_mods_callback_window = window;
    raia_callback->character_mods_callback_codepoint = codepoint;
    raia_callback->character_mods_callback_mods = mods;
}

char *get_char_mods_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->character_mods_callback_window);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "codepoint", raia_callback->character_mods_callback_codepoint);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "mods", raia_callback->character_mods_callback_mods);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_cursor_enter_callback(GLFWwindow* window, int entered) {
    raia_callback->cursor_enter_callback_window = window;
    raia_callback->cursor_enter_callback_entered = entered;
}

char *get_cursor_enter_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->cursor_enter_callback_window);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "entered", raia_callback->cursor_enter_callback_entered);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    raia_callback->scroll_callback_window = window;
    raia_callback->scroll_callback_xoffset = xoffset;
    raia_callback->scroll_callback_yoffset = yoffset;
}

char *get_scroll_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->scroll_callback_window);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "xoffset", raia_callback->scroll_callback_xoffset);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "yoffset", raia_callback->scroll_callback_yoffset);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}

void event_drop_callback(GLFWwindow* window, int count, const char** paths) {
    raia_callback->drop_callback_window = window;
    raia_callback->drop_callback_count = count;
    raia_callback->drop_callback_paths = paths;
}

char *get_drop_callback_t(void) {
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "window", (uint64_t)(uintptr_t)raia_callback->drop_callback_window);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "count", raia_callback->drop_callback_count);
    yyjson_mut_val *ret_vals = yyjson_mut_arr_with_str(ret_doc, raia_callback->drop_callback_paths, raia_callback->drop_callback_count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "paths", ret_vals);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return result;
}