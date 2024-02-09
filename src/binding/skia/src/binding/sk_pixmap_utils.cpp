//
// Created by dolphilia on 2024/02/02.
//

#include "sk_pixmap_utils.h"

extern "C" {

bool SkPixmapUtils_Orient(const SkPixmap* dst, const SkPixmap* src, SkEncodedOrigin origin) {
    return SkPixmapUtils::Orient(*dst, *src, origin);
}

sk_image_info_t SkPixmapUtils_SwapWidthHeight(const SkImageInfo* info) {
    return static_sk_image_info_make(SkPixmapUtils::SwapWidthHeight(*info));
}

}