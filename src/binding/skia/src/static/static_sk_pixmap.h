//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXMAP_H
#define RAIA_SKIA_STATIC_SK_PIXMAP_H

#include <string>
#include <map>
#include "include/core/SkPixmap.h"

void static_sk_pixmap_delete(const char *key);
SkPixmap static_sk_pixmap_get(const char *key) ;
void static_sk_pixmap_set(const char *key, SkPixmap value);

#endif //RAIA_SKIA_STATIC_SK_PIXMAP_H
