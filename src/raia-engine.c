//
// macos:
// HomebrewでGLFWとOpenAL-Softを導入済みの場合:
// $ clang -o raia-engine.out src/raia-engine.c include/duktape/duktape.c -lm -lglfw -framework OpenGL -framework OpenAL -I /opt/homebrew/include -I include -L /opt/homebrew/opt/openal-soft/lib -L /opt/homebrew/opt/glfw/lib
//

#include "raia-engine.h"

int main(int argc, char* argv[]) {
    init_raia_header(); // ヘッダー情報を初期化
    raia_header_t header = get_raia_header(); // ヘッダーを取得
    init_pixel_data(header.window_width, header.window_height, header.samples_per_pixel); // ピクセルデータを初期化
    //openal_start(); // OpenALを開始
    glfw_start(); // GLFWを開始
    glfw_redraw(); // 画面を再描画しておく
    duktape_start(); // Duktapeを開始
    glfwTerminate(); // GLFWを終了
    free_pixel_data(); // ピクセルデータを解放する
    exit(EXIT_SUCCESS);
}
