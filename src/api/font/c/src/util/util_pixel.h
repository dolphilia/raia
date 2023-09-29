//
// Created by dolphilia on 2023/01/21.
//

#ifndef RAIA_DRAW_UTIL_PIXEL_H
#define RAIA_DRAW_UTIL_PIXEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} raia_color_t;

typedef struct {
    int32_t x;
    int32_t y;
} raia_point_t;

typedef struct {
    raia_point_t start;
    raia_point_t end;
} raia_segment_t;

typedef struct {
    int32_t width;
    int32_t height;
} raia_size_t;

raia_color_t get_pixel_color(const uint8_t *pixels, raia_point_t point, raia_size_t canvas, int32_t samples_per_pixel);
raia_color_t get_pixel_color_rgba(const uint8_t *pixels, raia_point_t point, raia_size_t canvas, int32_t samples_per_pixel);
void set_pixel_rgb(uint8_t *pixels, raia_point_t point, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void set_pixel_rgb_alpha(uint8_t *pixels, raia_point_t point, raia_color_t color, uint8_t alpha, raia_size_t canvas, int32_t samples_per_pixel);
void set_pixel_rgba(uint8_t *pixels, raia_point_t point, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void set_line_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void set_line_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void fill_rect_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void fill_rect_rgb_fast(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t size, int32_t samples_per_pixel);
void fill_rect_rgb_alpha(uint8_t *pixels, raia_segment_t segment, raia_color_t color, uint8_t alpha, raia_size_t canvas, int32_t samples_per_pixel);
void fill_rect_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void draw_ellipse(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void draw_ellipse_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void draw_filled_ellipse(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void draw_filled_ellipse_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void draw_filled_ellipse_smooth(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void set_circle_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void fill_circle_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel);
void blend_pixels_rgba_to_rgb(
        uint8_t *pixels_rgb, int pixels_rgb_width, int pixels_rgb_height,
        uint8_t *pixels_rgba, int pixels_rgba_width, int pixels_rgba_height,
        int position_x, int position_y,
        int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2);
void blend_pixels_rgba_to_rgba(
        uint8_t *pixels_rgba_a, int pixels_rgba_a_width, int pixels_rgba_a_height,
        uint8_t *pixels_rgba_b, int pixels_rgba_b_width, int pixels_rgba_b_height,
        int position_x, int position_y,
        int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2);

#endif //RAIA_DRAW_UTIL_PIXEL_H
