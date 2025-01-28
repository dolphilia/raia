//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SHADER_H
#define RAIA_SKIA_SK_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkShader_delete(void *shader); // (SkShader *shader)
bool SkShader_isOpaque(void *shader); // (SkShader *shader) -> bool
void *SkShader_isAImage(void *shader, void *localMatrix, void * xy); // (SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]) -> SkImage *
bool SkShader_isAImage_2(void *shader); // (SkShader *shader) -> bool
int SkShader_makeWithLocalMatrix(void *shader, const void *matrix); // (SkShader *shader, const SkMatrix *matrix) -> sk_shader_t
int SkShader_makeWithColorFilter(void *shader, int color_filter); // (SkShader *shader, sk_color_filter_t color_filter) -> sk_shader_t
int SkShader_makeWithWorkingColorSpace(void *shader, int color_space); // (SkShader *shader, sk_color_space_t color_space) -> sk_shader_t
int SkShader_getFactory(void *shader); // (SkShader *shader) -> sk_flattenable_factory_t
const char *SkShader_getTypeName(void *shader); // (SkShader *shader) -> const char *
void SkShader_flatten(void *shader, void *buffer); // (SkShader *shader, SkWriteBuffer *buffer)
int SkShader_getFlattenableType(void *shader); // (SkShader *shader) -> SkShader::Type
int SkShader_serialize(void *shader, const void *procs); // (SkShader *shader, const SkSerialProcs *procs) -> sk_data_t
unsigned long SkShader_serialize_2(void *shader, void *memory, unsigned long memory_size, const void *procs); // (SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
bool SkShader_unique(void *shader); // (SkShader *shader) -> bool
void SkShader_ref(void *shader); // (SkShader *shader)
void SkShader_unref(void *shader); // (SkShader *shader)

// static

int SkShader_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char *SkShader_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkShader_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
int SkShader_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> sk_flattenable_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SHADER_H
