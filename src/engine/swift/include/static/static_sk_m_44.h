//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_M_44_H
#define RAIA_SKIA_STATIC_SK_M_44_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkM44.h"
#include "export_api.h"

typedef int sk_m_44_t;

extern "C" {
RAIA_API void static_sk_m_44_delete(int key);
RAIA_API SkM44 * static_sk_m_44_get_ptr(int key);
}

int static_sk_m_44_make(SkM44 value);
SkM44 static_sk_m_44_get(int key);
void static_sk_m_44_set(int key, SkM44 value);

#endif //RAIA_SKIA_STATIC_SK_M_44_H
