import {Std} from "raia_std";
const std = new Std();

import {GLFW} from 'raia_glfw';
import {GlfwEx} from 'raia_glfw_ex';
import {GlesEx} from 'raia_gles_ex';
import {ImGuiEx} from 'raia_imgui_ex';

(function(){
    if (globalThis.__RAIA_GUI__ === undefined) {
        const glfw = new GLFW();
        glfw.init();
        glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API);
        glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3);
        glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0);
        glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE);
        glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API);
        glfw.setErrorCallback();
        glfw.setJoystickCallback();
        globalThis.__RAIA_GUI__ = {};
    }
})();

export class GUI {
    constructor() {
        this.gles = new GlesEx();
        this.glfw = new GlfwEx();
        this.imgui = new ImGuiEx();
    }
}
