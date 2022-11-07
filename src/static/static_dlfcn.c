//
//  static_dlfcn.c
//  raia-engine
//
//  Created by dolphilia on 2022/11/07.
//

#include "static_dlfcn.h"

#ifdef _WIN32
HMODULE handle;
#else
void * handle;
#endif

duk_ret_t (*pfunc)(duk_context * ctx);

void init_dlfcn(const char * dll_file) {
#ifdef _WIN32
    handle = LoadLibrary(dll_file);
#else
    handle = dlopen(dll_file, RTLD_LAZY);
    if (handle == 0) {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }
#endif
}

#ifdef _WIN32
HMODULE get_dlfcn_handle(void)
#else
void * get_dlfcn_handle(void)
#endif
{
    return handle;
}

void add_dlfcn_func(duk_context *ctx, const char* dll_func_name, int nargs) {
    
#ifdef _WIN32
    pfunc = GetProcAddress(handle, dll_func_name);
#else
    pfunc = dlsym(handle, dll_func_name);
#endif
    
    duk_push_c_function(ctx, pfunc, nargs);
    //duk_put_global_string(ctx, regist_func_name);
    
    //regist_func(ctx, pfunc, regist_func_name, nargs);
    
    
    
}
    
void call_dlfcn_func(void) {
    //pfunc();
}

void close_dlfcn(void) {
#ifdef _WIN32
    if (FreeLibrary(handle)) {
        return;
    }
#else
    if (dlclose(handle) != 0) {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }
#endif
}

//static duk_ret_t regist_stdc_dlopen(duk_context *ctx) {
//    const char* dll_file = duk_to_string(ctx, 0);
//
//    duk_push_pointer(ctx, handle);
//    return 1;  /* no return value (= undefined) */
//}
//
//static duk_ret_t regist_stdc_dlsym(duk_context *ctx) {
//    void * handle = duk_to_pointer(ctx, 0);
//    const char* func_name = duk_to_string(ctx, 1);
//#ifdef _WIN32
//    void (*ret)(void) = GetProcAddress(handle, func_name);
//#else
//    void (*ret)(void) = dlsym(handle, func_name);
//#endif
//    duk_push_pointer(ctx, ret);
//    return 1;  /* no return value (= undefined) */
//}
