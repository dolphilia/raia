//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_effect.h"

extern "C" {

void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect) {
    delete runtime_effect;
}

void SkRuntimeEffect_makeShader(const char *sk_shader_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, runtime_effect->makeShader(std::move(uniforms), children, childCount, localMatrix));
}

void SkRuntimeEffect_makeShader_2(const char *sk_shader_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, runtime_effect->makeShader(std::move(uniforms), children, localMatrix));
}

void SkRuntimeEffect_makeColorFilter(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms) {
    static_sk_color_filter_set(sk_color_filter_key_out, runtime_effect->makeColorFilter(std::move(uniforms)));
}

void SkRuntimeEffect_makeColorFilter_2(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkColorFilter> children[], size_t childCount) {
    static_sk_color_filter_set(sk_color_filter_key_out, runtime_effect->makeColorFilter(std::move(uniforms), children, childCount));
}

void SkRuntimeEffect_makeColorFilter_3(const char *sk_color_filter_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children) {
    static_sk_color_filter_set(sk_color_filter_key_out, runtime_effect->makeColorFilter(std::move(uniforms), children));
}

void SkRuntimeEffect_makeBlender(const char *sk_blender_key_out, SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children) {
    static_sk_blender_set(sk_blender_key_out, runtime_effect->makeBlender(std::move(uniforms), children));
}

const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect) {
    return &runtime_effect->source();
}

size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->uniformSize();
}

void SkRuntimeEffect_uniforms(const char *sk_runtime_effect_uniform_key_out, SkRuntimeEffect *runtime_effect) {
    static_const_sk_runtime_effect_uniform_set(sk_runtime_effect_uniform_key_out, runtime_effect->uniforms());
}

void SkRuntimeEffect_children(const char *sk_runtime_effect_child_key_out, SkRuntimeEffect *runtime_effect) {
    static_const_sk_runtime_effect_child_set(sk_runtime_effect_child_key_out, runtime_effect->children());
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

void SkRuntimeEffect_MakeForColorFilter(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForColorFilter(std::move(sksl), options));
}

void SkRuntimeEffect_MakeForColorFilter_2(const char *sk_runtime_effect_result_key_out, SkString sksl) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForColorFilter(std::move(sksl)));
}

void SkRuntimeEffect_MakeForShader(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForShader(std::move(sksl), options));
}

void SkRuntimeEffect_MakeForShader_2(const char *sk_runtime_effect_result_key_out, SkString sksl) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForShader(std::move(sksl)));
}

void SkRuntimeEffect_MakeForBlender(const char *sk_runtime_effect_result_key_out, SkString sksl, const SkRuntimeEffect::Options &options) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForBlender(std::move(sksl), options));
}

void SkRuntimeEffect_MakeForBlender_2(const char *sk_runtime_effect_result_key_out, SkString sksl) {
    static_sk_runtime_effect_result_set(sk_runtime_effect_result_key_out, SkRuntimeEffect::MakeForBlender(std::move(sksl)));
}

void SkRuntimeEffect_MakeTraced(const char *sk_runtime_effect_traced_shader_key_out, sk_sp<SkShader> shader, const SkIPoint &traceCoord) {
    static_sk_runtime_effect_traced_shader_set(sk_runtime_effect_traced_shader_key_out, SkRuntimeEffect::MakeTraced(std::move(shader), traceCoord));
}

void SkRuntimeEffect_RegisterFlattenables() {
    SkRuntimeEffect::RegisterFlattenables();
}

}