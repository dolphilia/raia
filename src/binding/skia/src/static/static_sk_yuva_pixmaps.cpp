//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_pixmaps.h"

static std::map<int , SkYUVAPixmaps> static_sk_yuva_pixmaps;

void static_sk_yuva_pixmaps_delete(int key) {
    static_sk_yuva_pixmaps.erase(key);
}

SkYUVAPixmaps static_sk_yuva_pixmaps_get(int key) {
    return static_sk_yuva_pixmaps[key];
}

void static_sk_yuva_pixmaps_set(int key, SkYUVAPixmaps value) {
    static_sk_yuva_pixmaps[key] = std::move(value);
}