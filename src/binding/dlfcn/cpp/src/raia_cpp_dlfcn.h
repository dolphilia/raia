#ifndef RAIA_CPP_DLFCN_RAIA_CPP_DLFCN_H
#define RAIA_CPP_DLFCN_RAIA_CPP_DLFCN_H

#include <iostream>
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../third_party/cpp/nlohmann/json/json.hpp"


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

#endif //RAIA_CPP_DLFCN_RAIA_CPP_DLFCN_H
