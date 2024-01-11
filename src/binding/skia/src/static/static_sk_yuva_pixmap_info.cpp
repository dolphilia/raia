//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_pixmap_info.h"

static std::map<std::string, SkYUVAPixmapInfo> static_sk_yuva_pixmap_info;

void static_sk_yuva_pixmap_info_delete(const char *key) {
    static_sk_yuva_pixmap_info.erase(key);
}

SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get(const char *key) {
    return static_sk_yuva_pixmap_info[key];
}

void static_sk_yuva_pixmap_info_set(const char *key, SkYUVAPixmapInfo value) {
    static_sk_yuva_pixmap_info[key] = value;
}