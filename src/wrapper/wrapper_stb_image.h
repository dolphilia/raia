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
#include "stb/stb_image.h"
#include "stb/stb_image_write.h"

typedef struct{
    int32_t width;
    int32_t height;
} frame_t;

frame_t load_image_init_canvas(char const *file_name, uint8_t *pixel_data);
frame_t load_image(char const *file_ename, uint8_t *pixel_data, int32_t point_x, int32_t point_y, int32_t canvas_size_width, int32_t canvas_size_height);

#endif /* wrapper_stb_image_h */
