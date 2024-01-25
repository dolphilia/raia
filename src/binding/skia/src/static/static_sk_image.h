//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_H
#define RAIA_SKIA_STATIC_SK_IMAGE_H

#include <string>
#include <map>
#include "include/core/SkImage.h"

int static_sk_image_make(sk_sp<SkImage> value);
void static_sk_image_delete(int key);
SkImage *static_sk_image_get(int key);
void static_sk_image_set(int key, sk_sp<SkImage> value);
sk_sp<SkImage> static_sk_image_move(int key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_H
