//
//  raia_windows.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "static_window.h"

static GLFWwindow* raia_window;

void init_raia_window(int width, int height, const char* title) {
    raia_window = glfw_create_window(width, height, title, NULL, NULL);
}

GLFWwindow* get_raia_window(void) {
    return raia_window;
}
