//
// Created by dolphilia on 2024/02/16.
//

#ifndef RAIA_QUICKJS_RAIA_QUICKJS_H
#define RAIA_QUICKJS_RAIA_QUICKJS_H

#include <stdio.h>
#include <string.h>
#include "quickjs/quickjs.h"
#include "quickjs/quickjs-libc.h"
#include "../../../common/c/utility/export_api.h"
#include "../../../common/c/utility/platform.h"
#include "../../../common/c/static/shared_library_loader.h"
#include "ffi.h"
#include "../../../common/c/static/static_args_hash.h"
#include "../../../common/c/wrapper/wrapper_ffi.h"

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


#endif //RAIA_QUICKJS_RAIA_QUICKJS_H
