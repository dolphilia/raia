//
// Created by dolphilia on 2023/01/21.
//

#include "util_pixel.h"

raia_color_t get_pixel_color(const uint8_t *pixels, raia_point_t point, raia_size_t canvas, int32_t samples_per_pixel) {
    if (point.x < 0 || point.y < 0 || point.x >= canvas.width || point.y >= canvas.height) {
        raia_color_t ret = {0,0,0, 255};
        return ret;
    }
    int index = point.y * canvas.width * samples_per_pixel + point.x * samples_per_pixel;//(canvas.height - 1 - point.y) * canvas.width * samples_per_pixel + point.x * samples_per_pixel;
    raia_color_t color = {
        .red = pixels[index],
        .green = pixels[index + 1],
        .blue = pixels[index + 2],
        .alpha = 255,
    };
    return color;
}

raia_color_t get_pixel_color_rgba(const uint8_t *pixels, raia_point_t point, raia_size_t canvas, int32_t samples_per_pixel) {
    if (point.x < 0 || point.y < 0 || point.x >= canvas.width || point.y >= canvas.height) {
        raia_color_t ret = {0,0,0, 0};
        return ret;
    }
    int index = point.y * canvas.width * samples_per_pixel + point.x * samples_per_pixel;//(canvas.height - 1 - point.y) * canvas.width * samples_per_pixel + point.x * samples_per_pixel;
    raia_color_t color = {
            .red = pixels[index],
            .green = pixels[index + 1],
            .blue = pixels[index + 2],
            .alpha = pixels[index + 3],
    };
    return color;
}

void set_pixel_rgb(uint8_t *pixels, raia_point_t point, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    if (point.x < 0 || point.y < 0 || point.x >= canvas.width || point.y >= canvas.height) {
        return;
    }
    int index = point.y * canvas.width * samples_per_pixel + point.x * samples_per_pixel;
    pixels[index] = color.red;
    pixels[index + 1] = color.green;
    pixels[index + 2] = color.blue;
}

raia_color_t blend_colors(raia_color_t color_a, raia_color_t color_b, uint8_t alpha) {
    raia_color_t blended_color;

    if (alpha == 0) {
        return color_b;
    }
    double alpha_normalized = -alpha / 255.0;
    double inv_alpha_normalized = 1.0 - alpha_normalized;

    blended_color.red = (uint8_t)(color_a.red * inv_alpha_normalized + color_b.red * alpha_normalized);
    blended_color.green = (uint8_t)(color_a.green * inv_alpha_normalized + color_b.green * alpha_normalized);
    blended_color.blue = (uint8_t)(color_a.blue * inv_alpha_normalized + color_b.blue * alpha_normalized);

    return blended_color;
}

raia_color_t blend_colors_rgba(const raia_color_t color_a, const raia_color_t color_b) {
    raia_color_t result;
    double alpha_a = color_a.alpha / 255.0;
    double alpha_b = color_b.alpha / 255.0;
    double alpha_out = alpha_a + alpha_b * (1.0 - alpha_a);

    result.alpha = (uint8_t)(alpha_out * 255);
    result.red = (uint8_t)((color_a.red * alpha_a + color_b.red * alpha_b * (1.0 - alpha_a)) / alpha_out);
    result.green = (uint8_t)((color_a.green * alpha_a + color_b.green * alpha_b * (1.0 - alpha_a)) / alpha_out);
    result.blue = (uint8_t)((color_a.blue * alpha_a + color_b.blue * alpha_b * (1.0 - alpha_a)) / alpha_out);

    return result;
}

void set_pixel_rgb_alpha(uint8_t *pixels, raia_point_t point, raia_color_t color, uint8_t alpha, raia_size_t canvas, int32_t samples_per_pixel) {
    if (point.x < 0 || point.y < 0 || point.x >= canvas.width || point.y >= canvas.height) {
        return;
    }
    raia_color_t color_src = get_pixel_color(pixels, point, canvas, samples_per_pixel);
    raia_color_t color_dest = blend_colors(color, color_src, alpha);
    int index = point.y * canvas.width * 3 + point.x * 3;
    pixels[index] = color_dest.red;
    pixels[index + 1] = color_dest.green;
    pixels[index + 2] = color_dest.blue;
}

void set_pixel_rgba(uint8_t *pixels, raia_point_t point, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    if (point.x < 0 || point.y < 0 || point.x >= canvas.width || point.y >= canvas.height) {
        return;
    }
    raia_color_t color_src = get_pixel_color_rgba(pixels, point, canvas, samples_per_pixel);
    raia_color_t color_dest = blend_colors_rgba(color, color_src);
    int index = point.y * canvas.width * samples_per_pixel + point.x * samples_per_pixel;
    pixels[index] = color_dest.red;
    pixels[index + 1] = color_dest.green;
    pixels[index + 2] = color_dest.blue;
    pixels[index + 3] = color_dest.alpha;
}

void set_line_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int delta_x = abs(segment.end.x - segment.start.x);
    int delta_y = abs(segment.end.y - segment.start.y);
    int step_x = (segment.end.x > segment.start.x) ? 1 : -1;
    int step_y = (segment.end.y > segment.start.y) ? 1 : -1;
    int x = segment.start.x;
    int y = segment.start.y;
    int error;
    if (delta_x >= delta_y) {
        error = 2 * delta_y - delta_x;
        for (int i = 0; i <= delta_x; ++i) {
            if (x<0 || x>canvas.width || y<0 || y>canvas.height) { //描画範囲を超える場合
            } else {
                raia_point_t point = {
                    .x = x,
                    .y = y,
                };
                set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
            }
            x += step_x;
            error += 2 * delta_y;
            if (error >= 0) {
                y += step_y;
                error -= 2 * delta_x;
            }
        }
    } else {
        error = 2 * delta_x - delta_y;
        for (int i = 0; i <= delta_y; ++i) {
            if (x<0 || x>canvas.width || y<0 || y>canvas.height) {
            } else {
                raia_point_t point = {
                    .x = x,
                    .y = y,
                };
                set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
            }
            y += step_y;
            error += 2 * delta_x;
            if (error >= 0) {
                x += step_x;
                error -= 2 * delta_y;
            }
        }
    }
}

void set_line_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int delta_x = abs(segment.end.x - segment.start.x);
    int delta_y = abs(segment.end.y - segment.start.y);
    int step_x = (segment.end.x > segment.start.x) ? 1 : -1;
    int step_y = (segment.end.y > segment.start.y) ? 1 : -1;
    int x = segment.start.x;
    int y = segment.start.y;
    int error;
    if (delta_x >= delta_y) {
        error = 2 * delta_y - delta_x;
        for (int i = 0; i <= delta_x; ++i) {
            if (x<0 || x>canvas.width || y<0 || y>canvas.height) { //描画範囲を超える場合
            } else {
                raia_point_t point = {
                        .x = x,
                        .y = y,
                };
                set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);
            }
            x += step_x;
            error += 2 * delta_y;
            if (error >= 0) {
                y += step_y;
                error -= 2 * delta_x;
            }
        }
    } else {
        error = 2 * delta_x - delta_y;
        for (int i = 0; i <= delta_y; ++i) {
            if (x<0 || x>canvas.width || y<0 || y>canvas.height) {
            } else {
                raia_point_t point = {
                        .x = x,
                        .y = y,
                };
                set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);
            }
            y += step_y;
            error += 2 * delta_x;
            if (error >= 0) {
                x += step_x;
                error -= 2 * delta_y;
            }
        }
    }
}

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void fill_rect_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int min_x = MIN(segment.start.x, segment.end.x);
    int min_y = MIN(segment.start.y, segment.end.y);
    int diff_x = MAX(segment.start.x, segment.end.x) - MIN(segment.start.x, segment.end.x) + 1;
    int diff_y = MAX(segment.start.y, segment.end.y) - MIN(segment.start.y, segment.end.y) + 1;
    for (int y = 0; y < diff_y; y++) {
        for (int x = 0; x < diff_x; x++) {
            raia_point_t point = {
                .x = min_x + x,
                .y = min_y + y,
            };
            set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
        }
    }
}

void fill_rect_rgb_fast(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t size, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int red = color.red;
    int green = color.green;
    int blue = color.blue;
    int width = size.width;
    int height = size.height;
    int row_length = (x2 - x1 + 1) * samples_per_pixel;
    uint8_t *row_buffer = (uint8_t *)malloc(row_length);
    row_buffer[0] = red;
    row_buffer[1] = green;
    row_buffer[2] = blue;

    // Use memcpy to copy the color to the rest of the row_buffer
    for (int i = samples_per_pixel; i < row_length; i *= 2) {
        int copy_size = i < row_length - i ? i : row_length - i;
        memcpy(&row_buffer[i], row_buffer, copy_size);
    }

    for (int y = y1; y <= y2; y++) {
        uint8_t *dst = &pixels[(y * width + x1) * samples_per_pixel];
        memcpy(dst, row_buffer, row_length);
    }

    free(row_buffer);
}

void fill_rect_rgb_alpha(uint8_t *pixels, raia_segment_t segment, raia_color_t color, uint8_t alpha, raia_size_t canvas, int32_t samples_per_pixel) {
    int min_x = MIN(segment.start.x, segment.end.x);
    int min_y = MIN(segment.start.y, segment.end.y);
    int diff_x = MAX(segment.start.x, segment.end.x) - MIN(segment.start.x, segment.end.x) + 1;
    int diff_y = MAX(segment.start.y, segment.end.y) - MIN(segment.start.y, segment.end.y) + 1;
    for (int y = 0; y < diff_y; y++) {
        for (int x = 0; x < diff_x; x++) {
            raia_point_t point = {
                    .x = min_x + x,
                    .y = min_y + y,
            };
            set_pixel_rgb_alpha(pixels, point, color, alpha, canvas, samples_per_pixel);
        }
    }
}

void fill_rect_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int min_x = MIN(segment.start.x, segment.end.x);
    int min_y = MIN(segment.start.y, segment.end.y);
    int diff_x = MAX(segment.start.x, segment.end.x) - MIN(segment.start.x, segment.end.x) + 1;
    int diff_y = MAX(segment.start.y, segment.end.y) - MIN(segment.start.y, segment.end.y) + 1;
    for (int y = 0; y < diff_y; y++) {
        for (int x = 0; x < diff_x; x++) {
            raia_point_t point = {
                    .x = min_x + x,
                    .y = min_y + y,
            };
            set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);
        }
    }
}

void draw_ellipse(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int a = abs(x2 - x1) / 2;
    int b = abs(y2 - y1) / 2;
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;
    raia_point_t point;

    int x = 0;
    int y = b;
    int a2 = a * a;
    int b2 = b * b;
    int fx = 0;
    int fy = 2 * a2 * y;

    int p = (int)(b2 - a2 * b + 0.25 * a2);

    while (fx < fy) {
        point.x = xc + x;
        point.y = yc + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc + x;
        point.y = yc - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        x++;
        fx += 2 * b2;

        if (p < 0) {
            p += fx + b2;
        } else {
            y--;
            fy -= 2 * a2;
            p += fx - fy + b2;
        }
    }

    p = (int)(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);

    while (y >= 0) {
        point.x = xc + x;
        point.y = yc + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc + x;
        point.y = yc - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);

        y--;
        fy -= 2 * a2;

        if (p >= 0) {
            p -= fy + a2;
        } else {
            x++;
            fx += 2 * b2;
            p += fx - fy + a2;
        }
    }
}

void draw_ellipse_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int a = abs(x2 - x1) / 2;
    int b = abs(y2 - y1) / 2;
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;
    raia_point_t point;

    int x = 0;
    int y = b;
    int a2 = a * a;
    int b2 = b * b;
    int fx = 0;
    int fy = 2 * a2 * y;

    int p = (int)(b2 - a2 * b + 0.25 * a2);

    while (fx < fy) {
        point.x = xc + x;
        point.y = yc + y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc + y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc + x;
        point.y = yc - y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc - y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        x++;
        fx += 2 * b2;

        if (p < 0) {
            p += fx + b2;
        } else {
            y--;
            fy -= 2 * a2;
            p += fx - fy + b2;
        }
    }

    p = (int)(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);

    while (y >= 0) {
        point.x = xc + x;
        point.y = yc + y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc + y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc + x;
        point.y = yc - y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        point.x = xc - x;
        point.y = yc - y;
        set_pixel_rgba(pixels, point, color, canvas, samples_per_pixel);

        y--;
        fy -= 2 * a2;

        if (p >= 0) {
            p -= fy + a2;
        } else {
            x++;
            fx += 2 * b2;
            p += fx - fy + a2;
        }
    }
}

void draw_filled_ellipse(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int a = abs(x2 - x1) / 2;
    int b = abs(y2 - y1) / 2;
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;
    raia_segment_t seg;

    int x = 0;
    int y = b;
    int a2 = a * a;
    int b2 = b * b;
    int fx = 0;
    int fy = 2 * a2 * y;

    int p = (int)(b2 - a2 * b + 0.25 * a2);

    while (fx < fy) {
        seg.start.x = xc - x;
        seg.start.y = yc + y;
        seg.end.x = xc + x;
        seg.end.y = yc + y;
        set_line_rgb(pixels, seg, color, canvas, samples_per_pixel);

        seg.start.x = xc - x;
        seg.start.y = yc - y;
        seg.end.x = xc + x;
        seg.end.y = yc - y;
        set_line_rgb(pixels, seg, color, canvas, samples_per_pixel);

        x++;
        fx += 2 * b2;

        if (p < 0) {
            p += fx + b2;
        } else {
            y--;
            fy -= 2 * a2;
            p += fx - fy + b2;
        }
    }

    p = (int)(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);

    while (y >= 0) {
        seg.start.x = xc - x;
        seg.start.y = yc + y;
        seg.end.x = xc + x;
        seg.end.y = yc + y;
        set_line_rgb(pixels, seg, color, canvas, samples_per_pixel);

        seg.start.x = xc - x;
        seg.start.y = yc - y;
        seg.end.x = xc + x;
        seg.end.y = yc - y;
        set_line_rgb(pixels, seg, color, canvas, samples_per_pixel);

        y--;
        fy -= 2 * a2;

        if (p >= 0) {
            p -= fy + a2;
        } else {
            x++;
            fx += 2 * b2;
            p += fx - fy + a2;
        }
    }
}

void draw_filled_ellipse_rgba(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int a = abs(x2 - x1) / 2;
    int b = abs(y2 - y1) / 2;
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;
    raia_segment_t seg;

    int x = 0;
    int y = b;
    int a2 = a * a;
    int b2 = b * b;
    int fx = 0;
    int fy = 2 * a2 * y;

    int p = (int)(b2 - a2 * b + 0.25 * a2);

    while (fx < fy) {
        seg.start.x = xc - x;
        seg.start.y = yc + y;
        seg.end.x = xc + x;
        seg.end.y = yc + y;
        set_line_rgba(pixels, seg, color, canvas, samples_per_pixel);

        seg.start.x = xc - x;
        seg.start.y = yc - y;
        seg.end.x = xc + x;
        seg.end.y = yc - y;
        set_line_rgba(pixels, seg, color, canvas, samples_per_pixel);

        x++;
        fx += 2 * b2;

        if (p < 0) {
            p += fx + b2;
        } else {
            y--;
            fy -= 2 * a2;
            p += fx - fy + b2;
        }
    }

    p = (int)(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);

    while (y >= 0) {
        seg.start.x = xc - x;
        seg.start.y = yc + y;
        seg.end.x = xc + x;
        seg.end.y = yc + y;
        set_line_rgba(pixels, seg, color, canvas, samples_per_pixel);

        seg.start.x = xc - x;
        seg.start.y = yc - y;
        seg.end.x = xc + x;
        seg.end.y = yc - y;
        set_line_rgba(pixels, seg, color, canvas, samples_per_pixel);

        y--;
        fy -= 2 * a2;

        if (p >= 0) {
            p -= fy + a2;
        } else {
            x++;
            fx += 2 * b2;
            p += fx - fy + a2;
        }
    }
}


void draw_filled_ellipse_smooth(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    int x1 = segment.start.x;
    int y1 = segment.start.y;
    int x2 = segment.end.x;
    int y2 = segment.end.y;
    int width = x2 - x1;
    int height = y2 - y1;
    double radius_x = width / 2.0;
    double radius_y = height / 2.0;
    double center_x = x1 + radius_x;
    double center_y = y1 + radius_y;
    raia_segment_t seg;
    raia_point_t point;
    raia_color_t src_color;
    raia_color_t dist_color;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            double normalized_x = (x - center_x) / radius_x;
            double normalized_y = (y - center_y) / radius_y;
            double distance_squared = normalized_x * normalized_x + normalized_y * normalized_y;

            if (distance_squared <= 1) {
                if (distance_squared > 0.99) {
                    // Compute alpha for anti-aliasing
                    double distance = sqrt(distance_squared);
                    uint8_t alpha = (uint8_t)((1 - (distance - 0.99) / 0.01) * 255);
                    point.x = x;
                    point.y = y;
                    src_color = get_pixel_color(pixels, point, canvas, samples_per_pixel);
                    dist_color = blend_colors(color, src_color, alpha);
                    set_pixel_rgb(pixels, point, dist_color, canvas, samples_per_pixel);
                } else {
                    point.x = x;
                    point.y = y;
                    set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
                }
            }
        }
    }
}

void set_circle_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    if (segment.start.x >= segment.end.x || segment.start.y >= segment.end.y) {
        return;
    }
    double ix1 = segment.start.x;
    double iy1 = segment.start.y;
    double ix2 = segment.end.x;
    double iy2 = segment.end.y;
    double radius_width = (ix2 - ix1) / 2.0;
    double radius_height = (iy2 - iy1) / 2.0;
    double ratio_width = 1.0;
    double ratio_height = (ix2 - ix1) / (iy2 - iy1);
    double ratio_height_square = ratio_height *= ratio_height;
    int center_point_x = (int)(ix1 + radius_width);
    int center_point_y = (int)(iy1 + radius_height);
    int x = (int)(radius_width / sqrt(ratio_width));
    int y = 0;
    double d = sqrt(ratio_width) * radius_width;
    int F = (int)(-2.0 * d) + ratio_width + 2 * ratio_height_square;
    int H = (int)(-4.0 * d) + 2 * ratio_width + ratio_height_square;
    while (x >= 0) {
        raia_point_t point;
        point.x = center_point_x + x;
        point.y = center_point_y + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
        point.x = center_point_x - x;
        point.y = center_point_y + y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
        point.x = center_point_x + x;
        point.y = center_point_y - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
        point.x = center_point_x - x;
        point.y = center_point_y - y;
        set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
        if (F >= 0) {
            --x;
            F -= 4 * ratio_width * x;
            H -= 4 * ratio_width * x - 2 * ratio_width;
        }
        if (H < 0) {
            ++y;
            F += 4 * ratio_height_square * y + 2 * ratio_height_square;
            H += 4 * ratio_height_square * y;
        }
    }
}

void fill_circle_rgb(uint8_t *pixels, raia_segment_t segment, raia_color_t color, raia_size_t canvas, int32_t samples_per_pixel) {
    if (segment.start.x >= segment.end.x || segment.start.y >= segment.end.y) {
        return;
    }
    double _x1 = segment.start.x;
    double _y1 = segment.start.y;
    double _x2 = segment.end.x;
    double _y2 = segment.end.y;
    double radius_width = (_x2 - _x1) / 2.0;
    double radius_height = (_y2 - _y1) / 2.0;
    double x, y;
    double ratioHeightReverse = (_y2 - _y1) / (_x2 - _x1);

    for (int iy = segment.start.y; iy < segment.end.y + radius_height; iy++) {
        for (int ix = segment.start.x; ix < segment.end.x + radius_width; ix++) {
            x = ix - segment.start.x - radius_width;
            y = iy - segment.start.y - radius_height;
            y /= ratioHeightReverse;
            if (x * x + y * y < radius_width * radius_width) {
                raia_point_t point = {
                    .x = ix,
                    .y = iy,
                };
                set_pixel_rgb(pixels, point, color, canvas, samples_per_pixel);
            }
        }
    }
}

void blend_pixels_rgba_to_rgb(
        uint8_t *pixels_rgb, int pixels_rgb_width, int pixels_rgb_height,
        uint8_t *pixels_rgba, int pixels_rgba_width, int pixels_rgba_height,
        int position_x, int position_y,
        int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2
) {
    for (int y = trimming_y1; y < trimming_y2; y++) {
        for (int x = trimming_x1; x < trimming_x2; x++) {
            int src_x = x;
            int src_y = y;
            int dst_x = position_x + x - trimming_x1;
            int dst_y = position_y + y - trimming_y1;

            bool within_src_bounds = (src_x >= 0 && src_x < pixels_rgba_width && src_y >= 0 && src_y < pixels_rgba_height);
            bool within_dst_bounds = (dst_x >= 0 && dst_x < pixels_rgb_width && dst_y >= 0 && dst_y < pixels_rgb_height);

            if (within_src_bounds && within_dst_bounds) {
                int src_index = (src_y * pixels_rgba_width + src_x) * 4;
                int dst_index = (dst_y * pixels_rgb_width + dst_x) * 3;

                float src_alpha = pixels_rgba[src_index + 3] / 255.0f;
                pixels_rgb[dst_index]     = (uint8_t)(pixels_rgb[dst_index]     * (1 - src_alpha) + pixels_rgba[src_index]     * src_alpha);
                pixels_rgb[dst_index + 1] = (uint8_t)(pixels_rgb[dst_index + 1] * (1 - src_alpha) + pixels_rgba[src_index + 1] * src_alpha);
                pixels_rgb[dst_index + 2] = (uint8_t)(pixels_rgb[dst_index + 2] * (1 - src_alpha) + pixels_rgba[src_index + 2] * src_alpha);
            }
        }
    }
}

void blend_pixels_rgba_to_rgba(uint8_t *pixels_rgba_a, int pixels_rgba_a_width, int pixels_rgba_a_height,
                       uint8_t *pixels_rgba_b, int pixels_rgba_b_width, int pixels_rgba_b_height,
                       int position_x, int position_y,
                       int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2) {
    for (int y = trimming_y1; y < trimming_y2; y++) {
        for (int x = trimming_x1; x < trimming_x2; x++) {
            int rgba_b_index = (y * pixels_rgba_b_width + x) * 4;
            int rgba_a_x = position_x + x - trimming_x1;
            int rgba_a_y = position_y + y - trimming_y1;

            if (rgba_a_x >= 0 && rgba_a_x < pixels_rgba_a_width && rgba_a_y >= 0 && rgba_a_y < pixels_rgba_a_height) {
                int rgba_a_index = (rgba_a_y * pixels_rgba_a_width + rgba_a_x) * 4;

                uint8_t alpha_b = pixels_rgba_b[rgba_b_index + 3];
                float alpha_b_norm = alpha_b / 255.0f;
                float alpha_a_inv = 1.0f - alpha_b_norm;

                pixels_rgba_a[rgba_a_index] = (uint8_t)(pixels_rgba_b[rgba_b_index] * alpha_b_norm + pixels_rgba_a[rgba_a_index] * alpha_a_inv);
                pixels_rgba_a[rgba_a_index + 1] = (uint8_t)(pixels_rgba_b[rgba_b_index + 1] * alpha_b_norm + pixels_rgba_a[rgba_a_index + 1] * alpha_a_inv);
                pixels_rgba_a[rgba_a_index + 2] = (uint8_t)(pixels_rgba_b[rgba_b_index + 2] * alpha_b_norm + pixels_rgba_a[rgba_a_index + 2] * alpha_a_inv);

                float alpha_a = pixels_rgba_a[rgba_a_index + 3] / 255.0f;
                float alpha_out = alpha_a + alpha_b_norm * (1.0f - alpha_a);
                pixels_rgba_a[rgba_a_index + 3] = (uint8_t)(alpha_out * 255);
            }
        }
    }
}
