//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_pixmap_info.h"

static std::map<int , SkYUVAPixmapInfo> static_sk_yuva_pixmap_info;

void static_sk_yuva_pixmap_info_delete(int key) {
    static_sk_yuva_pixmap_info.erase(key);
}

SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get(int key) {
    return static_sk_yuva_pixmap_info[key];
}

void static_sk_yuva_pixmap_info_set(int key, SkYUVAPixmapInfo value) {
    static_sk_yuva_pixmap_info[key] = value;
}