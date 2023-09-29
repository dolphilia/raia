//
//  raia_pixel_data.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "static_pixel_data.h"

static uint8_t* pixel_data;

// ピクセルデータ領域を初期化する
void init_pixel_data(int width, int height, int samples_per_pixel) {
    pixel_data = calloc(width * height * samples_per_pixel, sizeof(uint8_t)); // ピクセルデータ領域を確保する
    for (int i = 0; i < width * height * samples_per_pixel; i++) { // ピクセルデータ領域を白で塗りつぶす
        pixel_data[i] = 255;
    }
}

void free_pixel_data(void) {
    free(pixel_data);
}

uint8_t* get_pixel_data(void) {
    return pixel_data;
}
