//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_pixel_ref.h"

#include <utility>

static std::map<int , sk_sp<SkPixelRef>> static_sk_pixel_ref;
static int static_sk_pixel_ref_index = 0;

int static_sk_pixel_ref_make(sk_sp<SkPixelRef> value) {
    static_sk_pixel_ref[static_sk_pixel_ref_index] = std::move(value);
    static_sk_pixel_ref_index++;
    return static_sk_pixel_ref_index - 1;
}

void static_sk_pixel_ref_delete(int key) {
    static_sk_pixel_ref[key].reset();
    static_sk_pixel_ref.erase(key);
}

SkPixelRef *static_sk_pixel_ref_get(int key) {
    return static_sk_pixel_ref[key].get();
}

void static_sk_pixel_ref_set(int key, sk_sp<SkPixelRef> value) {
    static_sk_pixel_ref[key] = std::move(value);
}

sk_sp<SkPixelRef> static_sk_pixel_ref_move(int key) {
    return std::move(static_sk_pixel_ref[key]);
}