//
//  util_glfw.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "wrapper/wrapper_glfw.h"

/// GLFWの初期化
void glfw_init(void) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "GLFWの初期化に失敗しました\n");
        exit(EXIT_FAILURE);
    }
}

/// ウィンドウの生成
GLFWwindow* glfw_create_window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
    GLFWwindow* window = glfwCreateWindow(640, 480, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "ウィンドウの生成に失敗しました\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    return window;
}

