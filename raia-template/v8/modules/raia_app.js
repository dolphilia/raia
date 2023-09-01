(function() {
    if (globalThis.__Raia__.App === undefined) {
        var handle = __Raia__.Lib.open("raia_gui");
        __Raia__.Lib.add(handle, "raia_gui_test");
        __Raia__.Lib.add(handle, "raia_gui_init_glfw");
        __Raia__.Lib.add(handle, "raia_gui_create_window");
        //
        __Raia__.Lib.add(handle, "raia_app_init");
        __Raia__.Lib.add(handle, "raia_app_window_create");
        __Raia__.Lib.add(handle, "raia_app_time_get_current_time");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_timer_value");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_timer_frequency");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_time");
        __Raia__.Lib.add(handle, "raia_app_glfw_set_time");
        __Raia__.Lib.add(handle, "raia_app_glfw_wait_event_timeout");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_joystick_present");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_joystick_axes");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_joystick_buttons");
        __Raia__.Lib.add(handle, "raia_app_glfw_get_joystick_name");
        __Raia__.Lib.add(handle, "raia_app_screen_redraw");
        __Raia__.Lib.add(handle, "raia_app_window_poll_events");
        __Raia__.Lib.add(handle, "raia_app_window_should_close");
        __Raia__.Lib.add(handle, "raia_app_window_set_title");
        __Raia__.Lib.add(handle, "raia_app_shader_init");
        __Raia__.Lib.add(handle, "raia_app_get_error");
        __Raia__.Lib.add(handle, "raia_app_get_key");
        __Raia__.Lib.add(handle, "raia_app_get_framebuffer_size");
        __Raia__.Lib.add(handle, "raia_app_get_joystick");
        __Raia__.Lib.add(handle, "raia_app_get_window_pos");
        __Raia__.Lib.add(handle, "raia_app_get_window_size");
        __Raia__.Lib.add(handle, "raia_app_get_window_close");
        __Raia__.Lib.add(handle, "raia_app_get_window_refresh");
        __Raia__.Lib.add(handle, "raia_app_get_window_focus");
        __Raia__.Lib.add(handle, "raia_app_get_window_iconify");
        __Raia__.Lib.add(handle, "raia_app_get_cursor_position");
        __Raia__.Lib.add(handle, "raia_app_get_mouse_button");
        __Raia__.Lib.add(handle, "raia_app_get_character");
        __Raia__.Lib.add(handle, "raia_app_get_character_mods");
        __Raia__.Lib.add(handle, "raia_app_get_cursor_enter");
        __Raia__.Lib.add(handle, "raia_app_get_scroll");
        __Raia__.Lib.add(handle, "raia_app_get_drop");
        //__Raia__.Lib.call("raia_app_init", "");
        globalThis.__Raia__.App = {};

        //__Raia__.Lib.call("raia_gui_init_glfw", "{}");
    }
}());

export class App {
    constructor(width, height, title) {
        var window = this.init_window(width, height, title);
        var shader = this.init_shader(window.width, window.height);
        this.id = window.id;
        this.title = window.title;
        this.resolution_width = window.resolution_width;
        this.resolution_height = window.resolution_height;
        this.vertices = shader.vertices;
        this.indices = shader.indices;
        this.program = shader.program;
        this.pos_location = shader.pos_location;
        this.tex_location = shader.tex_location;
        this.sampler_location = shader.sampler_location;
        this.texture = shader.texture;
        this.pixels = new ArrayBuffer(width * height * 3);
        this.pixels_size = width * height * 3;
        this.size = {
            width: window.width,
            height: window.height
        }
        this.color = {
            red: 0,
            green: 0,
            blue: 0
        };
        this.position = {
            x: 0,
            y: 0
        }
        this.fps = 60.0;
    }
    init_shader(width, height) {
        var args = JSON.stringify({
            "window_width": width,
            "window_height": height
        });
        var ret = __Raia__.Lib.call("raia_app_shader_init", args); // (width, height)
        return JSON.parse(ret);
    }
    init_window(width, height, title) {
        var args = JSON.stringify({
            "width": width,
            "height": height,
            "title": title
        });
        var ret = __Raia__.Lib.call("raia_app_window_create", args);
        return JSON.parse(ret);
    }
    init_gui(width, height, title) {
        var args = JSON.stringify({
            "width": width,
            "height": height,
            "title": title
        });
        var ret = __Raia__.Lib.call("raia_gui_window_create", args);
        return JSON.parse(ret);
    }
    waitEventTimeout(time) {
        var args = JSON.stringify({
            "time": time
        });
        var ret = __Raia__.Lib.call("raia_app_glfw_wait_event_timeout", args)
        return JSON.parse(ret).result;
    }
    setTitle(title) {
        var args = JSON.stringify({
            "window_id": this.id,
            "title": title
        });
        var ret = __Raia__.Lib.call("raia_app_window_set_title", args); // (window, title)
        return JSON.parse(ret).result;
    }
    shouldClose() {
        var args = JSON.stringify({
            "window_id": this.id
        });
        var ret = __Raia__.Lib.call("raia_app_window_should_close", args);
        return JSON.parse(ret).result;
    }
    pollEvents() {
        __Raia__.Lib.call("raia_app_window_poll_events", ""); // (void)
    }
    redraw() {
        var args = JSON.stringify({
            "vertices": this.vertices,
            "indices": this.indices,
            "program": this.program,
            "pos_location": this.pos_location,
            "tex_location": this.tex_location,
            "sampler_location": this.sampler_location,
            "texture": this.texture,
            "window_width": this.size.width,
            "window_height": this.size.height,
            "resolution_width": this.resolution_width,
            "resolution_height": this.resolution_height,
            "window_id": this.id,
            "pixels": __Raia__.Core.arrayBufferToPointer(this.pixels)
        });
        var ret = __Raia__.Lib.call("raia_app_screen_redraw", args);
        return JSON.parse(ret).result;
    }
    getError() {
        return JSON.parse(__Raia__.Core.Lib.call("raia_app_get_error", ""));
    }
    getKey() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_key", ""));
    }
    getFramebufferSize() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_framebuffer_size", ""));
    }
    getJoystick() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_joystick", ""));
    }
    getWindowPos() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_pos", ""));
    }
    getWindowSize() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_size", ""));
    }
    getWindowClose() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_close", ""));
    }
    getWindowRefresh() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_refresh", ""));
    }
    getWindowFocus() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_focus", ""));
    }
    getWindowIconify() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_window_iconify", ""));
    }
    getCursorPos() {
        // window, xpos, ypos
        return JSON.parse(__Raia__.Lib.call("raia_app_get_cursor_position", ""));
    }
    getMouseButton() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_mouse_button", ""));
    }
    getChar() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_character", ""));
    }
    getCharMods() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_character_mods", ""));
    }
    getCursorEnter() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_cursor_enter", ""));
    }
    getScroll() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_scroll", ""));
    }
    getDrop() {
        return JSON.parse(__Raia__.Lib.call("raia_app_get_drop", ""));
    }
    getCurrentTime() {
        var result = __Raia__.Lib.call("raia_app_time_get_current_time", "")
        return JSON.parse(result).result;
    }
    getTimerValue() {
        var result = __Raia__.Lib.call("raia_app_glfw_get_timer_value", "")
        return JSON.parse(result).result;
    }
    getTimerFrequency() {
        var result = __Raia__.Lib.call("raia_app_glfw_get_timer_frequency", "")
        return JSON.parse(result).result;
    }
    getTime() {
        var result = __Raia__.Lib.call("raia_app_glfw_get_time", "")
        return JSON.parse(result).result;
    }
    setTime(time) {
        var json_str = JSON.stringify({"time": time});
        var result = __Raia__.Lib.call("raia_app_glfw_set_time", json_str)
        return JSON.parse(result).result;
    }
    joystickPresent(jid) {
        var args = JSON.stringify({"jid": jid,});
        var ret = __Raia__.Lib.call("raia_app_glfw_get_joystick_present", args)
        return JSON.parse(ret).result;
    }
    getJoystickAxes(jid) {
        var args = JSON.stringify({"jid": jid});
        var ret = __Raia__.Lib.call("raia_app_glfw_get_joystick_axes", args)
        return JSON.parse(ret).result;
    }
    getJoystickButtons(jid) {
        var args = JSON.stringify({"jid": jid});
        var ret = __Raia__.Lib.call("raia_app_glfw_get_joystick_buttons", args)
        return JSON.parse(ret).result;
    }
    getJoystickName(jid) {
        var args = JSON.stringify({"jid": jid});
        var ret = __Raia__.Lib.call("raia_app_glfw_get_joystick_name", args)
        return JSON.parse(ret).result;
    }
}