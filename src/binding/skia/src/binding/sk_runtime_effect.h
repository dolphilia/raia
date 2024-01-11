//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_SK_RUNTIME_EFFECT_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_runtime_effect_uniform.h"
#include "../static/static_sk_runtime_effect_child.h"
#include "../static/static_sk_runtime_effect_result.h"
#include "../static/static_sk_runtime_effect_traced_shader.h"

extern "C" {
void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_makeShader(const char *sk_shader_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix);
void SkRuntimeEffect_makeShader_2(const char *sk_shader_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children, const SkMatrix *localMatrix);
void SkRuntimeEffect_makeColorFilter(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms);
void SkRuntimeEffect_makeColorFilter_2(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkColorFilter> children[], size_t childCount);
void SkRuntimeEffect_makeColorFilter_3(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children);
void SkRuntimeEffect_makeBlender(const char *sk_blender_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children);
const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect);
size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_uniforms(const char *sk_runtime_effect_uniform_key_out, SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_children(const char *sk_runtime_effect_child_key_out, SkRuntimeEffect *runtime_effect);
const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, std::string_view name);
const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, std::string_view name);
bool SkRuntimeEffect_allowShader(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowColorFilter(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowBlender(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_unique(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_ref(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_unref(SkRuntimeEffect *runtime_effect);
// static
void SkRuntimeEffect_MakeForColorFilter(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options);
void SkRuntimeEffect_MakeForColorFilter_2(const char *sk_runtime_effect_result_key_out, SkString sksl);
void SkRuntimeEffect_MakeForShader(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options);
void SkRuntimeEffect_MakeForShader_2(const char *sk_runtime_effect_result_key_out, SkString sksl);
void SkRuntimeEffect_MakeForBlender(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options);
void SkRuntimeEffect_MakeForBlender_2(const char *sk_runtime_effect_result_key_out, SkString sksl);
void SkRuntimeEffect_MakeTraced(const char *sk_runtime_effect_traced_shader_key_out, sk_sp<SkShader> shader, const SkIPoint &traceCoord);
void SkRuntimeEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_H