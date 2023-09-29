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
#include "../stb/stb_image.h"
#include "../stb/stb_image_write.h"
#include "../util/util_pixel.h"
#include "../lodepng/lodepng.h"

raia_size_t load_image_init_canvas(char const *file_name, uint8_t *pixels);
raia_size_t load_image(char const *file_name, uint8_t *pixel_data, raia_point_t point, raia_size_t canvas);
void load_and_blend_image_rgba(
        uint8_t *pixels_rgba, int pixels_rgba_width, int pixels_rgba_height,
        const char *filename,
        int position_x, int position_y,
        int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2);
void load_and_blend_image_rgb(
        uint8_t *pixels_rgba, int pixels_rgba_width, int pixels_rgba_height,
        const char *filename,
        int position_x, int position_y,
        int trimming_x1, int trimming_y1, int trimming_x2, int trimming_y2);

#endif /* wrapper_stb_image_h */
