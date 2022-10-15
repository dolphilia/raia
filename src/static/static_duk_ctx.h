//
//  static_duk_ctx.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#ifndef static_duk_ctx_h
#define static_duk_ctx_h

#include <stdio.h>
#include "duktape/duktape.h"

void init_duk_ctx(void);
duk_context* get_duk_ctx(void);

#endif /* static_duk_ctx_h */
