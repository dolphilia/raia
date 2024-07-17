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
//ImVec2 raia_imgui_GetCursorPos();
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
void raia_imgui_text(const char *text);

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

// ウィジェット: ドラッグスライダー

// ウィジェット: レギュラー・スライダー
float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max, const char* format /* = "%.3f" */, ImGuiSliderFlags flags /* = 0 */);

// ウィジェット: キーボード入力

// ウィジェット: カラーエディター/ピッカー
bool raia_imgui_color_edit_3(const char *label, float *col, ImGuiColorEditFlags flags /* = 0 */);

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
ImGuiViewport* raia_imgui_get_main_viewport();

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
void raia_imgui_getio_config_flags(int config_flags);
void raia_imgui_getio_config_viewports_no_auto_merge(bool flag);
void raia_imgui_getio_config_viewports_no_task_bar_icon(bool flag);
void raia_imgui_getio_font_global_scale(float num);
float raia_imgui_getio_get_framerate();
void raia_imgui_getio_font_default(ImFont *font);

// GetIO.Fonts ユーティリティ
ImFont* raia_imgui_getio_fonts_add_font_default();
const ImWchar *raia_imgui_getio_fonts_get_glyph_ranges_japanese();
ImFont *raia_imgui_getio_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges);

// GetStyle ユーティリティ
void raia_imgui_getstyle_window_border_size(float n);
void raia_imgui_getstyle_window_rounding(float n);
void raia_imgui_getstyle_scale_all_sizes(float n);
void raia_imgui_set_style_colors(int col, float red, float green, float blue, float alpha);

}

#endif //RAIA_GUI_RAIA_IMGUI_H
