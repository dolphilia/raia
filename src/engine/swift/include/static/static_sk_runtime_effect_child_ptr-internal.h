#ifndef STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_INTERNAL_H
#define STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_INTERNAL_H
#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
// const
int static_const_sk_runtime_effect_child_ptr_make(SkSpan<const SkRuntimeEffect::ChildPtr> value);
SkSpan<const SkRuntimeEffect::ChildPtr> static_const_sk_runtime_effect_child_ptr_get_entity(int key);
void static_const_sk_runtime_effect_child_ptr_set(int key, SkSpan<const SkRuntimeEffect::ChildPtr> value);
#endif // STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_INTERNAL_H
