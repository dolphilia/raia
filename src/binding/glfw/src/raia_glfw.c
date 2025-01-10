
#include "raia_glfw.h"
#include "static/static_callback.h"
#include <GLFW/glfw3.h>

//
// コンテキスト
//

void raia_glfw_make_context_current(void *window) {
    glfwMakeContextCurrent(window);
}

void *raia_glfw_get_current_context(void) {
    return glfwGetCurrentContext();
}

void raia_glfw_swap_interval(int interval) {
    glfwSwapInterval(interval);
}

int raia_glfw_extension_supported(const char *extension) {
    return glfwExtensionSupported(extension);
}

void *raia_glfw_get_proc_address(const char *procname) {
    return glfwGetProcAddress(procname);
}

//
// 初期化・バージョン・エラー
//

int raia_glfw_init(void) {
    return glfwInit();
}

void raia_glfw_terminate(void) {
    glfwTerminate();
}

void raia_glfw_init_hint(int hint, int value) {
    glfwInitHint(hint, value);
}

void raia_glfw_get_version(void *major, void *minor, void *rev) {
    glfwGetVersion(major, minor, rev);
}

const char *raia_glfw_get_version_string(void) {
    return glfwGetVersionString();
}

int raia_glfw_get_error(const char **description) {
    return glfwGetError(description);
}

void * raia_glfw_set_error_callback(void * callback) {
    return glfwSetErrorCallback(callback);
}

//
// 入力
//

int raia_glfw_get_input_mode(void *window, int mode) {
    return glfwGetInputMode(window, mode);
}

void raia_glfw_set_input_mode(void *window, int mode, int value) {
    glfwSetInputMode(window, mode, value);
}

int raia_glfw_raw_mouse_motion_supported(void) {
    return glfwRawMouseMotionSupported();
}

const char *raia_glfw_get_key_name(int key, int scancode) {
    return glfwGetKeyName(key, scancode);
}

int raia_glfw_get_key_scancode(int key){
    return glfwGetKeyScancode(key);
}

int raia_glfw_get_key(void *window, int key) {
    return glfwGetKey(window, key);
}

int raia_glfw_get_mouse_button(void *window, int button) {
    return glfwGetMouseButton(window, button);
}

void raia_glfw_get_cursor_pos(void *window, double *xpos, double *ypos) {
    glfwGetCursorPos(window, xpos, ypos);
}

void raia_glfw_set_cursor_pos(void *window, double xpos, double ypos) {
    glfwSetCursorPos(window, xpos, ypos);
}

void *raia_glfw_create_cursor(const void *image, int xhot, int yhot) {
    return glfwCreateCursor(image, xhot, yhot);
}

void *raia_glfw_create_standard_cursor(int shape) {
    return glfwCreateStandardCursor(shape);
}

void raia_glfw_destroy_cursor(void *cursor) {
    glfwDestroyCursor(cursor);
}

void raia_glfw_set_cursor(void *window, void *cursor) {
    glfwSetCursor(window, cursor);
}

void * raia_glfw_set_key_callback(void *window, void * callback) {
    return glfwSetKeyCallback(window, callback);
}

void * raia_glfw_set_char_callback(void *window, void * callback) {
    return glfwSetCharCallback(window, callback);
}

void * raia_glfw_set_char_mods_callback(void *window, void * callback) {
    return glfwSetCharModsCallback(window, callback);
}

void * raia_glfw_set_mouse_button_callback(void *window, void * callback) {
    return glfwSetMouseButtonCallback(window, callback);
}

void * raia_glfw_set_cursor_pos_callback(void *window, void * callback) {
    return glfwSetCursorPosCallback(window, callback);
}

void * raia_glfw_set_cursor_enter_callback(void *window, void * callback) {
    return glfwSetCursorEnterCallback(window, callback);
}

void * raia_glfw_set_scroll_callback(void *window, void * callback) {
    return glfwSetScrollCallback(window, callback);
}

void * raia_glfw_set_drop_callback(void *window, void * callback) {
    return glfwSetDropCallback(window, callback);
}

int raia_glfw_joystick_present(int jid) {
    return glfwJoystickPresent(jid);
}

const void *raia_glfw_get_joystick_axes(int jid, void *count) {
    return glfwGetJoystickAxes(jid, count); // 返された配列は，GLFWによって確保・解放される
}

const unsigned char *raia_glfw_get_joystick_buttons(int jid, void *count) {
    return glfwGetJoystickButtons(jid, count); // 返された配列は、GLFWによって割り当てられ、解放される。
}

const unsigned char *raia_glfw_get_joystick_hats(int jid, void *count) {
    return glfwGetJoystickHats(jid, count);
}

const char *raia_glfw_get_joystick_name(int jid) {
    return glfwGetJoystickName(jid);
}

const char *raia_glfw_get_joystick_guid(int jid) {
    return glfwGetJoystickGUID(jid);
}

void raia_glfw_set_joystick_user_pointer(int jid, void *pointer) {
    glfwSetJoystickUserPointer(jid, pointer);
}

void *raia_glfw_get_joystick_user_pointer(int jid) {
    return glfwGetJoystickUserPointer(jid);
}

int raia_glfw_joystick_is_gamepad(int jid) {
    return glfwJoystickIsGamepad(jid);
}

void * raia_glfw_set_joystick_callback(void * callback) {
    return glfwSetJoystickCallback(callback);
}

int raia_glfw_update_gamepad_mappings(const char *string) {
    return glfwUpdateGamepadMappings(string);
}

const char *raia_glfw_get_gamepad_name(int jid) {
    return glfwGetGamepadName(jid);
}

int raia_glfw_get_gamepad_state(int jid, void *state) {
    return glfwGetGamepadState(jid, state);
}

void raia_glfw_set_clipboard_string(void *window, const char *string) {
    glfwSetClipboardString(window, string);
}

const char *raia_glfw_get_clipboard_string(void *window) {
    return glfwGetClipboardString(window);
}

double raia_glfw_get_time(void) {
    return glfwGetTime();
}

void raia_glfw_set_time(double time) {
    glfwSetTime(time);
}

unsigned long long raia_glfw_get_timer_value(void) {
    return glfwGetTimerValue();
}

unsigned long long raia_glfw_get_timer_frequency(void) {
    return glfwGetTimerFrequency();
}

//
// モニター
//

void **raia_glfw_get_monitors(void *count) {
    return glfwGetMonitors(count);
}

void *raia_glfw_get_primary_monitor(void) {
    return glfwGetPrimaryMonitor();
}

void raia_glfw_get_monitor_pos(void *monitor, void *xpos, void *ypos) {
    glfwGetMonitorPos(monitor, xpos, ypos);
}

void raia_glfw_get_monitor_workarea(void *monitor, void *xpos, void *ypos, void *width, void *height) {
    glfwGetMonitorWorkarea(monitor,xpos, ypos, width, height);
}

void raia_glfw_get_monitor_physical_size(void *monitor, void *widthMM, void *heightMM) {
    glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
}

void raia_glfw_get_monitor_content_scale(void *monitor, void *xscale, void *yscale) {
    glfwGetMonitorContentScale(monitor, xscale, yscale);
}

const char *raia_glfw_get_monitor_name(void *monitor) {
    return glfwGetMonitorName(monitor);
}

void raia_glfw_set_monitor_user_pointer(void *monitor, void *pointer) {
    glfwSetMonitorUserPointer(monitor, pointer);
}

void *raia_glfw_get_monitor_user_pointer(void *monitor) {
    return glfwGetMonitorUserPointer(monitor);
}

void * raia_glfw_set_monitor_callback(void * callback) {
    return glfwSetMonitorCallback(callback);
}

const void *raia_glfw_get_video_modes(void *monitor, void *count) {
    return glfwGetVideoModes(monitor, count);
}

const void *raia_glfw_get_video_mode(void *monitor) {
    return glfwGetVideoMode(monitor);
}

void raia_glfw_set_gamma(void *monitor, float gamma) {
    glfwSetGamma(monitor, gamma);
}

const void *raia_glfw_get_gamma_ramp(void *monitor) {
    return glfwGetGammaRamp(monitor);
}

void raia_glfw_set_gamma_ramp(void *monitor, const void *ramp) {
    glfwSetGammaRamp(monitor, ramp);
}

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

int raia_glfw_vulkan_supported(void) {
    return glfwVulkanSupported();
}

const char **raia_glfw_get_required_instance_extensions(void *count) {
    return glfwGetRequiredInstanceExtensions(count);
}

// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

//
// ウィンドウ
//

void raia_glfw_default_window_hints(void) {
    glfwDefaultWindowHints();
}

void raia_glfw_window_hint(int hint, int value) {
    glfwWindowHint(hint, value);
}

void raia_glfw_window_hint_string(int hint, const char *value) {
    glfwWindowHintString(hint, value);
}

void *raia_glfw_create_window(int width, int height, const char *title, void *monitor, void *share) {
    return glfwCreateWindow(width, height, title, monitor, share);
}

void raia_glfw_destroy_window(void *window) {
    glfwDestroyWindow(window);
}

int raia_glfw_window_should_close(void *window) {
    return glfwWindowShouldClose(window);
}

void raia_glfw_set_window_should_close(void *window, int value) {
    glfwSetWindowShouldClose(window, value);
}

void raia_glfw_set_window_title(void *window, const char *title) {
    glfwSetWindowTitle(window, title);
}

void raia_glfw_set_window_icon(void *window, int count, const void *images) {
    glfwSetWindowIcon(window, count, images);
}

void raia_glfw_get_window_pos(void *window, void *xpos, void *ypos) {
    glfwGetWindowPos(window, xpos, ypos);
}

void raia_glfw_set_window_pos(void *window, int xpos, int ypos) {
    glfwSetWindowPos(window, xpos, ypos);
}

void raia_glfw_get_window_size(void *window, void *width, void *height) {
    glfwGetWindowSize(window, width, height);
}

void raia_glfw_set_window_size_limits(void *window, int minwidth, int minheight, int maxwidth, int maxheight) {
    glfwSetWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight);
}

void raia_glfw_set_window_aspect_ratio(void *window, int numer, int denom) {
    glfwSetWindowAspectRatio(window, numer, denom);
}

void raia_glfw_set_window_size(void *window, int width, int height) {
    glfwSetWindowSize(window, width, height);
}

void raia_glfw_get_framebuffer_size(void *window, void *width, void *height) {
    glfwGetFramebufferSize(window, width, height);
}

void raia_glfw_get_window_frame_size(void *window, void *left, void *top, void *right, void *bottom) {
    glfwGetWindowFrameSize(window, left, top, right, bottom);
}

void raia_glfw_get_window_content_scale(void *window, void *xscale, void *yscale) {
    glfwGetWindowContentScale(window, xscale, yscale);
}

float raia_glfw_get_window_opacity(void *window) {
    return glfwGetWindowOpacity(window);
}

void raia_glfw_set_window_opacity(void *window, float opacity) {
    glfwSetWindowOpacity(window, opacity);
}

void raia_glfw_iconify_window(void *window) {
    glfwIconifyWindow(window);
}

void raia_glfw_restore_window(void *window) {
    glfwRestoreWindow(window);
}

void raia_glfw_maximize_window(void *window) {
    glfwMaximizeWindow(window);
}

void raia_glfw_show_window(void *window) {
    glfwShowWindow(window);
}

void raia_glfw_hide_window(void *window) {
    glfwHideWindow(window);
}

void raia_glfw_focus_window(void *window) {
    glfwFocusWindow(window);
}

void raia_glfw_request_window_attention(void *window) {
    glfwRequestWindowAttention(window);
}

void *raia_glfw_get_window_monitor(void *window) {
    return glfwGetWindowMonitor(window);
}

void raia_glfw_set_window_monitor(void *window, void *monitor, int xpos, int ypos, int width, int height, int refreshRate) {
    glfwSetWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate);
}

int raia_glfw_get_window_attrib(void *window, int attrib) {
    return glfwGetWindowAttrib(window, attrib);
}

void raia_glfw_set_window_attrib(void *window, int attrib, int value) {
    glfwSetWindowAttrib(window, attrib, value);
}

void raia_glfw_set_window_user_pointer(void *window, void *pointer) {
    glfwSetWindowUserPointer(window, pointer);
}

void *raia_glfw_get_window_user_pointer(void *window) {
    return glfwGetWindowUserPointer(window);
}

void * raia_glfw_set_window_pos_callback(void *window, void * callback) {
    return glfwSetWindowPosCallback(window, callback);
}

void * raia_glfw_set_window_size_callback(void *window, void * callback) {
    return glfwSetWindowSizeCallback(window, callback);
}

void * raia_glfw_set_window_close_callback(void *window, void * callback) {
    return glfwSetWindowCloseCallback(window, callback);
}

void * raia_glfw_set_window_refresh_callback(void *window, void * callback) {
    return glfwSetWindowRefreshCallback(window, callback);
}

void * raia_glfw_set_window_focus_callback(void *window, void * callback) {
    return glfwSetWindowFocusCallback(window, callback);
}

void * raia_glfw_set_window_iconify_callback(void *window, void * callback) {
    return glfwSetWindowIconifyCallback(window, callback);
}

void * raia_glfw_set_window_maximize_callback(void *window, void * callback) {
    return glfwSetWindowMaximizeCallback(window, callback);
}

void * raia_glfw_set_framebuffer_size_callback(void *window, void * callback) {
    return glfwSetFramebufferSizeCallback(window, callback);
}

void * raia_glfw_set_window_content_scale_callback(void *window, void * callback) {
    return glfwSetWindowContentScaleCallback(window, callback);
}

void raia_glfw_poll_events(void) {
    glfwPollEvents();
}

void raia_glfw_wait_events(void) {
    glfwWaitEvents();
}

void raia_glfw_wait_events_timeout(double timeout) {
    glfwWaitEventsTimeout(timeout);
}

void raia_glfw_post_empty_event(void) {
    glfwPostEmptyEvent();
}

void raia_glfw_swap_buffers(void *window) {
    glfwSwapBuffers(window);
}

// (代替関数)

// Error

void raia_glfw_set_error_callback_alt(void) {
    glfwSetErrorCallback(error_callback);
}

int raia_glfw_get_error_code(void) {
    return get_callback_data_error_code();
}

const char *raia_glfw_get_error_message(void) {
    return get_callback_data_error_message();
}

// Joystick

void raia_glfw_set_joystick_callback_alt(void) {
    glfwSetJoystickCallback(joystick_callback);
}

int raia_glfw_get_joystick_id(void) {
    return get_callback_data_joystick_id();
}

int raia_glfw_get_joystick_event(void) {
    return get_callback_data_joystick_event();
}

// Monitor

void raia_glfw_set_monitor_callback_alt(void) {
    glfwSetMonitorCallback(monitor_callback);
}

void * raia_glfw_get_monitor(void) {
    return get_monitor();
}

int raia_glfw_get_monitor_event(void) {
    return get_monitor_event();
}

// Pos

void raia_glfw_set_window_pos_callback_alt(void *window) {
    glfwSetWindowPosCallback(window, window_pos_callback);
}

int raia_glfw_get_window_pos_x(void *window) {
    return get_window_pos_x(window);
}

int raia_glfw_get_window_pos_y(void *window) {
    return get_window_pos_y(window);
}

// Size

void raia_glfw_set_window_size_callback_alt(void *window) {
    glfwSetWindowSizeCallback(window, window_size_callback);
}

int raia_glfw_get_window_size_width(void *window) {
    return get_window_size_width(window);
}

int raia_glfw_get_window_size_height(void *window) {
    return get_window_size_height(window);
}

// Close

void raia_glfw_set_window_close_callback_alt(void *window) {
    glfwSetWindowCloseCallback(window, window_close_callback);
}

int raia_glfw_get_window_close(void *window) {
    return get_window_close(window);
}

// Refresh

void raia_glfw_set_window_refresh_callback_alt(void *window) {
    glfwSetWindowRefreshCallback(window, window_refresh_callback);
}

int raia_glfw_get_window_refresh(void *window) {
    return get_window_refresh(window);
}

// Focus

void raia_glfw_set_window_focus_callback_alt(void *window) {
    glfwSetWindowFocusCallback(window, window_focus_callback);
}

int raia_glfw_get_window_focus(void *window) {
    return get_window_close(window);
}

// Iconify

void raia_glfw_set_window_iconify_callback_alt(void *window) {
    glfwSetWindowIconifyCallback(window, window_iconify_callback);
}

int raia_glfw_get_window_iconified(void *window) {
    return get_window_iconified(window);
}

// Framebuffer Size

void raia_glfw_set_framebuffer_size_callback_alt(void *window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

int raia_glfw_get_framebuffer_size_width(void *window) {
    return get_framebuffer_size_width(window);
}

int raia_glfw_get_framebuffer_size_height(void *window) {
    return get_framebuffer_size_height(window);
}

// Key

void raia_glfw_set_key_callback_alt(void *window) {
    glfwSetKeyCallback(window, key_callback);
}

int raia_glfw_get_key_alt(void *window) {
    return get_key(window);
}

int raia_glfw_get_key_scancode_alt(void *window) {
    return get_key_scancode(window);
}

int raia_glfw_get_key_action(void *window) {
    return get_key_action(window);
}

int raia_glfw_get_key_mods(void *window) {
    return get_key_mods(window);
}

// Cursor pos

void raia_glfw_set_cursor_pos_callback_alt(void *window) {
    glfwSetCursorPosCallback(window, cursor_pos_callback);
}

double raia_glfw_get_cursor_pos_x(void *window) {
    return get_cursor_pos_x(window);
}

double raia_glfw_get_cursor_pos_y(void *window) {
    return get_cursor_pos_y(window);
}

// Mouse button

void raia_glfw_set_mouse_button_callback_alt(void *window) {
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

int raia_glfw_get_mouse_button_alt(void *window) {
    return get_mouse_button(window);
}

int raia_glfw_get_mouse_action(void *window) {
    return get_mouse_action(window);
}

int raia_glfw_get_mouse_mods(void *window) {
    return get_mouse_mods(window);
}

// Char

void raia_glfw_set_char_callback_alt(void *window) {
    glfwSetCharCallback(window, char_callback);
}

unsigned int raia_glfw_get_char(void *window) {
    return get_char_codepoint(window);
}

// Char mods

void raia_glfw_set_char_mods_callback_alt(void *window) {
    glfwSetCharModsCallback(window, char_mods_callback);
}

unsigned int raia_glfw_get_char_mods_codepoint(void *window) {
    return get_char_mods_codepoint(window);
}

int raia_glfw_get_char_mods_mods(void *window) {
    return get_char_mods_mods(window);
}

// Cursor enter

void raia_glfw_set_cursor_enter_callback_alt(void *window) {
    glfwSetCursorEnterCallback(window, cursor_enter_callback);
}

int raia_glfw_get_cursor_enter(void *window) {
    return get_cursor_entered(window);
}

// Scroll

void raia_glfw_set_scroll_callback_alt(void *window) {
    glfwSetScrollCallback(window, scroll_callback);
}

int raia_glfw_get_scroll_offset_x(void *window) {
    return get_scroll_xoffset(window);
}

int raia_glfw_get_scroll_offset_y(void *window) {
    return get_scroll_yoffset(window);
}

// Drop

void raia_glfw_set_drop_callback_alt(void *window) {
    glfwSetDropCallback(window, drop_callback);
}

int raia_glfw_get_drop_count(void *window) {
    return get_drop_count(window);
}

const char** raia_glfw_get_drop_paths(void *window) {
    return get_drop_paths(window);
}

// Maximized

void raia_glfw_set_window_maximize_callback_alt(void *window) {
    glfwSetWindowMaximizeCallback(window, window_maximize_callback);
}

int raia_glfw_get_window_maximized(void *window) {
    return get_window_maximized(window);
}

// Content scale

void raia_glfw_set_window_content_scale_callback_alt(void *window) {
    glfwSetWindowContentScaleCallback(window, window_content_scale_callback);
}

float raia_glfw_get_window_content_scale_x(void *window) {
    return get_window_content_scale_x(window);
}

float raia_glfw_get_window_content_scale_y(void *window) {
    return get_window_content_scale_y(window);
}
