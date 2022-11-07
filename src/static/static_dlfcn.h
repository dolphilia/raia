//
//  static_dlfcn.h
//  raia-engine
//
//  Created by dolphilia on 2022/11/07.
//

#ifndef static_dlfcn_h
#define static_dlfcn_h

#include <stdio.h>
#include <dlfcn.h>
#include "duktape/duktape.h"
#include "wrapper/wrapper_duktape.h"

void init_dlfcn(const char * dll_file);

#ifdef _WIN32
HMODULE get_dlfcn_handle(void);
#else
void * get_dlfcn_handle(void);
#endif

void add_dlfcn_func(duk_context *ctx, const char* func_name, int nargs);

#endif /* static_dlfcn_h */
