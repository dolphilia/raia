//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BLENDER_H
#define RAIA_SKIA_SK_BLENDER_H

#include "include/core/SkBlender.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_flattenable.h"

extern "C" {
SkBlender::Factory SkBlender_getFactory(SkBlender *blender);
const char *SkBlender_getTypeName(SkBlender *blender);
void SkBlender_flatten(SkBlender *blender, SkWriteBuffer *write_buffer);
SkBlender::Type SkBlender_getFlattenableType(SkBlender *blender);
void SkBlender_serialize(int sk_data_key_out, SkBlender *blender, const SkSerialProcs *serial_procs);
size_t SkBlender_serialize_2(SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkBlender_unique(SkBlender *blender);
void SkBlender_ref(SkBlender *blender);
void SkBlender_unref(SkBlender *blender);
// static
void SkBlender_Mode(int sk_blender_key_out, SkBlendMode mode);
SkBlender::Factory SkBlender_NameToFactory(const char name[]);
const char *SkBlender_FactoryToName(SkBlender::Factory factory);
void SkBlender_Register(const char name[], SkBlender::Factory factory);
void SkBlender_Deserialize(int sk_flattenable_key_out, SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_BLENDER_H
