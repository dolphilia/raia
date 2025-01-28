//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixmap.h"

#include <utility>
#include "static_sk_pixmap-internal.h"

static std::set<int> static_sk_pixmap_available_keys;
static std::map<int , SkPixmap> static_sk_pixmap;
static int static_sk_pixmap_index = 0;

int static_sk_pixmap_make(SkPixmap value) {
    int key;
    if (!static_sk_pixmap_available_keys.empty()) {
        auto it = static_sk_pixmap_available_keys.begin();
        key = *it;
        static_sk_pixmap_available_keys.erase(it);
    } else {
        key = static_sk_pixmap_index++;
    }
    static_sk_pixmap[key] = std::move(value);
    return key;
}

void static_sk_pixmap_delete(int key) {
    static_sk_pixmap.erase(key);
    static_sk_pixmap_available_keys.insert(key);
}

SkPixmap static_sk_pixmap_get(int key) {
    return static_sk_pixmap[key];
}

void * static_sk_pixmap_get_ptr(int key) { // -> SkPixmap *
    return &static_sk_pixmap[key];
}

void static_sk_pixmap_set(int key, SkPixmap value) {
    static_sk_pixmap[key] = std::move(value);
}
