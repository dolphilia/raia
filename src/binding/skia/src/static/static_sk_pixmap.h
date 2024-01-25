//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXMAP_H
#define RAIA_SKIA_STATIC_SK_PIXMAP_H

#include <string>
#include <map>
#include "include/core/SkPixmap.h"

void static_sk_pixmap_delete(int key);
SkPixmap static_sk_pixmap_get(int key) ;
void static_sk_pixmap_set(int key, SkPixmap value);

#endif //RAIA_SKIA_STATIC_SK_PIXMAP_H
