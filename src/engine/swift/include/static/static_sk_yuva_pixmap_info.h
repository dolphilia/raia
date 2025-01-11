//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkYUVAPixmaps.h"
#include "export_api.h"

typedef int sk_yuva_pixmap_info_t;

extern "C" {
RAIA_API void static_sk_yuva_pixmap_info_delete(int key);
RAIA_API SkYUVAPixmapInfo * static_sk_yuva_pixmap_info_get_ptr(int key);
}

int static_sk_yuva_pixmap_info_make(SkYUVAPixmapInfo value);
SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get(int key);
void static_sk_yuva_pixmap_info_set(int key, SkYUVAPixmapInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
