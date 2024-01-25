//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FLATTENABLE_H
#define RAIA_SKIA_SK_FLATTENABLE_H

#include "include/core/SkFlattenable.h"
#include "../static/static_sk_flattenable.h"
#include "../static/static_sk_data.h"

extern "C" {
SkFlattenable::Factory SkFlattenable_getFactory(SkFlattenable *flattenable);
const char * SkFlattenable_getTypeName(SkFlattenable *flattenable);
void SkFlattenable_flatten(SkFlattenable *flattenable, SkWriteBuffer *write_buffer);
SkFlattenable::Type SkFlattenable_getFlattenableType(SkFlattenable *flattenable);
int SkFlattenable_serialize(SkFlattenable *flattenable, const SkSerialProcs * serial_procs);
size_t SkFlattenable_serialize_2(SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs * serial_procs);
bool SkFlattenable_unique(SkFlattenable *flattenable);
void SkFlattenable_ref(SkFlattenable *flattenable);
void SkFlattenable_unref(SkFlattenable *flattenable);
// static
SkFlattenable::Factory SkFlattenable_NameToFactory(const char name[]);
const char * SkFlattenable_FactoryToName(SkFlattenable::Factory factory);
void SkFlattenable_Register(const char name[], SkFlattenable::Factory factory);
int SkFlattenable_Deserialize(SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_FLATTENABLE_H
