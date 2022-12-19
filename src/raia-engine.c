//
// raia-engine.c
//

#include "raia-engine.h"
#include "gamepad.h"

void callback(int type, int page, int usage, int value) {
    // 2 9 1 0 左ボタン離す
    // 2 9 1 1 左
    //     2 1 下
    //     3 1 右
    //     4 1 上
    //     5 1 L1
    //     6 1 R1
    //     7 1 L2
    //     8 1 R2
    //     9 1 左の小さいボタン
    //     10 1 右の小さいボタン（メニュー）
    //     11 1 左スティック押し込み
    //     12 1 右スティック押し込み
    //     13 1 PSボタン
    //     14 1 中央の大きいボタン
    //     15 1 ミュートボタン
    // 1 1 57 8 左カーソル離す
    // 1 1 57 0 上
    //        1 右上
    //        2 右
    //        3 右下
    //        4 下
    //        5 左下
    //        6 左
    //        7 左上
    // 1 1 49 左スティック
    // 1 1 50 右スティック
    // 1 1 48 傾き・加速度？
    // 1 1 53 傾き・加速度？
    // 1 1 65280 ?
    if (type == 1 && page != 65280 && usage!=48 && usage!=53)
        printf("type=%d, page=%d, usage=%d, value=%d\n", type, page, usage, value);
}

int main(int argc, char* argv[]) {
    /* initialize gamepad */
    void* ctx = gamepad_init(1, 1, 0);
    if (!ctx) {
        puts("init failed");
        return -1;
    }

    /* set callback */
    gamepad_set_callback(ctx, callback);
    
    init_raia_header(); // ヘッダー情報を初期化
    raia_header_t header = get_raia_header(); // ヘッダーを取得
    init_pixel_data(header.window_width, header.window_height, header.samples_per_pixel); // ピクセルデータを初期化
    //openal_start(); // OpenALを開始
    glfw_start(); // GLFWを開始
    init_raia_shader(get_pixel_data(), header.window_width, header.window_height);
    glfw_redraw(); // 画面を再描画しておく
    init_duk_ctx();
    duktape_start(); // Duktapeを開始
    glfwTerminate(); // GLFWを終了
    free_pixel_data(); // ピクセルデータを解放する
    exit(EXIT_SUCCESS);
}
