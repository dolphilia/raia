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
        glfw.windowHint(GLFW.CLIENT_API, GLFW.OPENGL_ES_API);
        glfw.windowHint(GLFW.CONTEXT_VERSION_MAJOR, 3);
        glfw.windowHint(GLFW.CONTEXT_VERSION_MINOR, 0);
        glfw.windowHint(GLFW.OPENGL_PROFILE, GLFW.OPENGL_CORE_PROFILE);
        glfw.windowHint(GLFW.CONTEXT_CREATION_API, GLFW.EGL_CONTEXT_API);
        glfw.setErrorCallbackDefault();
        glfw.setJoystickCallbackDefault();
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
