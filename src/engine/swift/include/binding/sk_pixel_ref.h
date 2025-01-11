//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PIXEL_REF_H
#define RAIA_SKIA_SK_PIXEL_REF_H

#include "include/core/SkPixelRef.h"
#include "../static/static_sk_id_change_listener.h"
#include "../static/static_sk_i_size.h"
#include "export_api.h"

extern "C" {
RAIA_API SkPixelRef *SkPixelRef_new(int width, int height, void *addr, size_t rowBytes);
RAIA_API void SkPixelRef_delete(SkPixelRef *pixel_ref);
RAIA_API sk_i_size_t SkPixelRef_dimensions(SkPixelRef *pixel_ref);
RAIA_API int SkPixelRef_width(SkPixelRef *pixel_ref);
RAIA_API int SkPixelRef_height(SkPixelRef *pixel_ref);
RAIA_API void * SkPixelRef_pixels(SkPixelRef *pixel_ref);
RAIA_API size_t SkPixelRef_rowBytes(SkPixelRef *pixel_ref);
RAIA_API uint32_t SkPixelRef_getGenerationID(SkPixelRef *pixel_ref);
RAIA_API void SkPixelRef_notifyPixelsChanged(SkPixelRef *pixel_ref);
RAIA_API bool SkPixelRef_isImmutable(SkPixelRef *pixel_ref);
RAIA_API void SkPixelRef_setImmutable(SkPixelRef *pixel_ref);
RAIA_API void SkPixelRef_addGenIDChangeListener(SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener);
RAIA_API void SkPixelRef_notifyAddedToCache(SkPixelRef *pixel_ref);
RAIA_API SkDiscardableMemory * SkPixelRef_diagnostic_only_getDiscardable(SkPixelRef *pixel_ref);
RAIA_API bool SkPixelRef_unique(SkPixelRef *pixel_ref);
RAIA_API void SkPixelRef_ref(SkPixelRef *pixel_ref);
RAIA_API void SkPixelRef_unref(SkPixelRef *pixel_ref);
}

#endif //RAIA_SKIA_SK_PIXEL_REF_H
