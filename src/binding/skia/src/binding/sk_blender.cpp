//
// Created by dolphilia on 2024/01/05.
//

#include "sk_blender.h"

extern "C" {

void SkBlender_delete(SkBlender *blender) {
    delete blender;
}

sk_flattenable_factory_t SkBlender_getFactory(SkBlender *blender) {
    return static_sk_flattenable_factory_make(blender->getFactory());
}

const char *SkBlender_getTypeName(SkBlender *blender) {
    return blender->getTypeName();
}

void SkBlender_flatten(SkBlender *blender, SkWriteBuffer *write_buffer) {
    blender->flatten(*write_buffer);
}

SkBlender::Type SkBlender_getFlattenableType(SkBlender *blender) {
    return blender->getFlattenableType();
}

sk_data_t SkBlender_serialize(SkBlender *blender, const SkSerialProcs *serial_procs) {
    return static_sk_data_make(blender->serialize(serial_procs));
}

size_t SkBlender_serialize_2(SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return blender->serialize(memory, memory_size, serial_procs);
}

bool SkBlender_unique(SkBlender *blender) {
    return blender->unique();
}

void SkBlender_ref(SkBlender *blender) {
    blender->ref();
}

void SkBlender_unref(SkBlender *blender) {
    blender->unref();
}

// static

sk_blender_t SkBlender_Mode(SkBlendMode mode) {
    return static_sk_blender_make(SkBlender::Mode(mode));
}

sk_flattenable_factory_t SkBlender_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkBlender::NameToFactory(name));
}

const char *SkBlender_FactoryToName(sk_flattenable_factory_t factory) {
    return SkBlender::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkBlender_Register(const char name[], sk_flattenable_factory_t factory) {
    SkBlender::Register(name, static_sk_flattenable_factory_get(factory));
}

sk_flattenable_t SkBlender_Deserialize(SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    return static_sk_flattenable_make(SkBlender::Deserialize(type, data, length, procs));
}

}