//
// Created by dolphilia on 2024/04/04.
//

#ifndef RAIA_SKIA_STATIC_SK_V4_H
#define RAIA_SKIA_STATIC_SK_V4_H

#include "../static/static_sk_m_44.h"
#include <set>
#include <map>

typedef int sk_v4_t;

int static_sk_v4_make(SkV4 value);
extern "C" void static_sk_v4_delete(int key);
SkV4 static_sk_v4_get(int key);
void static_sk_v4_set(int key, SkV4 value);

#endif //RAIA_SKIA_STATIC_SK_V4_H
