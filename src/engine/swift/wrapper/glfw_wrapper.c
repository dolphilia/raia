#include "glfw_wrapper.h"

WrapDropFunType wrap_raia_glfw_set_drop_callback(GLFWwindow* window, WrapDropFunType cb) {
    return raia_glfw_set_drop_callback(window, cb);
}