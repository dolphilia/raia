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
glfw.setErrorCallback();
glfw.setJoystickCallback();
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

glfw.setKeyCallback(window);
glfw.setFramebufferSizeCallback(window);
glfw.setWindowPosCallback(window);
glfw.setWindowSizeCallback(window);
glfw.setWindowCloseCallback(window);
glfw.setWindowRefreshCallback(window);
glfw.setWindowFocusCallback(window);
glfw.setWindowIconifyCallback(window);
glfw.setCursorPosCallback(window);
glfw.setMouseButtonCallback(window);
glfw.setCharCallback(window);
glfw.setCharModsCallback(window);
glfw.setCorsorEnterCallback(window);
glfw.setScrollCallback(window);
glfw.setDropCallback(window);

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
        lib.add(handle, "raia_glfw_init");
        lib.add(handle, "raia_glfw_terminate");
        lib.add(handle, "raia_glfw_create_window");
        lib.add(handle, "raia_glfw_destroy_window");
        lib.add(handle, "raia_glfw_window_hint");
        lib.add(handle, "raia_glfw_make_context_current");
        lib.add(handle, "raia_glfw_get_current_context");
        lib.add(handle, "raia_glfw_swap_interval");
        lib.add(handle, "raia_glfw_get_window_size");
        lib.add(handle, "raia_glfw_get_framebuffer_size");
        //
        lib.add(handle, "raia_glfw_set_error_callback");
        lib.add(handle, "raia_glfw_set_joystick_callback");
        lib.add(handle, "raia_glfw_set_key_callback");
        lib.add(handle, "raia_glfw_set_framebuffer_size_callback");
        lib.add(handle, "raia_glfw_set_window_pos_callback");
        lib.add(handle, "raia_glfw_set_window_size_callback");
        lib.add(handle, "raia_glfw_set_window_close_callback");
        lib.add(handle, "raia_glfw_set_window_refresh_callback");
        lib.add(handle, "raia_glfw_set_window_focus_callback");
        lib.add(handle, "raia_glfw_set_window_iconify_callback");
        lib.add(handle, "raia_glfw_set_cursor_pos_callback");
        lib.add(handle, "raia_glfw_set_mouse_button_callback");
        lib.add(handle, "raia_glfw_set_char_callback");
        lib.add(handle, "raia_glfw_set_char_mods_callback");
        lib.add(handle, "raia_glfw_set_cursor_enter_callback");
        lib.add(handle, "raia_glfw_set_scroll_callback");
        lib.add(handle, "raia_glfw_set_drop_callback");
        //
        lib.add(handle, "raia_glfw_get_error_callback");
        lib.add(handle, "raia_glfw_get_framebuffer_size_callback");
        lib.add(handle, "raia_glfw_get_key_callback");
        lib.add(handle, "raia_glfw_get_joystick_callback");
        lib.add(handle, "raia_glfw_get_window_pos_callback");
        lib.add(handle, "raia_glfw_get_window_size_callback");
        lib.add(handle, "raia_glfw_get_window_close_callback");
        lib.add(handle, "raia_glfw_get_window_refresh_callback");
        lib.add(handle, "raia_glfw_get_window_focus_callback");
        lib.add(handle, "raia_glfw_get_window_iconify_callback");
        lib.add(handle, "raia_glfw_get_cursor_pos_callback");
        lib.add(handle, "raia_glfw_get_mouse_button_callback");
        lib.add(handle, "raia_glfw_get_char_callback");
        lib.add(handle, "raia_glfw_get_char_mods_callback");
        lib.add(handle, "raia_glfw_get_cursor_enter_callback");
        lib.add(handle, "raia_glfw_get_scroll_callback");
        lib.add(handle, "raia_glfw_get_drop_callback");
        //
        lib.add(handle, "raia_glfw_get_timer_value");
        lib.add(handle, "raia_glfw_get_timer_frequency");
        lib.add(handle, "raia_glfw_get_time");
        lib.add(handle, "raia_glfw_set_time");
        lib.add(handle, "raia_glfw_wait_event_timeout");
        //
        lib.add(handle, "raia_glfw_joystick_present");
        lib.add(handle, "raia_glfw_get_joystick_axes");
        lib.add(handle, "raia_glfw_get_joystick_buttons");
        lib.add(handle, "raia_glfw_get_joystick_name");
        //
        lib.add(handle, "raia_glfw_swap_buffers");
        lib.add(handle, "raia_glfw_poll_events");
        lib.add(handle, "raia_glfw_window_should_close");
        lib.add(handle, "raia_glfw_set_window_title");
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
    /**
     * @returns {boolean}
     */
    init() {
        var ret = lib.call("raia_glfw_init");
        return JSON.parse(ret).result;
    }
    terminate() {
        lib.call("raia_glfw_terminate");
    }
    /**
     * @param {int} width
     * @param {int} height
     * @param {string} title
     * @returns {uintptr} window_id
     */
    createWindow(width, height, title) {
        var args = JSON.stringify({
            "width": width,
            "height": height,
            "title": title
        });
        var ret = lib.call("raia_glfw_create_window", args);
        return JSON.parse(ret).window_id;
    }
    /**
     * @param {uintptr} window_id
     */
    destroyWindow(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_destroy_window", args);
    }
    /**
     * @param {int} hint
     * @param {int} value
     */
    windowHint(hint, value) {
        var args = JSON.stringify({
            "hint": hint,
            "value": value
        });
        lib.call("raia_glfw_window_hint", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    makeContextCurrent(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_make_context_current", args);
    }
    /**
     * @returns {uintptr} window_id
     */
    getCurrentContext() {
        var ret = lib.call("raia_glfw_get_current_context");
        return JSON.parse(ret).window_id;
    }
    /**
     * @param {int} interval 
     */
    swapInterval(interval) {
        var args = JSON.stringify({
            "interval": interval
        });
        lib.call("raia_glfw_swap_interval", args);
    }
    /**
     * @param {uintptr} window_id 
     * @returns {{width: int, height: int}}
     */
    getWindowSize(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = lib.call("raia_glfw_get_window_size", args);
        return JSON.parse(ret);
    }
    /**
     * @param {uintptr} window_id 
     * @returns {{width: int, height: int}}
     */
    getFramebufferSize(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = lib.call("raia_glfw_get_framebuffer_size", args);
        return JSON.parse(ret);
    }
    /**
     * @param {uintptr} window_id 
     */
    swapBuffers(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_swap_buffers", args);
    }
    pollEvents() {
        lib.call("raia_glfw_poll_events");
    }
    /**
     * @param {uintptr} window_id 
     * @returns {int}
     */
    windowShouldClose(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = lib.call("raia_glfw_window_should_close", args);
        return JSON.parse(ret).result;
    }
    /**
     * @param {uintptr} window_id 
     * @param {string} title 
     */
    setWindowTitle(window_id, title) {
        var args = JSON.stringify({
            "window_id": window_id,
            "title": title
        });
        var ret = lib.call("raia_glfw_set_window_title", args);
    }
    /**
     * @returns {uint}
     */
    getTimerValue() {
        var ret = lib.call("raia_glfw_get_timer_value");
        return JSON.parse(ret).result;
    }
    /**
     * @returns {uint}
     */
    getTimerFrequency() {
        var ret = lib.call("raia_glfw_get_timer_frequency");
        return JSON.parse(ret).result;
    }
    /**
     * @returns {real}
     */
    getTime() {
        var ret = lib.call("raia_glfw_get_time");
        return JSON.parse(ret).result;
    }
    /**
     * @param {real} time 
     */
    setTime(time) {
        var args = JSON.stringify({
            "time": time
        });
        lib.call("raia_glfw_set_time", args);
    }
    /**
     * @param {real} time 
     */
    waitEventTimeout(time) {
        var args = JSON.stringify({
            "time": time
        });
        lib.call("raia_glfw_wait_event_timeout", args);
    }
    setErrorCallback() {
        lib.call("raia_glfw_set_error_callback");
    }
    setJoystickCallback() {
        lib.call("raia_glfw_set_joystick_callback");
    }
    /**
     * @param {uintptr} window_id 
     */
    setKeyCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_key_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setFramebufferSizeCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_framebuffer_size_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowPosCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_pos_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowSizeCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_size_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowCloseCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_close_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowRefreshCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_refresh_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowFocusCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_focus_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setWindowIconifyCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_window_iconify_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setCursorPosCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_cursor_pos_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setMouseButtonCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_mouse_button_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setCharCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_char_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setCharModsCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_char_mods_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setCorsorEnterCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_cursor_enter_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setScrollCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_scroll_callback", args);
    }
    /**
     * @param {uintptr} window_id 
     */
    setDropCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        lib.call("raia_glfw_set_drop_callback", args);
    }
    /**
     * @returns {{error: int, message: string}}
     */
    getErroCallback() {
        var ret = lib.call("raia_glfw_get_error_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{jid: int, event: int}}
     */
    getJoystickCallback() {
        var ret = lib.call("raia_glfw_get_joystick_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */
    getFramebufferSizeCallback() {
        var ret = lib.call("raia_glfw_get_framebuffer_size_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, key: int, scancode: int, action: int, mods: int}}
     */
    getKeyCallback() {
        var ret = lib.call("raia_glfw_get_key_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, x: int, y: int}}
     */
    getWindowPosCallback() {
        var ret = lib.call("raia_glfw_get_window_pos_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, width: int, height: int}}
     */
    getWindowSizeCallback() {
        var ret = lib.call("raia_glfw_get_window_size_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr}}
     */
    getWindowCloseCallback() {
        var ret = lib.call("raia_glfw_get_window_close_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr}}
     */
    getWindowRefreshCallback() {
        var ret = lib.call("raia_glfw_get_window_refresh_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, focused: int}}
     */
    getWindowFocusCallback() {
        var ret = lib.call("raia_glfw_get_window_focus_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, iconified: int}}
     */
    getWindowIconifyCallback() {
        var ret = lib.call("raia_glfw_get_window_iconify_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, xpos: real, ypos: real}}
     */
    getCursorPosCallback() {
        var ret = lib.call("raia_glfw_get_cursor_pos_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, button: int, action: int, mods: int}}
     */
    getMouseButtonCallback() {
        var ret = lib.call("raia_glfw_get_mouse_button_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, codepoint: uint}}
     */
    getCharCallback() {
        var ret = lib.call("raia_glfw_get_char_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, codepoint: uint, mods: int}}
     */
    getCharModsCallback() {
        var ret = lib.call("raia_glfw_get_char_mods_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, enterd: int}}
     */
    getCursorEnterCallback() {
        var ret = lib.call("raia_glfw_get_cursor_enter_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, xoffset: real, yoffset: real}}
     */
    getScrollCallback() {
        var ret = lib.call("raia_glfw_get_scroll_callback");
        return JSON.parse(ret);
    }
    /**
     * @returns {{window: uintptr, count: int, paths:string[]}}
     */
    getDropCallback() {
        var ret = lib.call("raia_glfw_get_drop_callback");
        return JSON.parse(ret);
    }
    /**
     * @param {int} jid
     * @returns {int}
     */
    joystickPresent(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = lib.call("raia_glfw_joystick_present", args);
        return JSON.parse(ret).result;
    }
    /**
     * @param {int} jid
     * @returns {real[]}
     */
    getJoystickAxes(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = lib.call("raia_glfw_get_joystick_axes", args);
        return JSON.parse(ret).result;
    }
    /**
     * @param {int} jid
     * @returns {uint[]}
     */
    getJoystickButtons(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = lib.call("raia_glfw_get_joystick_buttons", args);
        return JSON.parse(ret).result;
    }
    /**
     * @param {int} jid
     * @returns {string}
     */
    getJoystickName(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = lib.call("raia_glfw_get_joystick_name", args);
        return JSON.parse(ret).result;
    }
}