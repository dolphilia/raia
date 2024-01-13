//
// Created by dolphilia on 2024/01/12.
//

#include "gr_context_thread_safe_proxy.h"

extern "C" {

bool GrContextThreadSafeProxy_unique(GrContextThreadSafeProxy *context_thread_safe_proxy) {
    return context_thread_safe_proxy->unique();
}

void GrContextThreadSafeProxy_ref(GrContextThreadSafeProxy *context_thread_safe_proxy) {
    return context_thread_safe_proxy->ref();
}

void GrContextThreadSafeProxy_unref(GrContextThreadSafeProxy *context_thread_safe_proxy) {
    return context_thread_safe_proxy->unref();
}

void GrContextThreadSafeProxy_deref(GrContextThreadSafeProxy *context_thread_safe_proxy) {
    return context_thread_safe_proxy->deref();
}

bool GrContextThreadSafeProxy_refCntGreaterThan(GrContextThreadSafeProxy *context_thread_safe_proxy, int32_t threadIsolatedTestCnt) {
    return context_thread_safe_proxy->refCntGreaterThan(threadIsolatedTestCnt);
}

}