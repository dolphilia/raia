//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXMAP_H
#define RAIA_SKIA_STATIC_SK_PIXMAP_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPixmap.h"
#include "export_api.h"

typedef int sk_pixmap_t;

extern "C" {
RAIA_API void static_sk_pixmap_delete(int key);
RAIA_API SkPixmap * static_sk_pixmap_get_ptr(int key);
}

int static_sk_pixmap_make(SkPixmap value);
SkPixmap static_sk_pixmap_get(int key) ;
void static_sk_pixmap_set(int key, SkPixmap value);

#endif //RAIA_SKIA_STATIC_SK_PIXMAP_H
