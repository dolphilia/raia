//
// Created by dolphilia on 2024/01/09.
//

#include "sk_mask_filter.h"

extern "C" {

void SkMaskFilter_approximateFilteredBounds(const char* sk_rect_key_out, SkMaskFilter *mask_filter, const SkRect *src) {
    static_sk_rect_set(sk_rect_key_out, mask_filter->approximateFilteredBounds(*src));
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

void SkMaskFilter_serialize(const char *sk_data_key_out, SkMaskFilter *mask_filter, const SkSerialProcs *procs) {
    static_sk_data_set(sk_data_key_out, mask_filter->serialize(procs));
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

void SkMaskFilter_MakeBlur(const char *sk_mask_filter_key_out, SkBlurStyle style, SkScalar sigma, bool respectCTM) {
    static_sk_mask_filter_set(sk_mask_filter_key_out, SkMaskFilter::MakeBlur(style, sigma, respectCTM));
}

void SkMaskFilter_Deserialize(const char *sk_mask_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_mask_filter_set(sk_mask_filter_key_out, SkMaskFilter::Deserialize(data, size, procs));
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