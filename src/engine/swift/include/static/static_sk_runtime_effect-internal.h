#ifndef STATIC_SK_RUNTIME_EFFECT_INTERNAL_H
#define STATIC_SK_RUNTIME_EFFECT_INTERNAL_H
#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
int static_sk_runtime_effect_make(sk_sp<SkRuntimeEffect> value);
void static_sk_runtime_effect_set(int key, sk_sp<SkRuntimeEffect> value);
sk_sp<SkRuntimeEffect> static_sk_runtime_effect_get_entity(int key);
#endif // STATIC_SK_RUNTIME_EFFECT_INTERNAL_H
