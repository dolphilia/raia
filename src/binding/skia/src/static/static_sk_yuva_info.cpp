//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_info.h"

static std::map<int , SkYUVAInfo> static_sk_yuva_info;

void static_sk_yuva_info_delete(int key) {
    static_sk_yuva_info.erase(key);
}

SkYUVAInfo static_sk_yuva_info_get(int key) {
    return static_sk_yuva_info[key];
}

void static_sk_yuva_info_set(int key, SkYUVAInfo value) {
    static_sk_yuva_info[key] = value;
}
