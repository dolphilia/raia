//
// Created by dolphilia on 2023/07/18.
//

#ifndef RAIA_V8_RAIA_V8_H
#define RAIA_V8_RAIA_V8_H

extern "C" {
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#include "../../../../common/c/static/static_plugin_hash.h"
#include "../../../../common/c/static/static_func_hash.h"
#include "../../../../common/c/static/static_entrust.h"
#include "../../../../common/c/utility/util_file.h"
}
#include "static/static_raia_config.h"
#include "typescript/typescript.h"



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
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif



// Loads a module; line #187
v8::MaybeLocal<v8::Module> import_load(char code[],
                                       char name[],
                                       v8::Local<v8::Context> cx);

// Check, if module isn't empty (or pointer to it); line #221
v8::Local<v8::Module> import_check(v8::MaybeLocal<v8::Module> maybeModule,
                                   v8::Local<v8::Context> cx);

// Executes module; line #247
v8::Local<v8::Value> import_exec(v8::Local<v8::Module> mod,
                                 v8::Local<v8::Context> cx,
                                 bool nsObject = false);

// Callback for static import; line #270
v8::MaybeLocal<v8::Module> import_static_callback(v8::Local<v8::Context> context,
                                                  v8::Local<v8::String> specifier,
                                                  v8::Local<v8::Module> referrer);

// Callback for dynamic import; line #285
v8::MaybeLocal<v8::Promise> import_dynamic_callback(v8::Local<v8::Context> context,
                                                    v8::Local<v8::ScriptOrModule> referrer,
                                                    v8::Local<v8::String> specifier);

// Callback for module metadata; line #310
void import_meta(v8::Local<v8::Context> context,
                 v8::Local<v8::Module> module,
                 v8::Local<v8::Object> meta);

extern "C" RAIA_EXPORT char *init(int argc, char *argv[]);

#endif //RAIA_V8_RAIA_V8_H
