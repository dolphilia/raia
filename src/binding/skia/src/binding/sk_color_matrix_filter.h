//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
#define RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H

#include "include/effects/SkColorMatrixFilter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_data.h"

extern "C" {
bool SkColorMatrixFilter_asAColorMode(SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode);
bool SkColorMatrixFilter_asAColorMatrix(SkColorMatrixFilter *color_matrix_filter, float matrix[20]);
bool SkColorMatrixFilter_isAlphaUnchanged(SkColorMatrixFilter *color_matrix_filter);
SkColor SkColorMatrixFilter_filterColor(SkColorMatrixFilter *color_matrix_filter, SkColor color);
SkColor4f SkColorMatrixFilter_filterColor4f(SkColorMatrixFilter *color_matrix_filter, const SkColor4f &srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
void SkColorMatrixFilter_makeComposed(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in, SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_makeWithWorkingColorSpace(const char *sk_color_filter_key_out, const char *sk_color_space_key_in, SkColorMatrixFilter *color_matrix_filter);
SkColorMatrixFilter::Factory SkColorMatrixFilter_getFactory(SkColorMatrixFilter *color_matrix_filter);
const char * SkColorMatrixFilter_getTypeName(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_flatten(SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer);
SkColorMatrixFilter::Type SkColorMatrixFilter_getFlattenableType(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_serialize(const char *sk_data_key_out, SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs);
size_t SkColorMatrixFilter_serialize_2(SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkColorMatrixFilter_unique(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_ref(SkColorMatrixFilter *color_matrix_filter);
void SkColorMatrixFilter_unref(SkColorMatrixFilter *color_matrix_filter);
// static
void SkColorMatrixFilter_MakeLightingFilter(const char *sk_color_filter_key_out, SkColor mul, SkColor add);
void SkColorMatrixFilter_Deserialize(const char *sk_color_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
SkColorMatrixFilter::Factory SkColorMatrixFilter_NameToFactory(const char name[]);
const char * SkColorMatrixFilter_FactoryToName(SkColorMatrixFilter::Factory factory);
void SkColorMatrixFilter_Register(const char name[], SkColorMatrixFilter::Factory factory);
}

#endif //RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
