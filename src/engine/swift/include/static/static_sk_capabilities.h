//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CAPABILITIES_H
#define RAIA_SKIA_STATIC_SK_CAPABILITIES_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkCapabilities.h"

typedef int const_sk_capabilities_t;

int static_const_sk_capabilities_make(sk_sp<const SkCapabilities> value);
extern "C" void static_const_sk_capabilities_delete(int key);
extern "C" const SkCapabilities *static_const_sk_capabilities_get(int key);
void static_const_sk_capabilities_set(int key, sk_sp<const SkCapabilities> value);
sk_sp<const SkCapabilities> static_const_sk_capabilities_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CAPABILITIES_H
