#ifndef STATIC_SK_RUNTIME_EFFECT_UNIFORM_INTERNAL_H
#define STATIC_SK_RUNTIME_EFFECT_UNIFORM_INTERNAL_H
#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
// const
int static_const_sk_runtime_effect_uniform_make(SkSpan<const SkRuntimeEffect::Uniform> value);
SkSpan<const SkRuntimeEffect::Uniform> static_const_sk_runtime_effect_uniform_get(int key);
void static_const_sk_runtime_effect_uniform_set(int key, SkSpan<const SkRuntimeEffect::Uniform> value);
#endif // STATIC_SK_RUNTIME_EFFECT_UNIFORM_INTERNAL_H
