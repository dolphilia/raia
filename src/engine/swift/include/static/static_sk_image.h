//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_H
#define RAIA_SKIA_STATIC_SK_IMAGE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkImage.h"
#include "export_api.h"

typedef int sk_image_t;

extern "C" {
RAIA_API void static_sk_image_delete(int key);
RAIA_API SkImage *static_sk_image_get(int key);
}

int static_sk_image_make(sk_sp<SkImage> value);
void static_sk_image_set(int key, sk_sp<SkImage> value);
sk_sp<SkImage> static_sk_image_move(int key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_H
