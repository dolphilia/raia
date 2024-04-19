//
// Created by dolphilia on 2024/01/10.
//

#include "sk_pixel_ref.h"
#include "../static/static_sk_id_change_listener.h"

extern "C" {

SkPixelRef *SkPixelRef_new(int width, int height, void *addr, size_t rowBytes) {
    return new SkPixelRef(width, height, addr, rowBytes);
}

void SkPixelRef_delete(SkPixelRef *pixel_ref) {
    delete pixel_ref;
}

sk_i_size_t SkPixelRef_dimensions(SkPixelRef *pixel_ref) {
    return static_sk_i_size_make(pixel_ref->dimensions());
}

int SkPixelRef_width(SkPixelRef *pixel_ref) {
    return pixel_ref->width();
}

int SkPixelRef_height(SkPixelRef *pixel_ref) {
    return pixel_ref->height();
}

void * SkPixelRef_pixels(SkPixelRef *pixel_ref) {
    return pixel_ref->pixels();
}

size_t SkPixelRef_rowBytes(SkPixelRef *pixel_ref) {
    return pixel_ref->rowBytes();
}

uint32_t SkPixelRef_getGenerationID(SkPixelRef *pixel_ref) {
    return pixel_ref->getGenerationID();
}

void SkPixelRef_notifyPixelsChanged(SkPixelRef *pixel_ref) {
    pixel_ref->notifyPixelsChanged();
}

bool SkPixelRef_isImmutable(SkPixelRef *pixel_ref) {
    return pixel_ref->isImmutable();
}

void SkPixelRef_setImmutable(SkPixelRef *pixel_ref) {
    pixel_ref->setImmutable();
}

void SkPixelRef_addGenIDChangeListener(SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener) {
    pixel_ref->addGenIDChangeListener(static_sk_id_change_listener_move(id_change_listener));
}

void SkPixelRef_notifyAddedToCache(SkPixelRef *pixel_ref) {
    pixel_ref->notifyAddedToCache();
}

SkDiscardableMemory * SkPixelRef_diagnostic_only_getDiscardable(SkPixelRef *pixel_ref) {
    return pixel_ref->diagnostic_only_getDiscardable();
}

bool SkPixelRef_unique(SkPixelRef *pixel_ref) {
    return pixel_ref->unique();
}

void SkPixelRef_ref(SkPixelRef *pixel_ref) {
    pixel_ref->ref();
}

void SkPixelRef_unref(SkPixelRef *pixel_ref) {
    pixel_ref->unref();
}

}