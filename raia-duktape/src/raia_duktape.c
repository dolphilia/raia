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

//static duk_ret_t raia_core_entrust(duk_context *ctx) {
//    const char *json_string = duk_to_string(ctx, 0);
//    //duk_s
//}

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
    open_plugin(dll_file_extension);
    return 0;
}

static duk_ret_t raia_lib_close(duk_context *ctx) {
    close_plugin();
    return 0;
}

static duk_ret_t raia_lib_close_all(duk_context *ctx) {
    close_all_plugin();
    return 0;
}

static duk_ret_t raia_lib_func(duk_context *ctx) {
    const char *dll_func_name = duk_to_string(ctx, 0);
    int nargs = (int) duk_to_number(ctx, 1);
    duk_ret_t (*p_func)(duk_context *ctx) = add_plugin_func(ctx, dll_func_name);
    duk_push_c_function(ctx, p_func, nargs);
    return 1;
}

static duk_ret_t raia_lib_add(duk_context *ctx) { // func_hash
    const char *dll_func_name = duk_to_string(ctx, 0);
    add_plugin_func_hash(dll_func_name);
    return 0;
}

static duk_ret_t raia_lib_call(duk_context *ctx) { // func_hash
    const char *dll_func_name = duk_to_string(ctx, 0);
    char *src; //json string
    void *data;
    duk_size_t size;
    if (duk_is_string(ctx, 1)) {
        src = (char *)duk_require_string(ctx, 1);
    } else {
        src = NULL;
    }
    if (duk_is_buffer(ctx, 2)) {
        data = (void *)duk_require_buffer_data(ctx, 2, &size);
    } else if(duk_is_pointer(ctx, 2)) {
        data = (void *)duk_require_pointer(ctx, 2);
    } else {
        data = NULL;
        size = 0;
    }
    if (duk_is_number(ctx, 3)) {
        size = (duk_size_t)duk_require_number(ctx, 3);
    }

    if (src != NULL) {
        yyjson_doc *arg_doc = yyjson_read(src, strlen(src), 0);
        yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
        yyjson_val *arg_val = yyjson_obj_get(arg_root, "@return");
        const char *return_type = yyjson_get_str(arg_val);
        if (strcmp(return_type, "pointer") == 0 && return_type != NULL) {
            void *dest = call_func_hash(dll_func_name, src, data, (int)size);
            duk_push_pointer(ctx, dest);
            yyjson_doc_free(arg_doc);
            return 1;
        }
        yyjson_doc_free(arg_doc);
    }

    char *dest = (char *)call_func_hash(dll_func_name, src, data, (int)size);
    duk_push_string(ctx, dest);
    if(dest != NULL) {
        free(dest);
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

typedef struct {
    int debug_mode;
    int typescript_mode;
    int es2015_mode;
    char startup_script[512];
    int preprocess;
    char preprocess_script[512];
} raia_config_t;

static raia_config_t raia_load_config(const char *json_file_name) {
    yyjson_doc *doc = yyjson_read_file(json_file_name, 0, NULL, NULL);
    yyjson_val *root = yyjson_doc_get_root(doc);

    raia_config_t config;
    config.debug_mode = yyjson_get_bool(yyjson_obj_get(root, "debug_mode"));
    config.typescript_mode = yyjson_get_bool(yyjson_obj_get(root, "typescript_mode"));
    config.es2015_mode = yyjson_get_bool(yyjson_obj_get(root, "es2015_mode"));
    config.preprocess = yyjson_get_bool(yyjson_obj_get(root, "preprocess"));

    const char *startup_script = yyjson_get_str(yyjson_obj_get(root, "startup_script"));
    STRNCPY(config.startup_script, startup_script, sizeof(config.startup_script) - 1);
    config.startup_script[sizeof(config.startup_script) - 1] = '\0';

    const char *preprocess_script = yyjson_get_str(yyjson_obj_get(root, "preprocess_script"));
    STRNCPY(config.preprocess_script, preprocess_script, sizeof(config.preprocess_script) - 1);
    config.preprocess_script[sizeof(config.preprocess_script) - 1] = '\0';

    yyjson_doc_free(doc);
    return config;
}

static raia_config_t raia_set_functions(duk_context *ctx) {
    raia_config_t config = raia_load_config("raia_config.json");

    duk_idx_t raia_idx = duk_push_object(ctx);
    duk_idx_t core_idx = duk_push_object(ctx);

    duk_idx_t lib_idx = duk_push_object(ctx);
    register_function(ctx, "open", raia_lib_open, 1);
    register_function(ctx, "close", raia_lib_close, 0);
    register_function(ctx, "closeAll", raia_lib_close_all, 0);
    register_function(ctx, "func", raia_lib_func, 2);
    // func_hash
    register_function(ctx, "add", raia_lib_add, 1);
    register_function(ctx, "call", raia_lib_call, 4);

    duk_put_prop_string(ctx, core_idx, "Lib");

    register_function(ctx, "print", raia_core_print, 1);
    register_function(ctx, "exit", raia_core_exit, 1);
    register_function(ctx, "entrust", raia_core_entrust, 1);

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
    init_plugin_loader();
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
        yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
        yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
        yyjson_mut_doc_set_root(ret_doc, ret_root);
        yyjson_mut_obj_add_str(ret_doc, ret_root, "script", (const char *)get_entrust_script());
        yyjson_mut_obj_add_bool(ret_doc, ret_root, "entrust", true);
        char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);
        yyjson_mut_doc_free(ret_doc);
        free_entrust();
        return result;
    }
    return NULL;
}