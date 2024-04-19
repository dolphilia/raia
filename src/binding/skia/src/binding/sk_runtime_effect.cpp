//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_effect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_string.h"

extern "C" {

void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect) {
    delete runtime_effect;
}

sk_shader_t SkRuntimeEffect_makeShader(SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix) {
    return static_sk_shader_make(runtime_effect->makeShader(static_const_sk_data_move(data), children, childCount, localMatrix));
}

sk_shader_t SkRuntimeEffect_makeShader_2(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr, const SkMatrix *localMatrix) {
    return static_sk_shader_make(runtime_effect->makeShader(static_const_sk_data_move(data), static_const_sk_runtime_effect_child_ptr_get(runtime_effect_child_ptr), localMatrix));
}

sk_color_filter_t SkRuntimeEffect_makeColorFilter(SkRuntimeEffect *runtime_effect, sk_data_t data) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(data)));
}

sk_color_filter_t SkRuntimeEffect_makeColorFilter_2(SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkColorFilter> children[], size_t childCount) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(data), children, childCount));
}

sk_color_filter_t SkRuntimeEffect_makeColorFilter_3(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(data), static_const_sk_runtime_effect_child_ptr_get(runtime_effect_child_ptr)));
}

sk_blender_t SkRuntimeEffect_makeBlender(SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr) {
    return static_sk_blender_make(runtime_effect->makeBlender(static_const_sk_data_move(data), static_const_sk_runtime_effect_child_ptr_get(runtime_effect_child_ptr)));
}

const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect) {
    return &runtime_effect->source();
}

size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->uniformSize();
}

const_sk_runtime_effect_uniform_t SkRuntimeEffect_uniforms(SkRuntimeEffect *runtime_effect) {
    return static_const_sk_runtime_effect_uniform_make(runtime_effect->uniforms());
}

const_sk_runtime_effect_child_t SkRuntimeEffect_children(SkRuntimeEffect *runtime_effect) {
    return static_const_sk_runtime_effect_child_make(runtime_effect->children());
}

const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, string_view_t name) {
    return runtime_effect->findUniform(static_string_view_get(name));
}

const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, string_view_t name) {
    return runtime_effect->findChild(static_string_view_get(name));
}

bool SkRuntimeEffect_allowShader(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowShader();
}

bool SkRuntimeEffect_allowColorFilter(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowColorFilter();
}

bool SkRuntimeEffect_allowBlender(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowBlender();
}

bool SkRuntimeEffect_unique(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->unique();
}

void SkRuntimeEffect_ref(SkRuntimeEffect *runtime_effect) {
    runtime_effect->ref();
}

void SkRuntimeEffect_unref(SkRuntimeEffect *runtime_effect) {
    runtime_effect->unref();
}

// static

sk_runtime_effect_result_t SkRuntimeEffect_MakeForColorFilter(sk_string_t string, const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForColorFilter(static_sk_string_get(string), *options));
}

sk_runtime_effect_result_t SkRuntimeEffect_MakeForColorFilter_2(sk_string_t string) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForColorFilter(static_sk_string_get(string)));
}

sk_runtime_effect_result_t SkRuntimeEffect_MakeForShader(sk_string_t string, const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForShader(static_sk_string_get(string), *options));
}

sk_runtime_effect_result_t SkRuntimeEffect_MakeForShader_2(sk_string_t string) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForShader(static_sk_string_get(string)));
}

sk_runtime_effect_result_t SkRuntimeEffect_MakeForBlender(sk_string_t string, const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForBlender(static_sk_string_get(string), *options));
}

sk_runtime_effect_result_t SkRuntimeEffect_MakeForBlender_2(sk_string_t string) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForBlender(static_sk_string_get(string)));
}

sk_runtime_effect_traced_shader_t SkRuntimeEffect_MakeTraced(sk_shader_t shader, const SkIPoint *traceCoord) {
    return static_sk_runtime_effect_traced_shader_make(SkRuntimeEffect::MakeTraced(static_sk_shader_move(shader), *traceCoord));
}

void SkRuntimeEffect_RegisterFlattenables() {
    SkRuntimeEffect::RegisterFlattenables();
}

}