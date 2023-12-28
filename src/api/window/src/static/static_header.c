//
//  raia_struct.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "static_header.h"

static raia_header_t raia_header;

void init_raia_header(void) {
    set_array_from_str(raia_header.window_title, "Untitled"); // ウィンドウの初期状態のタイトル
    raia_header.window_width = 640; // ウィンドウの幅と高さ
    raia_header.window_height = 480;
    raia_header.resolution_width = 640; // 画面解像度の幅と高さ
    raia_header.resolution_height = 480;
    raia_header.magnification = 1; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    raia_header.samples_per_pixel = 3; // 3=RGBカラー, 4=RGBAカラー
    raia_header.current_color.red = 0;
    raia_header.current_color.green = 0;
    raia_header.current_color.blue = 0;
    raia_header.current_point.x = 0;
    raia_header.current_point.y = 0;
    raia_header.exist_update_callback = false;
}

raia_header_t get_raia_header(void) {
    return raia_header;
}

void set_window_size(int width, int height) {
    raia_header.window_width = width; // 画面解像度の幅と高さ
    raia_header.window_height = height;
}

void set_resolution_size(int width, int height) {
    raia_header.resolution_width = width; // 画面解像度の幅と高さ
    raia_header.resolution_height = height;
}

void set_title(char* title) {
    set_array_from_str(raia_header.window_title, title);
}

void set_current_color(int r, int g, int b) {
    raia_header.current_color.red = r;
    raia_header.current_color.green = g;
    raia_header.current_color.blue = b;
}

void set_current_point(int x, int y) {
    raia_header.current_point.x = x;
    raia_header.current_point.y = y;
}

void set_exist_update_callback(bool is_exist) {
    raia_header.exist_update_callback = is_exist;
}
