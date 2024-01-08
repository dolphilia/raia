//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixmap.h"

static std::map<std::string, SkPixmap> static_sk_pixmap;

void static_sk_pixmap_delete(const char *key) {
    static_sk_pixmap.erase(key);
}

SkPixmap static_sk_pixmap_get(const char *key) {
    return static_sk_pixmap[key];
}

void static_sk_pixmap_set(const char *key, SkPixmap value) {
    static_sk_pixmap[key] = std::move(value);
}