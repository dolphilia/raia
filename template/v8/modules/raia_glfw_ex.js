import {Std} from "raia_std";
const std = new Std();

import {GLFW} from 'raia_glfw';

/**
 * @extends GLFW
 */

export class GlfwEx extends GLFW {

    /**
     * @param {number} window (uintptr)
     */

    setCallback(window) {
        super.setKeyCallbackAlt(window);
        super.setCursorPosCallbackAlt(window);
        super.setMouseButtonCallbackAlt(window);
        super.setCharCallbackAlt(window);
        super.setCharModsCallbackAlt(window);
        super.setCorsorEnterCallbackAlt(window);
        super.setScrollCallbackAlt(window);
        super.setDropCallbackAlt(window);
        //
        super.setFramebufferSizeCallback(window);
        super.setWindowPosCallback(window);
        super.setWindowSizeCallback(window);
        super.setWindowCloseCallback(window);
        super.setWindowRefreshCallback(window);
        super.setWindowFocusCallback(window);
        super.setWindowIconifyCallback(window);
    }

    /**
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} title 
     * @returns {number} (uintptr) window_id
     */

    createMainWindow(width, height, title) {
        var window = super.createWindow(width, height, title);
        if(window === null) {
            std.print("Window creation failed.");
            super.terminate();
            std.exit(1);
        }
        return window;
    }

    /**
     * @param {number} window (uintptr)
     */

    destroy(window) {
        super.destroyWindow(window);
        super.terminate();
    }
}