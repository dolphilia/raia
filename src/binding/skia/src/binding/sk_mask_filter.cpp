//
// Created by dolphilia on 2024/01/09.
//

#include "sk_mask_filter.h"

extern "C" {

void SkMaskFilter_delete(SkMaskFilter *maskFilter) {
    delete maskFilter;
}

sk_rect_t SkMaskFilter_approximateFilteredBounds(SkMaskFilter *mask_filter, const SkRect *src) {
    return static_sk_rect_make(mask_filter->approximateFilteredBounds(*src));
}

sk_flattenable_factory_t SkMaskFilter_getFactory(SkMaskFilter *mask_filter) {
    return static_sk_flattenable_factory_make(mask_filter->getFactory());
}

const char * SkMaskFilter_getTypeName(SkMaskFilter *mask_filter) {
    return mask_filter->getTypeName();
}

void SkMaskFilter_flatten(SkMaskFilter *mask_filter, SkWriteBuffer *buffer) {
    return mask_filter->flatten(*buffer);
}

SkMaskFilter::Type SkMaskFilter_getFlattenableType(SkMaskFilter *mask_filter) {
    return mask_filter->getFlattenableType();
}

sk_data_t SkMaskFilter_serialize(SkMaskFilter *mask_filter, const SkSerialProcs *procs) {
    return static_sk_data_make(mask_filter->serialize(procs));
}

size_t SkMaskFilter_serialize_2(SkMaskFilter *mask_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return mask_filter->serialize(memory, memory_size, procs);
}

bool SkMaskFilter_unique(SkMaskFilter *mask_filter) {
    return mask_filter->unique();
}

void SkMaskFilter_ref(SkMaskFilter *mask_filter) {
    return mask_filter->ref();
}

void SkMaskFilter_unref(SkMaskFilter *mask_filter) {
    return mask_filter->unref();
}


// static

sk_mask_filter_t SkMaskFilter_MakeBlur(SkBlurStyle style, SkScalar sigma, bool respectCTM) {
    return static_sk_mask_filter_make(SkMaskFilter::MakeBlur(style, sigma, respectCTM));
}

sk_mask_filter_t SkMaskFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_mask_filter_make(SkMaskFilter::Deserialize(data, size, procs));
}

sk_flattenable_factory_t SkMaskFilter_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkMaskFilter::NameToFactory(name));
}

const char * SkMaskFilter_FactoryToName(sk_flattenable_factory_t factory) {
    return SkMaskFilter::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkMaskFilter_Register(const char name[], sk_flattenable_factory_t factory) {
    SkMaskFilter::Register(name, static_sk_flattenable_factory_get(factory));
}

}