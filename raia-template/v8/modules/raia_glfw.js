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

(function(){
    if (globalThis.__Raia__.GLFW === undefined) {
        var handle = __Raia__.Lib.open("raia_glfw");
        __Raia__.Lib.add(handle, "raia_glfw_init");
        __Raia__.Lib.add(handle, "raia_glfw_terminate");
        __Raia__.Lib.add(handle, "raia_glfw_create_window");
        __Raia__.Lib.add(handle, "raia_glfw_destroy_window");
        __Raia__.Lib.add(handle, "raia_glfw_window_hint");
        __Raia__.Lib.add(handle, "raia_glfw_make_context_current");
        __Raia__.Lib.add(handle, "raia_glfw_get_current_context");
        __Raia__.Lib.add(handle, "raia_glfw_swap_interval");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_size");
        __Raia__.Lib.add(handle, "raia_glfw_get_framebuffer_size");
        //
        __Raia__.Lib.add(handle, "raia_glfw_set_error_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_joystick_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_key_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_framebuffer_size_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_pos_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_size_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_close_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_refresh_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_focus_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_iconify_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_cursor_pos_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_mouse_button_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_char_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_char_mods_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_cursor_enter_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_scroll_callback");
        __Raia__.Lib.add(handle, "raia_glfw_set_drop_callback");
        //
        __Raia__.Lib.add(handle, "raia_glfw_get_error_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_framebuffer_size_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_key_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_joystick_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_pos_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_size_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_close_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_refresh_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_focus_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_window_iconify_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_cursor_pos_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_mouse_button_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_char_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_char_mods_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_cursor_enter_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_scroll_callback");
        __Raia__.Lib.add(handle, "raia_glfw_get_drop_callback");
        //
        __Raia__.Lib.add(handle, "raia_glfw_get_timer_value");
        __Raia__.Lib.add(handle, "raia_glfw_get_timer_frequency");
        __Raia__.Lib.add(handle, "raia_glfw_get_time");
        __Raia__.Lib.add(handle, "raia_glfw_set_time");
        __Raia__.Lib.add(handle, "raia_glfw_wait_event_timeout");
        //
        __Raia__.Lib.add(handle, "raia_glfw_joystick_present");
        __Raia__.Lib.add(handle, "raia_glfw_get_joystick_axes");
        __Raia__.Lib.add(handle, "raia_glfw_get_joystick_buttons");
        __Raia__.Lib.add(handle, "raia_glfw_get_joystick_name");
        //
        __Raia__.Lib.add(handle, "raia_glfw_swap_buffers");
        __Raia__.Lib.add(handle, "raia_glfw_poll_events");
        __Raia__.Lib.add(handle, "raia_glfw_window_should_close");
        __Raia__.Lib.add(handle, "raia_glfw_set_window_title");
        globalThis.__Raia__.GLFW = {};
    }
})();

export class GLFW {
    static CLIENT_API = 0x00022001;
    static CONTEXT_VERSION_MAJOR = 0x00022002;
    static CONTEXT_VERSION_MINOR = 0x00022003;
    static OPENGL_PROFILE = 0x00022008;
    static CONTEXT_CREATION_API = 0x0002200B;
    static OPENGL_ES_API = 0x00030002;
    static OPENGL_CORE_PROFILE = 0x00032001;
    static EGL_CONTEXT_API = 0x00036002;

    constructor() {
    }
    init() {
        var ret = __Raia__.Lib.call("raia_glfw_init", "");
        return JSON.parse(ret);
    }
    terminate() {
        __Raia__.Lib.call("raia_glfw_terminate", "");
    }
    createWindow(width, height, title) {
        var args = JSON.stringify({
            "width": width,
            "height": height,
            "title": title
        });
        var ret = __Raia__.Lib.call("raia_glfw_create_window", args);
        return JSON.parse(ret).window_id;
    }
    destroyWindow(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_destroy_window", args);
    }
    windowHint(hint, value) {
        var args = JSON.stringify({
            "hint": hint,
            "value": value
        });
        __Raia__.Lib.call("raia_glfw_window_hint", args);
    }
    makeContextCurrent(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_make_context_current", args);
    }
    getCurrentContext() {
        var ret = __Raia__.Lib.call("raia_glfw_get_current_context", "");
        return JSON.parse(ret).window_id;
    }
    swapInterval(interval) {
        var args = JSON.stringify({
            "interval": interval
        });
        __Raia__.Lib.call("raia_glfw_swap_interval", args);
    }
    getWindowSize(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = __Raia__.Lib.call("raia_glfw_get_window_size", args);
        return JSON.parse(ret);
    }
    getFramebufferSize(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = __Raia__.Lib.call("raia_glfw_get_framebuffer_size", args);
        return JSON.parse(ret);
    }
    swapBuffers(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_swap_buffers", args);
    }
    pollEvents() {
        __Raia__.Lib.call("raia_glfw_poll_events", "");
    }
    windowShouldClose(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        var ret = __Raia__.Lib.call("raia_glfw_window_should_close", args);
        return JSON.parse(ret).result;
    }
    setWindowTitle(window_id, title) {
        var args = JSON.stringify({
            "window_id": window_id,
            "title": title
        });
        var ret = __Raia__.Lib.call("raia_glfw_set_window_title", args);
    }
    getTimerValue() {
        var ret = __Raia__.Lib.call("raia_glfw_get_timer_value", "");
        return JSON.parse(ret).result;
    }
    getTimerFrequency() {
        var ret = __Raia__.Lib.call("raia_glfw_get_timer_frequency", "");
        return JSON.parse(ret).result;
    }
    getTime() {
        var ret = __Raia__.Lib.call("raia_glfw_get_time", "");
        return JSON.parse(ret).result;
    }
    setTime(time) {
        var args = JSON.stringify({
            "time": time
        });
        __Raia__.Lib.call("raia_glfw_set_time", args);
    }
    waitEventTimeout(time) {
        var args = JSON.stringify({
            "time": time
        });
        __Raia__.Lib.call("raia_glfw_wait_event_timeout", args);
    }
    setErrorCallback() {
        __Raia__.Lib.call("raia_glfw_set_error_callback", "");
    }
    setJoystickCallback() {
        __Raia__.Lib.call("raia_glfw_set_joystick_callback", "");
    }
    setKeyCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_key_callback", args);
    }
    setFramebufferSizeCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_framebuffer_size_callback", args);
    }
    setWindowPosCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_pos_callback", args);
    }
    setWindowSizeCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_size_callback", args);
    }
    setWindowCloseCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_close_callback", args);
    }
    setWindowRefreshCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_refresh_callback", args);
    }
    setWindowFocusCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_focus_callback", args);
    }
    setWindowIconifyCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_window_iconify_callback", args);
    }
    setCursorPosCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_cursor_pos_callback", args);
    }
    setMouseButtonCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_mouse_button_callback", args);
    }
    setCharCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_char_callback", args);
    }
    setCharModsCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_char_mods_callback", args);
    }
    setCorsorEnterCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_cursor_enter_callback", args);
    }
    setScrollCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_scroll_callback", args);
    }
    setDropCallback(window_id) {
        var args = JSON.stringify({
            "window_id": window_id
        });
        __Raia__.Lib.call("raia_glfw_set_drop_callback", args);
    }
    getErroCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_error_callback", "");
        return JSON.parse(ret);
    }
    getJoystickCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_joystick_callback", "");
        return JSON.parse(ret);
    }
    getFramebufferSizeCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_framebuffer_size_callback", "");
        return JSON.parse(ret);
    }
    getKeyCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_key_callback", "");
        return JSON.parse(ret);
    }
    getWindowPosCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_pos_callback", "");
        return JSON.parse(ret);
    }
    getWindowSizeCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_size_callback", "");
        return JSON.parse(ret);
    }
    getWindowCloseCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_close_callback", "");
        return JSON.parse(ret);
    }
    getWindowRefreshCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_refresh_callback", "");
        return JSON.parse(ret);
    }
    getWindowFocusCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_focus_callback", "");
        return JSON.parse(ret);
    }
    getWindowIconifyCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_window_iconify_callback", "");
        return JSON.parse(ret);
    }
    getCursorPosCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_cursor_pos_callback", "");
        return JSON.parse(ret);
    }
    getMouseButtonCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_mouse_button_callback", "");
        return JSON.parse(ret);
    }
    getCharCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_char_callback", "");
        return JSON.parse(ret);
    }
    getCharModsCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_char_mods_callback", "");
        return JSON.parse(ret);
    }
    getCursorEnterCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_cursor_enter_callback", "");
        return JSON.parse(ret);
    }
    getScrollCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_scroll_callback", "");
        return JSON.parse(ret);
    }
    getDropCallback() {
        var ret = __Raia__.Lib.call("raia_glfw_get_drop_callback", "");
        return JSON.parse(ret);
    }
    joystickPresent(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = __Raia__.Lib.call("raia_glfw_joystick_present", args);
        return JSON.parse(ret).result;
    }
    getJoystickAxes(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = __Raia__.Lib.call("raia_glfw_get_joystick_axes", args);
        return JSON.parse(ret).result;
    }
    getJoystickButtons(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = __Raia__.Lib.call("raia_glfw_get_joystick_buttons", args);
        return JSON.parse(ret).result;
    }
    getJoystickName(jid) {
        var args = JSON.stringify({
            "jid": jid
        });
        var ret = __Raia__.Lib.call("raia_glfw_get_joystick_name", args);
        return JSON.parse(ret).result;
    }
}