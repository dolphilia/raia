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
#include "../static/static_sk_flattenable_factory.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkImageFilter_delete(SkImageFilter *image_filter);
RAIA_API sk_i_rect_t SkImageFilter_filterBounds(SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect);
RAIA_API bool SkImageFilter_isColorFilterNode(SkImageFilter *image_filter, SkColorFilter **filterPtr);
RAIA_API bool SkImageFilter_asColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr);
RAIA_API bool SkImageFilter_asAColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr);
RAIA_API int SkImageFilter_countInputs(SkImageFilter *image_filter);
RAIA_API const SkImageFilter * SkImageFilter_getInput(SkImageFilter *image_filter, int i);
RAIA_API sk_rect_t SkImageFilter_computeFastBounds(SkImageFilter *image_filter, const SkRect *bounds);
RAIA_API bool SkImageFilter_canComputeFastBounds(SkImageFilter *image_filter);
RAIA_API sk_image_filter_t SkImageFilter_makeWithLocalMatrix(SkImageFilter *image_filter, const SkMatrix *matrix);
RAIA_API sk_flattenable_factory_t SkImageFilter_getFactory(SkImageFilter *image_filter);
RAIA_API const char * SkImageFilter_getTypeName(SkImageFilter *image_filter);
RAIA_API void SkImageFilter_flatten(SkImageFilter *image_filter, SkWriteBuffer *buffer);
RAIA_API SkImageFilter::Type SkImageFilter_getFlattenableType(SkImageFilter *image_filter);
RAIA_API sk_data_t SkImageFilter_serialize(SkImageFilter *image_filter, const SkSerialProcs *procs);
RAIA_API size_t SkImageFilter_serialize_2(SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs);
RAIA_API bool SkImageFilter_unique(SkImageFilter *image_filter);
RAIA_API void SkImageFilter_ref(SkImageFilter *image_filter);
RAIA_API void SkImageFilter_unref(SkImageFilter *image_filter);
// static
RAIA_API sk_image_filter_t SkImageFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_flattenable_factory_t SkImageFilter_NameToFactory(const char name[]);
RAIA_API const char * SkImageFilter_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkImageFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_IMAGE_FILTER_H
