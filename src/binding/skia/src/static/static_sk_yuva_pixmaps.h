//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H

#include <string>
#include <map>
#include "include/core/SkYUVAPixmaps.h"

void static_sk_yuva_pixmaps_delete(const char *key);
SkYUVAPixmaps static_sk_yuva_pixmaps_get(const char *key);
void static_sk_yuva_pixmaps_set(const char *key, SkYUVAPixmaps value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
