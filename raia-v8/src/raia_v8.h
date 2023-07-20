//
// Created by dolphilia on 2023/07/18.
//

#ifndef RAIA_V8_RAIA_V8_H
#define RAIA_V8_RAIA_V8_H

#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"
#include "static/static_plugin_hash.h"
#include "static/static_func_hash.h"
#include "static/static_entrust.h"
#include "util/util_file.h"
#include "platform.h"

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

typedef struct {
    int debug_mode;
    int typescript_mode;
    int es2015_mode;
    char startup_script[512];
    int preprocess;
    char preprocess_script[512];
} raia_config_t;

// Reads a file to char array; line #140
char* load_module_script(char filename[]);

// Simple print function binding to JavaScript VM; line #169
void print(const v8::FunctionCallbackInfo<v8::Value>& args);

// Loads a module; line #187
v8::MaybeLocal<v8::Module> loadModule(char code[],
                                      char name[],
                                      v8::Local<v8::Context> cx);

// Check, if module isn't empty (or pointer to it); line #221
v8::Local<v8::Module> checkModule(v8::MaybeLocal<v8::Module> maybeModule,
                                  v8::Local<v8::Context> cx);

// Executes module; line #247
v8::Local<v8::Value> execModule(v8::Local<v8::Module> mod,
                                v8::Local<v8::Context> cx,
                                bool nsObject = false);

// Callback for static import; line #270
v8::MaybeLocal<v8::Module> callResolve(v8::Local<v8::Context> context,
                                       v8::Local<v8::String> specifier,
                                       v8::Local<v8::Module> referrer);

// Callback for dynamic import; line #285
v8::MaybeLocal<v8::Promise> callDynamic(v8::Local<v8::Context> context,
                                        v8::Local<v8::ScriptOrModule> referrer,
                                        v8::Local<v8::String> specifier);

// Callback for module metadata; line #310
void callMeta(v8::Local<v8::Context> context,
              v8::Local<v8::Module> module,
              v8::Local<v8::Object> meta);

extern "C" RAIA_EXPORT char *init(int argc, char *argv[]);

#endif //RAIA_V8_RAIA_V8_H
