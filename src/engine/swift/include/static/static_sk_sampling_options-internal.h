#ifndef STATIC_SK_SAMPLING_OPTIONS_INTERNAL_H
#define STATIC_SK_SAMPLING_OPTIONS_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkSamplingOptions.h"
int static_sk_sampling_options_make(SkSamplingOptions value);
SkSamplingOptions static_sk_sampling_options_get(int key);
void static_sk_sampling_options_set(int key, SkSamplingOptions value);
#endif // STATIC_SK_SAMPLING_OPTIONS_INTERNAL_H
