//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_FILTER_H
#define RAIA_SKIA_SK_COLOR_FILTER_H

#include "include/core/SkColorFilter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_flattenable_factory.h"
#include "../static/static_sk_color_4f.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkColorFilter_delete(SkColorFilter *color_filter);
RAIA_API bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode);
RAIA_API bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]);
RAIA_API bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter);
RAIA_API SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color);
RAIA_API sk_color_4f_t SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
RAIA_API sk_color_filter_t SkColorFilter_makeComposed(SkColorFilter *color_filter, sk_color_filter_t inner);
RAIA_API sk_color_filter_t SkColorFilter_makeWithWorkingColorSpace(SkColorFilter *color_filter, sk_color_space_t colorSpace);
RAIA_API sk_flattenable_factory_t SkColorFilter_getFactory(SkColorFilter *color_filter);
RAIA_API const char *SkColorFilter_getTypeName(SkColorFilter *color_filter);
RAIA_API void SkColorFilter_flatten(SkColorFilter *color_filter, SkWriteBuffer *write_buffer);
RAIA_API SkColorFilter::Type SkColorFilter_getFlattenableType(SkColorFilter *color_filter);
RAIA_API sk_data_t SkColorFilter_serialize(SkColorFilter *color_filter, const SkSerialProcs *serial_procs);
RAIA_API size_t SkColorFilter_serialize_2(SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
RAIA_API bool SkColorFilter_unique(SkColorFilter *color_filter);
RAIA_API void SkColorFilter_ref(SkColorFilter *color_filter);
RAIA_API void SkColorFilter_unref(SkColorFilter *color_filter);
// static
RAIA_API sk_color_filter_t SkColorFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_flattenable_factory_t SkColorFilter_NameToFactory(const char name[]);
RAIA_API const char *SkColorFilter_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkColorFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_COLOR_FILTER_H
