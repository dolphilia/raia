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
#include "../static/static_sk_flattenable_factory.h"

extern "C" {
void SkShader_delete(SkShader *shader);
bool SkShader_isOpaque(SkShader *shader);
SkImage * SkShader_isAImage(SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]);
bool SkShader_isAImage_2(SkShader *shader);
sk_shader_t SkShader_makeWithLocalMatrix(SkShader *shader, const SkMatrix *matrix);
sk_shader_t SkShader_makeWithColorFilter(SkShader *shader, sk_color_filter_t color_filter);
sk_shader_t SkShader_makeWithWorkingColorSpace(SkShader *shader, sk_color_space_t color_space);
sk_flattenable_factory_t SkShader_getFactory(SkShader *shader);
const char * SkShader_getTypeName(SkShader *shader);
void SkShader_flatten(SkShader *shader, SkWriteBuffer *buffer);
SkShader::Type SkShader_getFlattenableType(SkShader *shader);
sk_data_t SkShader_serialize(SkShader *shader, const SkSerialProcs *procs);
size_t SkShader_serialize_2(SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkShader_unique(SkShader *shader);
void SkShader_ref(SkShader *shader);
void SkShader_unref(SkShader *shader);
// static
sk_flattenable_factory_t SkShader_NameToFactory(const char name[]);
const char * SkShader_FactoryToName(sk_flattenable_factory_t factory);
void SkShader_Register(const char name[], sk_flattenable_factory_t factory);
sk_flattenable_t SkShader_Deserialize(SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_SHADER_H
