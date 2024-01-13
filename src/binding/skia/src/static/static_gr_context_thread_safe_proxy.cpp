//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_context_thread_safe_proxy.h"

static std::map<std::string, sk_sp<GrContextThreadSafeProxy>> static_gr_context_thread_safe_proxy;

void static_gr_context_thread_safe_proxy_delete(const char *key) {
    static_gr_context_thread_safe_proxy[key].reset();
    static_gr_context_thread_safe_proxy.erase(key);
}

GrContextThreadSafeProxy *static_gr_context_thread_safe_proxy_get(const char *key) {
    return static_gr_context_thread_safe_proxy[key].get();
}

void static_gr_context_thread_safe_proxy_set(const char *key, sk_sp<GrContextThreadSafeProxy> value) {
    static_gr_context_thread_safe_proxy[key] = std::move(value);
}

sk_sp<GrContextThreadSafeProxy> static_gr_context_thread_safe_proxy_move(const char *key) {
    return std::move(static_gr_context_thread_safe_proxy[key]);
}