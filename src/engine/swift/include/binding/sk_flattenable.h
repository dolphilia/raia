//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FLATTENABLE_H
#define RAIA_SKIA_SK_FLATTENABLE_H

#include "include/core/SkFlattenable.h"
#include "../static/static_sk_flattenable.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_flattenable_factory.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkFlattenable_delete(SkFlattenable *flattenable);
RAIA_API sk_flattenable_factory_t SkFlattenable_getFactory(SkFlattenable *flattenable);
RAIA_API const char * SkFlattenable_getTypeName(SkFlattenable *flattenable);
RAIA_API void SkFlattenable_flatten(SkFlattenable *flattenable, SkWriteBuffer *write_buffer);
RAIA_API SkFlattenable::Type SkFlattenable_getFlattenableType(SkFlattenable *flattenable);
RAIA_API sk_data_t SkFlattenable_serialize(SkFlattenable *flattenable, const SkSerialProcs * serial_procs);
RAIA_API size_t SkFlattenable_serialize_2(SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs * serial_procs);
RAIA_API bool SkFlattenable_unique(SkFlattenable *flattenable);
RAIA_API void SkFlattenable_ref(SkFlattenable *flattenable);
RAIA_API void SkFlattenable_unref(SkFlattenable *flattenable);
// static
RAIA_API sk_flattenable_factory_t SkFlattenable_NameToFactory(const char name[]);
RAIA_API const char * SkFlattenable_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkFlattenable_Register(const char name[], sk_flattenable_factory_t factory);
RAIA_API int SkFlattenable_Deserialize(SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_FLATTENABLE_H
