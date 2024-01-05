//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PICTURE_H
#define RAIA_SKIA_STATIC_SK_PICTURE_H

#include <string>
#include <map>
#include "include/core/SkPicture.h"

void static_sk_picture_delete(const char *key);
SkPicture *static_sk_picture_get(const char *key);
void static_sk_picture_set(const char *key, sk_sp<SkPicture> value);
sk_sp<SkPicture> static_sk_picture_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_PICTURE_H
