#ifndef RAIA_DRAW_RAIA_DRAW_H
#define RAIA_DRAW_RAIA_DRAW_H

#include <stdio.h>
#include "duktape/duktape.h"
#include "util/util_math.h"
#include "util/util_pixel.h"
#include "util/util_utf8.h"
#include "util/util_primitive3d.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "wrapper/wrapper_stb_truetype.h"
#include "wrapper/wrapper_stb_image.h"
#include "platforms.h"
#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT duk_ret_t raia_draw_context_init(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_surface_init(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_noise(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_point(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_point_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_point_alpha(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_line(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_line_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_fill_rect(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_fill_rect_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_fill_rect_fast(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_fill_rect_alpha(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_ellipse(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_ellipse_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse_smooth(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_fill_circle(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_blend_pixels_rgba_to_rgb(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_blend_pixels_rgba_to_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_load_image(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_load_and_blend_image_rgb(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_load_and_blend_image_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_font_open(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_font_init_buffer(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_text_rgba(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_get_text_size(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_text_rgba_old(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_d3m_init(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_d3m_set_camera(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_draw_d3m_calc_position(duk_context *ctx);

#endif //RAIA_DRAW_RAIA_DRAW_H
