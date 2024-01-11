//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_yuva_info.h"

static std::map<std::string, SkYUVAInfo> static_sk_yuva_info;

void static_sk_yuva_info_delete(const char *key) {
    static_sk_yuva_info.erase(key);
}

SkYUVAInfo static_sk_yuva_info_get(const char *key) {
    return static_sk_yuva_info[key];
}

void static_sk_yuva_info_set(const char *key, SkYUVAInfo value) {
    static_sk_yuva_info[key] = value;
}
