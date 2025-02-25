#ifndef STATIC_SK_MASK_FILTER_INTERNAL_H
#define STATIC_SK_MASK_FILTER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkMaskFilter.h"
int static_sk_mask_filter_make(sk_sp<SkMaskFilter> value);
void static_sk_mask_filter_set(int key, sk_sp<SkMaskFilter> value);
sk_sp<SkMaskFilter> static_sk_mask_filter_get_entity(int key);
#endif // STATIC_SK_MASK_FILTER_INTERNAL_H
