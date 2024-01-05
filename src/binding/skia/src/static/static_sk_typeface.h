//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TYPEFACE_H
#define RAIA_SKIA_STATIC_SK_TYPEFACE_H

#include <string>
#include <map>
#include "include/core/SkTypeface.h"

void static_sk_typeface_delete(const char *key);
SkTypeface *static_sk_typeface_get(const char *key);
void static_sk_typeface_set(const char *key, sk_sp<SkTypeface> value);
sk_sp<SkTypeface> static_sk_typeface_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_TYPEFACE_H