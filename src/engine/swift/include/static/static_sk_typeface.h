//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TYPEFACE_H
#define RAIA_SKIA_STATIC_SK_TYPEFACE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkTypeface.h"
#include "export_api.h"

typedef int sk_typeface_t;

extern "C" {
RAIA_API void static_sk_typeface_delete(int key);
RAIA_API SkTypeface *static_sk_typeface_get(int key);
}

int static_sk_typeface_make(sk_sp<SkTypeface> value);
void static_sk_typeface_set(int key, sk_sp<SkTypeface> value);
sk_sp<SkTypeface> static_sk_typeface_move(int key);

#endif //RAIA_SKIA_STATIC_SK_TYPEFACE_H
