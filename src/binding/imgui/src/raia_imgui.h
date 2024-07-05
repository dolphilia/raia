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
void raia_imgui_set_next_window_pos(float pos_x, float pos_y, ImGuiCond cond = 0, float pivot_x = 0, float pivot_y = 0);
void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport);
void raia_imgui_set_next_window_bg_alpha(float alpha);

// コンテンツ領域

// ウィンドウ・スクロール

// パラメータ・スタック（共有）
void raia_imgui_push_style_color_u32(ImGuiCol idx, ImU32 col);
void raia_imgui_push_style_color_vec4(ImGuiCol idx, float x, float y, float z, float w);
void raia_imgui_pop_style_color(int count);
void raia_imgui_push_style_var_float(ImGuiStyleVar idx, float val);
void raia_imgui_push_style_var_vec2(ImGuiStyleVar idx, float x, float y);
void raia_imgui_pop_style_var(int count);

// パラメータ・スタック（現在のウィンドウ）

// スタイルの読み込みとアクセス

// カーソル / レイアウト
void raia_imgui_separator();
void raia_imgui_same_line();

// IDスタック / スコープ

// ウィジェット: テキスト
void raia_imgui_text(const char *text);

// ウィジェット: メイン
bool raia_imgui_button(const char *label, float width, float height);
bool raia_imgui_checkbox(const char *label, bool *v);

// ウィジェット: 画像
void raia_imgui_image(void *texture_id, float width, float height);

// ウィジェット: コンボボックス（ドロップダウン）

// ウィジェット: ドラッグスライダー

// ウィジェット: レギュラー・スライダー
float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max);

// ウィジェット: キーボード入力

// ウィジェット: カラーエディター/ピッカー
bool raia_imgui_color_edit_3(const char *label, float *col);

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
