//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_pixmaps.h"

#include <utility>

static std::map<int , SkYUVAPixmaps> static_sk_yuva_pixmaps;
static int static_sk_yuva_pixmaps_index = 0;

int static_sk_yuva_pixmaps_make(SkYUVAPixmaps value) {
    static_sk_yuva_pixmaps[static_sk_yuva_pixmaps_index] = std::move(value);
    static_sk_yuva_pixmaps_index++;
    return static_sk_yuva_pixmaps_index - 1;
}

void static_sk_yuva_pixmaps_delete(int key) {
    static_sk_yuva_pixmaps.erase(key);
}

SkYUVAPixmaps static_sk_yuva_pixmaps_get(int key) {
    return static_sk_yuva_pixmaps[key];
}

void static_sk_yuva_pixmaps_set(int key, SkYUVAPixmaps value) {
    static_sk_yuva_pixmaps[key] = std::move(value);
}