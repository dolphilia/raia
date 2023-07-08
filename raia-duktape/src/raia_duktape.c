#include "raia_duktape.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#endif

static duk_ret_t raia_core_print(duk_context *ctx) {
    int ret = puts(duk_to_string(ctx, 0));
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t raia_core_exit(duk_context *ctx) {
    int status = duk_to_int(ctx, 0);
    exit(status);
    return 0;
}

// entrust
static duk_ret_t raia_core_entrust(duk_context *ctx) {
    char *script = (char *)duk_to_string(ctx, 0);
    set_entrust_script(script);
    set_is_entrust(true);
    return 0;
}

// run
static duk_ret_t raia_core_is_pointer(duk_context *ctx) {
    duk_push_boolean(ctx, duk_is_pointer(ctx, 0));
    return 1;
}

static duk_ret_t raia_core_is_buffer(duk_context *ctx) {
    duk_push_boolean(ctx, duk_is_buffer(ctx, 0));
    return 1;
}

static duk_ret_t raia_core_pointer_to_number(duk_context *ctx) {
    duk_push_number(ctx, (double)(uintptr_t)duk_to_pointer(ctx, 0));
    return 1;
}

static duk_ret_t raia_core_number_to_pointer(duk_context *ctx) {
    duk_push_pointer(ctx, (void *)(uintptr_t)duk_to_number(ctx, 0));
    return 1;
}

static duk_ret_t raia_core_array_buffer_to_pointer(duk_context *ctx) {
    size_t size;
    duk_push_pointer(ctx, duk_to_buffer(ctx, 0, &size));
    return 1;
}

static duk_ret_t raia_core_array_buffer_to_number(duk_context *ctx) {
    size_t size;
    duk_push_number(ctx, (double)(uintptr_t)duk_to_buffer(ctx, 0, &size));
    return 1;
}

// lib
static duk_ret_t raia_lib_open(duk_context *ctx) {
    const char *dll_file = duk_to_string(ctx, 0);
#ifdef __WINDOWS__
    const char *extension = "dll";
#endif
#ifdef __MACOS__
    const char *extension = "dylib";
#endif
#ifdef __LINUX__
    const char *extension = "so";
#endif
    char dll_file_extension[500];
    SPRINTF(dll_file_extension, "%s.%s", dll_file, extension);
    void *handle = add_plugin_hash(dll_file_extension);
    duk_push_pointer(ctx, handle);
    return 1;
}

static duk_ret_t raia_lib_close(duk_context *ctx) {
    const char *name = duk_to_string(ctx, 0);
    delete_plugin_hash(name);
    return 0;
}

static duk_ret_t raia_lib_close_all(duk_context *ctx) {
    free_plugin_hash();
    return 0;
}

static duk_ret_t raia_lib_add(duk_context *ctx) { // func_hash
    void *handle = duk_to_pointer(ctx, 0);
    const char *dll_func_name = duk_to_string(ctx, 1);
    add_plugin_func_hash(handle, dll_func_name);
    return 0;
}

static duk_ret_t raia_lib_call(duk_context *ctx) { // func_hash
    const char *dll_func_name = duk_to_string(ctx, 0);
    char *src; //json string
    if (duk_is_string(ctx, 1)) {
        src = (char *)duk_require_string(ctx, 1);
    } else {
        src = NULL;
    }

    if (src != NULL) {
        joint_t *joint = joint_init_in_with_str(src);
        if (joint_in_exist(joint, "@return")) {
            const char *return_type = joint_get_in_str(joint, "@return");
            joint_free(joint);
            if (strcmp(return_type, "pointer") == 0 && return_type != NULL) {
                const char *dest = call_func_hash(dll_func_name, src);
                duk_push_pointer(ctx, (void *)dest);
                return 1;
            }
        } else {
            joint_free(joint);
        }
    }

    const char *dest = call_func_hash(dll_func_name, src);
    duk_push_string(ctx, dest);
    if(dest != NULL) {
        free((void *)dest);
    }
    return 1;
}

static void register_function(duk_context *ctx, const char *name, duk_c_function func, int nargs) {
    duk_push_c_function(ctx, func, nargs);
    duk_put_prop_string(ctx, -2, name);
}

static void register_int(duk_context *ctx, const char *name, duk_int_t val) {
    duk_push_int(ctx, val);
    duk_put_prop_string(ctx, -2, name);
}

static void register_boolean(duk_context *ctx, const char *name, duk_bool_t val) {
    duk_push_boolean(ctx, val);
    duk_put_prop_string(ctx, -2, name);
}

static void register_string(duk_context *ctx, const char *name, const char *str) {
    duk_push_string(ctx, str);
    duk_put_prop_string(ctx, -2, name);
}

static raia_config_t raia_load_config(const char *json_file_name) {
    joint_t *joint = joint_init_in_with_file(json_file_name);

    raia_config_t config;
    config.debug_mode = joint_get_in_bool(joint, "debug_mode");
    config.typescript_mode = joint_get_in_bool(joint, "typescript_mode");
    config.es2015_mode = joint_get_in_bool(joint, "es2015_mode");
    config.preprocess = joint_get_in_bool(joint, "preprocess");

    const char *startup_script = joint_get_in_str(joint, "startup_script");
    STRNCPY(config.startup_script, startup_script, sizeof(config.startup_script) - 1);
    config.startup_script[sizeof(config.startup_script) - 1] = '\0';

    const char *preprocess_script = joint_get_in_str(joint, "preprocess_script");
    STRNCPY(config.preprocess_script, preprocess_script, sizeof(config.preprocess_script) - 1);
    config.preprocess_script[sizeof(config.preprocess_script) - 1] = '\0';

    joint_free(joint);
    return config;
}

static raia_config_t raia_set_functions(duk_context *ctx) {
    raia_config_t config = raia_load_config("raia_config.json");

    duk_idx_t raia_idx = duk_push_object(ctx);
    duk_idx_t core_idx = duk_push_object(ctx);

    duk_idx_t lib_idx = duk_push_object(ctx);
    register_function(ctx, "open", raia_lib_open, 1);
    register_function(ctx, "close", raia_lib_close, 1);
    register_function(ctx, "closeAll", raia_lib_close_all, 0);
    register_function(ctx, "add", raia_lib_add, 2);
    register_function(ctx, "call", raia_lib_call, 2);
    duk_put_prop_string(ctx, core_idx, "Lib");

    register_function(ctx, "print", raia_core_print, 1);
    register_function(ctx, "exit", raia_core_exit, 1);
    register_function(ctx, "entrust", raia_core_entrust, 1);
    register_function(ctx, "isPointer", raia_core_is_pointer, 1);
    register_function(ctx, "isBuffer", raia_core_is_buffer, 1);
    register_function(ctx, "pointerToNumber", raia_core_pointer_to_number, 1);
    register_function(ctx, "numberToPointer", raia_core_number_to_pointer, 1);
    register_function(ctx, "arrayBufferToPointer", raia_core_array_buffer_to_pointer, 1);
    register_function(ctx, "arrayBufferToNumber", raia_core_array_buffer_to_number, 1);
    duk_put_prop_string(ctx, raia_idx, "Core");

    register_boolean(ctx, "debug_mode", config.debug_mode);
    register_boolean(ctx, "typescript_mode", config.typescript_mode);
    register_boolean(ctx, "es2015_mode", config.es2015_mode);
    register_boolean(ctx, "preprocess", config.preprocess);
    register_string(ctx, "startup_script", config.startup_script);
    register_string(ctx, "preprocess_script", config.preprocess_script);

    duk_put_global_string(ctx, "__Raia__");
    return config;
}

// init
RAIA_EXPORT char *init(int argc, char *argv[]) {
    init_entrust();
    init_plugin_hash();
    init_func_hash();
    duk_context *ctx = duk_create_heap_default();
    duk_module_duktape_init(ctx);
    raia_config_t config = raia_set_functions(ctx);
    if (config.preprocess == 1) {
        char *preprocess_script = file_load_string(config.preprocess_script);
        duk_eval_string(ctx, preprocess_script);
    }
    char *startup_script = file_load_string(config.startup_script); //ファイルを読み込む
    duk_eval_string(ctx, startup_script);
    duk_destroy_heap(ctx);

    // {
    //     "script": "xxx.xx"
    //     "entrust": "true" or false
    // }
    if (get_is_entrust()) {
        joint_t *joint = joint_init_out();
        joint_add_out_str(joint, "script", (const char *)get_entrust_script());
        joint_add_out_bool(joint, "entrust", true);
        char *result = (char *)joint_out_write(joint);
        free_entrust();
        return result;
    }
    return NULL;
}