//
// Created by dolphilia on 2024/02/14.
//

#ifndef SHARED_LIBRARY_LOADER_H
#define SHARED_LIBRARY_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../third_party/c/troydhanson/uthash/uthash.h"
#include "../../../third_party/c/troydhanson/uthash/utlist.h"
#include "../../../third_party/c/troydhanson/uthash/utstring.h"

#ifdef __WINDOWS__
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef __WINDOWS__
#define RAIA_DLOPEN(file) LoadLibraryA(file)
#define RAIA_DLSYM(handle, name) GetProcAddress(handle, name)
#define RAIA_DLCLOSE(handle) FreeLibrary(handle)
#else
#define RAIA_DLOPEN(file) dlopen(file, RTLD_LAZY)
#define RAIA_DLSYM(handle, name) dlsym(handle, name)
#define RAIA_DLCLOSE(handle) dlclose(handle)
#endif

typedef const char*(*callable_func_t)(const char *json);

typedef struct func_hash_t {
    UT_string *func_name;
    callable_func_t func_ptr;
    UT_hash_handle hh;
} func_hash_t;

typedef struct library_hash_t {
    int id;
    void* handle;
    func_hash_t* func_hash;
    UT_hash_handle hh;
} library_hash_t;

typedef struct deleted_key_list_t {
    int key;
    struct deleted_key_list_t *next;
} deleted_key_list_t;

#ifdef __cplusplus
extern "C" {
#endif

void close_all_shared_library(void);
int open_shared_library(const char* library_name);
void* find_shared_library(int library_key);
void close_shared_library(int library_key);
void add_func_shared_library(int library_key, const char *func_name);
const char* call_func_shared_library(int library_key, const char *func_name, const char *json);
callable_func_t find_func_shared_library(int library_key, const char *func_name);
void delete_func_shared_library(int library_key, const char *func_name);

#ifdef __cplusplus
}
#endif

#endif //SHARED_LIBRARY_LOADER_H
