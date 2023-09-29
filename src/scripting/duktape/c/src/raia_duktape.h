#ifndef RAIA_DUKTAPE_RAIA_DUKTAPE_H
#define RAIA_DUKTAPE_RAIA_DUKTAPE_H

#include <stdio.h>
#include <string.h>
#include "../../../../share/c/utility/export_api.h"
#include "../../../../share/c/utility/platform.h"
#include "../../../../share/c/wrapper/wrapper_yyjson.h"
#include "duktape-module/duk_module_duktape.h"
#include "static/static_plugin_hash.h"
#include "static/static_func_hash.h"
#include "static/static_entrust.h"
#include "util/util_file.h"

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

typedef struct {
    int debug_mode;
    int typescript_mode;
    int es2015_mode;
    char startup_script[512];
    int preprocess;
    char preprocess_script[512];
} raia_config_t;

#endif //RAIA_DUKTAPE_RAIA_DUKTAPE_H
