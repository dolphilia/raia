//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_context_thread_safe_proxy.h"

static std::set<int> static_gr_context_thread_safe_proxy_available_keys;
static std::map<int, sk_sp<GrContextThreadSafeProxy>> static_gr_context_thread_safe_proxy;
static int static_gr_context_thread_safe_proxy_index = 0;

int static_gr_context_thread_safe_proxy_make(sk_sp<GrContextThreadSafeProxy> value) {
    int key;
    if (!static_gr_context_thread_safe_proxy_available_keys.empty()) {
        auto it = static_gr_context_thread_safe_proxy_available_keys.begin();
        key = *it;
        static_gr_context_thread_safe_proxy_available_keys.erase(it);
    } else {
        key = static_gr_context_thread_safe_proxy_index++;
    }
    static_gr_context_thread_safe_proxy[key] = std::move(value);
    return key;
}

void static_gr_context_thread_safe_proxy_delete(int key) {
    static_gr_context_thread_safe_proxy[key].reset();
    static_gr_context_thread_safe_proxy.erase(key);
    static_gr_context_thread_safe_proxy_available_keys.insert(key);
}

GrContextThreadSafeProxy *static_gr_context_thread_safe_proxy_get(int key) {
    return static_gr_context_thread_safe_proxy[key].get();
}

void static_gr_context_thread_safe_proxy_set(int key, sk_sp<GrContextThreadSafeProxy> value) {
    static_gr_context_thread_safe_proxy[key] = std::move(value);
}

sk_sp<GrContextThreadSafeProxy> static_gr_context_thread_safe_proxy_move(int key) {
    return std::move(static_gr_context_thread_safe_proxy[key]);
}