//
//  util_glfw.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef wrapper_glfw_h
#define wrapper_glfw_h

#include <stdio.h>
#include <stdlib.h>
#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES
#include "GLFW/glfw3.h"
#include "EGL/egl.h"

void glfw_init(void);
GLFWwindow* glfw_create_window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);

#endif /* util_glfw_h */
