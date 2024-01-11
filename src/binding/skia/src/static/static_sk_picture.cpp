//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_picture.h"

static std::map<std::string, sk_sp<SkPicture>> static_sk_picture;

void static_sk_picture_delete(const char *key) {
    static_sk_picture[key].reset();
    static_sk_picture.erase(key);
}

SkPicture *static_sk_picture_get(const char *key) {
    return static_sk_picture[key].get();
}

void static_sk_picture_set(const char *key, sk_sp<SkPicture> value) {
    static_sk_picture[key] = std::move(value);
}

sk_sp<SkPicture> static_sk_picture_move(const char *key) {
    return std::move(static_sk_picture[key]);
}