//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H
#define RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H

#include <string>
#include <map>
#include "include/core/SkImageFilter.h"

void static_sk_image_filter_delete(int key);
SkImageFilter *static_sk_image_filter_get(int key);
void static_sk_image_filter_set(int key, sk_sp<SkImageFilter> value);
sk_sp<SkImageFilter> static_sk_image_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_FILTER_H
