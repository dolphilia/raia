#include "raia_draw.h"
#include "platforms.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

//RAIA_EXPORT duk_ret_t raia_draw_context_init(duk_context *ctx) {
//    duk_idx_t surface_idx = duk_push_array(ctx);
//    duk_idx_t obj_idx = duk_push_object(ctx);
//
//    duk_push_int(ctx, 0); // pixels
//    duk_put_prop_string(ctx, obj_idx, "pixels");
//
//    duk_idx_t position_idx = duk_push_object(ctx);
//    duk_push_int(ctx, 0); // x
//    duk_put_prop_string(ctx, position_idx, "x");
//    duk_push_int(ctx, 0); // y
//    duk_put_prop_string(ctx, position_idx, "y");
//    duk_put_prop_string(ctx, obj_idx, "position");
//
//    duk_idx_t size_idx = duk_push_object(ctx);
//    duk_push_int(ctx, 0); // width
//    duk_put_prop_string(ctx, size_idx, "width");
//    duk_push_int(ctx, 0); // height
//    duk_put_prop_string(ctx, size_idx, "height");
//    duk_put_prop_string(ctx, obj_idx, "size");
//
//    duk_put_prop_index(ctx, surface_idx, 0);
//    duk_put_prop_string(ctx, 0, "surface");
//    return 0;
//}
//
//RAIA_EXPORT duk_ret_t raia_draw_surface_init(duk_context *ctx) {
//    int index = (int) duk_to_number(ctx, 1);
//    int width = (int) duk_to_number(ctx, 2);
//    int height = (int) duk_to_number(ctx, 3);
//
//    duk_to_object(ctx, 0);
//    duk_idx_t surface_idx = duk_push_array(ctx);
//    duk_idx_t obj_idx = duk_push_object(ctx);
//
//    duk_push_buffer(ctx, width * height * 3, 0); // pixels
//    duk_put_prop_string(ctx, obj_idx, "pixels");
//
//    duk_idx_t size_idx = duk_push_object(ctx);
//    duk_push_int(ctx, width); // width
//    duk_put_prop_string(ctx, size_idx, "width");
//    duk_push_int(ctx, height); // height
//    duk_put_prop_string(ctx, size_idx, "height");
//    duk_put_prop_string(ctx, obj_idx, "size");
//
//    duk_put_prop_index(ctx, surface_idx, index);
//    duk_put_prop_string(ctx, 0, "surface");
//    return 0;
//}

static void _draw_noise(uint8_t *pixels, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        pixels[i] = rand_xor128(0, 254);
    }
}

RAIA_EXPORT void *raia_draw_noise(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    int width = yyjson_get_int(yyjson_obj_get(arg_root, "width"));
    int height = yyjson_get_int(yyjson_obj_get(arg_root, "height"));

    _draw_noise(pixels, width, height);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_point(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_point_t point = {
        .x = yyjson_get_int(yyjson_obj_get(arg_root, "point_x")),
        .y = yyjson_get_int(yyjson_obj_get(arg_root, "point_y")),
    };
    raia_color_t color = {
        .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
        .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
        .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
        .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
        .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    set_pixel_rgb(pixels, point, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_point_alpha(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_point_t point = {
            .x = yyjson_get_int(yyjson_obj_get(arg_root, "point_x")),
            .y = yyjson_get_int(yyjson_obj_get(arg_root, "point_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    set_pixel_rgb_alpha(pixels, point, color, color.alpha, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_point_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_point_t point = {
            .x = yyjson_get_int(yyjson_obj_get(arg_root, "point_x")),
            .y = yyjson_get_int(yyjson_obj_get(arg_root, "point_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    set_pixel_rgba(pixels, point, color, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_line(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    set_line_rgb(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_line_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    set_line_rgba(pixels, segment, color, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_fill_rect_fast(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    fill_rect_rgb_fast(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_fill_rect(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    fill_rect_rgb(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_fill_rect_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    fill_rect_rgba(pixels, segment, color, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_fill_rect_alpha(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    fill_rect_rgb_alpha(pixels, segment, color, color.alpha, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_ellipse(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    draw_ellipse(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_ellipse_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    draw_ellipse_rgba(pixels, segment, color, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_filled_ellipse(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    draw_filled_ellipse(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_filled_ellipse_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
            .alpha = yyjson_get_int(yyjson_obj_get(arg_root, "color_alpha")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    draw_filled_ellipse_rgba(pixels, segment, color, canvas, 4);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_filled_ellipse_smooth(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    draw_filled_ellipse_smooth(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_fill_circle(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_segment_t segment = {
            .start.x = yyjson_get_int(yyjson_obj_get(arg_root, "start_x")),
            .start.y = yyjson_get_int(yyjson_obj_get(arg_root, "start_y")),
            .end.x = yyjson_get_int(yyjson_obj_get(arg_root, "end_x")),
            .end.y = yyjson_get_int(yyjson_obj_get(arg_root, "end_y")),
    };
    raia_color_t color = {
            .red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red")),
            .green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green")),
            .blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };

    fill_circle_rgb(pixels, segment, color, canvas, 3);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_blend_pixels_rgba_to_rgb(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgb = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgb"));
    int pixels_rgb_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgb_width"));
    int pixels_rgb_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgb_height"));
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    int trimming_x1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x1"));
    int trimming_y1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y1"));
    int trimming_x2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x2"));
    int trimming_y2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y2"));

    blend_pixels_rgba_to_rgb(
            pixels_rgb, pixels_rgb_width, pixels_rgb_height,
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_blend_pixels_rgba_to_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba_a = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba_a"));
    int pixels_rgba_a_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_a_width"));
    int pixels_rgba_a_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_a_height"));
    uint8_t *pixels_rgba_b = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba_b"));
    int pixels_rgba_b_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_b_width"));
    int pixels_rgba_b_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_b_height"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    int trimming_x1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x1"));
    int trimming_y1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y1"));
    int trimming_x2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x2"));
    int trimming_y2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y2"));

    blend_pixels_rgba_to_rgba(
            pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
            pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_load_image(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels"));
    raia_point_t point = {
            .x = yyjson_get_int(yyjson_obj_get(arg_root, "point_x")),
            .y = yyjson_get_int(yyjson_obj_get(arg_root, "point_y")),
    };
    raia_size_t canvas = {
            .width = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_width")),
            .height = yyjson_get_int(yyjson_obj_get(arg_root, "canvas_height")),
    };
    const char* filename = yyjson_get_str(yyjson_obj_get(arg_root, "filename"));

    load_image(filename, pixels, point, canvas);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_load_and_blend_image_rgb(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    const char* filename = yyjson_get_str(yyjson_obj_get(arg_root, "filename"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    int trimming_x1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x1"));
    int trimming_y1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y1"));
    int trimming_x2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x2"));
    int trimming_y2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y2"));

    load_and_blend_image_rgb(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_load_and_blend_image_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    const char* filename = yyjson_get_str(yyjson_obj_get(arg_root, "filename"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    int trimming_x1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x1"));
    int trimming_y1 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y1"));
    int trimming_x2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_x2"));
    int trimming_y2 = yyjson_get_int(yyjson_obj_get(arg_root, "trimming_y2"));

    load_and_blend_image_rgba(
            pixels_rgba, pixels_rgba_width, pixels_rgba_height,
            filename,
            position_x, position_y,
            trimming_x1, trimming_y1, trimming_x2, trimming_y2);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
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

RAIA_EXPORT void *raia_draw_font_open(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    const char* font_path = yyjson_get_str(yyjson_obj_get(arg_root, "font_path"));

    int font_size_in_bytes = _draw_font_open(font_path);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "result", font_size_in_bytes);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
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

RAIA_EXPORT void *raia_draw_font_init_buffer(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    const char *font_path = yyjson_get_str(yyjson_obj_get(arg_root, "font_path"));
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "font_buffer"));

    raia_font_t font = _draw_font_init_buffer(font_path, font_buffer);


    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "userdata", (uint64_t)(uintptr_t)font.font_info.userdata);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "data", (uint64_t)(uintptr_t)font.font_info.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "fontstart", font.font_info.fontstart);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "numGlyphs", font.font_info.numGlyphs);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "loca", font.font_info.loca);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "head", font.font_info.head);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "glyf", font.font_info.glyf);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "hhea", font.font_info.hhea);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "hmtx", font.font_info.hmtx);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "kern", font.font_info.kern);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "gpos", font.font_info.gpos);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "svg", font.font_info.svg);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "index_map", font.font_info.index_map);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "indexToLocFormat", font.font_info.indexToLocFormat);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "cff_data", (uint64_t)(uintptr_t)font.font_info.cff.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "cff_cursor", font.font_info.cff.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "cff_size", font.font_info.cff.size);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "charstrings_data", (uint64_t)(uintptr_t)font.font_info.charstrings.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "charstrings_cursor", font.font_info.charstrings.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "charstrings_size", font.font_info.charstrings.size);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "gsubrs_data", (uint64_t)(uintptr_t)font.font_info.gsubrs.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "gsubrs_cursor", font.font_info.gsubrs.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "gsubrs_size", font.font_info.gsubrs.size);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "subrs_data", (uint64_t)(uintptr_t)font.font_info.subrs.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "subrs_cursor", font.font_info.subrs.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "subrs_size", font.font_info.subrs.size);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "fontdicts_data", (uint64_t)(uintptr_t)font.font_info.fontdicts.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "fontdicts_cursor", font.font_info.fontdicts.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "fontdicts_size", font.font_info.fontdicts.size);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "fdselect_data", (uint64_t)(uintptr_t)font.font_info.fdselect.data);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "fdselect_cursor", font.font_info.fdselect.cursor);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "fdselect_size", font.font_info.fdselect.size);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
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

RAIA_EXPORT void *raia_draw_text_rgb(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    const uint8_t *text = (const uint8_t *)yyjson_get_str(yyjson_obj_get(arg_root, "text"));
    int font_size = yyjson_get_int(yyjson_obj_get(arg_root, "font_size"));
    raia_color_t color;
    color.red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red"));
    color.green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green"));
    color.blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "font_buffer"));
    stbtt_fontinfo font_info;
    font_info.userdata = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "userdata"));
    font_info.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "data"));
    font_info.fontstart = yyjson_get_int(yyjson_obj_get(arg_root, "fontstart"));
    font_info.numGlyphs = yyjson_get_int(yyjson_obj_get(arg_root, "numGlyphs"));
    font_info.loca = yyjson_get_int(yyjson_obj_get(arg_root, "loca"));
    font_info.head = yyjson_get_int(yyjson_obj_get(arg_root, "head"));
    font_info.glyf = yyjson_get_int(yyjson_obj_get(arg_root, "glyf"));
    font_info.hhea = yyjson_get_int(yyjson_obj_get(arg_root, "hhea"));
    font_info.hmtx = yyjson_get_int(yyjson_obj_get(arg_root, "hmtx"));
    font_info.kern = yyjson_get_int(yyjson_obj_get(arg_root, "kern"));
    font_info.gpos = yyjson_get_int(yyjson_obj_get(arg_root, "gpos"));
    font_info.svg = yyjson_get_int(yyjson_obj_get(arg_root, "svg"));
    font_info.index_map = yyjson_get_int(yyjson_obj_get(arg_root, "index_map"));
    font_info.indexToLocFormat = yyjson_get_int(yyjson_obj_get(arg_root, "indexToLocFormat"));
    font_info.cff.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "cff_data"));
    font_info.cff.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "cff_cursor"));
    font_info.cff.size = yyjson_get_int(yyjson_obj_get(arg_root, "cff_size"));
    font_info.charstrings.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "charstrings_data"));
    font_info.charstrings.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_cursor"));
    font_info.charstrings.size = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_size"));
    font_info.gsubrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.gsubrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_cursor"));
    font_info.gsubrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.subrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "subrs_data"));
    font_info.subrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_cursor"));
    font_info.subrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_size"));
    font_info.fontdicts.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fontdicts_data"));
    font_info.fontdicts.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_cursor"));
    font_info.fontdicts.size = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_size"));
    font_info.fdselect.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fdselect_data"));
    font_info.fdselect.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_cursor"));
    font_info.fdselect.size = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_size"));

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

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", glyph_size.width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", glyph_size.height);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
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

    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_EXPORT void *raia_draw_text_rgba(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    const uint8_t *text = (const uint8_t *)yyjson_get_str(yyjson_obj_get(arg_root, "text"));
    int font_size = yyjson_get_int(yyjson_obj_get(arg_root, "font_size"));
    raia_color_t color;
    color.red = yyjson_get_int(yyjson_obj_get(arg_root, "color_red"));
    color.green = yyjson_get_int(yyjson_obj_get(arg_root, "color_green"));
    color.blue = yyjson_get_int(yyjson_obj_get(arg_root, "color_blue"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "font_buffer"));
    stbtt_fontinfo font_info;
    font_info.userdata = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "userdata"));
    font_info.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "data"));
    font_info.fontstart = yyjson_get_int(yyjson_obj_get(arg_root, "fontstart"));
    font_info.numGlyphs = yyjson_get_int(yyjson_obj_get(arg_root, "numGlyphs"));
    font_info.loca = yyjson_get_int(yyjson_obj_get(arg_root, "loca"));
    font_info.head = yyjson_get_int(yyjson_obj_get(arg_root, "head"));
    font_info.glyf = yyjson_get_int(yyjson_obj_get(arg_root, "glyf"));
    font_info.hhea = yyjson_get_int(yyjson_obj_get(arg_root, "hhea"));
    font_info.hmtx = yyjson_get_int(yyjson_obj_get(arg_root, "hmtx"));
    font_info.kern = yyjson_get_int(yyjson_obj_get(arg_root, "kern"));
    font_info.gpos = yyjson_get_int(yyjson_obj_get(arg_root, "gpos"));
    font_info.svg = yyjson_get_int(yyjson_obj_get(arg_root, "svg"));
    font_info.index_map = yyjson_get_int(yyjson_obj_get(arg_root, "index_map"));
    font_info.indexToLocFormat = yyjson_get_int(yyjson_obj_get(arg_root, "indexToLocFormat"));
    font_info.cff.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "cff_data"));
    font_info.cff.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "cff_cursor"));
    font_info.cff.size = yyjson_get_int(yyjson_obj_get(arg_root, "cff_size"));
    font_info.charstrings.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "charstrings_data"));
    font_info.charstrings.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_cursor"));
    font_info.charstrings.size = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_size"));
    font_info.gsubrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.gsubrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_cursor"));
    font_info.gsubrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.subrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "subrs_data"));
    font_info.subrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_cursor"));
    font_info.subrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_size"));
    font_info.fontdicts.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fontdicts_data"));
    font_info.fontdicts.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_cursor"));
    font_info.fontdicts.size = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_size"));
    font_info.fdselect.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fdselect_data"));
    font_info.fdselect.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_cursor"));
    font_info.fdselect.size = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_size"));

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

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", glyph_size.width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", glyph_size.height);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
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
    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_EXPORT void *raia_draw_get_text_size(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    const uint8_t *text = (const uint8_t *)yyjson_get_str(yyjson_obj_get(arg_root, "text"));
    int font_size = yyjson_get_int(yyjson_obj_get(arg_root, "font_size"));
    stbtt_fontinfo font_info;
    font_info.userdata = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "userdata"));
    font_info.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "data"));
    font_info.fontstart = yyjson_get_int(yyjson_obj_get(arg_root, "fontstart"));
    font_info.numGlyphs = yyjson_get_int(yyjson_obj_get(arg_root, "numGlyphs"));
    font_info.loca = yyjson_get_int(yyjson_obj_get(arg_root, "loca"));
    font_info.head = yyjson_get_int(yyjson_obj_get(arg_root, "head"));
    font_info.glyf = yyjson_get_int(yyjson_obj_get(arg_root, "glyf"));
    font_info.hhea = yyjson_get_int(yyjson_obj_get(arg_root, "hhea"));
    font_info.hmtx = yyjson_get_int(yyjson_obj_get(arg_root, "hmtx"));
    font_info.kern = yyjson_get_int(yyjson_obj_get(arg_root, "kern"));
    font_info.gpos = yyjson_get_int(yyjson_obj_get(arg_root, "gpos"));
    font_info.svg = yyjson_get_int(yyjson_obj_get(arg_root, "svg"));
    font_info.index_map = yyjson_get_int(yyjson_obj_get(arg_root, "index_map"));
    font_info.indexToLocFormat = yyjson_get_int(yyjson_obj_get(arg_root, "indexToLocFormat"));
    font_info.cff.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "cff_data"));
    font_info.cff.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "cff_cursor"));
    font_info.cff.size = yyjson_get_int(yyjson_obj_get(arg_root, "cff_size"));
    font_info.charstrings.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "charstrings_data"));
    font_info.charstrings.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_cursor"));
    font_info.charstrings.size = yyjson_get_int(yyjson_obj_get(arg_root, "charstrings_size"));
    font_info.gsubrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.gsubrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_cursor"));
    font_info.gsubrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "gsubrs_data"));
    font_info.subrs.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "subrs_data"));
    font_info.subrs.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_cursor"));
    font_info.subrs.size = yyjson_get_int(yyjson_obj_get(arg_root, "subrs_size"));
    font_info.fontdicts.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fontdicts_data"));
    font_info.fontdicts.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_cursor"));
    font_info.fontdicts.size = yyjson_get_int(yyjson_obj_get(arg_root, "fontdicts_size"));
    font_info.fdselect.data = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "fdselect_data"));
    font_info.fdselect.cursor = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_cursor"));
    font_info.fdselect.size = yyjson_get_int(yyjson_obj_get(arg_root, "fdselect_size"));

    raia_size_t glyph_size = _draw_get_text_size(text, font_size, font_info);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", glyph_size.width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", glyph_size.height);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_draw_text_rgba_old(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    uint8_t *pixels_rgba = (uint8_t *)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "pixels_rgba"));
    int pixels_rgba_width = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_width"));
    int pixels_rgba_height = yyjson_get_int(yyjson_obj_get(arg_root, "pixels_rgba_height"));
    const uint8_t *text = (const uint8_t *)yyjson_get_str(yyjson_obj_get(arg_root, "text"));
    const char *font_path = (const char *)yyjson_get_str(yyjson_obj_get(arg_root, "font_path"));
    int font_size = yyjson_get_int(yyjson_obj_get(arg_root, "font_size"));
    int position_x = yyjson_get_int(yyjson_obj_get(arg_root, "position_x"));
    int position_y = yyjson_get_int(yyjson_obj_get(arg_root, "position_y"));

    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);
    CharacterSize character_size = render_character(pixels_rgba, pixels_rgba_width, pixels_rgba_height, position_x, position_y, font_path, font_size, unicode_codepoint);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", character_size.width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", character_size.height);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

//---d3m

RAIA_EXPORT void *raia_draw_d3m_init(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    double width = yyjson_get_real(yyjson_obj_get(arg_root, "width"));
    double height = yyjson_get_real(yyjson_obj_get(arg_root, "height"));

    d3set_winx(width);
    d3set_winy(height);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}
RAIA_EXPORT void *raia_draw_d3m_set_camera(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    double pos_x = yyjson_get_real(yyjson_obj_get(arg_root, "pos_x"));
    double pos_y = yyjson_get_real(yyjson_obj_get(arg_root, "pos_y"));
    double pos_z = yyjson_get_real(yyjson_obj_get(arg_root, "pos_z"));
    double target_x = yyjson_get_real(yyjson_obj_get(arg_root, "target_x"));
    double target_y = yyjson_get_real(yyjson_obj_get(arg_root, "target_y"));
    double target_z = yyjson_get_real(yyjson_obj_get(arg_root, "target_z"));

    d3setcam_2(pos_x, pos_y, pos_z, target_x, target_y, target_z);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}
RAIA_EXPORT void *raia_draw_d3m_calc_position(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    double pos_x = yyjson_get_real(yyjson_obj_get(arg_root, "pos_x"));
    double pos_y = yyjson_get_real(yyjson_obj_get(arg_root, "pos_y"));
    double pos_z = yyjson_get_real(yyjson_obj_get(arg_root, "pos_z"));

    d3vpos(pos_x, pos_y, pos_z);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "x", (int)d3getdx());
    yyjson_mut_obj_add_int(ret_doc, ret_root, "y", (int)d3getdy());
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}