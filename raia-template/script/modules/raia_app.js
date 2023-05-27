__Raia__.Core.Lib.open("raia_app");

module.exports = {
    init: __Raia__.Core.Lib.func("raia_app_init", 0), // (void)
    Shader: {
        init: __Raia__.Core.Lib.func("raia_app_shader_init", 2), // (width, height)
    },
    Window: {
        init: __Raia__.Core.Lib.func("raia_app_window_init", 3), // (width, height, title)
        setTitle: __Raia__.Core.Lib.func("raia_app_window_set_title", 2), // (window, title)
        shouldClose: __Raia__.Core.Lib.func("raia_app_window_should_close", 1), // (window)
        pollEvents: __Raia__.Core.Lib.func("raia_app_window_poll_events", 0), // (void)
        waitEventTimeout: __Raia__.Core.Lib.func("raia_app_glfw_wait_event_timeout", 1), // (void)
    },
    Screen: {
        initPixels: __Raia__.Core.Lib.func("raia_app_screen_init_pixels", 0),
        //setPixels: __Raia__.Core.Lib.func("raia_app_screen_set_pixels", 1),
        redraw: __Raia__.Core.Lib.func("raia_app_screen_redraw", 13), // (window, pixels)
    },
    Event: {
        error: __Raia__.Core.Lib.func("raia_app_event_error_callback", 1), // (function(int error, const char *message))
        joystick: __Raia__.Core.Lib.func("raia_app_event_joystick_callback", 2), // (function(int jid, int event))
        windowPos:  __Raia__.Core.Lib.func("raia_app_event_window_pos_callback", 2),
        windowSize:  __Raia__.Core.Lib.func("raia_app_event_window_size_callback", 2),
        windowClose:  __Raia__.Core.Lib.func("raia_app_event_window_close_callback", 2),
        windowRefresh:  __Raia__.Core.Lib.func("raia_app_event_window_refresh_callback", 2),
        windowFocus:  __Raia__.Core.Lib.func("raia_app_event_window_focus_callback", 2),
        windowIconify:  __Raia__.Core.Lib.func("raia_app_event_window_iconify_callback", 2),
        frame:  __Raia__.Core.Lib.func("raia_app_event_framebuffer_size_callback", 2),
        key: __Raia__.Core.Lib.func("raia_app_event_key_callback", 2), // (window, function(key, scancode, action, mods))
        char: __Raia__.Core.Lib.func("raia_app_event_character_callback", 2), // (window, function(unsigned int codepoint))
        charMods: __Raia__.Core.Lib.func("raia_app_event_character_mods_callback", 2),
        mouse: __Raia__.Core.Lib.func("raia_app_event_mouse_button_callback", 2), // (function(int button, int action, int mods))
        cursor: __Raia__.Core.Lib.func("raia_app_event_cursor_position_callback", 2), // (function(double xpos, double ypos))
        enter: __Raia__.Core.Lib.func("raia_app_event_cursor_enter_callback", 2), // (function(int entered))
        scroll: __Raia__.Core.Lib.func("raia_app_event_scroll_callback", 2), // (function(double xoffset, double yoffset))
        drop: __Raia__.Core.Lib.func("raia_app_event_drop_callback", 2), // (function(int count, const char** paths))
    },
    Time: {
        getCurrentTime: __Raia__.Core.Lib.func("raia_app_time_get_current_time", 0),
    },
    GLFW: {
        getTimerValue: __Raia__.Core.Lib.func("raia_app_glfw_get_timer_value", 0),
        getTimerFrequency: __Raia__.Core.Lib.func("raia_app_glfw_get_timer_frequency", 0),
        getTime: __Raia__.Core.Lib.func("raia_app_glfw_get_time", 0),
        setTime: __Raia__.Core.Lib.func("raia_app_glfw_set_time", 1),
        joystickPresent: __Raia__.Core.Lib.func("raia_app_glfw_joystick_present", 1),
        getJoystickAxes: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_axes", 1),
        getJoystickButtons: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_buttons", 1),
        getJoystickName: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_name", 1),
    }
};