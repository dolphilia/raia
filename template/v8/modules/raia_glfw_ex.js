import {Std} from "raia_std";
const std = new Std();

import {GLFW} from 'raia_glfw';

/**
 * @extends GLFW
 */
export class GlfwEx extends GLFW {
    /**
     * 
     * @param {uintptr} window 
     */
    setCallback(window) {
        super.setKeyCallbackDefault(window);
        super.setCursorPosCallbackDefault(window);
        super.setMouseButtonCallbackDefault(window);
        super.setCharCallbackDefault(window);
        super.setCharModsCallbackDefault(window);
        super.setCorsorEnterCallbackDefault(window);
        super.setScrollCallbackDefault(window);
        super.setDropCallbackDefault(window);
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
     * 
     * @param {int} width 
     * @param {int} height 
     * @param {string} title 
     * @returns {uintptr} window_id
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
     * 
     * @param {uintptr} window 
     */
    destroy(window) {
        super.destroyWindow(window);
        super.terminate();
    }
}