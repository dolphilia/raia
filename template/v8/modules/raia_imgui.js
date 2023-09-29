import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_IMGUI__ === undefined) {
        const handle = lib.open("raia_imgui");
        lib.add(handle, "raia_imgui_check_version");
        lib.add(handle, "raia_imgui_create_context");
        lib.add(handle, "raia_imgui_set_config_flags");
        lib.add(handle, "raia_imgui_config_viewports_no_auto_merge");
        lib.add(handle, "raia_imgui_config_viewports_no_task_bar_icon");
        lib.add(handle, "raia_imgui_font_global_scale");
        lib.add(handle, "raia_imgui_get_framerate");
        lib.add(handle, "raia_imgui_style_colors_dark");
        lib.add(handle, "raia_imgui_style_colors_light");
        lib.add(handle, "raia_imgui_style_colors_classic");
        lib.add(handle, "raia_imgui_set_style_window_border_size");
        lib.add(handle, "raia_imgui_set_style_window_rounding");
        lib.add(handle, "raia_imgui_set_style_scale_all_sizes");
        lib.add(handle, "raia_imgui_set_style_colors");
        lib.add(handle, "raia_imgui_col_window_bg");
        lib.add(handle, "raia_imgui_col_text");
        lib.add(handle, "raia_imgui_impl_glfw_init_for_opengl");
        lib.add(handle, "raia_imgui_impl_opengl3_init");
        lib.add(handle, "raia_imgui_add_font_default");
        lib.add(handle, "raia_imgui_get_glyph_ranges_japanese");
        lib.add(handle, "raia_imgui_add_font_from_file_ttf");
        lib.add(handle, "raia_imgui_assert");
        lib.add(handle, "raia_imgui_set_font_default");
        lib.add(handle, "raia_imgui_init_font");
        lib.add(handle, "raia_imgui_impl_opengl3_shutdown");
        lib.add(handle, "raia_imgui_impl_glfw_shutdown");
        lib.add(handle, "raia_imgui_destroy_context");
        lib.add(handle, "raia_imgui_impl_opengl3_new_frame");
        lib.add(handle, "raia_imgui_impl_glfw_new_frame");
        lib.add(handle, "raia_imgui_new_frame");
        lib.add(handle, "raia_imgui_render");
        lib.add(handle, "raia_imgui_get_draw_data");
        lib.add(handle, "raia_imgui_impl_opengl3_render_draw_data");
        lib.add(handle, "raia_imgui_update_platform_windows");
        lib.add(handle, "raia_imgui_render_platform_windows_default");
        lib.add(handle, "raia_imgui_begin");
        lib.add(handle, "raia_imgui_end");
        lib.add(handle, "raia_imgui_text");
        lib.add(handle, "raia_imgui_button");
        lib.add(handle, "raia_imgui_image");
        lib.add(handle, "raia_imgui_checkbox");
        lib.add(handle, "raia_imgui_slider_float");
        lib.add(handle, "raia_imgui_color_edit_3");
        lib.add(handle, "raia_imgui_same_line");
        lib.add(handle, "raia_imgui_push_style_var_float");
        lib.add(handle, "raia_imgui_push_style_var_vec2");
        lib.add(handle, "raia_imgui_pop_style_var");
        lib.add(handle, "raia_imgui_push_style_color_u32");
        lib.add(handle, "raia_imgui_push_style_color_vec4");
        lib.add(handle, "raia_imgui_pop_style_color");
        lib.add(handle, "raia_imgui_set_next_window_bg_alpha");
        lib.add(handle, "raia_imgui_separator");
        // 初期化
        lib.call("raia_imgui_check_version");
        lib.call("raia_imgui_create_context");
        globalThis.__RAIA_IMGUI__ = {};
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
        lib.call("raia_imgui_check_version");
    }
    createContext() {
        lib.call("raia_imgui_create_context");
    }
    /**
     * 
     * @param {boolean} flag 
     */
    configViewportsNoAutoMerge(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        lib.call("raia_imgui_config_viewports_no_auto_merge", args);
    }
    /**
     * 
     * @param {boolean} flag 
     */
    configViewportsNoTaskBarIcon(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        lib.call("raia_imgui_config_viewports_no_task_bar_icon", args);
    }
    /**
     * 
     * @param {int} config_flags 
     */
    setConfigFlags(config_flags) {
        var args = JSON.stringify({
            "config_flags": config_flags
        });
        lib.call("raia_imgui_set_config_flags", args);
    }
    /**
     * 
     * @param {real} scale 
     */
    fontGlobalScale(scale) {
        var args = JSON.stringify({
            "scale": scale
        });
        lib.call("raia_imgui_font_global_scale", args);
    }
    /**
     * 
     * @returns {real} framerate
     */
    getFramerate() {
        var ret = lib.call("raia_imgui_get_framerate");
        return JSON.parse(ret).result;
    }
    styleColorsDark() {
        lib.call("raia_imgui_style_colors_dark");
    }
    styleColorsLight() {
        lib.call("raia_imgui_style_colors_light");
    }
    styleColorsClassic() {
        lib.call("raia_imgui_style_colors_classic");
    }
    /**
     * 
     * @param {real} width 
     */
    setStyleWindowBorderSize(width) {
        var args = JSON.stringify({
            "width": width
        });
        lib.call("raia_imgui_set_style_window_border_size", args);
    }
    /**
     * 
     * @param {real} radius 
     */
    setStyleWindowRounding(radius) {
        var args = JSON.stringify({
            "radius": radius
        });
        lib.call("raia_imgui_set_style_window_rounding", args);
    }
    /**
     * 
     * @param {real} scale 
     */
    setStyleScaleAllSizes(scale) {
        var args = JSON.stringify({
            "scale": scale
        });
        lib.call("raia_imgui_set_style_scale_all_sizes", args);
    }
    /**
     * 
     * @param {int} col 
     * @param {real} red 0.0 ~ 1.0
     * @param {real} green 0.0 ~ 1.0
     * @param {real} blue 0.0 ~ 1.0
     * @param {real} alpha 0.0 ~ 1.0
     */
    setStyleColors(col, red, green, blue, alpha) {
        var args = JSON.stringify({
            "col": col,
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        lib.call("raia_imgui_set_style_colors", args);
    }
    /**
     * 
     * @param {uintptr} window_id 
     * @param {boolean} install_callbacks 
     */
    implGlfwInitForOpenGL(window_id, install_callbacks) {
        var args = JSON.stringify({
            "window_id": window_id,
            "install_callbacks": install_callbacks
        });
        lib.call("raia_imgui_impl_glfw_init_for_opengl", args);
    }
    /**
     * 
     * @param {string} glsl_version 
     */
    implOpenGL3Init(glsl_version) {
        var args = JSON.stringify({
            "glsl_version": glsl_version
        });
        lib.call("raia_imgui_impl_opengl3_init", args);
    }
    addFontDefault() {
        lib.call("raia_imgui_add_font_default");
    }
    /**
     * 
     * @returns {uintptr} glyph_ranges
     */
    getGlyphRangesJapanese() {
        var ret = lib.call("raia_imgui_get_glyph_ranges_japanese");
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {string} filename 
     * @param {real} size_pixels 
     * @param {uintptr | null} font_cfg 
     * @param {uintptr | null} glyph_ranges 
     * @returns {uintptr} font
     */
    addFontFromFileTTF(filename, size_pixels, font_cfg = null, glyph_ranges = null) {
        var args = JSON.stringify({
            "filename": filename,
            "size_pixels": size_pixels,
            "font_cfg": font_cfg,
            "glyph_ranges": glyph_ranges
        });
        var ret = lib.call("raia_imgui_add_font_from_file_ttf", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {boolean} expr 
     */
    assert(expr) {
        var args = JSON.stringify({
            "expr": expr
        });
        lib.call("raia_imgui_assert", args);
    }
    /**
     * 
     * @param {uintptr} font 
     */
    setFontDefault(font) {
        var args = JSON.stringify({
            "font": font
        });
        lib.call("raia_imgui_set_font_default", args);
    }
    initFont() {
        lib.call("raia_imgui_init_font");
    }
    implOpenGL3Shutdown() {
        lib.call("raia_imgui_impl_opengl3_shutdown");
    }
    implGlfwShutdown() {
        lib.call("raia_imgui_impl_glfw_shutdown");
    }
    destroyContext() {
        lib.call("raia_imgui_destroy_context");
    }
    implOpenGL3NewFrame() {
        lib.call("raia_imgui_impl_opengl3_new_frame");
    }
    implGlfwNewFrame() {
        lib.call("raia_imgui_impl_glfw_new_frame");
    }
    newFrame() {
        lib.call("raia_imgui_new_frame");
    }
    render() {
        lib.call("raia_imgui_render");
    }
    /**
     * 
     * @returns {uintptr} draw_data
     */
    getDrawData() {
        var ret = lib.call("raia_imgui_get_draw_data");
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uintptr} draw_data 
     */
    implOpenGL3RenderDrawData(draw_data) {
        var args = JSON.stringify({
            "draw_data": draw_data
        });
        lib.call("raia_imgui_impl_opengl3_render_draw_data", args);
    }
    updatePlatformWindows() {
        lib.call("raia_imgui_update_platform_windows");
    }
    renderPlatformWindowsDefault() {
        lib.call("raia_imgui_render_platform_windows_default");
    }
    /**
     * 
     * @param {string} name 
     * @param {uintptr | null} p_open 
     * @param {int} flags 
     */
    begin(name = "Untitled", p_open = null, flags = 0) {
        var args = JSON.stringify({
            "name": name,
            "p_open": p_open,
            "flags": flags
        });
        lib.call("raia_imgui_begin", args);
    }
    end() {
        lib.call("raia_imgui_end");
    }
    /**
     * 
     * @param {string} text 
     */
    text(text) {
        var args = JSON.stringify({
            "text": text
        });
        lib.call("raia_imgui_text", args);
    }
    /**
     * 
     * @param {string} label 
     * @returns {boolean} pressed
     */
    button(label) {
        var args = JSON.stringify({
            "label": label
        });
        var ret = lib.call("raia_imgui_button", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {int} texture_id 
     * @param {real} width 
     * @param {real} height 
     */
    image(texture_id, width, height) {
        var args = JSON.stringify({
            "texture_id": texture_id,
            "width": width,
            "height": height
        });
        lib.call("raia_imgui_image", args);
    }
    /**
     * 
     * @param {string} label 
     * @param {boolean} v 
     * @returns {boolean} checked
     */
    checkbox(label, v) {
        var args = JSON.stringify({
            "label": label,
            "v": v
        });
        var ret = lib.call("raia_imgui_checkbox", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {string} label 
     * @param {real} v 
     * @param {real} v_min 
     * @param {real} v_max 
     * @returns {real} value
     */
    sliderFloat(label, v, v_min, v_max) {
        var args = JSON.stringify({
            "label": label,
            "v": v,
            "v_min": v_min,
            "v_max": v_max
        });
        var ret = lib.call("raia_imgui_slider_float", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {string} label 
     * @param {real} red 
     * @param {real} green 
     * @param {real} blue 
     * @returns {{red: real, gree: real, blue:real}}
     */
    colorEdit3(label, red, green, blue) {
        var args = JSON.stringify({
            "label": label,
            "red": red,
            "green": green,
            "blue": blue
        });
        var ret = lib.call("raia_imgui_color_edit_3", args);
        return JSON.parse(ret);
    }
    sameLine() {
        lib.call("raia_imgui_same_line");
    }
    /**
     * 
     * @param {int} idx 
     * @param {real} val 
     */
    pushStyleVarFloat(idx, val) {
        var args = JSON.stringify({
            "idx": idx,
            "val": val
        });
        lib.call("raia_imgui_push_style_var_float", args);
    }
    /**
     * 
     * @param {int} idx 
     * @param {real} x 
     * @param {real} y 
     */
    pushStyleVarVec2(idx, x, y) {
        var args = JSON.stringify({
            "idx": idx,
            "x": x,
            "y": y
        });
        lib.call("raia_imgui_push_style_var_vec2", args);
    }
    /**
     * 
     * @param {int} count 
     */
    popStyleVar(count) {
        var args = JSON.stringify({
            "count": count
        });
        lib.call("raia_imgui_pop_style_var", args);
    }
    /**
     * 
     * @param {int} idx 
     * @param {uint} col 
     */
    pushStyleColorU32(idx, col) {
        var args = JSON.stringify({
            "idx": idx,
            "col": col
        });
        lib.call("raia_imgui_push_style_color_u32", args);
    }
    /**
     * 
     * @param {int} idx 
     * @param {real} x 
     * @param {real} y 
     * @param {real} z 
     * @param {real} w 
     */
    pushStyleColorVec4(idx, x, y, z, w) {
        var args = JSON.stringify({
            "idx": idx,
            "x": x,
            "y": y,
            "z": z,
            "w": w
        });
        lib.call("raia_imgui_push_style_color_vec4", args);
    }
    /**
     * 
     * @param {int} count 
     */
    popStyleColor(count = 1) {
        var args = JSON.stringify({
            "count": count
        });
        lib.call("raia_imgui_pop_style_color", args);
    }
    /**
     * 
     * @param {real} alpha 
     */
    setNextWindowBgAlpha(alpha = 1.0) {
        var args = JSON.stringify({
            "alpha": alpha
        });
        lib.call("raia_imgui_set_next_window_bg_alpha", args);
    }
    separator() {
        lib.call("raia_imgui_separator");
    }
}