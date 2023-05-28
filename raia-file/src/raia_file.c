#include "raia_file.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT void *raia_file_exist(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    int exist = file_check_path(path);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "result", exist);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_load_string(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    const char *str = file_load_string(path);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "result", str);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_save_string(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);
    yyjson_val *arg_val2 = yyjson_obj_get(arg_root, "data");
    const char *data = yyjson_get_str(arg_val2);

    file_save_string(path, data);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", 1);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_load_binary(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    size_t file_size;
    uint8_t *file_data = file_load_binary(path, &file_size);
    if (file_data == NULL) {
        fprintf(stderr, "Failed to read binary file: %s", path);
        return NULL;
    }

    yyjson_doc_free(arg_doc);
    return file_data;
}

RAIA_EXPORT void *raia_file_save_binary(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    size_t data_size = n;
    uint8_t *data = p;
    int is_success = file_save_binary(path, data, data_size);
    const char *result;

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);

    if (is_success == 0) {
        yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", 1);
        result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);
    } else {
        yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", 0);
        result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);
    }

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_get_exe_path(const char *s, void *p, int n) {
    char *path = get_exe_path();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "result", path);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_get_cur_path(const char *s, void *p, int n) {
    char *path = get_current_path();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "result", path);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    free(path);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_get_dirs(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    char **directories = NULL;
    size_t count = 0;
    get_directories(path, &directories, &count);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_val *ret_vals = yyjson_mut_arr_with_str(ret_doc, (const char **)directories, count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "result", ret_vals);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_file_get_dirs_all(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "path");
    const char *path = yyjson_get_str(arg_val);

    char **directories = NULL;
    size_t count = 0;
    get_directories_recursive(path, &directories, &count);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_val *ret_vals = yyjson_mut_arr_with_str(ret_doc, (const char **)directories, count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "result", ret_vals);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}