//
//  raia_struct.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef static_header_h
#define static_header_h

#include <stdint.h>
#include "../util/util_string.h"

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} _color_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} _point_t;

// raia_header ヘッダー構造体
typedef struct raia_header_t {
    int32_t window_width; // ウィンドウの幅と高さ
    int32_t window_height;
    int32_t resolution_width; // 画面解像度の幅と高さ
    int32_t resolution_height;
    int32_t magnification; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    int32_t samples_per_pixel; // 3=RGBカラー, 4=RGBAカラー
    _color_t current_color; // 現在のカラーRGBA
    _point_t current_point; // 現在のポイントX,Y
    bool exist_update_callback;
    char window_title[512]; // ウィンドウの初期状態のタイトル
} raia_header_t;

void init_raia_header(void);
raia_header_t get_raia_header(void);
void set_window_size(int width, int height);
void set_resolution_size(int width, int height);
void set_title(char* title);
void set_current_color(int r, int g, int b);
void set_current_point(int x, int y);
void set_exist_update_callback(bool is_exist);

#endif /* raia_struct_h */
