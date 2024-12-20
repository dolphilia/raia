//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GLFW_H
#define RAIA_GUI_RAIA_GLFW_H

#include <stdbool.h>
#include "GLFW/glfw3.h"
#include "../../../common/c/utility/export_api.h"

//
// コンテキスト
//

RAIA_API void raia_glfw_make_context_current(GLFWwindow *window);
RAIA_API GLFWwindow *raia_glfw_get_current_context(void);
RAIA_API void raia_glfw_swap_interval(int interval);
RAIA_API int raia_glfw_extension_supported(const char *extension);
RAIA_API GLFWglproc raia_glfw_get_proc_address(const char *procname);

//
// 初期化・バージョン・エラー
//

RAIA_API int raia_glfw_init(void);
RAIA_API void raia_glfw_terminate(void);
RAIA_API void raia_glfw_init_hint(int hint, int value);
RAIA_API void raia_glfw_get_version(int *major, int *minor, int *rev);
RAIA_API const char *raia_glfw_get_version_string(void);
RAIA_API int raia_glfw_get_error(const char **description);
RAIA_API GLFWerrorfun raia_glfw_set_error_callback(GLFWerrorfun callback);

//
// 入力
//

RAIA_API int raia_glfw_get_input_mode(GLFWwindow *window, int mode);
RAIA_API void raia_glfw_set_input_mode(GLFWwindow *window, int mode, int value);
RAIA_API int raia_glfw_raw_mouse_motion_supported(void);
RAIA_API const char *raia_glfw_get_key_name(int key, int scancode);
RAIA_API int raia_glfw_get_key_scancode(int key);
RAIA_API int raia_glfw_get_key(GLFWwindow *window, int key);
RAIA_API int raia_glfw_get_mouse_button(GLFWwindow *window, int button);
RAIA_API void raia_glfw_get_cursor_pos(GLFWwindow *window, double *xpos, double *ypos);
RAIA_API void raia_glfw_set_cursor_pos(GLFWwindow *window, double xpos, double ypos);
RAIA_API GLFWcursor *raia_glfw_create_cursor(const GLFWimage *image, int xhot, int yhot);
RAIA_API GLFWcursor *raia_glfw_create_standard_cursor(int shape);
RAIA_API void raia_glfw_destroy_cursor(GLFWcursor *cursor);
RAIA_API void raia_glfw_set_cursor(GLFWwindow *window, GLFWcursor *cursor);
RAIA_API GLFWkeyfun raia_glfw_set_key_callback(GLFWwindow *window, GLFWkeyfun callback);
RAIA_API GLFWcharfun raia_glfw_set_char_callback(GLFWwindow *window, GLFWcharfun callback);
RAIA_API GLFWcharmodsfun raia_glfw_set_char_mods_callback(GLFWwindow *window, GLFWcharmodsfun callback);
RAIA_API GLFWmousebuttonfun raia_glfw_set_mouse_button_callback(GLFWwindow *window, GLFWmousebuttonfun callback);
RAIA_API GLFWcursorposfun raia_glfw_set_cursor_pos_callback(GLFWwindow *window, GLFWcursorposfun callback);
RAIA_API GLFWcursorenterfun raia_glfw_set_cursor_enter_callback(GLFWwindow *window, GLFWcursorenterfun callback);
RAIA_API GLFWscrollfun raia_glfw_set_scroll_callback(GLFWwindow *window, GLFWscrollfun callback);
RAIA_API GLFWdropfun raia_glfw_set_drop_callback(GLFWwindow *window, GLFWdropfun callback);
RAIA_API int raia_glfw_joystick_present(int jid);
RAIA_API const float *raia_glfw_get_joystick_axes(int jid, int *count);
RAIA_API const unsigned char *raia_glfw_get_joystick_buttons(int jid, int *count);
RAIA_API const unsigned char *raia_glfw_get_joystick_hats(int jid, int *count);
RAIA_API const char *raia_glfw_get_joystick_name(int jid);
RAIA_API const char *raia_glfw_get_joystick_guid(int jid);
RAIA_API void raia_glfw_set_joystick_user_pointer(int jid, void *pointer);
RAIA_API void *raia_glfw_get_joystick_user_pointer(int jid);
RAIA_API int raia_glfw_joystick_is_gamepad(int jid);
RAIA_API GLFWjoystickfun raia_glfw_set_joystick_callback(GLFWjoystickfun callback);
RAIA_API int raia_glfw_update_gamepad_mappings(const char *string);
RAIA_API const char *raia_glfw_get_gamepad_name(int jid);
RAIA_API int raia_glfw_get_gamepad_state(int jid, GLFWgamepadstate *state);
RAIA_API void raia_glfw_set_clipboard_string(GLFWwindow *window, const char *string);
RAIA_API const char *raia_glfw_get_clipboard_string(GLFWwindow *window);
RAIA_API double raia_glfw_get_time(void);
RAIA_API void raia_glfw_set_time(double time);
RAIA_API uint64_t raia_glfw_get_timer_value(void);
RAIA_API uint64_t raia_glfw_get_timer_frequency(void);

//
// モニター
//

RAIA_API GLFWmonitor **raia_glfw_get_monitors(int *count);
RAIA_API GLFWmonitor *raia_glfw_get_primary_monitor(void);
RAIA_API void raia_glfw_get_monitor_pos(GLFWmonitor *monitor, int *xpos, int *ypos);
RAIA_API void raia_glfw_get_monitor_workarea(GLFWmonitor *monitor, int *xpos, int *ypos, int *width, int *height);
RAIA_API void raia_glfw_get_monitor_physical_size(GLFWmonitor *monitor, int *widthMM, int *heightMM);
RAIA_API void raia_glfw_get_monitor_content_scale(GLFWmonitor *monitor, float *xscale, float *yscale);
RAIA_API const char *raia_glfw_get_monitor_name(GLFWmonitor *monitor);
RAIA_API void raia_glfw_set_monitor_user_pointer(GLFWmonitor *monitor, void *pointer);
RAIA_API void *raia_glfw_get_monitor_user_pointer(GLFWmonitor *monitor);
RAIA_API GLFWmonitorfun raia_glfw_set_monitor_callback(GLFWmonitorfun callback);
RAIA_API const GLFWvidmode *raia_glfw_get_video_modes(GLFWmonitor *monitor, int *count);
RAIA_API const GLFWvidmode *raia_glfw_get_video_mode(GLFWmonitor *monitor);
RAIA_API void raia_glfw_set_gamma(GLFWmonitor *monitor, float gamma);
RAIA_API const GLFWgammaramp *raia_glfw_get_gamma_ramp(GLFWmonitor *monitor);
RAIA_API void raia_glfw_set_gamma_ramp(GLFWmonitor *monitor, const GLFWgammaramp *ramp);

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

RAIA_API int raia_glfw_vulkan_supported(void);
RAIA_API const char **raia_glfw_get_required_instance_extensions(uint32_t *count);

// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

//
// ウィンドウ
//

RAIA_API void raia_glfw_default_window_hints(void);
RAIA_API void raia_glfw_window_hint(int hint, int value);
RAIA_API void raia_glfw_window_hint_string(int hint, const char *value);
RAIA_API GLFWwindow *raia_glfw_create_window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share);
RAIA_API void raia_glfw_destroy_window(GLFWwindow *window);
RAIA_API int raia_glfw_window_should_close(GLFWwindow *window);
RAIA_API void raia_glfw_set_window_should_close(GLFWwindow *window, int value);
RAIA_API void raia_glfw_set_window_title(GLFWwindow *window, const char *title);
RAIA_API void raia_glfw_set_window_icon(GLFWwindow *window, int count, const GLFWimage *images);
RAIA_API void raia_glfw_get_window_pos(GLFWwindow *window, int *xpos, int *ypos);
RAIA_API void raia_glfw_set_window_pos(GLFWwindow *window, int xpos, int ypos);
RAIA_API void raia_glfw_get_window_size(GLFWwindow *window, int *width, int *height);
RAIA_API void raia_glfw_set_window_size_limits(GLFWwindow *window, int minwidth, int minheight, int maxwidth, int maxheight);
RAIA_API void raia_glfw_set_window_aspect_ratio(GLFWwindow *window, int numer, int denom);
RAIA_API void raia_glfw_set_window_size(GLFWwindow *window, int width, int height);
RAIA_API void raia_glfw_get_framebuffer_size(GLFWwindow *window, int *width, int *height);
RAIA_API void raia_glfw_get_window_frame_size(GLFWwindow *window, int *left, int *top, int *right, int *bottom);
RAIA_API void raia_glfw_get_window_content_scale(GLFWwindow *window, float *xscale, float *yscale);
RAIA_API float raia_glfw_get_window_opacity(GLFWwindow *window);
RAIA_API void raia_glfw_set_window_opacity(GLFWwindow *window, float opacity);
RAIA_API void raia_glfw_iconify_window(GLFWwindow *window);
RAIA_API void raia_glfw_restore_window(GLFWwindow *window);
RAIA_API void raia_glfw_maximize_window(GLFWwindow *window);
RAIA_API void raia_glfw_show_window(GLFWwindow *window);
RAIA_API void raia_glfw_hide_window(GLFWwindow *window);
RAIA_API void raia_glfw_focus_window(GLFWwindow *window);
RAIA_API void raia_glfw_request_window_attention(GLFWwindow *window);
RAIA_API GLFWmonitor *raia_glfw_get_window_monitor(GLFWwindow *window);
RAIA_API void raia_glfw_set_window_monitor(GLFWwindow *window, GLFWmonitor *monitor, int xpos, int ypos, int width, int height, int refreshRate);
RAIA_API int raia_glfw_get_window_attrib(GLFWwindow *window, int attrib);
RAIA_API void raia_glfw_set_window_attrib(GLFWwindow *window, int attrib, int value);
RAIA_API void raia_glfw_set_window_user_pointer(GLFWwindow *window, void *pointer);
RAIA_API void *raia_glfw_get_window_user_pointer(GLFWwindow *window);
RAIA_API GLFWwindowposfun raia_glfw_set_window_pos_callback(GLFWwindow *window, GLFWwindowposfun callback);
RAIA_API GLFWwindowsizefun raia_glfw_set_window_size_callback(GLFWwindow *window, GLFWwindowsizefun callback);
RAIA_API GLFWwindowclosefun raia_glfw_set_window_close_callback(GLFWwindow *window, GLFWwindowclosefun callback);
RAIA_API GLFWwindowrefreshfun raia_glfw_set_window_refresh_callback(GLFWwindow *window, GLFWwindowrefreshfun callback);
RAIA_API GLFWwindowfocusfun raia_glfw_set_window_focus_callback(GLFWwindow *window, GLFWwindowfocusfun callback);
RAIA_API GLFWwindowiconifyfun raia_glfw_set_window_iconify_callback(GLFWwindow *window, GLFWwindowiconifyfun callback);
RAIA_API GLFWwindowmaximizefun raia_glfw_set_window_maximize_callback(GLFWwindow *window, GLFWwindowmaximizefun callback);
RAIA_API GLFWframebuffersizefun raia_glfw_set_framebuffer_size_callback(GLFWwindow *window, GLFWframebuffersizefun callback);
RAIA_API GLFWwindowcontentscalefun raia_glfw_set_window_content_scale_callback(GLFWwindow *window, GLFWwindowcontentscalefun callback);
RAIA_API void raia_glfw_poll_events(void);
RAIA_API void raia_glfw_wait_events(void);
RAIA_API void raia_glfw_wait_events_timeout(double timeout);
RAIA_API void raia_glfw_post_empty_event(void);
RAIA_API void raia_glfw_swap_buffers(GLFWwindow *window);

// (代替関数)

// Error

RAIA_API void raia_glfw_set_error_callback_alt(void);
RAIA_API int raia_glfw_get_error_code(void);
RAIA_API const char *raia_glfw_get_error_message(void);

// Joystick

RAIA_API void raia_glfw_set_joystick_callback_alt(void);
RAIA_API int raia_glfw_get_joystick_id(void);
RAIA_API int raia_glfw_get_joystick_event(void);

// Monitor

RAIA_API void raia_glfw_set_monitor_callback_alt(void);
RAIA_API GLFWmonitor* raia_glfw_get_monitor(void);
RAIA_API int raia_glfw_get_monitor_event(void);

// Pos

RAIA_API void raia_glfw_set_window_pos_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_pos_x(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_pos_y(GLFWwindow *window);

// Size

RAIA_API void raia_glfw_set_window_size_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_size_width(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_size_height(GLFWwindow *window);

// Close

RAIA_API void raia_glfw_set_window_close_callback_alt(GLFWwindow *window);
RAIA_API bool raia_glfw_get_window_close(GLFWwindow *window);

// Refresh

RAIA_API void raia_glfw_set_window_refresh_callback_alt(GLFWwindow *window);
RAIA_API bool raia_glfw_get_window_refresh(GLFWwindow *window);

// Focus

RAIA_API void raia_glfw_set_window_focus_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_focus(GLFWwindow *window);

// Iconify

RAIA_API void raia_glfw_set_window_iconify_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_iconified(GLFWwindow *window);

// Framebuffer Size

RAIA_API void raia_glfw_set_framebuffer_size_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_framebuffer_size_width(GLFWwindow *window);
RAIA_API int raia_glfw_get_framebuffer_size_height(GLFWwindow *window);

// Key

RAIA_API void raia_glfw_set_key_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_key_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_key_scancode_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_key_action(GLFWwindow *window);
RAIA_API int raia_glfw_get_key_mods(GLFWwindow *window);

// Cursor pos

RAIA_API void raia_glfw_set_cursor_pos_callback_alt(GLFWwindow *window);
RAIA_API double raia_glfw_get_cursor_pos_x(GLFWwindow *window);
RAIA_API double raia_glfw_get_cursor_pos_y(GLFWwindow *window);

// Mouse button

RAIA_API void raia_glfw_set_mouse_button_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_mouse_button_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_mouse_action(GLFWwindow *window);
RAIA_API int raia_glfw_get_mouse_mods(GLFWwindow *window);

// Char

RAIA_API void raia_glfw_set_char_callback_alt(GLFWwindow *window);
RAIA_API unsigned int raia_glfw_get_char(GLFWwindow *window);

// Char mods

RAIA_API void raia_glfw_set_char_mods_callback_alt(GLFWwindow *window);
RAIA_API unsigned int raia_glfw_get_char_mods_codepoint(GLFWwindow *window);
RAIA_API int raia_glfw_get_char_mods_mods(GLFWwindow *window);

// Cursor enter

RAIA_API void raia_glfw_set_cursor_enter_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_cursor_enter(GLFWwindow *window);

// Scroll

RAIA_API void raia_glfw_set_scroll_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_scroll_offset_x(GLFWwindow *window);
RAIA_API int raia_glfw_get_scroll_offset_y(GLFWwindow *window);

// Drop

RAIA_API void raia_glfw_set_drop_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_drop_count(GLFWwindow *window);
RAIA_API const char** raia_glfw_get_drop_paths(GLFWwindow *window);

// Maximized

RAIA_API void raia_glfw_set_window_maximize_callback_alt(GLFWwindow *window);
RAIA_API int raia_glfw_get_window_maximized(GLFWwindow *window);

// Content scale

RAIA_API void raia_glfw_set_window_content_scale_callback_alt(GLFWwindow *window);
RAIA_API float raia_glfw_get_window_content_scale_x(GLFWwindow *window);
RAIA_API float raia_glfw_get_window_content_scale_y(GLFWwindow *window);

#endif //RAIA_GUI_RAIA_GLFW_H
