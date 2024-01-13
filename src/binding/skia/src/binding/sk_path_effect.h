//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_EFFECT_H

#include "include/core/SkPathEffect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_path_effect.h"

extern "C" {
SkPathEffect::DashType SkPathEffect_asADash(SkPathEffect *path_effect, SkPathEffect::DashInfo *info);
bool SkPathEffect_filterPath(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR);
bool SkPathEffect_filterPath_2(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR, const SkMatrix *ctm);
bool SkPathEffect_needsCTM(SkPathEffect *path_effect);
SkPathEffect::Factory SkPathEffect_getFactory(SkPathEffect *path_effect);
const char * SkPathEffect_getTypeName(SkPathEffect *path_effect);
void SkPathEffect_flatten(SkPathEffect *path_effect, SkWriteBuffer *buffer);
SkPathEffect::Type SkPathEffect_getFlattenableType(SkPathEffect *path_effect);
void SkPathEffect_serialize(const char *sk_data_key_out, SkPathEffect *path_effect, const SkSerialProcs *procs);
size_t SkPathEffect_serialize_2(SkPathEffect *path_effect, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkPathEffect_unique(SkPathEffect *path_effect);
void SkPathEffect_ref(SkPathEffect *path_effect);
void SkPathEffect_unref(SkPathEffect *path_effect);
// static
void SkPathEffect_MakeSum(const char *sk_path_effect_key_out, const char *sk_path_effect_key_in, const char *sk_path_effect_key_in_2);
void SkPathEffect_MakeCompose(const char *sk_path_effect_key_out, const char *sk_path_effect_key_in, const char *sk_path_effect_key_in_2);
SkFlattenable::Type SkPathEffect_GetFlattenableType();
void SkPathEffect_Deserialize(const char *sk_path_effect_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
SkPathEffect::Factory SkPathEffect_NameToFactory(const char name[]);
const char * SkPathEffect_FactoryToName(SkPathEffect::Factory factory);
void SkPathEffect_Register(const char name[], SkPathEffect::Factory factory);
}

#endif //RAIA_SKIA_SK_PATH_EFFECT_H
