#include "raia_imgui.h"

extern "C" {

// ヘルパーマクロ

void raia_imgui_assert(bool expr) {
    IM_ASSERT(expr);
}

bool raia_imgui_check_version() {
    return IMGUI_CHECKVERSION();
}

// コンテキストの作成とアクセス

ImGuiContext* raia_imgui_create_context(ImFontAtlas* shared_font_atlas) {
    return ImGui::CreateContext(shared_font_atlas);
}

void raia_imgui_destroy_context(ImGuiContext* ctx) {
    ImGui::DestroyContext();
}

ImGuiContext* raia_imgui_get_current_context() {
    return ImGui::GetCurrentContext();
}

void raia_imgui_set_current_context(ImGuiContext* ctx) {
    ImGui::SetCurrentContext(ctx);
}

// メイン

ImGuiIO *raia_imgui_getio() {
    return &ImGui::GetIO();
}

ImGuiStyle *raia_imgui_getstyle() {
    return &ImGui::GetStyle();
}

void raia_imgui_new_frame() {
    ImGui::NewFrame();
}

void raia_imgui_end_frame() {
    ImGui::EndFrame();
}

void raia_imgui_render() {
    ImGui::Render();
}

ImDrawData *raia_imgui_get_draw_data() {
    return ImGui::GetDrawData();
}

// デモ・デバッグ・情報

void raia_imgui_show_demo_window(bool *p_open /* = NULL */) {
    ImGui::ShowDemoWindow(p_open);
}

void raia_imgui_show_metrics_window(bool* p_open /* = NULL */) {
    ImGui::ShowMetricsWindow(p_open);
}

void raia_imgui_show_debug_log_window(bool* p_open /* = NULL */) {
    ImGui::ShowDebugLogWindow(p_open);
}

void raia_imgui_show_stack_tool_window(bool* p_open /* = NULL */) {
    ImGui::ShowStackToolWindow(p_open);
}

void raia_imgui_show_about_window(bool* p_open /* = NULL */) {
    ImGui::ShowAboutWindow(p_open);
}

void raia_imgui_show_style_editor(ImGuiStyle* ref /* = NULL */) {
    ImGui::ShowStyleEditor(ref);
}

bool raia_imgui_show_style_selector(const char* label) {
    return ImGui::ShowStyleSelector(label);
}

void raia_imgui_show_font_selector(const char* label) {
    ImGui::ShowFontSelector(label);
}

void raia_imgui_show_user_guide() {
    ImGui::ShowUserGuide();
}

const char* raia_imgui_get_version() {
    return ImGui::GetVersion();
}


// スタイル

void raia_imgui_style_colors_dark(ImGuiStyle* dst) {
    ImGui::StyleColorsDark(dst);
}

void raia_imgui_style_colors_light(ImGuiStyle* dst) {
    ImGui::StyleColorsLight(dst);
}

void raia_imgui_style_colors_classic(ImGuiStyle* dst) {
    ImGui::StyleColorsClassic(dst);
}

// ウィンドウ

bool raia_imgui_begin(const char* name, bool* p_open /* = null */, ImGuiWindowFlags flags /* = 0 */) {
    return ImGui::Begin(name, p_open, flags);
}

void raia_imgui_end() {
    ImGui::End();
}

// 子ウィンドウ

bool raia_imgui_begin_child(const char* str_id, float size_x, float size_y, bool border, ImGuiWindowFlags flags) {
    return ImGui::BeginChild(str_id, ImVec2(size_x, size_y), border, flags);
}

bool raia_imgui_begin_child_2(ImGuiID id, float size_x, float size_y, bool border, ImGuiWindowFlags flags) {
    return ImGui::BeginChild(id, ImVec2(size_x, size_y), border, flags);
}

void raia_imgui_end_child() {
    ImGui::EndChild();
}

// ウィンドウ・ユーティリティ

bool raia_imgui_is_window_appearing() {
    return ImGui::IsWindowAppearing();
}

bool raia_imgui_is_window_collapsed() {
    return ImGui::IsWindowCollapsed();
}

bool raia_imgui_is_window_focused(ImGuiFocusedFlags flags /* = 0 */) {
    return ImGui::IsWindowFocused(flags);
}

bool raia_imgui_is_window_hovered(ImGuiHoveredFlags flags /* = 0 */) {
    return ImGui::IsWindowHovered(flags);
}

ImDrawList* raia_imgui_get_window_draw_list() {
    return ImGui::GetWindowDrawList();
}

//ImVec2 raia_imgui_get_window_pos() {
//    return ImGui::GetWindowPos();
//}

float raia_imgui_get_window_pos_x() {
    return ImGui::GetWindowPos().x;
}

float raia_imgui_get_window_pos_y() {
    return ImGui::GetWindowPos().y;
}

//ImVec2 raia_imgui_get_window_size() {
//    return ImGui::GetWindowSize();
//}

float raia_imgui_get_window_width() {
    return ImGui::GetWindowWidth();
}

float raia_imgui_get_window_height() {
    return ImGui::GetWindowHeight();
}


// ウィンドウ操作

void raia_imgui_set_next_window_pos(float pos_x, float pos_y, ImGuiCond cond /* = 0 */, float pivot_x /* = 0 */, float pivot_y /* = 0 */) {
    ImGui::SetNextWindowPos(ImVec2(pos_x, pos_y), cond, ImVec2(pivot_x, pivot_y));
}

void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport) {
    ImGui::SetNextWindowViewport(viewport->ID);
}

void raia_imgui_set_next_window_bg_alpha(float alpha) {
    ImGui::SetNextWindowBgAlpha(alpha);
}

// コンテンツ領域

// ウィンドウ・スクロール

// パラメータ・スタック（共有）

void raia_imgui_push_style_color_u32(ImGuiCol idx, ImU32 col) {
    ImGui::PushStyleColor(idx, col);
}

void raia_imgui_push_style_color_vec4(ImGuiCol idx, float x, float y, float z, float w) {
    ImGui::PushStyleColor(idx, ImVec4(x, y, z, w));
}

void raia_imgui_pop_style_color(int count) {
    ImGui::PopStyleColor(count);
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

// パラメータ・スタック（現在のウィンドウ）

// スタイルの読み込みとアクセス

// カーソル / レイアウト

void raia_imgui_separator() {
    ImGui::Separator();
}

void raia_imgui_same_line() {
    ImGui::SameLine();
}

// IDスタック / スコープ

// ウィジェット: テキスト

void raia_imgui_text(const char *text) {
    ImGui::Text("%s", text);
}

// ウィジェット: メイン

bool raia_imgui_button(const char *label, float width, float height) {
    return ImGui::Button(label, ImVec2(width, height));
}

bool raia_imgui_checkbox(const char *label, bool *v) {
    return ImGui::Checkbox(label, v);
}

// ウィジェット: 画像

void raia_imgui_image(void *texture_id, float width, float height) {
    ImGui::Image(texture_id, ImVec2(width, height));
}

// ウィジェット: コンボボックス（ドロップダウン）

// ウィジェット: ドラッグスライダー

// ウィジェット: レギュラー・スライダー

float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max) {
    return ImGui::SliderFloat(label, v, v_min, v_max);
}

// ウィジェット: キーボード入力

// ウィジェット: カラーエディター/ピッカー

bool raia_imgui_color_edit_3(const char *label, float *col) {
    return ImGui::ColorEdit3(label, col);
}

// ウィジェット: ツリー

// ウィジェット: セレクタブル

// ウィジェット: リストボックス

// ウィジェット: データプロット

// ウィジェット: Value() ヘルパー

// ウィジェット: メニュー

// ツールチップ

// ポップアップ・モーダル

// テーブル

// ロギング/キャプチャ

// 無効化 [BETA API]

// クリッピング

// フォーカス, アクティブ化

// オーバーラッピング・モード

// アイテム/ウィジェット ユーティリティとクエリ関数

// ビューポート

ImGuiViewport* raia_imgui_get_main_viewport() {
    return ImGui::GetMainViewport();
}

// 背景／前景ドローリスト

// その他ユーティリティ

// テキスト・ユーティリティ

// カラーユーティリティ

// 入力ユーティリティ: キーボード/マウス/ゲームパッド

// 入力ユーティリティ： マウス専用

// クリップボードユーティリティ

// 設定/.Ini ユーティリティ

// デバッグ・ユーティリティ

// メモリ・アロケータ

// -- ここから拡張

// imgui.cpp

void raia_imgui_update_platform_windows() {
    ImGui::UpdatePlatformWindows();
}

void raia_imgui_render_platform_windows_default() {
    ImGui::RenderPlatformWindowsDefault();
}

// impl GLFW

bool raia_imgui_impl_glfw_init_for_opengl(GLFWwindow* window, bool install_callbacks) {
    return ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
}

void raia_imgui_impl_glfw_new_frame() {
    ImGui_ImplGlfw_NewFrame();
}

void raia_imgui_impl_glfw_shutdown() {
    ImGui_ImplGlfw_Shutdown();
}

// impl OpenGL3

bool raia_imgui_impl_opengl3_init(const char *glsl_version) {
    return ImGui_ImplOpenGL3_Init(glsl_version); // #version 300 es
}

void raia_imgui_impl_opengl3_new_frame() {
    ImGui_ImplOpenGL3_NewFrame();
}

void raia_imgui_impl_opengl3_render_draw_data(ImDrawData* draw_data) {
    ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}

void raia_imgui_impl_opengl3_shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
}

// GetIO ユーティリティ

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

void raia_imgui_getio_font_default(ImFont *font) {
    ImGui::GetIO().FontDefault = font;
}

// GetIO.Fonts ユーティリティ

ImFont* raia_imgui_getio_fonts_add_font_default() {
    return ImGui::GetIO().Fonts->AddFontDefault();
}

const ImWchar *raia_imgui_getio_fonts_get_glyph_ranges_japanese() {
    return ImGui::GetIO().Fonts->GetGlyphRangesJapanese();
}

ImFont *raia_imgui_getio_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges) {
    return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges);
}

// GetStyle ユーティリティ

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

}