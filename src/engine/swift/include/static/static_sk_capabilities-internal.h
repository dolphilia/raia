#ifndef STATIC_SK_CAPABILITIES_INTERNAL_H
#define STATIC_SK_CAPABILITIES_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkCapabilities.h"
int static_const_sk_capabilities_make(sk_sp<const SkCapabilities> value);
void static_const_sk_capabilities_set(int key, sk_sp<const SkCapabilities> value);
sk_sp<const SkCapabilities> static_const_sk_capabilities_move(int key);
#endif // STATIC_SK_CAPABILITIES_INTERNAL_H
