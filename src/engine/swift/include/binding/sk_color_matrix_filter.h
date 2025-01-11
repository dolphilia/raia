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
#include "export_api.h"

extern "C" {
RAIA_API void SkColorMatrixFilter_delete(SkColorMatrixFilter *color_matrix_filter);
RAIA_API bool SkColorMatrixFilter_asAColorMode(SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode);
RAIA_API bool SkColorMatrixFilter_asAColorMatrix(SkColorMatrixFilter *color_matrix_filter, float matrix[20]);
RAIA_API bool SkColorMatrixFilter_isAlphaUnchanged(SkColorMatrixFilter *color_matrix_filter);
RAIA_API SkColor SkColorMatrixFilter_filterColor(SkColorMatrixFilter *color_matrix_filter, SkColor color);
RAIA_API sk_color_4f_t SkColorMatrixFilter_filterColor4f(SkColorMatrixFilter *color_matrix_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
RAIA_API sk_color_filter_t SkColorMatrixFilter_makeComposed(SkColorMatrixFilter *color_matrix_filter, sk_color_filter_t colorFilter);
RAIA_API sk_color_filter_t SkColorMatrixFilter_makeWithWorkingColorSpace(SkColorMatrixFilter *color_matrix_filter, sk_color_space_t colorSpace);
RAIA_API sk_flattenable_factory_t SkColorMatrixFilter_getFactory(SkColorMatrixFilter *color_matrix_filter);
RAIA_API const char * SkColorMatrixFilter_getTypeName(SkColorMatrixFilter *color_matrix_filter);
RAIA_API void SkColorMatrixFilter_flatten(SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer);
RAIA_API SkColorMatrixFilter::Type SkColorMatrixFilter_getFlattenableType(SkColorMatrixFilter *color_matrix_filter);
RAIA_API sk_data_t SkColorMatrixFilter_serialize(SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs);
RAIA_API size_t SkColorMatrixFilter_serialize_2(SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
RAIA_API bool SkColorMatrixFilter_unique(SkColorMatrixFilter *color_matrix_filter);
RAIA_API void SkColorMatrixFilter_ref(SkColorMatrixFilter *color_matrix_filter);
RAIA_API void SkColorMatrixFilter_unref(SkColorMatrixFilter *color_matrix_filter);
// static
RAIA_API sk_color_filter_t SkColorMatrixFilter_MakeLightingFilter(SkColor mul, SkColor add);
RAIA_API sk_color_filter_t SkColorMatrixFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_flattenable_factory_t SkColorMatrixFilter_NameToFactory(const char name[]);
RAIA_API const char * SkColorMatrixFilter_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkColorMatrixFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_COLOR_MATRIX_FILTER_H
