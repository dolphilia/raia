//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FLATTENABLE_H
#define RAIA_SKIA_SK_FLATTENABLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkFlattenable_delete(void *flattenable); // (SkFlattenable *flattenable)
int SkFlattenable_getFactory(void *flattenable); // (SkFlattenable *flattenable) -> sk_flattenable_factory_t
const char * SkFlattenable_getTypeName(void *flattenable); // (SkFlattenable *flattenable) -> const char *
void SkFlattenable_flatten(void *flattenable, void *write_buffer); // (SkFlattenable *flattenable, SkWriteBuffer *write_buffer)
int SkFlattenable_getFlattenableType(void *flattenable); // (SkFlattenable *flattenable) -> SkFlattenable::Type
int SkFlattenable_serialize(void *flattenable, const void * serial_procs); // (SkFlattenable *flattenable, const SkSerialProcs *serial_procs) -> sk_data_t
unsigned long SkFlattenable_serialize_2(void *flattenable, void *memory, unsigned long memory_size, const void * serial_procs); // (SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
bool SkFlattenable_unique(void *flattenable); // (SkFlattenable *flattenable) -> bool
void SkFlattenable_ref(void *flattenable); // (SkFlattenable *flattenable)
void SkFlattenable_unref(void *flattenable); // (SkFlattenable *flattenable)

// static

int SkFlattenable_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char * SkFlattenable_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkFlattenable_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
int SkFlattenable_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FLATTENABLE_H
