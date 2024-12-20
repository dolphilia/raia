#include "raia_glfw.h"
#include "static/static_callback.h"
#include "../../../common/c/utility/export_api.h"

//
// コンテキスト
//

RAIA_API void raia_glfw_make_context_current(GLFWwindow *window) {
    glfwMakeContextCurrent(window);
}

RAIA_API GLFWwindow *raia_glfw_get_current_context(void) {
    return glfwGetCurrentContext();
}

RAIA_API void raia_glfw_swap_interval(int interval) {
    glfwSwapInterval(interval);
}

RAIA_API int raia_glfw_extension_supported(const char *extension) {
    return glfwExtensionSupported(extension);
}

RAIA_API GLFWglproc raia_glfw_get_proc_address(const char *procname) {
    return glfwGetProcAddress(procname);
}

//
// 初期化・バージョン・エラー
//

RAIA_API int raia_glfw_init(void) {
    return glfwInit();
}

RAIA_API void raia_glfw_terminate(void) {
    glfwTerminate();
}

RAIA_API void raia_glfw_init_hint(int hint, int value) {
    glfwInitHint(hint, value);
}

RAIA_API void raia_glfw_get_version(int *major, int *minor, int *rev) {
    glfwGetVersion(major, minor, rev);
}

RAIA_API const char *raia_glfw_get_version_string(void) {
    return glfwGetVersionString();
}

RAIA_API int raia_glfw_get_error(const char **description) {
    return glfwGetError(description);
}

RAIA_API GLFWerrorfun raia_glfw_set_error_callback(GLFWerrorfun callback) {
    return glfwSetErrorCallback(callback);
}

//
// 入力
//

RAIA_API int raia_glfw_get_input_mode(GLFWwindow *window, int mode) {
    return glfwGetInputMode(window, mode);
}

RAIA_API void raia_glfw_set_input_mode(GLFWwindow *window, int mode, int value) {
    glfwSetInputMode(window, mode, value);
}

RAIA_API int raia_glfw_raw_mouse_motion_supported(void) {
    return glfwRawMouseMotionSupported();
}

RAIA_API const char *raia_glfw_get_key_name(int key, int scancode) {
    return glfwGetKeyName(key, scancode);
}

RAIA_API int raia_glfw_get_key_scancode(int key){
    return glfwGetKeyScancode(key);
}

RAIA_API int raia_glfw_get_key(GLFWwindow *window, int key) {
    return glfwGetKey(window, key);
}

RAIA_API int raia_glfw_get_mouse_button(GLFWwindow *window, int button) {
    return glfwGetMouseButton(window, button);
}

RAIA_API void raia_glfw_get_cursor_pos(GLFWwindow *window, double *xpos, double *ypos) {
    glfwGetCursorPos(window, xpos, ypos);
}

RAIA_API void raia_glfw_set_cursor_pos(GLFWwindow *window, double xpos, double ypos) {
    glfwSetCursorPos(window, xpos, ypos);
}

RAIA_API GLFWcursor *raia_glfw_create_cursor(const GLFWimage *image, int xhot, int yhot) {
    return glfwCreateCursor(image, xhot, yhot);
}

RAIA_API GLFWcursor *raia_glfw_create_standard_cursor(int shape) {
    return glfwCreateStandardCursor(shape);
}

RAIA_API void raia_glfw_destroy_cursor(GLFWcursor *cursor) {
    glfwDestroyCursor(cursor);
}

RAIA_API void raia_glfw_set_cursor(GLFWwindow *window, GLFWcursor *cursor) {
    glfwSetCursor(window, cursor);
}

RAIA_API GLFWkeyfun raia_glfw_set_key_callback(GLFWwindow *window, GLFWkeyfun callback) {
    return glfwSetKeyCallback(window, callback);
}

RAIA_API GLFWcharfun raia_glfw_set_char_callback(GLFWwindow *window, GLFWcharfun callback) {
    return glfwSetCharCallback(window, callback);
}

RAIA_API GLFWcharmodsfun raia_glfw_set_char_mods_callback(GLFWwindow *window, GLFWcharmodsfun callback) {
    return glfwSetCharModsCallback(window, callback);
}

RAIA_API GLFWmousebuttonfun raia_glfw_set_mouse_button_callback(GLFWwindow *window, GLFWmousebuttonfun callback) {
    return glfwSetMouseButtonCallback(window, callback);
}

RAIA_API GLFWcursorposfun raia_glfw_set_cursor_pos_callback(GLFWwindow *window, GLFWcursorposfun callback) {
    return glfwSetCursorPosCallback(window, callback);
}

RAIA_API GLFWcursorenterfun raia_glfw_set_cursor_enter_callback(GLFWwindow *window, GLFWcursorenterfun callback) {
    return glfwSetCursorEnterCallback(window, callback);
}

RAIA_API GLFWscrollfun raia_glfw_set_scroll_callback(GLFWwindow *window, GLFWscrollfun callback) {
    return glfwSetScrollCallback(window, callback);
}

RAIA_API GLFWdropfun raia_glfw_set_drop_callback(GLFWwindow *window, GLFWdropfun callback) {
    return glfwSetDropCallback(window, callback);
}

RAIA_API int raia_glfw_joystick_present(int jid) {
    return glfwJoystickPresent(jid);
}

RAIA_API const float *raia_glfw_get_joystick_axes(int jid, int *count) {
    return glfwGetJoystickAxes(jid, count); // 返された配列は，GLFWによって確保・解放される
}

RAIA_API const unsigned char *raia_glfw_get_joystick_buttons(int jid, int *count) {
    return glfwGetJoystickButtons(jid, count); // 返された配列は、GLFWによって割り当てられ、解放される。
}

RAIA_API const unsigned char *raia_glfw_get_joystick_hats(int jid, int *count) {
    return glfwGetJoystickHats(jid, count);
}

RAIA_API const char *raia_glfw_get_joystick_name(int jid) {
    return glfwGetJoystickName(jid);
}

RAIA_API const char *raia_glfw_get_joystick_guid(int jid) {
    return glfwGetJoystickGUID(jid);
}

RAIA_API void raia_glfw_set_joystick_user_pointer(int jid, void *pointer) {
    glfwSetJoystickUserPointer(jid, pointer);
}

RAIA_API void *raia_glfw_get_joystick_user_pointer(int jid) {
    return glfwGetJoystickUserPointer(jid);
}

RAIA_API int raia_glfw_joystick_is_gamepad(int jid) {
    return glfwJoystickIsGamepad(jid);
}

RAIA_API GLFWjoystickfun raia_glfw_set_joystick_callback(GLFWjoystickfun callback) {
    return glfwSetJoystickCallback(callback);
}

RAIA_API int raia_glfw_update_gamepad_mappings(const char *string) {
    return glfwUpdateGamepadMappings(string);
}

RAIA_API const char *raia_glfw_get_gamepad_name(int jid) {
    return glfwGetGamepadName(jid);
}

RAIA_API int raia_glfw_get_gamepad_state(int jid, GLFWgamepadstate *state) {
    return glfwGetGamepadState(jid, state);
}

RAIA_API void raia_glfw_set_clipboard_string(GLFWwindow *window, const char *string) {
    glfwSetClipboardString(window, string);
}

RAIA_API const char *raia_glfw_get_clipboard_string(GLFWwindow *window) {
    return glfwGetClipboardString(window);
}

RAIA_API double raia_glfw_get_time(void) {
    return glfwGetTime();
}

RAIA_API void raia_glfw_set_time(double time) {
    glfwSetTime(time);
}

RAIA_API uint64_t raia_glfw_get_timer_value(void) {
    return glfwGetTimerValue();
}

RAIA_API uint64_t raia_glfw_get_timer_frequency(void) {
    return glfwGetTimerFrequency();
}

//
// モニター
//

RAIA_API GLFWmonitor **raia_glfw_get_monitors(int *count) {
    return glfwGetMonitors(count);
}

RAIA_API GLFWmonitor *raia_glfw_get_primary_monitor(void) {
    return glfwGetPrimaryMonitor();
}

RAIA_API void raia_glfw_get_monitor_pos(GLFWmonitor *monitor, int *xpos, int *ypos) {
    glfwGetMonitorPos(monitor, xpos, ypos);
}

RAIA_API void raia_glfw_get_monitor_workarea(GLFWmonitor *monitor, int *xpos, int *ypos, int *width, int *height) {
    glfwGetMonitorWorkarea(monitor,xpos, ypos, width, height);
}

RAIA_API void raia_glfw_get_monitor_physical_size(GLFWmonitor *monitor, int *widthMM, int *heightMM) {
    glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
}

RAIA_API void raia_glfw_get_monitor_content_scale(GLFWmonitor *monitor, float *xscale, float *yscale) {
    glfwGetMonitorContentScale(monitor, xscale, yscale);
}

RAIA_API const char *raia_glfw_get_monitor_name(GLFWmonitor *monitor) {
    return glfwGetMonitorName(monitor);
}

RAIA_API void raia_glfw_set_monitor_user_pointer(GLFWmonitor *monitor, void *pointer) {
    glfwSetMonitorUserPointer(monitor, pointer);
}

RAIA_API void *raia_glfw_get_monitor_user_pointer(GLFWmonitor *monitor) {
    return glfwGetMonitorUserPointer(monitor);
}

RAIA_API GLFWmonitorfun raia_glfw_set_monitor_callback(GLFWmonitorfun callback) {
    return glfwSetMonitorCallback(callback);
}

RAIA_API const GLFWvidmode *raia_glfw_get_video_modes(GLFWmonitor *monitor, int *count) {
    return glfwGetVideoModes(monitor, count);
}

RAIA_API const GLFWvidmode *raia_glfw_get_video_mode(GLFWmonitor *monitor) {
    return glfwGetVideoMode(monitor);
}

RAIA_API void raia_glfw_set_gamma(GLFWmonitor *monitor, float gamma) {
    glfwSetGamma(monitor, gamma);
}

RAIA_API const GLFWgammaramp *raia_glfw_get_gamma_ramp(GLFWmonitor *monitor) {
    return glfwGetGammaRamp(monitor);
}

RAIA_API void raia_glfw_set_gamma_ramp(GLFWmonitor *monitor, const GLFWgammaramp *ramp) {
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

RAIA_API int raia_glfw_vulkan_supported(void) {
    return glfwVulkanSupported();
}

RAIA_API const char **raia_glfw_get_required_instance_extensions(uint32_t *count) {
    return glfwGetRequiredInstanceExtensions(count);
}

// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

//
// ウィンドウ
//

RAIA_API void raia_glfw_default_window_hints(void) {
    glfwDefaultWindowHints();
}

RAIA_API void raia_glfw_window_hint(int hint, int value) {
    glfwWindowHint(hint, value);
}

RAIA_API void raia_glfw_window_hint_string(int hint, const char *value) {
    glfwWindowHintString(hint, value);
}

RAIA_API GLFWwindow *raia_glfw_create_window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share) {
    return glfwCreateWindow(width, height, title, monitor, share);
}

RAIA_API void raia_glfw_destroy_window(GLFWwindow *window) {
    glfwDestroyWindow(window);
}

RAIA_API int raia_glfw_window_should_close(GLFWwindow *window) {
    return glfwWindowShouldClose(window);
}

RAIA_API void raia_glfw_set_window_should_close(GLFWwindow *window, int value) {
    glfwSetWindowShouldClose(window, value);
}

RAIA_API void raia_glfw_set_window_title(GLFWwindow *window, const char *title) {
    glfwSetWindowTitle(window, title);
}

RAIA_API void raia_glfw_set_window_icon(GLFWwindow *window, int count, const GLFWimage *images) {
    glfwSetWindowIcon(window, count, images);
}

RAIA_API void raia_glfw_get_window_pos(GLFWwindow *window, int *xpos, int *ypos) {
    glfwGetWindowPos(window, xpos, ypos);
}

RAIA_API void raia_glfw_set_window_pos(GLFWwindow *window, int xpos, int ypos) {
    glfwSetWindowPos(window, xpos, ypos);
}

RAIA_API void raia_glfw_get_window_size(GLFWwindow *window, int *width, int *height) {
    glfwGetWindowSize(window, width, height);
}

RAIA_API void raia_glfw_set_window_size_limits(GLFWwindow *window, int minwidth, int minheight, int maxwidth, int maxheight) {
    glfwSetWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight);
}

RAIA_API void raia_glfw_set_window_aspect_ratio(GLFWwindow *window, int numer, int denom) {
    glfwSetWindowAspectRatio(window, numer, denom);
}

RAIA_API void raia_glfw_set_window_size(GLFWwindow *window, int width, int height) {
    glfwSetWindowSize(window, width, height);
}

RAIA_API void raia_glfw_get_framebuffer_size(GLFWwindow *window, int *width, int *height) {
    glfwGetFramebufferSize(window, width, height);
}

RAIA_API void raia_glfw_get_window_frame_size(GLFWwindow *window, int *left, int *top, int *right, int *bottom) {
    glfwGetWindowFrameSize(window, left, top, right, bottom);
}

RAIA_API void raia_glfw_get_window_content_scale(GLFWwindow *window, float *xscale, float *yscale) {
    glfwGetWindowContentScale(window, xscale, yscale);
}

RAIA_API float raia_glfw_get_window_opacity(GLFWwindow *window) {
    return glfwGetWindowOpacity(window);
}

RAIA_API void raia_glfw_set_window_opacity(GLFWwindow *window, float opacity) {
    glfwSetWindowOpacity(window, opacity);
}

RAIA_API void raia_glfw_iconify_window(GLFWwindow *window) {
    glfwIconifyWindow(window);
}

RAIA_API void raia_glfw_restore_window(GLFWwindow *window) {
    glfwRestoreWindow(window);
}

RAIA_API void raia_glfw_maximize_window(GLFWwindow *window) {
    glfwMaximizeWindow(window);
}

RAIA_API void raia_glfw_show_window(GLFWwindow *window) {
    glfwShowWindow(window);
}

RAIA_API void raia_glfw_hide_window(GLFWwindow *window) {
    glfwHideWindow(window);
}

RAIA_API void raia_glfw_focus_window(GLFWwindow *window) {
    glfwFocusWindow(window);
}

RAIA_API void raia_glfw_request_window_attention(GLFWwindow *window) {
    glfwRequestWindowAttention(window);
}

RAIA_API GLFWmonitor *raia_glfw_get_window_monitor(GLFWwindow *window) {
    return glfwGetWindowMonitor(window);
}

RAIA_API void raia_glfw_set_window_monitor(GLFWwindow *window, GLFWmonitor *monitor, int xpos, int ypos, int width, int height, int refreshRate) {
    glfwSetWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate);
}

RAIA_API int raia_glfw_get_window_attrib(GLFWwindow *window, int attrib) {
    return glfwGetWindowAttrib(window, attrib);
}

RAIA_API void raia_glfw_set_window_attrib(GLFWwindow *window, int attrib, int value) {
    glfwSetWindowAttrib(window, attrib, value);
}

RAIA_API void raia_glfw_set_window_user_pointer(GLFWwindow *window, void *pointer) {
    glfwSetWindowUserPointer(window, pointer);
}

RAIA_API void *raia_glfw_get_window_user_pointer(GLFWwindow *window) {
    return glfwGetWindowUserPointer(window);
}

RAIA_API GLFWwindowposfun raia_glfw_set_window_pos_callback(GLFWwindow *window, GLFWwindowposfun callback) {
    return glfwSetWindowPosCallback(window, callback);
}

RAIA_API GLFWwindowsizefun raia_glfw_set_window_size_callback(GLFWwindow *window, GLFWwindowsizefun callback) {
    return glfwSetWindowSizeCallback(window, callback);
}

RAIA_API GLFWwindowclosefun raia_glfw_set_window_close_callback(GLFWwindow *window, GLFWwindowclosefun callback) {
    return glfwSetWindowCloseCallback(window, callback);
}

RAIA_API GLFWwindowrefreshfun raia_glfw_set_window_refresh_callback(GLFWwindow *window, GLFWwindowrefreshfun callback) {
    return glfwSetWindowRefreshCallback(window, callback);
}

RAIA_API GLFWwindowfocusfun raia_glfw_set_window_focus_callback(GLFWwindow *window, GLFWwindowfocusfun callback) {
    return glfwSetWindowFocusCallback(window, callback);
}

RAIA_API GLFWwindowiconifyfun raia_glfw_set_window_iconify_callback(GLFWwindow *window, GLFWwindowiconifyfun callback) {
    return glfwSetWindowIconifyCallback(window, callback);
}

RAIA_API GLFWwindowmaximizefun raia_glfw_set_window_maximize_callback(GLFWwindow *window, GLFWwindowmaximizefun callback) {
    return glfwSetWindowMaximizeCallback(window, callback);
}

RAIA_API GLFWframebuffersizefun raia_glfw_set_framebuffer_size_callback(GLFWwindow *window, GLFWframebuffersizefun callback) {
    return glfwSetFramebufferSizeCallback(window, callback);
}

RAIA_API GLFWwindowcontentscalefun raia_glfw_set_window_content_scale_callback(GLFWwindow *window, GLFWwindowcontentscalefun callback) {
    return glfwSetWindowContentScaleCallback(window, callback);
}

RAIA_API void raia_glfw_poll_events(void) {
    glfwPollEvents();
}

RAIA_API void raia_glfw_wait_events(void) {
    glfwWaitEvents();
}

RAIA_API void raia_glfw_wait_events_timeout(double timeout) {
    glfwWaitEventsTimeout(timeout);
}

RAIA_API void raia_glfw_post_empty_event(void) {
    glfwPostEmptyEvent();
}

RAIA_API void raia_glfw_swap_buffers(GLFWwindow *window) {
    glfwSwapBuffers(window);
}

// (代替関数)

// Error

RAIA_API void raia_glfw_set_error_callback_alt(void) {
    glfwSetErrorCallback(error_callback);
}

RAIA_API int raia_glfw_get_error_code(void) {
    return get_callback_data_error_code();
}

RAIA_API const char *raia_glfw_get_error_message(void) {
    return get_callback_data_error_message();
}

// Joystick

RAIA_API void raia_glfw_set_joystick_callback_alt(void) {
    glfwSetJoystickCallback(joystick_callback);
}

RAIA_API int raia_glfw_get_joystick_id(void) {
    return get_callback_data_joystick_id();
}

RAIA_API int raia_glfw_get_joystick_event(void) {
    return get_callback_data_joystick_event();
}

// Monitor

RAIA_API void raia_glfw_set_monitor_callback_alt(void) {
    glfwSetMonitorCallback(monitor_callback);
}

RAIA_API GLFWmonitor* raia_glfw_get_monitor(void) {
    return get_monitor();
}

RAIA_API int raia_glfw_get_monitor_event(void) {
    return get_monitor_event();
}

// Pos

RAIA_API void raia_glfw_set_window_pos_callback_alt(GLFWwindow *window) {
    glfwSetWindowPosCallback(window, window_pos_callback);
}

RAIA_API int raia_glfw_get_window_pos_x(GLFWwindow *window) {
    return get_window_pos_x(window);
}

RAIA_API int raia_glfw_get_window_pos_y(GLFWwindow *window) {
    return get_window_pos_y(window);
}

// Size

RAIA_API void raia_glfw_set_window_size_callback_alt(GLFWwindow *window) {
    glfwSetWindowSizeCallback(window, window_size_callback);
}

RAIA_API int raia_glfw_get_window_size_width(GLFWwindow *window) {
    return get_window_size_width(window);
}

RAIA_API int raia_glfw_get_window_size_height(GLFWwindow *window) {
    return get_window_size_height(window);
}

// Close

RAIA_API void raia_glfw_set_window_close_callback_alt(GLFWwindow *window) {
    glfwSetWindowCloseCallback(window, window_close_callback);
}

RAIA_API bool raia_glfw_get_window_close(GLFWwindow *window) {
    return get_window_close(window);
}

// Refresh

RAIA_API void raia_glfw_set_window_refresh_callback_alt(GLFWwindow *window) {
    glfwSetWindowRefreshCallback(window, window_refresh_callback);
}

RAIA_API bool raia_glfw_get_window_refresh(GLFWwindow *window) {
    return get_window_refresh(window);
}

// Focus

RAIA_API void raia_glfw_set_window_focus_callback_alt(GLFWwindow *window) {
    glfwSetWindowFocusCallback(window, window_focus_callback);
}

RAIA_API int raia_glfw_get_window_focus(GLFWwindow *window) {
    return get_window_close(window);
}

// Iconify

RAIA_API void raia_glfw_set_window_iconify_callback_alt(GLFWwindow *window) {
    glfwSetWindowIconifyCallback(window, window_iconify_callback);
}

RAIA_API int raia_glfw_get_window_iconified(GLFWwindow *window) {
    return get_window_iconified(window);
}

// Framebuffer Size

RAIA_API void raia_glfw_set_framebuffer_size_callback_alt(GLFWwindow *window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

RAIA_API int raia_glfw_get_framebuffer_size_width(GLFWwindow *window) {
    return get_framebuffer_size_width(window);
}

RAIA_API int raia_glfw_get_framebuffer_size_height(GLFWwindow *window) {
    return get_framebuffer_size_height(window);
}

// Key

RAIA_API void raia_glfw_set_key_callback_alt(GLFWwindow *window) {
    glfwSetKeyCallback(window, key_callback);
}

RAIA_API int raia_glfw_get_key_alt(GLFWwindow *window) {
    return get_key(window);
}

RAIA_API int raia_glfw_get_key_scancode_alt(GLFWwindow *window) {
    return get_key_scancode(window);
}

RAIA_API int raia_glfw_get_key_action(GLFWwindow *window) {
    return get_key_action(window);
}

RAIA_API int raia_glfw_get_key_mods(GLFWwindow *window) {
    return get_key_mods(window);
}

// Cursor pos

RAIA_API void raia_glfw_set_cursor_pos_callback_alt(GLFWwindow *window) {
    glfwSetCursorPosCallback(window, cursor_pos_callback);
}

RAIA_API double raia_glfw_get_cursor_pos_x(GLFWwindow *window) {
    return get_cursor_pos_x(window);
}

RAIA_API double raia_glfw_get_cursor_pos_y(GLFWwindow *window) {
    return get_cursor_pos_y(window);
}

// Mouse button

RAIA_API void raia_glfw_set_mouse_button_callback_alt(GLFWwindow *window) {
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

RAIA_API int raia_glfw_get_mouse_button_alt(GLFWwindow *window) {
    return get_mouse_button(window);
}

RAIA_API int raia_glfw_get_mouse_action(GLFWwindow *window) {
    return get_mouse_action(window);
}

RAIA_API int raia_glfw_get_mouse_mods(GLFWwindow *window) {
    return get_mouse_mods(window);
}

// Char

RAIA_API void raia_glfw_set_char_callback_alt(GLFWwindow *window) {
    glfwSetCharCallback(window, char_callback);
}

RAIA_API unsigned int raia_glfw_get_char(GLFWwindow *window) {
    return get_char_codepoint(window);
}

// Char mods

RAIA_API void raia_glfw_set_char_mods_callback_alt(GLFWwindow *window) {
    glfwSetCharModsCallback(window, char_mods_callback);
}

RAIA_API unsigned int raia_glfw_get_char_mods_codepoint(GLFWwindow *window) {
    return get_char_mods_codepoint(window);
}

RAIA_API int raia_glfw_get_char_mods_mods(GLFWwindow *window) {
    return get_char_mods_mods(window);
}

// Cursor enter

RAIA_API void raia_glfw_set_cursor_enter_callback_alt(GLFWwindow *window) {
    glfwSetCursorEnterCallback(window, cursor_enter_callback);
}

RAIA_API int raia_glfw_get_cursor_enter(GLFWwindow *window) {
    return get_cursor_entered(window);
}

// Scroll

RAIA_API void raia_glfw_set_scroll_callback_alt(GLFWwindow *window) {
    glfwSetScrollCallback(window, scroll_callback);
}

RAIA_API int raia_glfw_get_scroll_offset_x(GLFWwindow *window) {
    return get_scroll_xoffset(window);
}

RAIA_API int raia_glfw_get_scroll_offset_y(GLFWwindow *window) {
    return get_scroll_yoffset(window);
}

// Drop

RAIA_API void raia_glfw_set_drop_callback_alt(GLFWwindow *window) {
    glfwSetDropCallback(window, drop_callback);
}

RAIA_API int raia_glfw_get_drop_count(GLFWwindow *window) {
    return get_drop_count(window);
}

RAIA_API const char** raia_glfw_get_drop_paths(GLFWwindow *window) {
    return get_drop_paths(window);
}

// Maximized

RAIA_API void raia_glfw_set_window_maximize_callback_alt(GLFWwindow *window) {
    glfwSetWindowMaximizeCallback(window, window_maximize_callback);
}

RAIA_API int raia_glfw_get_window_maximized(GLFWwindow *window) {
    return get_window_maximized(window);
}

// Content scale

RAIA_API void raia_glfw_set_window_content_scale_callback_alt(GLFWwindow *window) {
    glfwSetWindowContentScaleCallback(window, window_content_scale_callback);
}

RAIA_API float raia_glfw_get_window_content_scale_x(GLFWwindow *window) {
    return get_window_content_scale_x(window);
}

RAIA_API float raia_glfw_get_window_content_scale_y(GLFWwindow *window) {
    return get_window_content_scale_y(window);
}
