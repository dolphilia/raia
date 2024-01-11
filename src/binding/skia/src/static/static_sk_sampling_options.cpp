//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_sampling_options.h"

static std::map<std::string, SkSamplingOptions> static_sk_sampling_options;

void static_sk_sampling_options_delete(const char *key) {
    static_sk_sampling_options.erase(key);
}

SkSamplingOptions static_sk_sampling_options_get(const char *key) {
    return static_sk_sampling_options[key];
}

void static_sk_sampling_options_set(const char *key, SkSamplingOptions value) {
    static_sk_sampling_options[key] = value;
}