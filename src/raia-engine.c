//
// raia-engine.c
//

#include "raia-engine.h"

int main(int argc, char* argv[]) {
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
