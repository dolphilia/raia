//

// sample code
/*
var glfw = new GLFW();
glfw.init();
glfw.windowHint(GLFW.CLIENT_API, GLFW.OPENGL_ES_API);
glfw.windowHint(GLFW.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(GLFW.CONTEXT_VERSION_MINOR, 0);
glfw.windowHint(GLFW.OPENGL_PROFILE, GLFW.OPENGL_CORE_PROFILE);
glfw.windowHint(GLFW.CONTEXT_CREATION_API, GLFW.EGL_CONTEXT_API);
glfw.setErrorCallbackDefault();
glfw.setJoystickCallbackDefault();
var window = glfw.createWindow(800, 600, "title");
if(window === null) {
    print("Window creation failed.");
    glfw.terminate();
    exit(1);
}
glfw.makeContextCurrent(window);
glfw.swapInterval(1);
var res_size = glfw.getFrameBufferSize(window);
var res_width = res_size.width;
var res_height = res_size.height;

glfw.setKeyCallbackDefault(window);
glfw.setFramebufferSizeCallbackDefault(window);
glfw.setWindowPosCallbackDefault(window);
glfw.setWindowSizeCallbackDefault(window);
glfw.setWindowCloseCallbackDefault(window);
glfw.setWindowRefreshCallbackDefault(window);
glfw.setWindowFocusCallbackDefault(window);
glfw.setWindowIconifyCallbackDefault(window);
glfw.setCursorPosCallbackDefault(window);
glfw.setMouseButtonCallbackDefault(window);
glfw.setCharCallbackDefault(window);
glfw.setCharModsCallbackDefault(window);
glfw.setCorsorEnterCallbackDefault(window);
glfw.setScrollCallbackDefault(window);
glfw.setDropCallbackDefault(window);

glfw.setWindowTitle(window, "f");

while(glfw.windowShouldClose(window) === 0) {
    print("getTimerValue: " + glfw.getTimerValue());
    print("getTimerFrequency: " + glfw.getTimerFrequency());
    print("getTime: " + glfw.getTime());
    print("joystickPresent: " + glfw.joystickPresent(0));
    glfw.setWindowTitle(window, "" + glfw.getCursorPosCallback().xpos + ":" + glfw.getCursorPosCallback().ypos);
    glfw.swapBuffers(window);
    glfw.pollEvents();
}
*/
import {Lib} from "raia_lib";
const lib = new Lib();

(function(){
    if (globalThis.__RAIA_GLFW__ === undefined) {
        const handle = lib.open("raia_glfw");
        // コンテキスト
        lib.add(handle, "raia_glfw_make_context_current");
        lib.add(handle, "raia_glfw_get_current_context");
        lib.add(handle, "raia_glfw_swap_interval");
        lib.add(handle, "raia_glfw_extension_supported");
        lib.add(handle, "raia_glfw_get_proc_address");
        // 初期化・バージョン・エラー
        lib.add(handle, "raia_glfw_init");
        lib.add(handle, "raia_glfw_terminate");
        lib.add(handle, "raia_glfw_init_hint");
        lib.add(handle, "raia_glfw_get_version");
        lib.add(handle, "raia_glfw_get_version_string");
        lib.add(handle, "raia_glfw_get_error");
        lib.add(handle, "raia_glfw_set_error_callback");
        lib.add(handle, "raia_glfw_get_error_default"); // 代替
        lib.add(handle, "raia_glfw_set_error_callback_default"); // 代替
        // 入力
        lib.add(handle, "raia_glfw_get_input_mode");
        lib.add(handle, "raia_glfw_set_input_mode");
        lib.add(handle, "raia_glfw_raw_mouse_motion_supported");
        lib.add(handle, "raia_glfw_get_key_name");
        lib.add(handle, "raia_glfw_get_key_scancode");
        lib.add(handle, "raia_glfw_get_key");
        lib.add(handle, "raia_glfw_get_mouse_button");
        lib.add(handle, "raia_glfw_get_cursor_pos");
        lib.add(handle, "raia_glfw_set_cursor_pos");
        lib.add(handle, "raia_glfw_create_cursor");
        lib.add(handle, "raia_glfw_create_standard_cursor");
        lib.add(handle, "raia_glfw_destroy_cursor");
        lib.add(handle, "raia_glfw_set_cursor");
        lib.add(handle, "raia_glfw_set_key_callback");
        lib.add(handle, "raia_glfw_set_char_callback");
        lib.add(handle, "raia_glfw_set_char_mods_callback");
        lib.add(handle, "raia_glfw_set_mouse_button_callback");
        lib.add(handle, "raia_glfw_set_cursor_pos_callback");
        lib.add(handle, "raia_glfw_set_cursor_enter_callback");
        lib.add(handle, "raia_glfw_set_scroll_callback");
        lib.add(handle, "raia_glfw_set_drop_callback");
        lib.add(handle, "raia_glfw_joystick_present");
        lib.add(handle, "raia_glfw_get_joystick_axes");
        lib.add(handle, "raia_glfw_get_joystick_buttons");
        lib.add(handle, "raia_glfw_get_joystick_hats");
        lib.add(handle, "raia_glfw_get_joystick_name");
        lib.add(handle, "raia_glfw_get_joystick_guid");
        lib.add(handle, "raia_glfw_set_joystick_user_pointer");
        lib.add(handle, "raia_glfw_get_joystick_user_pointer");
        lib.add(handle, "raia_glfw_joystick_is_gamepad");
        lib.add(handle, "raia_glfw_set_joystick_callback");
        lib.add(handle, "raia_glfw_update_gamepad_mappings");
        lib.add(handle, "raia_glfw_get_gamepad_name");
        lib.add(handle, "raia_glfw_get_gamepad_state");
        lib.add(handle, "raia_glfw_set_clipboard_string");
        lib.add(handle, "raia_glfw_get_clipboard_string");
        lib.add(handle, "raia_glfw_get_time");
        lib.add(handle, "raia_glfw_set_time");
        lib.add(handle, "raia_glfw_get_timer_value");
        lib.add(handle, "raia_glfw_get_timer_frequency");
        lib.add(handle, "raia_glfw_get_key_default"); // 代替
        lib.add(handle, "raia_glfw_set_key_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_char_default"); // 代替
        lib.add(handle, "raia_glfw_set_char_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_char_mods_default"); // 代替
        lib.add(handle, "raia_glfw_set_char_mods_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_mouse_button_default"); // 代替
        lib.add(handle, "raia_glfw_set_mouse_button_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_cursor_pos_default"); // 代替
        lib.add(handle, "raia_glfw_set_cursor_pos_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_cursor_enter_default"); // 代替
        lib.add(handle, "raia_glfw_set_cursor_enter_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_scroll_default"); // 代替
        lib.add(handle, "raia_glfw_set_scroll_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_drop_default"); // 代替
        lib.add(handle, "raia_glfw_set_drop_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_joystick_default"); // 代替
        lib.add(handle, "raia_glfw_set_joystick_callback_default"); // 代替
        // モニター
        lib.add(handle, "raia_glfw_get_monitors");
        lib.add(handle, "raia_glfw_get_primary_monitor");
        lib.add(handle, "raia_glfw_get_monitor_pos");
        lib.add(handle, "raia_glfw_get_monitor_workarea");
        lib.add(handle, "raia_glfw_get_monitor_physical_size");
        lib.add(handle, "raia_glfw_get_monitor_content_scale");
        lib.add(handle, "raia_glfw_get_monitor_name");
        lib.add(handle, "raia_glfw_set_monitor_user_pointer");
        lib.add(handle, "raia_glfw_get_monitor_user_pointer");
        lib.add(handle, "raia_glfw_set_monitor_callback");
        lib.add(handle, "raia_glfw_get_video_modes");
        lib.add(handle, "raia_glfw_get_video_mode");
        lib.add(handle, "raia_glfw_set_gamma");
        lib.add(handle, "raia_glfw_get_gamma_ramp");
        lib.add(handle, "raia_glfw_set_gamma_ramp");
        lib.add(handle, "raia_glfw_get_monitor_default"); // 代替
        lib.add(handle, "raia_glfw_set_monitor_callback_default"); // 代替
        // ネイティブアクセス
        // Vulkanサポート
        lib.add(handle, "raia_glfw_vulkan_supported");
        lib.add(handle, "raia_glfw_get_required_instance_extensions");
        // ウィンドウ
        lib.add(handle, "raia_glfw_default_window_hints");
        lib.add(handle, "raia_glfw_window_hint");
        lib.add(handle, "raia_glfw_window_hint_string");
        lib.add(handle, "raia_glfw_create_window");
        lib.add(handle, "raia_glfw_destroy_window");
        lib.add(handle, "raia_glfw_window_should_close");
        lib.add(handle, "raia_glfw_set_window_should_close");
        lib.add(handle, "raia_glfw_set_window_title");
        lib.add(handle, "raia_glfw_set_window_icon");
        lib.add(handle, "raia_glfw_get_window_pos");
        lib.add(handle, "raia_glfw_get_window_size");
        lib.add(handle, "raia_glfw_set_window_size_limits");
        lib.add(handle, "raia_glfw_set_window_aspect_ratio");
        lib.add(handle, "raia_glfw_set_window_size");
        lib.add(handle, "raia_glfw_get_framebuffer_size");
        lib.add(handle, "raia_glfw_get_window_frame_size");
        lib.add(handle, "raia_glfw_get_window_content_scale");
        lib.add(handle, "raia_glfw_get_window_opacity");
        lib.add(handle, "raia_glfw_set_window_opacity");
        lib.add(handle, "raia_glfw_iconify_window");
        lib.add(handle, "raia_glfw_restore_window");
        lib.add(handle, "raia_glfw_maximize_window");
        lib.add(handle, "raia_glfw_show_window");
        lib.add(handle, "raia_glfw_hide_window");
        lib.add(handle, "raia_glfw_focus_window");
        lib.add(handle, "raia_glfw_request_window_attention");
        lib.add(handle, "raia_glfw_get_window_monitor");
        lib.add(handle, "raia_glfw_set_window_monitor");
        lib.add(handle, "raia_glfw_get_window_attrib");
        lib.add(handle, "raia_glfw_set_window_attrib");
        lib.add(handle, "raia_glfw_set_window_user_pointer");
        lib.add(handle, "raia_glfw_get_window_user_pointer");
        lib.add(handle, "raia_glfw_set_window_pos_callback");
        lib.add(handle, "raia_glfw_set_window_size_callback");
        lib.add(handle, "raia_glfw_set_window_close_callback");
        lib.add(handle, "raia_glfw_set_window_refresh_callback");
        lib.add(handle, "raia_glfw_set_window_focus_callback");
        lib.add(handle, "raia_glfw_set_window_iconify_callback");
        lib.add(handle, "raia_glfw_set_window_maximize_callback");
        lib.add(handle, "raia_glfw_set_framebuffer_size_callback");
        lib.add(handle, "raia_glfw_set_window_content_scale_callback");        
        lib.add(handle, "raia_glfw_poll_events");
        lib.add(handle, "raia_glfw_wait_events");
        lib.add(handle, "raia_glfw_wait_event_timeout");
        lib.add(handle, "raia_glfw_post_empty_event");
        lib.add(handle, "raia_glfw_swap_buffers");
        lib.add(handle, "raia_glfw_get_window_pos_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_pos_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_size_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_size_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_close_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_close_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_refresh_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_refresh_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_focus_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_focus_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_iconify_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_iconify_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_maximize_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_maximize_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_framebuffer_size_default"); // 代替
        lib.add(handle, "raia_glfw_set_framebuffer_size_callback_default"); // 代替
        lib.add(handle, "raia_glfw_get_window_content_scale_default"); // 代替
        lib.add(handle, "raia_glfw_set_window_content_scale_callback_default"); // 代替
        globalThis.__RAIA_GLFW__ = {};
    }
})();

export class GLFW {
    constructor() {
        this.CLIENT_API = 0x00022001;
        this.CONTEXT_VERSION_MAJOR = 0x00022002;
        this.CONTEXT_VERSION_MINOR = 0x00022003;
        this.OPENGL_PROFILE = 0x00022008;
        this.CONTEXT_CREATION_API = 0x0002200B;
        this.OPENGL_ES_API = 0x00030002;
        this.OPENGL_CORE_PROFILE = 0x00032001;
        this.EGL_CONTEXT_API = 0x00036002;
    }

//
// コンテキスト
//

    /**
     * @param {uintptr} window
     */
    makeContextCurrent(window) {
        lib.ffi(
            "raia_glfw_make_context_current",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {uintptr} window
     */
    getCurrentContext() {
        return lib.ffi(
            "raia_glfw_get_current_context",
            "pointer",
            null
        );
    }
    /**
     * @param {int} interval 
     */
    swapInterval(interval) {
        lib.ffi(
            "raia_glfw_swap_interval",
            "void",
            [
                ["sint", "interval", interval]
            ]
        );
    }
    /**
     * @param {string} extension - 
     * @return {sint}
     */
    extensionSupported(extension) {
        return lib.ffi(
            "raia_glfw_extension_supported",
            "sint",
            [
                ["string", "extension", extension]
            ]
        );
    }
    /**
     * @param {string} procname
     * @return {uintptr}
     */
    getProcAddress(procname) {
        return lib.ffi(
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
     * @returns {boolean}
     */
    init() {
        return lib.ffi(
            "raia_glfw_init",
            "sint",
            null
        );
    }
    /**
     * 
     */
    terminate() {
        lib.ffi(
            "raia_glfw_terminate",
            "void",
            null
        );
    }
    initHint(hint, value) {
        lib.ffi(
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
            "raia_glfw_get_version_string",
            "string",
            null
        );
    }
    getError(description) {
        return lib.ffi(
            "raia_glfw_get_error",
            "sint",
            [
                ["pointer", "description", description]
            ]
        );
    }
    setErrorCallback(callback) {
        return lib.ffi(
            "raia_glfw_set_error_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }
    /**
     * @returns {{error: int, message: string}}
     */
    getErrorDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_error_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setErrorCallbackDefault() {
        lib.ffi(
            "raia_glfw_set_error_callback_default",
            "void",
            null
        );
    }
    // 入力
    getInputMode(window, mode) {
        return lib.ffi(
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
            "raia_glfw_raw_mouse_motion_supported",
            "sint",
            null
        );
    }
    getKeyName(key, scancode) {
        return lib.ffi(
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
            "raia_glfw_get_key_scancode",
            "sint",
            [
                ["sint", "key", key]
            ]
        );
    }
    getKey(window, key) {
        return lib.ffi(
            "raia_glfw_get_key",
            "sint",
            [
                ["pointer", "window", window],
                ["sint", "button", button]
            ]
        );
    }
    getMouseButton(window, button) {
        return lib.ffi(
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
            "raia_glfw_create_standard_cursor",
            "pointer",
            [
                ["sint", "shape", shape]
            ]
        );
    }
    destroyCursor(cursor) {
        lib.ffi(
            "raia_glfw_destroy_cursor",
            "void",
            [
                ["pointer", "cursor", cursor]
            ]
        );
    }
    setCursor(window, cursor) {
        lib.ffi(
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
            "raia_glfw_set_drop_callback",
            "pointer",
            [
                ["pointer", "window", window],
                ["pointer", "callback", callback]
            ]
        );
    }
    /**
     * @param {int} jid
     * @returns {int}
     */
    joystickPresent(jid) {
        return lib.ffi(
            "raia_glfw_joystick_present",
            "sint",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    /**
     * @param {int} jid
     * @param {uintptr} count
     * @returns {pointer}
     */
    getJoystickAxes(jid, count) {
        return lib.call(
            "raia_glfw_get_joystick_axes",
            "pointer",
            [
                ["sint", "jid", jid],
                ["pointer", "count", count]
            ]
        );
    }
    /**
     * @param {int} jid
     * @param {pointer} count
     * @returns {pointer}
     */
    getJoystickButtons(jid, count) {
        return lib.ffi(
            "raia_glfw_get_joystick_buttons",
            "pointer",
            [
                ["sint", "jid", jid],
                ["pointer", "count", count]
            ]
        );
    }
    /**
     * @param {int} jid
     * @returns {string}
     */
    getJoystickName(jid) {
        return lib.ffi(
            "raia_glfw_get_joystick_name",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    getJoystickGUID(jid) {
        return lib.ffi(
            "raia_glfw_get_joystick_guid",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    setJoystickUserPointer(jid, pointer) {
        lib.ffi(
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
            "raia_glfw_get_joystick_user_pointer",
            "pointer",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    joystickIsGamepad(jid) {
        return lib.ffi(
            "raia_glfw_joystick_is_gamepad",
            "sint",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    setJoystickCallback(callback) {
        return lib.ffi(
            "raia_glfw_set_joystick_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }
    updateGamepadMappings(string) {
        return lib.ffi(
            "raia_glfw_update_gamepad_mappings",
            "sint",
            [
                ["string", "string", string]
            ]
        );
    }
    getGamepadName(jid) {
        return lib.ffi(
            "raia_glfw_get_gamepad_name",
            "string",
            [
                ["sint", "jid", jid]
            ]
        );
    }
    getGamepadState(jid, state) {
        return lib.ffi(
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
            "raia_glfw_get_clipboard_string",
            "string",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {real}
     */
    getTime() {
        return lib.ffi(
            "raia_glfw_get_time",
            "double",
            null
        );
    }
    /**
     * @param {real} time 
     */
    setTime(time) {
        lib.ffi(
            "raia_glfw_set_time",
            "void",
            [
                ["double", "time", time]
            ]
        );
    }
    /**
     * @returns {uint}
     */
    getTimerValue() {
        return lib.ffi(
            "raia_glfw_get_timer_value",
            "uint64",
            null
        );
    }
    /**
     * @returns {uint}
     */
    getTimerFrequency() {
        return lib.ffi(
            "raia_glfw_get_timer_frequency",
            "uint64",
            null
        );
    }

    // 代替関数
    
    /**
     * @returns {{window: uintptr, key: int, scancode: int, action: int, mods: int}}
     */
    getKeyCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_key_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setKeyCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_key_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, codepoint: uint}}
     */
    getCharCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_char_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setCharCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_char_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, codepoint: uint, mods: int}}
     */
    getCharModsCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_char_mods_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setCharModsCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_char_mods_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, button: int, action: int, mods: int}}
     */
    getMouseButtonCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_mouse_button_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setMouseButtonCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_mouse_button_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, xpos: real, ypos: real}}
     */
    getCursorPosCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_cursor_pos_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setCursorPosCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_cursor_pos_callback_default",
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
            "raia_glfw_get_cursor_enter_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setCorsorEnterCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_cursor_enter_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, xoffset: real, yoffset: real}}
     */
    getScrollCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_scroll_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setScrollCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_scroll_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, count: int, paths:string[]}}
     */
    getDropCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_drop_callback",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setDropCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_drop_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{jid: int, event: int}}
     */
    getJoystickCallbackDefault() {
        const rets = lib.ffi(
            "raia_glfw_get_joystick_callback_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setJoystickCallbackDefault() {
        lib.ffi(
            "raia_glfw_set_joystick_callback_default",
            "void",
            null
        );
    }

//
// モニター
//

    getMonitors(count) {
        return lib.ffi(
            "raia_glfw_get_monitors",
            "pointer",
            [
                ["pointer", "count", count]
            ]
        );
    }
    getPrimaryMonitor() {
        return lib.ffi(
            "raia_glfw_get_primary_monitor",
            "pointer",
            null
        );
    }
    getMonitorPos(monitor, xpos, ypos) {
        lib.ffi(
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
            "raia_glfw_get_monitor_name",
            "string",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setMonitorUserPointer(monitor, pointer) {
        lib.ffi(
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
            "raia_glfw_get_monitor_user_pointer",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setMonitorCallback(callback) {
        return lib.ffi(
            "raia_glfw_set_monitor_callback",
            "pointer",
            [
                ["pointer", "callback", callback]
            ]
        );
    }
    getVideoModes(monitor, count) {
        return lib.ffi(
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
            "raia_glfw_get_video_mode",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setGamma(monitor, gamma) {
        lib.ffi(
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
            "raia_glfw_get_gamma_ramp",
            "pointer",
            [
                ["pointer", "monitor", monitor]
            ]
        );
    }
    setGammaRamp(monitor, ramp) {
        lib.ffi(
            "raia_glfw_set_gamma_ramp",
            "void",
            [
                ["pointer", "monitor", monitor],
                ["pointer", "ramp", ramp]
            ]
        );
    }

    // (代替関数)

    getMonitorDefault() {
        return lib.ffi(
            "raia_glfw_get_monitor_default",
            "string",
            null
        );
    }
    setMonitorCallbackDefault() {
        lib.ffi(
            "raia_glfw_set_monitor_callback_default",
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
            "raia_glfw_vulkan_supported",
            "sint",
            null
        )
    }
    getRequiredInstanceExtensions(count) {
        return lib.ffi(
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
            "raia_glfw_default_window_hints",
            "void",
            null
        );
    }
    /**
     * @param {int} hint
     * @param {int} value
     */
    windowHint(hint, value) {
        lib.ffi(
            "raia_glfw_window_hint",
            "void",
            [
                ["sint", "hint", hint],
                ["sint", "value", value]
            ]
        );
    }
    /**
     * @param {int} width1
     * @param {int} height
     * @param {string} title
     * @returns {uintptr} window
     */
    createWindow(width, height, title, monitor = null, share = null) {
        return lib.ffi(
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
     * @param {uintptr} window
     */
    destroyWindow(window) {
        lib.ffi(
            "raia_glfw_destroy_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @param {uintptr} window
     * @returns {int}
     */
    windowShouldClose(window) {
        return lib.ffi(
            "raia_glfw_window_should_close",
            "sint",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowShouldClose(window, value) {
        lib.ffi(
            "raia_glfw_set_window_should_close",
            "void",
            [
                ["pointer", "window", window],
                ["sint", "value", value]
            ]
        );
    }
    /**
     * @param {uintptr} window_id 
     * @param {string} title 
     */
    setWindowTitle(window, title) {
        lib.ffi(
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
     * @param {uintptr} window_id 
     * @returns {{width: int, height: int}}
     */
    getWindowSize(window, width, height) {
        lib.ffi(
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
     * @param {uintptr} window
     * @returns {{width: int, height: int}}
     */
    getFramebufferSize(window, width, height) {
        lib.ffi(
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
            "raia_glfw_get_window_opacity",
            "float",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowOpacity(window, opacity) {
        lib.ffi(
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
            "raia_glfw_iconify_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    restoreWindow(window) {
        lib.ffi(
            "raia_glfw_restore_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    maximizeWindow(window) {
        lib.ffi(
            "raia_glfw_maximize_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    showWindow(window) {
        lib.ffi(
            "raia_glfw_show_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    hideWindow(window) {
        lib.ffi(
            "raia_glfw_hide_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    focusWindow(window) {
        lib.ffi(
            "raia_glfw_focus_window",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    requestWindowAttention(window) {
        lib.ffi(
            "raia_glfw_request_window_attention",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    getWindowMonitor(window) {
        return lib.ffi(
            "raia_glfw_get_window_monitor",
            "pointer",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate) {
        lib.ffi(
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
            "raia_glfw_get_window_user_pointer",
            "pointer",
            [
                ["pointer", "window", window]
            ]
        );
    }
    setWindowPosCallback(window, callback) {
        return lib.ffi(
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
            "raia_glfw_poll_events",
            "void",
            null
        );
    }
    glfwWaitEvents() {
        lib.ffi(
            "raia_glfw_wait_events",
            "void",
            null
        );
    }
    /**
     * @param {real} timeout
     */
    waitEventTimeout(timeout) {
        lib.ffi(
            "raia_glfw_wait_event_timeout",
            "void",
            [
                ["double", "timeout", timeout]
            ]
        );
    }
    postEmptyEvent() {
        lib.ffi(
            "raia_glfw_post_empty_event",
            "void",
            null
        );
    }
    /**
     * @param {uintptr} window_id 
     */
    swapBuffers(window) {
        lib.ffi(
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
    getWindowPosDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_pos_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowPosCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_pos_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */
    getWindowSizeDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_size_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowSizeCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_size_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr}}
     */
    getWindowCloseDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_close_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowCloseCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_close_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr}}
     */
    getWindowRefreshDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_refresh_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowRefreshCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_refresh_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, focused: int}}
     */
    getWindowFocusDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_focus_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowFocusCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_focus_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, iconified: int}}
     */
    getWindowIconifyDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_iconify_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window
     */
    setWindowIconifyCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_iconify_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    getWindowMaximizeDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_maximize_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setWindowMaximizeCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_maximize_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */
    getFramebufferSizeDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_framebuffer_size_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    /**
     * @param {uintptr} window_id 
     */
    setFramebufferSizeCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_framebuffer_size_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
    getWindowContentScaleDefault() {
        var rets = lib.ffi(
            "raia_glfw_get_window_content_scale_default",
            "string",
            null
        );
        return JSON.parse(rets);
    }
    setWindowContentScaleCallbackDefault(window) {
        lib.ffi(
            "raia_glfw_set_window_content_scale_callback_default",
            "void",
            [
                ["pointer", "window", window]
            ]
        );
    }
}