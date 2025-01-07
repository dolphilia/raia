#include "raia_gui.h"

int main(int argc, char* argv[]) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Initialization of GLFW failed.\n");
        exit(EXIT_FAILURE);
    }
    constexpr int width = 800;
    constexpr int height = 600;
    const auto title = "RaiaEngine";
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        fprintf(stderr, "Window creation failed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
