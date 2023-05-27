#include "raia_draw.h"
#include "platforms.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT duk_ret_t raia_draw_context_init(duk_context *ctx) {
    duk_idx_t surface_idx = duk_push_array(ctx);
    duk_idx_t obj_idx = duk_push_object(ctx);

    duk_push_int(ctx, 0); // pixels
    duk_put_prop_string(ctx, obj_idx, "pixels");

    duk_idx_t position_idx = duk_push_object(ctx);
    duk_push_int(ctx, 0); // x
    duk_put_prop_string(ctx, position_idx, "x");
    duk_push_int(ctx, 0); // y
    duk_put_prop_string(ctx, position_idx, "y");
    duk_put_prop_string(ctx, obj_idx, "position");

    duk_idx_t size_idx = duk_push_object(ctx);
    duk_push_int(ctx, 0); // width
    duk_put_prop_string(ctx, size_idx, "width");
    duk_push_int(ctx, 0); // height
    duk_put_prop_string(ctx, size_idx, "height");
    duk_put_prop_string(ctx, obj_idx, "size");

    duk_put_prop_index(ctx, surface_idx, 0);
    duk_put_prop_string(ctx, 0, "surface");
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_surface_init(duk_context *ctx) {
    int index = (int) duk_to_number(ctx, 1);
    int width = (int) duk_to_number(ctx, 2);
    int height = (int) duk_to_number(ctx, 3);

    duk_to_object(ctx, 0);
    duk_idx_t surface_idx = duk_push_array(ctx);
    duk_idx_t obj_idx = duk_push_object(ctx);

    duk_push_buffer(ctx, width * height * 3, 0); // pixels
    duk_put_prop_string(ctx, obj_idx, "pixels");

    duk_idx_t size_idx = duk_push_object(ctx);
    duk_push_int(ctx, width); // width
    duk_put_prop_string(ctx, size_idx, "width");
    duk_push_int(ctx, height); // height
    duk_put_prop_string(ctx, size_idx, "height");
    duk_put_prop_string(ctx, obj_idx, "size");

    duk_put_prop_index(ctx, surface_idx, index);
    duk_put_prop_string(ctx, 0, "surface");
    return 0;
}

static void _draw_noise(uint8_t *pixels, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        pixels[i] = rand_xor128(0, 254);
    }
}

RAIA_EXPORT duk_ret_t raia_draw_noise(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    int width = (int)duk_to_number(ctx, 1);
    int height = (int)duk_to_number(ctx, 2);
    _draw_noise(pixels, width, height);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_point(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_point_t point = {
        .x = (int)duk_to_number(ctx, 1),
        .y = (int)duk_to_number(ctx, 2),
    };
    raia_color_t color = {
        .red = (int)duk_to_number(ctx, 3),
        .green = (int)duk_to_number(ctx, 4),
        .blue = (int)duk_to_number(ctx, 5),
    };
    raia_size_t canvas = {
        .width = (int)duk_to_number(ctx, 6),
        .height = (int)duk_to_number(ctx, 7),
    };
    set_pixel_rgb(pixels, point, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_point_alpha(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_point_t point = {
            .x = (int)duk_to_number(ctx, 1),
            .y = (int)duk_to_number(ctx, 2),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 3),
            .green = (int)duk_to_number(ctx, 4),
            .blue = (int)duk_to_number(ctx, 5),
            .alpha = (int)duk_to_number(ctx, 6),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 7),
            .height = (int)duk_to_number(ctx, 8),
    };
    set_pixel_rgb_alpha(pixels, point, color, color.alpha, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_point_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_point_t point = {
            .x = (int)duk_to_number(ctx, 1),
            .y = (int)duk_to_number(ctx, 2),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 3),
            .green = (int)duk_to_number(ctx, 4),
            .blue = (int)duk_to_number(ctx, 5),
            .alpha = (int)duk_to_number(ctx, 6),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 7),
            .height = (int)duk_to_number(ctx, 8),
    };
    set_pixel_rgba(pixels, point, color, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_line(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
        .start.x = (int)duk_to_number(ctx, 1),
        .start.y = (int)duk_to_number(ctx, 2),
        .end.x = (int)duk_to_number(ctx, 3),
        .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
        .red = (int)duk_to_number(ctx, 5),
        .green = (int)duk_to_number(ctx, 6),
        .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
        .width = (int)duk_to_number(ctx, 8),
        .height = (int)duk_to_number(ctx, 9),
    };
    set_line_rgb(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_line_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
            .alpha = (int)duk_to_number(ctx, 8),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 9),
            .height = (int)duk_to_number(ctx, 10),
    };
    set_line_rgba(pixels, segment, color, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_fill_rect_fast(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 8),
            .height = (int)duk_to_number(ctx, 9),
    };
    fill_rect_rgb_fast(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_fill_rect(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
        .start.x = (int)duk_to_number(ctx, 1),
        .start.y = (int)duk_to_number(ctx, 2),
        .end.x = (int)duk_to_number(ctx, 3),
        .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
        .red = (int)duk_to_number(ctx, 5),
        .green = (int)duk_to_number(ctx, 6),
        .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
        .width = (int)duk_to_number(ctx, 8),
        .height = (int)duk_to_number(ctx, 9),
    };
    fill_rect_rgb(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_fill_rect_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
            .alpha = (int)duk_to_number(ctx, 8),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 9),
            .height = (int)duk_to_number(ctx, 10),
    };
    fill_rect_rgba(pixels, segment, color, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_fill_rect_alpha(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
    };
    uint8_t alpha = (uint8_t)duk_to_number(ctx, 8);
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 9),
            .height = (int)duk_to_number(ctx, 10),
    };
    fill_rect_rgb_alpha(pixels, segment, color, alpha, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_ellipse(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 8),
            .height = (int)duk_to_number(ctx, 9),
    };
    draw_ellipse(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_ellipse_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
            .alpha = (int)duk_to_number(ctx, 8),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 9),
            .height = (int)duk_to_number(ctx, 10),
    };
    draw_ellipse_rgba(pixels, segment, color, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 8),
            .height = (int)duk_to_number(ctx, 9),
    };
    draw_filled_ellipse(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
            .alpha = (int)duk_to_number(ctx, 8),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 9),
            .height = (int)duk_to_number(ctx, 10),
    };
    draw_filled_ellipse_rgba(pixels, segment, color, canvas, 4);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_filled_ellipse_smooth(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
            .start.x = (int)duk_to_number(ctx, 1),
            .start.y = (int)duk_to_number(ctx, 2),
            .end.x = (int)duk_to_number(ctx, 3),
            .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
            .red = (int)duk_to_number(ctx, 5),
            .green = (int)duk_to_number(ctx, 6),
            .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 8),
            .height = (int)duk_to_number(ctx, 9),
    };
    draw_filled_ellipse_smooth(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_fill_circle(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_segment_t segment = {
        .start.x = (int)duk_to_number(ctx, 1),
        .start.y = (int)duk_to_number(ctx, 2),
        .end.x = (int)duk_to_number(ctx, 3),
        .end.y = (int)duk_to_number(ctx, 4),
    };
    raia_color_t color = {
        .red = (int)duk_to_number(ctx, 5),
        .green = (int)duk_to_number(ctx, 6),
        .blue = (int)duk_to_number(ctx, 7),
    };
    raia_size_t canvas = {
        .width = (int)duk_to_number(ctx, 8),
        .height = (int)duk_to_number(ctx, 9),
    };
    fill_circle_rgb(pixels, segment, color, canvas, 3);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_blend_pixels_rgba_to_rgb(duk_context *ctx) {
    duk_size_t pixels_rgb_len;
    uint8_t *pixels_rgb = (uint8_t *)duk_require_buffer_data(ctx, 0, &pixels_rgb_len);
    int pixels_rgb_width = (int)duk_to_number(ctx, 1);
    int pixels_rgb_height = (int)duk_to_number(ctx, 2);
    duk_size_t pixels_rgba_len;
    uint8_t *pixels_rgba = (uint8_t *)duk_require_buffer_data(ctx, 3, &pixels_rgba_len);
    int pixels_rgba_width = (int)duk_to_number(ctx, 4);
    int pixels_rgba_height = (int)duk_to_number(ctx, 5);
    int position_x = (int)duk_to_number(ctx, 6);
    int position_y = (int)duk_to_number(ctx, 7);
    int trimming_x1 = (int)duk_to_number(ctx, 8);
    int trimming_y1 = (int)duk_to_number(ctx, 9);
    int trimming_x2 = (int)duk_to_number(ctx, 10);
    int trimming_y2 = (int)duk_to_number(ctx, 11);
    blend_pixels_rgba_to_rgb(
            pixels_rgb, pixels_rgb_width, pixels_rgb_height,
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_blend_pixels_rgba_to_rgba(duk_context *ctx) {
    duk_size_t pixels_rgba_a_len;
    uint8_t *pixels_rgba_a = (uint8_t *)duk_require_buffer_data(ctx, 0, &pixels_rgba_a_len);
    int pixels_rgba_a_width = (int)duk_to_number(ctx, 1);
    int pixels_rgba_a_height = (int)duk_to_number(ctx, 2);
    duk_size_t pixels_rgba_b_len;
    uint8_t *pixels_rgba_b = (uint8_t *)duk_require_buffer_data(ctx, 3, &pixels_rgba_b_len);
    int pixels_rgba_b_width = (int)duk_to_number(ctx, 4);
    int pixels_rgba_b_height = (int)duk_to_number(ctx, 5);
    int position_x = (int)duk_to_number(ctx, 6);
    int position_y = (int)duk_to_number(ctx, 7);
    int trimming_x1 = (int)duk_to_number(ctx, 8);
    int trimming_y1 = (int)duk_to_number(ctx, 9);
    int trimming_x2 = (int)duk_to_number(ctx, 10);
    int trimming_y2 = (int)duk_to_number(ctx, 11);
    blend_pixels_rgba_to_rgba(
            pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
            pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_draw_load_image(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    raia_point_t point = {
            .x = (int)duk_to_number(ctx, 1),
            .y = (int)duk_to_number(ctx, 2),
    };
    raia_size_t canvas = {
            .width = (int)duk_to_number(ctx, 3),
            .height = (int)duk_to_number(ctx, 4),
    };
    const char* filename = duk_to_string(ctx, 5);
    load_image(filename, pixels, point, canvas);
    return 0;  /* no return value (= undefined) */
}

RAIA_EXPORT duk_ret_t raia_draw_load_and_blend_image_rgb(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels_rgba = (uint8_t *) duk_require_buffer_data(ctx, 0, &len);
    int pixels_rgba_width = (int) duk_to_number(ctx, 1);
    int pixels_rgba_height = (int) duk_to_number(ctx, 2);
    const char *filename = duk_to_string(ctx, 3);
    int position_x = (int) duk_to_number(ctx, 4);
    int position_y = (int) duk_to_number(ctx, 5);
    int trimming_x1 = (int) duk_to_number(ctx, 6);
    int trimming_y1 = (int) duk_to_number(ctx, 7);
    int trimming_x2 = (int) duk_to_number(ctx, 8);
    int trimming_y2 = (int) duk_to_number(ctx, 9);
    load_and_blend_image_rgb(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    return 0;  /* no return value (= undefined) */
}

RAIA_EXPORT duk_ret_t raia_draw_load_and_blend_image_rgba(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels_rgba = (uint8_t *) duk_require_buffer_data(ctx, 0, &len);
    int pixels_rgba_width = (int) duk_to_number(ctx, 1);
    int pixels_rgba_height = (int) duk_to_number(ctx, 2);
    const char *filename = duk_to_string(ctx, 3);
    int position_x = (int) duk_to_number(ctx, 4);
    int position_y = (int) duk_to_number(ctx, 5);
    int trimming_x1 = (int) duk_to_number(ctx, 6);
    int trimming_y1 = (int) duk_to_number(ctx, 7);
    int trimming_x2 = (int) duk_to_number(ctx, 8);
    int trimming_y2 = (int) duk_to_number(ctx, 9);
    load_and_blend_image_rgba(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);
    return 0;  /* no return value (= undefined) */
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

RAIA_EXPORT duk_ret_t raia_draw_font_open(duk_context *ctx) {
    const char* font_path = duk_to_string(ctx, 0);
    int font_size_in_bytes = _draw_font_open(font_path);
    duk_push_int(ctx, font_size_in_bytes);
    return 1;
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

RAIA_EXPORT duk_ret_t raia_draw_font_init_buffer(duk_context *ctx) {
    const char *font_path = duk_to_string(ctx, 0);
    duk_size_t len;
    uint8_t *font_buffer = (uint8_t *) duk_require_buffer_data(ctx, 1, &len);

    raia_font_t font = _draw_font_init_buffer(font_path, font_buffer);

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_pointer(ctx, font.font_info.userdata);
    duk_put_prop_string(ctx, obj_idx, "userdata");
    duk_push_pointer(ctx, font.font_info.data);
    duk_put_prop_string(ctx, obj_idx, "data");
    duk_push_int(ctx, font.font_info.fontstart);
    duk_put_prop_string(ctx, obj_idx, "fontstart");
    duk_push_int(ctx, font.font_info.numGlyphs);
    duk_put_prop_string(ctx, obj_idx, "numGlyphs");
    duk_push_int(ctx, font.font_info.loca);
    duk_put_prop_string(ctx, obj_idx, "loca");
    duk_push_int(ctx, font.font_info.head);
    duk_put_prop_string(ctx, obj_idx, "head");
    duk_push_int(ctx, font.font_info.glyf);
    duk_put_prop_string(ctx, obj_idx, "glyf");
    duk_push_int(ctx, font.font_info.hhea);
    duk_put_prop_string(ctx, obj_idx, "hhea");
    duk_push_int(ctx, font.font_info.hmtx);
    duk_put_prop_string(ctx, obj_idx, "hmtx");
    duk_push_int(ctx, font.font_info.kern);
    duk_put_prop_string(ctx, obj_idx, "kern");
    duk_push_int(ctx, font.font_info.gpos);
    duk_put_prop_string(ctx, obj_idx, "gpos");
    duk_push_int(ctx, font.font_info.svg);
    duk_put_prop_string(ctx, obj_idx, "svg");
    duk_push_int(ctx, font.font_info.index_map);
    duk_put_prop_string(ctx, obj_idx, "index_map");
    duk_push_int(ctx, font.font_info.indexToLocFormat);
    duk_put_prop_string(ctx, obj_idx, "indexToLocFormat");
    duk_push_pointer(ctx, font.font_info.cff.data);
    duk_put_prop_string(ctx, obj_idx, "cff_data");
    duk_push_int(ctx, font.font_info.cff.cursor);
    duk_put_prop_string(ctx, obj_idx, "cff_cursor");
    duk_push_int(ctx, font.font_info.cff.size);
    duk_put_prop_string(ctx, obj_idx, "cff_size");
    duk_push_pointer(ctx, font.font_info.charstrings.data);
    duk_put_prop_string(ctx, obj_idx, "charstrings_data");
    duk_push_int(ctx, font.font_info.charstrings.cursor);
    duk_put_prop_string(ctx, obj_idx, "charstrings_cursor");
    duk_push_int(ctx, font.font_info.charstrings.size);
    duk_put_prop_string(ctx, obj_idx, "charstrings_size");
    duk_push_pointer(ctx, font.font_info.gsubrs.data);
    duk_put_prop_string(ctx, obj_idx, "gsubrs_data");
    duk_push_int(ctx, font.font_info.gsubrs.cursor);
    duk_put_prop_string(ctx, obj_idx, "gsubrs_cursor");
    duk_push_int(ctx, font.font_info.gsubrs.size);
    duk_put_prop_string(ctx, obj_idx, "gsubrs_size");
    duk_push_pointer(ctx, font.font_info.subrs.data);
    duk_put_prop_string(ctx, obj_idx, "subrs_data");
    duk_push_int(ctx, font.font_info.subrs.cursor);
    duk_put_prop_string(ctx, obj_idx, "subrs_cursor");
    duk_push_int(ctx, font.font_info.subrs.size);
    duk_put_prop_string(ctx, obj_idx, "subrs_size");
    duk_push_pointer(ctx, font.font_info.fontdicts.data);
    duk_put_prop_string(ctx, obj_idx, "fontdicts_data");
    duk_push_int(ctx, font.font_info.fontdicts.cursor);
    duk_put_prop_string(ctx, obj_idx, "fontdicts_cursor");
    duk_push_int(ctx, font.font_info.fontdicts.size);
    duk_put_prop_string(ctx, obj_idx, "fontdicts_size");
    duk_push_pointer(ctx, font.font_info.fdselect.data);
    duk_put_prop_string(ctx, obj_idx, "fdselect_data");
    duk_push_int(ctx, font.font_info.fdselect.cursor);
    duk_put_prop_string(ctx, obj_idx, "fdselect_cursor");
    duk_push_int(ctx, font.font_info.fdselect.size);
    duk_put_prop_string(ctx, obj_idx, "fdselect_size");
    return 1;
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

RAIA_EXPORT duk_ret_t raia_draw_text_rgb(duk_context *ctx) {
    duk_size_t pixels_len;
    uint8_t *pixels_rgba = (uint8_t *)duk_require_buffer_data(ctx, 0, &pixels_len);
    int pixels_rgba_width = (int)duk_to_number(ctx, 1);
    int pixels_rgba_height = (int)duk_to_number(ctx, 2);
    const uint8_t* text = (uint8_t *)duk_to_string(ctx, 3);
    int font_size = (int)duk_to_number(ctx, 4);
    raia_color_t color;
    color.red = (int)duk_to_number(ctx, 5);
    color.green = (int)duk_to_number(ctx, 6);
    color.blue = (int)duk_to_number(ctx, 7);
    int position_x = (int)duk_to_number(ctx, 8);
    int position_y = (int)duk_to_number(ctx, 9);
    duk_size_t font_buffer_len;
    uint8_t *font_buffer = (uint8_t *) duk_require_buffer_data(ctx, 10, &font_buffer_len);
    stbtt_fontinfo font_info;
    font_info.userdata = duk_require_pointer(ctx, 11);
    font_info.data = duk_require_pointer(ctx, 12);
    font_info.fontstart = duk_to_int(ctx, 13);
    font_info.numGlyphs = duk_to_int(ctx, 14);
    font_info.loca = duk_to_int(ctx, 15);
    font_info.head = duk_to_int(ctx, 16);
    font_info.glyf = duk_to_int(ctx, 17);
    font_info.hhea = duk_to_int(ctx, 18);
    font_info.hmtx = duk_to_int(ctx, 19);
    font_info.kern = duk_to_int(ctx, 20);
    font_info.gpos = duk_to_int(ctx, 21);
    font_info.svg = duk_to_int(ctx, 22);
    font_info.index_map = duk_to_int(ctx, 23);
    font_info.indexToLocFormat = duk_to_int(ctx, 24);
    font_info.cff.data = duk_require_pointer(ctx, 25);
    font_info.cff.cursor = duk_to_int(ctx, 26);
    font_info.cff.size = duk_to_int(ctx, 27);
    font_info.charstrings.data = duk_require_pointer(ctx, 28);
    font_info.charstrings.cursor = duk_to_int(ctx, 29);
    font_info.charstrings.size = duk_to_int(ctx, 30);
    font_info.gsubrs.data = duk_require_pointer(ctx, 31);
    font_info.gsubrs.cursor = duk_to_int(ctx, 32);
    font_info.gsubrs.size = duk_to_int(ctx, 33);
    font_info.subrs.data = duk_require_pointer(ctx, 34);
    font_info.subrs.cursor = duk_to_int(ctx, 35);
    font_info.subrs.size = duk_to_int(ctx, 36);
    font_info.fontdicts.data = duk_require_pointer(ctx, 37);
    font_info.fontdicts.cursor = duk_to_int(ctx, 38);
    font_info.fontdicts.size = duk_to_int(ctx, 39);
    font_info.fdselect.data = duk_require_pointer(ctx, 40);
    font_info.fdselect.cursor = duk_to_int(ctx, 41);
    font_info.fdselect.size = duk_to_int(ctx, 42);

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
            font_info);

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, glyph_size.width);
    duk_put_prop_string(ctx, obj_idx, "width");
    duk_push_int(ctx, glyph_size.height);
    duk_put_prop_string(ctx, obj_idx, "height");
};

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

    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_EXPORT duk_ret_t raia_draw_text_rgba(duk_context *ctx) {
    duk_size_t pixels_len;
    uint8_t *pixels_rgba = (uint8_t *)duk_require_buffer_data(ctx, 0, &pixels_len);
    int pixels_rgba_width = (int)duk_to_number(ctx, 1);
    int pixels_rgba_height = (int)duk_to_number(ctx, 2);
    const uint8_t* text = (uint8_t *)duk_to_string(ctx, 3);
    int font_size = (int)duk_to_number(ctx, 4);
    raia_color_t color;
    color.red = (int)duk_to_number(ctx, 5);
    color.green = (int)duk_to_number(ctx, 6);
    color.blue = (int)duk_to_number(ctx, 7);
    int position_x = (int)duk_to_number(ctx, 8);
    int position_y = (int)duk_to_number(ctx, 9);
    duk_size_t font_buffer_len;
    uint8_t *font_buffer = (uint8_t *) duk_require_buffer_data(ctx, 10, &font_buffer_len);
    stbtt_fontinfo font_info;
    font_info.userdata = duk_require_pointer(ctx, 11);
    font_info.data = duk_require_pointer(ctx, 12);
    font_info.fontstart = duk_to_int(ctx, 13);
    font_info.numGlyphs = duk_to_int(ctx, 14);
    font_info.loca = duk_to_int(ctx, 15);
    font_info.head = duk_to_int(ctx, 16);
    font_info.glyf = duk_to_int(ctx, 17);
    font_info.hhea = duk_to_int(ctx, 18);
    font_info.hmtx = duk_to_int(ctx, 19);
    font_info.kern = duk_to_int(ctx, 20);
    font_info.gpos = duk_to_int(ctx, 21);
    font_info.svg = duk_to_int(ctx, 22);
    font_info.index_map = duk_to_int(ctx, 23);
    font_info.indexToLocFormat = duk_to_int(ctx, 24);
    font_info.cff.data = duk_require_pointer(ctx, 25);
    font_info.cff.cursor = duk_to_int(ctx, 26);
    font_info.cff.size = duk_to_int(ctx, 27);
    font_info.charstrings.data = duk_require_pointer(ctx, 28);
    font_info.charstrings.cursor = duk_to_int(ctx, 29);
    font_info.charstrings.size = duk_to_int(ctx, 30);
    font_info.gsubrs.data = duk_require_pointer(ctx, 31);
    font_info.gsubrs.cursor = duk_to_int(ctx, 32);
    font_info.gsubrs.size = duk_to_int(ctx, 33);
    font_info.subrs.data = duk_require_pointer(ctx, 34);
    font_info.subrs.cursor = duk_to_int(ctx, 35);
    font_info.subrs.size = duk_to_int(ctx, 36);
    font_info.fontdicts.data = duk_require_pointer(ctx, 37);
    font_info.fontdicts.cursor = duk_to_int(ctx, 38);
    font_info.fontdicts.size = duk_to_int(ctx, 39);
    font_info.fdselect.data = duk_require_pointer(ctx, 40);
    font_info.fdselect.cursor = duk_to_int(ctx, 41);
    font_info.fdselect.size = duk_to_int(ctx, 42);

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

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, glyph_size.width);
    duk_put_prop_string(ctx, obj_idx, "width");
    duk_push_int(ctx, glyph_size.height);
    duk_put_prop_string(ctx, obj_idx, "height");
};

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
    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_EXPORT duk_ret_t raia_draw_get_text_size(duk_context *ctx) {
    const uint8_t* text = (uint8_t *)duk_to_string(ctx, 0);
    int font_size = (int)duk_to_number(ctx, 1);
    stbtt_fontinfo font_info;
    font_info.userdata = duk_require_pointer(ctx, 2);
    font_info.data = duk_require_pointer(ctx, 3);
    font_info.fontstart = duk_to_int(ctx, 4);
    font_info.numGlyphs = duk_to_int(ctx, 5);
    font_info.loca = duk_to_int(ctx, 6);
    font_info.head = duk_to_int(ctx, 7);
    font_info.glyf = duk_to_int(ctx, 8);
    font_info.hhea = duk_to_int(ctx, 9);
    font_info.hmtx = duk_to_int(ctx, 10);
    font_info.kern = duk_to_int(ctx, 11);
    font_info.gpos = duk_to_int(ctx, 12);
    font_info.svg = duk_to_int(ctx, 13);
    font_info.index_map = duk_to_int(ctx, 14);
    font_info.indexToLocFormat = duk_to_int(ctx, 15);
    font_info.cff.data = duk_require_pointer(ctx, 16);
    font_info.cff.cursor = duk_to_int(ctx, 17);
    font_info.cff.size = duk_to_int(ctx, 18);
    font_info.charstrings.data = duk_require_pointer(ctx, 19);
    font_info.charstrings.cursor = duk_to_int(ctx, 20);
    font_info.charstrings.size = duk_to_int(ctx, 21);
    font_info.gsubrs.data = duk_require_pointer(ctx, 22);
    font_info.gsubrs.cursor = duk_to_int(ctx, 23);
    font_info.gsubrs.size = duk_to_int(ctx, 24);
    font_info.subrs.data = duk_require_pointer(ctx, 25);
    font_info.subrs.cursor = duk_to_int(ctx, 26);
    font_info.subrs.size = duk_to_int(ctx, 27);
    font_info.fontdicts.data = duk_require_pointer(ctx, 28);
    font_info.fontdicts.cursor = duk_to_int(ctx, 29);
    font_info.fontdicts.size = duk_to_int(ctx, 30);
    font_info.fdselect.data = duk_require_pointer(ctx, 31);
    font_info.fdselect.cursor = duk_to_int(ctx, 32);
    font_info.fdselect.size = duk_to_int(ctx, 33);

    raia_size_t glyph_size = _draw_get_text_size(text, font_size, font_info);

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, glyph_size.width);
    duk_put_prop_string(ctx, obj_idx, "width");
    duk_push_int(ctx, glyph_size.height);
    duk_put_prop_string(ctx, obj_idx, "height");
};

RAIA_EXPORT duk_ret_t raia_draw_text_rgba_old(duk_context *ctx) {
    duk_size_t len;
    uint8_t *pixels_rgba = (uint8_t *)duk_require_buffer_data(ctx, 0, &len);
    int pixels_rgba_width = (int)duk_to_number(ctx, 1);
    int pixels_rgba_height = (int)duk_to_number(ctx, 2);
    const uint8_t* text = (uint8_t *)duk_to_string(ctx, 3);
    const char* font_path = duk_to_string(ctx, 4);
    int font_size = (int)duk_to_number(ctx, 5);
    int position_x = (int)duk_to_number(ctx, 6);
    int position_y = (int)duk_to_number(ctx, 7);

    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

    CharacterSize character_size = render_character(pixels_rgba, pixels_rgba_width, pixels_rgba_height, position_x, position_y, font_path, font_size, unicode_codepoint);

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, character_size.width);
    duk_put_prop_string(ctx, obj_idx, "width");
    duk_push_int(ctx, character_size.height);
    duk_put_prop_string(ctx, obj_idx, "height");
};

//---d3m

RAIA_EXPORT duk_ret_t raia_draw_d3m_init(duk_context *ctx) {
    double width = (double)duk_to_number(ctx, 0);
    double height = (double)duk_to_number(ctx, 1);
    d3set_winx(width);
    d3set_winy(height);
    return 0;
}
RAIA_EXPORT duk_ret_t raia_draw_d3m_set_camera(duk_context *ctx) {
    double pos_x = (double)duk_to_number(ctx, 0);
    double pos_y = (double)duk_to_number(ctx, 1);
    double pos_z = (double)duk_to_number(ctx, 2);
    double target_x = (double)duk_to_number(ctx, 3);
    double target_y = (double)duk_to_number(ctx, 4);
    double target_z = (double)duk_to_number(ctx, 5);
    d3setcam_2(pos_x, pos_y, pos_z, target_x, target_y, target_z);
    return 0;
}
RAIA_EXPORT duk_ret_t raia_draw_d3m_calc_position(duk_context *ctx) {
    double pos_x = (double)duk_to_number(ctx, 0);
    double pos_y = (double)duk_to_number(ctx, 1);
    double pos_z = (double)duk_to_number(ctx, 2);
    d3vpos(pos_x, pos_y, pos_z);

    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, d3getdx()); // dx
    duk_put_prop_string(ctx, obj_idx, "x");
    duk_push_int(ctx, d3getdy()); // dx
    duk_put_prop_string(ctx, obj_idx, "y");
    return 1;
}