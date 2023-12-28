//
//  wrapper_stb_image.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "wrapper_stb_image.h"

raia_size_t _raia_image_load_init(char const *file_name, uint8_t *pixels) {
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

raia_size_t _raia_image_load(char const *filename, uint8_t *pixels, raia_point_t pos, raia_size_t size) {
    raia_size_t image_size;
    uint8_t *image_pixels;
    int image_width;
    int image_height;
    int image_bpp;//3 or 4
    
    image_pixels = stbi_load(filename, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    int i = pos.x * 3 + pos.y * size.width * 3;
    int j = 0;
    int posx_now = pos.x;
    
    for (int y = 0; y < image_height; y++) {
        if(size.height <= y + pos.y) {
            break;
        }
        posx_now = pos.x;
        for (int x = 0; x < image_width; x++) {
            if(size.width <= x + pos.x || posx_now < 0) {
                j += image_bpp;
                i += 4;
                posx_now++;
                continue;
            }
            if(image_bpp == 4) {
                memcpy(&pixels[i], &image_pixels[j], 4);
            } else {
                memcpy(&pixels[i], &image_pixels[j], 3);
                pixels[i + 3] = 255;
            }
            j += 4;//image_bpp;
            i += 3;
            posx_now++;
        }
        i += size.width * 3 - image_width * 3;
    }
    
    free(image_pixels);
    return image_size;
}

raia_size_t _raia_image_load_jpg_blend_rgb(uint8_t *pixels, int width, int height,
                                           const char *filename,
                                           int pos_x, int pos_y,
                                           int trim_x1, int trim_y1, int trim_x2, int trim_y2) {
    raia_size_t image_size = {0,0};
    unsigned error;
    unsigned char *image_pixels;
    unsigned int image_width_tmp, image_height_tmp;
    int image_width, image_height;
    int image_bpp;//3 or 4

    image_pixels = stbi_load(filename, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    if (trim_x2 == -1) {
        trim_x2 = image_width;
    }
    if (trim_y2 == -1) {
        trim_y2 = image_height;
    }

    // Image bounds checking
    if (trim_x1 < 0) trim_x1 = 0;
    if (trim_y1 < 0) trim_y1 = 0;
    if (trim_x2 > image_width) trim_x2 = image_width;
    if (trim_y2 > image_height) trim_y2 = image_height;

    for (int y = trim_y1; y < trim_y2; ++y) {
        for (int x = trim_x1; x < trim_x2; ++x) {
            int image_index = (y * image_width + x) * 3;
            int pixels_index = ((pos_y + y - trim_y1) * width + (pos_x + x - trim_x1)) * 3;

            if (pos_x + x - trim_x1 >= 0 && pos_x + x - trim_x1 < width && pos_y + y - trim_y1 >= 0 && pos_y + y - trim_y1 < height) {
                //uint8_t src_alpha = image_pixels[image_index + 3];
                //uint8_t dest_alpha = 255 - src_alpha;

                pixels[pixels_index] = image_pixels[image_index]; //(image_pixels[image_index] * src_alpha + pixels[pixels_index] * dest_alpha) / 255;
                pixels[pixels_index + 1] = image_pixels[image_index + 1]; //(image_pixels[image_index + 1] * src_alpha + pixels[pixels_index + 1] * dest_alpha) / 255;
                pixels[pixels_index + 2] = image_pixels[image_index + 2]; //(image_pixels[image_index + 2] * src_alpha + pixels[pixels_index + 2] * dest_alpha) / 255;
                //pixels_rgba[pixels_pos + 3] = 255;
            }
        }
    }

    free(image_pixels);
    return image_size;
}

raia_size_t _raia_image_load_jpg_blend_rgba(uint8_t *pixels, int width, int height,
                                           const char *filename,
                                           int pos_x, int pos_y,
                                           int trim_x1, int trim_y1, int trim_x2, int trim_y2) {
    raia_size_t image_size = {0,0};
    unsigned error;
    unsigned char *image_pixels;
    unsigned int image_width_tmp, image_height_tmp;
    int image_width, image_height;
    int image_bpp;//3 or 4

    image_pixels = stbi_load(filename, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    if (trim_x2 == -1) {
        trim_x2 = image_width;
    }
    if (trim_y2 == -1) {
        trim_y2 = image_height;
    }

    // Image bounds checking
    if (trim_x1 < 0) trim_x1 = 0;
    if (trim_y1 < 0) trim_y1 = 0;
    if (trim_x2 > image_width) trim_x2 = image_width;
    if (trim_y2 > image_height) trim_y2 = image_height;

    for (int y = trim_y1; y < trim_y2; ++y) {
        for (int x = trim_x1; x < trim_x2; ++x) {
            int image_index = (y * image_width + x) * 3;
            int pixels_index = ((pos_y + y - trim_y1) * width + (pos_x + x - trim_x1)) * 4;

            if (pos_x + x - trim_x1 >= 0 && pos_x + x - trim_x1 < width && pos_y + y - trim_y1 >= 0 && pos_y + y - trim_y1 < height) {
                //uint8_t src_alpha = image_pixels[image_index + 3];
                //uint8_t dest_alpha = 255 - src_alpha;

                pixels[pixels_index] = image_pixels[image_index]; //(image_pixels[image_index] * src_alpha + pixels[pixels_index] * dest_alpha) / 255;
                pixels[pixels_index + 1] = image_pixels[image_index + 1]; //(image_pixels[image_index + 1] * src_alpha + pixels[pixels_index + 1] * dest_alpha) / 255;
                pixels[pixels_index + 2] = image_pixels[image_index + 2]; //(image_pixels[image_index + 2] * src_alpha + pixels[pixels_index + 2] * dest_alpha) / 255;
                pixels[pixels_index + 3] = 255;
            }
        }
    }

    free(image_pixels);
    return image_size;
}

raia_size_t _raia_image_load_png_blend_rgb(uint8_t *pixels, int width, int height,
                                           const char *filename,
                                           int pos_x, int pos_y,
                                           int trim_x1, int trim_y1, int trim_x2, int trim_y2) {
    raia_size_t image_size = {0,0};
    unsigned error;
    unsigned char *image_pixels;
    unsigned int image_width_tmp, image_height_tmp;
    int image_width, image_height;
    int image_bpp;//3 or 4

    error = lodepng_decode32_file(&image_pixels, &image_width_tmp, &image_height_tmp, filename);
    if (error) {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        return image_size;
    }
    image_width = (int)image_width_tmp;
    image_height = (int)image_height_tmp;
    //image_pixels = stbi_load(filename, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    if (trim_x2 == -1) {
        trim_x2 = image_width;
    }
    if (trim_y2 == -1) {
        trim_y2 = image_height;
    }

    // Image bounds checking
    if (trim_x1 < 0) trim_x1 = 0;
    if (trim_y1 < 0) trim_y1 = 0;
    if (trim_x2 > image_width) trim_x2 = image_width;
    if (trim_y2 > image_height) trim_y2 = image_height;

    for (int y = trim_y1; y < trim_y2; ++y) {
        for (int x = trim_x1; x < trim_x2; ++x) {
            int image_index = (y * image_width + x) * 4;
            int pixels_index = ((pos_y + y - trim_y1) * width + (pos_x + x - trim_x1)) * 3;

            if (pos_x + x - trim_x1 >= 0 && pos_x + x - trim_x1 < width && pos_y + y - trim_y1 >= 0 && pos_y + y - trim_y1 < height) {
                uint8_t src_alpha = image_pixels[image_index + 3];
                uint8_t dest_alpha = 255 - src_alpha;

                pixels[pixels_index] = (image_pixels[image_index] * src_alpha + pixels[pixels_index] * dest_alpha) / 255;
                pixels[pixels_index + 1] = (image_pixels[image_index + 1] * src_alpha + pixels[pixels_index + 1] * dest_alpha) / 255;
                pixels[pixels_index + 2] = (image_pixels[image_index + 2] * src_alpha + pixels[pixels_index + 2] * dest_alpha) / 255;
                //pixels_rgba[pixels_pos + 3] = 255;
            }
        }
    }

    free(image_pixels);
    return image_size;
}

raia_size_t _raia_image_load_png_blend_rgba(uint8_t *pixels, int width, int height,
                                            const char *filename,
                                            int pos_x, int pos_y,
                                            int trim_x1, int trim_y1, int trim_x2, int trim_y2) {
    raia_size_t image_size = {0,0};
    unsigned error;
    unsigned char *image_pixels;
    unsigned int image_width_tmp, image_height_tmp;
    int image_width, image_height;
    int image_bpp;//3 or 4

    error = lodepng_decode32_file(&image_pixels, &image_width_tmp, &image_height_tmp, filename);
    if (error) {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        return image_size;
    }
    image_width = (int)image_width_tmp;
    image_height = (int)image_height_tmp;
    //image_pixels = stbi_load(filename, &image_width, &image_height, &image_bpp, 0);
    image_size.width = image_width;
    image_size.height = image_height;

    if (trim_x2 == -1) {
        trim_x2 = image_width;
    }
    if (trim_y2 == -1) {
        trim_y2 = image_height;
    }

    // Image bounds checking
    if (trim_x1 < 0) trim_x1 = 0;
    if (trim_y1 < 0) trim_y1 = 0;
    if (trim_x2 > image_width) trim_x2 = image_width;
    if (trim_y2 > image_height) trim_y2 = image_height;

    for (int y = trim_y1; y < trim_y2; ++y) {
        for (int x = trim_x1; x < trim_x2; ++x) {
            int image_pos = (y * image_width + x) * 4;
            int pixels_pos = ((pos_y + y - trim_y1) * width + (pos_x + x - trim_x1)) * 4;

            if (pos_x + x - trim_x1 >= 0 && pos_x + x - trim_x1 < width &&
                pos_y + y - trim_y1 >= 0 && pos_y + y - trim_y1 < height) {
                uint8_t src_alpha = image_pixels[image_pos + 3];
                uint8_t dest_alpha = pixels[pixels_pos + 3];

                uint8_t out_alpha = src_alpha + (dest_alpha * (255 - src_alpha) / 255);

                if (out_alpha != 0) {
                    pixels[pixels_pos] = (image_pixels[image_pos] * src_alpha +
                                          pixels[pixels_pos] * dest_alpha * (255 - src_alpha) / 255) /
                                         out_alpha;
                    pixels[pixels_pos + 1] = (image_pixels[image_pos + 1] * src_alpha +
                                              pixels[pixels_pos + 1] * dest_alpha * (255 - src_alpha) / 255) /
                                             out_alpha;
                    pixels[pixels_pos + 2] = (image_pixels[image_pos + 2] * src_alpha +
                                              pixels[pixels_pos + 2] * dest_alpha * (255 - src_alpha) / 255) /
                                             out_alpha;
                    pixels[pixels_pos + 3] = out_alpha;
                }
            }
        }
    }

    free(image_pixels);
    return image_size;
}