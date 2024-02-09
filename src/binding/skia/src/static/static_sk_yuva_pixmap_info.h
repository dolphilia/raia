//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkYUVAPixmaps.h"

typedef int sk_yuva_pixmap_info_t;

int static_sk_yuva_pixmap_info_make(SkYUVAPixmapInfo value);
extern "C" void static_sk_yuva_pixmap_info_delete(int key);
SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get(int key);
void static_sk_yuva_pixmap_info_set(int key, SkYUVAPixmapInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAP_INFO_H
