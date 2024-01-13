//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H
#define RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H

#include <string>
#include <map>
#include "include/gpu/GrContextThreadSafeProxy.h"

void static_gr_context_thread_safe_proxy_delete(const char *key);
GrContextThreadSafeProxy *static_gr_context_thread_safe_proxy_get(const char *key);
void static_gr_context_thread_safe_proxy_set(const char *key, sk_sp<GrContextThreadSafeProxy> value);
sk_sp<GrContextThreadSafeProxy> static_gr_context_thread_safe_proxy_move(const char *key);

#endif //RAIA_SKIA_STATIC_GR_CONTEXT_THREAD_SAFE_PROXY_H
