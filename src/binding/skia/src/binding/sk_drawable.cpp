//
// Created by dolphilia on 2024/01/08.
//

#include "sk_drawable.h"
#include "../static/static_sk_rect.h"

extern "C" {

void SkDrawable_draw(SkDrawable *drawable, SkCanvas * canvas, const SkMatrix * matrix) {
    drawable->draw(canvas, matrix);
}

void SkDrawable_draw_2(SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y) {
    drawable->draw(canvas, x, y);
}

void SkDrawable_snapGpuDrawHandler(int gpu_draw_handler_key_out, SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) {
    static_sk_drawable_gpu_draw_handler_set(gpu_draw_handler_key_out, drawable->snapGpuDrawHandler(backendApi, *matrix, *clipBounds, *bufferInfo));
}

void SkDrawable_makePictureSnapshot(int sk_picture_key_out, SkDrawable *drawable) {
    static_sk_picture_set(sk_picture_key_out, drawable->makePictureSnapshot());
}

uint32_t SkDrawable_getGenerationID(SkDrawable *drawable) {
    return drawable->getGenerationID();
}

void SkDrawable_getBounds(int sk_rect_key_out, SkDrawable *drawable) {
    static_sk_rect_set(sk_rect_key_out,drawable->getBounds());
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

SkDrawable::Factory SkDrawable_getFactory(SkDrawable *drawable) {
    return drawable->getFactory();
}

const char * SkDrawable_getTypeName(SkDrawable *drawable) {
    return drawable->getTypeName();
}

void SkDrawable_flatten(SkDrawable *drawable, SkWriteBuffer *write_buffer) {
    drawable->flatten(*write_buffer);
}

void SkDrawable_serialize(int sk_data_key_out, SkDrawable *drawable, const SkSerialProcs *serial_procs) {
    static_sk_data_set(sk_data_key_out, drawable->serialize(serial_procs));
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

void SkDrawable_Deserialize(int sk_drawable_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_drawable_set(sk_drawable_key_out, SkDrawable::Deserialize(data, size, procs));
}

SkDrawable::Factory SkDrawable_NameToFactory(const char name[]) {
    return SkDrawable::NameToFactory(name);
}

const char * SkDrawable_FactoryToName(SkDrawable::Factory factory) {
    return SkDrawable::FactoryToName(factory);
}

void SkDrawable_Register(const char name[], SkDrawable::Factory factory) {
    SkDrawable::Register(name, factory);
}

}