//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_sampling_options.h"

static std::set<int> static_sk_sampling_options_available_keys;
static std::map<int , SkSamplingOptions> static_sk_sampling_options;
static int static_sk_sampling_options_index = 0;

int static_sk_sampling_options_make(SkSamplingOptions value) {
    int key;
    if (!static_sk_sampling_options_available_keys.empty()) {
        auto it = static_sk_sampling_options_available_keys.begin();
        key = *it;
        static_sk_sampling_options_available_keys.erase(it);
    } else {
        key = static_sk_sampling_options_index++;
    }
    static_sk_sampling_options[key] = value;
    return key;
}

void static_sk_sampling_options_delete(int key) {
    static_sk_sampling_options.erase(key);
    static_sk_sampling_options_available_keys.insert(key);
}

SkSamplingOptions static_sk_sampling_options_get(int key) {
    return static_sk_sampling_options[key];
}

void static_sk_sampling_options_set(int key, SkSamplingOptions value) {
    static_sk_sampling_options[key] = value;
}