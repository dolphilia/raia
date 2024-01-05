//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_MGR_H
#define RAIA_SKIA_STATIC_SK_FONT_MGR_H

#include <string>
#include <map>
#include "include/core/SkFontMgr.h"

void static_sk_font_mgr_delete(const char *key);
SkFontMgr *static_sk_font_mgr_get(const char *key);
void static_sk_font_mgr_set(const char *key, sk_sp<SkFontMgr> value);
sk_sp<SkFontMgr> static_sk_font_mgr_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_FONT_MGR_H
