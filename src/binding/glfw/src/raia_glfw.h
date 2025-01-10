//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GLFW_H
#define RAIA_GUI_RAIA_GLFW_H

#ifdef __cplusplus
extern "C" {
#endif

//
// コンテキスト
//

void raia_glfw_make_context_current(void *window);
void *raia_glfw_get_current_context(void);
void raia_glfw_swap_interval(int interval);
int raia_glfw_extension_supported(const char *extension);
void *raia_glfw_get_proc_address(const char *procname);

//
// 初期化・バージョン・エラー
//

int raia_glfw_init(void);
void raia_glfw_terminate(void);
void raia_glfw_init_hint(int hint, int value);
void raia_glfw_get_version(void *major, void *minor, void *rev);
const char *raia_glfw_get_version_string(void);
int raia_glfw_get_error(const char **description);
void * raia_glfw_set_error_callback(void * callback);

//
// 入力
//

int raia_glfw_get_input_mode(void *window, int mode);
void raia_glfw_set_input_mode(void *window, int mode, int value);
int raia_glfw_raw_mouse_motion_supported(void);
const char *raia_glfw_get_key_name(int key, int scancode);
int raia_glfw_get_key_scancode(int key);
int raia_glfw_get_key(void *window, int key);
int raia_glfw_get_mouse_button(void *window, int button);
void raia_glfw_get_cursor_pos(void *window, double *xpos, double *ypos);
void raia_glfw_set_cursor_pos(void *window, double xpos, double ypos);
void *raia_glfw_create_cursor(const void *image, int xhot, int yhot);
void *raia_glfw_create_standard_cursor(int shape);
void raia_glfw_destroy_cursor(void *cursor);
void raia_glfw_set_cursor(void *window, void *cursor);
void * raia_glfw_set_key_callback(void *window, void * callback);
void * raia_glfw_set_char_callback(void *window, void * callback);
void * raia_glfw_set_char_mods_callback(void *window, void * callback);
void * raia_glfw_set_mouse_button_callback(void *window, void * callback);
void * raia_glfw_set_cursor_pos_callback(void *window, void * callback);
void * raia_glfw_set_cursor_enter_callback(void *window, void * callback);
void * raia_glfw_set_scroll_callback(void *window, void * callback);
void * raia_glfw_set_drop_callback(void *window, void * callback);
int raia_glfw_joystick_present(int jid);
const void *raia_glfw_get_joystick_axes(int jid, void *count);
const unsigned char *raia_glfw_get_joystick_buttons(int jid, void *count);
const unsigned char *raia_glfw_get_joystick_hats(int jid, void *count);
const char *raia_glfw_get_joystick_name(int jid);
const char *raia_glfw_get_joystick_guid(int jid);
void raia_glfw_set_joystick_user_pointer(int jid, void *pointer);
void *raia_glfw_get_joystick_user_pointer(int jid);
int raia_glfw_joystick_is_gamepad(int jid);
void * raia_glfw_set_joystick_callback(void * callback);
int raia_glfw_update_gamepad_mappings(const char *string);
const char *raia_glfw_get_gamepad_name(int jid);
int raia_glfw_get_gamepad_state(int jid, void *state);
void raia_glfw_set_clipboard_string(void *window, const char *string);
const char *raia_glfw_get_clipboard_string(void *window);
double raia_glfw_get_time(void);
void raia_glfw_set_time(double time);
unsigned long long raia_glfw_get_timer_value(void);
unsigned long long raia_glfw_get_timer_frequency(void);

//
// モニター
//

void **raia_glfw_get_monitors(void *count);
void *raia_glfw_get_primary_monitor(void);
void raia_glfw_get_monitor_pos(void *monitor, void *xpos, void *ypos);
void raia_glfw_get_monitor_workarea(void *monitor, void *xpos, void *ypos, void *width, void *height);
void raia_glfw_get_monitor_physical_size(void *monitor, void *widthMM, void *heightMM);
void raia_glfw_get_monitor_content_scale(void *monitor, void *xscale, void *yscale);
const char *raia_glfw_get_monitor_name(void *monitor);
void raia_glfw_set_monitor_user_pointer(void *monitor, void *pointer);
void *raia_glfw_get_monitor_user_pointer(void *monitor);
void * raia_glfw_set_monitor_callback(void * callback);
const void *raia_glfw_get_video_modes(void *monitor, void *count);
const void *raia_glfw_get_video_mode(void *monitor);
void raia_glfw_set_gamma(void *monitor, float gamma);
const void *raia_glfw_get_gamma_ramp(void *monitor);
void raia_glfw_set_gamma_ramp(void *monitor, const void *ramp);

//
// ネイティブアクセス
//

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

//
// Vulkanサポート
//

int raia_glfw_vulkan_supported(void);
const char **raia_glfw_get_required_instance_extensions(void *count);

// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

//
// ウィンドウ
//

void raia_glfw_default_window_hints(void);
void raia_glfw_window_hint(int hint, int value);
void raia_glfw_window_hint_string(int hint, const char *value);
void *raia_glfw_create_window(int width, int height, const char *title, void *monitor, void *share);
void raia_glfw_destroy_window(void *window);
int raia_glfw_window_should_close(void *window);
void raia_glfw_set_window_should_close(void *window, int value);
void raia_glfw_set_window_title(void *window, const char *title);
void raia_glfw_set_window_icon(void *window, int count, const void *images);
void raia_glfw_get_window_pos(void *window, void *xpos, void *ypos);
void raia_glfw_set_window_pos(void *window, int xpos, int ypos);
void raia_glfw_get_window_size(void *window, void *width, void *height);
void raia_glfw_set_window_size_limits(void *window, int minwidth, int minheight, int maxwidth, int maxheight);
void raia_glfw_set_window_aspect_ratio(void *window, int numer, int denom);
void raia_glfw_set_window_size(void *window, int width, int height);
void raia_glfw_get_framebuffer_size(void *window, void *width, void *height);
void raia_glfw_get_window_frame_size(void *window, void *left, void *top, void *right, void *bottom);
void raia_glfw_get_window_content_scale(void *window, void *xscale, void *yscale);
float raia_glfw_get_window_opacity(void *window);
void raia_glfw_set_window_opacity(void *window, float opacity);
void raia_glfw_iconify_window(void *window);
void raia_glfw_restore_window(void *window);
void raia_glfw_maximize_window(void *window);
void raia_glfw_show_window(void *window);
void raia_glfw_hide_window(void *window);
void raia_glfw_focus_window(void *window);
void raia_glfw_request_window_attention(void *window);
void *raia_glfw_get_window_monitor(void *window);
void raia_glfw_set_window_monitor(void *window, void *monitor, int xpos, int ypos, int width, int height, int refreshRate);
int raia_glfw_get_window_attrib(void *window, int attrib);
void raia_glfw_set_window_attrib(void *window, int attrib, int value);
void raia_glfw_set_window_user_pointer(void *window, void *pointer);
void *raia_glfw_get_window_user_pointer(void *window);
void * raia_glfw_set_window_pos_callback(void *window, void * callback);
void * raia_glfw_set_window_size_callback(void *window, void * callback);
void * raia_glfw_set_window_close_callback(void *window, void * callback);
void * raia_glfw_set_window_refresh_callback(void *window, void * callback);
void * raia_glfw_set_window_focus_callback(void *window, void * callback);
void * raia_glfw_set_window_iconify_callback(void *window, void * callback);
void * raia_glfw_set_window_maximize_callback(void *window, void * callback);
void * raia_glfw_set_framebuffer_size_callback(void *window, void * callback);
void * raia_glfw_set_window_content_scale_callback(void *window, void * callback);
void raia_glfw_poll_events(void);
void raia_glfw_wait_events(void);
void raia_glfw_wait_events_timeout(double timeout);
void raia_glfw_post_empty_event(void);
void raia_glfw_swap_buffers(void *window);

// (代替関数)

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
void *raia_glfw_get_monitor(void);
int raia_glfw_get_monitor_event(void);

// Pos

void raia_glfw_set_window_pos_callback_alt(void *window);
int raia_glfw_get_window_pos_x(void *window);
int raia_glfw_get_window_pos_y(void *window);

// Size

void raia_glfw_set_window_size_callback_alt(void *window);
int raia_glfw_get_window_size_width(void *window);
int raia_glfw_get_window_size_height(void *window);

// Close

void raia_glfw_set_window_close_callback_alt(void *window);
int raia_glfw_get_window_close(void *window);

// Refresh

void raia_glfw_set_window_refresh_callback_alt(void *window);
int raia_glfw_get_window_refresh(void *window);

// Focus

void raia_glfw_set_window_focus_callback_alt(void *window);
int raia_glfw_get_window_focus(void *window);

// Iconify

void raia_glfw_set_window_iconify_callback_alt(void *window);
int raia_glfw_get_window_iconified(void *window);

// Framebuffer Size

void raia_glfw_set_framebuffer_size_callback_alt(void *window);
int raia_glfw_get_framebuffer_size_width(void *window);
int raia_glfw_get_framebuffer_size_height(void *window);

// Key

void raia_glfw_set_key_callback_alt(void *window);
int raia_glfw_get_key_alt(void *window);
int raia_glfw_get_key_scancode_alt(void *window);
int raia_glfw_get_key_action(void *window);
int raia_glfw_get_key_mods(void *window);

// Cursor pos

void raia_glfw_set_cursor_pos_callback_alt(void *window);
double raia_glfw_get_cursor_pos_x(void *window);
double raia_glfw_get_cursor_pos_y(void *window);

// Mouse button

void raia_glfw_set_mouse_button_callback_alt(void *window);
int raia_glfw_get_mouse_button_alt(void *window);
int raia_glfw_get_mouse_action(void *window);
int raia_glfw_get_mouse_mods(void *window);

// Char

void raia_glfw_set_char_callback_alt(void *window);
unsigned int raia_glfw_get_char(void *window);

// Char mods

void raia_glfw_set_char_mods_callback_alt(void *window);
unsigned int raia_glfw_get_char_mods_codepoint(void *window);
int raia_glfw_get_char_mods_mods(void *window);

// Cursor enter

void raia_glfw_set_cursor_enter_callback_alt(void *window);
int raia_glfw_get_cursor_enter(void *window);

// Scroll

void raia_glfw_set_scroll_callback_alt(void *window);
int raia_glfw_get_scroll_offset_x(void *window);
int raia_glfw_get_scroll_offset_y(void *window);

// Drop

void raia_glfw_set_drop_callback_alt(void *window);
int raia_glfw_get_drop_count(void *window);
const char** raia_glfw_get_drop_paths(void *window);

// Maximized

void raia_glfw_set_window_maximize_callback_alt(void *window);
int raia_glfw_get_window_maximized(void *window);

// Content scale

void raia_glfw_set_window_content_scale_callback_alt(void *window);
float raia_glfw_get_window_content_scale_x(void *window);
float raia_glfw_get_window_content_scale_y(void *window);

#ifdef __cplusplus
}
#endif

#endif //RAIA_GUI_RAIA_GLFW_H
