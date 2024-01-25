//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image.h"

#include <utility>

static std::map<int , sk_sp<SkImage>> static_sk_image;
static int static_sk_image_index = 0;

int static_sk_image_make(sk_sp<SkImage> value) {
    static_sk_image[static_sk_image_index] = std::move(value);
    static_sk_image_index++;
    return static_sk_image_index - 1;
}

void static_sk_image_delete(int key) {
    static_sk_image[key].reset();
    static_sk_image.erase(key);
}

SkImage *static_sk_image_get(int key) {
    return static_sk_image[key].get();
}

void static_sk_image_set(int key, sk_sp<SkImage> value) {
    static_sk_image[key] = std::move(value);
}

sk_sp<SkImage> static_sk_image_move(int key) {
    return std::move(static_sk_image[key]);
}