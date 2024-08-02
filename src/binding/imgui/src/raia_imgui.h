//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_IMGUI_H
#define RAIA_GUI_RAIA_IMGUI_H

#include "../../../third_party/cpp/ocornut/imgui/imgui.h"
#include "../../../third_party/cpp/ocornut/imgui/imgui_impl_glfw.h"
#include "../../../third_party/cpp/ocornut/imgui/imgui_impl_opengl3.h"

extern "C" {
#include <time.h>
#include "../../../common/c/utility/export_api.h"
#include "../../../common/c/utility/platform.h"
#include "../../../common/c/wrapper/wrapper_yyjson.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif
}

//#define GL_SILENCE_DEPRECATION
//#define IMGUI_IMPL_OPENGL_ES2
//#if defined(IMGUI_IMPL_OPENGL_ES2)
//#include "GLES3/gl32.h"
//#endif
//#include <random>
// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
//#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
//#pragma comment(lib, "legacy_stdio_definitions")
//#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
//#ifdef __EMSCRIPTEN__
//#include "../libs/emscripten/emscripten_mainloop_stub.h"
//#endif

extern "C" {
// ヘルパーマクロ
void raia_imgui_assert(bool expr);
bool raia_imgui_check_version();

// コンテキストの作成とアクセス
ImGuiContext* raia_imgui_create_context(ImFontAtlas* shared_font_atlas);
void raia_imgui_destroy_context(ImGuiContext* ctx);
ImGuiContext* raia_imgui_get_current_context();
void raia_imgui_set_current_context(ImGuiContext* ctx);

// メイン
ImGuiIO *raia_imgui_getio();
ImGuiStyle *raia_imgui_getstyle();
void raia_imgui_new_frame();
void raia_imgui_end_frame();
void raia_imgui_render();
ImDrawData *raia_imgui_get_draw_data();

// デモ・デバッグ・情報
void raia_imgui_show_demo_window(bool *p_open);
void raia_imgui_show_metrics_window(bool* p_open /* = NULL */);
void raia_imgui_show_debug_log_window(bool* p_open /* = NULL */);
void raia_imgui_show_stack_tool_window(bool* p_open /* = NULL */);
void raia_imgui_show_about_window(bool* p_open /* = NULL */);
void raia_imgui_show_style_editor(ImGuiStyle* ref /* = NULL */);
bool raia_imgui_show_style_selector(const char* label);
void raia_imgui_show_font_selector(const char* label);
void raia_imgui_show_user_guide();
const char* raia_imgui_get_version();

// スタイル
void raia_imgui_style_colors_dark(ImGuiStyle* dst);
void raia_imgui_style_colors_light(ImGuiStyle* dst);
void raia_imgui_style_colors_classic(ImGuiStyle* dst);

// ウィンドウ
bool raia_imgui_begin(const char* name, bool* p_open, ImGuiWindowFlags flags);
void raia_imgui_end();

// 子ウィンドウ
bool raia_imgui_begin_child(const char* str_id, float size_x, float size_y, bool border, ImGuiWindowFlags flags);
bool raia_imgui_begin_child_2(ImGuiID id, float size_x, float size_y, bool border, ImGuiWindowFlags flags);
void raia_imgui_end_child();

// ウィンドウ・ユーティリティ
bool raia_imgui_is_window_appearing();
bool raia_imgui_is_window_collapsed();
bool raia_imgui_is_window_focused(ImGuiFocusedFlags flags /* = 0 */);
bool raia_imgui_is_window_hovered(ImGuiHoveredFlags flags /* = 0 */);
ImDrawList* raia_imgui_get_window_draw_list();
float raia_imgui_get_window_pos_x();
float raia_imgui_get_window_pos_y();
float raia_imgui_get_window_width();
float raia_imgui_get_window_height();

// ウィンドウ操作
void raia_imgui_set_next_window_pos(float pos_x, float pos_y, ImGuiCond cond /* = 0 */, float pivot_x /* = 0 */, float pivot_y /* = 0 */);
void raia_imgui_set_next_window_size(float size_x, float size_y, ImGuiCond cond /* = 0 */);
void raia_imgui_set_next_window_size_constraints(float size_min_x, float size_min_y, float size_max_x, float size_max_y, ImGuiSizeCallback custom_callback /* = NULL*/, void* custom_callback_data /* = NULL*/);
void raia_imgui_set_next_window_content_size(float size_x, float size_y);
void raia_imgui_set_next_window_collapsed(bool collapsed, ImGuiCond cond /*= 0*/);
void raia_imgui_set_next_window_focus();
void raia_imgui_set_next_window_scroll(float scroll_x, float scroll_y);
void raia_imgui_set_next_window_bg_alpha(float alpha);
void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport);
void raia_imgui_set_next_window_viewport_2(ImGuiID viewport_id);
void raia_imgui_set_window_pos(float pos_x, float pos_y, ImGuiCond cond /* = 0*/);
void raia_imgui_set_window_size(float size_x, float size_y, ImGuiCond cond /* = 0 */);
void raia_imgui_set_window_collapsed(bool collapsed, ImGuiCond cond /* = 0*/);
void raia_imgui_set_window_focus();
void raia_imgui_set_window_font_scale(float scale);
void raia_imgui_set_window_pos_2(const char* name, float pos_x, float pos_y, ImGuiCond cond /*= 0*/);
void raia_imgui_set_window_size_2(const char* name, float size_x, float size_y, ImGuiCond cond /*= 0*/);
void raia_imgui_set_window_collapsed_2(const char* name, bool collapsed, ImGuiCond cond /*= 0*/);
void raia_imgui_set_window_focus_2(const char* name);

// コンテンツ領域

float raia_imgui_get_content_region_avail_x();
float raia_imgui_get_content_region_avail_y();
float raia_imgui_get_content_region_max_x();
float raia_imgui_get_content_region_max_y();
float raia_imgui_get_window_content_region_min_x();
float raia_imgui_get_window_content_region_min_y();
float raia_imgui_get_window_content_region_max_x();
float raia_imgui_get_window_content_region_max_y();

// ウィンドウ・スクロール
float raia_imgui_get_scroll_x();
float raia_imgui_get_scroll_y();
void raia_imgui_set_scroll_x(float scroll_x);
void raia_imgui_set_scroll_y(float scroll_y);
float raia_imgui_get_scroll_max_x();
float raia_imgui_get_scroll_max_y();
void raia_imgui_set_scroll_here_x(float center_x_ratio /* = 0.5f*/);
void raia_imgui_set_scroll_here_y(float center_y_ratio /* = 0.5f*/);
void raia_imgui_set_scroll_from_pos_x(float local_x, float center_x_ratio /* = 0.5f*/);
void raia_imgui_set_scroll_from_pos_y(float local_y, float center_y_ratio /* = 0.5f*/);

// パラメータ・スタック（共有）
void raia_imgui_push_font(ImFont* font);
void raia_imgui_pop_font();
void raia_imgui_push_style_color(ImGuiCol idx, ImU32 col);
void raia_imgui_push_style_color_2(ImGuiCol idx, float col_x, float col_y, float col_z, float col_w);
void raia_imgui_pop_style_color_3(int count /* = 1*/);
void raia_imgui_push_style_var(ImGuiStyleVar idx, float val);
void raia_imgui_push_style_var_2(ImGuiStyleVar idx, float val_x, float val_y);
void raia_imgui_pop_style_var_3(int count /* = 1*/);
void raia_imgui_push_tab_stop(bool tab_stop);
void raia_imgui_pop_tab_stop();
void raia_imgui_push_button_repeat(bool repeat);
void raia_imgui_pop_button_repeat();

// パラメータ・スタック（現在のウィンドウ）
void raia_imgui_push_item_width(float item_width);
void raia_imgui_pop_item_width();
void raia_imgui_set_next_item_width(float item_width);
float raia_imgui_calc_item_width();
void raia_imgui_push_text_wrap_pos(float wrap_local_pos_x /* = 0.0f*/);
void raia_imgui_pop_text_wrap_pos();

// スタイルの読み込みとアクセス
ImFont* raia_imgui_get_font();
float raia_imgui_get_font_size();
float raia_imgui_get_font_tex_uv_white_pixel_x();
float raia_imgui_get_font_tex_uv_white_pixel_y();
ImU32 raia_imgui_get_color_u32(ImGuiCol idx, float alpha_mul /* = 1.0f*/);
ImU32 raia_imgui_get_color_u32_2(float col_x, float col_y, float col_z, float col_w);
ImU32 raia_imgui_get_color_u32_3(ImU32 col);
float raia_imgui_get_style_color_vec4_x(ImGuiCol idx);
float raia_imgui_get_style_color_vec4_y(ImGuiCol idx);
float raia_imgui_get_style_color_vec4_z(ImGuiCol idx);
float raia_imgui_get_style_color_vec4_w(ImGuiCol idx);

// カーソル / レイアウト
void raia_imgui_separator();
void raia_imgui_same_line();
void raia_imgui_new_line();
void raia_imgui_spacing();
void raia_imgui_dummy(float size_x, float size_y);
void raia_imgui_indent(float indent_w /* = 0.0f*/);
void raia_imgui_unindent(float indent_w /* = 0.0f*/);
void raia_imgui_begin_group();
void raia_imgui_end_group();
float raia_imgui_get_cursor_pos_x();
float raia_imgui_get_cursor_pos_y();
void raia_imgui_set_cursor_pos(float local_pos_x, float local_pos_y);
void raia_imgui_set_cursor_pos_x(float local_x);
void raia_imgui_set_cursor_pos_y(float local_y);
float raia_imgui_get_cursor_start_pos_x();
float raia_imgui_get_cursor_start_pos_y();
float raia_imgui_get_cursor_screen_pos_x();
float raia_imgui_get_cursor_screen_pos_y();
void raia_imgui_set_cursor_screen_pos(float pos_x, float pos_y);
void raia_imgui_align_text_to_frame_padding();
float raia_imgui_get_text_line_height();
float raia_imgui_get_text_line_height_with_spacing();
float raia_imgui_get_frame_height();
float raia_imgui_get_frame_height_with_spacing();

// IDスタック / スコープ
void raia_imgui_push_id(const char* str_id);
void raia_imgui_push_id_2(const char* str_id_begin, const char* str_id_end);
void raia_imgui_push_id_3(const void* ptr_id);
void raia_imgui_push_id_4(int int_id);
void raia_imgui_pop_id();
ImGuiID raia_imgui_get_id(const char* str_id);
ImGuiID raia_imgui_get_id_2(const char* str_id_begin, const char* str_id_end);
ImGuiID raia_imgui_get_id_3(const void* ptr_id);

// ウィジェット: テキスト
void raia_imgui_text_unformatted(const char* text, const char* text_end /* = NULL */);
void raia_imgui_text(const char *text);
void raia_imgui_text_colored(float col_x, float col_y, float col_z, float col_w, const char* text);
void raia_imgui_text_disabled(const char* text);
void raia_imgui_text_wrapped(const char* text);
void raia_imgui_label_text(const char* label, const char* text);
void raia_imgui_bullet_text(const char* text);
void raia_imgui_separator_text(const char* label);

// ウィジェット: メイン
bool raia_imgui_button(const char *label, float width, float height);
bool raia_imgui_small_button(const char* label);
bool raia_imgui_invisible_button(const char* str_id, float size_x, float size_y, ImGuiButtonFlags flags /* = 0*/);
bool raia_imgui_arrow_button(const char* str_id, ImGuiDir dir);
bool raia_imgui_checkbox(const char *label, bool *v);
bool raia_imgui_checkbox_flags(const char* label, int* flags, int flags_value);
bool raia_imgui_checkbox_flags_2(const char* label, unsigned int* flags, unsigned int flags_value);
bool raia_imgui_radio_button(const char* label, bool active);
bool raia_imgui_radio_button_2(const char* label, int* v, int v_button);
void raia_imgui_progress_bar(float fraction, float size_arg_x /*= -FLT_MIN*/, float size_arg_y /*= 0*/, const char* overlay /* = NULL*/);
void raia_imgui_bullet();

// ウィジェット: 画像
void raia_imgui_image(void *texture_id, float width, float height);
bool raia_imgui_image_button(const char* str_id, ImTextureID user_texture_id, float size_x, float size_y,
                             float uv0_x /* = 0 */, float uv0_y /* = 0 */,
                             float uv1_x /* = 1 */, float uv1_y /* = 1 */,
                             float bg_col_x /* = 0 */, float bg_col_y /* = 0 */, float bg_col_z /* = 0 */, float bg_col_w /* = 0 */,
                             float tint_col_x /* = 1 */, float tint_col_y /* = 1 */, float tint_col_z /* = 1 */, float tint_col_w /* = 1 */);

// ウィジェット: コンボボックス（ドロップダウン）
bool raia_imgui_begin_combo(const char* label, const char* preview_value, ImGuiComboFlags flags /* = 0 */);
void raia_imgui_end_combo();
bool raia_imgui_combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items /* = -1 */);
bool raia_imgui_combo_2(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items /* = -1 */);
bool raia_imgui_combo_3(const char* label, int* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items /* = -1 */);

// ウィジェット: ドラッグスライダー
bool raia_imgui_drag_float(const char* label, float* v, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_float2(const char* label, float v[2], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_float3(const char* label, float v[3], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_float4(const char* label, float v[4], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_float_range2(const char* label, float* v_current_min, float* v_current_max, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, const char* format_max /* = NULL */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_int(const char* label, int* v, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */) ;
bool raia_imgui_drag_int2(const char* label, int v[2], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_int3(const char* label, int v[3], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_int4(const char* label, int v[4], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_int_range2(const char* label, int* v_current_min, int* v_current_max, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, const char* format_max /* = NULL */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_scalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_drag_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */);

// ウィジェット: レギュラー・スライダー
float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_float2(const char* label, float v[2], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_float3(const char* label, float v[3], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_float4(const char* label, float v[4], float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_angle(const char* label, float* v_rad, float v_degrees_min /* = -360.0f */, float v_degrees_max /* = +360.0f */, const char* format /* = "%.0f deg" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_int(const char* label, int* v, int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_int2(const char* label, int v[2], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_int3(const char* label, int v[3], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_int4(const char* label, int v[4], int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_scalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_slider_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_v_slider_float(const char* label, float size_x, float size_y, float* v, float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_v_slider_int(const char* label, float size_x, float size_y, int* v, int v_min, int v_max, const char* format /* = "%d" */, ImGuiSliderFlags flags /* = 0 */);
bool raia_imgui_v_slider_scalar(const char* label, float size_x, float size_y, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, ImGuiSliderFlags flags /* = 0 */);

// ウィジェット: キーボード入力
bool raia_imgui_input_text(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */);
bool raia_imgui_input_text_multiline(const char* label, char* buf, size_t buf_size, float size_x /* = 0 */, float size_y /* = 0 */, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */);
bool raia_imgui_input_text_with_hint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags /* = 0 */, ImGuiInputTextCallback callback /* = NULL */, void* user_data /* = NULL */);
bool raia_imgui_input_float(const char* label, float* v, float step /* = 0.0f */, float step_fast /* = 0.0f */, const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_float2(const char* label, float v[2], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_float3(const char* label, float v[3], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_float4(const char* label, float v[4], const char* format /* = "%.3f" */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_int(const char* label, int* v, int step /* = 1 */, int step_fast /* = 100 */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_int2(const char* label, int v[2], ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_int3(const char* label, int v[3], ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_int4(const char* label, int v[4], ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_double(const char* label, double* v, double step /* = 0.0 */, double step_fast /* = 0.0 */, const char* format /* = "%.6f" */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_scalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, ImGuiInputTextFlags flags /* = 0 */);
bool raia_imgui_input_scalar_n(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, ImGuiInputTextFlags flags /* = 0 */);

// ウィジェット: カラーエディター/ピッカー
bool raia_imgui_color_edit3(const char *label, float *col, ImGuiColorEditFlags flags /* = 0 */);
bool raia_imgui_color_edit4(const char* label, float col[4], ImGuiColorEditFlags flags /* = 0 */);
bool raia_imgui_color_picker3(const char* label, float col[3], ImGuiColorEditFlags flags /* = 0 */);
bool raia_imgui_color_picker4(const char* label, float col[4], ImGuiColorEditFlags flags /* = 0 */, const float* ref_col /* = NULL */);
bool raia_imgui_color_button(const char* desc_id, float col_x, float col_y, float col_z, float col_w, ImGuiColorEditFlags flags /* = 0 */, float size_x /* = 0 */, float size_y /* = 0 */);
void raia_imgui_set_color_edit_options(ImGuiColorEditFlags flags);

// ウィジェット: ツリー
bool raia_imgui_tree_node(const char* label);
bool raia_imgui_tree_node_2(const char* str_id, const char* text);
bool raia_imgui_tree_node_3(const void* ptr_id, const char* text);
bool raia_imgui_tree_node_ex(const char* label, int flags /* = 0 */);
bool raia_imgui_tree_node_ex_2(const char* str_id, int flags, const char* text);
bool raia_imgui_tree_node_ex_3(const void* ptr_id, int flags, const char* text);
void raia_imgui_tree_push(const char* str_id);
void raia_imgui_tree_push_2(const void* ptr_id);
void raia_imgui_tree_pop();
float raia_imgui_get_tree_node_to_label_spacing();
bool raia_imgui_collapsing_header(const char* label, int flags /* = 0 */);
bool raia_imgui_collapsing_header_2(const char* label, bool* p_visible, int flags /* = 0 */);
void raia_imgui_set_next_item_open(bool is_open, int cond /* = 0 */);

// ウィジェット: セレクタブル
bool raia_imgui_selectable(const char* label, bool selected /* = false */, ImGuiSelectableFlags flags /* = 0 */, float size_x /* = 0*/, float size_y /* = 0*/);
bool raia_imgui_selectable_2(const char* label, bool* p_selected, ImGuiSelectableFlags flags /* = 0 */,  float size_x /* = 0*/, float size_y /* = 0*/);

// ウィジェット: リストボックス
bool raia_imgui_begin_list_box(const char* label, float size_x /* = 0*/, float size_y /* = 0*/);
void raia_imgui_end_list_box();
bool raia_imgui_list_box(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items /* = -1 */);
bool raia_imgui_list_box_2(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items /* = -1 */);

// ウィジェット: データプロット
void raia_imgui_plot_lines(const char* label, const float* values, int values_count,
                           int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                           float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                           float graph_size_x /* = 0*/, float graph_size_y /* = 0 */, int stride /* = sizeof(float) */);
void raia_imgui_plot_lines_2(const char* label, float(*values_getter)(void* data, int idx),
                             void* data, int values_count, int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                             float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                             float graph_size_x /* = 0*/, float graph_size_y /* = 0 */);
void raia_imgui_plot_histogram(const char* label, const float* values, int values_count, int values_offset /* = 0 */,
                               const char* overlay_text /* = NULL */, float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                               float graph_size_x /* = 0*/, float graph_size_y /* = 0 */, int stride /* = sizeof(float) */);
void raia_imgui_plot_histogram_2(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count,
                                 int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                                 float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                                 float graph_size_x /* = 0*/, float graph_size_y /* = 0 */);

// ウィジェット: Value() ヘルパー
void raia_imgui_value(const char* prefix, bool b);
void raia_imgui_value_2(const char* prefix, int v);
void raia_imgui_value_3(const char* prefix, unsigned int v);
void raia_imgui_value_4(const char* prefix, float v, const char* float_format /* = NULL */);

// ウィジェット: メニュー
bool raia_imgui_begin_menu_bar();
void raia_imgui_end_menu_bar();
bool raia_imgui_begin_main_menu_bar();
void raia_imgui_end_main_menu_bar();
bool raia_imgui_begin_menu(const char* label, bool enabled /* = true */);
void raia_imgui_end_menu();
bool raia_imgui_menu_item(const char* label, const char* shortcut /* = NULL */, bool selected /* = false */, bool enabled /* = true */);
bool raia_imgui_menu_item_2(const char* label, const char* shortcut, bool* p_selected, bool enabled /* = true */);

// ツールチップ
bool raia_imgui_begin_tooltip();
void raia_imgui_end_tooltip();
void raia_imgui_set_tooltip(const char* text);
bool raia_imgui_begin_item_tooltip();
void raia_imgui_set_item_tooltip(const char* text);

// ポップアップ・モーダル
bool raia_imgui_begin_popup(const char* str_id, ImGuiWindowFlags flags /* = 0 */);
bool raia_imgui_begin_popup_modal(const char* name, bool* p_open /* = NULL */, ImGuiWindowFlags flags /* = 0 */);
void raia_imgui_end_popup();
void raia_imgui_open_popup(const char* str_id, ImGuiPopupFlags popup_flags /* = 0 */);
void raia_imgui_open_popup_2(ImGuiID id, ImGuiPopupFlags popup_flags /* = 0 */);
void raia_imgui_open_popup_on_item_click(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */);
void raia_imgui_close_current_popup();
bool raia_imgui_begin_popup_context_item(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */);
bool raia_imgui_begin_popup_context_window(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */);
bool raia_imgui_begin_popup_context_void(const char* str_id /* = NULL */, ImGuiPopupFlags popup_flags /* = 1 */);
bool raia_imgui_is_popup_open(const char* str_id, ImGuiPopupFlags flags /* = 0 */);

// テーブル
bool raia_imgui_begin_table(const char* str_id, int column, ImGuiTableFlags flags /* = 0 */, float outer_size_x /* = 0 */, float outer_size_y /* = 0 */, float inner_width /* = 0.0f */);
void raia_imgui_end_table();
void raia_imgui_table_next_row(ImGuiTableRowFlags row_flags /* = 0 */, float min_row_height /* = 0.0f */);
bool raia_imgui_table_next_column();
bool raia_imgui_table_set_column_index(int column_n);
void raia_imgui_table_setup_column(const char* label, ImGuiTableColumnFlags flags /* = 0 */, float init_width_or_weight /* = 0.0f */, ImGuiID user_id /* = 0 */);
void raia_imgui_table_setup_scroll_freeze(int cols, int rows);
void raia_imgui_table_headers_row();
void raia_imgui_table_header(const char* label);
ImGuiTableSortSpecs* raia_imgui_table_get_sort_specs();
int raia_imgui_table_get_column_count();
int raia_imgui_table_get_column_index();
int raia_imgui_table_get_row_index();
const char* raia_imgui_table_get_column_name(int column_n /* = -1 */);
ImGuiTableColumnFlags raia_imgui_table_get_column_flags(int column_n /* = -1 */);
void raia_imgui_table_set_column_enabled(int column_n, bool v);
void raia_imgui_table_set_bg_color(ImGuiTableBgTarget target, ImU32 color, int column_n /* = -1 */);
void raia_imgui_columns(int count /* = 1 */, const char* id /* = NULL */, bool border /* = true */); // ここからレガシーなテーブルAPI
void raia_imgui_next_column();
int raia_imgui_get_column_index();
float raia_imgui_get_column_width(int column_index /* = -1 */);
void raia_imgui_set_column_width(int column_index, float width);
float raia_imgui_get_column_offset(int column_index /* = -1 */);
void raia_imgui_set_column_offset(int column_index, float offset_x);
int raia_imgui_get_columns_count();

// タブバー、タブ
bool raia_imgui_begin_tab_bar(const char* str_id, ImGuiTabBarFlags flags /* = 0 */);
void raia_imgui_end_tab_bar();
bool raia_imgui_begin_tab_item(const char* label, bool* p_open /* = NULL */, ImGuiTabItemFlags flags /* = 0 */);
void raia_imgui_end_tab_item();
bool raia_imgui_tab_item_button(const char* label, ImGuiTabItemFlags flags /* = 0 */);
void raia_imgui_set_tab_item_closed(const char* tab_or_docked_window_label);

// ロギング/キャプチャ
void raia_imgui_log_to_tty(int auto_open_depth /* = -1 */);
void raia_imgui_log_to_file(int auto_open_depth /* = -1 */, const char* filename /* = NULL */);
void raia_imgui_log_to_clipboard(int auto_open_depth /* = -1 */);
void raia_imgui_log_finish();
void raia_imgui_log_buttons();
void raia_imgui_log_text(const char* text);

// 無効化 [BETA API]
void raia_imgui_begin_disabled(bool disabled /* = true */);
void raia_imgui_end_disabled();

// クリッピング
void raia_imgui_push_clip_rect(float clip_rect_min_x, float clip_rect_min_y, float clip_rect_max_x, float clip_rect_max_y, bool intersect_with_current_clip_rect);
void raia_imgui_pop_clip_rect();

// フォーカス, アクティブ化
void raia_imgui_set_item_default_focus();
void raia_imgui_set_keyboard_focus_here(int offset /* = 0 */);

// オーバーラッピング・モード
void raia_imgui_set_next_item_allow_overlap();

// アイテム/ウィジェット ユーティリティとクエリ関数
bool raia_imgui_is_item_hovered(ImGuiHoveredFlags flags /* = 0 */);
bool raia_imgui_is_item_active();
bool raia_imgui_is_item_focused();
bool raia_imgui_is_item_clicked(ImGuiMouseButton mouse_button /* = 0 */);
bool raia_imgui_is_item_visible();
bool raia_imgui_is_item_edited();
bool raia_imgui_is_item_activated();
bool raia_imgui_is_item_deactivated();
bool raia_imgui_is_item_deactivated_after_edit();
bool raia_imgui_is_item_toggled_open();
bool raia_imgui_is_any_item_hovered();
bool raia_imgui_is_any_item_active();
bool raia_imgui_is_any_item_focused();
ImGuiID raia_imgui_get_item_id();
float raia_imgui_get_item_rect_min_x();
float raia_imgui_get_item_rect_min_y();
float raia_imgui_get_item_rect_max_x();
float raia_imgui_get_item_rect_max_y();
float raia_imgui_get_item_rect_size_x();
float raia_imgui_get_item_rect_size_y();

// ビューポート
ImGuiViewport* raia_imgui_get_main_viewport();

// 背景／前景ドローリスト
ImDrawList* raia_imgui_get_background_draw_list();
ImDrawList* raia_imgui_get_foreground_draw_list();

// その他ユーティリティ
bool raia_imgui_is_rect_visible(float size_x, float size_y);
bool raia_imgui_is_rect_visible_2(float rect_min_x, float rect_min_y, float rect_max_x, float rect_max_y);
double raia_imgui_get_time();
int raia_imgui_get_frame_count();
ImDrawListSharedData* raia_imgui_get_draw_list_shared_data();
const char* raia_imgui_get_style_color_name(ImGuiCol idx);
void raia_imgui_set_state_storage(ImGuiStorage* storage);
ImGuiStorage* raia_imgui_get_state_storage();
bool raia_imgui_begin_child_frame(ImGuiID id, float size_x, float size_y, ImGuiWindowFlags flags /* = 0 */);
void raia_imgui_end_child_frame();

// テキスト・ユーティリティ
float raia_imgui_calc_text_size_x(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */);
float raia_imgui_calc_text_size_y(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */);

// カラーユーティリティ
float raia_imgui_color_convert_u32_to_float4_x(ImU32 in);
float raia_imgui_color_convert_u32_to_float4_y(ImU32 in);
float raia_imgui_color_convert_u32_to_float4_z(ImU32 in);
float raia_imgui_color_convert_u32_to_float4_w(ImU32 in);
ImU32 raia_imgui_color_convert_float4_to_u32(float in_x, float in_y, float in_z, float in_w);
void raia_imgui_color_convert_rgb_to_hsv(float r, float g, float b, float * out_h, float * out_s, float * out_v);
void raia_imgui_color_convert_hsv_to_rgb(float h, float s, float v, float * out_r, float * out_g, float * out_b);

// 入力ユーティリティ: キーボード/マウス/ゲームパッド
bool raia_imgui_is_key_down(ImGuiKey key);
bool raia_imgui_is_key_pressed(ImGuiKey key, bool repeat /* = true */);
bool raia_imgui_is_key_released(ImGuiKey key);
int raia_imgui_get_key_pressed_amount(ImGuiKey key, float repeat_delay, float rate);
const char* raia_imgui_get_key_name(ImGuiKey key);
void raia_imgui_set_next_frame_want_capture_keyboard(bool want_capture_keyboard);

// 入力ユーティリティ： マウス専用
bool raia_imgui_is_mouse_down(ImGuiMouseButton button);
bool raia_imgui_is_mouse_clicked(ImGuiMouseButton button, bool repeat /* = false */);
bool raia_imgui_is_mouse_released(ImGuiMouseButton button);
bool raia_imgui_is_mouse_double_clicked(ImGuiMouseButton button);
int raia_imgui_get_mouse_clicked_count(ImGuiMouseButton button);
bool raia_imgui_is_mouse_hovering_rect(float r_min_x, float r_min_y, float r_max_x, float r_max_y, bool clip /* = true */);
bool raia_imgui_is_mouse_pos_valid(const ImVec2* mouse_pos /* = NULL */);
bool raia_imgui_is_any_mouse_down();
float raia_imgui_get_mouse_pos_x();
float raia_imgui_get_mouse_pos_y();
float raia_imgui_get_mouse_pos_on_opening_current_popup_x();
float raia_imgui_get_mouse_pos_on_opening_current_popup_y();
bool raia_imgui_is_mouse_dragging(ImGuiMouseButton button, float lock_threshold /* = -1.0f */);
float raia_imgui_get_mouse_drag_delta_x(ImGuiMouseButton button /* = 0 */, float lock_threshold /* = -1.0f */);
float raia_imgui_get_mouse_drag_delta_y(ImGuiMouseButton button /* = 0 */, float lock_threshold /* = -1.0f */);
void raia_imgui_reset_mouse_drag_delta(ImGuiMouseButton button /* = 0 */);
ImGuiMouseCursor raia_imgui_get_mouse_cursor();
void raia_imgui_set_mouse_cursor(ImGuiMouseCursor cursor_type);
void raia_imgui_set_next_frame_want_capture_mouse(bool want_capture_mouse);

// クリップボードユーティリティ
const char* raia_imgui_get_clipboard_text();
void raia_imgui_set_clipboard_text(const char* text);

// 設定/.Ini ユーティリティ
void raia_imgui_load_ini_settings_from_disk(const char* ini_filename);
void raia_imgui_load_ini_settings_from_memory(const char* ini_data, size_t ini_size /* = 0 */);
void raia_imgui_save_ini_settings_to_disk(const char* ini_filename);
const char* raia_imgui_save_ini_settings_to_memory(size_t* out_ini_size /* = NULL */);

// デバッグ・ユーティリティ
void raia_imgui_debug_text_encoding(const char* text);
bool raia_imgui_debug_check_version_and_data_layout(const char* version_str, size_t sz_io, size_t sz_style, size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx);

// メモリ・アロケータ
void raia_imgui_set_allocator_functions(ImGuiMemAllocFunc alloc_func, ImGuiMemFreeFunc free_func, void* user_data /* = NULL */);
void raia_imgui_get_allocator_functions(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data);
void* raia_imgui_mem_alloc(size_t size);
void raia_imgui_mem_free(void* ptr);

// -- ここから拡張

// FLT_MIN MAX
double raia_get_flt_min();
double raia_get_flt_max();

// imgui.cpp
void raia_imgui_update_platform_windows();
void raia_imgui_render_platform_windows_default();

// impl GLFW
bool raia_imgui_impl_glfw_init_for_opengl(GLFWwindow* window, bool install_callbacks);
void raia_imgui_impl_glfw_new_frame();
void raia_imgui_impl_glfw_shutdown();

// impl OpenGL3
bool raia_imgui_impl_opengl3_init(const char *glsl_version);
void raia_imgui_impl_opengl3_new_frame();
void raia_imgui_impl_opengl3_render_draw_data(ImDrawData* draw_data);
void raia_imgui_impl_opengl3_shutdown();

// GetIO ユーティリティ
void raia_imgui_io_set_config_flags(int config_flags);
void raia_imgui_io_set_config_viewports_no_auto_merge(bool flag);
void raia_imgui_io_set_config_viewports_no_task_bar_icon(bool flag);
void raia_imgui_io_set_font_global_scale(float num);
float raia_imgui_io_get_framerate();
void raia_imgui_io_set_font_default(ImFont *font);

// GetIO.Fonts ユーティリティ
ImFont* raia_imgui_io_fonts_add_font_default();
const ImWchar *raia_imgui_io_fonts_get_glyph_ranges_japanese();
ImFont *raia_imgui_io_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges);

// GetStyle ユーティリティ
void raia_imgui_style_set_alpha(float n);
void raia_imgui_style_set_disabled_alpha(float n);
void raia_imgui_style_set_window_padding(float x, float y);
void raia_imgui_style_set_window_rounding(float n);
void raia_imgui_style_set_window_border_size(float n);
void raia_imgui_style_set_window_min_size(float x, float y);
void raia_imgui_style_set_window_title_align(float x, float y);
void raia_imgui_style_set_window_menu_button_position(ImGuiDir n);
void raia_imgui_style_set_child_rounding(float n);
void raia_imgui_style_set_child_border_size(float n);
void raia_imgui_style_set_popup_rounding(float n);
void raia_imgui_style_set_popup_border_size(float n);
void raia_imgui_style_set_frame_padding(float x, float y);
void raia_imgui_style_set_frame_rounding(float n);
void raia_imgui_style_set_frame_border_size(float n);
void raia_imgui_style_set_item_spacing(float x, float y);
void raia_imgui_style_set_item_inner_spacing(float x, float y);
void raia_imgui_style_set_cell_padding(float x, float y);
void raia_imgui_style_set_touch_extra_padding(float x, float y);
void raia_imgui_style_set_indent_spacing(float n);
void raia_imgui_style_set_columns_min_spacing(float n);
void raia_imgui_style_set_scrollbar_size(float n);
void raia_imgui_style_set_scrollbar_rounding(float n);
void raia_imgui_style_set_grab_min_size(float n);
void raia_imgui_style_set_grab_rounding(float n);
void raia_imgui_style_set_log_slider_deadzone(float n);
void raia_imgui_style_set_tab_rounding(float n);
void raia_imgui_style_set_tab_border_size(float n);
void raia_imgui_style_set_tab_min_width_for_close_button(float n);
void raia_imgui_style_set_bolor_button_position(ImGuiDir n);
void raia_imgui_style_set_button_text_align(float x, float y);
void raia_imgui_style_set_selectable_text_align(float x, float y);
void raia_imgui_style_set_separator_text_border_size(float n);
void raia_imgui_style_set_separator_text_align(float x, float y);
void raia_imgui_style_set_separator_text_padding(float x, float y);
void raia_imgui_style_set_display_window_padding(float x, float y);
void raia_imgui_style_set_display_safe_area_padding(float x, float y);
void raia_imgui_style_set_mouse_cursor_scale(float n);
void raia_imgui_style_set_anti_aliased_lines(bool n);
void raia_imgui_style_set_anti_aliased_lines_use_tex(bool n);
void raia_imgui_style_set_anti_aliased_fill(bool n);
void raia_imgui_style_set_curve_tessellation_tol(float n);
void raia_imgui_style_set_circle_tessellation_max_error(float n);
void raia_imgui_style_scale_all_sizes(float n);
void raia_imgui_style_set_colors(int col, float red, float green, float blue, float alpha);

// Image ユーティリティ
void *raia_imgui_int_to_ptr(int value);
}

#endif //RAIA_GUI_RAIA_IMGUI_H