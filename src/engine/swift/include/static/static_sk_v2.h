//
// Created by dolphilia on 2024/04/04.
//

#ifndef RAIA_SKIA_STATIC_SK_V2_H
#define RAIA_SKIA_STATIC_SK_V2_H

#include "../static/static_sk_m_44.h"
#include <set>
#include <map>
#include "export_api.h"

typedef int sk_v2_t;

extern "C" {
RAIA_API void static_sk_v2_delete(int key);
RAIA_API SkV2 * static_sk_v2_get_ptr(int key);
}

int static_sk_v2_make(SkV2 value);
SkV2 static_sk_v2_get(int key);
void static_sk_v2_set(int key, SkV2 value);

#endif //RAIA_SKIA_STATIC_SK_V2_H
