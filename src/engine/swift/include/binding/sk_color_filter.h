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

extern "C" {
void SkColorFilter_delete(SkColorFilter *color_filter);
bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode);
bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]);
bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter);
SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color);
sk_color_4f_t SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
sk_color_filter_t SkColorFilter_makeComposed(SkColorFilter *color_filter, sk_color_filter_t inner);
sk_color_filter_t SkColorFilter_makeWithWorkingColorSpace(SkColorFilter *color_filter, sk_color_space_t colorSpace);
sk_flattenable_factory_t SkColorFilter_getFactory(SkColorFilter *color_filter);
const char *SkColorFilter_getTypeName(SkColorFilter *color_filter);
void SkColorFilter_flatten(SkColorFilter *color_filter, SkWriteBuffer *write_buffer);
SkColorFilter::Type SkColorFilter_getFlattenableType(SkColorFilter *color_filter);
sk_data_t SkColorFilter_serialize(SkColorFilter *color_filter, const SkSerialProcs *serial_procs);
size_t SkColorFilter_serialize_2(SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkColorFilter_unique(SkColorFilter *color_filter);
void SkColorFilter_ref(SkColorFilter *color_filter);
void SkColorFilter_unref(SkColorFilter *color_filter);
// static
sk_color_filter_t SkColorFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
sk_flattenable_factory_t SkColorFilter_NameToFactory(const char name[]);
const char *SkColorFilter_FactoryToName(sk_flattenable_factory_t factory);
void SkColorFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_COLOR_FILTER_H
