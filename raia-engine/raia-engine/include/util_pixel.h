//
//  util_pixel.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef util_pixel_h
#define util_pixel_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} color_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} point_t;

color_t get_pixel_color(uint8_t *pixel_data, int32_t point_x, int32_t point_y, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
void set_pixel_rgb(uint8_t *pixel_data, int32_t point_x, int32_t point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
void set_pixel_rgb_protect_alpha(uint8_t *pixel_data, int32_t point_x, int32_t point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t protect_alpha, int32_t samples_per_pixel);
void set_line_rgb(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
void fill_rect_rgb(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
void set_circle_rgb(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
void fill_circle_rgb(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
//color_t get_color_hsv(int32_t hue, int32_t saturation, int32_t brightness);
//void clear_canvas_rgba(uint8_t *pixel_data, int32_t canvas_size_width, int32_t canvas_size_height, int32_t color_number);
//void set_pixel_rgba(uint8_t *pixel_data, int32_t point_x, int32_t point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel);
//void set_pixel_rgba_protect_alpha_fast(uint8_t *pixel_data, int32_t point_x, int32_t point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height, int32_t protect_alpha, int32_t index, int32_t samples_per_pixel);
//void set_line_rgba(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void fill_circle_rgba_smooth(uint8_t *pixel_data, double point_x, double point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height, double radius);
//void set_line_rgba_smooth(uint8_t *pixel_data, double start_point_x, double start_point_y, double end_point_x, double end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height, double radius, double interval);
//void set_line_rgba_smooth_i(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void fill_rect_rgba(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void fill_rect_rgba_slow(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void set_circle_rgba(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void fill_circle_rgba(uint8_t *pixel_data, int32_t start_point_x, int32_t start_point_y, int32_t end_point_x, int32_t end_point_y, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_size_width, int32_t canvas_size_height);
//void copy_pixel_data(uint8_t *pixel_data_dest, uint8_t *pixel_data_source, int32_t current_point_x, int32_t current_point_y, int32_t copy_point_x, int32_t copy_point_y, int32_t copy_size_width, int32_t copy_size_height, int32_t copy_defalut_size_width, int32_t copy_default_size_height, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_alpha, int32_t canvas_dest_size_width, int32_t canvas_dest_size_height, int32_t canvas_source_size_width, int32_t canvas_source_size_height, int8_t blend_mode, int8_t blend_opacity, int32_t samples_per_pixel);

#endif /* util_pixel_h */
