//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_FILTER_H
#define RAIA_SKIA_SK_IMAGE_FILTER_H

#include "include/core/SkImageFilter.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkImageFilter_filterBounds(const char *sk_i_rect_key_out, SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect);
bool SkImageFilter_isColorFilterNode(SkImageFilter *image_filter, SkColorFilter **filterPtr);
bool SkImageFilter_asColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr);
bool SkImageFilter_asAColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr);
int SkImageFilter_countInputs(SkImageFilter *image_filter);
const SkImageFilter * SkImageFilter_getInput(SkImageFilter *image_filter, int i);
void SkImageFilter_computeFastBounds(const char *sk_rect_key_out, SkImageFilter *image_filter, const SkRect *bounds);
bool SkImageFilter_canComputeFastBounds(SkImageFilter *image_filter);
void SkImageFilter_makeWithLocalMatrix(const char *sk_image_filter_key_out, SkImageFilter *image_filter, const SkMatrix *matrix);
SkImageFilter::Factory SkImageFilter_getFactory(SkImageFilter *image_filter);
const char * SkImageFilter_getTypeName(SkImageFilter *image_filter);
void SkImageFilter_flatten(SkImageFilter *image_filter, SkWriteBuffer *buffer);
SkImageFilter::Type SkImageFilter_getFlattenableType(SkImageFilter *image_filter);
void SkImageFilter_serialize(const char *sk_data_key_out, SkImageFilter *image_filter, const SkSerialProcs *procs);
size_t SkImageFilter_serialize_2(SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkImageFilter_unique(SkImageFilter *image_filter);
void SkImageFilter_ref(SkImageFilter *image_filter);
void SkImageFilter_unref(SkImageFilter *image_filter);
// static
void SkImageFilter_Deserialize(const char *sk_image_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
SkImageFilter::Factory SkImageFilter_NameToFactory(const char name[]);
const char * SkImageFilter_FactoryToName(SkImageFilter::Factory factory);
void SkImageFilter_Register(const char name[], SkImageFilter::Factory factory);
}

#endif //RAIA_SKIA_SK_IMAGE_FILTER_H
