//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_capabilities.h"

static std::map<std::string, sk_sp<const SkCapabilities>> static_const_sk_capabilities;

void static_const_sk_capabilities_delete(const char *key) {
    static_const_sk_capabilities[key].reset();
    static_const_sk_capabilities.erase(key);
}

const SkCapabilities *static_const_sk_capabilities_get(const char *key) {
    return static_const_sk_capabilities[key].get();
}

void static_const_sk_capabilities_set(const char *key, sk_sp<const SkCapabilities> value) {
    static_const_sk_capabilities[key] = std::move(value);
}

sk_sp<const SkCapabilities> static_const_sk_capabilities_move(const char *key) {
    return std::move(static_const_sk_capabilities[key]);
}