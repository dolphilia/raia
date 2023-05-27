//
// Created by dolphilia on 2022/12/10.
//

#include "static_plugin_loader.h"

static list_t *lib_list;
static list_t *func_list;
static int lib_list_count;
static int lib_list_index;

void init_plugin_loader(void) {
    lib_list = list_new();
    func_list = list_new();
    lib_list_count = -1;
    lib_list_index = lib_list_count;
}

void open_plugin(const char *dll_file) {
#ifdef __LINUX__
    char path[500];
    sprintf(path, "./%s\0", dll_file);
    void * handle = raia_dlopen(path);
#else
    void *handle = raia_dlopen(dll_file);
#endif
    list_node_t *plugin_list_node = list_node_new(handle);
    list_rpush(lib_list, plugin_list_node);
    lib_list_count++;
    lib_list_index = lib_list_count;
}

void close_plugin(void) {
    raia_handle_t handle = list_at(lib_list, lib_list_index)->val;
    raia_dlclose(handle);
    lib_list_count--;
    lib_list_index = lib_list_count;
}

void close_all_plugin(void) {
    list_node_t *node;
    list_iterator_t *it = list_iterator_new(lib_list, LIST_HEAD);
    while ((node = list_iterator_next(it))) {
        raia_dlclose(node->val);
    }
}

void *get_plugin_handle(void) {
    return list_at(lib_list, lib_list_index)->val;
}

//duk_ret_t (*add_plugin_func(duk_context *ctx, const char *dll_func_name))(duk_context *ctx) {
//    raia_handle_t handle = list_at(lib_list, lib_list_index)->val;
//    duk_ret_t (*p_func)(duk_context *ctx) = (duk_ret_t (*)(duk_context *))raia_dlsym(handle, dll_func_name);
//    list_node_t *func_list_node = list_node_new(p_func);
//    list_rpush(func_list, func_list_node);
//    return p_func;
//}
//
//void (*add_plugin_init(const char *dll_func_name))(void) {
//    raia_handle_t handle = list_at(lib_list, lib_list_index)->val;
//    void (*p_func)(void) = (void (*)(void))raia_dlsym(handle, dll_func_name);
//    return p_func;
//}