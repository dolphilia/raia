//
//  wrapper_stb_image.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef wrapper_stb_image_h
#define wrapper_stb_image_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include "../../../../../thirdparty/c/nothings/stb/stb_image.h"
#include "../../../../../thirdparty/c/nothings/stb/stb_image_write.h"
#include "../../../../../thirdparty/c/lvandeve/lodepng/lodepng.h"

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

raia_size_t _raia_image_load_init(char const *file_name, uint8_t *pixels);
raia_size_t _raia_image_load(char const *filename, uint8_t *pixels, raia_point_t pos, raia_size_t size);
raia_size_t _raia_image_load_jpg_blend_rgb(uint8_t *pixels, int width, int height,
                                           const char *filename,
                                           int pos_x, int pos_y,
                                           int trim_x1, int trim_y1, int trim_x2, int trim_y2);
raia_size_t _raia_image_load_jpg_blend_rgba(uint8_t *pixels, int width, int height,
                                            const char *filename,
                                            int pos_x, int pos_y,
                                            int trim_x1, int trim_y1, int trim_x2, int trim_y2);
raia_size_t _raia_image_load_png_blend_rgb(uint8_t *pixels, int width, int height,
                                           const char *filename,
                                           int pos_x, int pos_y,
                                           int trim_x1, int trim_y1, int trim_x2, int trim_y2);
raia_size_t _raia_image_load_png_blend_rgba(
        uint8_t *pixels, int width, int height,
        const char *filename,
        int pos_x, int pos_y,
        int trim_x1, int trim_y1, int trim_x2, int trim_y2);

#endif /* wrapper_stb_image_h */
