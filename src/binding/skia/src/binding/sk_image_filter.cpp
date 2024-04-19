//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image_filter.h"

extern "C" {

void SkImageFilter_delete(SkImageFilter *image_filter) {
    delete image_filter;
}

sk_i_rect_t SkImageFilter_filterBounds(SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect) {
    return static_sk_i_rect_make(image_filter->filterBounds(*src, *ctm, direction, inputRect));
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

sk_rect_t SkImageFilter_computeFastBounds(SkImageFilter *image_filter, const SkRect *bounds) {
    return static_sk_rect_make(image_filter->computeFastBounds(*bounds));
}

bool SkImageFilter_canComputeFastBounds(SkImageFilter *image_filter) {
    return image_filter->canComputeFastBounds();
}

sk_image_filter_t SkImageFilter_makeWithLocalMatrix(SkImageFilter *image_filter, const SkMatrix *matrix) {
    return static_sk_image_filter_make(image_filter->makeWithLocalMatrix(*matrix));
}

sk_flattenable_factory_t SkImageFilter_getFactory(SkImageFilter *image_filter) {
    return static_sk_flattenable_factory_make(image_filter->getFactory());
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

sk_data_t SkImageFilter_serialize(SkImageFilter *image_filter, const SkSerialProcs *procs) {
    return static_sk_data_make(image_filter->serialize(procs));
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

sk_image_filter_t SkImageFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_image_filter_make(SkImageFilter::Deserialize(data, size, procs));
}

sk_flattenable_factory_t SkImageFilter_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkImageFilter::NameToFactory(name));
}

const char * SkImageFilter_FactoryToName(sk_flattenable_factory_t factory) {
    return SkImageFilter::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkImageFilter_Register(const char name[], sk_flattenable_factory_t factory) {
    return SkImageFilter::Register(name, static_sk_flattenable_factory_get(factory));
}

}