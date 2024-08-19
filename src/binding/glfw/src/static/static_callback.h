//
// Created by dolphilia on 2022/12/25.
//

#ifndef RAIA_APP_STATIC_CALLBACK_H
#define RAIA_APP_STATIC_CALLBACK_H

#include <stdbool.h>
#include "GLFW/glfw3.h"
#include "luajit/lua.h"
#include "luajit/lualib.h"
#include "luajit/lauxlib.h"
#include "luajit/luajit.h"
#include "../../../third_party/c/troydhanson/uthash/uthash.h"

typedef struct raia_callback_t{
    // error_callback
    int error_code;
    const char *error_message;
    int error_callback_lua_fn_ref;
    // joystick_callback
    int joystick_id;
    int joystick_event;
    int joystick_callback_lua_fn_ref;
    // monitor_callback
    GLFWmonitor* monitor;
    int monitor_event;
    int monitor_callback_lua_fn_ref;
} callback_data_t;

typedef struct {
    GLFWwindow *window; // GLFWwindow* をキーとして使用
    int x, y;           // ウィンドウの位置情報
    int width, height;  // ウィンドウのサイズ情報
    bool close;
    bool refresh;
    int focused;
    int iconified;
    int framebuffer_size_width, framebuffer_size_height;
    int key, key_scancode, key_action, key_mods;
    // cursor_pos_callback
    double cursor_pos_x, cursor_pos_y;
    int cursor_pos_callback_ref;
    //
    int mouse_button, mouse_action, mouse_mods;
    unsigned int char_codepoint;
    unsigned int char_mods_codepoint;
    int char_mods_mods;
    int cursor_entered;
    int scroll_offset_x, scroll_offset_y;
    int drop_count;
    const char **drop_paths;
    int maximized;
    float content_scale_x;
    float content_scale_y;
    UT_hash_handle hh;  // uthash 用のハンドル
} window_data_t;

void init_callback_data(void);

// utils
window_data_t* get_or_create_window_data(GLFWwindow *window);
callback_data_t *get_or_create_callback_data();

// Error
void error_callback(int error, const char *message);
int get_callback_data_error_code();
const char *get_callback_data_error_message();

// Joystick
void joystick_callback(int jid, int event);
int get_callback_data_joystick_id();
int get_callback_data_joystick_event();

// Monitor
void monitor_callback(GLFWmonitor* monitor, int event);
GLFWmonitor* get_monitor(void);
int get_monitor_event(void);

// Pos
void window_pos_callback(GLFWwindow *window, int x, int y);
int get_window_pos_x(GLFWwindow *window);
int get_window_pos_y(GLFWwindow *window);

// Size
void window_size_callback(GLFWwindow *window, int width, int height);
int get_window_size_width(GLFWwindow *window);
int get_window_size_height(GLFWwindow *window);

// Close
void window_close_callback(GLFWwindow *window);
bool get_window_close(GLFWwindow *window);

// Refresh
void window_refresh_callback(GLFWwindow *window);
bool get_window_refresh(GLFWwindow *window);

// Forcus
void window_focus_callback(GLFWwindow* window, int focused);
int get_window_focus(GLFWwindow *window);

// Iconify
void window_iconify_callback(GLFWwindow *window, int iconified);
int get_window_iconified(GLFWwindow *window);

// Framebuffer Size
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
int get_framebuffer_size_width(GLFWwindow *window);
int get_framebuffer_size_height(GLFWwindow *window);

// Key
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
int get_key(GLFWwindow *window);
int get_key_scancode(GLFWwindow *window);
int get_key_action(GLFWwindow *window);
int get_key_mods(GLFWwindow *window);

// Cursor pos
void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
double get_cursor_pos_x(GLFWwindow* window);
double get_cursor_pos_y(GLFWwindow* window);

// Mouse Button
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
int get_mouse_button(GLFWwindow* window);
int get_mouse_action(GLFWwindow* window);
int get_mouse_mods(GLFWwindow* window);

// Char
void char_callback(GLFWwindow* window, unsigned int codepoint);
unsigned int get_char_codepoint(GLFWwindow* window);

// Char mods
void char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods);
unsigned int get_char_mods_codepoint(GLFWwindow* window);
int get_char_mods_mods(GLFWwindow* window);

// Cursor enter
void cursor_enter_callback(GLFWwindow* window, int entered);
int get_cursor_entered(GLFWwindow* window);

// Scroll
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
int get_scroll_xoffset(GLFWwindow* window);
int get_scroll_yoffset(GLFWwindow* window);

// Drop
void drop_callback(GLFWwindow* window, int count, const char** paths);
int get_drop_count(GLFWwindow* window);
const char** get_drop_paths(GLFWwindow* window);

// Maximize
void window_maximize_callback(GLFWwindow* window, int maximized);
int get_window_maximized(GLFWwindow* window);

// Content scale
void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale);
float get_window_content_scale_x(GLFWwindow* window);
float get_window_content_scale_y(GLFWwindow* window);

#endif //RAIA_APP_STATIC_CALLBACK_H
