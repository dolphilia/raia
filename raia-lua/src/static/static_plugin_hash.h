//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_STATIC_PLUGIN_LOADER_H
#define RAIA_CORE_STATIC_PLUGIN_LOADER_H

#include <stdio.h>
#include "../uthash/uthash.h"
#include "../platform.h"
//#include "../duktape/duktape.h"

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef __WINDOWS__
#define raia_handle_t HMODULE
#define raia_dlopen(file) LoadLibraryA(file)
#define raia_dlsym(handle,name) GetProcAddress(handle,name)
#define raia_dlclose(handle) FreeLibrary(handle)
#else
#define raia_handle_t void *
#define raia_dlopen(file) dlopen(file, RTLD_LAZY)
#define raia_dlsym(handle, name) dlsym(handle,name)
#define raia_dlclose(handle) dlclose(handle)
#endif

typedef struct raia_plugin_hash_t {
    char name[50];
    void *handle;
    UT_hash_handle hh;
} raia_plugin_hash_t;

void init_plugin_hash(void);
void free_plugin_hash();
void *add_plugin_hash(const char *name);
void *find_plugin_hash(const char *name);
void delete_plugin_hash(const char *name);

#endif //RAIA_CORE_STATIC_PLUGIN_LOADER_H
