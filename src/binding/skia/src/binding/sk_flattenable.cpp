//
// Created by dolphilia on 2024/01/08.
//

#include "sk_flattenable.h"

extern "C" {

void SkFlattenable_delete(SkFlattenable *flattenable) {
    delete flattenable;
}

sk_flattenable_factory_t SkFlattenable_getFactory(SkFlattenable *flattenable) {
    return static_sk_flattenable_factory_make(flattenable->getFactory());
}

const char * SkFlattenable_getTypeName(SkFlattenable *flattenable) {
    return flattenable->getTypeName();
}

void SkFlattenable_flatten(SkFlattenable *flattenable, SkWriteBuffer * write_buffer) {
    flattenable->flatten(*write_buffer);
}

SkFlattenable::Type SkFlattenable_getFlattenableType(SkFlattenable *flattenable) {
    return flattenable->getFlattenableType();
}

sk_data_t SkFlattenable_serialize(SkFlattenable *flattenable, const SkSerialProcs * serial_procs) {
    return static_sk_data_make(flattenable->serialize(serial_procs));
}

size_t SkFlattenable_serialize_2(SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs * serial_procs) {
    return flattenable->serialize(memory, memory_size, serial_procs);
}

bool SkFlattenable_unique(SkFlattenable *flattenable) {
    return flattenable->unique();
}

void SkFlattenable_ref(SkFlattenable *flattenable) {
    flattenable->ref();
}

void SkFlattenable_unref(SkFlattenable *flattenable) {
    flattenable->unref();
}

// static

sk_flattenable_factory_t SkFlattenable_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkFlattenable::NameToFactory(name));
}

const char * SkFlattenable_FactoryToName(sk_flattenable_factory_t factory) {
    return SkFlattenable::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkFlattenable_Register(const char name[], sk_flattenable_factory_t factory) {
    SkFlattenable::Register(name, static_sk_flattenable_factory_get(factory));
}

sk_flattenable_t SkFlattenable_Deserialize(SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    return static_sk_flattenable_make(SkFlattenable::Deserialize(type, data, length, procs));
}

}