//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CAPABILITIES_H
#define RAIA_SKIA_STATIC_SK_CAPABILITIES_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkCapabilities.h"
#include "export_api.h"

typedef int const_sk_capabilities_t;

extern "C" {
RAIA_API void static_const_sk_capabilities_delete(int key);
RAIA_API const SkCapabilities *static_const_sk_capabilities_get(int key);
}

int static_const_sk_capabilities_make(sk_sp<const SkCapabilities> value);
void static_const_sk_capabilities_set(int key, sk_sp<const SkCapabilities> value);
sk_sp<const SkCapabilities> static_const_sk_capabilities_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CAPABILITIES_H
