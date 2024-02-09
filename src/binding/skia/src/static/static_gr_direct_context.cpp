//
// Created by dolphilia on 2024/02/09.
//

#include "static_gr_direct_context.h"

static std::set<int> static_gr_direct_context_available_keys;
static std::map<int, sk_sp<GrDirectContext>> static_gr_direct_context;
static int static_gr_direct_context_index = 0;

int static_gr_direct_context_make(sk_sp<GrDirectContext> value) {
    int key;
    if (!static_gr_direct_context_available_keys.empty()) {
        auto it = static_gr_direct_context_available_keys.begin();
        key = *it;
        static_gr_direct_context_available_keys.erase(it);
    } else {
        key = static_gr_direct_context_index++;
    }
    static_gr_direct_context[key] = std::move(value);
    return key;
}

void static_gr_direct_context_delete(int key) {
    static_gr_direct_context[key].reset();
    static_gr_direct_context.erase(key);
    static_gr_direct_context_available_keys.insert(key);
}

GrDirectContext *static_gr_direct_context_get(int key) {
    return static_gr_direct_context[key].get();
}

void static_gr_direct_context_set(int key, sk_sp<GrDirectContext> value) {
    static_gr_direct_context[key] = std::move(value);
}

sk_sp<GrDirectContext> static_gr_direct_context_move(int key) {
    return std::move(static_gr_direct_context[key]);
}