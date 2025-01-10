//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BLENDER_H
#define RAIA_SKIA_SK_BLENDER_H

#include "include/core/SkBlender.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_flattenable.h"
#include "../static/static_sk_flattenable_factory.h"

extern "C" {
void SkBlender_delete(SkBlender *blender);
sk_flattenable_factory_t SkBlender_getFactory(SkBlender *blender);
const char *SkBlender_getTypeName(SkBlender *blender);
void SkBlender_flatten(SkBlender *blender, SkWriteBuffer *write_buffer);
SkBlender::Type SkBlender_getFlattenableType(SkBlender *blender);
sk_data_t SkBlender_serialize(SkBlender *blender, const SkSerialProcs *serial_procs);
size_t SkBlender_serialize_2(SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkBlender_unique(SkBlender *blender);
void SkBlender_ref(SkBlender *blender);
void SkBlender_unref(SkBlender *blender);
// static
sk_blender_t SkBlender_Mode(SkBlendMode mode);
sk_flattenable_factory_t SkBlender_NameToFactory(const char name[]);
const char *SkBlender_FactoryToName(sk_flattenable_factory_t factory);
void SkBlender_Register(const char name[], sk_flattenable_factory_t factory);
sk_flattenable_t SkBlender_Deserialize(SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_BLENDER_H
