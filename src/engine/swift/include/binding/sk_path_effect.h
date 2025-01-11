//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_EFFECT_H

#include "include/core/SkPathEffect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_path_effect.h"
#include "../static/static_sk_flattenable_factory.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkPathEffect_delete(SkPathEffect * pathEffect);
RAIA_API SkPathEffect::DashType SkPathEffect_asADash(SkPathEffect *path_effect, SkPathEffect::DashInfo *info);
RAIA_API bool SkPathEffect_filterPath(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR);
RAIA_API bool SkPathEffect_filterPath_2(SkPathEffect *path_effect, SkPath *dst, const SkPath *src, SkStrokeRec *rec, const SkRect *cullR, const SkMatrix *ctm);
RAIA_API bool SkPathEffect_needsCTM(SkPathEffect *path_effect);
RAIA_API sk_flattenable_factory_t SkPathEffect_getFactory(SkPathEffect *path_effect);
RAIA_API const char * SkPathEffect_getTypeName(SkPathEffect *path_effect);
RAIA_API void SkPathEffect_flatten(SkPathEffect *path_effect, SkWriteBuffer *buffer);
RAIA_API SkPathEffect::Type SkPathEffect_getFlattenableType(SkPathEffect *path_effect);
RAIA_API sk_data_t SkPathEffect_serialize(SkPathEffect *path_effect, const SkSerialProcs *procs);
RAIA_API size_t SkPathEffect_serialize_2(SkPathEffect *path_effect, void *memory, size_t memory_size, const SkSerialProcs *procs);
RAIA_API bool SkPathEffect_unique(SkPathEffect *path_effect);
RAIA_API void SkPathEffect_ref(SkPathEffect *path_effect);
RAIA_API void SkPathEffect_unref(SkPathEffect *path_effect);
// static
RAIA_API sk_path_effect_t SkPathEffect_MakeSum(sk_path_effect_t first, sk_path_effect_t second);
RAIA_API sk_path_effect_t SkPathEffect_MakeCompose(sk_path_effect_t outer, sk_path_effect_t inner);
RAIA_API SkFlattenable::Type SkPathEffect_GetFlattenableType();
RAIA_API sk_path_effect_t SkPathEffect_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_flattenable_factory_t SkPathEffect_NameToFactory(const char name[]);
RAIA_API const char * SkPathEffect_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkPathEffect_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_PATH_EFFECT_H
