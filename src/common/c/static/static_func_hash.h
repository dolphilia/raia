//
// Created by dolphilia on 2023/05/04.
//

#ifndef RAIA_CORE_STATIC_FUNC_HASH_H
#define RAIA_CORE_STATIC_FUNC_HASH_H

#include "../../../third_party/c/troydhanson/uthash/uthash.h"

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef __WINDOWS__
#define raia_dlsym(handle,name) GetProcAddress(handle,name)
#else
#define RAIA_DLSYM(handle, name) dlsym(handle,name)
#endif

/**
 * @param json C string written in json format.
 * @param data Binary data
 * @param size Binary data size
 * @return Returns a C string in json format.
 */
typedef const char*(*callable_func_t)(const char *s);

typedef struct raia_func_hash_t {
    char func_name[50];
    callable_func_t func_ret_ptr;
    UT_hash_handle hh;
} func_hash_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void init_func_hash();
void free_func_hash();
void add_func_hash(const char *name, callable_func_t func);
callable_func_t find_func_hash(const char *name);
void delete_func_hash(const char *name);
void add_plugin_func_hash(void *handle, const char *name);
const char*call_func_hash(const char *name, const char *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif //RAIA_CORE_STATIC_FUNC_HASH_H
