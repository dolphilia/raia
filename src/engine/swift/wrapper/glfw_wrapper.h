#ifndef CFUNC_H
#define CFUNC_H

#include "raia_glfw.h"

typedef struct GLFWwindow GLFWwindow;
typedef void (*WrapDropFunType)(GLFWwindow*, int, const char*[]);

WrapDropFunType wrap_raia_glfw_set_drop_callback(
    GLFWwindow* window, 
    WrapDropFunType cb
);

#endif /* CFUNC_H */
