//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MASK_FILTER_H
#define RAIA_SKIA_SK_MASK_FILTER_H

#include "include/core/SkMaskFilter.h"
#include "include/core/SkRect.h"
#include "include/core/SkData.h"
#include "../static/static_sk_mask_filter.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_flattenable_factory.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkMaskFilter_delete(SkMaskFilter *maskFilter);
RAIA_API sk_rect_t SkMaskFilter_approximateFilteredBounds(SkMaskFilter *mask_filter, const SkRect *src);
RAIA_API sk_flattenable_factory_t SkMaskFilter_getFactory(SkMaskFilter *mask_filter);
RAIA_API const char * SkMaskFilter_getTypeName(SkMaskFilter *mask_filter);
RAIA_API void SkMaskFilter_flatten(SkMaskFilter *mask_filter, SkWriteBuffer *buffer);
RAIA_API SkMaskFilter::Type SkMaskFilter_getFlattenableType(SkMaskFilter *mask_filter);
RAIA_API sk_data_t SkMaskFilter_serialize(SkMaskFilter *mask_filter, const SkSerialProcs *procs);
RAIA_API size_t SkMaskFilter_serialize_2(SkMaskFilter *mask_filter, void *memory, size_t memory_size, const SkSerialProcs *procs);
RAIA_API bool SkMaskFilter_unique(SkMaskFilter *mask_filter);
RAIA_API void SkMaskFilter_ref(SkMaskFilter *mask_filter);
RAIA_API void SkMaskFilter_unref(SkMaskFilter *mask_filter);
// static
RAIA_API sk_mask_filter_t SkMaskFilter_MakeBlur(SkBlurStyle style, SkScalar sigma, bool respectCTM);
RAIA_API sk_mask_filter_t SkMaskFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_flattenable_factory_t SkMaskFilter_NameToFactory(const char name[]);
RAIA_API const char * SkMaskFilter_FactoryToName(sk_flattenable_factory_t factory);
RAIA_API void SkMaskFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_MASK_FILTER_H
