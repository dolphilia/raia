//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_info.h"

static std::map<int , SkImageInfo> static_sk_image_info;

void static_sk_image_info_delete(int key) {
    static_sk_image_info.erase(key);
}

SkImageInfo static_sk_image_info_get(int key) {
    return static_sk_image_info[key];
}

void static_sk_image_info_set(int key, SkImageInfo value) {
    static_sk_image_info[key] = std::move(value);
}