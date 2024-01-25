//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_sampling_options.h"

static std::map<int , SkSamplingOptions> static_sk_sampling_options;
static int static_sk_sampling_options_index = 0;

int static_sk_sampling_options_make(SkSamplingOptions value) {
    static_sk_sampling_options[static_sk_sampling_options_index] = value;
    static_sk_sampling_options_index++;
    return static_sk_sampling_options_index - 1;
}

void static_sk_sampling_options_delete(int key) {
    static_sk_sampling_options.erase(key);
}

SkSamplingOptions static_sk_sampling_options_get(int key) {
    return static_sk_sampling_options[key];
}

void static_sk_sampling_options_set(int key, SkSamplingOptions value) {
    static_sk_sampling_options[key] = value;
}