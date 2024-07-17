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

void raia_imgui_set_next_window_size(float size_x, float size_y, ImGuiCond cond /* = 0 */) {
    ImGui::SetNextWindowSize(ImVec2(size_x, size_y), cond);
}

void raia_imgui_set_next_window_size_constraints(float size_min_x, float size_min_y, float size_max_x, float size_max_y, ImGuiSizeCallback custom_callback /* = NULL*/, void* custom_callback_data /* = NULL*/) {
    ImGui::SetNextWindowSizeConstraints(ImVec2(size_min_x, size_min_y), ImVec2(size_max_x, size_max_y), custom_callback, custom_callback_data);
}

void raia_imgui_set_next_window_content_size(float size_x, float size_y) {
    ImGui::SetNextWindowContentSize(ImVec2(size_x, size_y));
}

void raia_imgui_set_next_window_collapsed(bool collapsed, ImGuiCond cond /*= 0*/) {
    ImGui::SetNextWindowCollapsed(collapsed, cond);
}

void raia_imgui_set_next_window_focus() {
    ImGui::SetNextWindowFocus();
}

void raia_imgui_set_next_window_scroll(float scroll_x, float scroll_y) {
    ImGui::SetNextWindowScroll(ImVec2(scroll_x, scroll_y));
}

void raia_imgui_set_next_window_bg_alpha(float alpha) {
    ImGui::SetNextWindowBgAlpha(alpha);
}

void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport) {
    ImGui::SetNextWindowViewport(viewport->ID);
}

void raia_imgui_set_next_window_viewport_2(ImGuiID viewport_id) {
    ImGui::SetNextWindowViewport(viewport_id);
}

void raia_imgui_set_window_pos(float pos_x, float pos_y, ImGuiCond cond /* = 0*/) {
    ImGui::SetWindowPos(ImVec2(pos_x, pos_y), cond);
}

void raia_imgui_set_window_size(float size_x, float size_y, ImGuiCond cond /* = 0 */) {
    ImGui::SetWindowSize(ImVec2(size_x, size_y), cond);
}

void raia_imgui_set_window_collapsed(bool collapsed, ImGuiCond cond /* = 0*/) {
    ImGui::SetWindowCollapsed(collapsed, cond);
}

void raia_imgui_set_window_focus() {
    ImGui::SetWindowFocus();
}

void raia_imgui_set_window_font_scale(float scale) {
    ImGui::SetWindowFontScale(scale);
}

void raia_imgui_set_window_pos_2(const char* name, float pos_x, float pos_y, ImGuiCond cond /*= 0*/) {
    ImGui::SetWindowPos(name, ImVec2(pos_x, pos_y), cond);
}

void raia_imgui_set_window_size_2(const char* name, float size_x, float size_y, ImGuiCond cond /*= 0*/) {
    ImGui::SetWindowSize(name, ImVec2(size_x, size_y), cond);
}

void raia_imgui_set_window_collapsed_2(const char* name, bool collapsed, ImGuiCond cond /*= 0*/) {
    ImGui::SetWindowCollapsed(name, collapsed, cond);
}

void raia_imgui_set_window_focus_2(const char* name) {
    ImGui::SetWindowFocus(name);
}

// コンテンツ領域

float raia_imgui_get_content_region_avail_x() {
    return ImGui::GetContentRegionAvail().x;
}

float raia_imgui_get_content_region_avail_y() {
    return ImGui::GetContentRegionAvail().y;
}

float raia_imgui_get_content_region_max_x() {
    return ImGui::GetContentRegionMax().x;
}

float raia_imgui_get_content_region_max_y() {
    return ImGui::GetContentRegionMax().y;
}

float raia_imgui_get_window_content_region_min_x() {
    return ImGui::GetWindowContentRegionMin().x;
}

float raia_imgui_get_window_content_region_min_y() {
    return ImGui::GetWindowContentRegionMin().y;
}

float raia_imgui_get_window_content_region_max_x() {
    return ImGui::GetWindowContentRegionMax().x;
}

float raia_imgui_get_window_content_region_max_y() {
    return ImGui::GetWindowContentRegionMax().y;
}

// ウィンドウ・スクロール

float raia_imgui_get_scroll_x() {
    return ImGui::GetScrollX();
}

float raia_imgui_get_scroll_y() {
    return ImGui::GetScrollY();
}

void raia_imgui_set_scroll_x(float scroll_x) {
    ImGui::SetScrollX(scroll_x);
}

void raia_imgui_set_scroll_y(float scroll_y) {
    ImGui::SetScrollY(scroll_y);
}

float raia_imgui_get_scroll_max_x() {
    return ImGui::GetScrollMaxX();
}

float raia_imgui_get_scroll_max_y() {
    return ImGui::GetScrollMaxY();
}

void raia_imgui_set_scroll_here_x(float center_x_ratio /* = 0.5f*/) {
    ImGui::SetScrollHereX(center_x_ratio);
}

void raia_imgui_set_scroll_here_y(float center_y_ratio /* = 0.5f*/) {
    ImGui::SetScrollHereY(center_y_ratio);
}

void raia_imgui_set_scroll_from_pos_x(float local_x, float center_x_ratio /* = 0.5f*/) {
    ImGui::SetScrollFromPosX(local_x, center_x_ratio);
}

void raia_imgui_set_scroll_from_pos_y(float local_y, float center_y_ratio /* = 0.5f*/) {
    ImGui::SetScrollFromPosY(local_y, center_y_ratio);
}

// パラメータ・スタック（共有）

void raia_imgui_push_font(ImFont* font) {
    ImGui::PushFont(font);
}

void raia_imgui_pop_font() {
    ImGui::PopFont();
}

void raia_imgui_push_style_color(ImGuiCol idx, ImU32 col) {
    ImGui::PushStyleColor(idx, col);
}

void raia_imgui_push_style_color_2(ImGuiCol idx, float col_x, float col_y, float col_z, float col_w) {
    ImGui::PushStyleColor(idx, ImVec4(col_x, col_y, col_z, col_w));
}

void raia_imgui_pop_style_color_3(int count /* = 1*/) {
    ImGui::PopStyleColor(count);
}

void raia_imgui_push_style_var(ImGuiStyleVar idx, float val) {
    ImGui::PushStyleVar(idx, val);
}

void raia_imgui_push_style_var_2(ImGuiStyleVar idx, float val_x, float val_y) {
    ImGui::PushStyleVar(idx, ImVec2(val_x, val_y));
}

void raia_imgui_pop_style_var_3(int count /* = 1*/) {
    ImGui::PopStyleVar(count);
}

void raia_imgui_push_tab_stop(bool tab_stop) {
    ImGui::PushTabStop(tab_stop);
}

void raia_imgui_pop_tab_stop() {
    ImGui::PopTabStop();
}

void raia_imgui_push_button_repeat(bool repeat) {
    ImGui::PushButtonRepeat(repeat);
}

void raia_imgui_pop_button_repeat() {
    ImGui::PopButtonRepeat();
}

// パラメータ・スタック（現在のウィンドウ）

void raia_imgui_push_item_width(float item_width) {
    ImGui::PushItemWidth(item_width);
}

void raia_imgui_pop_item_width() {
    ImGui::PopItemWidth();
}

void raia_imgui_set_next_item_width(float item_width) {
    ImGui::SetNextItemWidth(item_width);
}

float raia_imgui_calc_item_width() {
    return ImGui::CalcItemWidth();
}

void raia_imgui_push_text_wrap_pos(float wrap_local_pos_x /* = 0.0f*/) {
    ImGui::PushTextWrapPos(wrap_local_pos_x);
}

void raia_imgui_pop_text_wrap_pos() {
    ImGui::PopTextWrapPos();
}

// スタイルの読み込みとアクセス

ImFont* raia_imgui_get_font() {
    return ImGui::GetFont();
}

float raia_imgui_get_font_size() {
    return ImGui::GetFontSize();
}

float raia_imgui_get_font_tex_uv_white_pixel_x() {
    return ImGui::GetFontTexUvWhitePixel().x;
}

float raia_imgui_get_font_tex_uv_white_pixel_y() {
    return ImGui::GetFontTexUvWhitePixel().y;
}

ImU32 raia_imgui_get_color_u32(ImGuiCol idx, float alpha_mul /* = 1.0f*/) {
    return ImGui::GetColorU32(idx, alpha_mul);
}

ImU32 raia_imgui_get_color_u32_2(float col_x, float col_y, float col_z, float col_w) {
    return ImGui::GetColorU32(ImVec4(col_x, col_y, col_z, col_w));
}

ImU32 raia_imgui_get_color_u32_3(ImU32 col) {
    return ImGui::GetColorU32(col);
}

float raia_imgui_get_style_color_vec4_x(ImGuiCol idx) {
    return ImGui::GetStyleColorVec4(idx).x;
}

float raia_imgui_get_style_color_vec4_y(ImGuiCol idx) {
    return ImGui::GetStyleColorVec4(idx).y;
}

float raia_imgui_get_style_color_vec4_z(ImGuiCol idx) {
    return ImGui::GetStyleColorVec4(idx).z;
}

float raia_imgui_get_style_color_vec4_w(ImGuiCol idx) {
    return ImGui::GetStyleColorVec4(idx).w;
}

// カーソル / レイアウト

void raia_imgui_separator() {
    ImGui::Separator();
}

void raia_imgui_same_line() {
    ImGui::SameLine();
}

void raia_imgui_new_line() {
    ImGui::NewLine();
}

void raia_imgui_spacing() {
    ImGui::Spacing();
}

void raia_imgui_dummy(float size_x, float size_y) {
    ImGui::Dummy(ImVec2(size_x, size_y));
}

void raia_imgui_indent(float indent_w /* = 0.0f*/) {
    ImGui::Indent(indent_w);
}

void raia_imgui_unindent(float indent_w /* = 0.0f*/) {
    ImGui::Unindent(indent_w);
}

void raia_imgui_begin_group() {
    ImGui::BeginGroup();
}

void raia_imgui_end_group() {
    ImGui::EndGroup();
}

//ImVec2 raia_imgui_GetCursorPos() {
//    return ImGui::GetCursorPos();
//}

float raia_imgui_get_cursor_pos_x() {
    return ImGui::GetCursorPosX();
}

float raia_imgui_get_cursor_pos_y() {
    return ImGui::GetCursorPosY();
}

void raia_imgui_set_cursor_pos(float local_pos_x, float local_pos_y) {
    ImGui::SetCursorPos(ImVec2(local_pos_x, local_pos_y));
}

void raia_imgui_set_cursor_pos_x(float local_x) {
    ImGui::SetCursorPosX(local_x);
}

void raia_imgui_set_cursor_pos_y(float local_y) {
    ImGui::SetCursorPosY(local_y);
}

float raia_imgui_get_cursor_start_pos_x() {
    return ImGui::GetCursorStartPos().x;
}

float raia_imgui_get_cursor_start_pos_y() {
    return ImGui::GetCursorStartPos().y;
}

float raia_imgui_get_cursor_screen_pos_x() {
    return ImGui::GetCursorScreenPos().x;
}

float raia_imgui_get_cursor_screen_pos_y() {
    return ImGui::GetCursorScreenPos().y;
}

void raia_imgui_set_cursor_screen_pos(float pos_x, float pos_y) {
    ImGui::SetCursorPos(ImVec2(pos_x, pos_y));
}

void raia_imgui_align_text_to_frame_padding() {
    ImGui::AlignTextToFramePadding();
}

float raia_imgui_get_text_line_height() {
    return ImGui::GetTextLineHeight();
}

float raia_imgui_get_text_line_height_with_spacing() {
    return ImGui::GetTextLineHeightWithSpacing();
}

float raia_imgui_get_frame_height() {
    return ImGui::GetFrameHeight();
}

float raia_imgui_get_frame_height_with_spacing() {
    return ImGui::GetFrameHeightWithSpacing();
}

// IDスタック / スコープ

void raia_imgui_push_id(const char* str_id) {
    ImGui::PushID(str_id);
}

void raia_imgui_push_id_2(const char* str_id_begin, const char* str_id_end) {
    ImGui::PushID(str_id_begin, str_id_end);
}

void raia_imgui_push_id_3(const void* ptr_id) {
    ImGui::PushID(ptr_id);
}

void raia_imgui_push_id_4(int int_id) {
    ImGui::PushID(int_id);
}

void raia_imgui_pop_id() {
    ImGui::PopID();
}

ImGuiID raia_imgui_get_id(const char* str_id) {
    return ImGui::GetID(str_id);
}

ImGuiID raia_imgui_get_id_2(const char* str_id_begin, const char* str_id_end) {
    return ImGui::GetID(str_id_begin, str_id_end);
}

ImGuiID raia_imgui_get_id_3(const void* ptr_id) {
    return ImGui::GetID(ptr_id);
}

// ウィジェット: テキスト

void raia_imgui_text(const char *text) {
    ImGui::Text("%s", text);
}

//void TextV(const char* fmt, va_list args) {
//    ImGui::TextV(fmt, args);
//}

// ウィジェット: メイン

bool raia_imgui_button(const char *label, float width, float height) {
    return ImGui::Button(label, ImVec2(width, height));
}

bool raia_imgui_small_button(const char* label) {
    return ImGui::SmallButton(label);
}

bool raia_imgui_invisible_button(const char* str_id, float size_x, float size_y, ImGuiButtonFlags flags /* = 0*/) {
    return ImGui::InvisibleButton(str_id, ImVec2(size_x, size_y), flags);
}

bool raia_imgui_arrow_button(const char* str_id, ImGuiDir dir) {
    return ImGui::ArrowButton(str_id, dir);
}

bool raia_imgui_checkbox(const char *label, bool *v) {
    return ImGui::Checkbox(label, v);
}

bool raia_imgui_checkbox_flags(const char* label, int* flags, int flags_value) {
    return ImGui::CheckboxFlags(label, flags, flags_value);
}

bool raia_imgui_checkbox_flags_2(const char* label, unsigned int* flags, unsigned int flags_value) {
    return ImGui::CheckboxFlags(label, flags, flags_value);
}

bool raia_imgui_radio_button(const char* label, bool active) {
    return ImGui::RadioButton(label, active);
}

bool raia_imgui_radio_button_2(const char* label, int* v, int v_button) {
    return ImGui::RadioButton(label, v, v_button);
}

void raia_imgui_progress_bar(float fraction, float size_arg_x /*= -FLT_MIN*/, float size_arg_y /*= 0*/, const char* overlay /* = NULL*/) {
    return ImGui::ProgressBar(fraction, ImVec2(size_arg_x, size_arg_y), overlay);
}

void raia_imgui_bullet() {
    return ImGui::Bullet();
}


// ウィジェット: 画像

void raia_imgui_image(void *texture_id, float width, float height) {
    ImGui::Image(texture_id, ImVec2(width, height));
}

bool raia_imgui_image_button(const char* str_id, ImTextureID user_texture_id, float size_x, float size_y,
                 float uv0_x /* = 0 */, float uv0_y /* = 0 */,
                 float uv1_x /* = 1 */, float uv1_y /* = 1 */,
                 float bg_col_x /* = 0 */, float bg_col_y /* = 0 */, float bg_col_z /* = 0 */, float bg_col_w /* = 0 */,
                 float tint_col_x /* = 1 */, float tint_col_y /* = 1 */, float tint_col_z /* = 1 */, float tint_col_w /* = 1 */) {
    return ImGui::ImageButton(str_id, user_texture_id, ImVec2(size_x, size_y),
                              ImVec2(uv0_x, uv0_y), ImVec2(uv1_x, uv1_y),
                              ImVec4(bg_col_x, bg_col_y, bg_col_z, bg_col_w),
                              ImVec4(tint_col_x, tint_col_y, tint_col_z, tint_col_w));
}

// ウィジェット: コンボボックス（ドロップダウン）

bool raia_imgui_begin_combo(const char* label, const char* preview_value, ImGuiComboFlags flags /* = 0 */) {
    return ImGui::BeginCombo(label, preview_value, flags);
}

void raia_imgui_end_combo() {
    ImGui::EndCombo();
}

bool raia_imgui_combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items /* = -1 */) {
    return ImGui::Combo(label, current_item, items, items_count, popup_max_height_in_items);
}

bool raia_imgui_combo_2(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items /* = -1 */) {
    return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items);
}

bool raia_imgui_combo_3(const char* label, int* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items /* = -1 */) {
    return ImGui::Combo(label, current_item, items_getter, data, items_count, popup_max_height_in_items);
}

// ウィジェット: ドラッグスライダー

bool raia_imgui_drag_float(const char* label, float* v, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_float2(const char* label, float v[2], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_float3(const char* label, float v[3], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_float4(const char* label, float v[4], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_float_range2(const char* label, float* v_current_min, float* v_current_max, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, const char* format_max /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags);
}

bool raia_imgui_drag_int(const char* label, int* v, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_int2(const char* label, int v[2], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragInt2(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_int3(const char* label, int v[3], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragInt3(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_int4(const char* label, int v[4], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragInt4(label, v, v_speed, v_min, v_max, format, flags);
}

bool raia_imgui_drag_int_range2(const char* label, int* v_current_min, int* v_current_max, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, const char* format_max /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags);
}

bool raia_imgui_drag_scalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags);
}

bool raia_imgui_drag_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::DragScalarN(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags);
}

// ウィジェット: レギュラー・スライダー

float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderFloat(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_float2(const char* label, float v[2], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderFloat2(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_float3(const char* label, float v[3], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderFloat3(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_float4(const char* label, float v[4], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderFloat4(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_angle(const char* label, float* v_rad, float v_degrees_min /* = -360.0f */, float v_degrees_max /* = +360.0f */, const char* format /* = "%.0f deg" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags);
}

bool raia_imgui_slider_int(const char* label, int* v, int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderInt(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_int2(const char* label, int v[2], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderInt2(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_int3(const char* label, int v[3], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderInt3(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_int4(const char* label, int v[4], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderInt4(label, v, v_min, v_max, format, flags);
}

bool raia_imgui_slider_scalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderScalar(label, data_type, p_data, p_min, p_max, format, flags);
}

bool raia_imgui_slider_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::SliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags);
}

bool raia_imgui_v_slider_float(const char* label, float size_x, float size_y, float* v, float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::VSliderFloat(label, ImVec2(size_x, size_y), v, v_min, v_max, format, flags);
}

bool raia_imgui_v_slider_int(const char* label, float size_x, float size_y, int* v, int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::VSliderInt(label, ImVec2(size_x, size_y), v, v_min, v_max, format, flags);
}

bool raia_imgui_v_slider_scalar(const char* label, float size_x, float size_y, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */) {
    return ImGui::VSliderScalar(label, ImVec2(size_x, size_y), data_type, p_data, p_min, p_max, format, flags);
}

// ウィジェット: キーボード入力

bool raia_imgui_input_text(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */) {
    return ImGui::InputText(label, buf, buf_size, flags, callback, user_data);
}

bool raia_imgui_input_text_multiline(const char* label, char* buf, size_t buf_size, float size_x /* = 0 */, float size_y /* = 0 */, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */) {
    return ImGui::InputTextMultiline(label, buf, buf_size, ImVec2(size_x, size_y), flags, callback, user_data);
}

bool raia_imgui_input_text_with_hint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */) {
    return ImGui::InputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data);
}

bool raia_imgui_input_float(const char* label, float* v, float step /* = 0.0f */, float step_fast /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputFloat(label, v, step, step_fast, format, flags);
}

bool raia_imgui_input_float2(const char* label, float v[2], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputFloat2(label, v, format, flags);
}

bool raia_imgui_input_float3(const char* label, float v[3], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputFloat3(label, v, format, flags);
}

bool raia_imgui_input_float4(const char* label, float v[4], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputFloat4(label, v, format, flags);
}

bool raia_imgui_input_int(const char* label, int* v, int step /* = 1 */, int step_fast /* = 100 */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputInt(label, v, step, step_fast, flags);
}

bool raia_imgui_input_int2(const char* label, int v[2], ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputInt2(label, v, flags);
}

bool raia_imgui_input_int3(const char* label, int v[3], ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputInt3(label, v, flags);
}

bool raia_imgui_input_int4(const char* label, int v[4], ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputInt4(label, v, flags);
}

bool raia_imgui_input_double(const char* label, double* v, double step /* = 0.0 */, double step_fast /* = 0.0 */, const char* format /* = "%.6f" */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputDouble(label, v, step, step_fast, format, flags);
}

bool raia_imgui_input_scalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags);
}

bool raia_imgui_input_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, ImGuiInputTextFlags flags /* = 0 */) {
    return ImGui::InputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags);
}

// ウィジェット: カラーエディター/ピッカー

bool raia_imgui_color_edit3(const char *label, float *col, ImGuiColorEditFlags flags /* = 0 */) {
    return ImGui::ColorEdit3(label, col, flags);
}

bool raia_imgui_color_edit4(const char* label, float col[4], ImGuiColorEditFlags flags /* = 0 */) {
    return ImGui::ColorEdit4(label, col, flags);
}

bool raia_imgui_color_picker3(const char* label, float col[3], ImGuiColorEditFlags flags /* = 0 */) {
    return ImGui::ColorPicker3(label, col, flags);
}

bool raia_imgui_color_picker4(const char* label, float col[4], ImGuiColorEditFlags flags /* = 0 */, const float* ref_col /* = NULL */) {
    return ImGui::ColorPicker4(label, col, flags, ref_col);
}

bool raia_imgui_color_button(const char* desc_id, float col_x, float col_y, float col_z, float col_w, ImGuiColorEditFlags flags /* = 0 */, float size_x /* = 0 */, float size_y /* = 0 */) {
    return ImGui::ColorButton(desc_id, ImVec4(col_x, col_y, col_z, col_w), flags, ImVec2(size_x, size_y));
}

void raia_imgui_set_color_edit_options(ImGuiColorEditFlags flags) {
    ImGui::SetColorEditOptions(flags);
}

// ウィジェット: ツリー

// ウィジェット: セレクタブル

bool raia_imgui_selectable(const char* label, bool selected /* = false */, ImGuiSelectableFlags flags /* = 0 */, float size_x /* = 0*/, float size_y /* = 0*/) {
    return ImGui::Selectable(label, selected, flags, ImVec2(size_x, size_y));
}

bool raia_imgui_selectable_2(const char* label, bool* p_selected, ImGuiSelectableFlags flags /* = 0 */,  float size_x /* = 0*/, float size_y /* = 0*/) {
    return ImGui::Selectable(label, p_selected, flags, ImVec2(size_x, size_y));
}

// ウィジェット: リストボックス

bool raia_imgui_begin_list_box(const char* label, float size_x /* = 0*/, float size_y /* = 0*/) {
    return ImGui::BeginListBox(label, ImVec2(size_x, size_y));
}

void raia_imgui_end_list_box() {
    return ImGui::EndListBox();
}

bool raia_imgui_list_box(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items /* = -1 */) {
    return ImGui::ListBox(label, current_item, items, items_count, height_in_items);
}

bool raia_imgui_list_box_2(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items /* = -1 */) {
    return ImGui::ListBox(label, current_item, items_getter, data, items_count, height_in_items);
}

// ウィジェット: データプロット

//void raia_imgui_plot_lines(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0), int stride /* = sizeof(float) */);
//void raia_imgui_plot_lines_2(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0));
//void raia_imgui_plot_histogram(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0), int stride /* = sizeof(float) */);
//void raia_imgui_plot_histogram_2(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0));

// ウィジェット: Value() ヘルパー

void raia_imgui_value(const char* prefix, bool b) {
    ImGui::Value(prefix, b);
}

void raia_imgui_value_2(const char* prefix, int v) {
    ImGui::Value(prefix, v);
}

void raia_imgui_value_3(const char* prefix, unsigned int v) {
    ImGui::Value(prefix, v);
}

void raia_imgui_value_4(const char* prefix, float v, const char* float_format /* = NULL */) {
    ImGui::Value(prefix, v, float_format);
}

// ウィジェット: メニュー

bool raia_imgui_begin_menu_bar() {
    return ImGui::BeginMenuBar();
}

void raia_imgui_end_menu_bar() {
    ImGui::EndMenuBar();
}

bool raia_imgui_begin_main_menu_bar() {
    return ImGui::BeginMainMenuBar();
}

void raia_imgui_end_main_menu_bar() {
    ImGui::EndMainMenuBar();
}

bool raia_imgui_begin_menu(const char* label, bool enabled /* = true */) {
    return ImGui::BeginMenu(label, enabled);
}

void raia_imgui_end_menu() {
    ImGui::EndMenu();
}

bool raia_imgui_menu_item(const char* label, const char* shortcut /* = NULL */, bool selected /* = false */, bool enabled /* = true */) {
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

bool raia_imgui_menu_item_2(const char* label, const char* shortcut, bool* p_selected, bool enabled /* = true */) {
    return ImGui::MenuItem(label, shortcut, p_selected, enabled);
}

// ツールチップ

bool raia_imgui_begin_tooltip() {
    return ImGui::BeginTooltip();
}

void raia_imgui_end_tooltip() {
    ImGui::EndTooltip();
}

//void raia_imgui_set_tooltip(const char* fmt, ...) IM_FMTARGS(1);
//void raia_imgui_set_tooltip_v(const char* fmt, va_list args) IM_FMTLIST(1);

bool raia_imgui_begin_item_tooltip() {
    return ImGui::BeginItemTooltip();
}

//IMGUI_API void SetItemTooltip(const char* fmt, ...) IM_FMTARGS(1);
//IMGUI_API void SetItemTooltipV(const char* fmt, va_list args) IM_FMTLIST(1);

// ポップアップ・モーダル

bool raia_imgui_begin_popup(const char* str_id, ImGuiWindowFlags flags /* = 0 */) {
    return ImGui::BeginPopup(str_id, flags);
}

bool raia_imgui_begin_popup_modal(const char* name, bool* p_open /* = NULL */, ImGuiWindowFlags flags /* = 0 */) {
    return ImGui::BeginPopupModal(name, p_open, flags);
}

void raia_imgui_end_popup() {
    ImGui::EndPopup();
}

void raia_imgui_open_popup(const char* str_id, ImGuiPopupFlags popup_flags /* = 0 */) {
    ImGui::OpenPopup(str_id, popup_flags);
}

void raia_imgui_open_popup_2(ImGuiID id, ImGuiPopupFlags popup_flags /* = 0 */) {
    ImGui::OpenPopup(id, popup_flags);
}

void raia_imgui_open_popup_on_item_click(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */) {
    ImGui::OpenPopupOnItemClick(str_id, popup_flags);
}

void raia_imgui_close_current_popup() {
    ImGui::CloseCurrentPopup();
}

bool raia_imgui_begin_popup_context_item(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */) {
    return ImGui::BeginPopupContextItem(str_id, popup_flags);
}

bool raia_imgui_begin_popup_context_window(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */) {
    return ImGui::BeginPopupContextWindow(str_id, popup_flags);
}

bool raia_imgui_begin_popup_context_void(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */) {
    return ImGui::BeginPopupContextVoid(str_id, popup_flags);
}

bool raia_imgui_is_popup_open(const char* str_id, ImGuiPopupFlags flags /* = 0 */) {
    return ImGui::IsPopupOpen(str_id, flags);
}

// テーブル

bool raia_imgui_begin_table(const char* str_id, int column, ImGuiTableFlags flags /* = 0 */, float outer_size_x /* = 0 */, float outer_size_y /* = 0 */, float inner_width /* = 0.0f */) {
    return ImGui::BeginTable(str_id, column, flags, ImVec2(outer_size_x, outer_size_y), inner_width);
}

void raia_imgui_end_table() {
    ImGui::EndTable();
}

void raia_imgui_table_next_row(ImGuiTableRowFlags row_flags /* = 0 */, float min_row_height /* = 0.0f */) {
    ImGui::TableNextRow(row_flags, min_row_height);
}

bool raia_imgui_table_next_column() {
    return ImGui::TableNextColumn();
}

bool raia_imgui_table_set_column_index(int column_n) {
    return ImGui::TableSetColumnIndex(column_n);
}

void raia_imgui_table_setup_column(const char* label, ImGuiTableColumnFlags flags /* = 0 */, float init_width_or_weight /* = 0.0f */, ImGuiID user_id /* = 0 */) {
    ImGui::TableSetupColumn(label, flags, init_width_or_weight, user_id);
}

void raia_imgui_table_setup_scroll_freeze(int cols, int rows) {
    ImGui::TableSetupScrollFreeze(cols, rows);
}

void raia_imgui_table_headers_row() {
    ImGui::TableHeadersRow();
}

void raia_imgui_table_header(const char* label) {
    ImGui::TableHeader(label);
}

ImGuiTableSortSpecs* raia_imgui_table_get_sort_specs() {
    return ImGui::TableGetSortSpecs();
}

int raia_imgui_table_get_column_count() {
    return ImGui::TableGetColumnCount();
}

int raia_imgui_table_get_column_index() {
    return ImGui::TableGetColumnIndex();
}

int raia_imgui_table_get_row_index() {
    return ImGui::TableGetRowIndex();
}

const char* raia_imgui_table_get_column_name(int column_n /* = -1 */) {
    return ImGui::TableGetColumnName(column_n);
}

ImGuiTableColumnFlags raia_imgui_table_get_column_flags(int column_n /* = -1 */) {
    return ImGui::TableGetColumnFlags(column_n);
}

void raia_imgui_table_set_column_enabled(int column_n, bool v) {
    ImGui::TableSetColumnEnabled(column_n, v);
}

void raia_imgui_table_set_bg_color(ImGuiTableBgTarget target, ImU32 color, int column_n /* = -1 */) {
    ImGui::TableSetBgColor(target, color, column_n);
}

void raia_imgui_columns(int count /* = 1 */, const char* id /* = NULL */, bool border /* = true */) { // ここからレガシーなテーブルAPI
    ImGui::Columns(count, id, border);
}

void raia_imgui_next_column() {
    ImGui::NextColumn();
}

int raia_imgui_get_column_index() {
    return ImGui::GetColumnIndex();
}

float raia_imgui_get_column_width(int column_index /* = -1 */) {
    return ImGui::GetColumnWidth(column_index);
}

void raia_imgui_set_column_width(int column_index, float width) {
    ImGui::SetColumnWidth(column_index, width);
}

float raia_imgui_get_column_offset(int column_index /* = -1 */) {
    return ImGui::GetColumnOffset(column_index);
}

void raia_imgui_set_column_offset(int column_index, float offset_x) {
    ImGui::SetColumnOffset(column_index, offset_x);
}

int raia_imgui_get_columns_count() {
    return ImGui::GetColumnsCount();
}

// タブバー、タブ

bool raia_imgui_begin_tab_bar(const char* str_id, ImGuiTabBarFlags flags /* = 0 */) {
    return ImGui::BeginTabBar(str_id, flags);
}

void raia_imgui_end_tab_bar() {
    ImGui::EndTabBar();
}

bool raia_imgui_begin_tab_item(const char* label, bool* p_open /* = NULL */, ImGuiTabItemFlags flags /* = 0 */) {
    return ImGui::BeginTabItem(label, p_open, flags);
}

void raia_imgui_end_tab_item() {
    ImGui::EndTabItem();
}

bool raia_imgui_tab_item_button(const char* label, ImGuiTabItemFlags flags /* = 0 */) {
    return ImGui::TabItemButton(label, flags);
}

void raia_imgui_set_tab_item_closed(const char* tab_or_docked_window_label) {
    ImGui::SetTabItemClosed(tab_or_docked_window_label);
}

// ロギング/キャプチャ

// ドラッグ・アンド・ドロップ

bool raia_imgui_begin_drag_drop_source(ImGuiDragDropFlags flags /* = 0 */) {
    return ImGui::BeginDragDropSource(flags);
}

bool raia_imgui_set_drag_drop_payload(const char* type, const void* data, size_t sz, ImGuiCond cond /* = 0 */) {
    return ImGui::SetDragDropPayload(type, data, sz, cond);
}

void raia_imgui_end_drag_drop_source() {
    ImGui::EndDragDropSource();
}

bool raia_imgui_begin_drag_drop_target() {
    return ImGui::BeginDragDropTarget();
}

const ImGuiPayload* raia_imgui_accept_drag_drop_payload(const char* type, ImGuiDragDropFlags flags /* = 0 */) {
    return ImGui::AcceptDragDropPayload(type, flags);
}

void raia_imgui_end_drag_drop_target() {
    ImGui::EndDragDropTarget();
}

const ImGuiPayload* raia_imgui_get_drag_drop_payload() {
    return ImGui::GetDragDropPayload();
}

// 無効化 [BETA API]

void raia_imgui_begin_disabled(bool disabled /* = true */) {
    ImGui::BeginDisabled();
}

void raia_imgui_end_disabled() {
    ImGui::EndDisabled();
}

// クリッピング

void raia_imgui_push_clip_rect(float clip_rect_min_x, float clip_rect_min_y, float clip_rect_max_x, float clip_rect_max_y, bool intersect_with_current_clip_rect) {
    ImGui::PushClipRect(ImVec2(clip_rect_min_x, clip_rect_min_y), ImVec2(clip_rect_max_x, clip_rect_max_y), intersect_with_current_clip_rect);
}

void raia_imgui_pop_clip_rect() {
    ImGui::PopClipRect();
}

// フォーカス, アクティブ化

void raia_imgui_set_item_default_focus() {
    ImGui::SetItemDefaultFocus();
}

void raia_imgui_set_keyboard_focus_here(int offset /* = 0 */) {
    ImGui::SetKeyboardFocusHere(offset);
}

// オーバーラッピング・モード

void raia_imgui_set_next_item_allow_overlap() {
    ImGui::SetNextItemAllowOverlap();
}

// アイテム/ウィジェット ユーティリティとクエリ関数

bool raia_imgui_is_item_hovered(ImGuiHoveredFlags flags /* = 0 */) {
    return ImGui::IsItemHovered(flags);
}

bool raia_imgui_is_item_active() {
    return ImGui::IsItemActive();
}

bool raia_imgui_is_item_focused() {
    return ImGui::IsItemFocused();
}

bool raia_imgui_is_item_clicked(ImGuiMouseButton mouse_button /* = 0 */) {
    return ImGui::IsItemClicked(mouse_button);
}

bool raia_imgui_is_item_visible() {
    return ImGui::IsItemVisible();
}

bool raia_imgui_is_item_edited() {
    return ImGui::IsItemEdited();
}

bool raia_imgui_is_item_activated() {
    return ImGui::IsItemActivated();
}

bool raia_imgui_is_item_deactivated() {
    return ImGui::IsItemDeactivated();
}

bool raia_imgui_is_item_deactivated_after_edit() {
    return ImGui::IsItemDeactivatedAfterEdit();
}

bool raia_imgui_is_item_toggled_open() {
    return ImGui::IsItemToggledOpen();
}

bool raia_imgui_is_any_item_hovered() {
    return ImGui::IsAnyItemHovered();
}

bool raia_imgui_is_any_item_active() {
    return ImGui::IsAnyItemActive();
}

bool raia_imgui_is_any_item_focused() {
    return ImGui::IsAnyItemFocused();
}

ImGuiID raia_imgui_get_item_id() {
    return ImGui::GetItemID();
}

float raia_imgui_get_item_rect_min_x() {
    return ImGui::GetItemRectMin().x;
}

float raia_imgui_get_item_rect_min_y() {
    return ImGui::GetItemRectMin().y;
}

float raia_imgui_get_item_rect_max_x() {
    return ImGui::GetItemRectMax().x;
}

float raia_imgui_get_item_rect_max_y() {
    return ImGui::GetItemRectMax().y;
}

float raia_imgui_get_item_rect_size_x() {
    return ImGui::GetItemRectSize().x;
}

float raia_imgui_get_item_rect_size_y() {
    return ImGui::GetItemRectSize().y;
}

// ビューポート

ImGuiViewport* raia_imgui_get_main_viewport() {
    return ImGui::GetMainViewport();
}

// 背景／前景ドローリスト

ImDrawList* raia_imgui_get_background_draw_list() {
    return ImGui::GetBackgroundDrawList();
}

ImDrawList* raia_imgui_get_foreground_draw_list() {
    return ImGui::GetForegroundDrawList();
}

// その他ユーティリティ

bool raia_imgui_is_rect_visible(float size_x, float size_y) {
    return ImGui::IsRectVisible(ImVec2(size_x, size_y));
}

bool raia_imgui_is_rect_visible_2(float rect_min_x, float rect_min_y, float rect_max_x, float rect_max_y) {
    return ImGui::IsRectVisible(ImVec2(rect_min_x, rect_min_y), ImVec2(rect_max_x, rect_max_y));
}

double raia_imgui_get_time() {
    return ImGui::GetTime();
}

int raia_imgui_get_frame_count() {
    return ImGui::GetFrameCount();
}

ImDrawListSharedData* raia_imgui_get_draw_list_shared_data() {
    return ImGui::GetDrawListSharedData();
}

const char* raia_imgui_get_style_color_name(ImGuiCol idx) {
    return ImGui::GetStyleColorName(idx);
}

void raia_imgui_set_state_storage(ImGuiStorage* storage) {
    ImGui::SetStateStorage(storage);
}

ImGuiStorage* raia_imgui_get_state_storage() {
    return ImGui::GetStateStorage();
}

bool raia_imgui_begin_child_frame(ImGuiID id, float size_x, float size_y, ImGuiWindowFlags flags /* = 0 */) {
    return ImGui::BeginChildFrame(id, ImVec2(size_x, size_y), flags);
}

void raia_imgui_end_child_frame() {
    ImGui::EndChildFrame();
}

// テキスト・ユーティリティ

float raia_imgui_calc_text_size_x(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */) {
    return ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width).x;
}

float raia_imgui_calc_text_size_y(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */) {
    return ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width).y;
}

// カラーユーティリティ

float raia_imgui_color_convert_u32_to_float4_x(ImU32 in) {
    return ImGui::ColorConvertU32ToFloat4(in).x;
}

float raia_imgui_color_convert_u32_to_float4_y(ImU32 in) {
    return ImGui::ColorConvertU32ToFloat4(in).y;
}

float raia_imgui_color_convert_u32_to_float4_z(ImU32 in) {
    return ImGui::ColorConvertU32ToFloat4(in).z;
}

float raia_imgui_color_convert_u32_to_float4_w(ImU32 in) {
    return ImGui::ColorConvertU32ToFloat4(in).w;
}

ImU32 raia_imgui_color_convert_float4_to_u32(float in_x, float in_y, int in_z, int in_w) {
    return ImGui::ColorConvertFloat4ToU32(ImVec4(in_x, in_y, in_z, in_w));
}

void raia_imgui_color_convert_rgb_to_hsv(float r, float g, float b, float * out_h, float * out_s, float * out_v) {
    return ImGui::ColorConvertRGBtoHSV(r, g, b, *out_h, *out_s, *out_v);
}

void raia_imgui_color_convert_hsv_to_rgb(float h, float s, float v, float * out_r, float * out_g, float * out_b) {
    return ImGui::ColorConvertHSVtoRGB(h, s, v, *out_r, *out_g, *out_b);
}

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