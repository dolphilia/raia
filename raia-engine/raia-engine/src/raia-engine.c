//
// macos:
// HomebrewでGLFWとOpenAL-Softを導入済みの場合:
// $ clang -o raia-engine.out src/raia-engine.c include/duktape/duktape.c -lm -lglfw -framework OpenGL -framework OpenAL -I /opt/homebrew/include -I include -L /opt/homebrew/opt/openal-soft/lib -L /opt/homebrew/opt/glfw/lib
//

#ifdef _WIN32
#define __WIN32__
#define __WINDOWS__
#endif

#ifdef _WIN64
#define __WIN64__
#define __WINDOWS__
#endif

#ifdef _WINDOWS
#define __WINGUI__
#endif

#ifdef _CONSOLE
#define __WINCUI__
#endif

#ifdef __APPLE__
#define __MACOS__
#endif

#ifdef __linux
#define __LINUX__
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "duktape/duktape.h"

#ifdef __MACOS__
#include <unistd.h>
#endif

#ifdef __WINDOWS__
#include <windows.h>
#endif

// raia_header ヘッダー構造体
typedef struct raia_header_t {
    int32_t window_width; // ウィンドウの幅と高さ
    int32_t window_height;
    int32_t resolution_width; // 画面解像度の幅と高さ
    int32_t resolution_height;
    int32_t magnification; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    int32_t samples_per_pixel; // 3=RGBカラー, 4=RGBAカラー
    GLFWwindow* glfw_window;
    uint8_t* pixel_data;
    char window_title[512]; // ウィンドウの初期状態のタイトル
} raia_header_t;

raia_header_t raia_header;


int rnd(int min, int max) {
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

uint32_t xor128(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

uint32_t random_ul_range(uint32_t min_value, uint32_t max_value) {
    return (xor128() % (max_value - min_value + 1) + min_value);
}

int32_t rand_xor128(int32_t min_value, int32_t max_value) {
    if (min_value < 0) {
        uint32_t ul = random_ul_range(0, (uint32_t)(max_value + (-1) * min_value));
        return (int)(ul) + min_value;
    } else {
        return random_ul_range((uint32_t)(min_value), (uint32_t)(max_value));
    }
}

void set_pixel_rgb(uint8_t *pixel_data,
    int32_t point_x, int32_t point_y,
    uint8_t color_red, uint8_t color_green, uint8_t color_blue,
    int32_t canvas_size_width, int32_t canvas_size_height, int32_t samples_per_pixel)
{
    if (point_x < 0 ||
        point_y < 0 ||
        point_x >= canvas_size_width ||
        point_y >= canvas_size_height)
    {
        return;
    }

    int index = (canvas_size_height - 1 - point_y) * canvas_size_width * samples_per_pixel + point_x * samples_per_pixel;
    pixel_data[index] = color_red;
    pixel_data[index + 1] = color_green;
    pixel_data[index + 2] = color_blue;
}

void set_array_from_str(char* array, char* src) {
    int i;
    for (i = 0; i < (int)strlen(src); i++) {
        array[i] = src[i];
    }
    array[i] = '\0';
}

// テキストファイルの読み込み
char* load_string_filename(const char* filename) {
    size_t file_index = 0;
    char* str = NULL;
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("ファイルの読み取りに失敗しました %s\n", filename); // ファイルの読み込みに失敗しました
        exit(EXIT_FAILURE);
    }
    fseek(file_ptr, 0, SEEK_END);
    const size_t initial_size = ftell(file_ptr);
    size_t buffer_size = initial_size + 4; // 初期バッファ
    str = (char*)malloc(buffer_size + 1);
    fseek(file_ptr, 0, SEEK_SET);
    for (;;) {
        const int c = fgetc(file_ptr);
        if (c == EOF) {
            break;
        }
        const char ch = (char)c;
        if (buffer_size <= file_index) {
            buffer_size *= 2;
            str = (char*)realloc(str, buffer_size);
        }
        str[file_index] = ch;
        file_index++;
    }
    str[file_index] = '\0';
    fclose(file_ptr);
    return str;
}

/// 文字列を結合する
char* str_join(const char* str1, const char* str2) {
    char* result = (char*)malloc((int)strlen(str1) + (int)strlen(str2));
    sprintf(result, "%s%s", str1, str2); // 文字列を結合する
    return result;
}

/// OpenALのテスト
void openal_sample(void) {
    ALCdevice* device;
    ALCcontext* context;
    ALshort data[44100 * 3];
    ALuint buffer, source;
    device = alcOpenDevice(NULL);
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);
    alGenBuffers(1, &buffer);
    for (int i = 0; i < 44100 * 3; i++)
        data[i] = rnd(-32767, 32767);
    alBufferData(buffer, AL_FORMAT_MONO16, data, sizeof(data), 44100);
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSourcePlay(source);
#ifdef __WINDOWS__
    Sleep(3000);
#else
    sleep(1);
#endif
    alSourceStop(source);
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
}

/// GLFWの初期化
void glfw_init(void) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "GLFWの初期化に失敗しました\n");
        exit(EXIT_FAILURE);
    }
}

/// ウィンドウの生成
GLFWwindow* glfw_create_window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
    GLFWwindow* window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ウィンドウの生成に失敗しました\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    return window;
}

/// 再描画する
void glfw_redraw(uint8_t* pixel_data) {
    // 描画の準備
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(-1, -1);
    
    int mag = raia_header.magnification; // mag = magnification = 倍率

#ifdef __MACOS__
    int now_width, now_height;
    glfwGetFramebufferSize(raia_header.glfw_window, &now_width, &now_height);
    if (now_width > raia_header.window_width) {
        mag = raia_header.magnification * 2;
    }
#endif
    // ピクセルを描画
    int mag_width = mag * raia_header.resolution_width;
    int mag_height = mag * raia_header.resolution_height;;
    uint8_t* mag_pixel_data = calloc(mag_width * mag_height * raia_header.samples_per_pixel * 4, sizeof(uint8_t));
    
    int i = 0;
    for (int y = 0; y < mag_height; y += mag) {
        for (int x = 0; x < mag_width * raia_header.samples_per_pixel; x += mag * raia_header.samples_per_pixel) {
            for (int m = 0; m < mag; m++) {
                for (int n = 0; n < mag; n++) {
                    for (int p = 0; p < raia_header.samples_per_pixel; p++) {
                        mag_pixel_data[x + (y + m) * mag_width * raia_header.samples_per_pixel + n * raia_header.samples_per_pixel + p] = pixel_data[i + p];
                    }
                }
            }
            i += raia_header.samples_per_pixel;
        }
    }
    
    glDrawPixels(mag_width, mag_height, GL_RGB, GL_UNSIGNED_BYTE, mag_pixel_data);
    free(mag_pixel_data);
    
    glfwSwapBuffers(raia_header.glfw_window);
}

/// ウィンドウを閉じるまでループ
void glfw_loop(void) {
    uint8_t pixel_data[raia_header.window_width * raia_header.window_height * raia_header.samples_per_pixel];
    while (!glfwWindowShouldClose(raia_header.glfw_window)) {
        for (int i = 0; i < raia_header.window_width * raia_header.window_height * raia_header.samples_per_pixel; i++) {
            pixel_data[i] = rnd(0, 250);
        }
        glfw_redraw(pixel_data);
        glfwPollEvents();
    }
}

/// GLFWのテスト
void glfw_sample(void) {
    glfw_init();
    raia_header.glfw_window = glfw_create_window(raia_header.window_width, raia_header.window_height, raia_header.window_title, NULL, NULL);
    glfwMakeContextCurrent(raia_header.glfw_window);
}

// duktape用print関数
duk_ret_t regist_print(duk_context *ctx) {
  printf("%s\n", duk_to_string(ctx, 0));
  return 0;  /* no return value (= undefined) */
}

// duktape用print関数
duk_ret_t regist_glfw_pool_events(duk_context *ctx) {
    glfwPollEvents();
    return 0;  /* no return value (= undefined) */
}

duk_ret_t regist_glfw_window_should_close(duk_context *ctx) {
    int ret = glfwWindowShouldClose(raia_header.glfw_window);
    duk_push_number(ctx, ret);
    return 1; /* one return value */
}

duk_ret_t regist_glfw_redraw(duk_context *ctx) {
    glfw_redraw(raia_header.pixel_data);
    return 0; /* no return value */
}

duk_ret_t regist_set_pixel(duk_context *ctx) {
    int n = duk_get_top(ctx);  /* #args */
    if (n < 2) {
        fprintf(stderr, "引数の数が足りません\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    int point_x = duk_to_number(ctx, 0);
    int point_y = duk_to_number(ctx, 1);
    set_pixel_rgb(raia_header.pixel_data, point_x, point_y, 0, 0, 0, raia_header.window_width, raia_header.window_height, raia_header.samples_per_pixel);
    return 0;
}

/// 関数を登録する
void regist_func(duk_context *ctx, duk_c_function func, const char *str, int nargs) {
    duk_push_c_function(ctx, func, nargs);
    duk_put_global_string(ctx, str);
}

/// 関数群を登録する
void regist_functions(duk_context *ctx) {
    regist_func(ctx, regist_print, "print", 1);
    regist_func(ctx, regist_glfw_pool_events, "glfw_pool_events", 0);
    regist_func(ctx, regist_glfw_window_should_close, "glfw_window_should_close", 0);
    regist_func(ctx, regist_glfw_redraw, "glfw_redraw", 0);
    regist_func(ctx, regist_set_pixel, "set_pixel", 2);
}

/// スクリプトファイルを読み込んでスタックにプッシュする
void load_script_filename(duk_context *ctx, const char* filename) {
    char* script = load_string_filename("startup.js"); //ファイルを読み込む
    duk_push_string(ctx, script);
    free(script);
}

/// Duktapeのテスト
void duktape_sample(void) {
    duk_context* ctx = duk_create_heap_default();
    regist_functions(ctx); // 関数群を登録する
    load_script_filename(ctx, "startup.js"); // スクリプトファイルを読み込んでスタックにプッシュする
    duk_eval(ctx); // 実行する
    duk_destroy_heap(ctx); // ヒープを削除する
}

void setup_raia_header(void) {
    set_array_from_str(raia_header.window_title, "Untitled"); // ウィンドウの初期状態のタイトル
    raia_header.window_width = 640; // ウィンドウの幅と高さ
    raia_header.window_height = 480;
    raia_header.resolution_width = 640; // 画面解像度の幅と高さ
    raia_header.resolution_height = 640;
    raia_header.magnification = 1; // 倍率 = WINDOW_WIDTH / SCREEN_WIDTH
    raia_header.samples_per_pixel = 3; // 3=RGBカラー, 4=RGBAカラー
    
    // ピクセルデータ領域を確保する
    raia_header.pixel_data = calloc(raia_header.window_width * raia_header.window_height * raia_header.samples_per_pixel, sizeof(uint8_t));
    
    // ピクセルデータ領域を白で塗りつぶす
    for (int i = 0; i < raia_header.window_width * raia_header.window_height * raia_header.samples_per_pixel; i++) {
        raia_header.pixel_data[i] = 255;
    }
}

int main(int argc, char* argv[]) {
    setup_raia_header();
    //openal_sample();
    glfw_sample();
    glfw_redraw(raia_header.pixel_data); // 画面を再描画する
    duktape_sample();
    glfwTerminate();
    free(raia_header.pixel_data);
    exit(EXIT_SUCCESS);
}
