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
void raia_imgui_show_demo_window();
void raia_imgui_impl_opengl3_new_frame();
void raia_imgui_impl_glfw_new_frame();
void raia_imgui_new_frame();
bool raia_imgui_check_version();
ImGuiContext* raia_imgui_create_context();
ImGuiIO *raia_imgui_getio();
void raia_imgui_getio_config_flags(int config_flags);
void raia_imgui_getio_config_viewports_no_auto_merge(bool flag);
void raia_imgui_getio_config_viewports_no_task_bar_icon(bool flag);
void raia_imgui_getio_font_global_scale(float num);
float raia_imgui_getio_get_framerate();
void raia_imgui_style_colors_dark();
void raia_imgui_style_colors_light();
void raia_imgui_style_colors_classic();
ImGuiStyle *raia_imgui_getstyle();
void raia_imgui_getstyle_window_border_size(float n);
void raia_imgui_getstyle_window_rounding(float n);
void raia_imgui_getstyle_scale_all_sizes(float n);
void raia_imgui_set_style_colors(int col, float red, float green, float blue, float alpha);
bool raia_imgui_impl_glfw_init_for_opengl(GLFWwindow* window, bool install_callbacks);
bool raia_imgui_impl_opengl3_init(const char *glsl_version);
ImFont* raia_imgui_getio_fonts_add_font_default();
const ImWchar *raia_imgui_getio_fonts_get_glyph_ranges_japanese();
ImFont *raia_imgui_getio_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const ImFontConfig *font_cfg, const ImWchar *glyph_ranges);
void raia_imgui_getio_font_default(ImFont *font);
void raia_imgui_assert(bool expr);
void raia_imgui_impl_opengl3_shutdown();
void raia_imgui_impl_glfw_shutdown();
void raia_imgui_destroy_context();
void raia_imgui_render();
ImDrawData *raia_imgui_get_draw_data();
void raia_imgui_impl_opengl3_render_draw_data(ImDrawData* draw_data);
void raia_imgui_update_platform_windows();
void raia_imgui_render_platform_windows_default();
void raia_imgui_begin(const char* name, bool* p_open, ImGuiWindowFlags flags);
void raia_imgui_end();
void raia_imgui_text(const char *text);
bool raia_imgui_button(const char *label, float width, float height);
void raia_imgui_image(void *texture_id, float width, float height);
bool raia_imgui_checkbox(const char *label, bool *v);
float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max);
bool raia_imgui_color_edit_3(const char *label, float *col);
void raia_imgui_same_line();
void raia_imgui_push_style_var_float(ImGuiStyleVar idx, float val);
void raia_imgui_push_style_var_vec2(ImGuiStyleVar idx, float x, float y);
void raia_imgui_pop_style_var(int count);
void raia_imgui_push_style_color_u32(ImGuiCol idx, ImU32 col);
void raia_imgui_push_style_color_vec4(ImGuiCol idx, float x, float y, float z, float w);
void raia_imgui_pop_style_color(int count);
ImGuiViewport* raia_imgui_get_main_viewport();
void raia_imgui_set_next_window_pos(float pos_x, float pos_y, ImGuiCond cond = 0, float pivot_x = 0, float pivot_y = 0);
void raia_imgui_set_next_window_viewport(ImGuiViewport* viewport);
void raia_imgui_set_next_window_bg_alpha(float alpha);
void raia_imgui_separator();
}

#endif //RAIA_GUI_RAIA_IMGUI_H
