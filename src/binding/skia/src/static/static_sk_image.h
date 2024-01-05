//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_H
#define RAIA_SKIA_STATIC_SK_IMAGE_H

#include <string>
#include <map>
#include "include/core/SkImage.h"

void static_sk_image_delete(const char *key);
SkImage *static_sk_image_get(const char *key);
void static_sk_image_set(const char *key, sk_sp<SkImage> value);
sk_sp<SkImage> static_sk_image_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_H
