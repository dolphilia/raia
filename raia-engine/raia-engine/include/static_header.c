//
//  raia_struct.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include <static_header.h>

static raia_header_t raia_header;

void init_raia_header(void) {
    set_array_from_str(raia_header.window_title, "Untitled"); // ウィンドウの初期状態のタイトル
    raia_header.window_width = 640; // ウィンドウの幅と高さ
    raia_header.window_height = 480;
    raia_header.resolution_width = 640; // 画面解像度の幅と高さ
    raia_header.resolution_height = 480;
    raia_header.magnification = 1; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    raia_header.samples_per_pixel = 3; // 3=RGBカラー, 4=RGBAカラー
}

raia_header_t get_raia_header(void) {
    return raia_header;
}
