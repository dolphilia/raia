//
// Created by dolphilia on 2024/01/10.
//

#include "sk_path_effect.h"

extern "C" {

SkPathEffect::DashType SkPathEffect_asADash(SkPathEffect *path_effect, SkPathEffect::DashInfo *info) {
    return path_effect->asADash(info);
}

bool SkPathEffect_filterPath(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR) {
    return path_effect->filterPath(dst, *src, rec, cullR);
}

bool SkPathEffect_filterPath_2(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR, const SkMatrix *ctm) {
    return path_effect->filterPath(dst, *src, rec, cullR, *ctm);
}

bool SkPathEffect_needsCTM(SkPathEffect *path_effect) {
    return path_effect->needsCTM();
}

SkPathEffect::Factory SkPathEffect_getFactory(SkPathEffect *path_effect) {
    return path_effect->getFactory();
}

const char * SkPathEffect_getTypeName(SkPathEffect *path_effect) {
    return path_effect->getTypeName();
}

void SkPathEffect_flatten(SkPathEffect *path_effect, SkWriteBuffer *buffer) {
    path_effect->flatten(*buffer);
}

SkPathEffect::Type SkPathEffect_getFlattenableType(SkPathEffect *path_effect) {
    return path_effect->getFlattenableType();
}

void SkPathEffect_serialize(int sk_data_key_out, SkPathEffect *path_effect, const SkSerialProcs *procs) {
    static_sk_data_set(sk_data_key_out, path_effect->serialize(procs));
}

size_t SkPathEffect_serialize_2(SkPathEffect *path_effect, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return path_effect->serialize(memory, memory_size, procs);
}

bool SkPathEffect_unique(SkPathEffect *path_effect) {
    return path_effect->unique();
}

void SkPathEffect_ref(SkPathEffect *path_effect) {
    path_effect->ref();
}

void SkPathEffect_unref(SkPathEffect *path_effect) {
    path_effect->unref();
}

// static

void SkPathEffect_MakeSum(int sk_path_effect_key_out, int sk_path_effect_key_in, int sk_path_effect_key_in_2) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkPathEffect::MakeSum(static_sk_path_effect_move(sk_path_effect_key_in), static_sk_path_effect_move(sk_path_effect_key_in_2)));
}

void SkPathEffect_MakeCompose(int sk_path_effect_key_out, int sk_path_effect_key_in, int sk_path_effect_key_in_2) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkPathEffect::MakeCompose(static_sk_path_effect_move(sk_path_effect_key_in), static_sk_path_effect_move(sk_path_effect_key_in_2)));
}

SkFlattenable::Type SkPathEffect_GetFlattenableType() {
    return SkPathEffect::GetFlattenableType();
}

void SkPathEffect_Deserialize(int sk_path_effect_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkPathEffect::Deserialize(data, size, procs));
}

SkPathEffect::Factory SkPathEffect_NameToFactory(const char name[]) {
    return SkPathEffect::NameToFactory(name);
}

const char * SkPathEffect_FactoryToName(SkPathEffect::Factory factory) {
    return SkPathEffect::FactoryToName(factory);
}

void SkPathEffect_Register(const char name[], SkPathEffect::Factory factory) {
    SkPathEffect::Register(name, factory);
}

}