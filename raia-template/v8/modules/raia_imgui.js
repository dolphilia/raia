(function() {
    if (globalThis.__Raia__.ImGui === undefined) {
        var handle = __Raia__.Lib.open("raia_imgui");
        __Raia__.Lib.add(handle, "raia_imgui_check_version");
        __Raia__.Lib.add(handle, "raia_imgui_create_context");
        __Raia__.Lib.add(handle, "raia_imgui_set_config_flags");
        __Raia__.Lib.add(handle, "raia_imgui_config_viewports_no_auto_merge");
        __Raia__.Lib.add(handle, "raia_imgui_config_viewports_no_task_bar_icon");
        __Raia__.Lib.add(handle, "raia_imgui_font_global_scale");
        __Raia__.Lib.add(handle, "raia_imgui_get_framerate");
        __Raia__.Lib.add(handle, "raia_imgui_style_colors_dark");
        __Raia__.Lib.add(handle, "raia_imgui_style_colors_light");
        __Raia__.Lib.add(handle, "raia_imgui_style_colors_classic");
        __Raia__.Lib.add(handle, "raia_imgui_set_style_window_border_size");
        __Raia__.Lib.add(handle, "raia_imgui_set_style_window_rounding");
        __Raia__.Lib.add(handle, "raia_imgui_set_style_scale_all_sizes");
        __Raia__.Lib.add(handle, "raia_imgui_set_style_colors");
        __Raia__.Lib.add(handle, "raia_imgui_col_window_bg");
        __Raia__.Lib.add(handle, "raia_imgui_col_text");
        __Raia__.Lib.add(handle, "raia_imgui_impl_glfw_init_for_opengl");
        __Raia__.Lib.add(handle, "raia_imgui_impl_opengl3_init");
        __Raia__.Lib.add(handle, "raia_imgui_add_font_default");
        __Raia__.Lib.add(handle, "raia_imgui_get_glyph_ranges_japanese");
        __Raia__.Lib.add(handle, "raia_imgui_add_font_from_file_ttf");
        __Raia__.Lib.add(handle, "raia_imgui_assert");
        __Raia__.Lib.add(handle, "raia_imgui_set_font_default");
        __Raia__.Lib.add(handle, "raia_imgui_init_font");
        __Raia__.Lib.add(handle, "raia_imgui_impl_opengl3_shutdown");
        __Raia__.Lib.add(handle, "raia_imgui_impl_glfw_shutdown");
        __Raia__.Lib.add(handle, "raia_imgui_destroy_context");
        __Raia__.Lib.add(handle, "raia_imgui_impl_opengl3_new_frame");
        __Raia__.Lib.add(handle, "raia_imgui_impl_glfw_new_frame");
        __Raia__.Lib.add(handle, "raia_imgui_new_frame");
        __Raia__.Lib.add(handle, "raia_imgui_render");
        __Raia__.Lib.add(handle, "raia_imgui_get_draw_data");
        __Raia__.Lib.add(handle, "raia_imgui_impl_opengl3_render_draw_data");
        __Raia__.Lib.add(handle, "raia_imgui_update_platform_windows");
        __Raia__.Lib.add(handle, "raia_imgui_render_platform_windows_default");
        __Raia__.Lib.add(handle, "raia_imgui_begin");
        __Raia__.Lib.add(handle, "raia_imgui_end");
        __Raia__.Lib.add(handle, "raia_imgui_text");
        __Raia__.Lib.add(handle, "raia_imgui_button");
        __Raia__.Lib.add(handle, "raia_imgui_image");
        __Raia__.Lib.add(handle, "raia_imgui_checkbox");
        __Raia__.Lib.add(handle, "raia_imgui_slider_float");
        __Raia__.Lib.add(handle, "raia_imgui_color_edit_3");
        __Raia__.Lib.add(handle, "raia_imgui_same_line");
        globalThis.__Raia__.ImGui = {};
    }
})();

export class ImGui {
    static ConfigFlags = {
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
    static Col = { // enum
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
    constructor() {
    }
    checkVersion() {
        __Raia__.Lib.call("raia_imgui_check_version", "");
    }
    createContext() {
        __Raia__.Lib.call("raia_imgui_create_context", "");
    }
    configViewportsNoAutoMerge(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        __Raia__.Lib.call("raia_imgui_config_viewports_no_auto_merge", args);
    }
    configViewportsNoTaskBarIcon(flag) {
        var args = JSON.stringify({
            "flag": flag
        });
        __Raia__.Lib.call("raia_imgui_config_viewports_no_task_bar_icon", args);
    }
    setConfigFlags(config_flags) {
        var args = JSON.stringify({
            "config_flags": config_flags
        });
        __Raia__.Lib.call("raia_imgui_set_config_flags", args);
    }
    fontGlobalScale(num) {
        var args = JSON.stringify({
            "num": num
        });
        __Raia__.Lib.call("raia_imgui_font_global_scale", args);
    }
    getFramerate() {
        var ret = __Raia__.Lib.call("raia_imgui_get_framerate", "");
        return JSON.parse(ret).result;
    }
    styleColorsDark() {
        __Raia__.Lib.call("raia_imgui_style_colors_dark", "");
    }
    styleColorsLight() {
        __Raia__.Lib.call("raia_imgui_style_colors_light", "");
    }
    styleColorsClassic() {
        __Raia__.Lib.call("raia_imgui_style_colors_classic", "");
    }
    setStyleWindowBorderSize(num) {
        var args = JSON.stringify({
            "num": num
        });
        __Raia__.Lib.call("raia_imgui_set_style_window_border_size", args);
    }
    setStyleWindowRounding(num) {
        var args = JSON.stringify({
            "num": num
        });
        __Raia__.Lib.call("raia_imgui_set_style_window_rounding", args);
    }
    setStyleScaleAllSizes(num) {
        var args = JSON.stringify({
            "num": num
        });
        __Raia__.Lib.call("raia_imgui_set_style_scale_all_sizes", args);
    }
    setStyleColors(col, red, green, blue, alpha) {
        var args = JSON.stringify({
            "col": col,
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        __Raia__.Lib.call("raia_imgui_set_style_colors", args);
    }
    implGlfwInitForOpenGL(window_id, install_callbacks) {
        var args = JSON.stringify({
            "window_id": window_id,
            "install_callbacks": install_callbacks
        });
        __Raia__.Lib.call("raia_imgui_impl_glfw_init_for_opengl", args);
    }
    implOpenGL3Init(glsl_version) {
        var args = JSON.stringify({
            "glsl_version": glsl_version
        });
        __Raia__.Lib.call("raia_imgui_impl_opengl3_init", args);
    }
    addFontDefault() {
        __Raia__.Lib.call("raia_imgui_add_font_default", "");
    }
    getGlyphRangesJapanese() {
        var ret = __Raia__.Lib.call("raia_imgui_get_glyph_ranges_japanese", "");
        return JSON.parse(ret).result;
    }
    addFontFromFileTTF(filename, size_pixels, font_cfg = null, glyph_ranges = null) {
        var args = JSON.stringify({
            "filename": filename,
            "size_pixels": size_pixels,
            "font_cfg": font_cfg,
            "glyph_ranges": glyph_ranges
        });
        var ret = __Raia__.Lib.call("raia_imgui_add_font_from_file_ttf", args);
        return JSON.parse(ret).result;
    }
    assert(expr) {
        var args = JSON.stringify({
            "expr": expr
        });
        __Raia__.Lib.call("raia_imgui_assert", args);
    }
    setFontDefault(font) {
        var args = JSON.stringify({
            "font": font
        });
        __Raia__.Lib.call("raia_imgui_set_font_default", args);
    }

    initFont() {
        __Raia__.Lib.call("raia_imgui_init_font", "");
    }
    implOpenGL3Shutdown() {
        __Raia__.Lib.call("raia_imgui_impl_opengl3_shutdown", "");
    }
    implGlfwShutdown() {
        __Raia__.Lib.call("raia_imgui_impl_glfw_shutdown", "");
    }
    destroyContext() {
        __Raia__.Lib.call("raia_imgui_destroy_context", "");
    }
    implOpenGL3NewFrame() {
        __Raia__.Lib.call("raia_imgui_impl_opengl3_new_frame", "");
    }
    implGlfwNewFrame() {
        __Raia__.Lib.call("raia_imgui_impl_glfw_new_frame", "");
    }
    newFrame() {
        __Raia__.Lib.call("raia_imgui_new_frame", "");
    }
    render() {
        __Raia__.Lib.call("raia_imgui_render", "");
    }
    getDrawData() {
        var ret = __Raia__.Lib.call("raia_imgui_get_draw_data", "");
        return JSON.parse(ret).result;
    }
    implOpenGL3RenderDrawData(draw_data) {
        var args = JSON.stringify({
            "draw_data": draw_data
        });
        __Raia__.Lib.call("raia_imgui_impl_opengl3_render_draw_data", args);
    }
    updatePlatformWindows() {
        __Raia__.Lib.call("raia_imgui_update_platform_windows", "");
    }
    renderPlatformWindowsDefault() {
        __Raia__.Lib.call("raia_imgui_render_platform_windows_default", "");
    }
    begin(name = "Untitled") {
        var args = JSON.stringify({
            "name": name
        });
        __Raia__.Lib.call("raia_imgui_begin", args);
    }
    end() {
        __Raia__.Lib.call("raia_imgui_end", "");
    }
    text(text) {
        var args = JSON.stringify({
            "text": text
        });
        __Raia__.Lib.call("raia_imgui_text", args);
    }
    button(label) {
        var args = JSON.stringify({
            "label": label
        });
        var ret = __Raia__.Lib.call("raia_imgui_button", args);
        return JSON.parse(ret).result;
    }
    image(texture_id, width, height) {
        var args = JSON.stringify({
            "texture_id": texture_id,
            "width": width,
            "height": height
        });
        __Raia__.Lib.call("raia_imgui_image", args);
    }
    checkbox(label, v) {
        var args = JSON.stringify({
            "label": label,
            "v": v
        });
        var ret = __Raia__.Lib.call("raia_imgui_checkbox", args);
        return JSON.parse(ret).result;
    }
    sliderFloat(label, v, v_min, v_max) {
        var args = JSON.stringify({
            "label": label,
            "v": v,
            "v_min": v_min,
            "v_max": v_max
        });
        var ret = __Raia__.Lib.call("raia_imgui_slider_float", args);
        return JSON.parse(ret).result;
    }
    colorEdit3(label, red, green, blue) {
        var args = JSON.stringify({
            "label": label,
            "red": red,
            "green": green,
            "blue": blue
        });
        var ret = __Raia__.Lib.call("raia_imgui_color_edit_3", args);
        return JSON.parse(ret);
    }
    sameLine() {
        __Raia__.Lib.call("raia_imgui_same_line", "");
    }
}