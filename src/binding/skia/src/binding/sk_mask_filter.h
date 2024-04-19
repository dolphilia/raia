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

extern "C" {
void SkMaskFilter_delete(SkMaskFilter *maskFilter);
sk_rect_t SkMaskFilter_approximateFilteredBounds(SkMaskFilter *mask_filter, const SkRect *src);
sk_flattenable_factory_t SkMaskFilter_getFactory(SkMaskFilter *mask_filter);
const char * SkMaskFilter_getTypeName(SkMaskFilter *mask_filter);
void SkMaskFilter_flatten(SkMaskFilter *mask_filter, SkWriteBuffer *buffer);
SkMaskFilter::Type SkMaskFilter_getFlattenableType(SkMaskFilter *mask_filter);
sk_data_t SkMaskFilter_serialize(SkMaskFilter *mask_filter, const SkSerialProcs *procs);
size_t SkMaskFilter_serialize_2(SkMaskFilter *mask_filter, void *memory, size_t memory_size, const SkSerialProcs *procs);
bool SkMaskFilter_unique(SkMaskFilter *mask_filter);
void SkMaskFilter_ref(SkMaskFilter *mask_filter);
void SkMaskFilter_unref(SkMaskFilter *mask_filter);
// static
sk_mask_filter_t SkMaskFilter_MakeBlur(SkBlurStyle style, SkScalar sigma, bool respectCTM);
sk_mask_filter_t SkMaskFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
sk_flattenable_factory_t SkMaskFilter_NameToFactory(const char name[]);
const char * SkMaskFilter_FactoryToName(sk_flattenable_factory_t factory);
void SkMaskFilter_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_MASK_FILTER_H
