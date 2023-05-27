//
//  wrapper_stb_image.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "wrapper_stb_image.h"

raia_size_t load_image_init_canvas(char const *file_name, uint8_t *pixels) {
    raia_size_t image_size;
    uint8_t *image_pixels;
    int image_width;
    int image_height;
    int image_bpp;// 3 or 4
    
    image_pixels = stbi_load(file_name, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;
    
    if(image_bpp == 4) {
        memcpy(pixels, image_pixels, image_width * image_height * image_bpp * sizeof(unsigned char));
    } else {
        int i = 0;
        for(int j = 0; j < image_width * image_height * image_bpp; j += 3) {
            memcpy(&pixels[i], &image_pixels[j], 3);
            pixels[i + 3] = 255;
            i += 4;
        }
    }
    
    free(image_pixels);
    return image_size;
}

raia_size_t load_image(char const *file_name, uint8_t *pixel_data, raia_point_t point, raia_size_t canvas) {
    raia_size_t image_size;
    uint8_t *image_pixels;
    int image_width;
    int image_height;
    int image_bpp;//3 or 4
    
    image_pixels = stbi_load(file_name, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    int i = point.x * 3 + point.y * canvas.width * 3;
    int j = 0;
    int posx_now = point.x;
    
    for (int y = 0; y < image_height; y++) {
        if(canvas.height <= y + point.y) {
            break;
        }
        posx_now = point.x;
        for (int x = 0; x < image_width; x++) {
            if(canvas.width <= x + point.x || posx_now < 0) {
                j += image_bpp;
                i += 4;
                posx_now++;
                continue;
            }
            if(image_bpp == 4) {
                memcpy(&pixel_data[i], &image_pixels[j], 4);
            } else {
                memcpy(&pixel_data[i], &image_pixels[j], 3);
                pixel_data[i + 3] = 255;
            }
            j += 4;//image_bpp;
            i += 3;
            posx_now++;
        }
        i += canvas.width * 3 - image_width * 3;
    }
    
    free(image_pixels);
    return image_size;
}

void load_and_blend_image_rgba(uint8_t *pixels_rgba, int pixels_rgba_width, int pixels_rgba_height,
                               const char *filename,
                               int position_x, int position_y,
                               int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2) {
    unsigned error;
    unsigned char *image_data;
    unsigned width_png, height_png;

    error = lodepng_decode32_file(&image_data, &width_png, &height_png, filename);
    if (error) {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        return;
    }

    if (trimming_x2 == -1) {
        trimming_x2 = width_png;
    }
    if (trimming_y2 == -1) {
        trimming_y2 = height_png;
    }

    // Image bounds checking
    if (trimming_x1 < 0) trimming_x1 = 0;
    if (trimming_y1 < 0) trimming_y1 = 0;
    if (trimming_x2 > width_png) trimming_x2 = width_png;
    if (trimming_y2 > height_png) trimming_y2 = height_png;

    for (int y = trimming_y1; y < trimming_y2; ++y) {
        for (int x = trimming_x1; x < trimming_x2; ++x) {
            int image_pos = (y * width_png + x) * 4;
            int pixels_pos = ((position_y + y - trimming_y1) * pixels_rgba_width + (position_x + x - trimming_x1)) * 4;

            if (position_x + x - trimming_x1 >= 0 && position_x + x - trimming_x1 < pixels_rgba_width &&
                position_y + y - trimming_y1 >= 0 && position_y + y - trimming_y1 < pixels_rgba_height) {
                uint8_t src_alpha = image_data[image_pos + 3];
                uint8_t dest_alpha = pixels_rgba[pixels_pos + 3];

                uint8_t out_alpha = src_alpha + (dest_alpha * (255 - src_alpha) / 255);

                if (out_alpha != 0) {
                    pixels_rgba[pixels_pos] = (image_data[image_pos] * src_alpha +
                                               pixels_rgba[pixels_pos] * dest_alpha * (255 - src_alpha) / 255) /
                                              out_alpha;
                    pixels_rgba[pixels_pos + 1] = (image_data[image_pos + 1] * src_alpha +
                                                   pixels_rgba[pixels_pos + 1] * dest_alpha * (255 - src_alpha) / 255) /
                                                  out_alpha;
                    pixels_rgba[pixels_pos + 2] = (image_data[image_pos + 2] * src_alpha +
                                                   pixels_rgba[pixels_pos + 2] * dest_alpha * (255 - src_alpha) / 255) /
                                                  out_alpha;
                    pixels_rgba[pixels_pos + 3] = out_alpha;
                }
            }
        }
    }

    free(image_data);
}

void load_and_blend_image_rgb(uint8_t *pixels_rgb, int pixels_rgb_width, int pixels_rgb_height,
                               const char *filename,
                               int position_x, int position_y,
                               int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2) {
    unsigned error;
    unsigned char *image_data;
    unsigned width_png, height_png;

    error = lodepng_decode32_file(&image_data, &width_png, &height_png, filename);
    if (error) {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        return;
    }

    if (trimming_x2 == -1) {
        trimming_x2 = width_png;
    }
    if (trimming_y2 == -1) {
        trimming_y2 = height_png;
    }

    // Image bounds checking
    if (trimming_x1 < 0) trimming_x1 = 0;
    if (trimming_y1 < 0) trimming_y1 = 0;
    if (trimming_x2 > width_png) trimming_x2 = width_png;
    if (trimming_y2 > height_png) trimming_y2 = height_png;

    for (int y = trimming_y1; y < trimming_y2; ++y) {
        for (int x = trimming_x1; x < trimming_x2; ++x) {
            int image_pos = (y * width_png + x) * 4;
            int pixels_pos = ((position_y + y - trimming_y1) * pixels_rgb_width + (position_x + x - trimming_x1)) * 3;

            if (position_x + x - trimming_x1 >= 0 && position_x + x - trimming_x1 < pixels_rgb_width && position_y + y - trimming_y1 >= 0 && position_y + y - trimming_y1 < pixels_rgb_height) {
                uint8_t src_alpha = image_data[image_pos + 3];
                uint8_t dest_alpha = 255 - src_alpha;

                pixels_rgb[pixels_pos] = (image_data[image_pos] * src_alpha + pixels_rgb[pixels_pos] * dest_alpha) / 255;
                pixels_rgb[pixels_pos + 1] = (image_data[image_pos + 1] * src_alpha + pixels_rgb[pixels_pos + 1] * dest_alpha) / 255;
                pixels_rgb[pixels_pos + 2] = (image_data[image_pos + 2] * src_alpha + pixels_rgb[pixels_pos + 2] * dest_alpha) / 255;
                //pixels_rgba[pixels_pos + 3] = 255;
            }
        }
    }

    free(image_data);
}