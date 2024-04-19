//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_matrix_filter.h"

extern "C" {

void SkColorMatrixFilter_delete(SkColorMatrixFilter *color_matrix_filter) {
    delete color_matrix_filter;
}

bool SkColorMatrixFilter_asAColorMode(SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode) {
    return color_matrix_filter->asAColorMode(color, mode);
}

bool SkColorMatrixFilter_asAColorMatrix(SkColorMatrixFilter *color_matrix_filter, float matrix[20]) {
    return color_matrix_filter->asAColorMatrix(matrix);
}

bool SkColorMatrixFilter_isAlphaUnchanged(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->isAlphaUnchanged();
}

SkColor SkColorMatrixFilter_filterColor(SkColorMatrixFilter *color_matrix_filter, SkColor color) {
    return color_matrix_filter->filterColor(color);
}

sk_color_4f_t SkColorMatrixFilter_filterColor4f(SkColorMatrixFilter *color_matrix_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) {
    return static_sk_color_4f_make(color_matrix_filter->filterColor4f(*srcColor, srcCS, dstCS));
}

sk_color_filter_t SkColorMatrixFilter_makeComposed(SkColorMatrixFilter *color_matrix_filter, sk_color_filter_t colorFilter) {
    return static_sk_color_filter_make(color_matrix_filter->makeComposed(static_sk_color_filter_move(colorFilter)));
}

sk_color_filter_t SkColorMatrixFilter_makeWithWorkingColorSpace(SkColorMatrixFilter *color_matrix_filter, sk_color_space_t colorSpace) {
    return static_sk_color_filter_make(color_matrix_filter->makeWithWorkingColorSpace(static_sk_color_space_move(colorSpace)));
}

sk_flattenable_factory_t SkColorMatrixFilter_getFactory(SkColorMatrixFilter *color_matrix_filter) {
    return static_sk_flattenable_factory_make(color_matrix_filter->getFactory());
}

const char * SkColorMatrixFilter_getTypeName(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->getTypeName();
}

void SkColorMatrixFilter_flatten(SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer) {
    color_matrix_filter->flatten(*write_buffer);
}

SkColorMatrixFilter::Type SkColorMatrixFilter_getFlattenableType(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->getFlattenableType();
}

sk_data_t SkColorMatrixFilter_serialize(SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs) {
    return static_sk_data_make(color_matrix_filter->serialize(serial_procs));
}

size_t SkColorMatrixFilter_serialize_2(SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return color_matrix_filter->serialize(memory, memory_size, serial_procs);
}

bool SkColorMatrixFilter_unique(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->unique();
}

void SkColorMatrixFilter_ref(SkColorMatrixFilter *color_matrix_filter) {
    color_matrix_filter->ref();
}

void SkColorMatrixFilter_unref(SkColorMatrixFilter *color_matrix_filter) {
    color_matrix_filter->unref();
}

// static

sk_color_filter_t SkColorMatrixFilter_MakeLightingFilter(SkColor mul, SkColor add) {
    return static_sk_color_filter_make(SkColorMatrixFilter::MakeLightingFilter(mul, add));
}

sk_color_filter_t SkColorMatrixFilter_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_color_filter_make(SkColorMatrixFilter::Deserialize(data, size, procs));
}

sk_flattenable_factory_t SkColorMatrixFilter_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkColorMatrixFilter::NameToFactory(name));
}

const char * SkColorMatrixFilter_FactoryToName(sk_flattenable_factory_t factory) {
    return SkColorMatrixFilter::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkColorMatrixFilter_Register(const char name[], sk_flattenable_factory_t factory) {
    SkColorMatrixFilter::Register(name, static_sk_flattenable_factory_get(factory));
}

}