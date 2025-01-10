//
// Created by dolphilia on 2024/04/04.
//

#ifndef RAIA_SKIA_STATIC_SK_V2_H
#define RAIA_SKIA_STATIC_SK_V2_H

#include "../static/static_sk_m_44.h"
#include <set>
#include <map>

typedef int sk_v2_t;

int static_sk_v2_make(SkV2 value);
extern "C" void static_sk_v2_delete(int key);
SkV2 static_sk_v2_get(int key);
void static_sk_v2_set(int key, SkV2 value);

#endif //RAIA_SKIA_STATIC_SK_V2_H
