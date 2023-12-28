//
// Created by dolphilia on 2022/12/25.
//

#ifndef RAIA_APP_STATIC_CALLBACK_H
#define RAIA_APP_STATIC_CALLBACK_H

#include <stdio.h>
#include "GLFW/glfw3.h"
#include "../../../../third_party/c/ibireme/yyjson/yyjson.h"

typedef struct raia_callback_t{
    //error_callback
    int error_callback_error;
    const char *error_callback_message;

    // joystick_callback
    int joystick_callback_jid;
    int joystick_callback_event;

    // window_pos_callback
    GLFWwindow *window_pos_callback_window;
    int window_pos_callback_x;
    int window_pos_callback_y;

    // window_size_callback
    GLFWwindow *window_size_callback_window;
    int window_size_callback_width;
    int window_size_callback_height;

    // window_close_callback
    GLFWwindow *window_close_callback_window;

    // window_refresh_callback
    GLFWwindow *window_refresh_callback_window;

    // window_focus_callback
    GLFWwindow* window_focus_callback_window;
    int window_focus_callback_focused;

    // window_iconify_callback
    GLFWwindow *window_iconify_callback_window;
    int window_iconify_callback_iconified;

    // framebuffer_size_callback
    GLFWwindow *framebuffer_size_callback_window;
    int framebuffer_size_callback_width;
    int framebuffer_size_callback_height;

    // key_callback
    GLFWwindow* key_callback_window;
    int key_callback_key;
    int key_callback_scancode;
    int key_callback_action;
    int key_callback_mods;

    // cursor_position_callback
    GLFWwindow* cursor_position_callback_window;
    double cursor_position_callback_xpos;
    double cursor_position_callback_ypos;

    // mouse_button_callback
    GLFWwindow* mouse_button_callback_window;
    int mouse_button_callback_button;
    int mouse_button_callback_action;
    int mouse_button_callback_mods;

    // character_callback
    GLFWwindow* character_callback_window;
    unsigned int character_callback_codepoint;

    // character_mods_callback
    GLFWwindow *character_mods_callback_window;
    unsigned int character_mods_callback_codepoint;
    int character_mods_callback_mods;

    // cursor_enter_callback
    GLFWwindow* cursor_enter_callback_window;
    int cursor_enter_callback_entered;

    // scroll_callback
    GLFWwindow* scroll_callback_window;
    double scroll_callback_xoffset;
    double scroll_callback_yoffset;

    // drop_callback
    GLFWwindow* drop_callback_window;
    int drop_callback_count;
    const char** drop_callback_paths;
} raia_callback_t;

void init_raia_callback(void);

void event_error_callback(int error, const char *message);
void event_window_pos_callback(GLFWwindow *window, int x, int y);
void event_window_size_callback(GLFWwindow *window, int width, int height);
void event_window_close_callback(GLFWwindow *window);
void event_window_refresh_callback(GLFWwindow *window);
void event_window_focus_callback(GLFWwindow* window, int focused);
void event_window_iconify_callback(GLFWwindow *window, int iconified);
void event_framebuffer_size_callback(GLFWwindow *window, int width, int height);
void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void event_character_callback(GLFWwindow* window, unsigned int codepoint);
void event_character_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods);
void event_cursor_enter_callback(GLFWwindow* window, int entered);
void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void event_joystick_callback(int jid, int event);
void event_drop_callback(GLFWwindow* window, int count, const char** paths);

char *get_error_callback_t(void);
char *get_joystick_callback_t(void);
char *get_window_pos_callback_t(void);
char *get_window_size_callback_t(void);
char *get_window_close_callback_t(void);
char *get_window_refresh_callback_t(void);
char *get_window_focus_callback_t(void);
char *get_window_iconify_callback_t(void);
char *get_framebuffer_size_callback_t(void);
char *get_key_callback_t(void);
char *get_cursor_position_callback_t(void);
char *get_mouse_button_callback_t(void);
char *get_character_callback_t(void);
char *get_character_mods_callback_t(void);
char *get_cursor_enter_callback_t(void);
char *get_scroll_callback_t(void);
char *get_drop_callback_t(void);

#endif //RAIA_APP_STATIC_CALLBACK_H
