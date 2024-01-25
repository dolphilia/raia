//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_info.h"

static std::map<int , SkYUVAInfo> static_sk_yuva_info;
static int static_sk_yuva_info_index = 0;

int static_sk_yuva_info_make(SkYUVAInfo value) {
    static_sk_yuva_info[static_sk_yuva_info_index] = value;
    static_sk_yuva_info_index++;
    return static_sk_yuva_info_index - 1;
}

void static_sk_yuva_info_delete(int key) {
    static_sk_yuva_info.erase(key);
}

SkYUVAInfo static_sk_yuva_info_get(int key) {
    return static_sk_yuva_info[key];
}

void static_sk_yuva_info_set(int key, SkYUVAInfo value) {
    static_sk_yuva_info[key] = value;
}
