#include "wrapper.h"

WrapDropFunType wrap_raia_glfw_set_drop_callback(
    GLFWwindow* window, 
    WrapDropFunType cb
) {
    // 中で本物の raia_glfw_set_drop_callback を呼ぶだけ
    return raia_glfw_set_drop_callback(window, cb);
}