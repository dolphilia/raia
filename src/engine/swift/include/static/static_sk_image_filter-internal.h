#ifndef STATIC_SK_IMAGE_FILTER_INTERNAL_H
#define STATIC_SK_IMAGE_FILTER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkImageFilter.h"
int static_sk_image_filter_make(sk_sp<SkImageFilter> value);
void static_sk_image_filter_set(int key, sk_sp<SkImageFilter> value);
sk_sp<SkImageFilter> static_sk_image_filter_move(int key);
#endif // STATIC_SK_IMAGE_FILTER_INTERNAL_H
