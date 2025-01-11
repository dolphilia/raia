//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_PIXMAP_UTILS_H
#define RAIA_SKIA_SK_PIXMAP_UTILS_H

#include "include/codec/SkPixmapUtils.h"
#include "../static/static_sk_image_info.h"
#include "export_api.h"

extern "C" {
RAIA_API bool SkPixmapUtils_Orient(const SkPixmap* dst, const SkPixmap* src, SkEncodedOrigin origin);
RAIA_API sk_image_info_t SkPixmapUtils_SwapWidthHeight(const SkImageInfo* info);
}

#endif //RAIA_SKIA_SK_PIXMAP_UTILS_H
