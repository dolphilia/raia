//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
#define RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H

#include "include/effects/SkColorMatrixFilter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_color_4f.h"
#include "../static/static_sk_flattenable_factory.h"

extern "C" {
void SkColorMatrixFilter_delete(SkColorMatrixFilter *color_matrix_filter);
bool SkColorMatrixFilter_asAColorMode(SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode);
bool SkColorMatrixFilter_asAColorMatrix(SkColorMatrixFilter *color_matrix_filter, float matrix[20]);
bool SkColorMatrixFilter_isAlphaUnchanged(SkColorMatrixFilter *color_matrix_filter);
SkColor SkColorMatrixFilter_filterColor(SkColorMatrixFilter *color_matrix_filter, SkColor color);
sk_color_4f_t SkColorMatrixFilter_filterColor4f(SkColorMatrixFilter *color_matrix_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
sk_color_filter_t SkColorMatrixFilter_makeComposed(SkColorMatrixFilter *color_matrix_filter, sk_color_filter_t colorFilter);
sk_color_filter_t SkColorMatrixFilter_makeWithWorkingColorSpace(SkColorMatrixFilter *color_matrix_filter, sk_color_space_t colorSpace);
sk_flattenable_factory_t SkColorMatrixFilter_getFactory(SkColorMatrixFilter *color_matrix_filter);
const char * SkColorMatrixFilter_getTypeName(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_flatten(SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer);
SkColorMatrixFilter::Type SkColorMatrixFilter_getFlattenableType(SkColorMatrixFilter *color_matrix_filter);
sk_data_t SkColorMatrixFilter_serialize(SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs);
size_t SkColorMatrixFilter_serialize_2(SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkColorMatrixFilter_unique(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_ref(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_unref(SkColorMatrixFilter *color_matrix_filter);
// static
sk_color_filter_t SkColorMatrixFilter_MakeLightingFilter(SkColor mul, SkColor add);
sk_color_filter_t SkColorMatrixFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
sk_flattenable_factory_t SkColorMatrixFilter_NameToFactory(const char name[]);
const char * SkColorMatrixFilter_FactoryToName(sk_flattenable_factory_t factory);
void SkColorMatrixFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
