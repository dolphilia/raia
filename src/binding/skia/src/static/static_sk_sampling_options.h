//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H

#include <string>
#include <map>
#include "include/core/SkSamplingOptions.h"

void static_sk_sampling_options_delete(const char *key);
SkSamplingOptions static_sk_sampling_options_get(const char *key);
void static_sk_sampling_options_set(const char *key, SkSamplingOptions value);

#endif //RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
