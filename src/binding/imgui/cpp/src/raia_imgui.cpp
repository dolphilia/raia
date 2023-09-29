#include "raia_imgui.h"

extern "C" {
    
static const char* raia_not_use_s(const char *s) {
    return s;
}
}

extern "C" RAIA_API const char* raia_imgui_impl_opengl3_new_frame(const char *s) {
    ImGui_ImplOpenGL3_NewFrame();
    return nullptr;
}

extern "C" RAIA_API const char* raia_imgui_impl_glfw_new_frame(const char *s) {
    ImGui_ImplGlfw_NewFrame();
    return nullptr;
}

void raia_gui_new_frame() {
    ImGui::NewFrame();
}

extern "C" RAIA_API const char* raia_imgui_new_frame(const char *s) {
    raia_gui_new_frame();
    return nullptr;
}

void _raia_imgui_check_version() {
    IMGUI_CHECKVERSION();
}

extern "C" RAIA_API const char* raia_imgui_check_version(const char *s) {
    _raia_imgui_check_version();
    return nullptr;
}

void _raia_imgui_create_context() {
    ImGui::CreateContext();
}

extern "C" RAIA_API const char* raia_imgui_create_context(const char *s) {
    _raia_imgui_create_context();
    return nullptr;
}

void _raia_imgui_set_config_flags(int config_flags) {
    ImGui::GetIO().ConfigFlags = config_flags;
}

extern "C" RAIA_API const char* raia_imgui_set_config_flags(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int config_flags = joint_get_in_int(joint, "config_flags");
    _raia_imgui_set_config_flags(config_flags);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_config_viewports_no_auto_merge(bool flag) {
    ImGui::GetIO().ConfigViewportsNoAutoMerge = flag;
}

extern "C" RAIA_API const char* raia_imgui_config_viewports_no_auto_merge(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    bool flag = joint_get_in_bool(joint, "flag");
    _raia_imgui_config_viewports_no_auto_merge(flag);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_config_viewports_no_task_bar_icon(bool flag) {
    ImGui::GetIO().ConfigViewportsNoTaskBarIcon = flag;
}

extern "C" RAIA_API const char* raia_imgui_config_viewports_no_task_bar_icon(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    bool flag = joint_get_in_bool(joint, "flag");
    _raia_imgui_config_viewports_no_task_bar_icon(flag);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_font_global_scale(float num) {
    ImGui::GetIO().FontGlobalScale = num;
}

extern "C" RAIA_API const char* raia_imgui_font_global_scale(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double scale = joint_get_in_int_or_real(joint, "scale");
    _raia_imgui_font_global_scale((float)scale);
    joint_free(joint);
    return nullptr;
}

float _raia_imgui_get_framerate() {
    return ImGui::GetIO().Framerate;
}

extern "C" RAIA_API const char* raia_imgui_get_framerate(const char *s) {
    float framerate = _raia_imgui_get_framerate();
    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", framerate);
    return joint_out_write(joint);
}

void _raia_imgui_style_colors_dark() {
    ImGui::StyleColorsDark();
}

extern "C" RAIA_API const char *raia_imgui_style_colors_dark(const char *s) {
    _raia_imgui_style_colors_dark();
    return nullptr;
}

void _raia_imgui_style_colors_light() {
    ImGui::StyleColorsLight();
}

extern "C" RAIA_API const char *raia_imgui_style_colors_light(const char *s) {
    _raia_imgui_style_colors_light();
    return nullptr;
}

void _raia_imgui_style_colors_classic() {
    ImGui::StyleColorsClassic();
}

extern "C" RAIA_API const char *raia_imgui_style_colors_classic(const char *s) {
    _raia_imgui_style_colors_classic();
    return nullptr;
}

void _raia_imgui_set_style_window_border_size(float n) {
    ImGui::GetStyle().WindowBorderSize = n;
}

extern "C" RAIA_API const char* raia_imgui_set_style_window_border_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double width = joint_get_in_int_or_real(joint, "width");
    _raia_imgui_set_style_window_border_size((float)width);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_set_style_window_rounding(float n) {
    ImGui::GetStyle().WindowRounding = n;
}

extern "C" RAIA_API const char* raia_imgui_set_style_window_rounding(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double radius = joint_get_in_int_or_real(joint, "radius");
    _raia_imgui_set_style_window_rounding((float)radius);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_set_style_scale_all_sizes(float n) {
    ImGui::GetStyle().ScaleAllSizes(n);
}

extern "C" RAIA_API const char* raia_imgui_set_style_scale_all_sizes(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double scale = joint_get_in_int_or_real(joint, "scale");
    _raia_imgui_set_style_scale_all_sizes((float)scale);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_set_style_colors(int col, float red, float green, float blue, float alpha) {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[col].x = red;
    style.Colors[col].y = green;
    style.Colors[col].z = blue;
    style.Colors[col].w = alpha;
}

extern "C" RAIA_API const char* raia_imgui_set_style_colors(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int col = joint_get_in_int(joint, "col");
    double red = joint_get_in_int_or_real(joint, "red");
    double green = joint_get_in_int_or_real(joint, "green");
    double blue = joint_get_in_int_or_real(joint, "blue");
    double alpha = joint_get_in_int_or_real(joint, "alpha");
    _raia_imgui_set_style_colors(col, (float)red, (float)green, (float)blue, (float)alpha);
    joint_free(joint);
    return nullptr;
}

extern "C" RAIA_API const char* raia_imgui_impl_glfw_init_for_opengl(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window = (GLFWwindow*)joint_get_in_uint_to_ptr(joint, "window_id");
    bool install_callbacks = joint_get_in_bool(joint, "install_callbacks");
    ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
    joint_free(joint);
    return nullptr;
}

extern "C" RAIA_API const char* raia_imgui_impl_opengl3_init(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *glsl_version = joint_get_in_str(joint, "glsl_version");
    ImGui_ImplOpenGL3_Init(glsl_version); // #version 300 es
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_add_font_default() {
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();
}

extern "C" RAIA_API const char* raia_imgui_add_font_default(const char *s) {
    _raia_imgui_add_font_default();
    return nullptr;
}

const ImWchar *_raia_imgui_get_glyph_ranges_japanese() {
    return ImGui::GetIO().Fonts->GetGlyphRangesJapanese();
}

extern "C" RAIA_API const char* raia_imgui_get_glyph_ranges_japanese(const char *s) {
    const ImWchar *glyph_ranges = _raia_imgui_get_glyph_ranges_japanese();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)glyph_ranges);
    return joint_out_write(joint);
}

ImFont *_raia_imgui_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges) {
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges);
    return font;
}

extern "C" RAIA_API const char* raia_imgui_add_font_from_file_ttf(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *filename = joint_get_in_str(joint, "filename");
    float size_pixels;
    const ImFontConfig *font_cfg;
    const ImWchar *glyph_ranges;
    size_pixels = (float)joint_get_in_int_or_real(joint, "size_pixels");
    font_cfg = (const ImFontConfig *)joint_get_in_uint_to_ptr(joint, "font_cfg");
    glyph_ranges = (const ImWchar *)joint_get_in_uint_to_ptr(joint, "glyph_ranges");
    ImFont *font = _raia_imgui_add_font_from_file_ttf(filename, size_pixels, font_cfg, glyph_ranges);
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)font);
    return joint_out_write(joint);
}

void _raia_imgui_assert(bool expr) {
    IM_ASSERT(expr);
}

extern "C" RAIA_API const char* raia_imgui_assert(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    bool expr = joint_get_in_bool(joint, "expr");
    _raia_imgui_assert(expr);
    joint_free(joint);
    return nullptr;
}

void _raia_imgui_set_font_default(ImFont *font) {
    ImGui::GetIO().FontDefault = font;
}

extern "C" RAIA_API const char* raia_imgui_set_font_default(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    ImFont *font = (ImFont *)joint_get_in_uint_to_ptr(joint, "font");
    _raia_imgui_set_font_default(font);
    joint_free(joint);
    return nullptr;
}

extern "C" RAIA_API const char* raia_imgui_impl_opengl3_shutdown(const char *s) {
    ImGui_ImplOpenGL3_Shutdown();
    return nullptr;
}

extern "C" RAIA_API const char* raia_imgui_impl_glfw_shutdown(const char *s) {
    ImGui_ImplGlfw_Shutdown();
    return nullptr;
}

void _raia_imgui_destroy_context() {
    ImGui::DestroyContext();
}

extern "C" RAIA_API const char* raia_imgui_destroy_context(const char *s) {
    _raia_imgui_destroy_context();
    return nullptr;
}

void _raia_gui_imgui_render() {
    ImGui::Render();
}

extern "C" RAIA_API const char* raia_imgui_render(const char *s) {
    _raia_gui_imgui_render();
    return nullptr;
}

ImDrawData *_raia_imgui_get_draw_data() {
    return ImGui::GetDrawData();
}

extern "C" RAIA_API const char* raia_imgui_get_draw_data(const char *s) {
    ImDrawData *draw_data = _raia_imgui_get_draw_data();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)draw_data);
    return joint_out_write(joint);
}

extern "C" RAIA_API const char* raia_imgui_impl_opengl3_render_draw_data(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    ImDrawData* draw_data = (ImDrawData*)joint_get_in_uint_to_ptr(joint, "draw_data");
    ImGui_ImplOpenGL3_RenderDrawData(draw_data);
    joint_free(joint);
    return nullptr;
}

void _imgui_update_platform_windows() {
    ImGui::UpdatePlatformWindows();
}

extern "C" RAIA_API const char* raia_imgui_update_platform_windows(const char *s) {
    _imgui_update_platform_windows();
    return nullptr;
}

void _imgui_render_platform_windows_default() {
    ImGui::RenderPlatformWindowsDefault();
}

extern "C" RAIA_API const char* raia_imgui_render_platform_windows_default(const char *s) {
    _imgui_render_platform_windows_default();
    return nullptr;
}

void _raia_gui_imgui_begin(const char* name, bool* p_open = nullptr, ImGuiWindowFlags flags = 0) {
    ImGui::Begin(name, p_open, flags);
}

extern "C" RAIA_API const char* raia_imgui_begin(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* name = joint_get_in_str(joint, "name");
    bool* p_open;
    if(joint_is_in_null(joint, "p_open")) {
        p_open = nullptr;
    } else {
        p_open = (bool*)joint_get_in_uint_to_ptr(joint, "p_open");
    }
    ImGuiWindowFlags flags = joint_get_in_int(joint, "flags");
    _raia_gui_imgui_begin(name, p_open, flags);
    joint_free(joint);
    return nullptr;
}

void _raia_gui_imgui_end() {
    ImGui::End();
}

extern "C" RAIA_API const char* raia_imgui_end(const char *s) {
    _raia_gui_imgui_end();
    return nullptr;
}

void _raia_imgui_text(const char *text) {
    ImGui::Text("%s", text);
}

extern "C" RAIA_API const char* raia_imgui_text(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* text = joint_get_in_str(joint, "text");
    _raia_imgui_text(text);
    joint_free(joint);
    return nullptr;
}

bool _raia_imgui_button(const char *label) {
    return ImGui::Button(label);
}

extern "C" RAIA_API const char* raia_imgui_button(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* label = joint_get_in_str(joint, "label");
    bool result = _raia_imgui_button(label);
    joint_add_out_bool(joint, "result", result);
    return joint_out_write(joint);
}

void _raia_imgui_image(int texture_id, float width, float height) {
    ImGui::Image((void*)(intptr_t)texture_id, ImVec2(width, height));
}

extern "C" RAIA_API const char* raia_imgui_image(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int texture_id = joint_get_in_int(joint, "texture_id");
    double width = joint_get_in_int_or_real(joint, "width");
    double height = joint_get_in_int_or_real(joint, "height");
    _raia_imgui_image(texture_id, (float)width, (float)height);
    joint_free(joint);
    return nullptr;
}

bool _raia_imgui_checkbox(const char *label, bool v) {
    ImGui::Checkbox(label, &v);
    return v;
}

extern "C" RAIA_API const char* raia_imgui_checkbox(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *label = joint_get_in_str(joint, "label");
    bool v = joint_get_in_bool(joint, "v");
    bool result = _raia_imgui_checkbox(label, v);
    joint_add_out_bool(joint, "result", result);
    return joint_out_write(joint);
}

float _raia_imgui_slider_float(const char *label, float v, float v_min, float v_max) {
    ImGui::SliderFloat(label, &v, v_min, v_max);
    return v;
}

extern "C" RAIA_API const char* raia_imgui_slider_float(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *label = joint_get_in_str(joint, "label");
    double v = joint_get_in_int_or_real(joint, "v");
    double v_min = joint_get_in_int_or_real(joint, "v_min");
    double v_max = joint_get_in_int_or_real(joint, "v_max");
    float result = _raia_imgui_slider_float(label, (float)v, (float)v_min, (float)v_max);
    joint_add_out_real(joint, "result", result);
    return joint_out_write(joint);
}

ImVec4 _raia_imgui_color_edit_3(const char *label, ImVec4 col) {
    ImGui::ColorEdit3(label, (float *)&col);
    return col;
}

extern "C" RAIA_API const char* raia_imgui_color_edit_3(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *label = joint_get_in_str(joint, "label");
    double red = joint_get_in_int_or_real(joint, "red");
    double green = joint_get_in_int_or_real(joint, "green");
    double blue = joint_get_in_int_or_real(joint, "blue");
    ImVec4 col = ImVec4((float)red, (float)green, (float)blue, 1.0f);
    col = _raia_imgui_color_edit_3(label, col);
    joint_add_out_real(joint, "red", col.x);
    joint_add_out_real(joint, "green", col.y);
    joint_add_out_real(joint, "blue", col.z);
    return joint_out_write(joint);
}

void _raia_imgui_same_line() {
    ImGui::SameLine();
}

extern "C" RAIA_API const char* raia_imgui_same_line(const char *s) {
    _raia_imgui_same_line();
    return NULL;
}

void _raia_imgui_push_style_var_float(ImGuiStyleVar idx, float val) {
    ImGui::PushStyleVar(idx, val);
}

extern "C" RAIA_API const char* raia_imgui_push_style_var_float(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int idx = joint_get_in_int(joint, "idx");
    double val = joint_get_in_int_or_real(joint, "val");
    _raia_imgui_push_style_var_float(idx, (float)val);
    joint_free(joint);
    return NULL;
}

void _raia_imgui_push_style_var_vec2(ImGuiStyleVar idx, ImVec2 val) {
    ImGui::PushStyleVar(idx, val);
}

extern "C" RAIA_API const char* raia_imgui_push_style_var_vec2(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int idx = joint_get_in_int(joint, "idx");
    double x = joint_get_in_int_or_real(joint, "x");
    double y = joint_get_in_int_or_real(joint, "y");
    _raia_imgui_push_style_var_vec2(idx, ImVec2((float)x, (float)y));
    joint_free(joint);
    return NULL;
}

void _raia_imgui_pop_style_var(int count) {
    ImGui::PopStyleVar(count);
}

extern "C" RAIA_API const char* raia_imgui_pop_style_var(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int count = joint_get_in_int(joint, "count");
    _raia_imgui_pop_style_var(count);
    joint_free(joint);
    return NULL;
}

void _raia_imgui_push_style_color_u32(ImGuiCol idx, ImU32 col) {
    ImGui::PushStyleColor(idx, col);
}

extern "C" RAIA_API const char* raia_imgui_push_style_color_u32(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int idx = joint_get_in_int(joint, "idx");
    ImU32 col = joint_get_in_uint(joint, "col");
    _raia_imgui_push_style_color_u32(idx, col);
    joint_free(joint);
    return NULL;
}

void _raia_imgui_push_style_color_vec4(ImGuiCol idx, const ImVec4 col) {
    ImGui::PushStyleColor(idx, col);
}

extern "C" RAIA_API const char* raia_imgui_push_style_color_vec4(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int idx = joint_get_in_int(joint, "idx");
    double x = joint_get_in_int_or_real(joint, "x");
    double y = joint_get_in_int_or_real(joint, "y");
    double z = joint_get_in_int_or_real(joint, "z");
    double w = joint_get_in_int_or_real(joint, "w");
    _raia_imgui_push_style_color_vec4(idx, ImVec4((float)x, (float)y, (float)z, (float)w));
    joint_free(joint);
    return NULL;
}

void _raia_imgui_pop_style_color(int count) {
    ImGui::PopStyleColor(count);
}

extern "C" RAIA_API const char* raia_imgui_pop_style_color(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int count = joint_get_in_int(joint, "count");
    _raia_imgui_pop_style_color(count);
    joint_free(joint);
    return NULL;
}

ImGuiViewport* _raia_imgui_get_main_viewport() {
    return ImGui::GetMainViewport();
}

extern "C" RAIA_API const char* raia_imgui_get_main_viewport(const char *s) {
    const ImGuiViewport* viewport = _raia_imgui_get_main_viewport();
    joint_t* joint = joint_init_out();
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)viewport);
    return joint_out_write(joint);
}

void _raia_imgui_set_next_window_pos(const ImVec2 &pos, ImGuiCond cond = 0, const ImVec2 &pivot = ImVec2(0, 0)) {
    ImGui::SetNextWindowPos(pos, cond, pivot);
}

extern "C" RAIA_API const char* raia_imgui_set_next_window_pos(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double pos_x = joint_get_in_int_or_real(joint, "pos_x");
    double pos_y = joint_get_in_int_or_real(joint, "pos_y");
    int cond = joint_get_in_int(joint, "cond");
    double pivot_x = joint_get_in_int_or_real(joint, "pivot_x");
    double pivot_y = joint_get_in_int_or_real(joint, "pivot_y");
    _raia_imgui_set_next_window_pos(ImVec2((float)pos_x, (float)pos_y), cond, ImVec2((float)pivot_x, (float)pivot_y));
    joint_free(joint);
    return NULL;
}

void _raia_imgui_set_next_window_viewport(ImGuiViewport* viewport) {
    ImGui::SetNextWindowViewport(viewport->ID);
}

extern "C" RAIA_API const char* raia_imgui_set_next_window_viewport(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    ImGuiViewport* viewport = (ImGuiViewport*)joint_get_in_uint_to_ptr(joint, "viewport");
    _raia_imgui_set_next_window_viewport(viewport);
    joint_free(joint);
    return NULL;
}

void _raia_imgui_set_next_window_bg_alpha(float alpha) {
    ImGui::SetNextWindowBgAlpha(alpha);
}

extern "C" RAIA_API const char* raia_imgui_set_next_window_bg_alpha(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double alpha = joint_get_in_int_or_real(joint, "alpha");
    _raia_imgui_set_next_window_bg_alpha((float)alpha);
    joint_free(joint);
    return NULL;
}

void _raia_imgui_separator() {
    ImGui::Separator();
}

extern "C" RAIA_API const char* raia_imgui_separator(const char *s) {
    _raia_imgui_separator();
    return NULL;
}

void dammy() {}
