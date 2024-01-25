//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_FILTER_H
#define RAIA_SKIA_SK_COLOR_FILTER_H

#include "include/core/SkColorFilter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_data.h"

extern "C" {
bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode);
bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]);
bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter);
SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color);
SkColor4f SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS);
void SkColorFilter_makeComposed(int sk_color_filter_key_out, int sk_color_filter_key_in, SkColorFilter *color_filter);
void SkColorFilter_makeWithWorkingColorSpace(int sk_color_filter_key_out, int sk_color_space_key_in, SkColorFilter *color_filter);
SkColorFilter::Factory SkColorFilter_getFactory(SkColorFilter *color_filter);
const char *SkColorFilter_getTypeName(SkColorFilter *color_filter);
void SkColorFilter_flatten(SkColorFilter *color_filter, SkWriteBuffer *write_buffer);
SkColorFilter::Type SkColorFilter_getFlattenableType(SkColorFilter *color_filter);
void SkColorFilter_serialize(int sk_data_key_out, SkColorFilter *color_filter, const SkSerialProcs *serial_procs);
size_t SkColorFilter_serialize_2(SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkColorFilter_unique(SkColorFilter *color_filter);
void SkColorFilter_ref(SkColorFilter *color_filter);
void SkColorFilter_unref(SkColorFilter *color_filter);
// static
void SkColorFilter_Deserialize(int sk_color_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
SkColorFilter::Factory SkColorFilter_NameToFactory(const char name[]);
const char *SkColorFilter_FactoryToName(SkColorFilter::Factory factory);
void SkColorFilter_Register(const char name[], SkColorFilter::Factory factory);
}

#endif //RAIA_SKIA_SK_COLOR_FILTER_H
