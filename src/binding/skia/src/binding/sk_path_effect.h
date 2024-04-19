//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_EFFECT_H

#include "include/core/SkPathEffect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_path_effect.h"
#include "../static/static_sk_flattenable_factory.h"

extern "C" {
void SkPathEffect_delete(SkPathEffect * pathEffect);
SkPathEffect::DashType SkPathEffect_asADash(SkPathEffect *path_effect, SkPathEffect::DashInfo *info);
bool SkPathEffect_filterPath(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR);
bool SkPathEffect_filterPath_2(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR, const SkMatrix *ctm);
bool SkPathEffect_needsCTM(SkPathEffect *path_effect);
sk_flattenable_factory_t SkPathEffect_getFactory(SkPathEffect *path_effect);
const char * SkPathEffect_getTypeName(SkPathEffect *path_effect);
void SkPathEffect_flatten(SkPathEffect *path_effect, SkWriteBuffer *buffer);
SkPathEffect::Type SkPathEffect_getFlattenableType(SkPathEffect *path_effect);
sk_data_t SkPathEffect_serialize(SkPathEffect *path_effect, const SkSerialProcs *procs);
size_t SkPathEffect_serialize_2(SkPathEffect *path_effect, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkPathEffect_unique(SkPathEffect *path_effect);
void SkPathEffect_ref(SkPathEffect *path_effect);
void SkPathEffect_unref(SkPathEffect *path_effect);
// static
sk_path_effect_t SkPathEffect_MakeSum(sk_path_effect_t first, sk_path_effect_t second);
sk_path_effect_t SkPathEffect_MakeCompose(sk_path_effect_t outer, sk_path_effect_t inner);
SkFlattenable::Type SkPathEffect_GetFlattenableType();
sk_path_effect_t SkPathEffect_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
sk_flattenable_factory_t SkPathEffect_NameToFactory(const char name[]);
const char * SkPathEffect_FactoryToName(sk_flattenable_factory_t factory);
void SkPathEffect_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_PATH_EFFECT_H
