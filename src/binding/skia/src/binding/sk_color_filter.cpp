//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_filter.h"

extern "C" {

void SkColorFilter_delete(SkColorFilter *color_filter) {
    delete color_filter;
}

bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode) {
    return color_filter->asAColorMode(color, mode);
}

bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]) {
    return color_filter->asAColorMatrix(matrix);
}

bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter) {
    return color_filter->isAlphaUnchanged();
}

SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color) {
    return color_filter->filterColor(color);
}

SkColor4f SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS,
                                      SkColorSpace *dstCS) {
    return color_filter->filterColor4f(*srcColor, srcCS, dstCS);
}

int SkColorFilter_makeComposed(int sk_color_filter_key_in,
                                SkColorFilter *color_filter) {
    return static_sk_color_filter_make(color_filter->makeComposed(static_sk_color_filter_move(sk_color_filter_key_in)));
}

int SkColorFilter_makeWithWorkingColorSpace(int sk_color_space_key_in,
                                             SkColorFilter *color_filter) {
    return static_sk_color_filter_make(color_filter->makeWithWorkingColorSpace(
            static_sk_color_space_move(sk_color_space_key_in)));
}

SkColorFilter::Factory SkColorFilter_getFactory(SkColorFilter *color_filter) {
    return color_filter->getFactory();
}

const char *SkColorFilter_getTypeName(SkColorFilter *color_filter) {
    return color_filter->getTypeName();
}

void SkColorFilter_flatten(SkColorFilter *color_filter, SkWriteBuffer *write_buffer) {
    color_filter->flatten(*write_buffer);
}

SkColorFilter::Type SkColorFilter_getFlattenableType(SkColorFilter *color_filter) {
    return color_filter->getFlattenableType();
}

int SkColorFilter_serialize(SkColorFilter *color_filter, const SkSerialProcs *serial_procs) {
    return static_sk_data_make(color_filter->serialize(serial_procs));
}

size_t SkColorFilter_serialize_2(SkColorFilter *color_filter, void *memory, size_t memory_size,
                                 const SkSerialProcs *serial_procs) {
    return color_filter->serialize(memory, memory_size, serial_procs);
}

bool SkColorFilter_unique(SkColorFilter *color_filter) {
    return color_filter->unique();
}

void SkColorFilter_ref(SkColorFilter *color_filter) {
    return color_filter->ref();
}

void SkColorFilter_unref(SkColorFilter *color_filter) {
    color_filter->unref();
}

// static

int SkColorFilter_Deserialize(const void *data, size_t size,
                               const SkDeserialProcs *procs) {
    return static_sk_color_filter_make(SkColorFilter::Deserialize(data, size, procs));
}

SkColorFilter::Factory SkColorFilter_NameToFactory(const char name[]) {
    return SkColorFilter::NameToFactory(name);
}

const char *SkColorFilter_FactoryToName(SkColorFilter::Factory factory) {
    return SkColorFilter::FactoryToName(factory);
}

void SkColorFilter_Register(const char name[], SkColorFilter::Factory factory) {
    SkColorFilter::Register(name, factory);
}

}