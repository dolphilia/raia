import {Lib} from "raia_lib";
const lib = new Lib();

(function() {
    if (globalThis.__RAIA_GLFW__ === undefined) {
        globalThis.__RAIA_GLFW__ = {};
        globalThis.__RAIA_GLFW__.handle = lib.open("raia_glfw");
        // コンテキスト
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_make_context_current");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_current_context");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_swap_interval");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_extension_supported");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_proc_address");
        // 初期化・バージョン・エラー
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_init");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_terminate");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_init_hint");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_version");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_version_string");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_error");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_error_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_error_callback_alt"); // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_error_callback_alt"); // 代替
        // 入力
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_input_mode");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_input_mode");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_raw_mouse_motion_supported");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_key_name");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_key_scancode");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_key");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_mouse_button");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_cursor_pos");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor_pos");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_create_cursor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_create_standard_cursor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_destroy_cursor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_key_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_char_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_char_mods_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_mouse_button_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor_pos_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor_enter_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_scroll_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_drop_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_joystick_present");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_axes");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_buttons");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_hats");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_name");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_guid");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_joystick_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_joystick_is_gamepad");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_joystick_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_update_gamepad_mappings");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_gamepad_name");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_gamepad_state");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_clipboard_string");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_clipboard_string");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_time");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_time");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_timer_value");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_timer_frequency");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_key_alt");                   // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_key_callback_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_char_alt");                  // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_char_callback_alt");         // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_char_mods_alt");             // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_char_mods_callback_alt");    // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_mouse_button_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_mouse_button_callback_alt"); // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_cursor_pos_alt");            // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor_pos_callback_alt");   // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_cursor_enter_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_cursor_enter_callback_alt"); // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_scroll_alt");                // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_scroll_callback_alt");       // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_drop_alt");                  // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_drop_callback_alt");         // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_joystick_alt");              // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_joystick_callback_alt");     // 代替
        // モニター
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitors");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_primary_monitor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_pos");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_workarea");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_physical_size");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_content_scale");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_name");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_monitor_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_monitor_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_video_modes");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_video_mode");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_gamma");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_gamma_ramp");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_gamma_ramp");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_monitor_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_monitor_callback_alt"); // 代替
        // ネイティブアクセス
        // Vulkanサポート
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_vulkan_supported");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_required_instance_extensions");
        // ウィンドウ
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_default_window_hints");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_window_hint");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_window_hint_string");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_create_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_destroy_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_window_should_close");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_should_close");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_title");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_icon");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_pos");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_size");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_size_limits");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_aspect_ratio");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_size");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_framebuffer_size");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_frame_size");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_content_scale");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_opacity");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_opacity");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_iconify_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_restore_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_maximize_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_show_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_hide_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_focus_window");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_request_window_attention");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_monitor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_monitor");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_attrib");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_attrib");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_user_pointer");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_pos_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_size_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_close_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_refresh_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_focus_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_iconify_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_maximize_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_framebuffer_size_callback");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_content_scale_callback");        
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_poll_events");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_wait_events");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_wait_events_timeout");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_post_empty_event");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_swap_buffers");
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_pos_alt");                    // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_pos_callback_alt");           // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_size_alt");                   // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_size_callback_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_close_alt");                  // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_close_callback_alt");         // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_refresh_alt");                // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_refresh_callback_alt");       // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_focus_alt");                  // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_focus_callback_alt");         // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_iconify_alt");                // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_iconify_callback_alt");       // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_maximize_alt");               // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_maximize_callback_alt");      // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_framebuffer_size_alt");              // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_framebuffer_size_callback_alt");     // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_get_window_content_scale_alt");          // 代替
        lib.add(globalThis.__RAIA_GLFW__.handle, "raia_glfw_set_window_content_scale_callback_alt"); // 代替
    }
})();

export class GLFW {

    static VERSION_MAJOR                   = 3;
    static VERSION_MINOR                   = 4;
    static VERSION_REVISION                = 0;
    static TRUE                            = 1;
    static FALSE                           = 0;
    static RELEASE                         = 0;
    static PRESS                           = 1;
    static REPEAT                          = 2;
    static HAT_CENTERED                    = 0;
    static HAT_UP                          = 1;
    static HAT_RIGHT                       = 2;
    static HAT_DOWN                        = 4;
    static HAT_LEFT                        = 8;
    static HAT_RIGHT_UP                    = (this.HAT_RIGHT | this.HAT_UP);
    static HAT_RIGHT_DOWN                  = (this.HAT_RIGHT | this.HAT_DOWN);
    static HAT_LEFT_UP                     = (this.HAT_LEFT  | this.HAT_UP);
    static HAT_LEFT_DOWN                   = (this.HAT_LEFT  | this.HAT_DOWN);
    static KEY_UNKNOWN                     = -1;
    static KEY_SPACE                       = 32;
    static KEY_APOSTROPHE                  = 39  /* ' */;
    static KEY_COMMA                       = 44  /* , */;
    static KEY_MINUS                       = 45  /* - */;
    static KEY_PERIOD                      = 46  /* . */;
    static KEY_SLASH                       = 47  /* / */;
    static KEY_0                           = 48;
    static KEY_1                           = 49;
    static KEY_2                           = 50;
    static KEY_3                           = 51;
    static KEY_4                           = 52;
    static KEY_5                           = 53;
    static KEY_6                           = 54;
    static KEY_7                           = 55;
    static KEY_8                           = 56;
    static KEY_9                           = 57;
    static KEY_SEMICOLON                   = 59  /* ; */;
    static KEY_EQUAL                       = 61  /* = */;
    static KEY_A                           = 65;
    static KEY_B                           = 66;
    static KEY_C                           = 67;
    static KEY_D                           = 68;
    static KEY_E                           = 69;
    static KEY_F                           = 70;
    static KEY_G                           = 71;
    static KEY_H                           = 72;
    static KEY_I                           = 73;
    static KEY_J                           = 74;
    static KEY_K                           = 75;
    static KEY_L                           = 76;
    static KEY_M                           = 77;
    static KEY_N                           = 78;
    static KEY_O                           = 79;
    static KEY_P                           = 80;
    static KEY_Q                           = 81;
    static KEY_R                           = 82;
    static KEY_S                           = 83;
    static KEY_T                           = 84;
    static KEY_U                           = 85;
    static KEY_V                           = 86;
    static KEY_W                           = 87;
    static KEY_X                           = 88;
    static KEY_Y                           = 89;
    static KEY_Z                           = 90;
    static KEY_LEFT_BRACKET                = 91  /* [ */;
    static KEY_BACKSLASH                   = 92  /* \ */;
    static KEY_RIGHT_BRACKET               = 93  /* ] */;
    static KEY_GRAVE_ACCENT                = 96  /* ` */;
    static KEY_WORLD_1                     = 161 /* non-US #1 */;
    static KEY_WORLD_2                     = 162 /* non-US #2 */;
    static KEY_ESCAPE                      = 256;
    static KEY_ENTER                       = 257;
    static KEY_TAB                         = 258;
    static KEY_BACKSPACE                   = 259;
    static KEY_INSERT                      = 260;
    static KEY_DELETE                      = 261;
    static KEY_RIGHT                       = 262;
    static KEY_LEFT                        = 263;
    static KEY_DOWN                        = 264;
    static KEY_UP                          = 265;
    static KEY_PAGE_UP                     = 266;
    static KEY_PAGE_DOWN                   = 267;
    static KEY_HOME                        = 268;
    static KEY_END                         = 269;
    static KEY_CAPS_LOCK                   = 280;
    static KEY_SCROLL_LOCK                 = 281;
    static KEY_NUM_LOCK                    = 282;
    static KEY_PRINT_SCREEN                = 283;
    static KEY_PAUSE                       = 284;
    static KEY_F1                          = 290;
    static KEY_F2                          = 291;
    static KEY_F3                          = 292;
    static KEY_F4                          = 293;
    static KEY_F5                          = 294;
    static KEY_F6                          = 295;
    static KEY_F7                          = 296;
    static KEY_F8                          = 297;
    static KEY_F9                          = 298;
    static KEY_F10                         = 299;
    static KEY_F11                         = 300;
    static KEY_F12                         = 301;
    static KEY_F13                         = 302;
    static KEY_F14                         = 303;
    static KEY_F15                         = 304;
    static KEY_F16                         = 305;
    static KEY_F17                         = 306;
    static KEY_F18                         = 307;
    static KEY_F19                         = 308;
    static KEY_F20                         = 309;
    static KEY_F21                         = 310;
    static KEY_F22                         = 311;
    static KEY_F23                         = 312;
    static KEY_F24                         = 313;
    static KEY_F25                         = 314;
    static KEY_KP_0                        = 320;
    static KEY_KP_1                        = 321;
    static KEY_KP_2                        = 322;
    static KEY_KP_3                        = 323;
    static KEY_KP_4                        = 324;
    static KEY_KP_5                        = 325;
    static KEY_KP_6                        = 326;
    static KEY_KP_7                        = 327;
    static KEY_KP_8                        = 328;
    static KEY_KP_9                        = 329;
    static KEY_KP_DECIMAL                  = 330;
    static KEY_KP_DIVIDE                   = 331;
    static KEY_KP_MULTIPLY                 = 332;
    static KEY_KP_SUBTRACT                 = 333;
    static KEY_KP_ADD                      = 334;
    static KEY_KP_ENTER                    = 335;
    static KEY_KP_EQUAL                    = 336;
    static KEY_LEFT_SHIFT                  = 340;
    static KEY_LEFT_CONTROL                = 341;
    static KEY_LEFT_ALT                    = 342;
    static KEY_LEFT_SUPER                  = 343;
    static KEY_RIGHT_SHIFT                 = 344;
    static KEY_RIGHT_CONTROL               = 345;
    static KEY_RIGHT_ALT                   = 346;
    static KEY_RIGHT_SUPER                 = 347;
    static KEY_MENU                        = 348;
    static KEY_LAST                        = this.KEY_MENU;
    static MOD_SHIFT                       = 0x0001;
    static MOD_CONTROL                     = 0x0002;
    static MOD_ALT                         = 0x0004;
    static MOD_SUPER                       = 0x0008;
    static MOD_CAPS_LOCK                   = 0x0010;
    static MOD_NUM_LOCK                    = 0x0020;
    static MOUSE_BUTTON_1                  = 0;
    static MOUSE_BUTTON_2                  = 1;
    static MOUSE_BUTTON_3                  = 2;
    static MOUSE_BUTTON_4                  = 3;
    static MOUSE_BUTTON_5                  = 4;
    static MOUSE_BUTTON_6                  = 5;
    static MOUSE_BUTTON_7                  = 6;
    static MOUSE_BUTTON_8                  = 7;
    static MOUSE_BUTTON_LAST               = this.MOUSE_BUTTON_8;
    static MOUSE_BUTTON_LEFT               = this.MOUSE_BUTTON_1;
    static MOUSE_BUTTON_RIGHT              = this.MOUSE_BUTTON_2;
    static MOUSE_BUTTON_MIDDLE             = this.MOUSE_BUTTON_3;
    static JOYSTICK_1                      = 0;
    static JOYSTICK_2                      = 1;
    static JOYSTICK_3                      = 2;
    static JOYSTICK_4                      = 3;
    static JOYSTICK_5                      = 4;
    static JOYSTICK_6                      = 5;
    static JOYSTICK_7                      = 6;
    static JOYSTICK_8                      = 7;
    static JOYSTICK_9                      = 8;
    static JOYSTICK_10                     = 9;
    static JOYSTICK_11                     = 10;
    static JOYSTICK_12                     = 11;
    static JOYSTICK_13                     = 12;
    static JOYSTICK_14                     = 13;
    static JOYSTICK_15                     = 14;
    static JOYSTICK_16                     = 15;
    static JOYSTICK_LAST                   = this.JOYSTICK_16;
    static GAMEPAD_BUTTON_A                = 0;
    static GAMEPAD_BUTTON_B                = 1;
    static GAMEPAD_BUTTON_X                = 2;
    static GAMEPAD_BUTTON_Y                = 3;
    static GAMEPAD_BUTTON_LEFT_BUMPER      = 4;
    static GAMEPAD_BUTTON_RIGHT_BUMPER     = 5;
    static GAMEPAD_BUTTON_BACK             = 6;
    static GAMEPAD_BUTTON_START            = 7;
    static GAMEPAD_BUTTON_GUIDE            = 8;
    static GAMEPAD_BUTTON_LEFT_THUMB       = 9;
    static GAMEPAD_BUTTON_RIGHT_THUMB      = 10;
    static GAMEPAD_BUTTON_DPAD_UP          = 11;
    static GAMEPAD_BUTTON_DPAD_RIGHT       = 12;
    static GAMEPAD_BUTTON_DPAD_DOWN        = 13;
    static GAMEPAD_BUTTON_DPAD_LEFT        = 14;
    static GAMEPAD_BUTTON_LAST             = this.GAMEPAD_BUTTON_DPAD_LEFT;
    static GAMEPAD_BUTTON_CROSS            = this.GAMEPAD_BUTTON_A;
    static GAMEPAD_BUTTON_CIRCLE           = this.GAMEPAD_BUTTON_B;
    static GAMEPAD_BUTTON_SQUARE           = this.GAMEPAD_BUTTON_X;
    static GAMEPAD_BUTTON_TRIANGLE         = this.GAMEPAD_BUTTON_Y;
    static GAMEPAD_AXIS_LEFT_X             = 0;
    static GAMEPAD_AXIS_LEFT_Y             = 1;
    static GAMEPAD_AXIS_RIGHT_X            = 2;
    static GAMEPAD_AXIS_RIGHT_Y            = 3;
    static GAMEPAD_AXIS_LEFT_TRIGGER       = 4;
    static GAMEPAD_AXIS_RIGHT_TRIGGER      = 5;
    static GAMEPAD_AXIS_LAST               = this.GAMEPAD_AXIS_RIGHT_TRIGGER;
    static NO_ERROR                        = 0;
    static NOT_INITIALIZED                 = 0x00010001;
    static NO_CURRENT_CONTEXT              = 0x00010002;
    static INVALID_ENUM                    = 0x00010003;
    static INVALID_VALUE                   = 0x00010004;
    static OUT_OF_MEMORY                   = 0x00010005;
    static API_UNAVAILABLE                 = 0x00010006;
    static VERSION_UNAVAILABLE             = 0x00010007;
    static PLATFORM_ERROR                  = 0x00010008;
    static FORMAT_UNAVAILABLE              = 0x00010009;
    static NO_WINDOW_CONTEXT               = 0x0001000A;
    static CURSOR_UNAVAILABLE              = 0x0001000B;
    static FEATURE_UNAVAILABLE             = 0x0001000C;
    static FEATURE_UNIMPLEMENTED           = 0x0001000D;
    static PLATFORM_UNAVAILABLE            = 0x0001000E;
    static FOCUSED                         = 0x00020001;
    static ICONIFIED                       = 0x00020002;
    static RESIZABLE                       = 0x00020003;
    static VISIBLE                         = 0x00020004;
    static DECORATED                       = 0x00020005;
    static AUTO_ICONIFY                    = 0x00020006;
    static FLOATING                        = 0x00020007;
    static MAXIMIZED                       = 0x00020008;
    static CENTER_CURSOR                   = 0x00020009;
    static TRANSPARENT_FRAMEBUFFER         = 0x0002000A;
    static HOVERED                         = 0x0002000B;
    static FOCUS_ON_SHOW                   = 0x0002000C;
    static MOUSE_PASSTHROUGH               = 0x0002000D;
    static POSITION_X                      = 0x0002000E;
    static POSITION_Y                      = 0x0002000F;
    static RED_BITS                        = 0x00021001;
    static GREEN_BITS                      = 0x00021002;
    static BLUE_BITS                       = 0x00021003;
    static ALPHA_BITS                      = 0x00021004;
    static DEPTH_BITS                      = 0x00021005;
    static STENCIL_BITS                    = 0x00021006;
    static ACCUM_RED_BITS                  = 0x00021007;
    static ACCUM_GREEN_BITS                = 0x00021008;
    static ACCUM_BLUE_BITS                 = 0x00021009;
    static ACCUM_ALPHA_BITS                = 0x0002100A;
    static AUX_BUFFERS                     = 0x0002100B;
    static STEREO                          = 0x0002100C;
    static SAMPLES                         = 0x0002100D;
    static SRGB_CAPABLE                    = 0x0002100E;
    static REFRESH_RATE                    = 0x0002100F;
    static DOUBLEBUFFER                    = 0x00021010;
    static CLIENT_API                      = 0x00022001;
    static CONTEXT_VERSION_MAJOR           = 0x00022002;
    static CONTEXT_VERSION_MINOR           = 0x00022003;
    static CONTEXT_REVISION                = 0x00022004;
    static CONTEXT_ROBUSTNESS              = 0x00022005;
    static OPENGL_FORWARD_COMPAT           = 0x00022006;
    static CONTEXT_DEBUG                   = 0x00022007;
    static OPENGL_DEBUG_CONTEXT            = this.CONTEXT_DEBUG;
    static OPENGL_PROFILE                  = 0x00022008;
    static CONTEXT_RELEASE_BEHAVIOR        = 0x00022009;
    static CONTEXT_NO_ERROR                = 0x0002200A;
    static CONTEXT_CREATION_API            = 0x0002200B;
    static SCALE_TO_MONITOR                = 0x0002200C;
    static COCOA_RETINA_FRAMEBUFFER        = 0x00023001;
    static COCOA_FRAME_NAME                = 0x00023002;
    static COCOA_GRAPHICS_SWITCHING        = 0x00023003;
    static X11_CLASS_NAME                  = 0x00024001;
    static X11_INSTANCE_NAME               = 0x00024002;
    static WIN32_KEYBOARD_MENU             = 0x00025001;
    static WAYLAND_APP_ID                  = 0x00026001;
    static NO_API                          = 0;
    static OPENGL_API                      = 0x00030001;
    static OPENGL_ES_API                   = 0x00030002;
    static NO_ROBUSTNESS                   = 0;
    static NO_RESET_NOTIFICATION           = 0x00031001;
    static LOSE_CONTEXT_ON_RESET           = 0x00031002;
    static OPENGL_ANY_PROFILE              = 0;
    static OPENGL_CORE_PROFILE             = 0x00032001;
    static OPENGL_COMPAT_PROFILE           = 0x00032002;
    static CURSOR                          = 0x00033001;
    static STICKY_KEYS                     = 0x00033002;
    static STICKY_MOUSE_BUTTONS            = 0x00033003;
    static LOCK_KEY_MODS                   = 0x00033004;
    static RAW_MOUSE_MOTION                = 0x00033005;
    static CURSOR_NORMAL                   = 0x00034001;
    static CURSOR_HIDDEN                   = 0x00034002;
    static CURSOR_DISABLED                 = 0x00034003;
    static CURSOR_CAPTURED                 = 0x00034004;
    static ANY_RELEASE_BEHAVIOR            = 0;
    static RELEASE_BEHAVIOR_FLUSH          = 0x00035001;
    static RELEASE_BEHAVIOR_NONE           = 0x00035002;
    static NATIVE_CONTEXT_API              = 0x00036001;
    static EGL_CONTEXT_API                 = 0x00036002;
    static OSMESA_CONTEXT_API              = 0x00036003;
    static ANGLE_PLATFORM_TYPE_NONE        = 0x00037001;
    static ANGLE_PLATFORM_TYPE_OPENGL      = 0x00037002;
    static ANGLE_PLATFORM_TYPE_OPENGLES    = 0x00037003;
    static ANGLE_PLATFORM_TYPE_D3D9        = 0x00037004;
    static ANGLE_PLATFORM_TYPE_D3D11       = 0x00037005;
    static ANGLE_PLATFORM_TYPE_VULKAN      = 0x00037007;
    static ANGLE_PLATFORM_TYPE_METAL       = 0x00037008;
    static WAYLAND_PREFER_LIBDECOR         = 0x00038001;
    static WAYLAND_DISABLE_LIBDECOR        = 0x00038002;
    static ANY_POSITION                    = 0x80000000;
    static ARROW_CURSOR                    = 0x00036001;
    static IBEAM_CURSOR                    = 0x00036002;
    static CROSSHAIR_CURSOR                = 0x00036003;
    static POINTING_HAND_CURSOR            = 0x00036004;
    static RESIZE_EW_CURSOR                = 0x00036005;
    static RESIZE_NS_CURSOR                = 0x00036006;
    static RESIZE_NWSE_CURSOR              = 0x00036007;
    static RESIZE_NESW_CURSOR              = 0x00036008;
    static RESIZE_ALL_CURSOR               = 0x00036009;
    static NOT_ALLOWED_CURSOR              = 0x0003600A;
    static HRESIZE_CURSOR                  = this.RESIZE_EW_CURSOR;
    static VRESIZE_CURSOR                  = this.RESIZE_NS_CURSOR;
    static HAND_CURSOR                     = this.POINTING_HAND_CURSOR;
    static CONNECTED                       = 0x00040001;
    static DISCONNECTED                    = 0x00040002;
    static JOYSTICK_HAT_BUTTONS            = 0x00050001;
    static ANGLE_PLATFORM_TYPE             = 0x00050002;
    static PLATFORM                        = 0x00050003;
    static COCOA_CHDIR_RESOURCES           = 0x00051001;
    static COCOA_MENUBAR                   = 0x00051002;
    static X11_XCB_VULKAN_SURFACE          = 0x00052001;
    static WAYLAND_LIBDECOR                = 0x00053001;
    static ANY_PLATFORM                    = 0x00060000;
    static PLATFORM_WIN32                  = 0x00060001;
    static PLATFORM_COCOA                  = 0x00060002;
    static PLATFORM_WAYLAND                = 0x00060003;
    static PLATFORM_X11                    = 0x00060004;
    static PLATFORM_NULL                   = 0x00060005;
    static DONT_CARE                       = -1;

    constructor() {
    }

//
// コンテキスト
//

    /**
     * @param {number} window (uintptr)
     */

    makeContextCurrent(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_make_context_current",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {number} window (uintptr)
     */

    getCurrentContext() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_current_context",
            "pointer",
            null
        );
    }

    /**
     * @param {number} interval (sint)
     */
    
    swapInterval(interval) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_swap_interval",
            "void",
            [
                ["sint", "interval", interval]
            ]
        );
    }

    /**
     * @param {string} extension
     * @return {number} (sint)
     */

    extensionSupported(extension) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_extension_supported",
            "sint",
            [
                ["string", "extension", extension]
            ]
        );
    }

    /**
     * @param {string} procname
     * @return {number} (uintptr)
     */

    getProcAddress(procname) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_proc_address",
            "pointer",
            [
                ["string", "procname", procname]
            ]
        );
    }

//
// 初期化・バージョン・エラー
//  

    /**
     * @returns {boolean} (sint)
     */

    init() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_init",
            "sint",
            null
        );
    }

    terminate() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_terminate",
            "void",
            null
        );
    }
    initHint(hint, value) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_init_hint",
            "void",
            [
                ["sint", "hint", hint],
                ["sint", "value", value]
            ]
        );
    }
    getVersion(major, minor, rev) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_version",
            "void",
            [
                ["pointer", "major", major],
                ["pointer", "minor", minor],
                ["pointer", "rev", rev]
            ]
        );
    }
    getVersionString() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_version_string",
            "string",
            null
        );
    }
    getError(description) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_error",
            "sint",
            [
                ["pointer", "description", description]
            ]
        );
    }
    setErrorCallback(callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_error_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }

    /**
     * @returns {{error: number, message: string}} {int, string}
     */

    getErrorAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_error_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setErrorCallbackAlt() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_error_callback_alt",
            "void",
            null
        );
    }
    // 入力
    getInputMode(window, mode) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_input_mode",
            "sint",
            [
                ["pointer", "window", window],
                ["sint", "mode", mode]
            ]
        );
    }
    setInputMode(window, mode, value) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_input_mode",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "mode", mode],
                ["sint", "value", value]
            ]
        );
    }
    rawMouseMotionSupported() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_raw_mouse_motion_supported",
            "sint",
            null
        );
    }
    getKeyName(key, scancode) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_key_name",
            "string",
            [
                ["sint", "key", key],
                ["sint", "scancode", scancode]
            ]
        );
    }
    getKeyScancode(key) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_key_scancode",
            "sint",
            [
                ["sint", "key", key]
            ]
        );
    }
    getKey(window, key) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_key",
            "sint",
            [
                ["pointer", "window", window],
                ["sint", "key", key]
            ]
        );
    }
    getMouseButton(window, button) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_mouse_button",
            "sint",
            [
                ["pointer", "window", window],
                ["sint", "button", button]
            ]
        );
    }
    getCursorPos(window, xpos, ypos) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_cursor_pos",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "xpos", xpos],
                ["pointer", "ypos", ypos]
            ]
        );
    }
    setCursorPos(window, xpos, ypos) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor_pos",
            "void",
            [
                ["pointer", "window", window],
                ["double", "xpos", xpos],
                ["double", "ypos", ypos]
            ]
        );
    }
    createCursor(image, xhot, yhot) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_create_cursor",
            "pointer",
            [
                ["pointer", "image", image],
                ["sint", "xhot", xhot],
                ["sint", "yhot", yhot]
            ]
        );
    }
    createStandardCursor(shape) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_create_standard_cursor",
            "pointer",
            [
                ["sint", "shape", shape]
            ]
        );
    }
    destroyCursor(cursor) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_destroy_cursor",
            "void",
            [
                ["pointer", "cursor", cursor]
            ]
        );
    }
    setCursor(window, cursor) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "cursor", cursor]
            ]
        );
    }
    setKeyCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_key_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setCharCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_char_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setCharModsCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_char_mods_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setMouseButtonCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_mouse_button_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setCursorPosCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor_pos_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setCursorEnterCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor_enter_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setScrollCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_scroll_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setDropCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_drop_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    
    /**
     * @param {number} jid (int)
     * @returns {number} (int)
     */

    joystickPresent(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_joystick_present",
            "sint",
            [
                ["sint", "jid", jid]
            ]
        );
    }

    /**
     * @param {number} jid (int)
     * @param {number} count (uintptr)
     * @returns {number} (pointer)
     */

    getJoystickAxes(jid, count) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_axes",
            "pointer",
            [
                ["sint", "jid", jid],
                ["pointer", "count", count]
            ]
        );
    }

    /**
     * @param {number} jid (int)
     * @param {number} count (pointer)
     * @returns {number} (pointer)
     */

    getJoystickButtons(jid, count) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_buttons",
            "pointer",
            [
                ["sint", "jid", jid],
                ["pointer", "count", count]
            ]
        );
    }

    /**
     * @param {number} jid (int)
     * @returns {string} (string)
     */

    getJoystickName(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_name",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    getJoystickGUID(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_guid",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    setJoystickUserPointer(jid, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_joystick_user_pointer",
            "void",
            [
                ["sint", "jid", jid],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    getJoystickUserPointer(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_user_pointer",
            "pointer",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    joystickIsGamepad(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_joystick_is_gamepad",
            "sint",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    setJoystickCallback(callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_joystick_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }
    updateGamepadMappings(string) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_update_gamepad_mappings",
            "sint",
            [
                ["string", "string", string]
            ]
        );
    }
    getGamepadName(jid) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_gamepad_name",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    getGamepadState(jid, state) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_gamepad_state",
            "sint",
            [
                ["sint", "jid", jid],
                ["pointer", "state", state]
            ]
        );
    }
    setClipboardString(window, string) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_clipboard_string",
            "void",
            [
                ["pointer", "window", window],
                ["string", "string", string]
            ]
        );
    }
    getClipboardString(window) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_clipboard_string",
            "string",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {number} (real)
     */
    
    getTime() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_time",
            "double",
            null
        );
    }

    /**
     * @param {number} time (real)
     */

    setTime(time) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_time",
            "void",
            [
                ["double", "time", time]
            ]
        );
    }

    /**
     * @returns {number} (uint)
     */
    
    getTimerValue() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_timer_value",
            "uint64",
            null
        );
    }
    
    /**
     * @returns {number} (uint)
     */

    getTimerFrequency() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_timer_frequency",
            "uint64",
            null
        );
    }

    // 代替関数
    
    /**
     * @returns {{window: uintptr, key: int, scancode: int, action: int, mods: int}}
     */

    getKeyCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_key_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setKeyCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_key_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, codepoint: uint}}
     */

    getCharCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_char_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setCharCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_char_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, codepoint: uint, mods: int}}
     */

    getCharModsCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_char_mods_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setCharModsCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_char_mods_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, button: int, action: int, mods: int}}
     */
    
    getMouseButtonCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_mouse_button_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */
    
    setMouseButtonCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_mouse_button_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, xpos: real, ypos: real}}
     */

    getCursorPosCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_cursor_pos_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */
    
    setCursorPosCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor_pos_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, enterd: int}}
     */
    
    getCursorEnterCallback() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_cursor_enter_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */
    
    setCorsorEnterCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_cursor_enter_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, xoffset: real, yoffset: real}}
     */
    
    getScrollCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_scroll_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */
    
    setScrollCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_scroll_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, count: int, paths:string[]}}
     */
    
    getDropCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_drop_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window uintptr
     */

    setDropCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_drop_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{jid: int, event: int}}
     */
    
    getJoystickCallbackAlt() {
        const rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_joystick_callback_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    setJoystickCallbackAlt() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_joystick_callback_alt",
            "void",
            null
        );
    }

//
// モニター
//

    getMonitors(count) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitors",
            "pointer",
            [
                ["pointer", "count", count]
            ]
        );
    }
    getPrimaryMonitor() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_primary_monitor",
            "pointer",
            null
        );
    }
    getMonitorPos(monitor, xpos, ypos) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_pos",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "xpos", xpos],
                ["pointer", "ypos", ypos]
            ]
        );
    }
    getMonitorWorkarea(monitor,xpos, ypos, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_workarea",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "xpos", xpos],
                ["pointer", "ypos", ypos],
                ["pointer", "width", width],
                ["pointer", "height", height]
            ]
        );
    }
    getMonitorPhysicalSize(monitor, widthMM, heightMM) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_physical_size",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "widthMM", widthMM],
                ["pointer", "heightMM", heightMM]
            ]
        );
    }
    getMonitorContentScale(monitor, xscale, yscale) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_content_scale",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "xscale", xscale],
                ["pointer", "yscale", yscale]
            ]
        );
    }
    getMonitorName(monitor) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_name",
            "string",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setMonitorUserPointer(monitor, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_monitor_user_pointer",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    getMonitorUserPointer(monitor) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_user_pointer",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setMonitorCallback(callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_monitor_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }
    getVideoModes(monitor, count) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_video_modes",
            "pointer",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "count", count]
            ]
        );
    }
    getVideoMode(monitor) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_video_mode",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setGamma(monitor, gamma) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_gamma",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["float", "gamma", gamma]
            ]
        );
    }
    getGammaRamp(monitor) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_gamma_ramp",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setGammaRamp(monitor, ramp) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_gamma_ramp",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "ramp", ramp]
            ]
        );
    }

    // (代替関数)

    getMonitorAlt() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_monitor_alt",
            "string",
            null
        );
    }
    setMonitorCallbackAlt() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_monitor_callback_alt",
            "void",
            null
        )
    }


//
// ネイティブアクセス
//

    // 未対応
    // getWin32Adapter
    // getWin32Monitor
    // getWin32Window
    // getWGLContext
    // getCocoaMonitor
    // getCocoaWindow
    // getNSGLContext
    // getX11Display
    // getX11Adapter
    // getX11Monitor
    // getX11Window
    // getX11SelectionString
    // getX11SelectionString
    // getGLXContext
    // getGLXWindow
    // getWaylandDisplay
    // getWaylandMonitor
    // getWaylandWindow
    // getEGLDisplay
    // getEGLContext
    // getEGLSurface
    // getOSMesaColorBuffer
    // getOSMesaDepthBuffer
    // getOSMesaContext

//
// Vulkanサポート
//

    vulkanSupported() {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_vulkan_supported",
            "sint",
            null
        )
    }
    getRequiredInstanceExtensions(count) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_required_instance_extensions",
            "pointer",
            [
                ["pointer", "count", count]
            ]
        );
    }

    // 未対応
    // getInstanceProcAddress
    // getPhysicalDevicePresentationSupport
    // createWindowSurface

//
// ウィンドウ
//

    defaultWindowHints() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_default_window_hints",
            "void",
            null
        );
    }

    /**
     * @param {number} hint (int)
     * @param {number} value (int)
     */
    
    windowHint(hint, value) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_window_hint",
            "void",
            [
                ["sint", "hint", hint],
                ["sint", "value", value]
            ]
        );
    }
    
    /**
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} title (string)
     * @returns {number} (uintptr) Window ID
     */

    createWindow(width, height, title, monitor = null, share = null) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_create_window",
            "pointer",
            [
                ["sint", "width", width],
                ["sint", "height", height],
                ["string", "title", title],
                ["pointer", "monitor", null],
                ["pointer", "share", null]
            ]
        );
    }

    /**
     * @param {number} window (uintptr)
     */

    destroyWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_destroy_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @param {number} window (uintptr)
     * @returns {number} (int)
     */

    windowShouldClose(window) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_window_should_close",
            "sint",
            [
                ["pointer", "window", window]
            ]
        );
    }

    setWindowShouldClose(window, value) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_should_close",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "value", value]
            ]
        );
    }

    /**
     * @param {number} window (uintptr)
     * @param {string} title (string) 
     */

    setWindowTitle(window, title) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_title",
            "void",
            [
                ["pointer", "window", window],
                ["string", "title", title]
            ]
        );
    }

    setWindowIcon(window, count, images) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_icon",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "count", count],
                ["pointer", "images", images]
            ]
        );
    }
    getWindowPos(window, xpos, ypos) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_pos",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "xpos", xpos],
                ["pointer", "ypos", ypos]
            ]
        );
    }
    setWindowPos(window, xpos, ypos) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_pos",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "xpos", xpos],
                ["sint", "ypos", ypos]
            ]
        );
    }

    /**
     * @param {number} window (uintptr)
     */
    
    getWindowSize(window, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_size",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "width", width],
                ["pointer", "height", height]
            ]
        );
    }
    setWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_size_limits",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "minwidth", minwidth],
                ["sint", "minheight", minheight],
                ["sint", "maxwidth", maxwidth],
                ["sint", "maxheight", maxheight]
            ]
        );
    }
    setWindowAspectRatio(window, numer, denom) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_aspect_ratio",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "numer", numer],
                ["sint", "denom", denom]
            ]
        );
    }
    setWindowSize(window, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_size",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    /**
     * @param {number} window (uintptr)
     */
    getFramebufferSize(window, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_framebuffer_size",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "width", width],
                ["pointer", "height", height]
            ]
        );
    }
    getWindowFrameSize(window, left, top, right, bottom) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_frame_size",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "left", left],
                ["pointer", "top", top],
                ["pointer", "right", right],
                ["pointer", "bottom", bottom]
            ]
        );
    }
    getWindowContentScale(window, xscale, yscale) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_content_scale",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "xscale", xscale],
                ["pointer", "yscale", yscale]
            ]
        );
    }
    getWindowOpacity(window) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_opacity",
            "float",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowOpacity(window, opacity) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_opacity",
            "void",
            [
                ["pointer", "window", window],
                ["float", "opacity", opacity]
            ]
        );
    }
    iconifyWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_iconify_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    restoreWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_restore_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    maximizeWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_maximize_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    showWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_show_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    hideWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_hide_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    focusWindow(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_focus_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    requestWindowAttention(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_request_window_attention",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    getWindowMonitor(window) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_monitor",
            "pointer",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_monitor",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "monitor", monitor],
                ["sint", "xpos", xpos],
                ["sint", "ypos", ypos],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "refreshRate", refreshRate]
            ]
        );
    }
    getWindowAttrib(window, attrib) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_attrib",
            "sint",
            [
                ["pointer", "window", window],
                ["sint", "attrib", attrib]
            ]
        );
    }
    setWindowAttrib(window, attrib, value) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_attrib",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "attrib", attrib],
                ["sint", "value", value]
            ]
        );
    }
    setWindowUserPointer(window, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_user_pointer",
            "void",
            [
                ["pointer", "window", window],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    getWindowUserPointer(window) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_user_pointer",
            "pointer",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowPosCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_pos_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowSizeCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_size_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowCloseCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_close_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowRefreshCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_refresh_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowFocusCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_focus_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowIconifyCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_iconify_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowMaximizeCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_maximize_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setFramebufferSizeCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_framebuffer_size_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    setWindowContentScaleCallback(window, callback) {
        return lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_content_scale_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    pollEvents() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_poll_events",
            "void",
            null
        );
    }
    glfwWaitEvents() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_wait_events",
            "void",
            null
        );
    }

    /**
     * @param {number} timeout (real)
     */
    
    waitEventTimeout(timeout) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_wait_event_timeout",
            "void",
            [
                ["double", "timeout", timeout]
            ]
        );
    }

    postEmptyEvent() {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_post_empty_event",
            "void",
            null
        );
    }

    /**
     * @param {number} window (uintptr)
     */

    swapBuffers(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_swap_buffers", 
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    // 代替

    /**
     * @returns {{window: uintptr, x: int, y: int}}
     */

    getWindowPosAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_pos_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */
    
    setWindowPosCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_pos_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */
    
    getWindowSizeAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_size_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setWindowSizeCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_size_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr}}
     */

    getWindowCloseAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_close_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setWindowCloseCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_close_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr}}
     */

    getWindowRefreshAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_refresh_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setWindowRefreshCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_refresh_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, focused: int}}
     */

    getWindowFocusAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_focus_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setWindowFocusCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_focus_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, iconified: int}}
     */

    getWindowIconifyAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_iconify_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setWindowIconifyCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_iconify_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    getWindowMaximizeAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_maximize_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    setWindowMaximizeCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_maximize_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }

    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */

    getFramebufferSizeAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_framebuffer_size_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }

    /**
     * @param {number} window (uintptr)
     */

    setFramebufferSizeCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_framebuffer_size_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    getWindowContentScaleAlt() {
        var rets = lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_get_window_content_scale_alt",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setWindowContentScaleCallbackAlt(window) {
        lib.ffi(
            globalThis.__RAIA_GLFW__.handle,
            "raia_glfw_set_window_content_scale_callback_alt",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
}