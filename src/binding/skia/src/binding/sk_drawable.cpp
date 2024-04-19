//
// Created by dolphilia on 2024/01/08.
//

#include "sk_drawable.h"

extern "C" {

void SkDrawable_delete(SkDrawable *drawable) {
    delete drawable;
}

void SkDrawable_draw(SkDrawable *drawable, SkCanvas * canvas, const SkMatrix * matrix) {
    drawable->draw(canvas, matrix);
}

void SkDrawable_draw_2(SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y) {
    drawable->draw(canvas, x, y);
}

sk_drawable_gpu_draw_handler_t SkDrawable_snapGpuDrawHandler(SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) {
    return static_sk_drawable_gpu_draw_handler_make(drawable->snapGpuDrawHandler(backendApi, *matrix, *clipBounds, *bufferInfo));
}

sk_picture_t SkDrawable_makePictureSnapshot(SkDrawable *drawable) {
    return static_sk_picture_make(drawable->makePictureSnapshot());
}

uint32_t SkDrawable_getGenerationID(SkDrawable *drawable) {
    return drawable->getGenerationID();
}

sk_rect_t SkDrawable_getBounds(SkDrawable *drawable) {
    return static_sk_rect_make(drawable->getBounds());
}

size_t SkDrawable_approximateBytesUsed(SkDrawable *drawable) {
    return drawable->approximateBytesUsed();
}

void SkDrawable_notifyDrawingChanged(SkDrawable *drawable) {
    drawable->notifyDrawingChanged();
}

SkFlattenable::Type SkDrawable_getFlattenableType(SkDrawable *drawable) {
    return drawable->getFlattenableType();
}

sk_flattenable_factory_t SkDrawable_getFactory(SkDrawable *drawable) {
    return static_sk_flattenable_factory_make(drawable->getFactory());
}

const char * SkDrawable_getTypeName(SkDrawable *drawable) {
    return drawable->getTypeName();
}

void SkDrawable_flatten(SkDrawable *drawable, SkWriteBuffer *write_buffer) {
    drawable->flatten(*write_buffer);
}

sk_data_t SkDrawable_serialize(SkDrawable *drawable, const SkSerialProcs *serial_procs) {
    return static_sk_data_make(drawable->serialize(serial_procs));
}

size_t SkDrawable_serialize_2(SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return drawable->serialize(memory, memory_size, serial_procs);
}

bool SkDrawable_unique(SkDrawable *drawable) {
    return drawable->unique();
}

void SkDrawable_ref(SkDrawable *drawable) {
    drawable->ref();
}

void SkDrawable_unref(SkDrawable *drawable) {
    drawable->unref();
}

// static

SkFlattenable::Type SkDrawable_GetFlattenableType() {
    return SkDrawable::GetFlattenableType();
}

sk_drawable_t SkDrawable_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_drawable_make(SkDrawable::Deserialize(data, size, procs));
}

sk_flattenable_factory_t SkDrawable_NameToFactory(const char name[]) {
    return static_sk_flattenable_factory_make(SkDrawable::NameToFactory(name));
}

const char * SkDrawable_FactoryToName(sk_flattenable_factory_t factory) {
    return SkDrawable::FactoryToName(static_sk_flattenable_factory_get(factory));
}

void SkDrawable_Register(const char name[], sk_flattenable_factory_t factory) {
    SkDrawable::Register(name, static_sk_flattenable_factory_get(factory));
}

}