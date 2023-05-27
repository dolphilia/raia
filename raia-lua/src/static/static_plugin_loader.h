//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_STATIC_PLUGIN_LOADER_H
#define RAIA_CORE_STATIC_PLUGIN_LOADER_H

#include <stdio.h>

#include "../platform.h"

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#else

#include <dlfcn.h>

#endif

//#include "../duktape/duktape.h"
#include "../list/list.h"

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

void init_plugin_loader(void);

void open_plugin(const char *dll_file);

void close_plugin(void);

void close_all_plugin(void);

void *get_plugin_handle(void);

//duk_ret_t (*add_plugin_func(duk_context *ctx, const char *func_name))(duk_context *ctx);
//void (*add_plugin_init(const char *func_name))(void);

#endif //RAIA_CORE_STATIC_PLUGIN_LOADER_H
