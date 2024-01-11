//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixel_ref.h"

static std::map<std::string, sk_sp<SkPixelRef>> static_sk_pixel_ref;

void static_sk_pixel_ref_delete(const char *key) {
    static_sk_pixel_ref[key].reset();
    static_sk_pixel_ref.erase(key);
}

SkPixelRef *static_sk_pixel_ref_get(const char *key) {
    return static_sk_pixel_ref[key].get();
}

void static_sk_pixel_ref_set(const char *key, sk_sp<SkPixelRef> value) {
    static_sk_pixel_ref[key] = std::move(value);
}

sk_sp<SkPixelRef> static_sk_pixel_ref_move(const char *key) {
    return std::move(static_sk_pixel_ref[key]);
}