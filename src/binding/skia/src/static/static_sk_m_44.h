//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_M_44_H
#define RAIA_SKIA_STATIC_SK_M_44_H

#include <string>
#include <map>
#include "include/core/SkM44.h"

void static_sk_m_44_delete(const char *key);
SkM44 static_sk_m_44_get(const char *key);
void static_sk_m_44_set(const char *key, SkM44 value);

#endif //RAIA_SKIA_STATIC_SK_M_44_H
