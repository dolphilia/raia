//
//  util_duktape.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef wrapper_duktape_h
#define wrapper_duktape_h

#include <stdio.h>
#include "util_io.h"
#include "duktape.h"

void load_script_filename(duk_context *ctx, const char* filename);
void regist_func(duk_context *ctx, duk_c_function func, const char *str, int nargs);

#endif /* util_duktape_h */
