#include "raia_image.h"

RAIA_API const char * raia_image_load(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)joint_get_in_uint_to_ptr(joint, "pixels");
    raia_size_t size = {
            .width = joint_get_in_int(joint, "width"),
            .height = joint_get_in_int(joint, "height"),
    };
    const char* filename = joint_get_in_str(joint, "filename");
    raia_point_t pos = {
            .x = joint_get_in_int(joint, "pos_x"),
            .y = joint_get_in_int(joint, "pos_y"),
    };

    raia_size_t image_size = _raia_image_load(filename, pixels, pos, size);

    joint_add_out_int(joint, "width", image_size.width);
    joint_add_out_int(joint, "height", image_size.height);

    return joint_out_write(joint);
}

RAIA_API const char * raia_image_load_jpg_blend_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)joint_get_in_uint_to_ptr(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char* filename = joint_get_in_str(joint, "filename");
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    int trim_x1 = joint_get_in_int(joint, "trim_x1");
    int trim_y1 = joint_get_in_int(joint, "trim_y1");
    int trim_x2 = joint_get_in_int(joint, "trim_x2");
    int trim_y2 = joint_get_in_int(joint, "trim_y2");

    raia_size_t image_size = _raia_image_load_jpg_blend_rgb(
            pixels, width, height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);

    joint_add_out_int(joint, "width", image_size.width);
    joint_add_out_int(joint, "height", image_size.height);
    return joint_out_write(joint);
}

RAIA_API const char * raia_image_load_jpg_blend_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)joint_get_in_uint_to_ptr(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char* filename = joint_get_in_str(joint, "filename");
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    int trim_x1 = joint_get_in_int(joint, "trim_x1");
    int trim_y1 = joint_get_in_int(joint, "trim_y1");
    int trim_x2 = joint_get_in_int(joint, "trim_x2");
    int trim_y2 = joint_get_in_int(joint, "trim_y2");

    raia_size_t image_size = _raia_image_load_jpg_blend_rgba(
            pixels, width, height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);

    joint_add_out_int(joint, "width", image_size.width);
    joint_add_out_int(joint, "height", image_size.height);
    return joint_out_write(joint);
}

RAIA_API const char * raia_image_load_png_blend_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)joint_get_in_uint_to_ptr(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char* filename = joint_get_in_str(joint, "filename");
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    int trim_x1 = joint_get_in_int(joint, "trim_x1");
    int trim_y1 = joint_get_in_int(joint, "trim_y1");
    int trim_x2 = joint_get_in_int(joint, "trim_x2");
    int trim_y2 = joint_get_in_int(joint, "trim_y2");

    raia_size_t image_size = _raia_image_load_png_blend_rgb(
            pixels, width, height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);

    joint_add_out_int(joint, "width", image_size.width);
    joint_add_out_int(joint, "height", image_size.height);
    return joint_out_write(joint);
}

RAIA_API const char * raia_image_load_png_blend_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)joint_get_in_uint_to_ptr(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char* filename = joint_get_in_str(joint, "filename");
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    int trim_x1 = joint_get_in_int(joint, "trim_x1");
    int trim_y1 = joint_get_in_int(joint, "trim_y1");
    int trim_x2 = joint_get_in_int(joint, "trim_x2");
    int trim_y2 = joint_get_in_int(joint, "trim_y2");

    raia_size_t image_size = _raia_image_load_png_blend_rgba(
            pixels, width, height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);

    joint_add_out_int(joint, "width", image_size.width);
    joint_add_out_int(joint, "height", image_size.height);
    return joint_out_write(joint);
}