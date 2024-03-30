#include "raia_primitive.h"

RAIA_API void raia_draw_noise_cpu(uint8_t *pixels, int width, int height, int depth) {
    for (int i = 0; i < width * height * depth; i++) {
        pixels[i] = rand_xor128(0, 254);
    }
}

RAIA_API void raia_draw_noise_gpu(uint8_t *pixels, int width, int height, int depth) {
    #pragma omp target teams distribute parallel for // NOLINT
    for (int i = 0; i < width * height * depth; i++) {
        pixels[i] = rand_xor128(0, 254);
    }
}

RAIA_API void raia_draw_point(uint8_t *pixels, int point_x, int point_y, int color_red, int color_green, int color_blue, int width, int height) {
    raia_point_t point = {
        .x = point_x,
        .y = point_y
    };
    raia_color_t color = {
        .red = color_red,
        .green = color_green,
        .blue = color_blue
    };
    raia_size_t canvas = {
        .width = width,
        .height = height
    };
    set_pixel_rgb(pixels, point, color, canvas, 3);
}

RAIA_API const char * raia_draw_point_alpha(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_point_t point = {
            .x = joint_get_in_int(joint, "point_x"),
            .y = joint_get_in_int(joint, "point_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    set_pixel_rgb_alpha(pixels, point, color, color.alpha, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_point_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_point_t point = {
            .x = joint_get_in_int(joint, "point_x"),
            .y = joint_get_in_int(joint, "point_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    set_pixel_rgba(pixels, point, color, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_line(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    set_line_rgb(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_line_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    set_line_rgba(pixels, segment, color, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_fill_rect_fast(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    fill_rect_rgb_fast(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_fill_rect(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    fill_rect_rgb(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_fill_rect_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    fill_rect_rgba(pixels, segment, color, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_fill_rect_alpha(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    fill_rect_rgb_alpha(pixels, segment, color, color.alpha, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_ellipse(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    draw_ellipse(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_ellipse_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    draw_ellipse_rgba(pixels, segment, color, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_filled_ellipse(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    draw_filled_ellipse(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_filled_ellipse_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
            .alpha = joint_get_in_int(joint, "color_alpha"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    draw_filled_ellipse_rgba(pixels, segment, color, canvas, 4);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_filled_ellipse_smooth(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    draw_filled_ellipse_smooth(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_fill_circle(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_segment_t segment = {
            .start.x = joint_get_in_int(joint, "start_x"),
            .start.y = joint_get_in_int(joint, "start_y"),
            .end.x = joint_get_in_int(joint, "end_x"),
            .end.y = joint_get_in_int(joint, "end_y"),
    };
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    fill_circle_rgb(pixels, segment, color, canvas, 3);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_blend_pixels_rgba_to_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgb = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgb");
    int pixels_rgb_width = joint_get_in_int(joint, "pixels_rgb_width");
    int pixels_rgb_height = joint_get_in_int(joint, "pixels_rgb_height");
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    int trimming_x1 = joint_get_in_int(joint, "trimming_x1");
    int trimming_y1 = joint_get_in_int(joint, "trimming_y1");
    int trimming_x2 = joint_get_in_int(joint, "trimming_x2");
    int trimming_y2 = joint_get_in_int(joint, "trimming_y2");
    blend_pixels_rgba_to_rgb(
            pixels_rgb, pixels_rgb_width, pixels_rgb_height,
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_blend_pixels_rgba_to_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba_a = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba_a");
    int pixels_rgba_a_width = joint_get_in_int(joint, "pixels_rgba_a_width");
    int pixels_rgba_a_height = joint_get_in_int(joint, "pixels_rgba_a_height");
    uint8_t *pixels_rgba_b = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba_b");
    int pixels_rgba_b_width = joint_get_in_int(joint, "pixels_rgba_b_width");
    int pixels_rgba_b_height = joint_get_in_int(joint, "pixels_rgba_b_height");
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    int trimming_x1 = joint_get_in_int(joint, "trimming_x1");
    int trimming_y1 = joint_get_in_int(joint, "trimming_y1");
    int trimming_x2 = joint_get_in_int(joint, "trimming_x2");
    int trimming_y2 = joint_get_in_int(joint, "trimming_y2");
    blend_pixels_rgba_to_rgba(
            pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
            pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    joint_free(joint);
    return NULL;
}

//---d3m

RAIA_API const char * raia_draw_d3m_init(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double width = joint_get_in_real(joint, "width");
    double height = joint_get_in_real(joint, "height");
    d3set_winx(width);
    d3set_winy(height);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_d3m_set_camera(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double pos_x = joint_get_in_real(joint, "pos_x");
    double pos_y = joint_get_in_real(joint, "pos_y");
    double pos_z = joint_get_in_real(joint, "pos_z");
    double target_x = joint_get_in_real(joint, "target_x");
    double target_y = joint_get_in_real(joint, "target_y");
    double target_z = joint_get_in_real(joint, "target_z");
    d3setcam_2(pos_x, pos_y, pos_z, target_x, target_y, target_z);
    joint_free(joint);
    return NULL;
}

RAIA_API const char * raia_draw_d3m_calc_position(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double pos_x = joint_get_in_real(joint, "pos_x");
    double pos_y = joint_get_in_real(joint, "pos_y");
    double pos_z = joint_get_in_real(joint, "pos_z");
    d3vpos(pos_x, pos_y, pos_z);
    joint_add_out_int(joint, "x", (int)d3getdx());
    joint_add_out_int(joint, "y", (int)d3getdy());
    return joint_out_write(joint);
}