//
//  static_duk_ctx.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#include "static_duk_ctx.h"

static duk_context* duk_ctx;

void init_duk_ctx(void) {
    duk_ctx = duk_create_heap_default();
}

duk_context* get_duk_ctx(void) {
    return duk_ctx;
}
