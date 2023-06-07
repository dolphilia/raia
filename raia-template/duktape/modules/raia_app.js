"use strict";

var raia_app_handle = __Raia__.Core.Lib.open("raia_app");

__Raia__.Core.Lib.add(raia_app_handle, "raia_app_init");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_window_create");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_time_get_current_time");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_timer_value");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_timer_frequency");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_time");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_set_time");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_wait_event_timeout");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_joystick_present");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_joystick_axes");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_joystick_buttons");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_glfw_get_joystick_name");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_screen_redraw");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_window_poll_events");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_window_should_close");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_window_set_title");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_shader_init");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_error");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_key");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_framebuffer_size");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_joystick");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_pos");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_size");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_close");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_refresh");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_focus");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_window_iconify");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_cursor_position");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_mouse_button");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_character");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_character_mods");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_cursor_enter");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_scroll");
__Raia__.Core.Lib.add(raia_app_handle, "raia_app_get_drop");

module.exports = {
    init: function init() {
        var json_str = JSON.stringify({ "@return": "string" });
        __Raia__.Core.Lib.call("raia_app_init", json_str, null, null); // (void)
    },
    Shader: {
        init: function init(width, height) {
            var json_str = JSON.stringify({
                "window_width": width,
                "window_height": height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_app_shader_init", json_str, null, null); // (width, height)
            return JSON.parse(ret);
        }
    },
    Window: {
        waitEventTimeout: function waitEventTimeout(time) {
            var json_str = JSON.stringify({ "time": time, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_wait_event_timeout", json_str, null, null);
            return JSON.parse(result).result;
        },
        init: function init(width, height, title) {
            var json_str = JSON.stringify({
                "width": width,
                "height": height,
                "title": title,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_app_window_create", json_str, null, null);
            return JSON.parse(ret);
        }, // (width, height, title)
        setTitle: function setTitle(window_id, title) {
            var json_str = JSON.stringify({
                "window_id": __Raia__.Core.pointerToNumber(window_id),
                "title": title,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_app_window_set_title", json_str, null, null); // (window, title)
            return JSON.parse(ret).result;
        },
        shouldClose: function shouldClose(window_id) {
            var json_str = JSON.stringify({
                "window_id": __Raia__.Core.pointerToNumber(window_id),
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_app_window_should_close", json_str, null, null);
            return JSON.parse(ret).result;
        }, // (window)
        pollEvents: function pollEvents() {
            var json_str = JSON.stringify({ "@return": "string" });
            __Raia__.Core.Lib.call("raia_app_window_poll_events", json_str, null, null); // (void)
        },
        //waitEventTimeout: __Raia__.Core.Lib.func("raia_app_glfw_wait_event_timeout", 1), // (void)
        redraw: function redraw(vertices, indices, program, pos_location, tex_location, sampler_location, texture, window_width, window_height, resolution_width, resolution_height, id, pixels) {
            var json = {
                "vertices": vertices,
                "indices": indices,
                "program": program,
                "pos_location": pos_location,
                "tex_location": tex_location,
                "sampler_location": sampler_location,
                "texture": texture,
                "window_width": window_width,
                "window_height": window_height,
                "resolution_width": resolution_width,
                "resolution_height": resolution_height,
                "window_id": __Raia__.Core.pointerToNumber(id),
                "@return": "string"
            };
            var json_str = JSON.stringify(json);
            var result = __Raia__.Core.Lib.call("raia_app_screen_redraw", json_str, pixels, null);
            return JSON.parse(result).result;
        }
    },
    Event: {
        getError: function getError() {
            var json_str = JSON.stringify({ "@return": "string" });
            return __Raia__.Core.Lib.call("raia_app_get_error", json_str, null, null);
        },
        getKey: function getKey() {
            var json_str = JSON.stringify({ "@return": "string" });
            return __Raia__.Core.Lib.call("raia_app_get_key", json_str, null, null); // (void)
        },
        getFramebufferSize: function getFramebufferSize() {
            var json_str = JSON.stringify({ "@return": "string" });
            return __Raia__.Core.Lib.call("raia_app_get_framebuffer_size", json_str, null, null); // (void)
        },
        getJoystick: function getJoystick() {
            return __Raia__.Core.Lib.call("raia_app_get_joystick", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowPos: function getWindowPos() {
            return __Raia__.Core.Lib.call("raia_app_get_window_pos", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowSize: function getWindowSize() {
            return __Raia__.Core.Lib.call("raia_app_get_window_size", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowClose: function getWindowClose() {
            return __Raia__.Core.Lib.call("raia_app_get_window_close", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowRefresh: function getWindowRefresh() {
            return __Raia__.Core.Lib.call("raia_app_get_window_refresh", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowFocus: function getWindowFocus() {
            return __Raia__.Core.Lib.call("raia_app_get_window_focus", JSON.stringify({ "@return": "string" }), null, null);
        },
        getWindowIconify: function getWindowIconify() {
            return __Raia__.Core.Lib.call("raia_app_get_window_iconify", JSON.stringify({ "@return": "string" }), null, null);
        },
        getCursorPos: function getCursorPos() {
            return __Raia__.Core.Lib.call("raia_app_get_cursor_position", JSON.stringify({ "@return": "string" }), null, null);
        },
        getMouseButton: function getMouseButton() {
            return __Raia__.Core.Lib.call("raia_app_get_mouse_button", JSON.stringify({ "@return": "string" }), null, null);
        },
        getChar: function getChar() {
            return __Raia__.Core.Lib.call("raia_app_get_character", JSON.stringify({ "@return": "string" }), null, null);
        },
        getCharMods: function getCharMods() {
            return __Raia__.Core.Lib.call("raia_app_get_character_mods", JSON.stringify({ "@return": "string" }), null, null);
        },
        getCursorEnter: function getCursorEnter() {
            return __Raia__.Core.Lib.call("raia_app_get_cursor_enter", JSON.stringify({ "@return": "string" }), null, null);
        },
        getScroll: function getScroll() {
            return __Raia__.Core.Lib.call("raia_app_get_scroll", JSON.stringify({ "@return": "string" }), null, null);
        },
        getDrop: function getDrop() {
            return __Raia__.Core.Lib.call("raia_app_get_drop", JSON.stringify({ "@return": "string" }), null, null);
        }
    },
    Time: {
        getCurrentTime: function getCurrentTime() {
            var json_str = JSON.stringify({ "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_time_get_current_time", json_str, null, null);
            return JSON.parse(result).result;
        },
        getTimerValue: function getTimerValue() {
            var json_str = JSON.stringify({ "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_timer_value", json_str, null, null);
            return JSON.parse(result).result;
        },
        getTimerFrequency: function getTimerFrequency() {
            var json_str = JSON.stringify({ "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_timer_frequency", json_str, null, null);
            return JSON.parse(result).result;
        },
        getTime: function getTime() {
            var json_str = JSON.stringify({ "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_time", json_str, null, null);
            return JSON.parse(result).result;
        },
        setTime: function setTime(time) {
            var json_str = JSON.stringify({ "time": time, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_set_time", json_str, null, null);
            return JSON.parse(result).result;
        }
        //getCurrentTime: __Raia__.Core.Lib.func("raia_app_time_get_current_time", 0),
        //getTimerValue: __Raia__.Core.Lib.func("raia_app_glfw_get_timer_value", 0),
        //getTimerFrequency: __Raia__.Core.Lib.func("raia_app_glfw_get_timer_frequency", 0),
        //getTime: __Raia__.Core.Lib.func("raia_app_glfw_get_time", 0),
        //setTime: __Raia__.Core.Lib.func("raia_app_glfw_set_time", 1),
    },
    Joystick: {
        joystickPresent: function joystickPresent(jid) {
            var json_str = JSON.stringify({ "jid": jid, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_joystick_present", json_str, null, null);
            return JSON.parse(result).result;
        },
        getJoystickAxes: function getJoystickAxes(jid) {
            var json_str = JSON.stringify({ "jid": jid, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_joystick_axes", json_str, null, null);
            return JSON.parse(result).result;
        },
        getJoystickButtons: function getJoystickButtons(jid) {
            var json_str = JSON.stringify({ "jid": jid, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_joystick_buttons", json_str, null, null);
            return JSON.parse(result).result;
        },
        getJoystickName: function getJoystickName(jid) {
            var json_str = JSON.stringify({ "jid": jid, "@return": "string" });
            var result = __Raia__.Core.Lib.call("raia_app_glfw_get_joystick_name", json_str, null, null);
            return JSON.parse(result).result;
        }
        //joystickPresent: __Raia__.Core.Lib.func("raia_app_glfw_joystick_present", 1),
        //getJoystickAxes: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_axes", 1),
        //getJoystickButtons: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_buttons", 1),
        //getJoystickName: __Raia__.Core.Lib.func("raia_app_glfw_get_joystick_name", 1),
    }
};