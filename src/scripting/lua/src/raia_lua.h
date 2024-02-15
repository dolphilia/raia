#ifndef RAIA_LUA_RAIA_LUA_H
#define RAIA_LUA_RAIA_LUA_H

#include <stdio.h>
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include "../../../common/c/wrapper/wrapper_yyjson.h"
#include "../../../common/c/utility/util_file.h"
#include "../../../common/c/utility/export_api.h"
#include "../../../common/c/utility/platform.h"

#ifdef _WIN32
#include <stdlib.h>
#define STRCAT(dest, src) { size_t size = sizeof(dest) / sizeof(dest[0]); strcat_s(dest, size, src); }
#define SPRINTF(dest, format, ...) { size_t size = sizeof(dest) / sizeof(dest[0]); sprintf_s(dest, size, format, __VA_ARGS__); }
#define STRNCPY(dest, src, count) { size_t size = sizeof(dest) / sizeof(dest[0]); strncpy_s(dest, size, src, count); }
#else
#define STRCAT(dest, src) strcat(dest, src)
#define SPRINTF(dest, format, ...) sprintf(dest, format, __VA_ARGS__)
#define STRNCPY(dest, src, count) strncpy(dest, src, count)
#endif

#ifdef __WINDOWS__
#define DYNAMIC_LIB_EXT "dll"
#endif
#ifdef __MACOS__
#define DYNAMIC_LIB_EXT "dylib"
#endif
#ifdef __LINUX__
#define DYNAMIC_LIB_EXT "so"
#endif

#endif //RAIA_LUA_RAIA_LUA_H
