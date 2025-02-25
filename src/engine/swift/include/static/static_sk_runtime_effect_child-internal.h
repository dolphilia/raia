#ifndef STATIC_SK_RUNTIME_EFFECT_CHILD_INTERNAL_H
#define STATIC_SK_RUNTIME_EFFECT_CHILD_INTERNAL_H
#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
// const
int static_const_sk_runtime_effect_child_make(SkSpan<const SkRuntimeEffect::Child> value);
SkSpan<const SkRuntimeEffect::Child> static_const_sk_runtime_effect_child_get_entity(int key);
void static_const_sk_runtime_effect_child_set(int key, SkSpan<const SkRuntimeEffect::Child> value);
#endif // STATIC_SK_RUNTIME_EFFECT_CHILD_INTERNAL_H
