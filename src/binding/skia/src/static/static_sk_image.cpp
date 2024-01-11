//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image.h"

static std::map<std::string, sk_sp<SkImage>> static_sk_image;

void static_sk_image_delete(const char *key) {
    static_sk_image[key].reset();
    static_sk_image.erase(key);
}

SkImage *static_sk_image_get(const char *key) {
    return static_sk_image[key].get();
}

void static_sk_image_set(const char *key, sk_sp<SkImage> value) {
    static_sk_image[key] = std::move(value);
}

sk_sp<SkImage> static_sk_image_move(const char *key) {
    return std::move(static_sk_image[key]);
}