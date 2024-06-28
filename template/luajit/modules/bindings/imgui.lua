local ffi = require("ffi")

ffi.cdef[[
    void raia_imgui_show_demo_window();
    void raia_imgui_impl_opengl3_new_frame();
    void raia_imgui_impl_glfw_new_frame();
    void raia_imgui_new_frame();
    bool raia_imgui_check_version();
    void *raia_imgui_create_context();
    void *raia_imgui_getio();
    void raia_imgui_getio_config_flags(int config_flags);
    void raia_imgui_getio_config_viewports_no_auto_merge(bool flag);
    void raia_imgui_getio_config_viewports_no_task_bar_icon(bool flag);
    void raia_imgui_getio_font_global_scale(float num);
    float raia_imgui_getio_get_framerate();
    void raia_imgui_style_colors_dark();
    void raia_imgui_style_colors_light();
    void raia_imgui_style_colors_classic();
    void *raia_imgui_getstyle();
    void raia_imgui_getstyle_window_border_size(float n);
    void raia_imgui_getstyle_window_rounding(float n);
    void raia_imgui_getstyle_scale_all_sizes(float n);
    void raia_imgui_set_style_colors(int col, float red, float green, float blue, float alpha);
    bool raia_imgui_impl_glfw_init_for_opengl(void* window, bool install_callbacks);
    bool raia_imgui_impl_opengl3_init(const char *glsl_version);
    void* raia_imgui_getio_fonts_add_font_default();
    const void *raia_imgui_getio_fonts_get_glyph_ranges_japanese();
    void *raia_imgui_getio_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const void *font_cfg, const void *glyph_ranges);
    void raia_imgui_getio_font_default(void *font);
    void raia_imgui_assert(bool expr);
    void raia_imgui_impl_opengl3_shutdown();
    void raia_imgui_impl_glfw_shutdown();
    void raia_imgui_destroy_context();
    void raia_imgui_render();
    void *raia_imgui_get_draw_data();
    void raia_imgui_impl_opengl3_render_draw_data(void* draw_data);
    void raia_imgui_update_platform_windows();
    void raia_imgui_render_platform_windows_default();
    void raia_imgui_begin(const char* name, bool* p_open, int flags);
    void raia_imgui_end();
    void raia_imgui_text(const char *text);
    bool raia_imgui_button(const char *label, float width, float height);
    void raia_imgui_image(void *texture_id, float width, float height);
    bool raia_imgui_checkbox(const char *label, bool *v);
    float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max);
    bool raia_imgui_color_edit_3(const char *label, float *col);
    void raia_imgui_same_line();
    void raia_imgui_push_style_var_float(int idx, float val);
    void raia_imgui_push_style_var_vec2(int idx, float x, float y);
    void raia_imgui_pop_style_var(int count);
    void raia_imgui_push_style_color_u32(int idx, unsigned int col);
    void raia_imgui_push_style_color_vec4(int idx, float x, float y, float z, float w);
    void raia_imgui_pop_style_color(int count);
    void* raia_imgui_get_main_viewport();
    void raia_imgui_set_next_window_pos(float pos_x, float pos_y, int cond, float pivot_x, float pivot_y);
    void raia_imgui_set_next_window_viewport(void* viewport);
    void raia_imgui_set_next_window_bg_alpha(float alpha);
    void raia_imgui_separator();
]]

local lib = ffi.load("libraia_imgui")
local ImGui = {}
local bit = require("bit")

ImGui.ConfigFlags = {
    None                    = 0,
    NavEnableKeyboard       = bit.lshift(1, 0),
    NavEnableGamepad        = bit.lshift(1, 1),
    NavEnableSetMousePos    = bit.lshift(1, 2),
    NavNoCaptureKeyboard    = bit.lshift(1, 3),
    NoMouse                 = bit.lshift(1, 4),
    NoMouseCursorChange     = bit.lshift(1, 5),
    DockingEnable           = bit.lshift(1, 6),
    ViewportsEnable         = bit.lshift(1, 10),
    DpiEnableScaleViewports = bit.lshift(1, 14),
    DpiEnableScaleFonts     = bit.lshift(1, 15),
    IsSRGB                  = bit.lshift(1, 20),
    IsTouchScreen           = bit.lshift(1, 21),
}

ImGui.Col = { -- enum
    Text                  = 0,
    TextDisabled          = 1,
    WindowBg              = 2,
    ChildBg               = 3,
    PopupBg               = 4,
    Border                = 5,
    BorderShadow          = 6,
    FrameBg               = 7,
    FrameBgHovered        = 8,
    FrameBgActive         = 9,
    TitleBg               = 10,
    TitleBgActive         = 11,
    TitleBgCollapsed      = 12,
    MenuBarBg             = 13,
    ScrollbarBg           = 14,
    ScrollbarGrab         = 15,
    ScrollbarGrabHovered  = 16,
    ScrollbarGrabActive   = 17,
    CheckMark             = 18,
    SliderGrab            = 19,
    SliderGrabActive      = 20,
    Button                = 21,
    ButtonHovered         = 22,
    ButtonActive          = 23,
    Header                = 24,
    HeaderHovered         = 25,
    HeaderActive          = 26,
    Separator             = 27,
    SeparatorHovered      = 28,
    SeparatorActive       = 29,
    ResizeGrip            = 30,
    ResizeGripHovered     = 31,
    ResizeGripActive      = 32,
    Tab                   = 33,
    TabHovered            = 34,
    TabActive             = 35,
    TabUnfocused          = 36,
    TabUnfocusedActive    = 37,
    DockingPreview        = 38,
    DockingEmptyBg        = 39,
    PlotLines             = 40,
    PlotLinesHovered      = 41,
    PlotHistogram         = 42,
    PlotHistogramHovered  = 43,
    TableHeaderBg         = 44,
    TableBorderStrong     = 45,
    TableBorderLight      = 46,
    TableRowBg            = 47,
    TableRowBgAlt         = 48,
    TextSelectedBg        = 49,
    DragDropTarget        = 40,
    NavHighlight          = 51,
    NavWindowingHighlight = 52,
    NavWindowingDimBg     = 53,
    ModalWindowDimBg      = 54,
    COUNT                 = 55
}

ImGui.WindowFlags = {
    None                     = 0,
    NoTitleBar               = bit.lshift(1, 0),
    NoResize                 = bit.lshift(1, 1),
    NoMove                   = bit.lshift(1, 2),
    NoScrollbar              = bit.lshift(1, 3),
    NoScrollWithMouse        = bit.lshift(1, 4),
    NoCollapse               = bit.lshift(1, 5),
    AlwaysAutoResize         = bit.lshift(1, 6),
    NoBackground             = bit.lshift(1, 7),
    NoSavedSettings          = bit.lshift(1, 8),
    NoMouseInputs            = bit.lshift(1, 9),
    MenuBar                  = bit.lshift(1, 10),
    HorizontalScrollbar      = bit.lshift(1, 11),
    NoFocusOnAppearing       = bit.lshift(1, 12),
    NoBringToFrontOnFocus    = bit.lshift(1, 13),
    AlwaysVerticalScrollbar  = bit.lshift(1, 14),
    AlwaysHorizontalScrollbar= bit.lshift(1, 15),
    AlwaysUseWindowPadding   = bit.lshift(1, 16),
    NoNavInputs              = bit.lshift(1, 18),
    NoNavFocus               = bit.lshift(1, 19),
    UnsavedDocument          = bit.lshift(1, 20),
    NoDocking                = bit.lshift(1, 21),
}

ImGui.WindowFlags.NoNav        = bit.bor(ImGui.WindowFlags.NoNavInputs, ImGui.WindowFlags.NoNavFocus)
ImGui.WindowFlags.NoDecoration = bit.bor(ImGui.WindowFlags.NoTitleBar, ImGui.WindowFlags.NoResize, ImGui.WindowFlags.NoScrollbar, ImGui.WindowFlags.NoCollapse)
ImGui.WindowFlags.NoInputs     = bit.bor(ImGui.WindowFlags.NoMouseInputs, ImGui.WindowFlags.NoNavInputs, ImGui.WindowFlags.NoNavFocus)

-- demo

function ImGui.showDemoWindow()
    lib.raia_imgui_show_demo_window()
end

-- impl GLFW

function ImGui.newFrameImplGLFW()
    lib.raia_imgui_impl_glfw_new_frame()
end

function ImGui.initForOpenGLImplGLFW(window, install_callbacks)
    return lib.raia_imgui_impl_glfw_init_for_opengl(window, install_callbacks)
end

function ImGui.shutdownImplGLFW()
    lib.raia_imgui_impl_glfw_shutdown()
end

-- impl OpenGL3

function ImGui.newFrameImplOpenGL3()
    lib.raia_imgui_impl_opengl3_new_frame()
end

function ImGui.initImplOpenGL3(glsl_version)
    return lib.raia_imgui_impl_opengl3_init(glsl_version)
end

function ImGui.shutdownImplOpenGL3()
    lib.raia_imgui_impl_opengl3_shutdown()
end

function ImGui.renderDrawDataImplOpenGL3(draw_data)
    lib.raia_imgui_impl_opengl3_render_draw_data(draw_data)
end

--

function ImGui.newFrame()
    lib.raia_imgui_new_frame()
end

function ImGui.checkVersion()
    return lib.raia_imgui_check_version()
end

function ImGui.createContext()
    return lib.raia_imgui_create_context()
end

-- GetIO().

function ImGui.getIO()
    return lib.raia_imgui_getio()
end

function ImGui.getIO_configFlags(config_flags)
    lib.raia_imgui_getio_config_flags(config_flags)
end

function ImGui.getIO_configViewportsNoAutoMerge(flag)
    lib.raia_imgui_getio_config_viewports_no_auto_merge(flag)
end

function ImGui.getIO_configViewportsNoTaskBarIcon(flag)
    lib.raia_imgui_getio_config_viewports_no_task_bar_icon(flag)
end

function ImGui.getIO_fontGlobalScale(num)
    lib.raia_imgui_getio_font_global_scale(num)
end

function ImGui.getIO_getFramerate()
    return lib.raia_imgui_getio_get_framerate()
end

function ImGui.getIO_Fonts_addFontDefault()
    return lib.raia_imgui_getio_fonts_add_font_default()
end

function ImGui.getIO_Fonts_getGlyphRangesJapanese()
    return lib.raia_imgui_getio_fonts_get_glyph_ranges_japanese()
end

function ImGui.getIO_Fonts_addFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges)
    return lib.raia_imgui_getio_fonts_add_font_from_file_ttf(filename, size_pixels, font_cfg, glyph_ranges)
end

function ImGui.getIO_fontDefault(font)
    lib.raia_imgui_getio_font_default(font)
end

-- GetStyle().

function ImGui.getStyle()
    return lib.raia_imgui_getstyle()
end

function ImGui.getStyle_windowBorderSize(n)
    lib.raia_imgui_getstyle_window_border_size(n)
end

function ImGui.getStyle_windowRounding(n)
    lib.raia_imgui_getstyle_window_rounding(n)
end

function ImGui.getStyle_scaleAllSizes(n)
    lib.raia_imgui_getstyle_scale_all_sizes(n)
end

function ImGui.setStyleColors(col, red, green, blue, alpha)
    lib.raia_imgui_set_style_colors(col, red, green, blue, alpha)
end

function ImGui.styleColorsDark()
    lib.raia_imgui_style_colors_dark()
end

function ImGui.styleColorsLight()
    lib.raia_imgui_style_colors_light()
end

function ImGui.styleColorsClassic()
    lib.raia_imgui_style_colors_classic()
end

function ImGui.assert(expr)
    lib.raia_imgui_assert(expr)
end

function ImGui.destroyContext()
    lib.raia_imgui_destroy_context()
end

function ImGui.render()
    lib.raia_imgui_render()
end

function ImGui.getDrawData()
    return lib.raia_imgui_get_draw_data()
end

function ImGui.updatePlatformWindows()
    lib.raia_imgui_update_platform_windows()
end

function ImGui.renderPlatformWindowsDefault()
    lib.raia_imgui_render_platform_windows_default()
end

function ImGui.Begin(name, p_open, flags)
    p_open = p_open or nil
    flags = flags or 0
    lib.raia_imgui_begin(name, p_open, flags)
end

function ImGui.End()
    lib.raia_imgui_end()
end

function ImGui.text(text)
    lib.raia_imgui_text(text)
end

function ImGui.button(label, width, height)
    return lib.raia_imgui_button(label, width, height)
end

function ImGui.image(texture_id, width, height)
    raia_imgui_image(texture_id, width, height)
end

function ImGui.checkbox(label, v)
    return lib.raia_imgui_checkbox(label, v)
end

function ImGui.sliderFloat(label, v, v_min, v_max)
    return lib.raia_imgui_slider_float(label, v, v_min, v_max)
end

function ImGui.colorEdit3(label, col)
    return lib.raia_imgui_color_edit_3(label, col)
end

function ImGui.sameLine()
    lib.raia_imgui_same_line()
end

function ImGui.pushStyleVarFloat(idx, val)
    lib.raia_imgui_push_style_var_float(idx, val)
end

function ImGui.pushStyleVarVec2(idx, x, y)
    lib.raia_imgui_push_style_var_vec2(idx, x, y)
end

function ImGui.popStyleVar(count)
    lib.raia_imgui_pop_style_var(count)
end

function ImGui.pushStyleColorU32(idx, col)
    lib.raia_imgui_push_style_color_u32(idx, col)
end

function ImGui.pushStyleColorVec4(idx, x, y, z, w)
    lib.raia_imgui_push_style_color_vec4(idx, x, y, z, w)
end

function ImGui.popStyleColor(count)
    lib.raia_imgui_pop_style_color(count)
end

function ImGui.getMainViewport()
    return lib.raia_imgui_get_main_viewport()
end

function ImGui.setNextWindowPos(pos_x, pos_y, cond, pivot_x, pivot_y)
    return raia_imgui_set_next_window_pos(pos_x, pos_y, cond, pivot_x, pivot_y)
end

function ImGui.setNextWindowViewport(viewport)
    return raia_imgui_set_next_window_viewport(viewport)
end

function ImGui.setNextWindowBgAlpha(alpha)
    return raia_imgui_set_next_window_bg_alpha(alpha)
end

function ImGui.separator()
    return raia_imgui_separator()
end

return ImGui