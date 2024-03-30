//
// Created by dolphilia on 2024/02/09.
//

#ifndef RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_H
#define RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_H

#include <set>
#include <map>
#include "include/gpu/GrDirectContext.h"

typedef int gr_direct_context_t;

int static_gr_direct_context_make(sk_sp<GrDirectContext> value);
extern "C" void static_gr_direct_context_delete(int key);
extern "C" GrDirectContext *static_gr_direct_context_get(int key);
void static_gr_direct_context_set(int key, sk_sp<GrDirectContext> value);
sk_sp<GrDirectContext> static_gr_direct_context_move(int key);

#endif //RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_H
