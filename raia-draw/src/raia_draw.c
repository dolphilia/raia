#include "raia_draw.h"
#include "platforms.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

static void _draw_noise(uint8_t *pixels, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        pixels[i] = rand_xor128(0, 254);
    }
}

RAIA_EXPORT const char * raia_draw_noise(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");

    _draw_noise(pixels, width, height);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_point(const char *s) {
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
    };
    raia_size_t canvas = {
        .width = joint_get_in_int(joint, "canvas_width"),
        .height = joint_get_in_int(joint, "canvas_height"),
    };

    set_pixel_rgb(pixels, point, color, canvas, 3);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_point_alpha(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_point_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_line(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_line_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_fill_rect_fast(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_fill_rect(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_fill_rect_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_fill_rect_alpha(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_ellipse(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_ellipse_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_filled_ellipse(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_filled_ellipse_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_filled_ellipse_smooth(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_fill_circle(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_blend_pixels_rgba_to_rgb(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_blend_pixels_rgba_to_rgba(const char *s) {
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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_load_image(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    raia_point_t point = {
            .x = joint_get_in_int(joint, "point_x"),
            .y = joint_get_in_int(joint, "point_y"),
    };
    raia_size_t canvas = {
            .width = joint_get_in_int(joint, "canvas_width"),
            .height = joint_get_in_int(joint, "canvas_height"),
    };
    const char* filename = joint_get_in_str(joint, "filename");

    load_image(filename, pixels, point, canvas);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_load_and_blend_image_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    const char* filename = joint_get_in_str(joint, "filename");
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    int trimming_x1 = joint_get_in_int(joint, "trimming_x1");
    int trimming_y1 = joint_get_in_int(joint, "trimming_y1");
    int trimming_x2 = joint_get_in_int(joint, "trimming_x2");
    int trimming_y2 = joint_get_in_int(joint, "trimming_y2");

    load_and_blend_image_rgb(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_load_and_blend_image_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    const char* filename = joint_get_in_str(joint, "filename");
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    int trimming_x1 = joint_get_in_int(joint, "trimming_x1");
    int trimming_y1 = joint_get_in_int(joint, "trimming_y1");
    int trimming_x2 = joint_get_in_int(joint, "trimming_x2");
    int trimming_y2 = joint_get_in_int(joint, "trimming_y2");

    load_and_blend_image_rgba(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

static int _draw_font_open(const char* font_path) {
    FILE *font_file;
#ifdef __WINDOWS__
    fopen_s(&font_file, font_path, "rb");
#else
    font_file = fopen(font_path, "rb");
#endif
    if ((font_file) == NULL) {
        fprintf(stderr, "Error: Unable to open font file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(font_file, 0, SEEK_END);
    long font_size_in_bytes = ftell(font_file);
    fseek(font_file, 0, SEEK_SET);
    fclose(font_file);
    return (int)font_size_in_bytes;
}

RAIA_EXPORT const char * raia_draw_font_open(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* font_path = joint_get_in_str(joint, "font_path");

    int font_size_in_bytes = _draw_font_open(font_path);

    joint_add_out_int(joint, "result", font_size_in_bytes);
    return joint_out_write(joint);
}

static raia_font_t _draw_font_init_buffer(const char *font_path, uint8_t *font_buffer) {
    FILE *font_file;
#ifdef __WINDOWS__
    fopen_s(&font_file, font_path, "rb");
#else
    font_file = fopen(font_path, "rb");
#endif
    if ((font_file) == NULL) {
        fprintf(stderr, "Error: Unable to open font file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(font_file, 0, SEEK_END);
    long font_size_in_bytes = ftell(font_file);
    fseek(font_file, 0, SEEK_SET);

    //font_buffer = (uint8_t *)malloc(font_size_in_bytes);
    fread(font_buffer, 1, font_size_in_bytes, font_file);
    fclose(font_file);

    stbtt_fontinfo font_info;
    if (!stbtt_InitFont(&font_info, font_buffer, stbtt_GetFontOffsetForIndex(font_buffer, 0))) {
        fprintf(stderr, "Error: Failed to initialize font.\n");
        exit(EXIT_FAILURE);
    }

    raia_font_t font;
    font.font_info = font_info;
    font.font_buffer = font_buffer;
    return font;
}

RAIA_EXPORT const char * raia_draw_font_init_buffer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* font_path = joint_get_in_str(joint, "font_path");
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "font_buffer");

    raia_font_t font = _draw_font_init_buffer(font_path, font_buffer);

    joint_add_out_uint(joint, "userdata", (uint64_t)(uintptr_t)font.font_info.userdata);
    joint_add_out_uint(joint, "data", (uint64_t)(uintptr_t)font.font_info.data);
    joint_add_out_int(joint, "fontstart", font.font_info.fontstart);
    joint_add_out_int(joint, "numGlyphs", font.font_info.numGlyphs);
    joint_add_out_int(joint, "loca", font.font_info.loca);
    joint_add_out_int(joint, "head", font.font_info.head);
    joint_add_out_int(joint, "glyf", font.font_info.glyf);
    joint_add_out_int(joint, "hhea", font.font_info.hhea);
    joint_add_out_int(joint, "hmtx", font.font_info.hmtx);
    joint_add_out_int(joint, "kern", font.font_info.kern);
    joint_add_out_int(joint, "gpos", font.font_info.gpos);
    joint_add_out_int(joint, "svg", font.font_info.svg);
    joint_add_out_int(joint, "index_map", font.font_info.index_map);
    joint_add_out_int(joint, "indexToLocFormat", font.font_info.indexToLocFormat);
    joint_add_out_uint(joint, "cff_data", (uint64_t)(uintptr_t)font.font_info.cff.data);
    joint_add_out_int(joint, "cff_cursor", font.font_info.cff.cursor);
    joint_add_out_int(joint, "cff_size", font.font_info.cff.size);
    joint_add_out_uint(joint, "charstrings_data", (uint64_t)(uintptr_t)font.font_info.charstrings.data);
    joint_add_out_int(joint, "charstrings_cursor", font.font_info.charstrings.cursor);
    joint_add_out_int(joint, "charstrings_size", font.font_info.charstrings.size);
    joint_add_out_uint(joint, "gsubrs_data", (uint64_t)(uintptr_t)font.font_info.gsubrs.data);
    joint_add_out_int(joint, "gsubrs_cursor", font.font_info.gsubrs.cursor);
    joint_add_out_int(joint, "gsubrs_size", font.font_info.gsubrs.size);
    joint_add_out_uint(joint, "subrs_data", (uint64_t)(uintptr_t)font.font_info.subrs.data);
    joint_add_out_int(joint, "subrs_cursor", font.font_info.subrs.cursor);
    joint_add_out_int(joint, "subrs_size", font.font_info.subrs.size);
    joint_add_out_uint(joint, "fontdicts_data", (uint64_t)(uintptr_t)font.font_info.fontdicts.data);
    joint_add_out_int(joint, "fontdicts_cursor", font.font_info.fontdicts.cursor);
    joint_add_out_int(joint, "fontdicts_size", font.font_info.fontdicts.size);
    joint_add_out_uint(joint, "fdselect_data", (uint64_t)(uintptr_t)font.font_info.fdselect.data);
    joint_add_out_int(joint, "fdselect_cursor", font.font_info.fdselect.cursor);
    joint_add_out_int(joint, "fdselect_size", font.font_info.fdselect.size);
    return joint_out_write(joint);
}

static raia_size_t _draw_text_rgb(
        uint8_t *pixels_rgba,
        int pixels_rgba_width,
        int pixels_rgba_height,
        const uint8_t* text,
        int font_size,
        raia_color_t  color,
        int position_x,
        int position_y,
        uint8_t *font_buffer,
        stbtt_fontinfo font_info
) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

    float scale = stbtt_ScaleForPixelHeight(&font_info, font_size);
    int ascent, descent, line_gap;
    stbtt_GetFontVMetrics(&font_info, &ascent, &descent, &line_gap);
    ascent *= scale;
    descent *= scale;

    int advance_width, left_side_bearing;
    stbtt_GetCodepointHMetrics(&font_info, unicode_codepoint, &advance_width, &left_side_bearing);
    advance_width *= scale;
    left_side_bearing *= scale;

    int glyph_width, glyph_height, glyph_xoffset, glyph_yoffset;
    uint8_t *glyph_bitmap = stbtt_GetCodepointBitmap(&font_info, 0, scale, unicode_codepoint, &glyph_width, &glyph_height, &glyph_xoffset, &glyph_yoffset);

    raia_point_t point;
    raia_color_t current_color = color;
    raia_size_t size = {pixels_rgba_width, pixels_rgba_height};
    for (int y = 0; y < glyph_height; y++) {
        for (int x = 0; x < glyph_width; x++) {
            int pixel_x = position_x + x;
            int pixel_y = position_y + y + glyph_yoffset + (int)((float)font_size / 1.3);
            if (pixel_x >= 0 && pixel_x < pixels_rgba_width && pixel_y >= 0 && pixel_y < pixels_rgba_height) {
                uint8_t alpha = glyph_bitmap[y * glyph_width + x];
                int pixel_index = (pixel_y * pixels_rgba_width + pixel_x) * 3;
                point.x = pixel_x;
                point.y = pixel_y;
                current_color.alpha = alpha;
                set_pixel_rgb_alpha(pixels_rgba,  point, color, alpha, size, 3);
            }
        }
    }

    stbtt_FreeBitmap(glyph_bitmap, 0);

    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_EXPORT const char *raia_draw_text_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "font_buffer");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    raia_size_t glyph_size = _draw_text_rgb(
            pixels_rgba,
            pixels_rgba_width,
            pixels_rgba_height,
            text,
            font_size,
            color,
            position_x,
            position_y,
            font_buffer,
            font_info
            );

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}

static raia_size_t _draw_text_rgba(
        uint8_t *pixels_rgba,
        int pixels_rgba_width,
        int pixels_rgba_height,
        const uint8_t* text,
        int font_size,
        raia_color_t  color,
        int position_x,
        int position_y,
        uint8_t *font_buffer,
        stbtt_fontinfo font_info
        ) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

    float scale = stbtt_ScaleForPixelHeight(&font_info, font_size);
    int ascent, descent, line_gap;
    stbtt_GetFontVMetrics(&font_info, &ascent, &descent, &line_gap);
    ascent *= scale;
    descent *= scale;

    int advance_width, left_side_bearing;
    stbtt_GetCodepointHMetrics(&font_info, unicode_codepoint, &advance_width, &left_side_bearing);
    advance_width *= scale;
    left_side_bearing *= scale;

    int glyph_width, glyph_height, glyph_xoffset, glyph_yoffset;
    uint8_t *glyph_bitmap = stbtt_GetCodepointBitmap(&font_info, 0, scale, unicode_codepoint, &glyph_width, &glyph_height, &glyph_xoffset, &glyph_yoffset);

    raia_point_t point;
    raia_color_t current_color = color;
    raia_size_t size = {pixels_rgba_width, pixels_rgba_height};
    for (int y = 0; y < glyph_height; y++) {
        for (int x = 0; x < glyph_width; x++) {
            int pixel_x = position_x + x;
            int pixel_y = position_y + y + glyph_yoffset + (int)((float)font_size / 1.3);
            if (pixel_x >= 0 && pixel_x < pixels_rgba_width && pixel_y >= 0 && pixel_y < pixels_rgba_height) {
                uint8_t alpha = glyph_bitmap[y * glyph_width + x];
                int pixel_index = (pixel_y * pixels_rgba_width + pixel_x) * 4;
                point.x = pixel_x;
                point.y = pixel_y;
                current_color.alpha = alpha;
                set_pixel_rgba(pixels_rgba,  point, current_color, size, 4);
            }
        }
    }
    stbtt_FreeBitmap(glyph_bitmap, 0);
    raia_size_t glyph_size = {
        .width = glyph_width,
        .height = glyph_height,
    };
    return glyph_size;
}

RAIA_EXPORT const char * raia_draw_text_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "font_buffer");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    raia_size_t glyph_size = _draw_text_rgba(
            pixels_rgba,
            pixels_rgba_width,
            pixels_rgba_height,
            text,
            font_size,
            color,
            position_x,
            position_y,
            font_buffer,
            font_info);

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}

static raia_size_t _draw_get_text_size(const uint8_t* text, int font_size, stbtt_fontinfo font_info) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

    float scale = stbtt_ScaleForPixelHeight(&font_info, font_size);
    int ascent, descent, line_gap;
    stbtt_GetFontVMetrics(&font_info, &ascent, &descent, &line_gap);
    ascent *= scale;
    descent *= scale;

    int advance_width, left_side_bearing;
    stbtt_GetCodepointHMetrics(&font_info, unicode_codepoint, &advance_width, &left_side_bearing);
    advance_width *= scale;
    left_side_bearing *= scale;

    int glyph_width, glyph_height, glyph_xoffset, glyph_yoffset;
    uint8_t *glyph_bitmap = stbtt_GetCodepointBitmap(&font_info, 0, scale, unicode_codepoint, &glyph_width, &glyph_height, &glyph_xoffset, &glyph_yoffset);

    stbtt_FreeBitmap(glyph_bitmap, 0);
    raia_size_t glyph_size = {
        .width = glyph_width,
        .height = glyph_height,
    };
    return glyph_size;
}

RAIA_EXPORT const char * raia_draw_get_text_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    raia_size_t glyph_size = _draw_get_text_size(text, font_size, font_info);

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_text_rgba_old(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels_rgba");
    int pixels_rgba_width = joint_get_in_int(joint, "pixels_rgba_width");
    int pixels_rgba_height = joint_get_in_int(joint, "pixels_rgba_height");
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    const char *font_path = (const char *)joint_get_in_str(joint, "font_path");
    int font_size = joint_get_in_int(joint, "font_size");
    int position_x = joint_get_in_int(joint, "position_x");
    int position_y = joint_get_in_int(joint, "position_y");

    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);
    CharacterSize character_size = render_character(pixels_rgba, pixels_rgba_width, pixels_rgba_height, position_x, position_y, font_path, font_size, unicode_codepoint);

    joint_add_out_int(joint, "width", character_size.width);
    joint_add_out_int(joint, "height", character_size.height);
    return joint_out_write(joint);
}

//---d3m

RAIA_EXPORT const char * raia_draw_d3m_init(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double width = joint_get_in_real(joint, "width");
    double height = joint_get_in_real(joint, "height");

    d3set_winx(width);
    d3set_winy(height);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_d3m_set_camera(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double pos_x = joint_get_in_real(joint, "pos_x");
    double pos_y = joint_get_in_real(joint, "pos_y");
    double pos_z = joint_get_in_real(joint, "pos_z");
    double target_x = joint_get_in_real(joint, "target_x");
    double target_y = joint_get_in_real(joint, "target_y");
    double target_z = joint_get_in_real(joint, "target_z");

    d3setcam_2(pos_x, pos_y, pos_z, target_x, target_y, target_z);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_draw_d3m_calc_position(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double pos_x = joint_get_in_real(joint, "pos_x");
    double pos_y = joint_get_in_real(joint, "pos_y");
    double pos_z = joint_get_in_real(joint, "pos_z");

    d3vpos(pos_x, pos_y, pos_z);

    joint_add_out_int(joint, "x", (int)d3getdx());
    joint_add_out_int(joint, "y", (int)d3getdy());
    return joint_out_write(joint);
}