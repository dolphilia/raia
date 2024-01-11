//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image_filter.h"

extern "C" {

void SkImageFilter_filterBounds(const char *sk_i_rect_key_out, SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect) {
    static_sk_i_rect_set(sk_i_rect_key_out, image_filter->filterBounds(*src, *ctm, direction, inputRect));
}

bool SkImageFilter_isColorFilterNode(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->isColorFilterNode(filterPtr);
}

bool SkImageFilter_asColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->asColorFilter(filterPtr);
}

bool SkImageFilter_asAColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->asAColorFilter(filterPtr);
}

int SkImageFilter_countInputs(SkImageFilter *image_filter) {
    return image_filter->countInputs();
}

const SkImageFilter * SkImageFilter_getInput(SkImageFilter *image_filter, int i) {
    return image_filter->getInput(i);
}

void SkImageFilter_computeFastBounds(const char *sk_rect_key_out, SkImageFilter *image_filter, const SkRect *bounds) {
    static_sk_rect_set(sk_rect_key_out, image_filter->computeFastBounds(*bounds));
}

bool SkImageFilter_canComputeFastBounds(SkImageFilter *image_filter) {
    return image_filter->canComputeFastBounds();
}

void SkImageFilter_makeWithLocalMatrix(const char *sk_image_filter_key_out, SkImageFilter *image_filter, const SkMatrix *matrix) {
    static_sk_image_filter_set(sk_image_filter_key_out, image_filter->makeWithLocalMatrix(*matrix));
}

SkImageFilter::Factory SkImageFilter_getFactory(SkImageFilter *image_filter) {
    return image_filter->getFactory();
}

const char * SkImageFilter_getTypeName(SkImageFilter *image_filter) {
    return image_filter->getTypeName();
}

void SkImageFilter_flatten(SkImageFilter *image_filter, SkWriteBuffer *buffer) {
    image_filter->flatten(*buffer);
}

SkImageFilter::Type SkImageFilter_getFlattenableType(SkImageFilter *image_filter) {
    return image_filter->getFlattenableType();
}

void SkImageFilter_serialize(const char *sk_data_key_out, SkImageFilter *image_filter, const SkSerialProcs *procs) {
    static_sk_data_set(sk_data_key_out, image_filter->serialize(procs));
}

size_t SkImageFilter_serialize_2(SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return image_filter->serialize(memory, memory_size, procs);
}

bool SkImageFilter_unique(SkImageFilter *image_filter) {
    return image_filter->unique();
}

void SkImageFilter_ref(SkImageFilter *image_filter) {
    image_filter->ref();
}

void SkImageFilter_unref(SkImageFilter *image_filter) {
    image_filter->unref();
}

// static

void SkImageFilter_Deserialize(const char *sk_image_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilter::Deserialize(data, size, procs));
}

SkImageFilter::Factory SkImageFilter_NameToFactory(const char name[]) {
    return SkImageFilter::NameToFactory(name);
}

const char * SkImageFilter_FactoryToName(SkImageFilter::Factory factory) {
    return SkImageFilter::FactoryToName(factory);
}

void SkImageFilter_Register(const char name[], SkImageFilter::Factory factory) {
    return SkImageFilter::Register(name, factory);
}

}