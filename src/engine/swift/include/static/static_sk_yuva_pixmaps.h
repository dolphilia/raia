//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkYUVAPixmaps.h"
#include "export_api.h"

typedef int sk_yuva_pixmaps_t;

extern "C" {
RAIA_API void static_sk_yuva_pixmaps_delete(int key);
RAIA_API SkYUVAPixmaps * static_sk_yuva_pixmaps_get_ptr(int key);
}

int static_sk_yuva_pixmaps_make(SkYUVAPixmaps value);
SkYUVAPixmaps static_sk_yuva_pixmaps_get(int key);
void static_sk_yuva_pixmaps_set(int key, SkYUVAPixmaps value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
