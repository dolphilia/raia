//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_sampling_options.h"

static std::map<int , SkSamplingOptions> static_sk_sampling_options;

void static_sk_sampling_options_delete(int key) {
    static_sk_sampling_options.erase(key);
}

SkSamplingOptions static_sk_sampling_options_get(int key) {
    return static_sk_sampling_options[key];
}

void static_sk_sampling_options_set(int key, SkSamplingOptions value) {
    static_sk_sampling_options[key] = value;
}