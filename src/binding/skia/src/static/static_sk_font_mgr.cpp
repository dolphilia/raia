//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_mgr.h"

#include <utility>

static std::map<int , sk_sp<SkFontMgr>> static_sk_font_mgr;
static int static_sk_font_mgr_index = 0;

int static_sk_font_mgr_make(sk_sp<SkFontMgr> value) {
    static_sk_font_mgr[static_sk_font_mgr_index] = std::move(value);
    static_sk_font_mgr_index++;
    return static_sk_font_mgr_index - 1;
}

void static_sk_font_mgr_delete(int key) {
    static_sk_font_mgr[key].reset();
    static_sk_font_mgr.erase(key);
}

SkFontMgr *static_sk_font_mgr_get(int key) {
    return static_sk_font_mgr[key].get();
}

void static_sk_font_mgr_set(int key, sk_sp<SkFontMgr> value) {
    static_sk_font_mgr[key] = std::move(value);
}

sk_sp<SkFontMgr> static_sk_font_mgr_move(int key) {
    return std::move(static_sk_font_mgr[key]);
}