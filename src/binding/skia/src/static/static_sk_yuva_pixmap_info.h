//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H

#include <string>
#include <map>
#include "include/core/SkYUVAPixmaps.h"

void static_sk_yuva_pixmap_info_delete(const char *key);
SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get(const char *key);
void static_sk_yuva_pixmap_info_set(const char *key, SkYUVAPixmapInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
