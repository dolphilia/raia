//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkSamplingOptions.h"

typedef int sk_sampling_options_t;

int static_sk_sampling_options_make(SkSamplingOptions value);
extern "C" void static_sk_sampling_options_delete(int key);
SkSamplingOptions static_sk_sampling_options_get(int key);
void static_sk_sampling_options_set(int key, SkSamplingOptions value);

#endif //RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
