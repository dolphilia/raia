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

int SkRuntimeEffect_makeShader(int sk_data_key_in, SkRuntimeEffect *runtime_effect, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix) {
    return static_sk_shader_make(runtime_effect->makeShader(static_const_sk_data_move(sk_data_key_in), children, childCount, localMatrix));
}

int SkRuntimeEffect_makeShader_2(int sk_data_key_in,
                             int sk_runtime_effect_child_ptr_key_in, SkRuntimeEffect *runtime_effect,
                             const SkMatrix *localMatrix) {
    return static_sk_shader_make(runtime_effect->makeShader(static_const_sk_data_move(sk_data_key_in), static_const_sk_runtime_effect_child_ptr_get(sk_runtime_effect_child_ptr_key_in), localMatrix));
}

int SkRuntimeEffect_makeColorFilter(int sk_data_key_in,
                                     SkRuntimeEffect *runtime_effect) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(sk_data_key_in)));
}

int SkRuntimeEffect_makeColorFilter_2(int sk_data_key_in,
                                       SkRuntimeEffect *runtime_effect, sk_sp<SkColorFilter> children[],
                                       size_t childCount) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(sk_data_key_in), children, childCount));
}

int SkRuntimeEffect_makeColorFilter_3(int sk_data_key_in,
                                       int sk_runtime_effect_child_ptr_key_in,
                                       SkRuntimeEffect *runtime_effect) {
    return static_sk_color_filter_make(runtime_effect->makeColorFilter(static_const_sk_data_move(sk_data_key_in), static_const_sk_runtime_effect_child_ptr_get(sk_runtime_effect_child_ptr_key_in)));
}

int SkRuntimeEffect_makeBlender(int sk_data_key_in,
                            int sk_runtime_effect_child_ptr_key_in, SkRuntimeEffect *runtime_effect) {
    return static_sk_blender_make(runtime_effect->makeBlender(static_const_sk_data_move(sk_data_key_in), static_const_sk_runtime_effect_child_ptr_get(sk_runtime_effect_child_ptr_key_in)));
}

const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect) {
    return &runtime_effect->source();
}

size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->uniformSize();
}

int SkRuntimeEffect_uniforms(SkRuntimeEffect *runtime_effect) {
    return static_const_sk_runtime_effect_uniform_make(runtime_effect->uniforms());
}

int SkRuntimeEffect_children(SkRuntimeEffect *runtime_effect) {
    return static_const_sk_runtime_effect_child_make(runtime_effect->children());
}

const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, std::string_view name) {
    return runtime_effect->findUniform(name);
}

const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, std::string_view name) {
    return runtime_effect->findChild(name);
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

int SkRuntimeEffect_MakeForColorFilter(int sk_string_key_in,
                                        const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForColorFilter(static_sk_string_get(sk_string_key_in), *options));
}

int SkRuntimeEffect_MakeForColorFilter_2(int sk_string_key_in) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForColorFilter(static_sk_string_get(sk_string_key_in)));
}

int SkRuntimeEffect_MakeForShader(int sk_string_key_in, const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForShader(static_sk_string_get(sk_string_key_in), *options));
}

int SkRuntimeEffect_MakeForShader_2(int sk_string_key_in) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForShader(static_sk_string_get(sk_string_key_in)));
}

int SkRuntimeEffect_MakeForBlender(int sk_string_key_in, const SkRuntimeEffect::Options *options) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForBlender(static_sk_string_get(sk_string_key_in), *options));
}

int SkRuntimeEffect_MakeForBlender_2(int sk_string_key_in) {
    return static_sk_runtime_effect_result_make(SkRuntimeEffect::MakeForBlender(static_sk_string_get(sk_string_key_in)));
}

int SkRuntimeEffect_MakeTraced(int sk_shader_key_in,
                                const SkIPoint *traceCoord) {
    return static_sk_runtime_effect_traced_shader_make(SkRuntimeEffect::MakeTraced(static_sk_shader_move(sk_shader_key_in), *traceCoord));
}

void SkRuntimeEffect_RegisterFlattenables() {
    SkRuntimeEffect::RegisterFlattenables();
}

}