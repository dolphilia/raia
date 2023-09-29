#ifndef RAIA_C_DLFCN_RAIA_C_DLFCN_H
#define RAIA_C_DLFCN_RAIA_C_DLFCN_H

#include "../../../../share/c/utility/export_api.h"
#include "../../../../share/c/utility/platform.h"
#include "../../../../share/c/wrapper/wrapper_yyjson.h"

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef __WINDOWS__
#define raia_dl_handle_t HMODULE
#define raia_dlopen(path) LoadLibraryA(path)
#define raia_dlsym(handle,symbol) GetProcAddress(handle,symbol)
#define raia_dlclose(handle) FreeLibrary(handle)
#else
#define raia_dl_handle_t void *
#define raia_dlopen(path) dlopen(path, RTLD_LAZY)
#define raia_dlsym(handle, symbol) dlsym(handle, symbol)
#define raia_dlclose(handle) dlclose(handle)
#endif

#endif //RAIA_C_DLFCN_RAIA_C_DLFCN_H
