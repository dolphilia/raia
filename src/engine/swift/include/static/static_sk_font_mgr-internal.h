#ifndef STATIC_SK_FONT_MGR_INTERNAL_H
#define STATIC_SK_FONT_MGR_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFontMgr.h"
int static_sk_font_mgr_make(sk_sp<SkFontMgr> value);
void static_sk_font_mgr_set(int key, sk_sp<SkFontMgr> value);
sk_sp<SkFontMgr> static_sk_font_mgr_move(int key);
#endif // STATIC_SK_FONT_MGR_INTERNAL_H
