import {GlfwEx} from 'raia_glfw_ex';
import {GlesEx} from 'raia_gles_ex';
import {ImGuiEx} from 'raia_imgui_ex';

/**
 * @extends GUI
 */
export class Frame {

    /**
     * @param {number} window_id (uintptr)
     */

    constructor(window_id) {
        this.gles = new GlesEx();
        this.glfw = new GlfwEx();
        this.imgui = new ImGuiEx();
        this.imgui.setDefaultConfigFlags();
        this.imgui.addFontDefault();
        var font = this.imgui.addJapaneseFontFromFileTTF("./Mplus1-Regular.ttf", 18, null);
        this.imgui.setFontDefault(font);
        this.imgui.initImpl(window_id);
    }

    destroy() {
        this.imgui.destroy();
    }

    render() {
        this.imgui.render();
        const draw_data = this.imgui.getDrawData();
        this.imgui.implOpenGL3RenderDrawData(draw_data);
        const ctx = this.glfw.getCurrentContext();
        this.imgui.updatePlatformWindows();
        this.imgui.renderPlatformWindowsDefault();
        this.glfw.makeContextCurrent(ctx);
    }

    /**
     * @param {string} title 
     * @param {function} f 
     */

    show(title, f) {
        this.imgui.begin(title);
        f();
        this.imgui.end();
    }

    start() {
        this.imgui.newFrame();
    }

    /**
     * @param {string} text 
     */

    text(text) {
        this.imgui.text(text);
    }

    /**
     * 
     * @param {object} image 
     */

    drawImage(image) {
        this.gles.setTextureRGBA(image.texture, image.width, image.height, image.pixels);
        this.imgui.image(image.texture, image.width, image.height);
    }
}