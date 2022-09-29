//
//  raia_struct.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef static_header_h
#define static_header_h

#include <stdint.h>
#include "util/util_string.h"

// raia_header ヘッダー構造体
typedef struct raia_header_t {
    int32_t window_width; // ウィンドウの幅と高さ
    int32_t window_height;
    int32_t resolution_width; // 画面解像度の幅と高さ
    int32_t resolution_height;
    int32_t magnification; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    int32_t samples_per_pixel; // 3=RGBカラー, 4=RGBAカラー
    //uint8_t* pixel_data;
    char window_title[512]; // ウィンドウの初期状態のタイトル
} raia_header_t;

void init_raia_header(void);
raia_header_t get_raia_header(void);
void set_resolution_size(int width, int height);

#endif /* raia_struct_h */
