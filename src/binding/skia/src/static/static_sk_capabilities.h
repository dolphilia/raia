//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CAPABILITIES_H
#define RAIA_SKIA_STATIC_SK_CAPABILITIES_H

#include <string>
#include <map>
#include "include/core/SkCapabilities.h"

void static_const_sk_capabilities_delete(const char *key);
const SkCapabilities *static_const_sk_capabilities_get(const char *key);
void static_const_sk_capabilities_set(const char *key, sk_sp<const SkCapabilities> value);
sk_sp<const SkCapabilities> static_const_sk_capabilities_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_CAPABILITIES_H
