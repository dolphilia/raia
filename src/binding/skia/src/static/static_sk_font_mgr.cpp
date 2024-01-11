//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_mgr.h"

static std::map<std::string, sk_sp<SkFontMgr>> static_sk_font_mgr;

void static_sk_font_mgr_delete(const char *key) {
    static_sk_font_mgr[key].reset();
    static_sk_font_mgr.erase(key);
}

SkFontMgr *static_sk_font_mgr_get(const char *key) {
    return static_sk_font_mgr[key].get();
}

void static_sk_font_mgr_set(const char *key, sk_sp<SkFontMgr> value) {
    static_sk_font_mgr[key] = std::move(value);
}

sk_sp<SkFontMgr> static_sk_font_mgr_move(const char *key) {
    return std::move(static_sk_font_mgr[key]);
}