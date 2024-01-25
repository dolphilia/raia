//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SHADER_H
#define RAIA_SKIA_SK_SHADER_H

#include <utility>
#include "include/core/SkShader.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_flattenable.h"

extern "C" {
bool SkShader_isOpaque(SkShader *shader);
SkImage * SkShader_isAImage(SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]);
bool SkShader_isAImage_2(SkShader *shader);
void SkShader_makeWithLocalMatrix(int sk_shader_key_out, SkShader *shader, const SkMatrix *matrix);
void SkShader_makeWithColorFilter(int sk_shader_key_out, int sk_color_filter_key_in, SkShader *shader);
void
SkShader_makeWithWorkingColorSpace(int sk_shader_key_out, int sk_color_space_key_in, SkShader *shader);
SkShader::Factory SkShader_getFactory(SkShader *shader);
const char * SkShader_getTypeName(SkShader *shader);
void SkShader_flatten(SkShader *shader, SkWriteBuffer *buffer);
SkShader::Type SkShader_getFlattenableType(SkShader *shader);
void SkShader_serialize(int sk_data_key_out, SkShader *shader, const SkSerialProcs *procs);
size_t SkShader_serialize_2(SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkShader_unique(SkShader *shader);
void SkShader_ref(SkShader *shader);
void SkShader_unref(SkShader *shader);
// static
SkShader::Factory SkShader_NameToFactory(const char name[]);
const char * SkShader_FactoryToName(SkShader::Factory factory);
void SkShader_Register(const char name[], SkShader::Factory factory);
void SkShader_Deserialize(int sk_flattenable_key_out, SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_SHADER_H
