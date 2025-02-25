#ifndef STATIC_SK_RUNTIME_EFFECT_RESULT_INTERNAL_H
#define STATIC_SK_RUNTIME_EFFECT_RESULT_INTERNAL_H
#include <set>
#include <map>
#include <utility>
#include "include/effects/SkRuntimeEffect.h"
// const
int static_sk_runtime_effect_result_make(SkRuntimeEffect::Result value);
SkRuntimeEffect::Result static_sk_runtime_effect_result_get_entity(int key);
void static_sk_runtime_effect_result_set(int key, SkRuntimeEffect::Result value);
#endif // STATIC_SK_RUNTIME_EFFECT_RESULT_INTERNAL_H
