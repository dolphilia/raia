local ffi = require("ffi")

-- 汎用ファイナライザ設定関数
local function setFinalizer(key, deleteFunction)
    ffi.gc(ffi.new("int[1]", key), function(k)
        deleteFunction(k[0])
    end)
end

ffi.cdef[[
    typedef void (*GLFWglproc)(void);
    typedef void (*GLFWvkproc)(void);
    typedef struct GLFWmonitor GLFWmonitor;
    typedef struct GLFWwindow GLFWwindow;
    typedef struct GLFWcursor GLFWcursor;
    typedef void* (* GLFWallocatefun)(size_t size, void* user);
    typedef void* (* GLFWreallocatefun)(void* block, size_t size, void* user);
    typedef void (* GLFWdeallocatefun)(void* block, void* user);
    typedef void (* GLFWerrorfun)(int error_code, const char* description);
    typedef void (* GLFWwindowposfun)(GLFWwindow* window, int xpos, int ypos);
    typedef void (* GLFWwindowsizefun)(GLFWwindow* window, int width, int height);
    typedef void (* GLFWwindowclosefun)(GLFWwindow* window);
    typedef void (* GLFWwindowrefreshfun)(GLFWwindow* window);
    typedef void (* GLFWwindowfocusfun)(GLFWwindow* window, int focused);
    typedef void (* GLFWwindowiconifyfun)(GLFWwindow* window, int iconified);
    typedef void (* GLFWwindowmaximizefun)(GLFWwindow* window, int maximized);
    typedef void (* GLFWframebuffersizefun)(GLFWwindow* window, int width, int height);
    typedef void (* GLFWwindowcontentscalefun)(GLFWwindow* window, float xscale, float yscale);
    typedef void (* GLFWmousebuttonfun)(GLFWwindow* window, int button, int action, int mods);
    typedef void (* GLFWcursorposfun)(GLFWwindow* window, double xpos, double ypos);
    typedef void (* GLFWcursorenterfun)(GLFWwindow* window, int entered);
    typedef void (* GLFWscrollfun)(GLFWwindow* window, double xoffset, double yoffset);
    typedef void (* GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);
    typedef void (* GLFWcharfun)(GLFWwindow* window, unsigned int codepoint);
    typedef void (* GLFWcharmodsfun)(GLFWwindow* window, unsigned int codepoint, int mods);
    typedef void (* GLFWdropfun)(GLFWwindow* window, int path_count, const char* paths[]);
    typedef void (* GLFWmonitorfun)(GLFWmonitor* monitor, int event);
    typedef void (* GLFWjoystickfun)(int jid, int event);
    typedef struct GLFWvidmode
    {
        int width;
        int height;
        int redBits;
        int greenBits;
        int blueBits;
        int refreshRate;
    } GLFWvidmode;
    typedef struct GLFWgammaramp
    {
        unsigned short* red;
        unsigned short* green;
        unsigned short* blue;
        unsigned int size;
    } GLFWgammaramp;
    typedef struct GLFWimage
    {
        int width;
        int height;
        unsigned char* pixels;
    } GLFWimage;
    typedef struct GLFWgamepadstate
    {
        unsigned char buttons[15];
        float axes[6];
    } GLFWgamepadstate;
    typedef struct GLFWallocator
    {
        GLFWallocatefun allocate;
        GLFWreallocatefun reallocate;
        GLFWdeallocatefun deallocate;
        void* user;
    } GLFWallocator;
    //
    // コンテキスト
    //
    void raia_glfw_make_context_current(GLFWwindow *window);
    GLFWwindow *raia_glfw_get_current_context(void);
    void raia_glfw_swap_interval(int interval);
    int raia_glfw_extension_supported(const char *extension);
    GLFWglproc raia_glfw_get_proc_address(const char *procname);
    //
    // 初期化・バージョン・エラー
    //
    int raia_glfw_init(void);
    void raia_glfw_terminate(void);
    void raia_glfw_init_hint(int hint, int value);
    void raia_glfw_get_version(int *major, int *minor, int *rev);
    const char *raia_glfw_get_version_string(void);
    int raia_glfw_get_error(const char **description);
    GLFWerrorfun raia_glfw_set_error_callback(GLFWerrorfun callback);
    // (代替関数)
    const char *raia_glfw_get_error_callback_alt(void);
    void raia_glfw_set_error_callback_alt(void);
    //
    // 入力
    //
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
    // (代替関数)
    const char *raia_glfw_get_key_alt(void);
    void raia_glfw_set_key_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_char_alt(void);
    void raia_glfw_set_char_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_char_mods_alt(void);
    void raia_glfw_set_char_mods_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_mouse_button_alt(void);
    void raia_glfw_set_mouse_button_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_cursor_pos_alt(void);
    void raia_glfw_set_cursor_pos_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_cursor_enter_alt(void);
    void raia_glfw_set_cursor_enter_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_scroll_alt(void);
    void raia_glfw_set_scroll_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_drop_alt(void);
    void raia_glfw_set_drop_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_joystick_alt(void);
    void raia_glfw_set_joystick_callback_alt(void);
    //
    // モニター
    //
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
    // (代替関数)
    const char *raia_glfw_get_monitor_alt(void);
    void raia_glfw_set_monitor_callback_alt(GLFWmonitorfun callback);
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
    const char **raia_glfw_get_required_instance_extensions(uint32_t *count);
    // glfwGetInstanceProcAddress
    // glfwGetPhysicalDevicePresentationSupport
    // glfwCreateWindowSurface
    //
    // ウィンドウ
    //
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
    // (代替関数)
    const char *raia_glfw_get_window_pos_alt(void);
    void raia_glfw_set_window_pos_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_size_alt(void);
    void raia_glfw_set_window_size_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_close_alt(void);
    void raia_glfw_set_window_close_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_refresh_alt(void);
    void raia_glfw_set_window_refresh_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_focus_alt(void);
    void raia_glfw_set_window_focus_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_iconify_alt(void);
    void raia_glfw_set_window_iconify_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_maximize_alt(void);
    void raia_glfw_set_window_maximize_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_framebuffer_size_alt(const char *s);
    void raia_glfw_set_framebuffer_size_callback_alt(GLFWwindow *window);
    const char *raia_glfw_get_window_content_scale_alt(void);
    void raia_glfw_set_window_content_scale_callback_alt(GLFWwindow *window);
]]

local lib = ffi.load("raia_glfw")
local GLFW = {}

-- 定数

GLFW.VERSION_MAJOR                   = 3
GLFW.VERSION_MINOR                   = 4
GLFW.VERSION_REVISION                = 0
GLFW.TRUE                            = 1
GLFW.FALSE                           = 0
GLFW.RELEASE                         = 0
GLFW.PRESS                           = 1
GLFW.REPEAT                          = 2
GLFW.HAT_CENTERED                    = 0
GLFW.HAT_UP                          = 1
GLFW.HAT_RIGHT                       = 2
GLFW.HAT_DOWN                        = 4
GLFW.HAT_LEFT                        = 8
GLFW.HAT_RIGHT_UP                    = GLFW.HAT_RIGHT or GLFW.HAT_UP
GLFW.HAT_RIGHT_DOWN                  = GLFW.HAT_RIGHT or GLFW.HAT_DOWN
GLFW.HAT_LEFT_UP                     = GLFW.HAT_LEFT  or GLFW.HAT_UP
GLFW.HAT_LEFT_DOWN                   = GLFW.HAT_LEFT  or GLFW.HAT_DOWN
GLFW.KEY_UNKNOWN                     = -1
GLFW.KEY_SPACE                       = 32
GLFW.KEY_APOSTROPHE                  = 39  -- ' 
GLFW.KEY_COMMA                       = 44  -- , 
GLFW.KEY_MINUS                       = 45  -- - 
GLFW.KEY_PERIOD                      = 46  -- . 
GLFW.KEY_SLASH                       = 47  -- / 
GLFW.KEY_0                           = 48
GLFW.KEY_1                           = 49
GLFW.KEY_2                           = 50
GLFW.KEY_3                           = 51
GLFW.KEY_4                           = 52
GLFW.KEY_5                           = 53
GLFW.KEY_6                           = 54
GLFW.KEY_7                           = 55
GLFW.KEY_8                           = 56
GLFW.KEY_9                           = 57
GLFW.KEY_SEMICOLON                   = 59  -- ;
GLFW.KEY_EQUAL                       = 61  -- = 
GLFW.KEY_A                           = 65
GLFW.KEY_B                           = 66
GLFW.KEY_C                           = 67
GLFW.KEY_D                           = 68
GLFW.KEY_E                           = 69
GLFW.KEY_F                           = 70
GLFW.KEY_G                           = 71
GLFW.KEY_H                           = 72
GLFW.KEY_I                           = 73
GLFW.KEY_J                           = 74
GLFW.KEY_K                           = 75
GLFW.KEY_L                           = 76
GLFW.KEY_M                           = 77
GLFW.KEY_N                           = 78
GLFW.KEY_O                           = 79
GLFW.KEY_P                           = 80
GLFW.KEY_Q                           = 81
GLFW.KEY_R                           = 82
GLFW.KEY_S                           = 83
GLFW.KEY_T                           = 84
GLFW.KEY_U                           = 85
GLFW.KEY_V                           = 86
GLFW.KEY_W                           = 87
GLFW.KEY_X                           = 88
GLFW.KEY_Y                           = 89
GLFW.KEY_Z                           = 90
GLFW.KEY_LEFT_BRACKET                = 91  -- [ 
GLFW.KEY_BACKSLASH                   = 92  -- \\
GLFW.KEY_RIGHT_BRACKET               = 93  -- ] 
GLFW.KEY_GRAVE_ACCENT                = 96  -- ` 
GLFW.KEY_WORLD_1                     = 161 -- non-US #1 
GLFW.KEY_WORLD_2                     = 162 -- non-US #2 
GLFW.KEY_ESCAPE                      = 256
GLFW.KEY_ENTER                       = 257
GLFW.KEY_TAB                         = 258
GLFW.KEY_BACKSPACE                   = 259
GLFW.KEY_INSERT                      = 260
GLFW.KEY_DELETE                      = 261
GLFW.KEY_RIGHT                       = 262
GLFW.KEY_LEFT                        = 263
GLFW.KEY_DOWN                        = 264
GLFW.KEY_UP                          = 265
GLFW.KEY_PAGE_UP                     = 266
GLFW.KEY_PAGE_DOWN                   = 267
GLFW.KEY_HOME                        = 268
GLFW.KEY_END                         = 269
GLFW.KEY_CAPS_LOCK                   = 280
GLFW.KEY_SCROLL_LOCK                 = 281
GLFW.KEY_NUM_LOCK                    = 282
GLFW.KEY_PRINT_SCREEN                = 283
GLFW.KEY_PAUSE                       = 284
GLFW.KEY_F1                          = 290
GLFW.KEY_F2                          = 291
GLFW.KEY_F3                          = 292
GLFW.KEY_F4                          = 293
GLFW.KEY_F5                          = 294
GLFW.KEY_F6                          = 295
GLFW.KEY_F7                          = 296
GLFW.KEY_F8                          = 297
GLFW.KEY_F9                          = 298
GLFW.KEY_F10                         = 299
GLFW.KEY_F11                         = 300
GLFW.KEY_F12                         = 301
GLFW.KEY_F13                         = 302
GLFW.KEY_F14                         = 303
GLFW.KEY_F15                         = 304
GLFW.KEY_F16                         = 305
GLFW.KEY_F17                         = 306
GLFW.KEY_F18                         = 307
GLFW.KEY_F19                         = 308
GLFW.KEY_F20                         = 309
GLFW.KEY_F21                         = 310
GLFW.KEY_F22                         = 311
GLFW.KEY_F23                         = 312
GLFW.KEY_F24                         = 313
GLFW.KEY_F25                         = 314
GLFW.KEY_KP_0                        = 320
GLFW.KEY_KP_1                        = 321
GLFW.KEY_KP_2                        = 322
GLFW.KEY_KP_3                        = 323
GLFW.KEY_KP_4                        = 324
GLFW.KEY_KP_5                        = 325
GLFW.KEY_KP_6                        = 326
GLFW.KEY_KP_7                        = 327
GLFW.KEY_KP_8                        = 328
GLFW.KEY_KP_9                        = 329
GLFW.KEY_KP_DECIMAL                  = 330
GLFW.KEY_KP_DIVIDE                   = 331
GLFW.KEY_KP_MULTIPLY                 = 332
GLFW.KEY_KP_SUBTRACT                 = 333
GLFW.KEY_KP_ADD                      = 334
GLFW.KEY_KP_ENTER                    = 335
GLFW.KEY_KP_EQUAL                    = 336
GLFW.KEY_LEFT_SHIFT                  = 340
GLFW.KEY_LEFT_CONTROL                = 341
GLFW.KEY_LEFT_ALT                    = 342
GLFW.KEY_LEFT_SUPER                  = 343
GLFW.KEY_RIGHT_SHIFT                 = 344
GLFW.KEY_RIGHT_CONTROL               = 345
GLFW.KEY_RIGHT_ALT                   = 346
GLFW.KEY_RIGHT_SUPER                 = 347
GLFW.KEY_MENU                        = 348
GLFW.KEY_LAST                        = GLFW.KEY_MENU
GLFW.MOD_SHIFT                       = 0x0001
GLFW.MOD_CONTROL                     = 0x0002
GLFW.MOD_ALT                         = 0x0004
GLFW.MOD_SUPER                       = 0x0008
GLFW.MOD_CAPS_LOCK                   = 0x0010
GLFW.MOD_NUM_LOCK                    = 0x0020
GLFW.MOUSE_BUTTON_1                  = 0
GLFW.MOUSE_BUTTON_2                  = 1
GLFW.MOUSE_BUTTON_3                  = 2
GLFW.MOUSE_BUTTON_4                  = 3
GLFW.MOUSE_BUTTON_5                  = 4
GLFW.MOUSE_BUTTON_6                  = 5
GLFW.MOUSE_BUTTON_7                  = 6
GLFW.MOUSE_BUTTON_8                  = 7
GLFW.MOUSE_BUTTON_LAST               = GLFW.MOUSE_BUTTON_8
GLFW.MOUSE_BUTTON_LEFT               = GLFW.MOUSE_BUTTON_1
GLFW.MOUSE_BUTTON_RIGHT              = GLFW.MOUSE_BUTTON_2
GLFW.MOUSE_BUTTON_MIDDLE             = GLFW.MOUSE_BUTTON_3
GLFW.JOYSTICK_1                      = 0
GLFW.JOYSTICK_2                      = 1
GLFW.JOYSTICK_3                      = 2
GLFW.JOYSTICK_4                      = 3
GLFW.JOYSTICK_5                      = 4
GLFW.JOYSTICK_6                      = 5
GLFW.JOYSTICK_7                      = 6
GLFW.JOYSTICK_8                      = 7
GLFW.JOYSTICK_9                      = 8
GLFW.JOYSTICK_10                     = 9
GLFW.JOYSTICK_11                     = 10
GLFW.JOYSTICK_12                     = 11
GLFW.JOYSTICK_13                     = 12
GLFW.JOYSTICK_14                     = 13
GLFW.JOYSTICK_15                     = 14
GLFW.JOYSTICK_16                     = 15
GLFW.JOYSTICK_LAST                   = GLFW.JOYSTICK_16
GLFW.GAMEPAD_BUTTON_A                = 0
GLFW.GAMEPAD_BUTTON_B                = 1
GLFW.GAMEPAD_BUTTON_X                = 2
GLFW.GAMEPAD_BUTTON_Y                = 3
GLFW.GAMEPAD_BUTTON_LEFT_BUMPER      = 4
GLFW.GAMEPAD_BUTTON_RIGHT_BUMPER     = 5
GLFW.GAMEPAD_BUTTON_BACK             = 6
GLFW.GAMEPAD_BUTTON_START            = 7
GLFW.GAMEPAD_BUTTON_GUIDE            = 8
GLFW.GAMEPAD_BUTTON_LEFT_THUMB       = 9
GLFW.GAMEPAD_BUTTON_RIGHT_THUMB      = 10
GLFW.GAMEPAD_BUTTON_DPAD_UP          = 11
GLFW.GAMEPAD_BUTTON_DPAD_RIGHT       = 12
GLFW.GAMEPAD_BUTTON_DPAD_DOWN        = 13
GLFW.GAMEPAD_BUTTON_DPAD_LEFT        = 14
GLFW.GAMEPAD_BUTTON_LAST             = GLFW.GAMEPAD_BUTTON_DPAD_LEFT
GLFW.GAMEPAD_BUTTON_CROSS            = GLFW.GAMEPAD_BUTTON_A
GLFW.GAMEPAD_BUTTON_CIRCLE           = GLFW.GAMEPAD_BUTTON_B
GLFW.GAMEPAD_BUTTON_SQUARE           = GLFW.GAMEPAD_BUTTON_X
GLFW.GAMEPAD_BUTTON_TRIANGLE         = GLFW.GAMEPAD_BUTTON_Y
GLFW.GAMEPAD_AXIS_LEFT_X             = 0
GLFW.GAMEPAD_AXIS_LEFT_Y             = 1
GLFW.GAMEPAD_AXIS_RIGHT_X            = 2
GLFW.GAMEPAD_AXIS_RIGHT_Y            = 3
GLFW.GAMEPAD_AXIS_LEFT_TRIGGER       = 4
GLFW.GAMEPAD_AXIS_RIGHT_TRIGGER      = 5
GLFW.GAMEPAD_AXIS_LAST               = GLFW.GAMEPAD_AXIS_RIGHT_TRIGGER
GLFW.NO_ERROR                        = 0
GLFW.NOT_INITIALIZED                 = 0x00010001
GLFW.NO_CURRENT_CONTEXT              = 0x00010002
GLFW.INVALID_ENUM                    = 0x00010003
GLFW.INVALID_VALUE                   = 0x00010004
GLFW.OUT_OF_MEMORY                   = 0x00010005
GLFW.API_UNAVAILABLE                 = 0x00010006
GLFW.VERSION_UNAVAILABLE             = 0x00010007
GLFW.PLATFORM_ERROR                  = 0x00010008
GLFW.FORMAT_UNAVAILABLE              = 0x00010009
GLFW.NO_WINDOW_CONTEXT               = 0x0001000A
GLFW.CURSOR_UNAVAILABLE              = 0x0001000B
GLFW.FEATURE_UNAVAILABLE             = 0x0001000C
GLFW.FEATURE_UNIMPLEMENTED           = 0x0001000D
GLFW.PLATFORM_UNAVAILABLE            = 0x0001000E
GLFW.FOCUSED                         = 0x00020001
GLFW.ICONIFIED                       = 0x00020002
GLFW.RESIZABLE                       = 0x00020003
GLFW.VISIBLE                         = 0x00020004
GLFW.DECORATED                       = 0x00020005
GLFW.AUTO_ICONIFY                    = 0x00020006
GLFW.FLOATING                        = 0x00020007
GLFW.MAXIMIZED                       = 0x00020008
GLFW.CENTER_CURSOR                   = 0x00020009
GLFW.TRANSPARENT_FRAMEBUFFER         = 0x0002000A
GLFW.HOVERED                         = 0x0002000B
GLFW.FOCUS_ON_SHOW                   = 0x0002000C
GLFW.MOUSE_PASSTHROUGH               = 0x0002000D
GLFW.POSITION_X                      = 0x0002000E
GLFW.POSITION_Y                      = 0x0002000F
GLFW.RED_BITS                        = 0x00021001
GLFW.GREEN_BITS                      = 0x00021002
GLFW.BLUE_BITS                       = 0x00021003
GLFW.ALPHA_BITS                      = 0x00021004
GLFW.DEPTH_BITS                      = 0x00021005
GLFW.STENCIL_BITS                    = 0x00021006
GLFW.ACCUM_RED_BITS                  = 0x00021007
GLFW.ACCUM_GREEN_BITS                = 0x00021008
GLFW.ACCUM_BLUE_BITS                 = 0x00021009
GLFW.ACCUM_ALPHA_BITS                = 0x0002100A
GLFW.AUX_BUFFERS                     = 0x0002100B
GLFW.STEREO                          = 0x0002100C
GLFW.SAMPLES                         = 0x0002100D
GLFW.SRGB_CAPABLE                    = 0x0002100E
GLFW.REFRESH_RATE                    = 0x0002100F
GLFW.DOUBLEBUFFER                    = 0x00021010
GLFW.CLIENT_API                      = 0x00022001
GLFW.CONTEXT_VERSION_MAJOR           = 0x00022002
GLFW.CONTEXT_VERSION_MINOR           = 0x00022003
GLFW.CONTEXT_REVISION                = 0x00022004
GLFW.CONTEXT_ROBUSTNESS              = 0x00022005
GLFW.OPENGL_FORWARD_COMPAT           = 0x00022006
GLFW.CONTEXT_DEBUG                   = 0x00022007
GLFW.OPENGL_DEBUG_CONTEXT            = GLFW.CONTEXT_DEBUG
GLFW.OPENGL_PROFILE                  = 0x00022008
GLFW.CONTEXT_RELEASE_BEHAVIOR        = 0x00022009
GLFW.CONTEXT_NO_ERROR                = 0x0002200A
GLFW.CONTEXT_CREATION_API            = 0x0002200B
GLFW.SCALE_TO_MONITOR                = 0x0002200C
GLFW.COCOA_RETINA_FRAMEBUFFER        = 0x00023001
GLFW.COCOA_FRAME_NAME                = 0x00023002
GLFW.COCOA_GRAPHICS_SWITCHING        = 0x00023003
GLFW.X11_CLASS_NAME                  = 0x00024001
GLFW.X11_INSTANCE_NAME               = 0x00024002
GLFW.WIN32_KEYBOARD_MENU             = 0x00025001
GLFW.WAYLAND_APP_ID                  = 0x00026001
GLFW.NO_API                          = 0
GLFW.OPENGL_API                      = 0x00030001
GLFW.OPENGL_ES_API                   = 0x00030002
GLFW.NO_ROBUSTNESS                   = 0
GLFW.NO_RESET_NOTIFICATION           = 0x00031001
GLFW.LOSE_CONTEXT_ON_RESET           = 0x00031002
GLFW.OPENGL_ANY_PROFILE              = 0
GLFW.OPENGL_CORE_PROFILE             = 0x00032001
GLFW.OPENGL_COMPAT_PROFILE           = 0x00032002
GLFW.CURSOR                          = 0x00033001
GLFW.STICKY_KEYS                     = 0x00033002
GLFW.STICKY_MOUSE_BUTTONS            = 0x00033003
GLFW.LOCK_KEY_MODS                   = 0x00033004
GLFW.RAW_MOUSE_MOTION                = 0x00033005
GLFW.CURSOR_NORMAL                   = 0x00034001
GLFW.CURSOR_HIDDEN                   = 0x00034002
GLFW.CURSOR_DISABLED                 = 0x00034003
GLFW.CURSOR_CAPTURED                 = 0x00034004
GLFW.ANY_RELEASE_BEHAVIOR            = 0
GLFW.RELEASE_BEHAVIOR_FLUSH          = 0x00035001
GLFW.RELEASE_BEHAVIOR_NONE           = 0x00035002
GLFW.NATIVE_CONTEXT_API              = 0x00036001
GLFW.EGL_CONTEXT_API                 = 0x00036002
GLFW.OSMESA_CONTEXT_API              = 0x00036003
GLFW.ANGLE_PLATFORM_TYPE_NONE        = 0x00037001
GLFW.ANGLE_PLATFORM_TYPE_OPENGL      = 0x00037002
GLFW.ANGLE_PLATFORM_TYPE_OPENGLES    = 0x00037003
GLFW.ANGLE_PLATFORM_TYPE_D3D9        = 0x00037004
GLFW.ANGLE_PLATFORM_TYPE_D3D11       = 0x00037005
GLFW.ANGLE_PLATFORM_TYPE_VULKAN      = 0x00037007
GLFW.ANGLE_PLATFORM_TYPE_METAL       = 0x00037008
GLFW.WAYLAND_PREFER_LIBDECOR         = 0x00038001
GLFW.WAYLAND_DISABLE_LIBDECOR        = 0x00038002
GLFW.ANY_POSITION                    = 0x80000000
GLFW.ARROW_CURSOR                    = 0x00036001
GLFW.IBEAM_CURSOR                    = 0x00036002
GLFW.CROSSHAIR_CURSOR                = 0x00036003
GLFW.POINTING_HAND_CURSOR            = 0x00036004
GLFW.RESIZE_EW_CURSOR                = 0x00036005
GLFW.RESIZE_NS_CURSOR                = 0x00036006
GLFW.RESIZE_NWSE_CURSOR              = 0x00036007
GLFW.RESIZE_NESW_CURSOR              = 0x00036008
GLFW.RESIZE_ALL_CURSOR               = 0x00036009
GLFW.NOT_ALLOWED_CURSOR              = 0x0003600A
GLFW.HRESIZE_CURSOR                  = GLFW.RESIZE_EW_CURSOR
GLFW.VRESIZE_CURSOR                  = GLFW.RESIZE_NS_CURSOR
GLFW.HAND_CURSOR                     = GLFW.POINTING_HAND_CURSOR
GLFW.CONNECTED                       = 0x00040001
GLFW.DISCONNECTED                    = 0x00040002
GLFW.JOYSTICK_HAT_BUTTONS            = 0x00050001
GLFW.ANGLE_PLATFORM_TYPE             = 0x00050002
GLFW.PLATFORM                        = 0x00050003
GLFW.COCOA_CHDIR_RESOURCES           = 0x00051001
GLFW.COCOA_MENUBAR                   = 0x00051002
GLFW.X11_XCB_VULKAN_SURFACE          = 0x00052001
GLFW.WAYLAND_LIBDECOR                = 0x00053001
GLFW.ANY_PLATFORM                    = 0x00060000
GLFW.PLATFORM_WIN32                  = 0x00060001
GLFW.PLATFORM_COCOA                  = 0x00060002
GLFW.PLATFORM_WAYLAND                = 0x00060003
GLFW.PLATFORM_X11                    = 0x00060004
GLFW.PLATFORM_NULL                   = 0x00060005
GLFW.DONT_CARE                       = -1

-- コンテキスト

function GLFW.makeContextCurrent(window)
    lib.raia_glfw_make_context_current(window)
end

function GLFW.getCurrentContext()
    return lib.raia_glfw_get_current_context()
end

function GLFW.swapInterval(interval)
    lib.raia_glfw_swap_interval(interval)
end

function GLFW.extensionSupported(extension)
    return lib.raia_glfw_extension_supported(extension)
end

function GLFW.getProcAddress(procname)
    return lib.raia_glfw_get_proc_address(procname)
end


-- 初期化・バージョン・エラー

function GLFW.init()
    return lib.raia_glfw_init()
end

function GLFW.terminate()
    lib.raia_glfw_terminate()
end

function GLFW.initHint(hint, value)
    lib.raia_glfw_init_hint(hint, value)
end

function GLFW.getVersion(major, minor, rev)
    lib.raia_glfw_get_version(major, minor, rev)
end

function GLFW.getVersionString()
    return lib.raia_glfw_get_version_string()
end

function GLFW.getError(description)
    return lib.raia_glfw_get_error(description)
end

function GLFW.setErrorCallback(callback)
    return lib.raia_glfw_set_error_callback(callback)
end

-- (代替関数)

function GLFW.getErrorCallbackAlt()
    return lib.raia_glfw_get_error_callback_alt()
end

function GLFW.setErrorCallbackAlt()
    lib.raia_glfw_set_error_callback_alt()
end


-- 入力

function GLFW.getInputMode(window, mode)
    return lib.raia_glfw_get_input_mode(window, mode)
end

function GLFW.setInputMode(window, mode, value)
    lib.raia_glfw_set_input_mode(window, mode, value)
end

function GLFW.rawMouseMotionSupported()
    return lib.raia_glfw_raw_mouse_motion_supported()
end

function GLFW.getKeyName(key, scancode)
    return lib.raia_glfw_get_key_name(key, scancode)
end

function GLFW.getKeyScancode(key)
    return lib.raia_glfw_get_key_scancode(key)
end

function GLFW.getKey(window, key)
    return lib.raia_glfw_get_key(window, key)
end

function GLFW.getMouseButton(window, button)
    return lib.raia_glfw_get_mouse_button(window, button)
end

function GLFW.getCursorPos(window, xpos, ypos)
    lib.raia_glfw_get_cursor_pos(window, xpos, ypos)
end

function GLFW.setCursorPos(window, xpos, ypos)
    lib.raia_glfw_set_cursor_pos(window, xpos, ypos)
end

function GLFW.createCursor(image, xhot, yhot)
    return lib.raia_glfw_create_cursor(image, xhot, yhot)
end

function GLFW.createStandardCursor(shape)
    return lib.raia_glfw_create_standard_cursor(shape)
end

function GLFW.destroyCursor(cursor)
    lib.raia_glfw_destroy_cursor(cursor)
end

function GLFW.setCursor(window, cursor)
    lib.raia_glfw_set_cursor(window, cursor)
end

function GLFW.setKeyCallback(window, callback)
    return lib.raia_glfw_set_key_callback(window, callback)
end

function GLFW.setCharCallback(window, callback)
    return lib.raia_glfw_set_char_callback(window, callback)
end

function GLFW.setCharModsCallback(window, callback)
    return lib.raia_glfw_set_char_mods_callback(window, callback)
end

function GLFW.setMouseButtonCallback(window, callback)
    return lib.raia_glfw_set_mouse_button_callback(window, callback)
end

function GLFW.setCursorPosCallback(window, callback)
    return lib.raia_glfw_set_cursor_pos_callback(window, callback)
end

function GLFW.setCursorEnterCallback(window, callback)
    return lib.raia_glfw_set_cursor_enter_callback(window, callback)
end

function GLFW.setScrollCallback(window, callback)
    return lib.raia_glfw_set_scroll_callback(window, callback)
end

function GLFW.setDropCallback(window, callback)
    return lib.raia_glfw_set_drop_callback(window, callback)
end

function GLFW.joystickPresent(jid)
    return lib.raia_glfw_joystick_present(jid)
end

function GLFW.getJoystickAxes(jid, count)
    return lib.raia_glfw_get_joystick_axes(jid, count)
end

function GLFW.getJoystickButtons(jid, count)
    return lib.raia_glfw_get_joystick_buttons(jid, count)
end

function GLFW.getJoystickHats(jid, count)
    return lib.raia_glfw_get_joystick_hats(jid, count)
end

function GLFW.getJoystickName(jid)
    return lib.raia_glfw_get_joystick_name(jid)
end

function GLFW.getJoystickGuid(jid)
    return lib.raia_glfw_get_joystick_guid(jid)
end

function GLFW.setJoystickUserPointer(jid, pointer)
    lib.raia_glfw_set_joystick_user_pointer(jid, pointer)
end

function GLFW.getJoystickUserPointer(jid)
    return lib.raia_glfw_get_joystick_user_pointer(jid)
end

function GLFW.joystickIsGamepad(jid)
    return lib.raia_glfw_joystick_is_gamepad(jid)
end

function GLFW.setJoystickCallback(callback)
    return lib.raia_glfw_set_joystick_callback(callback)
end

function GLFW.updateGamepadMappings(string)
    return lib.raia_glfw_update_gamepad_mappings(string)
end

function GLFW.getGamepadName(jid)
    return lib.raia_glfw_get_gamepad_name(jid)
end

function GLFW.getGamepadState(jid, state)
    return lib.raia_glfw_get_gamepad_state(jid, state)
end

function GLFW.setClipboardString(window, string)
    lib.raia_glfw_set_clipboard_string(window, string)
end

function GLFW.getClipboardString(window)
    return lib.raia_glfw_get_clipboard_string(window)
end

function GLFW.getTime()
    return lib.raia_glfw_get_time()
end

function GLFW.setTime(time)
    lib.raia_glfw_set_time(time)
end

function GLFW.getTimerValue()
    return lib.raia_glfw_get_timer_value()
end

function GLFW.getTimerFrequency()
    return lib.raia_glfw_get_timer_frequency()
end

-- (代替関数)

function GLFW.getKeyAlt()
    lib.raia_glfw_get_key_alt()
end

function GLFW.setKeyCallbackAlt(window)
    lib.raia_glfw_set_key_callback_alt(window)
end

function GLFW.getCharAlt()
    return lib.raia_glfw_get_char_alt()
end

function GLFW.setCharCallbackAlt(window)
    lib.raia_glfw_set_char_callback_alt(window)
end

function GLFW.getCharModsAlt()
    return lib.raia_glfw_get_char_mods_alt()
end

function GLFW.setCharModsCallbackAlt(window)
    lib.raia_glfw_set_char_mods_callback_alt(window)
end

function GLFW.getMouseButtonAlt()
    return lib.raia_glfw_get_mouse_button_alt()
end

function GLFW.setMouseButtonCallbackAlt(window)
    lib.raia_glfw_set_mouse_button_callback_alt(window)
end

function GLFW.getCursorPosAlt()
    return lib.raia_glfw_get_cursor_pos_alt()
end

function GLFW.setCursorPosCallbackAlt(window)
    lib.raia_glfw_set_cursor_pos_callback_alt(window)
end

function GLFW.getCursorEnterAlt()
    return lib.raia_glfw_get_cursor_enter_alt()
end

function GLFW.setCursorEnterCallbackAlt(window)
    lib.raia_glfw_set_cursor_enter_callback_alt(window)
end

function GLFW.getScrollAlt()
    return lib.raia_glfw_get_scroll_alt()
end

function GLFW.setScrollCallbackAlt(window)
    lib.raia_glfw_set_scroll_callback_alt(window)
end

function GLFW.getDropAlt()
    return lib.raia_glfw_get_drop_alt()
end

function GLFW.setDropCallbackAlt(window)
    lib.raia_glfw_set_drop_callback_alt(window)
end

function GLFW.getJoystickAlt()
    return lib.raia_glfw_get_joystick_alt()
end

function GLFW.setJoystickCallbackAlt()
    lib.raia_glfw_set_joystick_callback_alt()
end


-- モニター

function GLFW.getMonitors(count)
    return lib.raia_glfw_get_monitors(count)
end

function GLFW.getPrimaryMonitor()
    return lib.raia_glfw_get_primary_monitor()
end

function GLFW.getMonitorPos(monitor, xpos, ypos)
    lib.raia_glfw_get_monitor_pos(monitor, xpos, ypos)
end

function GLFW.getMonitorWorkarea(monitor, xpos, ypos, width, height)
    lib.raia_glfw_get_monitor_workarea(monitor, xpos, ypos, width, height)
end

function GLFW.getMonitorPhysicalSize(monitor, widthMM, heightMM)
    lib.raia_glfw_get_monitor_physical_size(monitor, widthMM, heightMM)
end

function GLFW.getMonitorContentScale(monitor, xscale, yscale)
    lib.raia_glfw_get_monitor_content_scale(monitor, xscale, yscale)
end

function GLFW.getMonitorName(monitor)
    return lib.raia_glfw_get_monitor_name(monitor)
end

function GLFW.setMonitorUserPointer(monitor, pointer)
    lib.raia_glfw_set_monitor_user_pointer(monitor, pointer)
end

function GLFW.getMonitorUserPointer(monitor)
    return lib.raia_glfw_get_monitor_user_pointer(monitor)
end

function GLFW.setMonitorCallback(callback)
    return lib.raia_glfw_set_monitor_callback(callback)
end

function GLFW.getVideoModes(monitor, count)
    return lib.raia_glfw_get_video_modes(monitor, count)
end

function GLFW.getVideoMode(monitor)
    return lib.raia_glfw_get_video_mode(monitor)
end

function GLFW.setGamma(monitor, gamma)
    lib.raia_glfw_set_gamma(monitor, gamma)
end

function GLFW.getGammaRamp(monitor)
    return lib.raia_glfw_get_gamma_ramp(monitor)
end

function GLFW.setGammaRamp(monitor, ramp)
    lib.raia_glfw_set_gamma_ramp(monitor, ramp)
end

-- (代替関数)

function GLFW.getMonitorAlt()
    lib.raia_glfw_get_monitor_alt()
end

function GLFW.setMonitorCallbackAlt(callback)
    lib.raia_glfw_set_monitor_callback_alt(callback)
end


-- ネイティブアクセス

-- glfwGetWin32Adapter
-- glfwGetWin32Monitor
-- glfwGetWin32Window
-- glfwGetWGLContext
-- glfwGetCocoaMonitor
-- glfwGetCocoaWindow
-- glfwGetNSGLContext
-- glfwGetX11Display
-- glfwGetX11Adapter
-- glfwGetX11Monitor
-- glfwGetX11Window
-- glfwSetX11SelectionString
-- glfwGetX11SelectionString
-- glfwGetGLXContext
-- glfwGetGLXWindow
-- glfwGetWaylandDisplay
-- glfwGetWaylandMonitor
-- glfwGetWaylandWindow
-- glfwGetEGLDisplay
-- glfwGetEGLContext
-- glfwGetEGLSurface
-- glfwGetOSMesaColorBuffer
-- glfwGetOSMesaDepthBuffer
-- glfwGetOSMesaContext

-- Vulkanサポート

function GLFW.vulkanSupported()
    return lib.raia_glfw_vulkan_supported()
end

function GLFW.getRequiredInstanceExtensions(count)
    return lib.raia_glfw_get_required_instance_extensions(count)
end

-- glfwGetInstanceProcAddress
-- glfwGetPhysicalDevicePresentationSupport
-- glfwCreateWindowSurface

-- ウィンドウ

function GLFW.defaultWindowHints()
    return lib.raia_glfw_default_window_hints()
end

function GLFW.windowHint(hint, value)
    lib.raia_glfw_window_hint(hint, value)
end

function GLFW.windowHintString(hint, value)
    lib.raia_glfw_window_hint_string(hint, value)
end

function GLFW.createWindow(width, height, title, monitor, share)
    local obj = lib.raia_glfw_create_window(width, height, title, monitor, share)
    ffi.gc(obj, lib.raia_glfw_destroy_window)
    return obj
end

function GLFW.destroyWindow(window)
    lib.raia_glfw_destroy_window(window)
end

function GLFW.windowShouldClose(window)
    return lib.raia_glfw_window_should_close(window)
end

function GLFW.setWindowShouldClose(window, value)
    lib.raia_glfw_set_window_should_close(window, value)
end

function GLFW.setWindowTitle(window, title)
    lib.raia_glfw_set_window_title(window, title)
end

function GLFW.setWindowIcon(window, count, images)
    lib.raia_glfw_set_window_icon(window, count, images)
end

function GLFW.getWindowPos(window, xpos, ypos)
    lib.raia_glfw_get_window_pos(window, xpos, ypos)
end

function GLFW.setWindowPos(window, xpos, ypos)
    lib.raia_glfw_set_window_pos(window, xpos, ypos)
end

function GLFW.getWindowSize(window, width, height)
    lib.raia_glfw_get_window_size(window, width, height)
end

function GLFW.setWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight)
    lib.raia_glfw_set_window_size_limits(window, minwidth, minheight, maxwidth, maxheight)
end

function GLFW.setWindowAspectRatio(window, numer, denom)
    lib.raia_glfw_set_window_aspect_ratio(window, numer, denom)
end

function GLFW.setWindowSize(window, width, height)
    lib.raia_glfw_set_window_size(window, width, height)
end

function GLFW.getFramebufferSize(window, width, height)
    lib.raia_glfw_get_framebuffer_size(window, width, height)
end

function GLFW.getWindowFrameSize(window, left, top, right, bottom)
    lib.raia_glfw_get_window_frame_size(window, left, top, right, bottom)
end

function GLFW.getWindowContentScale(window, xscale, yscale)
    lib.raia_glfw_get_window_content_scale(window, xscale, yscale)
end

function GLFW.getWindowOpacity(window)
    return lib.raia_glfw_get_window_opacity(window)
end

function GLFW.setWindowOpacity(window, opacity)
    lib.raia_glfw_set_window_opacity(window, opacity)
end

function GLFW.iconifyWindow(window)
    lib.raia_glfw_iconify_window(window)
end

function GLFW.restoreWindow(window)
    lib.raia_glfw_restore_window(window)
end

function GLFW.maximizeWindow(window)
    lib.raia_glfw_maximize_window(window)
end

function GLFW.showWindow(window)
    lib.raia_glfw_show_window(window)
end

function GLFW.hideWindow(window)
    lib.raia_glfw_hide_window(window)
end

function GLFW.focusWindow(window)
    lib.raia_glfw_focus_window(window)
end

function GLFW.requestWindowAttention(window)
    lib.raia_glfw_request_window_attention(window)
end

function GLFW.getWindowMonitor(window)
    return lib.raia_glfw_get_window_monitor(window)
end

function GLFW.setWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate)
    lib.raia_glfw_set_window_monitor(window, monitor, xpos, ypos, width, height, refreshRate)
end

function GLFW.getWindowAttrib(window, attrib)
    return lib.raia_glfw_get_window_attrib(window, attrib)
end

function GLFW.setWindowAttrib(window, attrib, value)
    lib.raia_glfw_set_window_attrib(window, attrib, value)
end

function GLFW.setWindowUserPointer(window, pointer)
    lib.raia_glfw_set_window_user_pointer(window, pointer)
end

function GLFW.getWindowUserPointer(window)
    return lib.raia_glfw_get_window_user_pointer(window)
end

function GLFW.setWindowPosCallback(window, callback)
    return lib.raia_glfw_set_window_pos_callback(window, callback)
end

function GLFW.setWindowSizeCallback(window, callback)
    return lib.raia_glfw_set_window_size_callback(window, callback)
end

function GLFW.setWindowCloseCallback(window, callback)
    return lib.raia_glfw_set_window_close_callback(window, callback)
end

function GLFW.setWindowRefreshCallback(window, callback)
    return lib.raia_glfw_set_window_refresh_callback(window, callback)
end

function GLFW.setWindowFocusCallback(window, callback)
    return lib.raia_glfw_set_window_focus_callback(window, callback)
end

function GLFW.setWindowIconifyCallback(window, callback)
    return lib.raia_glfw_set_window_iconify_callback(window, callback)
end

function GLFW.setWindowMaximizeCallback(window, callback)
    return lib.raia_glfw_set_window_maximize_callback(window, callback)
end

function GLFW.setFramebufferSizeCallback(window, callback)
    return lib.raia_glfw_set_framebuffer_size_callback(window, callback)
end

function GLFW.setWindowContentScaleCallback(window, callback)
    return lib.raia_glfw_set_window_content_scale_callback(window, callback)
end

function GLFW.pollEvents()
    lib.raia_glfw_poll_events()
end

function GLFW.waitEvents()
    lib.raia_glfw_wait_events()
end

function GLFW.waitEventsTimeout(timeout)
    lib.raia_glfw_wait_events_timeout(timeout)
end

function GLFW.postEmptyEvent()
    lib.raia_glfw_post_empty_event()
end

function GLFW.swapBuffers(window)
    lib.raia_glfw_swap_buffers(window)
end

-- (代替関数)

function GLFW.getWindowPosAlt()
    return lib.raia_glfw_get_window_pos_alt()
end

function GLFW.setWindowPosCallbackAlt(window)
    lib.raia_glfw_set_window_pos_callback_alt(window)
end

function GLFW.getWindowSizeAlt()
    return lib.raia_glfw_get_window_size_alt()
end

function GLFW.setWindowSizeCallbackAlt(window)
    lib.raia_glfw_set_window_size_callback_alt(window)
end

function GLFW.getWindowCloseAlt()
    return lib.raia_glfw_get_window_close_alt()
end

function GLFW.setWindowCloseCallbackAlt(window)
    lib.raia_glfw_set_window_close_callback_alt(window)
end

function GLFW.getWindowRefreshAlt()
    return lib.raia_glfw_get_window_refresh_alt()
end

function GLFW.setWindowRefreshCallbackAlt(window)
    lib.raia_glfw_set_window_refresh_callback_alt(window)
end

function GLFW.getWindowFocusAlt()
    return lib.raia_glfw_get_window_focus_alt()
end

function GLFW.setWindowFocusCallbackAlt(window)
    lib.raia_glfw_set_window_focus_callback_alt(window)
end

function GLFW.getWindowIconifyAlt()
    return lib.raia_glfw_get_window_iconify_alt()
end

function GLFW.setWindowIconifyCallbackAlt(window)
    lib.raia_glfw_set_window_iconify_callback_alt(window)
end

function GLFW.getWindowMaximizeAlt()
    return lib.raia_glfw_get_window_maximize_alt()
end

function GLFW.setWindowMaximizeCallbackAlt(window)
    lib.raia_glfw_set_window_maximize_callback_alt(window)
end

function GLFW.getFramebufferSizeAlt(s)
    return lib.raia_glfw_get_framebuffer_size_alt(s)
end

function GLFW.setFramebufferSizeCallbackAlt(window)
    lib.raia_glfw_set_framebuffer_size_callback_alt(window)
end

function GLFW.getWindowContentScaleAlt()
    return lib.raia_glfw_get_window_content_scale_alt()
end

function GLFW.setWindowContentScaleCallbackAlt(window)
    lib.raia_glfw_set_window_content_scale_callback_alt(window)
end

return GLFW