#include "raia_glfw.h"

// コンテキスト

RAIA_API const char *raia_glfw_make_context_current(const char *s) {
    joint_t *joint_args = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)(uintptr_t)joint_get_in_uint(joint_args, "window_id");
    glfwMakeContextCurrent(window);
    joint_free(joint_args);
    return NULL;
}

RAIA_API const char *raia_glfw_get_current_context(const char *s) {
    GLFWwindow *window = glfwGetCurrentContext();
    joint_t *joint_out = joint_init_out();
    joint_add_out_uint(joint_out, "window_id", (uint64_t)(uintptr_t)window);
    return joint_out_write(joint_out);
}

RAIA_API const char *raia_glfw_swap_interval(const char *s) {
    joint_t *joint_in = joint_init_with_str(s);
    int interval = joint_get_in_int(joint_in, "interval");
    glfwSwapInterval(interval);
    joint_free(joint_in);
    return NULL;
}

// glfwExtensionSupported()
// glfwGetProcAddress()

// 初期化・バージョン・エラー

RAIA_API const char *raia_glfw_init(const char *s) {
    init_static_callback();
    GLboolean ret = glfwInit();
    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", ret);
    return joint_out_write(joint);
}

RAIA_API const char *raia_glfw_terminate(const char *s) {
    glfwTerminate();
    return NULL;
}

// glfwInitHint()
// glfwGetVersion()
// glfwGetVersionString()
// glfwGetError()
// glfwSetErrorCallback()

// 代替関数

// TODO -> raia_glfw_get_error_default
RAIA_API const char *raia_glfw_set_error_callback(const char *s) {
    glfwSetErrorCallback(event_error_callback);
    return NULL;
}

RAIA_API const char *raia_glfw_get_error_callback(const char *s) {
    return get_error_callback_t();
}

// 入力

// glfwGetInputMode
// glfwSetInputMode
// glfwRawMouseMotionSupported
// glfwGetKeyName
// glfwGetKeyScancode
// glfwGetKey
// glfwGetMouseButton
// glfwGetCursorPos
// glfwSetCursorPos
// glfwCreateCursor
// glfwCreateStandardCursor
// glfwDestroyCursor
// glfwSetCursor
// glfwSetKeyCallback
// glfwSetCharCallback
// glfwSetCharModsCallback
// glfwSetMouseButtonCallback
// glfwSetCursorPosCallback
// glfwSetCursorEnterCallback
// glfwSetScrollCallback
// glfwSetDropCallback

RAIA_API const char *raia_glfw_joystick_present(const char *s) {
    joint_t *joint_in = joint_init_with_str(s);
    int jid = joint_get_in_int(joint_in, "jid");
    int val = glfwJoystickPresent(jid);
    joint_free(joint_in);
    joint_t *joint_out = joint_init_out();
    joint_add_out_int(joint_out, "result", val);
    return joint_out_write(joint_out);
}

RAIA_API const char *raia_glfw_get_joystick_axes(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");
    int count = 0;
    const float *axes = glfwGetJoystickAxes(jid, &count); // 返された配列は，GLFWによって確保・解放される
    joint_add_out_arr_real(joint, "result", (double *) axes, count);
    return joint_out_write(joint);
}

RAIA_API const char *raia_glfw_get_joystick_buttons(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");
    int count = 0;
    const unsigned char *buttons = glfwGetJoystickButtons(jid, &count); // 返された配列は、GLFWによって割り当てられ、解放される。
    joint_add_out_arr_uint8(joint, "result", (uint8_t *) buttons, count);
    return joint_out_write(joint);
}

// glfwGetJoystickHats()

RAIA_API const char *raia_glfw_get_joystick_name(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");
    const char *name = glfwGetJoystickName(jid);
    joint_add_out_str(joint, "result", name);
    return joint_out_write(joint);
}

// glfwGetJoystickGUID
// glfwSetJoystickUserPointer
// glfwGetJoystickUserPointer
// glfwJoystickIsGamepad
// glfwSetJoystickCallback
// glfwUpdateGamepadMappings
// glfwGetGamepadName
// glfwGetGamepadState
// glfwSetClipboardString
// glfwGetClipboardString

RAIA_API const char *raia_glfw_get_time(const char *s) {
    double time = glfwGetTime();
    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", time);
    return joint_out_write(joint);
}

RAIA_API const char *raia_glfw_set_time(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");
    glfwSetTime(time);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_timer_value(const char *s) {
    uint64_t val = glfwGetTimerValue();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_API const char *raia_glfw_get_timer_frequency(const char *s) {
    uint64_t val = glfwGetTimerFrequency();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

// 代替関数

RAIA_API const char *raia_glfw_set_key_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetKeyCallback(window, event_key_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_key_callback(const char *s) {
    return get_key_callback_t();
}

RAIA_API const char *raia_glfw_set_char_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetCharCallback(window, event_char_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_char_callback(const char *s) {
    return get_char_callback_t();
}

RAIA_API const char *raia_glfw_set_char_mods_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetCharModsCallback(window, event_char_mods_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_char_mods_callback(const char *s) {
    return get_char_mods_callback_t();
}

RAIA_API const char *raia_glfw_set_mouse_button_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetMouseButtonCallback(window, event_mouse_button_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_mouse_button_callback(const char *s) {
    return get_mouse_button_callback_t();
}

RAIA_API const char *raia_glfw_set_cursor_pos_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetCursorPosCallback(window, event_cursor_pos_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_cursor_pos_callback(const char *s) {
    return get_cursor_pos_callback_t();
}

RAIA_API const char *raia_glfw_set_cursor_enter_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetCursorEnterCallback(window, event_cursor_enter_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_cursor_enter_callback(const char *s) {
    return get_cursor_enter_callback_t();
}

RAIA_API const char *raia_glfw_set_scroll_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetScrollCallback(window, event_scroll_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_scroll_callback(const char *s) {
    return get_scroll_callback_t();
}

RAIA_API const char *raia_glfw_set_drop_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetDropCallback(window, event_drop_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_drop_callback(const char *s) {
    return get_drop_callback_t();
}

RAIA_API const char *raia_glfw_set_joystick_callback(const char *s) {
    glfwSetJoystickCallback(event_joystick_callback);
    return NULL;
}

RAIA_API const char *raia_glfw_get_joystick_callback(const char *s) {
    return get_joystick_callback_t();
}

// モニター

// glfwGetMonitors
// glfwGetPrimaryMonitor
// glfwGetMonitorPos
// glfwGetMonitorWorkarea
// glfwGetMonitorPhysicalSize
// glfwGetMonitorContentScale
// glfwGetMonitorName
// glfwSetMonitorUserPointer
// glfwGetMonitorUserPointer
// glfwSetMonitorCallback
// glfwGetVideoModes
// glfwGetVideoMode
// glfwSetGamma
// glfwGetGammaRamp
// glfwSetGammaRamp

// ネイティブアクセス

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

// Vulkanサポート

// glfwVulkanSupported
// glfwGetRequiredInstanceExtensions
// glfwGetInstanceProcAddress
// glfwGetPhysicalDevicePresentationSupport
// glfwCreateWindowSurface

// ウィンドウ

// glfwDefaultWindowHints

RAIA_API const char *raia_glfw_window_hint(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int hint = joint_get_in_int(joint, "hint");
    int value = joint_get_in_int(joint, "value");
    glfwWindowHint(hint, value);
    return joint_out_write(joint);
}

// glfwWindowHintString

RAIA_API const char *raia_glfw_create_window(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char *title = joint_get_in_str(joint, "title");

    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) {
        joint_add_out_null(joint, "window_id");
        return joint_out_write(joint);
    }
    joint_add_out_uint(joint, "window_id", (uint64_t)(uintptr_t)window);
    return joint_out_write(joint);
}

RAIA_API const char *raia_glfw_destroy_window(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwDestroyWindow(window);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_window_should_close(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window_id = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    int ret = glfwWindowShouldClose(window_id);
    joint_add_out_int(joint, "result", ret);
    return joint_out_write(joint);
}

// glfwSetWindowShouldClose

RAIA_API const char *raia_glfw_set_window_title(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window_id = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    const char *title = joint_get_in_str(joint, "title");
    glfwSetWindowTitle(window_id, title);
    joint_free(joint);
    return NULL;
}

// glfwSetWindowIcon
// glfwGetWindowPos
// glfwSetWindowPos

RAIA_API const char *raia_glfw_get_window_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    joint_add_out_int(joint, "width", width);
    joint_add_out_int(joint, "height", height);
    return joint_out_write(joint);
}

// glfwSetWindowSizeLimits
// glfwSetWindowAspectRatio
// glfwSetWindowSize

RAIA_API const char *raia_glfw_get_framebuffer_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    joint_add_out_int(joint, "width", width);
    joint_add_out_int(joint, "height", height);
    return joint_out_write(joint);
}

// glfwGetWindowFrameSize
// glfwGetWindowContentScale
// glfwGetWindowOpacity
// glfwSetWindowOpacity
// glfwIconifyWindow
// glfwRestoreWindow
// glfwMaximizeWindow
// glfwShowWindow
// glfwHideWindow
// glfwFocusWindow
// glfwRequestWindowAttention
// glfwGetWindowMonitor
// glfwSetWindowMonitor
// glfwGetWindowAttrib
// glfwSetWindowAttrib
// glfwSetWindowUserPointer
// glfwGetWindowUserPointer
// glfwSetWindowPosCallback
// glfwSetWindowSizeCallback
// glfwSetWindowCloseCallback
// glfwSetWindowRefreshCallback
// glfwSetWindowFocusCallback
// glfwSetWindowIconifyCallback
// glfwSetWindowMaximizeCallback
// glfwSetFramebufferSizeCallback
// glfwSetWindowContentScaleCallback

RAIA_API const char *raia_glfw_poll_events(const char *s) {
    glfwPollEvents();
    return NULL;
}

// glfwWaitEvents

RAIA_API const char *raia_glfw_wait_event_timeout(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");
    glfwWaitEventsTimeout(time);
    joint_free(joint);
    return NULL;
}

// glfwPostEmptyEvent

RAIA_API const char *raia_glfw_swap_buffers(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window_id = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSwapBuffers(window_id);
    joint_free(joint);
    return NULL;
}

// 代替

RAIA_API const char *raia_glfw_set_window_pos_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowPosCallback(window, event_window_pos_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_pos_callback(const char *s) {
    return get_window_pos_callback_t();
}

RAIA_API const char *raia_glfw_set_window_size_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowSizeCallback(window, event_window_size_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_size_callback(const char *s) {
    return get_window_size_callback_t();
}

RAIA_API const char *raia_glfw_set_window_close_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowCloseCallback(window, event_window_close_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_close_callback(const char *s) {
    return get_window_close_callback_t();
}

RAIA_API const char *raia_glfw_set_window_refresh_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowRefreshCallback(window, event_window_refresh_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_refresh_callback(const char *s) {
    return get_window_refresh_callback_t();
}

RAIA_API const char *raia_glfw_set_window_focus_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowFocusCallback(window, event_window_focus_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_focus_callback(const char *s) {
    return get_window_focus_callback_t();
}

RAIA_API const char *raia_glfw_set_window_iconify_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetWindowIconifyCallback(window, event_window_iconify_callback);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_glfw_get_window_iconify_callback(const char *s) {
    return get_window_iconify_callback_t();
}

// WindowMaximizeCallback

RAIA_API const char *raia_glfw_get_framebuffer_size_callback(const char *s) {
    return get_framebuffer_size_callback_t();
}

RAIA_API const char *raia_glfw_set_framebuffer_size_callback(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow *window = (GLFWwindow *)joint_get_in_uint_to_ptr(joint, "window_id");
    glfwSetFramebufferSizeCallback(window, event_framebuffer_size_callback);
    joint_free(joint);
    return NULL;
}

// WindowContentScaleCallback