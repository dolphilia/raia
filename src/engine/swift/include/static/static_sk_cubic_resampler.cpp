//
// Created by dolphilia on 2024/04/03.
//

#include "static_sk_cubic_resampler.h"
#include "static_sk_cubic_resampler-internal.h"

static std::set<int> static_sk_cubic_resampler_available_keys;
static std::map<int , SkCubicResampler> static_sk_cubic_resampler;
static int static_sk_cubic_resampler_index = 0;

int static_sk_cubic_resampler_make(SkCubicResampler value) {
    int key;
    if (!static_sk_cubic_resampler_available_keys.empty()) {
        auto it = static_sk_cubic_resampler_available_keys.begin();
        key = *it;
        static_sk_cubic_resampler_available_keys.erase(it);
    } else {
        key = static_sk_cubic_resampler_index++;
    }
    static_sk_cubic_resampler[key] = value;
    return key;
}

void static_sk_cubic_resampler_delete(int key) {
    static_sk_cubic_resampler.erase(key);
    static_sk_cubic_resampler_available_keys.insert(key);
}

SkCubicResampler static_sk_cubic_resampler_get(int key) {
    return static_sk_cubic_resampler[key];
}

void * static_sk_cubic_resampler_get_ptr(int key) { // -> SkCubicResampler *
    return &static_sk_cubic_resampler[key];
}
