//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_mgr.h"

#include <utility>
#include "static_sk_font_mgr-internal.h"

static std::set<int> static_sk_font_mgr_available_keys;
static std::map<int , sk_sp<SkFontMgr>> static_sk_font_mgr;
static int static_sk_font_mgr_index = 0;

int static_sk_font_mgr_make(sk_sp<SkFontMgr> value) {
    int key;
    if (!static_sk_font_mgr_available_keys.empty()) {
        auto it = static_sk_font_mgr_available_keys.begin();
        key = *it;
        static_sk_font_mgr_available_keys.erase(it);
    } else {
        key = static_sk_font_mgr_index++;
    }
    static_sk_font_mgr[key] = std::move(value);
    return key;
}

void static_sk_font_mgr_delete(int key) {
    static_sk_font_mgr[key].reset();
    static_sk_font_mgr.erase(key);
    static_sk_font_mgr_available_keys.insert(key);
}

void *static_sk_font_mgr_get(int key) { // -> SkFontMgr *
    return static_sk_font_mgr[key].get();
}

void static_sk_font_mgr_set(int key, sk_sp<SkFontMgr> value) {
    static_sk_font_mgr[key] = std::move(value);
}

sk_sp<SkFontMgr> static_sk_font_mgr_move(int key) {
    return std::move(static_sk_font_mgr[key]);
}
