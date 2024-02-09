//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PICTURE_H
#define RAIA_SKIA_STATIC_SK_PICTURE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPicture.h"

typedef int sk_picture_t;

int static_sk_picture_make(sk_sp<SkPicture> value);
extern "C" void static_sk_picture_delete(int key);
extern "C" SkPicture *static_sk_picture_get(int key);
void static_sk_picture_set(int key, sk_sp<SkPicture> value);
sk_sp<SkPicture> static_sk_picture_move(int key);

#endif //RAIA_SKIA_STATIC_SK_PICTURE_H
