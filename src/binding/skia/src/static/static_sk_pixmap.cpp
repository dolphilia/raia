//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixmap.h"

static std::map<int , SkPixmap> static_sk_pixmap;

void static_sk_pixmap_delete(int key) {
    static_sk_pixmap.erase(key);
}

SkPixmap static_sk_pixmap_get(int key) {
    return static_sk_pixmap[key];
}

void static_sk_pixmap_set(int key, SkPixmap value) {
    static_sk_pixmap[key] = std::move(value);
}