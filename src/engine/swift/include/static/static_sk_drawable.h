//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkDrawable.h"
#include "export_api.h"

typedef int sk_drawable_t;

extern "C" {
RAIA_API void static_sk_drawable_delete(int key);
RAIA_API SkDrawable *static_sk_drawable_get(int key);
}

int static_sk_drawable_make(sk_sp<SkDrawable> value);
void static_sk_drawable_set(int key, sk_sp<SkDrawable> value);
sk_sp<SkDrawable> static_sk_drawable_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_H
