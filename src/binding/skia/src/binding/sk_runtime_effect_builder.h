//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"

extern "C" {
const SkRuntimeEffect * SkRuntimeEffectBuilder_effect(SkRuntimeEffectBuilder *runtime_effect_builder);
SkRuntimeEffectBuilder::BuilderUniform SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name);
SkRuntimeEffectBuilder::BuilderChild SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name);
void SkRuntimeEffectBuilder_uniforms(const char *sk_data_key_out, SkRuntimeEffectBuilder *runtime_effect_builder);
void SkRuntimeEffectBuilder_children(const char *sk_runtime_effect_child_ptr_key_out, SkRuntimeEffectBuilder *runtime_effect_builder);
// static
// SkRuntimeEffectBuilder()=delete
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect)
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect, sk_sp<SkData> uniforms)
// SkRuntimeEffectBuilder(SkRuntimeEffectBuilder &&)
// SkRuntimeEffectBuilder(const SkRuntimeEffectBuilder &)
// SkRuntimeEffectBuilder & operator=(SkRuntimeEffectBuilder &&)=delete
// SkRuntimeEffectBuilder & operator=(const SkRuntimeEffectBuilder &)=delete
}

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H