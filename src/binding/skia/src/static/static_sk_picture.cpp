//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_picture.h"

#include <utility>

static std::map<int , sk_sp<SkPicture>> static_sk_picture;
static int static_sk_picture_index = 0;

int static_sk_picture_make(sk_sp<SkPicture> value) {
    static_sk_picture[static_sk_picture_index] = std::move(value);
    static_sk_picture_index++;
    return static_sk_picture_index - 1;
}

void static_sk_picture_delete(int key) {
    static_sk_picture[key].reset();
    static_sk_picture.erase(key);
}

SkPicture *static_sk_picture_get(int key) {
    return static_sk_picture[key].get();
}

void static_sk_picture_set(int key, sk_sp<SkPicture> value) {
    static_sk_picture[key] = std::move(value);
}

sk_sp<SkPicture> static_sk_picture_move(int key) {
    return std::move(static_sk_picture[key]);
}