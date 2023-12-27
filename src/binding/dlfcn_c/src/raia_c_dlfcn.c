#include "raia_c_dlfcn.h"

RAIA_API const char *raia_dlfcn_dlopen(const char *args) {
    joint_t *joint = joint_init_with_str(args);
    const char *path = joint_get_in_str(joint, "path");
    raia_dl_handle_t handle = raia_dlopen(path);
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)handle);
    return joint_out_write(joint);
}

RAIA_API const char *raia_dlfcn_dlclose(const char *args) {
    joint_t *joint = joint_init_with_str(args);
    raia_dl_handle_t handle = (raia_dl_handle_t)(uintptr_t)joint_get_in_uint_to_ptr(joint, "handle");
    int result = raia_dlclose(handle);
    joint_add_out_int(joint, "result", result);
    return joint_out_write(joint);
}

RAIA_API const char *raia_dlfcn_dlsym(const char *args) {
    joint_t *joint = joint_init_with_str(args);
    raia_dl_handle_t handle = (raia_dl_handle_t)(uintptr_t)joint_get_in_uint_to_ptr(joint, "handle");
    const char *symbol = joint_get_in_str(joint, "symbol");
    void *result = raia_dlsym(handle, symbol);
    joint_add_out_uint(joint, "result", (uint64_t)(uintptr_t)result);
    return joint_out_write(joint);
}

//void test() {
//    raia_dlfcn_dlopen("");
//    raia_dlfcn_dlclose("");
//    raia_dlfcn_dlsym("");
//}