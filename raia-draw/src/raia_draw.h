#ifndef RAIA_DRAW_RAIA_DRAW_H
#define RAIA_DRAW_RAIA_DRAW_H

#include <stdio.h>
#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"
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

RAIA_EXPORT const char * raia_draw_noise(const char *s);
RAIA_EXPORT const char * raia_draw_point(const char *s);
RAIA_EXPORT const char * raia_draw_point_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_point_alpha(const char *s);
RAIA_EXPORT const char * raia_draw_line(const char *s);
RAIA_EXPORT const char * raia_draw_line_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_fill_rect(const char *s);
RAIA_EXPORT const char * raia_draw_fill_rect_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_fill_rect_fast(const char *s);
RAIA_EXPORT const char * raia_draw_fill_rect_alpha(const char *s);
RAIA_EXPORT const char * raia_draw_ellipse(const char *s);
RAIA_EXPORT const char * raia_draw_ellipse_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_filled_ellipse(const char *s);
RAIA_EXPORT const char * raia_draw_filled_ellipse_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_filled_ellipse_smooth(const char *s);
RAIA_EXPORT const char * raia_draw_fill_circle(const char *s);
RAIA_EXPORT const char * raia_draw_blend_pixels_rgba_to_rgb(const char *s);
RAIA_EXPORT const char * raia_draw_blend_pixels_rgba_to_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_load_image(const char *s);
RAIA_EXPORT const char * raia_draw_load_and_blend_image_rgb(const char *s);
RAIA_EXPORT const char * raia_draw_load_and_blend_image_rgba(const char *s);
RAIA_EXPORT const char * raia_draw_d3m_init(const char *s);
RAIA_EXPORT const char * raia_draw_d3m_set_camera(const char *s);
RAIA_EXPORT const char * raia_draw_d3m_calc_position(const char *s);

#endif //RAIA_DRAW_RAIA_DRAW_H
