//
// Created by dolphilia on 2023/07/23.
//

#ifndef RAIA_V8_WRAPPER_V8_H
#define RAIA_V8_WRAPPER_V8_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include "v8.h"
#include "../static/static_raia_config.h"

//-- define

#define isol_t v8::Isolate
#define isol_cp_t v8::Isolate::CreateParams
#define platform_t v8::Platform
#define local_t v8::Local
#define obj_t v8::Object
#define fc_t v8::FunctionCallback
#define l_obj_t v8::Local<v8::Object>
#define l_mod_t v8::Local<v8::Module>
#define l_obj_tmp_t v8::Local<v8::ObjectTemplate>
#define l_ctx_t v8::Local<v8::Context>
#define l_buf_t v8::Local<v8::ArrayBuffer>
#define l_fn_tmp_t v8::Local<v8::FunctionTemplate>
#define l_fn_t v8::Local<v8::Function>
#define l_str_t v8::Local<v8::String>
#define l_script_t v8::Local<v8::Script>
#define l_val_t v8::Local<v8::Value>
#define l_mes_t v8::Local<v8::Message>
#define l_som_t v8::Local<v8::ScriptOrModule>
#define l_res_t v8::Local<v8::Promise::Resolver>
#define fci_val_t v8::FunctionCallbackInfo<v8::Value>
#define up_pf_t std::unique_ptr<v8::Platform>
#define sp_bs_t std::shared_ptr<v8::BackingStore>
#define up_bs_t std::unique_ptr<v8::BackingStore>
#define str_utf8_t v8::String::Utf8Value
#define string_t std::string
#define vec_str_t std::vector<std::string>
#define ifstream_t std::ifstream
#define filebuf_t std::filebuf
#define try_catch_t v8::TryCatch
#define ml_val_t v8::MaybeLocal<v8::Value>
#define ml_mod_t v8::MaybeLocal<v8::Module>
#define ml_bool_t v8::Maybe<bool>
#define ml_promise_t v8::MaybeLocal<v8::Promise>
#define ml_fn_t v8::MaybeLocal<v8::Function>
#define l_prim_arr_t v8::Local<v8::PrimitiveArray>
#define isol_scope_t v8::Isolate::Scope
#define handle_scope_t v8::HandleScope
#define ctx_scope_t v8::Context::Scope
#define source_t v8::ScriptCompiler::Source

enum ScriptType : int {
    kScript,
    kModule,
    kFunction,
};

enum HostDefinedOptions : int {
    kType = 8,
    kID = 9,
    kLength = 10,
};

//-- util function

l_str_t local_str(isol_t *isolate, const char *data);
l_script_t local_script(l_ctx_t context, l_str_t str);
string_t get_str_v8_fn_args(const fci_val_t &args, int num);
void set_int_v8_fn_ret(const fci_val_t &args, int result);
void set_local_obj(isol_t *isolate, l_obj_t obj, const char *key, l_val_t value);
l_obj_t set_new_local_obj(isol_t *isolate, l_obj_t obj, const char *key);
l_str_t new_local_str(isol_t *isolate, const char *data);
l_fn_tmp_t new_fn_tmp(isol_t *isolate, fc_t callback);
l_fn_t new_local_fn(isol_t *isolate, fc_t callback);
ml_fn_t new_maybe_local_fn(l_ctx_t context, fc_t callback);
void set_local_fn(isol_t *isolate, l_obj_t obj, const char *key, fc_t callback);
string_t new_str_from_val(isol_t *isolate, l_val_t val);
vec_str_t get_directories(const std::string& s);
string_t file_exists_in_directories(const std::string& filename, const vec_str_t& directories);
string_t find_file_in_directories(const std::string& filename, const vec_str_t& dirs);
char* load_script(char filename[], const string_t& root_dir, bool is_startup);
//bool write_script(const std::string& filename, const std::string& code);
//std::string replace_extension(const std::string& filepath, const std::string& new_extension);
//char* load_module_script(char filename[], const string_t& root_dir, bool is_startup, bool ts_mode);
//void set_module_fn(l_ctx_t context, l_obj_t obj, const char *name, fc_t callback);
//l_obj_t set_module_obj(l_ctx_t context, l_obj_tmp_t obj_tmp, l_obj_t obj, const char *name);

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

#endif //RAIA_V8_WRAPPER_V8_H
