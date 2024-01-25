//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_capabilities.h"

static std::map<int , sk_sp<const SkCapabilities>> static_const_sk_capabilities;
static int static_const_sk_capabilities_index = 0;

int static_const_sk_capabilities_make(sk_sp<const SkCapabilities> value) {
    static_const_sk_capabilities[static_const_sk_capabilities_index] = std::move(value);
    static_const_sk_capabilities_index++;
    return static_const_sk_capabilities_index - 1;
}

void static_const_sk_capabilities_delete(int key) {
    static_const_sk_capabilities[key].reset();
    static_const_sk_capabilities.erase(key);
}

const SkCapabilities *static_const_sk_capabilities_get(int key) {
    return static_const_sk_capabilities[key].get();
}

void static_const_sk_capabilities_set(int key, sk_sp<const SkCapabilities> value) {
    static_const_sk_capabilities[key] = std::move(value);
}

sk_sp<const SkCapabilities> static_const_sk_capabilities_move(int key) {
    return std::move(static_const_sk_capabilities[key]);
}