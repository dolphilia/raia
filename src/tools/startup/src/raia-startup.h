//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_RAIA_STARTUP_H
#define RAIA_CORE_RAIA_STARTUP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "../../../third_party/c/ibireme/yyjson/yyjson.h"
#include "../../../common/c/utility/platform.h"

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#define raia_handle_t HMODULE
#define raia_dlopen(file) LoadLibraryA(file)
#define raia_dlsym(handle,name) GetProcAddress(handle,name)
#define raia_dlclose(handle) FreeLibrary(handle)
#define SPRINTF(dest, format, ...) { size_t size = sizeof(dest) / sizeof(dest[0]); sprintf_s(dest, size, format, __VA_ARGS__); }
#else
#include <dlfcn.h>
#define raia_handle_t void *
#define raia_dlopen(file) dlopen(file, RTLD_LAZY)
#define raia_dlsym(handle, name) dlsym(handle,name)
#define raia_dlclose(handle) dlclose(handle)
#define SPRINTF(dest, format, ...) sprintf(dest, format, __VA_ARGS__)
#endif

typedef char *(*raia_runtime_func_t)(int argc, char *argv[]);

#endif //RAIA_CORE_RAIA_STARTUP_H
