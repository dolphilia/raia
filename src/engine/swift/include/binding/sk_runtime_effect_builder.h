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
#include "../static/static_sk_runtime_effect_builder_builder_uniform.h"
#include "../static/static_sk_runtime_effect_builder_builder_child.h"
#include "../static/static_std_string_view.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkRuntimeEffectBuilder_delete(SkRuntimeEffectBuilder *runtime_effect_builder);
RAIA_API const SkRuntimeEffect * SkRuntimeEffectBuilder_effect(SkRuntimeEffectBuilder *runtime_effect_builder);
RAIA_API sk_runtime_effect_builder_builder_uniform_t SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name);
RAIA_API sk_runtime_effect_builder_builder_child_t SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name);
RAIA_API const_sk_data_t SkRuntimeEffectBuilder_uniforms(SkRuntimeEffectBuilder *runtime_effect_builder);
RAIA_API const_sk_runtime_effect_child_ptr_t SkRuntimeEffectBuilder_children(SkRuntimeEffectBuilder *runtime_effect_builder);
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
