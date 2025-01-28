//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PIXEL_REF_H
#define RAIA_SKIA_SK_PIXEL_REF_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkPixelRef_new(int width, int height, void *addr, unsigned long rowBytes); // (int width, int height, void *addr, size_t rowBytes) -> SkPixelRef *
void SkPixelRef_delete(void *pixel_ref); // (SkPixelRef *pixel_ref)
int SkPixelRef_dimensions(void *pixel_ref); // (SkPixelRef *pixel_ref) -> sk_i_size_t
int SkPixelRef_width(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
int SkPixelRef_height(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
void * SkPixelRef_pixels(void *pixel_ref); // (SkPixelRef *pixel_ref) -> void *
unsigned long SkPixelRef_rowBytes(void *pixel_ref); // (SkPixelRef *pixel_ref) -> size_t
unsigned int SkPixelRef_getGenerationID(void *pixel_ref); // (SkPixelRef *pixel_ref) -> uint32_t
void SkPixelRef_notifyPixelsChanged(void *pixel_ref); // (SkPixelRef *pixel_ref)
bool SkPixelRef_isImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
void SkPixelRef_setImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref)
void SkPixelRef_addGenIDChangeListener(void *pixel_ref, int id_change_listener); // (SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener)
void SkPixelRef_notifyAddedToCache(void *pixel_ref); // (SkPixelRef *pixel_ref)
void * SkPixelRef_diagnostic_only_getDiscardable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> SkDiscardableMemory *
bool SkPixelRef_unique(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
void SkPixelRef_ref(void *pixel_ref); // (SkPixelRef *pixel_ref)
void SkPixelRef_unref(void *pixel_ref); // (SkPixelRef *pixel_ref)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PIXEL_REF_H
