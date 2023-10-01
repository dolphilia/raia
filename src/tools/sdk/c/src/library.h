#ifndef RAIA_SDK_LIBRARY_H
#define RAIA_SDK_LIBRARY_H

#include "duktape/duktape.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT duk_ret_t hello(duk_context *ctx);

#endif //RAIA_SDK_LIBRARY_H
