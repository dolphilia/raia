//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixmap.h"

#include <utility>

static std::map<int , SkPixmap> static_sk_pixmap;
static int static_sk_pixmap_index = 0;

int static_sk_pixmap_make(SkPixmap value) {
    static_sk_pixmap[static_sk_pixmap_index] = std::move(value);
    static_sk_pixmap_index++;
    return static_sk_pixmap_index - 1;
}

void static_sk_pixmap_delete(int key) {
    static_sk_pixmap.erase(key);
}

SkPixmap static_sk_pixmap_get(int key) {
    return static_sk_pixmap[key];
}

void static_sk_pixmap_set(int key, SkPixmap value) {
    static_sk_pixmap[key] = std::move(value);
}