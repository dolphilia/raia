//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkSamplingOptions.h"
#include "export_api.h"

typedef int sk_sampling_options_t;

extern "C" {
RAIA_API void static_sk_sampling_options_delete(int key);
RAIA_API SkSamplingOptions * static_sk_sampling_options_get_ptr(int key);
}

int static_sk_sampling_options_make(SkSamplingOptions value);
SkSamplingOptions static_sk_sampling_options_get(int key);
void static_sk_sampling_options_set(int key, SkSamplingOptions value);

#endif //RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
