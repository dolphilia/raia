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
#include "../static/static_sk_runtime_effect_child_ptr.h"
#include "../static/static_sk_runtime_effect_result.h"
#include "../static/static_sk_runtime_effect_traced_shader.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_string.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"
#include "../static/static_std_string_view.h"

extern "C" {
void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect);
sk_shader_t SkRuntimeEffect_makeShader(SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix);
sk_shader_t SkRuntimeEffect_makeShader_2(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr, const SkMatrix *localMatrix);
sk_color_filter_t SkRuntimeEffect_makeColorFilter(SkRuntimeEffect *runtime_effect, sk_data_t data);
sk_color_filter_t SkRuntimeEffect_makeColorFilter_2(SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkColorFilter> children[], size_t childCount);
sk_color_filter_t SkRuntimeEffect_makeColorFilter_3(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr);
sk_blender_t SkRuntimeEffect_makeBlender(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr);
const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect);
size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect);
int SkRuntimeEffect_uniforms(SkRuntimeEffect *runtime_effect);
int SkRuntimeEffect_children(SkRuntimeEffect *runtime_effect);
const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, string_view_t name);
const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, string_view_t name);
bool SkRuntimeEffect_allowShader(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowColorFilter(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowBlender(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_unique(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_ref(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_unref(SkRuntimeEffect *runtime_effect);
// static
sk_runtime_effect_result_t SkRuntimeEffect_MakeForColorFilter(sk_string_t string, const SkRuntimeEffect::Options *options);
sk_runtime_effect_result_t SkRuntimeEffect_MakeForColorFilter_2(sk_string_t string);
sk_runtime_effect_result_t SkRuntimeEffect_MakeForShader(sk_string_t string, const SkRuntimeEffect::Options *options);
sk_runtime_effect_result_t SkRuntimeEffect_MakeForShader_2(sk_string_t string);
sk_runtime_effect_result_t SkRuntimeEffect_MakeForBlender(sk_string_t string, const SkRuntimeEffect::Options *options);
sk_runtime_effect_result_t SkRuntimeEffect_MakeForBlender_2(sk_string_t string);
sk_runtime_effect_result_t SkRuntimeEffect_MakeTraced(sk_shader_t shader, const SkIPoint *traceCoord);
void SkRuntimeEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_H
