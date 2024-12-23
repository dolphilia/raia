//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GLFW_H
#define RAIA_GUI_RAIA_GLFW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

// MARK: 型

#define GLFW_TRUE 1

typedef struct GLFWwindow   GLFWwindow;
typedef struct GLFWmonitor  GLFWmonitor;
typedef struct GLFWcursor   GLFWcursor;

typedef struct GLFWvidmode {
    int width;
    int height;
    int redBits;
    int greenBits;
    int blueBits;
    int refreshRate;
} GLFWvidmode;

typedef struct GLFWgammaramp {
    unsigned short* red;
    unsigned short* green;
    unsigned short* blue;
    unsigned int size;
} GLFWgammaramp;

typedef struct GLFWimage {
    int width;
    int height;
    unsigned char* pixels;
} GLFWimage;

typedef struct GLFWgamepadstate {
    unsigned char buttons[15];
    float axes[6];
} GLFWgamepadstate;

typedef void (*GLFWerrorfun)(int, const char*);
typedef void (*GLFWkeyfun)(GLFWwindow*, int, int, int, int);
typedef void (*GLFWcharfun)(GLFWwindow*, unsigned int);
typedef void (*GLFWcharmodsfun)(GLFWwindow*, unsigned int, int);
typedef void (*GLFWmousebuttonfun)(GLFWwindow*, int, int, int);
typedef void (*GLFWcursorposfun)(GLFWwindow*, double, double);
typedef void (*GLFWcursorenterfun)(GLFWwindow*, int);
typedef void (*GLFWscrollfun)(GLFWwindow*, double, double);
typedef void (*GLFWdropfun)(GLFWwindow*, int, const char**);
typedef void (*GLFWjoystickfun)(int, int);
typedef void (*GLFWmonitorfun)(GLFWmonitor*, int);
typedef void (*GLFWwindowposfun)(GLFWwindow*, int, int);
typedef void (*GLFWwindowsizefun)(GLFWwindow*, int, int);
typedef void (*GLFWwindowclosefun)(GLFWwindow*);
typedef void (*GLFWwindowrefreshfun)(GLFWwindow*);
typedef void (*GLFWwindowfocusfun)(GLFWwindow*, int);
typedef void (*GLFWwindowiconifyfun)(GLFWwindow*, int);
typedef void (*GLFWwindowmaximizefun)(GLFWwindow*, int);
typedef void (*GLFWframebuffersizefun)(GLFWwindow*, int, int);
typedef void (*GLFWwindowcontentscalefun)(GLFWwindow*, float, float);

typedef void (*GLFWglproc)(void);

// MARK: コンテキスト

void raia_glfw_make_context_current(GLFWwindow *window);
GLFWwindow *raia_glfw_get_current_context(void);
void raia_glfw_swap_interval(int interval);
int raia_glfw_extension_supported(const char *extension);
GLFWglproc raia_glfw_get_proc_address(const char *procname);

// MARK: 初期化・バージョン・エラー

int raia_glfw_init(void);
void raia_glfw_terminate(void);
void raia_glfw_init_hint(int hint, int value);
void raia_glfw_get_version(int *major, int *minor, int *rev);
const char *raia_glfw_get_version_string(void);
int raia_glfw_get_error(const char **description);
GLFWerrorfun raia_glfw_set_error_callback(GLFWerrorfun callback);

// MARK: 入力

int raia_glfw_get_input_mode(GLFWwindow *window, int mode);
void raia_glfw_set_input_mode(GLFWwindow *window, int mode, int value);
int raia_glfw_raw_mouse_motion_supported(void);
const char *raia_glfw_get_key_name(int key, int scancode);
int raia_glfw_get_key_scancode(int key);
int raia_glfw_get_key(GLFWwindow *window, int key);
int raia_glfw_get_mouse_button(GLFWwindow *window, int button);
void raia_glfw_get_cursor_pos(GLFWwindow *window, double *xpos, double *ypos);
void raia_glfw_set_cursor_pos(GLFWwindow *window, double xpos, double ypos);
GLFWcursor *raia_glfw_create_cursor(const GLFWimage *image, int xhot, int yhot);
GLFWcursor *raia_glfw_create_standard_cursor(int shape);
void raia_glfw_destroy_cursor(GLFWcursor *cursor);
void raia_glfw_set_cursor(GLFWwindow *window, GLFWcursor *cursor);
GLFWkeyfun raia_glfw_set_key_callback(GLFWwindow *window, GLFWkeyfun callback);
GLFWcharfun raia_glfw_set_char_callback(GLFWwindow *window, GLFWcharfun callback);
GLFWcharmodsfun raia_glfw_set_char_mods_callback(GLFWwindow *window, GLFWcharmodsfun callback);
GLFWmousebuttonfun raia_glfw_set_mouse_button_callback(GLFWwindow *window, GLFWmousebuttonfun callback);
GLFWcursorposfun raia_glfw_set_cursor_pos_callback(GLFWwindow *window, GLFWcursorposfun callback);
GLFWcursorenterfun raia_glfw_set_cursor_enter_callback(GLFWwindow *window, GLFWcursorenterfun callback);
GLFWscrollfun raia_glfw_set_scroll_callback(GLFWwindow *window, GLFWscrollfun callback);
GLFWdropfun raia_glfw_set_drop_callback(GLFWwindow *window, GLFWdropfun callback);
int raia_glfw_joystick_present(int jid);
const float *raia_glfw_get_joystick_axes(int jid, int *count);
const unsigned char *raia_glfw_get_joystick_buttons(int jid, int *count);
const unsigned char *raia_glfw_get_joystick_hats(int jid, int *count);
const char *raia_glfw_get_joystick_name(int jid);
const char *raia_glfw_get_joystick_guid(int jid);
void raia_glfw_set_joystick_user_pointer(int jid, void *pointer);
void *raia_glfw_get_joystick_user_pointer(int jid);
int raia_glfw_joystick_is_gamepad(int jid);
GLFWjoystickfun raia_glfw_set_joystick_callback(GLFWjoystickfun callback);
int raia_glfw_update_gamepad_mappings(const char *string);
const char *raia_glfw_get_gamepad_name(int jid);
int raia_glfw_get_gamepad_state(int jid, GLFWgamepadstate *state);
void raia_glfw_set_clipboard_string(GLFWwindow *window, const char *string);
const char *raia_glfw_get_clipboard_string(GLFWwindow *window);
double raia_glfw_get_time(void);
void raia_glfw_set_time(double time);
uint64_t raia_glfw_get_timer_value(void);
uint64_t raia_glfw_get_timer_frequency(void);

// MARK: モニター

GLFWmonitor **raia_glfw_get_monitors(int *count);
GLFWmonitor *raia_glfw_get_primary_monitor(void);
void raia_glfw_get_monitor_pos(GLFWmonitor *monitor, int *xpos, int *ypos);
void raia_glfw_get_monitor_workarea(GLFWmonitor *monitor, int *xpos, int *ypos, int *width, int *height);
void raia_glfw_get_monitor_physical_size(GLFWmonitor *monitor, int *widthMM, int *heightMM);
void raia_glfw_get_monitor_content_scale(GLFWmonitor *monitor, float *xscale, float *yscale);
const char *raia_glfw_get_monitor_name(GLFWmonitor *monitor);
void raia_glfw_set_monitor_user_pointer(GLFWmonitor *monitor, void *pointer);
void *raia_glfw_get_monitor_user_pointer(GLFWmonitor *monitor);
GLFWmonitorfun raia_glfw_set_monitor_callback(GLFWmonitorfun callback);
const GLFWvidmode *raia_glfw_get_video_modes(GLFWmonitor *monitor, int *count);
const GLFWvidmode *raia_glfw_get_video_mode(GLFWmonitor *monitor);
void raia_glfw_set_gamma(GLFWmonitor *monitor, float gamma);
const GLFWgammaramp *raia_glfw_get_gamma_ramp(GLFWmonitor *monitor);
void raia_glfw_set_gamma_ramp(GLFWmonitor *monitor, const GLFWgammaramp *ramp);

// MARK: ネイティブアクセス

// glfwGetWin32Adapter
// glfwGetWin32Monitor
// glfwGetWin32Window
// glfwGetWGLContext
// glfwGetCocoaMonitor
// glfwGetCocoaWindow
// glfwGetNSGLContext
// glfwGetX11Display
// glfwGetX11Adapter
// glfwGetX11Monitor
// glfwGetX11Window
// glfwSetX11SelectionString
// glfwGetX11SelectionString
// glfwGetGLXContext
// glfwGetGLXWindow
// glfwGetWaylandDisplay
// glfwGetWaylandMonitor
// glfwGetWaylandWindow
// glfwGetEGLDisplay
// glfwGetEGLContext
// glfwGetEGLSurface
// glfwGetOSMesaColorBuffer
// glfwGetOSMesaDepthBuffer
// glfwGetOSMesaContext

// MARK: Vulkanサポート

int raia_glfw_vulkan_supported(void);
const char **raia_glfw_get_required_instance_extensions(uint32_t *count);

// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

// MARK: ウィンドウ

void raia_glfw_default_window_hints(void);
void raia_glfw_window_hint(int hint, int value);
void raia_glfw_window_hint_string(int hint, const char *value);
GLFWwindow *raia_glfw_create_window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share);
void raia_glfw_destroy_window(GLFWwindow *window);
int raia_glfw_window_should_close(GLFWwindow *window);
void raia_glfw_set_window_should_close(GLFWwindow *window, int value);
void raia_glfw_set_window_title(GLFWwindow *window, const char *title);
void raia_glfw_set_window_icon(GLFWwindow *window, int count, const GLFWimage *images);
void raia_glfw_get_window_pos(GLFWwindow *window, int *xpos, int *ypos);
void raia_glfw_set_window_pos(GLFWwindow *window, int xpos, int ypos);
void raia_glfw_get_window_size(GLFWwindow *window, int *width, int *height);
void raia_glfw_set_window_size_limits(GLFWwindow *window, int minwidth, int minheight, int maxwidth, int maxheight);
void raia_glfw_set_window_aspect_ratio(GLFWwindow *window, int numer, int denom);
void raia_glfw_set_window_size(GLFWwindow *window, int width, int height);
void raia_glfw_get_framebuffer_size(GLFWwindow *window, int *width, int *height);
void raia_glfw_get_window_frame_size(GLFWwindow *window, int *left, int *top, int *right, int *bottom);
void raia_glfw_get_window_content_scale(GLFWwindow *window, float *xscale, float *yscale);
float raia_glfw_get_window_opacity(GLFWwindow *window);
void raia_glfw_set_window_opacity(GLFWwindow *window, float opacity);
void raia_glfw_iconify_window(GLFWwindow *window);
void raia_glfw_restore_window(GLFWwindow *window);
void raia_glfw_maximize_window(GLFWwindow *window);
void raia_glfw_show_window(GLFWwindow *window);
void raia_glfw_hide_window(GLFWwindow *window);
void raia_glfw_focus_window(GLFWwindow *window);
void raia_glfw_request_window_attention(GLFWwindow *window);
GLFWmonitor *raia_glfw_get_window_monitor(GLFWwindow *window);
void raia_glfw_set_window_monitor(GLFWwindow *window, GLFWmonitor *monitor, int xpos, int ypos, int width, int height, int refreshRate);
int raia_glfw_get_window_attrib(GLFWwindow *window, int attrib);
void raia_glfw_set_window_attrib(GLFWwindow *window, int attrib, int value);
void raia_glfw_set_window_user_pointer(GLFWwindow *window, void *pointer);
void *raia_glfw_get_window_user_pointer(GLFWwindow *window);
GLFWwindowposfun raia_glfw_set_window_pos_callback(GLFWwindow *window, GLFWwindowposfun callback);
GLFWwindowsizefun raia_glfw_set_window_size_callback(GLFWwindow *window, GLFWwindowsizefun callback);
GLFWwindowclosefun raia_glfw_set_window_close_callback(GLFWwindow *window, GLFWwindowclosefun callback);
GLFWwindowrefreshfun raia_glfw_set_window_refresh_callback(GLFWwindow *window, GLFWwindowrefreshfun callback);
GLFWwindowfocusfun raia_glfw_set_window_focus_callback(GLFWwindow *window, GLFWwindowfocusfun callback);
GLFWwindowiconifyfun raia_glfw_set_window_iconify_callback(GLFWwindow *window, GLFWwindowiconifyfun callback);
GLFWwindowmaximizefun raia_glfw_set_window_maximize_callback(GLFWwindow *window, GLFWwindowmaximizefun callback);
GLFWframebuffersizefun raia_glfw_set_framebuffer_size_callback(GLFWwindow *window, GLFWframebuffersizefun callback);
GLFWwindowcontentscalefun raia_glfw_set_window_content_scale_callback(GLFWwindow *window, GLFWwindowcontentscalefun callback);
void raia_glfw_poll_events(void);
void raia_glfw_wait_events(void);
void raia_glfw_wait_events_timeout(double timeout);
void raia_glfw_post_empty_event(void);
void raia_glfw_swap_buffers(GLFWwindow *window);

// MARK: (代替関数)

// Error

void raia_glfw_set_error_callback_alt(void);
int raia_glfw_get_error_code(void);
const char *raia_glfw_get_error_message(void);

// Joystick

void raia_glfw_set_joystick_callback_alt(void);
int raia_glfw_get_joystick_id(void);
int raia_glfw_get_joystick_event(void);

// Monitor

void raia_glfw_set_monitor_callback_alt(void);
GLFWmonitor* raia_glfw_get_monitor(void);
int raia_glfw_get_monitor_event(void);

// Pos

void raia_glfw_set_window_pos_callback_alt(GLFWwindow *window);
int raia_glfw_get_window_pos_x(GLFWwindow *window);
int raia_glfw_get_window_pos_y(GLFWwindow *window);

// Size

void raia_glfw_set_window_size_callback_alt(GLFWwindow *window);
int raia_glfw_get_window_size_width(GLFWwindow *window);
int raia_glfw_get_window_size_height(GLFWwindow *window);

// Close

void raia_glfw_set_window_close_callback_alt(GLFWwindow *window);
bool raia_glfw_get_window_close(GLFWwindow *window);

// Refresh

void raia_glfw_set_window_refresh_callback_alt(GLFWwindow *window);
bool raia_glfw_get_window_refresh(GLFWwindow *window);

// Focus

void raia_glfw_set_window_focus_callback_alt(GLFWwindow *window);
int raia_glfw_get_window_focus(GLFWwindow *window);

// Iconify

void raia_glfw_set_window_iconify_callback_alt(GLFWwindow *window);
int raia_glfw_get_window_iconified(GLFWwindow *window);

// Framebuffer Size

void raia_glfw_set_framebuffer_size_callback_alt(GLFWwindow *window);
int raia_glfw_get_framebuffer_size_width(GLFWwindow *window);
int raia_glfw_get_framebuffer_size_height(GLFWwindow *window);

// Key

void raia_glfw_set_key_callback_alt(GLFWwindow *window);
int raia_glfw_get_key_alt(GLFWwindow *window);
int raia_glfw_get_key_scancode_alt(GLFWwindow *window);
int raia_glfw_get_key_action(GLFWwindow *window);
int raia_glfw_get_key_mods(GLFWwindow *window);

// Cursor pos

void raia_glfw_set_cursor_pos_callback_alt(GLFWwindow *window);
double raia_glfw_get_cursor_pos_x(GLFWwindow *window);
double raia_glfw_get_cursor_pos_y(GLFWwindow *window);

// Mouse button

void raia_glfw_set_mouse_button_callback_alt(GLFWwindow *window);
int raia_glfw_get_mouse_button_alt(GLFWwindow *window);
int raia_glfw_get_mouse_action(GLFWwindow *window);
int raia_glfw_get_mouse_mods(GLFWwindow *window);

// Char

void raia_glfw_set_char_callback_alt(GLFWwindow *window);
unsigned int raia_glfw_get_char(GLFWwindow *window);

// Char mods

void raia_glfw_set_char_mods_callback_alt(GLFWwindow *window);
unsigned int raia_glfw_get_char_mods_codepoint(GLFWwindow *window);
int raia_glfw_get_char_mods_mods(GLFWwindow *window);

// Cursor enter

void raia_glfw_set_cursor_enter_callback_alt(GLFWwindow *window);
int raia_glfw_get_cursor_enter(GLFWwindow *window);

// Scroll

void raia_glfw_set_scroll_callback_alt(GLFWwindow *window);
int raia_glfw_get_scroll_offset_x(GLFWwindow *window);
int raia_glfw_get_scroll_offset_y(GLFWwindow *window);

// Drop

void raia_glfw_set_drop_callback_alt(GLFWwindow *window);
int raia_glfw_get_drop_count(GLFWwindow *window);
const char** raia_glfw_get_drop_paths(GLFWwindow *window);

// Maximized

void raia_glfw_set_window_maximize_callback_alt(GLFWwindow *window);
int raia_glfw_get_window_maximized(GLFWwindow *window);

// Content scale

void raia_glfw_set_window_content_scale_callback_alt(GLFWwindow *window);
float raia_glfw_get_window_content_scale_x(GLFWwindow *window);
float raia_glfw_get_window_content_scale_y(GLFWwindow *window);

#ifdef __cplusplus
}
#endif

#endif //RAIA_GUI_RAIA_GLFW_H
