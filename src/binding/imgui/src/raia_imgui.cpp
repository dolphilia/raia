#include "raia_imgui.h"

extern "C" {

void raia_imgui_show_demo_window() {
    ImGui::ShowDemoWindow();
}

void raia_imgui_impl_opengl3_new_frame() {
    ImGui_ImplOpenGL3_NewFrame();
}

void raia_imgui_impl_glfw_new_frame() {
    ImGui_ImplGlfw_NewFrame();
}

void raia_imgui_new_frame() {
    ImGui::NewFrame();
}

bool raia_imgui_check_version() {
    return IMGUI_CHECKVERSION();
}

ImGuiContext* raia_imgui_create_context() {
    return ImGui::CreateContext();
}

ImGuiIO *raia_imgui_getio() {
    return &ImGui::GetIO();
}

void raia_imgui_getio_config_flags(int config_flags) {
    ImGui::GetIO().ConfigFlags = config_flags;
}

void raia_imgui_getio_config_viewports_no_auto_merge(bool flag) {
    ImGui::GetIO().ConfigViewportsNoAutoMerge = flag;
}

void raia_imgui_getio_config_viewports_no_task_bar_icon(bool flag) {
    ImGui::GetIO().ConfigViewportsNoTaskBarIcon = flag;
}

void raia_imgui_getio_font_global_scale(float num) {
    ImGui::GetIO().FontGlobalScale = num;
}

float raia_imgui_getio_get_framerate() {
    return ImGui::GetIO().Framerate;
}

void raia_imgui_style_colors_dark() {
    ImGui::StyleColorsDark();
}

void raia_imgui_style_colors_light() {
    ImGui::StyleColorsLight();
}

void raia_imgui_style_colors_classic() {
    ImGui::StyleColorsClassic();
}

ImGuiStyle *raia_imgui_getstyle() {
    return &ImGui::GetStyle();
}

void raia_imgui_getstyle_window_border_size(float n) {
    ImGui::GetStyle().WindowBorderSize = n;
}

void raia_imgui_getstyle_window_rounding(float n) {
    ImGui::GetStyle().WindowRounding = n;
}

void raia_imgui_getstyle_scale_all_sizes(float n) {
    ImGui::GetStyle().ScaleAllSizes(n);
}

void raia_imgui_set_style_colors(int col, float red, float green, float blue, float alpha) {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[col].x = red;
    style.Colors[col].y = green;
    style.Colors[col].z = blue;
    style.Colors[col].w = alpha;
}

bool raia_imgui_impl_glfw_init_for_opengl(GLFWwindow* window, bool install_callbacks) {
    return ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
}

bool raia_imgui_impl_opengl3_init(const char *glsl_version) {
    return ImGui_ImplOpenGL3_Init(glsl_version); // #version 300 es
}

ImFont* raia_imgui_getio_fonts_add_font_default() {
    return ImGui::GetIO().Fonts->AddFontDefault();
}

const ImWchar *raia_imgui_getio_fonts_get_glyph_ranges_japanese() {
    return ImGui::GetIO().Fonts->GetGlyphRangesJapanese();
}

ImFont *raia_imgui_getio_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges) {
    return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges);
}

void raia_imgui_getio_font_default(ImFont *font) {
    ImGui::GetIO().FontDefault = font;
}

void raia_imgui_assert(bool expr) {
    IM_ASSERT(expr);
}

void raia_imgui_impl_opengl3_shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
}

void raia_imgui_impl_glfw_shutdown() {
    ImGui_ImplGlfw_Shutdown();
}

void raia_imgui_destroy_context() {
    ImGui::DestroyContext();
}

void raia_imgui_render() {
    ImGui::Render();
}

ImDrawData *raia_imgui_get_draw_data() {
    return ImGui::GetDrawData();
}

void raia_imgui_impl_opengl3_render_draw_data(ImDrawData* draw_data) {
    ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}

void raia_imgui_update_platform_windows() {
    ImGui::UpdatePlatformWindows();
}

void raia_imgui_render_platform_windows_default() {
    ImGui::RenderPlatformWindowsDefault();
}

void raia_imgui_begin(const char* name, bool* p_open /* = null */, ImGuiWindowFlags flags /* = 0 */) {
    ImGui::Begin(name, p_open, flags);
}

void raia_imgui_end() {
    ImGui::End();
}

void raia_imgui_text(const char *text) {
    ImGui::Text("%s", text);
}

bool raia_imgui_button(const char *label, float width, float height) {
    return ImGui::Button(label, ImVec2(width, height));
}

void raia_imgui_image(void *texture_id, float width, float height) {
    ImGui::Image(texture_id, ImVec2(width, height));
}

bool raia_imgui_checkbox(const char *label, bool *v) {
    return ImGui::Checkbox(label, v);
}

float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max) {
    return ImGui::SliderFloat(label, v, v_min, v_max);
}

bool raia_imgui_color_edit_3(const char *label, float *col) {
    return ImGui::ColorEdit3(label, col);
}

void raia_imgui_same_line() {
    ImGui::SameLine();
}

void raia_imgui_push_style_var_float(ImGuiStyleVar idx, float val) {
    ImGui::PushStyleVar(idx, val);
}

void raia_imgui_push_style_var_vec2(ImGuiStyleVar idx, float x, float y) {
    ImGui::PushStyleVar(idx, ImVec2(x, y));
}

void raia_imgui_pop_style_var(int count) {
    ImGui::PopStyleVar(count);
}

void raia_imgui_push_style_color_u32(ImGuiCol idx, ImU32 col) {
    ImGui::PushStyleColor(idx, col);
}

void raia_imgui_push_style_color_vec4(ImGuiCol idx, float x, float y, float z, float w) {
    ImGui::PushStyleColor(idx, ImVec4(x, y, z, w));
}

void raia_imgui_pop_style_color(int count) {
    ImGui::PopStyleColor(count);
}

ImGuiViewport* raia_imgui_get_main_viewport() {
    return ImGui::GetMainViewport();
}

void raia_imgui_set_next_window_pos(float pos_x, float pos_y, ImGuiCond cond /* = 0 */, float pivot_x /* = 0 */, float pivot_y /* = 0 */) {
    ImGui::SetNextWindowPos(ImVec2(pos_x, pos_y), cond, ImVec2(pivot_x, pivot_y));
}

void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport) {
    ImGui::SetNextWindowViewport(viewport->ID);
}

void raia_imgui_set_next_window_bg_alpha(float alpha) {
    ImGui::SetNextWindowBgAlpha(alpha);
}

void raia_imgui_separator() {
    ImGui::Separator();
}

}