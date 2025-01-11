//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H
#define RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkImageFilter.h"
#include "export_api.h"

typedef int sk_image_filter_t;

extern "C" {
RAIA_API void static_sk_image_filter_delete(int key);
RAIA_API SkImageFilter *static_sk_image_filter_get(int key);
}

int static_sk_image_filter_make(sk_sp<SkImageFilter> value);
void static_sk_image_filter_set(int key, sk_sp<SkImageFilter> value);
sk_sp<SkImageFilter> static_sk_image_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H
