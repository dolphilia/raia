//
//  raia_duktape.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "raia/raia_duktape.h"

// 登録用のprint関数
duk_ret_t regist_print(duk_context *ctx) {
    printf("%s\n", duk_to_string(ctx, 0));
    return 0;  /* no return value (= undefined) */
}

// 登録用のglfw_pool_events関数（イベント待ち）
duk_ret_t regist_glfw_pool_events(duk_context *ctx) {
    glfwPollEvents();
    return 0;  /* no return value (= undefined) */
}

// 登録用のglfw_window_should_close関数（終了判定）
duk_ret_t regist_glfw_window_should_close(duk_context *ctx) {
    GLFWwindow* glfw_window = get_raia_window();
    int ret = glfwWindowShouldClose(glfw_window);
    duk_push_number(ctx, ret);
    return 1; /* one return value */
}

// 登録用のglfw_redraw（再描画）
duk_ret_t regist_glfw_redraw(duk_context *ctx) {
    glfw_redraw();
    return 0; /* no return value */
}

// 登録用のset_pixel（ドットを描画する）
duk_ret_t regist_set_pixel_rgb(duk_context *ctx) {
    int n = duk_get_top(ctx);  /* #args */
    if (n < 5) {
        fprintf(stderr, "引数の数が足りません\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    int point_x = (int)duk_to_number(ctx, 0);
    int point_y = (int)duk_to_number(ctx, 1);
    int color_r = (int)duk_to_number(ctx, 2);
    int color_g = (int)duk_to_number(ctx, 3);
    int color_b = (int)duk_to_number(ctx, 4);
    uint8_t* pixel_data = get_pixel_data();
    raia_header_t header = get_raia_header();
    set_pixel_rgb(pixel_data, point_x, point_y, color_r, color_g, color_b, header.window_width, header.window_height, header.samples_per_pixel);
    return 0;
}

// 登録用のfill_rect_rgb（ドットを描画する）
duk_ret_t regist_fill_rect_rgb(duk_context *ctx) {
    int n = duk_get_top(ctx);  /* #args */
    if (n < 7) {
        fprintf(stderr, "引数の数が足りません\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    int start_point_x = (int)duk_to_number(ctx, 0);
    int start_point_y = (int)duk_to_number(ctx, 1);
    int end_point_x = (int)duk_to_number(ctx, 2);
    int end_point_y = (int)duk_to_number(ctx, 3);
    int color_r = (int)duk_to_number(ctx, 4);
    int color_g = (int)duk_to_number(ctx, 5);
    int color_b = (int)duk_to_number(ctx, 6);
    uint8_t* pixel_data = get_pixel_data();
    raia_header_t header = get_raia_header();
    fill_rect_rgb(pixel_data, start_point_x, start_point_y, end_point_x, end_point_y, color_r, color_g, color_b, header.window_width, header.window_height, header.samples_per_pixel);
    return 0;
}

duk_ret_t regist_set_title(duk_context *ctx) {
    GLFWwindow* window = get_raia_window();
    glfwSetWindowTitle(window, duk_to_string(ctx, 0));
    return 0;  /* no return value (= undefined) */
}

/// 関数群を登録する
void regist_functions(duk_context *ctx) {
    regist_func(ctx, regist_print, "print", 1);
    regist_func(ctx, regist_glfw_pool_events, "glfw_pool_events", 0);
    regist_func(ctx, regist_glfw_window_should_close, "glfw_window_should_close", 0);
    regist_func(ctx, regist_glfw_redraw, "glfw_redraw", 0);
    regist_func(ctx, regist_set_pixel_rgb, "set_pixel_rgb", 5);
    regist_func(ctx, regist_fill_rect_rgb, "fill_rect_rgb", 7);
    regist_func(ctx, regist_set_title, "set_title", 1);
}

/// Duktapeの開始
void duktape_start(void) {
    duk_context* ctx = duk_create_heap_default();
    regist_functions(ctx); // 関数群を登録する
    duk_eval_string(ctx, "device = 'desktop';");
#ifdef __WINDOWS__
    duk_eval_string(ctx, "platform = 'windows';");
#endif
#ifdef __MACOS__
    duk_eval_string(ctx, "platform = 'macos';");
#endif
    load_script_filename(ctx, "startup.js"); // スクリプトファイルを読み込んでスタックにプッシュする

    duk_eval(ctx); // 実行する
    
    duk_eval_string(ctx, "if(typeof update == 'function'){1;}else{0;}");
    int is_exist_update_func = (int)duk_get_int(ctx, -1);
    if (is_exist_update_func == 1) {
        //printf("update関数は存在する\n");
        double now = (double)clock() / CLOCKS_PER_SEC;
        double prev = (double)clock() / CLOCKS_PER_SEC;
        while(!glfwWindowShouldClose(get_raia_window())) {
            now = (double)clock() / CLOCKS_PER_SEC;
            //printf("%f\n", 1.0 / (now - prev));
            duk_eval_string(ctx, "update();");
            prev = now;
            // ほぼ 60fps になるように待つ
            while(!glfwWindowShouldClose(get_raia_window())) {
                now = (double)clock() / CLOCKS_PER_SEC;
                if ((now - prev) > 0.016667) {
                    break;
                }
                glfwPollEvents();
            }
            glfwPollEvents();
        }
    } else {
        // printf("update関数は存在しない\n");
    }
    duk_destroy_heap(ctx); // ヒープを削除する
}
