//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shader.h"

extern "C" {

void SkShader_delete(SkShader *shader) {
    delete shader;
}

bool SkShader_isOpaque(SkShader *shader) {
    return shader->isOpaque();
}

SkImage * SkShader_isAImage(SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]) {
    return shader->isAImage(localMatrix, xy);
}

bool SkShader_isAImage_2(SkShader *shader) {
    return shader->isAImage();
}

sk_shader_t SkShader_makeWithLocalMatrix(SkShader *shader, const SkMatrix *matrix) {
    return static_sk_shader_make(shader->makeWithLocalMatrix(*matrix));
}

sk_shader_t SkShader_makeWithColorFilter(SkShader *shader, sk_color_filter_t color_filter) {
    return static_sk_shader_make(shader->makeWithColorFilter(static_sk_color_filter_move(color_filter)));
}

sk_shader_t SkShader_makeWithWorkingColorSpace(SkShader *shader, sk_color_space_t color_space) {
    return static_sk_shader_make(shader->makeWithWorkingColorSpace(static_sk_color_space_move(color_space)));
}

sk_flattenable_factory_t SkShader_getFactory(SkShader *shader) {
    return static_sk_flattenable_factory_make(shader->getFactory());
}

const char * SkShader_getTypeName(SkShader *shader) {
    return shader->getTypeName();
}

void SkShader_flatten(SkShader *shader, SkWriteBuffer *buffer) {
    shader->flatten(*buffer);
}

SkShader::Type SkShader_getFlattenableType(SkShader *shader) {
    return shader->getFlattenableType();
}

sk_data_t SkShader_serialize(SkShader *shader, const SkSerialProcs *procs) {
    return static_sk_data_make(shader->serialize(procs));
}

size_t SkShader_serialize_2(SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return shader->serialize(memory, memory_size, procs);
}

bool SkShader_unique(SkShader *shader) {
    return shader->unique();
}

void SkShader_ref(SkShader *shader) {
    shader->ref();
}

void SkShader_unref(SkShader *shader) {
    shader->unref();
}

// static

sk_flattenable_factory_t SkShader_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkShader::NameToFactory(name));
}

const char * SkShader_FactoryToName(sk_flattenable_factory_t factory) {
    return SkShader::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkShader_Register(const char name[], sk_flattenable_factory_t factory) {
    SkShader::Register(name, static_sk_flattenable_factory_get(factory));
}

sk_flattenable_t SkShader_Deserialize(SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    return static_sk_flattenable_make(SkShader::Deserialize(type, data, length, procs));
}

}