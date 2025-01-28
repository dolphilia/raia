//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
#define RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorMatrixFilter_delete(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter)
bool SkColorMatrixFilter_asAColorMode(void *color_matrix_filter, void *color, void *mode); // (SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode) -> bool
bool SkColorMatrixFilter_asAColorMatrix(void *color_matrix_filter, void * matrix); // (SkColorMatrixFilter *color_matrix_filter, float matrix[20]) -> bool
bool SkColorMatrixFilter_isAlphaUnchanged(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter) -> bool
unsigned int SkColorMatrixFilter_filterColor(void *color_matrix_filter, unsigned int color); // (SkColorMatrixFilter *color_matrix_filter, SkColor color) -> SkColor
int SkColorMatrixFilter_filterColor4f(void *color_matrix_filter, const void *srcColor, void *srcCS, void *dstCS); // (SkColorMatrixFilter *color_matrix_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) -> sk_color_4f_t
int SkColorMatrixFilter_makeComposed(void *color_matrix_filter, int colorFilter); // (SkColorMatrixFilter *color_matrix_filter, sk_color_filter_t colorFilter) -> sk_color_filter_t
int SkColorMatrixFilter_makeWithWorkingColorSpace(void *color_matrix_filter, int colorSpace); // (SkColorMatrixFilter *color_matrix_filter, sk_color_space_t colorSpace) -> sk_color_filter_t
int SkColorMatrixFilter_getFactory(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter) -> sk_flattenable_factory_t
const char * SkColorMatrixFilter_getTypeName(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter) -> const char *
void SkColorMatrixFilter_flatten(void *color_matrix_filter, void * write_buffer); // (SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer)
int SkColorMatrixFilter_getFlattenableType(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter) -> SkColorMatrixFilter::Type
int SkColorMatrixFilter_serialize(void *color_matrix_filter, const void *serial_procs); // (SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs) -> sk_data_t
unsigned long SkColorMatrixFilter_serialize_2(void *color_matrix_filter, void *memory, unsigned long memory_size, const void *serial_procs); // (SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
bool SkColorMatrixFilter_unique(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter) -> bool
void SkColorMatrixFilter_ref(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter)
void SkColorMatrixFilter_unref(void *color_matrix_filter); // (SkColorMatrixFilter *color_matrix_filter)

// static

int SkColorMatrixFilter_MakeLightingFilter(unsigned int mul, unsigned int add); // (SkColor mul, SkColor add) -> sk_color_filter_t
int SkColorMatrixFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_color_filter_t
int SkColorMatrixFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char * SkColorMatrixFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkColorMatrixFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
