//
//  static_dlfcn.h
//  raia-engine
//
//  Created by dolphilia on 2022/11/07.
//

#ifndef static_dlfcn_h
#define static_dlfcn_h

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "duktape/duktape.h"
#include "wrapper/wrapper_duktape.h"

#ifdef _WIN32
#define raia_handle_t HMODULE
#define raia_dlopen(file) LoadLibrary(file)
#define raia_dlsym(handle,name) GetProcAddress(handle,name)
#define raia_dlclose(handle) FreeLibrary(handle)
#else
#define raia_handle_t void *
#define raia_dlopen(file) dlopen(file, RTLD_LAZY)
#define raia_dlsym(handle,name) dlsym(handle,name)
#define raia_dlclose(handle) dlclose(handle)
#define raia_dlerror
#endif



//== 連結リスト

//-- プラグインリスト

typedef struct plugin_cell {
    raia_handle_t handle;
    struct plugin_cell *next;
} PluginCell;

typedef struct {
    PluginCell *top;
} PluginList;

// 関数リスト
PluginList *make_plugin_list(void);
void delete_plugin_list(PluginList *ls);
raia_handle_t nth_plugin_list(PluginList *ls, int n, bool *err);
bool insert_nth_plugin_list(PluginList *ls, int n, raia_handle_t handle);
bool delete_nth_plugin_list(PluginList *ls, int n);
bool push_plugin_list(PluginList *ls, raia_handle_t handle);
raia_handle_t pop_plugin_list(PluginList *ls, bool *err);
bool empty_plugin_list(PluginList *ls);
void print_plugin_list(PluginList *ls);

//-- 関数リスト

// セル
typedef struct func_cell {
    duk_ret_t (*pfunc)(duk_context * ctx);
    struct func_cell *next;
} FuncCell;

// リスト
typedef struct {
    FuncCell *top;
} FuncList;

// 関数リスト
FuncList *make_func_list(void);
void delete_func_list(FuncList *ls);
duk_ret_t (*nth_func_list(FuncList *ls, int n, bool *err)) (duk_context *ctx);
bool insert_nth_func_list(FuncList *ls, int n, duk_ret_t (*pfunc)(duk_context *ctx));
bool delete_nth_func_list(FuncList *ls, int n);
bool push_func_list(FuncList *ls, duk_ret_t (*pfunc)(duk_context *ctx));
duk_ret_t (*pop_func_list(FuncList *ls, bool *err)) (duk_context *ctx);
bool empty_func_list(FuncList *ls);
void print_func_list(FuncList *ls);

//
void init_dlfcn(const char * dll_file);

#ifdef _WIN32
HMODULE get_dlfcn_handle(void);
#else
void * get_dlfcn_handle(void);
#endif

duk_ret_t (*add_dlfcn_func(duk_context *ctx, const char* func_name)) (duk_context * ctx);

#endif /* static_dlfcn_h */
