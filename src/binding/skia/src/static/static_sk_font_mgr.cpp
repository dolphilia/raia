//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_mgr.h"

static std::map<int , sk_sp<SkFontMgr>> static_sk_font_mgr;

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