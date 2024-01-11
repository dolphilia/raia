//
// Created by dolphilia on 2024/01/05.
//

#include "sk_blender.h"

extern "C" {

SkBlender::Factory SkBlender_getFactory(SkBlender *blender) {
    return blender->getFactory();
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

void SkBlender_serialize(const char *sk_data_key_out, SkBlender *blender, const SkSerialProcs *serial_procs) {
    static_sk_data_set(sk_data_key_out, blender->serialize(serial_procs));
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

void SkBlender_Mode(const char *sk_blender_key_out, SkBlendMode mode) {
    static_sk_blender_set(sk_blender_key_out, SkBlender::Mode(mode));
}

SkBlender::Factory SkBlender_NameToFactory(const char name[]) {
    return SkBlender::NameToFactory(name);
}

const char *SkBlender_FactoryToName(SkBlender::Factory factory) {
    return SkBlender::FactoryToName(factory);
}

void SkBlender_Register(const char name[], SkBlender::Factory factory) {
    SkBlender::Register(name, factory);
}

void SkBlender_Deserialize(const char *sk_flattenable_key_out, SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    static_sk_flattenable_set(sk_flattenable_key_out, SkBlender::Deserialize(type, data, length, procs));
}

}