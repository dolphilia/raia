//
// Created by dolphilia on 2022/12/25.
//

#include "static_callback.h"

static window_data_t *window_data_map = NULL;
static callback_data_t *callback_data = NULL;

// Util

window_data_t* get_or_create_window_data(GLFWwindow *window) {
    window_data_t *data;
    HASH_FIND_PTR(window_data_map, &window, data);
    if (data == NULL) {
        data = (window_data_t*)malloc(sizeof(window_data_t));
        data->window = window;
        data->x = -1; // 初期値
        data->y = -1;
        data->width = -1;
        data->height = -1;
        data->close = false;
        data->refresh = false;
        data->focused = -1;
        data->framebuffer_size_width = -1;
        data->framebuffer_size_height = -1;
        data->key = -1;
        data->key_scancode = -1;
        data->key_action = -1;
        data->key_mods = -1;
        //
        data->cursor_pos_x = -1;
        data->cursor_pos_y = -1;
        // data->cursor_pos_callback_ref = LUA_NOREF;
        //
        data->mouse_button = -1;
        data->mouse_action = -1;
        data->mouse_mods = -1;
        data->char_codepoint = 0;
        data->char_mods_codepoint = 0;
        data->char_mods_mods = -1;
        data->cursor_entered = -1;
        data->scroll_offset_x = -1;
        data->scroll_offset_y = -1;
        data->drop_count = -1;
        data->drop_paths = NULL;
        data->maximized = -1;
        data->content_scale_x = -1;
        data->content_scale_y = -1;
        HASH_ADD_PTR(window_data_map, window, data);
    }
    return data;
}

callback_data_t *get_or_create_callback_data() {
    if (callback_data == NULL) {
        callback_data = (callback_data_t *)malloc(sizeof(callback_data_t));
        // error_callback
        callback_data->error_code = -1;
        callback_data->error_message = NULL;
        // callback_data->error_callback_lua_fn_ref = LUA_NOREF;
        // joystick_callback
        callback_data->joystick_id = -1;
        callback_data->joystick_event = -1;
        // callback_data->joystick_callback_lua_fn_ref = LUA_NOREF;
        // monitor_callback
        callback_data->monitor = NULL;
        callback_data->monitor_event = -1;
        // callback_data->monitor_callback_lua_fn_ref = LUA_NOREF;
    }
    return callback_data;
}

// Error

void error_callback(int error, const char *message) {
    callback_data_t *data = get_or_create_callback_data();
    data->error_code = error;
    data->error_message = message;
}

int get_callback_data_error_code() {
    return callback_data->error_code;
}

const char * get_callback_data_error_message() {
    return callback_data->error_message;
}

// Joystick

void joystick_callback(int jid, int event) {
    callback_data_t *data = get_or_create_callback_data();
    data->joystick_id = jid;
    data->joystick_event = event;
}

int get_callback_data_joystick_id() {
    return callback_data->joystick_id;
}

int get_callback_data_joystick_event() {
    return callback_data->joystick_event;
}

// Monitor

void monitor_callback(GLFWmonitor* monitor, int event) {
    callback_data_t *data = get_or_create_callback_data();
    data->monitor = monitor;
    data->monitor_event = event;
}

GLFWmonitor* get_monitor(void) {
    return callback_data->monitor;
}

int get_monitor_event(void) {
    return callback_data->monitor_event;
}

// Pos

void window_pos_callback(GLFWwindow *window, int x, int y) {
    window_data_t *data = get_or_create_window_data(window);
    data->x = x;
    data->y = y;
}

int get_window_pos_x(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->x;
}

int get_window_pos_y(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->y;
}

// Size

void window_size_callback(GLFWwindow *window, int width, int height) {
    window_data_t *data = get_or_create_window_data(window);
    data->width = width;
    data->height = height;
}

int get_window_size_width(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->width;
}

int get_window_size_height(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->height;
}

// Close

void window_close_callback(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    data->close = true;
}

bool get_window_close(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    if (data->close) {
        data->close = false;
        return true;
    }
    return false;
}

// Refresh

void window_refresh_callback(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    data->refresh = true;
}

bool get_window_refresh(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    if (data->refresh) {
        data->refresh = false;
        return true;
    }
    return false;
}

// Focus

void window_focus_callback(GLFWwindow* window, int focused) {
    window_data_t *data = get_or_create_window_data(window);
    data->focused = focused;
}

int get_window_focus(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->focused;
}

// Iconify

void window_iconify_callback(GLFWwindow *window, int iconified) {
    window_data_t *data = get_or_create_window_data(window);
    data->iconified = iconified;
}

int get_window_iconified(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->iconified;
}

// Framebuffer Size

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    window_data_t *data = get_or_create_window_data(window);
    data->framebuffer_size_width = width;
    data->framebuffer_size_height = height;
}

int get_framebuffer_size_width(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->framebuffer_size_width;
}

int get_framebuffer_size_height(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->framebuffer_size_width;
}

// Key

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    window_data_t *data = get_or_create_window_data(window);
    data->key = key;
    data->key_scancode = scancode;
    data->key_action = action;
    data->key_mods = mods;
}

int get_key(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->key;
}

int get_key_scancode(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->key_scancode;
}

int get_key_action(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->key_action;
}

int get_key_mods(GLFWwindow *window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->key_mods;
}

// Cursor pos

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    window_data_t *data = get_or_create_window_data(window);
    data->cursor_pos_x = xpos;
    data->cursor_pos_y = ypos;
    //printf("%f\n", data->cursor_pos_x);
}

double get_cursor_pos_x(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->cursor_pos_x;
}

double get_cursor_pos_y(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->cursor_pos_y;
}

// Mouse button

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    window_data_t *data = get_or_create_window_data(window);
    data->mouse_button = button;
    data->mouse_action = action;
    data->mouse_mods = mods;
}

int get_mouse_button(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->mouse_button;
}

int get_mouse_action(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->mouse_action;
}

int get_mouse_mods(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->mouse_mods;
}

// Char

void char_callback(GLFWwindow* window, unsigned int codepoint) {
    window_data_t *data = get_or_create_window_data(window);
    data->char_codepoint = codepoint;
}

unsigned int get_char_codepoint(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->char_codepoint;
}

// Char mods

void char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods) {
    window_data_t *data = get_or_create_window_data(window);
    data->char_mods_codepoint = codepoint;
    data->char_mods_mods = mods;
}

unsigned int get_char_mods_codepoint(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->char_mods_codepoint;
}

int get_char_mods_mods(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->char_mods_mods;
}

// Enter

void cursor_enter_callback(GLFWwindow* window, int entered) {
    window_data_t *data = get_or_create_window_data(window);
    data->cursor_entered = entered;
}

int get_cursor_entered(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->cursor_entered;
}

// Scroll

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    window_data_t *data = get_or_create_window_data(window);
    data->scroll_offset_x = xoffset;
    data->scroll_offset_y = yoffset;
}

int get_scroll_xoffset(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->scroll_offset_x;
}

int get_scroll_yoffset(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->scroll_offset_y;
}

// Drop

void drop_callback(GLFWwindow* window, int count, const char** paths) {
    window_data_t *data = get_or_create_window_data(window);
    data->drop_count = count;
    data->drop_paths = paths;
}

int get_drop_count(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->drop_count;
}

const char** get_drop_paths(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->drop_paths;
}

// Maximize

void window_maximize_callback(GLFWwindow* window, int maximized) {
    window_data_t *data = get_or_create_window_data(window);
    data->maximized = maximized;
}

int get_window_maximized(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->maximized;
}

// Content scale

void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale) {
    window_data_t *data = get_or_create_window_data(window);
    data->content_scale_x = xscale;
    data->content_scale_y = yscale;
}

float get_window_content_scale_x(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->content_scale_x;
}

float get_window_content_scale_y(GLFWwindow* window) {
    window_data_t *data = get_or_create_window_data(window);
    return data->content_scale_y;
}