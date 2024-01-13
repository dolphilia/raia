//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_CONTEXT_THREAD_SAFE_PROXY_H
#define RAIA_SKIA_GR_CONTEXT_THREAD_SAFE_PROXY_H

#include "include/gpu/GrContextThreadSafeProxy.h"

extern "C" {
bool GrContextThreadSafeProxy_unique(GrContextThreadSafeProxy *context_thread_safe_proxy);
void GrContextThreadSafeProxy_ref(GrContextThreadSafeProxy *context_thread_safe_proxy);
void GrContextThreadSafeProxy_unref(GrContextThreadSafeProxy *context_thread_safe_proxy);
void GrContextThreadSafeProxy_deref(GrContextThreadSafeProxy *context_thread_safe_proxy);
bool GrContextThreadSafeProxy_refCntGreaterThan(GrContextThreadSafeProxy *context_thread_safe_proxy, int32_t threadIsolatedTestCnt);
}

#endif //RAIA_SKIA_GR_CONTEXT_THREAD_SAFE_PROXY_H
