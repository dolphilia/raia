//
// Created by dolphilia on 2022/12/10.
//

#include "raia-startup.h"

void report_error(const char *msg, const char *file, int line, const char *func) {
    fprintf(stderr, "Error in function '%s' at %s:%d: %s\n", func, file, line, msg);
    exit(EXIT_FAILURE);
}


static const char *get_runtime_from_json(yyjson_doc *doc) {
    yyjson_val *root = yyjson_doc_get_root(doc);
    yyjson_val *runtime_val = yyjson_obj_get(root, "runtime");
    const char *runtime = yyjson_get_str(runtime_val);
    if (!runtime) {
        fprintf(stderr, "Failed to retrieve runtime from JSON\n");
        exit(EXIT_FAILURE);
    }
    return runtime;
}

static void *load_dll_file(const char *dll_file_name) {
    void *handle = raia_dlopen(dll_file_name);
    if (!handle) {
        fprintf(stderr, "Failed to load DLL file: %s\n", dll_file_name);
        exit(EXIT_FAILURE);
    }
    return handle;
}

static raia_runtime_func_t get_raia_runtime_func(void *handle, const char *func_name) {
    raia_runtime_func_t func = (raia_runtime_func_t) raia_dlsym(handle, func_name);
    if (!func) {
        fprintf(stderr, "Failed to get function from DLL: %s\n", func_name);
        raia_dlclose(handle);
        exit(EXIT_FAILURE);
    }
    return func;
}

static void raia_alert_exec(const char *caption, const char *text) {
    if (fork() == 0) {
        execlp("./raia_alert", "", "-c", caption, "-t", text, NULL);
    } else {
        wait(NULL);
    }
}

int main(int argc, char *argv[]) {
    yyjson_doc *doc = yyjson_read_file("config.json", 0, NULL, NULL);
    if (doc == NULL) {
        yyjson_doc_free(doc);
        raia_alert_exec("エラー", "jsonファイルを読み込めません");
        exit(1);
    }
    const char *runtime = get_runtime_from_json(doc);

    const char *extension;
#ifdef __WINDOWS__
    extension = "dll";
#elif defined(__MACOS__)
    extension = "dylib";
#elif defined(__LINUX__)
    extension = "so";
#else
    fprintf(stderr, "Unsupported OS\n");
    exit(1);
#endif
    char dll_file_name[500];
    SPRINTF(dll_file_name, "%s.%s", runtime, extension);
    void *handle = load_dll_file(dll_file_name);
    raia_runtime_func_t raia_runtime_run = get_raia_runtime_func(handle, "init");
    yyjson_doc_free(doc);

    char * result = raia_runtime_run(argc, argv);
    if (result != NULL) {
        printf("%s \n", result);
        free((void *)result);
    }
    return 0;
}