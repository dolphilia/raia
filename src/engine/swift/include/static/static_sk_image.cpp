//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image.h"

#include <utility>
#include "static_sk_image-internal.h"

static std::set<int> static_sk_image_available_keys;
static std::map<int , sk_sp<SkImage>> static_sk_image;
static int static_sk_image_index = 0;

int static_sk_image_make(sk_sp<SkImage> value) {
    int key;
    if (!static_sk_image_available_keys.empty()) {
        auto it = static_sk_image_available_keys.begin();
        key = *it;
        static_sk_image_available_keys.erase(it);
    } else {
        key = static_sk_image_index++;
    }
    static_sk_image[key] = std::move(value);
    return key;
}

void static_sk_image_delete(int key) {
    static_sk_image[key].reset();
    static_sk_image.erase(key);
    static_sk_image_available_keys.insert(key);
}

void *static_sk_image_get(int key) { // -> SkImage *
    return static_sk_image[key].get();
}

void static_sk_image_set(int key, sk_sp<SkImage> value) {
    static_sk_image[key] = std::move(value);
}

sk_sp<SkImage> static_sk_image_move(int key) {
    return std::move(static_sk_image[key]);
}
