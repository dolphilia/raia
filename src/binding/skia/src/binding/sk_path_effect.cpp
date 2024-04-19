//
// Created by dolphilia on 2024/01/10.
//

#include "sk_path_effect.h"

extern "C" {

void SkPathEffect_delete(SkPathEffect * pathEffect) {
    delete pathEffect;
}

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

sk_flattenable_factory_t SkPathEffect_getFactory(SkPathEffect *path_effect) {
    return static_sk_flattenable_factory_make(path_effect->getFactory());
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

sk_data_t SkPathEffect_serialize(SkPathEffect *path_effect, const SkSerialProcs *procs) {
    return static_sk_data_make(path_effect->serialize(procs));
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

sk_path_effect_t SkPathEffect_MakeSum(sk_path_effect_t first, sk_path_effect_t second) {
    return static_sk_path_effect_make(SkPathEffect::MakeSum(static_sk_path_effect_move(first), static_sk_path_effect_move(second)));
}

sk_path_effect_t SkPathEffect_MakeCompose(sk_path_effect_t outer, sk_path_effect_t inner) {
    return static_sk_path_effect_make(SkPathEffect::MakeCompose(static_sk_path_effect_move(outer), static_sk_path_effect_move(inner)));
}

SkFlattenable::Type SkPathEffect_GetFlattenableType() {
    return SkPathEffect::GetFlattenableType();
}

sk_path_effect_t SkPathEffect_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_path_effect_make(SkPathEffect::Deserialize(data, size, procs));
}

sk_flattenable_factory_t SkPathEffect_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkPathEffect::NameToFactory(name));
}

const char * SkPathEffect_FactoryToName(sk_flattenable_factory_t factory) {
    return SkPathEffect::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkPathEffect_Register(const char name[], sk_flattenable_factory_t factory) {
    SkPathEffect::Register(name, static_sk_flattenable_factory_get(factory));
}

}