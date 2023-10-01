#include "library.h"

#include <stdio.h>

RAIA_EXPORT duk_ret_t hello(duk_context *ctx) {
    const char *str = duk_to_string(ctx, 0);
    printf("%s\n", str);
    return 0;
}
