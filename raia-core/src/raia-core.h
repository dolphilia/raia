//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_RAIA_CORE_H
#define RAIA_CORE_RAIA_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "yyjson/yyjson.h"
#include "tomlc99/toml.h"

#ifdef _WIN32
#define __WINDOWS__
#endif

#ifdef _WIN64
#define __WINDOWS__
#endif

#ifdef __APPLE__

#include "TargetConditionals.h"

#ifdef TARGET_OS_MAC
#define __MACOS__
#endif
#endif

#ifdef __linux__
#define __LINUX__
#endif

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

#endif //RAIA_CORE_RAIA_CORE_H
