#include "raia_app.h"

#include <stdio.h>

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT duk_ret_t raia_app_glfw_init(duk_context *ctx) {
    duk_push_c_function(ctx, dukopen_glfw, 0);
    duk_call(ctx, 0);
    duk_put_global_string(ctx, "glfw");
}

RAIA_EXPORT duk_ret_t raia_app_event_error_callback(duk_context *ctx) {
    duk_dup(ctx, 0);
    duk_put_global_string(ctx, "_glfw_error_callback");
    set_context(ctx);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_event_key_callback(duk_context *ctx) {
    duk_dup(ctx, 0);
    duk_put_global_string(ctx, "_glfw_key_callback");
    set_context(ctx);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_event_update_callback(duk_context *ctx) {
    duk_dup(ctx, 0);
    duk_put_global_string(ctx, "_event_update_callback");
    set_exist_update_callback(true);
    set_context(ctx);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_event_cursor_position_callback(duk_context *ctx) {
    duk_dup(ctx, 0);
    duk_put_global_string(ctx, "_glfw_cursor_position_callback");
    set_context(ctx);
    return 0;
}

RAIA_EXPORT
duk_ret_t raia_app_event_mouse_button_callback(duk_context *ctx) {
    duk_dup(ctx, 0);
    duk_put_global_string(ctx, "_glfw_mouse_button_callback");
    set_context(ctx);
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_event_update_enable(duk_context *ctx) {
    raia_header_t header = get_raia_header();
    if (header.exist_update_callback == true) {
        glfw_loop();
    }
    return 0;
}

RAIA_EXPORT
duk_ret_t raia_app_screen_redraw(duk_context *ctx) {
    glfw_redraw();
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_window_poll_events(duk_context *ctx) {
    glfwPollEvents();
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_window_should_close(duk_context *ctx) {
    GLFWwindow *window = get_raia_window();
    duk_push_number(ctx, glfwWindowShouldClose(window));
    return 1;
}

RAIA_EXPORT duk_ret_t raia_app_window_init(duk_context *ctx) {
    int width = (int) duk_to_number(ctx, 1);
    int height = (int) duk_to_number(ctx, 2);
    const char *title = duk_to_string(ctx, 3);

    //
    // ctx ->
    //
    // ctx.text = 100;
    //
    //duk_to_object(ctx, 0);
    //duk_push_string(ctx, "100");
    //duk_put_prop_string(ctx, 0, "test");

    //
    // ctx.app = {
    //    foo: "bar"
    // }
    //
    //duk_to_object(ctx, 0);
    //duk_idx_t obj_idx = duk_push_object(ctx);
    //duk_push_string(ctx, "bar");
    //duk_put_prop_string(ctx, obj_idx, "foo");
    //duk_put_prop_string(ctx, 0, "app");

    //
    // ctx.app = {
    //    window: {
    //        width: <width>,
    //        height: <height>,
    //        title: <title>
    //    }
    // }
    duk_to_object(ctx, 0);
    duk_idx_t obj_idx2 = duk_push_object(ctx);
    duk_idx_t obj_idx = duk_push_object(ctx);
    duk_push_number(ctx, width);
    duk_put_prop_string(ctx, obj_idx, "width");
    duk_push_number(ctx, height);
    duk_put_prop_string(ctx, obj_idx, "height");
    duk_push_string(ctx, title);
    duk_put_prop_string(ctx, obj_idx, "title");
    duk_put_prop_string(ctx, obj_idx2, "window");
    duk_put_prop_string(ctx, 0, "app");
    duk_pop(ctx);

    init_raia_header(); // ヘッダー情報を初期化
    set_window_size(width, height);
    set_resolution_size(width, height);
    set_title(title);

    raia_header_t header = get_raia_header(); // ヘッダーを取得
    init_pixel_data(header.window_width, header.window_height, header.samples_per_pixel); // ピクセルデータを初期化
    glfw_start(); // GLFWを開始
    regist_callbacks(ctx); // コールバック群を登録する
    init_raia_shader(get_pixel_data(), header.window_width, header.window_height);
    glfw_redraw(); // 画面を再描画しておく
    return 0;
}

RAIA_EXPORT duk_ret_t raia_app_window_set_title(duk_context *ctx) {
    const char *title = duk_to_string(ctx, 1);
    GLFWwindow *window = get_raia_window();
    glfwSetWindowTitle(window, title);
    set_title(title);

    duk_to_object(ctx, 0);

    duk_push_string(ctx, "app");
    duk_get_prop(ctx, 0);
    duk_push_string(ctx, "window");
    duk_get_prop(ctx, -2);
    duk_push_string(ctx, title);
    duk_put_prop_string(ctx, -2, "title");
    duk_pop(ctx);

    return 0;
}

void regist_callbacks(duk_context *ctx) {
    glfwSetKeyCallback(get_raia_window(), event_key_callback); // キー入力コールバック
    glfwSetErrorCallback(event_error_callback); // エラーコールバック
    glfwSetCursorPosCallback(get_raia_window(), event_cursor_position_callback); // マウス移動
    glfwSetMouseButtonCallback(get_raia_window(), event_mouse_button_callback); // マウスボタン
}

void wait_time_with_fps(double now, double prev, int fps) {
    while (!glfwWindowShouldClose(get_raia_window())) { // ほぼ 60fps になるように待つ
        now = (double) clock() / CLOCKS_PER_SEC;
        if ((now - prev) > 1.0 / (double) fps) {
            break;
        }
        glfwPollEvents();
    }
}

void glfw_loop(void) {
    double now = (double) clock() / CLOCKS_PER_SEC;
    double prev = (double) clock() / CLOCKS_PER_SEC;
    while (!glfwWindowShouldClose(get_raia_window())) {
        now = (double) clock() / CLOCKS_PER_SEC;
        event_update_callback();
        glfw_redraw();
        prev = now;
        wait_time_with_fps(now, prev, 60);
        glfwPollEvents();
    }
}

void glfw_start(void) {
    glfw_init();
    raia_header_t header = get_raia_header();
    init_raia_window(header.window_width, header.window_height, header.window_title);
    GLFWwindow *glfw_window = get_raia_window();
    glfwMakeContextCurrent(glfw_window);
    glfwSwapInterval(1);

    // HiDPI
    int now_width, now_height;
    glfwGetFramebufferSize(glfw_window, &now_width, &now_height);
    if (now_width > header.window_width) {
        set_resolution_size(header.window_width * 2, header.window_height * 2);
    } else {
        set_resolution_size(header.window_width, header.window_height);
    }
}

void glfw_redraw(void) {
    raia_header_t header = get_raia_header();
    raia_shader_t shader = get_raia_shader();
    GLFWwindow *glfw_window = get_raia_window();
    uint8_t *pixel_data = get_pixel_data();
    glViewport(0, 0, header.resolution_width, header.resolution_height); // Set the viewport
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glUseProgram(shader.program); // Use the program object
    glVertexAttribPointer(shader.pos_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                          shader.vertices); // Load the vertex position
    glVertexAttribPointer(shader.tex_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                          shader.vertices + 3); // Load the texture coordinate
    glEnableVertexAttribArray(shader.pos_location);
    glEnableVertexAttribArray(shader.tex_location);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, header.window_width, header.window_height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                 pixel_data);
    glActiveTexture(GL_TEXTURE0); // Bind the texture
    glBindTexture(GL_TEXTURE_2D, shader.texture);
    glUniform1i(shader.sampler_location, 0); // Set the texture sampler to texture unit to 0
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, shader.indices);
    glfwSwapBuffers(glfw_window);
}

void init(void) {
}