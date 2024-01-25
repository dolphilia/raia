//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_H

#include <string>
#include <map>
#include "include/core/SkDrawable.h"

void static_sk_drawable_delete(int key);
SkDrawable *static_sk_drawable_get(int key);
void static_sk_drawable_set(int key, sk_sp<SkDrawable> value);
sk_sp<SkDrawable> static_sk_drawable_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_H
