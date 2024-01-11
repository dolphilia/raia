//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_pixmaps.h"

static std::map<std::string, SkYUVAPixmaps> static_sk_yuva_pixmaps;

void static_sk_yuva_pixmaps_delete(const char *key) {
    static_sk_yuva_pixmaps.erase(key);
}

SkYUVAPixmaps static_sk_yuva_pixmaps_get(const char *key) {
    return static_sk_yuva_pixmaps[key];
}

void static_sk_yuva_pixmaps_set(const char *key, SkYUVAPixmaps value) {
    static_sk_yuva_pixmaps[key] = std::move(value);
}