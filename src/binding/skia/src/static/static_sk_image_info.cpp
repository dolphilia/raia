//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_info.h"

#include <utility>

static std::map<int , SkImageInfo> static_sk_image_info;
static int static_sk_image_info_index = 0;

int static_sk_image_info_make(SkImageInfo value) {
    static_sk_image_info[static_sk_image_info_index] = std::move(value);
    static_sk_image_info_index++;
    return static_sk_image_info_index - 1;
}

void static_sk_image_info_delete(int key) {
    static_sk_image_info.erase(key);
}

SkImageInfo static_sk_image_info_get(int key) {
    return static_sk_image_info[key];
}

void static_sk_image_info_set(int key, SkImageInfo value) {
    static_sk_image_info[key] = std::move(value);
}