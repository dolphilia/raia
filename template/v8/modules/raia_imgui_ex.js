import {ImGui} from 'raia_imgui';

/**
 * @extends ImGui
 */

export class ImGuiEx extends ImGui {
    newFrame() {
        super.implOpenGL3NewFrame();
        super.implGlfwNewFrame();
        super.newFrame();
    }
    destroy() {
        super.implOpenGL3Shutdown();
        super.implGlfwShutdown();
        super.destroyContext();
    }
    init() {
        super.checkVersion();
        super.createContext();
    }
    /**
     * 
     * @param {uintptr} window 
     */
    initImpl(window) {
        super.implGlfwInitForOpenGL(window, true);
        super.implOpenGL3Init("#version 300 es");
    }
    setDefaultConfigFlags() {
        var config_flags = 0;
        config_flags |= this.ConfigFlags.NavEnableKeyboard;
        config_flags |= this.ConfigFlags.NavEnableGamepad;
        config_flags |= this.ConfigFlags.DockingEnable;
        config_flags |= this.ConfigFlags.ViewportsEnable;
        super.setConfigFlags(config_flags);
    }
    /**
     * 
     * @param {string} filename 
     * @param {real} size_pixels 
     * @param {uintptr} font_cfg 
     * @returns {uint} font
     */
    addJapaneseFontFromFileTTF(filename, size_pixels, font_cfg = null) {
        var glyph_ranges_japanese = super.getGlyphRangesJapanese();
        return super.addFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges_japanese);
    }        
}
