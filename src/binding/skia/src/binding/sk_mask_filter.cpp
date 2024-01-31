//
// Created by dolphilia on 2024/01/09.
//

#include "sk_mask_filter.h"

extern "C" {

void SkMaskFilter_delete(SkMaskFilter *maskFilter) {
    delete maskFilter;
}

int SkMaskFilter_approximateFilteredBounds(SkMaskFilter *mask_filter, const SkRect *src) {
    return static_sk_rect_make(mask_filter->approximateFilteredBounds(*src));
}

SkMaskFilter::Factory SkMaskFilter_getFactory(SkMaskFilter *mask_filter) {
    return mask_filter->getFactory();
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

int SkMaskFilter_serialize(SkMaskFilter *mask_filter, const SkSerialProcs *procs) {
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

int SkMaskFilter_MakeBlur(SkBlurStyle style, SkScalar sigma, bool respectCTM) {
    return static_sk_mask_filter_make(SkMaskFilter::MakeBlur(style, sigma, respectCTM));
}

int SkMaskFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_mask_filter_make(SkMaskFilter::Deserialize(data, size, procs));
}

SkMaskFilter::Factory SkMaskFilter_NameToFactory(const char name[]) {
    return SkMaskFilter::NameToFactory(name);
}

const char * SkMaskFilter_FactoryToName(SkMaskFilter::Factory factory) {
    return SkMaskFilter::FactoryToName(factory);
}

void SkMaskFilter_Register(const char name[], SkMaskFilter::Factory factory) {
    SkMaskFilter::Register(name, factory);
}

}