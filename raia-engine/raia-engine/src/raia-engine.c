//
// macos:
// clang glfw-template.c -o glfw-template -lglfw -framework OpenGL -I /opt/homebrew/include -L /opt/homebrew/lib
// clang -std=c99 -oduktape-one-dot duktape-one-dot.c duktape.c -lm
//

#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#endif
#include <GLFW/glfw3.h>
#include "duktape/duktape.h"

int main(int argc, char* argv[]) {
    duk_context* ctx = duk_create_heap_default();
    duk_eval_string(ctx, "1+2");
    printf("1+2=%d\n", (int)duk_get_int(ctx, -1));
    duk_destroy_heap(ctx);


    GLFWwindow* window;

    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return EXIT_FAILURE;
    }

    // この記述があるとmacosでウィンドウ生成に失敗する
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create window.\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}