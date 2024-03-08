import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_IMGUI__ === undefined) {
        globalThis.__RAIA_IMGUI__ = {};
        globalThis.__RAIA_IMGUI__.handle = lib.open("raia_imgui");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_check_version");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_create_context");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_config_flags");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_config_viewports_no_auto_merge");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_config_viewports_no_task_bar_icon");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_font_global_scale");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_framerate");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_dark");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_light");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_classic");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_window_border_size");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_window_rounding");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_scale_all_sizes");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_colors");
        //lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_col_window_bg");
        //lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_col_text");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_init_for_opengl");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_init");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_add_font_default");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_glyph_ranges_japanese");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_add_font_from_file_ttf");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_assert");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_font_default");
        //lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_init_font");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_shutdown");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_shutdown");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_destroy_context");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_new_frame");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_new_frame");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_new_frame");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_render");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_draw_data");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_render_draw_data");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_update_platform_windows");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_render_platform_windows_default");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_begin");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_end");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_text");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_button");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_image");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_checkbox");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_slider_float");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_color_edit_3");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_same_line");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_var_float");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_var_vec2");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_pop_style_var");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_color_u32");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_color_vec4");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_pop_style_color");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_next_window_bg_alpha");
        lib.add(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_separator");
        
        // 初期化
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_check_version");
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_create_context");
    }
})();

export class ImGui {

    constructor() {
        this.ConfigFlags = {
            None                    : 0,
            NavEnableKeyboard       : 1 << 0,
            NavEnableGamepad        : 1 << 1,
            NavEnableSetMousePos    : 1 << 2,
            NavNoCaptureKeyboard    : 1 << 3,
            NoMouse                 : 1 << 4,
            NoMouseCursorChange     : 1 << 5,
            DockingEnable           : 1 << 6,
            ViewportsEnable         : 1 << 10,
            DpiEnableScaleViewports : 1 << 14,
            DpiEnableScaleFonts     : 1 << 15,
            IsSRGB                  : 1 << 20,
            IsTouchScreen           : 1 << 21
        };
        this.Col = { // enum
            Text                  : 0,
            TextDisabled          : 1,
            WindowBg              : 2,
            ChildBg               : 3,
            PopupBg               : 4,
            Border                : 5,
            BorderShadow          : 6,
            FrameBg               : 7,
            FrameBgHovered        : 8,
            FrameBgActive         : 9,
            TitleBg               : 10,
            TitleBgActive         : 11,
            TitleBgCollapsed      : 12,
            MenuBarBg             : 13,
            ScrollbarBg           : 14,
            ScrollbarGrab         : 15,
            ScrollbarGrabHovered  : 16,
            ScrollbarGrabActive   : 17,
            CheckMark             : 18,
            SliderGrab            : 19,
            SliderGrabActive      : 20,
            Button                : 21,
            ButtonHovered         : 22,
            ButtonActive          : 23,
            Header                : 24,
            HeaderHovered         : 25,
            HeaderActive          : 26,
            Separator             : 27,
            SeparatorHovered      : 28,
            SeparatorActive       : 29,
            ResizeGrip            : 30,
            ResizeGripHovered     : 31,
            ResizeGripActive      : 32,
            Tab                   : 33,
            TabHovered            : 34,
            TabActive             : 35,
            TabUnfocused          : 36,
            TabUnfocusedActive    : 37,
            DockingPreview        : 38,
            DockingEmptyBg        : 39,
            PlotLines             : 40,
            PlotLinesHovered      : 41,
            PlotHistogram         : 42,
            PlotHistogramHovered  : 43,
            TableHeaderBg         : 44,
            TableBorderStrong     : 45,
            TableBorderLight      : 46,
            TableRowBg            : 47,
            TableRowBgAlt         : 48,
            TextSelectedBg        : 49,
            DragDropTarget        : 40,
            NavHighlight          : 51,
            NavWindowingHighlight : 52,
            NavWindowingDimBg     : 53,
            ModalWindowDimBg      : 54,
            COUNT                 : 55
        };
        this.WindowFlags = {
            None                     : 0,
            NoTitleBar               : 1 << 0,
            NoResize                 : 1 << 1,
            NoMove                   : 1 << 2,
            NoScrollbar              : 1 << 3,
            NoScrollWithMouse        : 1 << 4,
            NoCollapse               : 1 << 5,
            AlwaysAutoResize         : 1 << 6,
            NoBackground             : 1 << 7,
            NoSavedSettings          : 1 << 8,
            NoMouseInputs            : 1 << 9,
            MenuBar                  : 1 << 10,
            HorizontalScrollbar      : 1 << 11,
            NoFocusOnAppearing       : 1 << 12,
            NoBringToFrontOnFocus    : 1 << 13,
            AlwaysVerticalScrollbar  : 1 << 14,
            AlwaysHorizontalScrollbar: 1 << 15,
            AlwaysUseWindowPadding   : 1 << 16,
            NoNavInputs              : 1 << 18,
            NoNavFocus               : 1 << 19,
            UnsavedDocument          : 1 << 20,
            NoDocking                : 1 << 21
        };
        this.WindowFlags.NoNav        = this.WindowFlags.NoNavInputs   | this.WindowFlags.NoNavFocus;
        this.WindowFlags.NoDecoration = this.WindowFlags.NoTitleBar    | this.WindowFlags.NoResize    | this.WindowFlags.NoScrollbar | this.WindowFlags.NoCollapse;
        this.WindowFlags.NoInputs     = this.WindowFlags.NoMouseInputs | this.WindowFlags.NoNavInputs | this.WindowFlags.NoNavFocus;
    }

    checkVersion() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_check_version");
    }

    createContext() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_create_context");
    }

    /**
     * 
     * @param {boolean} flag (int)
     */

    configViewportsNoAutoMerge(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_config_viewports_no_auto_merge", args);
    }

    /**
     * 
     * @param {boolean} flag (int)
     */

    configViewportsNoTaskBarIcon(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_config_viewports_no_task_bar_icon", args);
    }

    /**
     * @param {number} config_flags (int)
     */

    setConfigFlags(config_flags) {
        var args = JSON.stringify({
            "config_flags": config_flags
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_config_flags", args);
    }

    /**
     * @param {number} scale (real)
     */

    fontGlobalScale(scale) {
        var args = JSON.stringify({
            "scale": scale
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_font_global_scale", args);
    }

    /**
     * @returns {number} framerate (real)
     */

    getFramerate() {
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_framerate");
        return JSON.parse(ret).result;
    }

    styleColorsDark() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_dark");
    }

    styleColorsLight() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_light");
    }

    styleColorsClassic() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_style_colors_classic");
    }

    /**
     * @param {number} width (real)
     */

    setStyleWindowBorderSize(width) {
        var args = JSON.stringify({
            "width": width
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_window_border_size", args);
    }

    /**
     * @param {number} radius (real)
     */

    setStyleWindowRounding(radius) {
        var args = JSON.stringify({
            "radius": radius
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_window_rounding", args);
    }

    /**
     * @param {number} scale (real)
     */

    setStyleScaleAllSizes(scale) {
        var args = JSON.stringify({
            "scale": scale
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_scale_all_sizes", args);
    }

    /**
     * @param {number} col (int)
     * @param {number} red (real) 0.0 ~ 1.0
     * @param {number} green (real) 0.0 ~ 1.0
     * @param {number} blue (real) 0.0 ~ 1.0
     * @param {number} alpha (real) 0.0 ~ 1.0
     */

    setStyleColors(col, red, green, blue, alpha) {
        var args = JSON.stringify({
            "col": col,
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_style_colors", args);
    }

    /**
     * @param {number} window_id (uintptr)
     * @param {boolean} install_callbacks (int)
     */

    implGlfwInitForOpenGL(window_id, install_callbacks) {
        var args = JSON.stringify({
            "window_id": window_id,
            "install_callbacks": install_callbacks
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_init_for_opengl", args);
    }

    /**
     * @param {string} glsl_version (string)
     */

    implOpenGL3Init(glsl_version) {
        var args = JSON.stringify({
            "glsl_version": glsl_version
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_init", args);
    }

    addFontDefault() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_add_font_default");
    }

    /**
     * @returns {number} (uintptr) glyph_ranges
     */

    getGlyphRangesJapanese() {
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_glyph_ranges_japanese");
        return JSON.parse(ret).result;
    }

    /**
     * @param {string} filename (string)
     * @param {number} size_pixels (real)
     * @param {number | null} font_cfg (uintptr | null)
     * @param {number | null} glyph_ranges (uintptr | null)
     * @returns {number} font (uintptr)
     */

    addFontFromFileTTF(filename, size_pixels, font_cfg = null, glyph_ranges = null) {
        var args = JSON.stringify({
            "filename": filename,
            "size_pixels": size_pixels,
            "font_cfg": font_cfg,
            "glyph_ranges": glyph_ranges
        });
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_add_font_from_file_ttf", args);
        return JSON.parse(ret).result;
    }

    /**
     * @param {boolean} expr (boolean)
     */

    assert(expr) {
        var args = JSON.stringify({
            "expr": expr
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_assert", args);
    }

    /**
     * @param {number} font (uintptr)
     */

    setFontDefault(font) {
        var args = JSON.stringify({
            "font": font
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_font_default", args);
    }

    initFont() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_init_font");
    }

    implOpenGL3Shutdown() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_shutdown");
    }

    implGlfwShutdown() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_shutdown");
    }

    destroyContext() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_destroy_context");
    }

    implOpenGL3NewFrame() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_new_frame");
    }

    implGlfwNewFrame() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_glfw_new_frame");
    }

    newFrame() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_new_frame");
    }

    render() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_render");
    }

    /**
     * @returns {number} draw_data (uintptr)
     */

    getDrawData() {
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_get_draw_data");
        return JSON.parse(ret).result;
    }

    /**
     * @param {number} draw_data (uintptr)
     */

    implOpenGL3RenderDrawData(draw_data) {
        var args = JSON.stringify({
            "draw_data": draw_data
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_impl_opengl3_render_draw_data", args);
    }

    updatePlatformWindows() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_update_platform_windows");
    }

    renderPlatformWindowsDefault() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_render_platform_windows_default");
    }

    /**
     * @param {string} name (string)
     * @param {number | null} p_open (uintptr)
     * @param {number} flags (int)
     */

    begin(name = "Untitled", p_open = null, flags = 0) {
        var args = JSON.stringify({
            "name": name,
            "p_open": p_open,
            "flags": flags
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_begin", args);
    }

    end() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_end");
    }

    /**
     * @param {string} text (string)
     */
    text(text) {
        var args = JSON.stringify({
            "text": text
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_text", args);
    }

    /**
     * @param {string} label (string)
     * @returns {boolean} (boolean) pressed
     */

    button(label) {
        var args = JSON.stringify({
            "label": label
        });
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_button", args);
        return JSON.parse(ret).result;
    }

    /**
     * @param {number} texture_id (int)
     * @param {number} width (real)
     * @param {number} height (real)
     */

    image(texture_id, width, height) {
        var args = JSON.stringify({
            "texture_id": texture_id,
            "width": width,
            "height": height
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_image", args);
    }

    /**
     * @param {string} label (string)
     * @param {boolean} v (boolean)
     * @returns {boolean} (boolean) checked
     */

    checkbox(label, v) {
        var args = JSON.stringify({
            "label": label,
            "v": v
        });
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_checkbox", args);
        return JSON.parse(ret).result;
    }

    /**
     * @param {string} label (string)
     * @param {number} v (real)
     * @param {number} v_min (real)
     * @param {number} v_max (real)
     * @returns {number} (real) value
     */

    sliderFloat(label, v, v_min, v_max) {
        var args = JSON.stringify({
            "label": label,
            "v": v,
            "v_min": v_min,
            "v_max": v_max
        });
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_slider_float", args);
        return JSON.parse(ret).result;
    }

    /**
     * @param {string} label (string)
     * @param {number} red (real)
     * @param {number} green (real)
     * @param {number} blue (real)
     * @returns {{red: real, gree: real, blue:real}}
     */

    colorEdit3(label, red, green, blue) {
        var args = JSON.stringify({
            "label": label,
            "red": red,
            "green": green,
            "blue": blue
        });
        var ret = lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_color_edit_3", args);
        return JSON.parse(ret);
    }

    sameLine() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_same_line");
    }

    /**
     * @param {number} idx (int)
     * @param {number} val (real)
     */

    pushStyleVarFloat(idx, val) {
        var args = JSON.stringify({
            "idx": idx,
            "val": val
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_var_float", args);
    }

    /**
     * @param {number} idx (int)
     * @param {number} x (real)
     * @param {number} y (real)
     */

    pushStyleVarVec2(idx, x, y) {
        var args = JSON.stringify({
            "idx": idx,
            "x": x,
            "y": y
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_var_vec2", args);
    }

    /**
     * @param {number} count (int)
     */

    popStyleVar(count) {
        var args = JSON.stringify({
            "count": count
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_pop_style_var", args);
    }

    /**
     * @param {number} idx (int)
     * @param {number} col (uint)
     */

    pushStyleColorU32(idx, col) {
        var args = JSON.stringify({
            "idx": idx,
            "col": col
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_color_u32", args);
    }

    /**
     * @param {number} idx (int)
     * @param {number} x (real) 
     * @param {number} y (real) 
     * @param {number} z (real) 
     * @param {number} w (real) 
     */

    pushStyleColorVec4(idx, x, y, z, w) {
        var args = JSON.stringify({
            "idx": idx,
            "x": x,
            "y": y,
            "z": z,
            "w": w
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_push_style_color_vec4", args);
    }

    /**
     * @param {number} count (int)
     */

    popStyleColor(count = 1) {
        var args = JSON.stringify({
            "count": count
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_pop_style_color", args);
    }

    /**
     * @param {number} alpha (real)
     */

    setNextWindowBgAlpha(alpha = 1.0) {
        var args = JSON.stringify({
            "alpha": alpha
        });
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_set_next_window_bg_alpha", args);
    }
    
    separator() {
        lib.call(globalThis.__RAIA_IMGUI__.handle, "raia_imgui_separator");
    }
}