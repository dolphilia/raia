//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H
#define RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H

#include <set>
#include <string>
#include <map>
#include "include/gpu/GrContextThreadSafeProxy.h"

typedef int gr_context_thread_safe_proxy_t;

int static_gr_context_thread_safe_proxy_make(sk_sp<GrContextThreadSafeProxy> value);
extern "C" void static_gr_context_thread_safe_proxy_delete(int key);
extern "C" GrContextThreadSafeProxy *static_gr_context_thread_safe_proxy_get(int key);
void static_gr_context_thread_safe_proxy_set(int key, sk_sp<GrContextThreadSafeProxy> value);
sk_sp<GrContextThreadSafeProxy> static_gr_context_thread_safe_proxy_move(int key);

#endif //RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H
