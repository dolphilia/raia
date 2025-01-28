//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_PIXMAP_UTILS_H
#define RAIA_SKIA_SK_PIXMAP_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

bool SkPixmapUtils_Orient(const void* dst, const void* src, int origin); // (const SkPixmap* dst, const SkPixmap* src, SkEncodedOrigin origin) -> bool
int SkPixmapUtils_SwapWidthHeight(const void* info); // (const SkImageInfo* info) -> sk_image_info_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PIXMAP_UTILS_H
