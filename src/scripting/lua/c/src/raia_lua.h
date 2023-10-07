#ifndef RAIA_LUA_RAIA_LUA_H
#define RAIA_LUA_RAIA_LUA_H

#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#include "../../../../common/c/static/static_plugin_hash.h"
#include "../../../../common/c/static/static_func_hash.h"
#include "../../../../common/c/utility/util_file.h"
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"

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

#endif //RAIA_LUA_RAIA_LUA_H
