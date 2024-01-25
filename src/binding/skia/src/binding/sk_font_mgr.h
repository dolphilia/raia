//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_MGR_H
#define RAIA_SKIA_SK_FONT_MGR_H

#include "include/core/SkFontMgr.h"
#include "../static/static_sk_font_mgr.h"
#include "../static/static_sk_font_style_set.h"
#include "../static/static_sk_typeface.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
int SkFontMgr_countFamilies(SkFontMgr *font_mgr);
void SkFontMgr_getFamilyName(SkFontMgr *font_mgr, int index, SkString *familyName);
void SkFontMgr_createStyleSet(int sk_font_style_set_out, SkFontMgr *font_mgr, int index);
void SkFontMgr_matchFamily(int sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[]);
int SkFontMgr_matchFamilyStyle(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style);
int SkFontMgr_matchFamilyStyleCharacter(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character);
int SkFontMgr_makeFromData(int sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex);
int SkFontMgr_makeFromStream(int sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex);
int SkFontMgr_makeFromStream_2(int sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments);
int SkFontMgr_makeFromFile(SkFontMgr *font_mgr, const char path[], int ttcIndex);
int SkFontMgr_legacyMakeTypeface(SkFontMgr *font_mgr, const char familyName[], SkFontStyle style);
bool SkFontMgr_unique(SkFontMgr *font_mgr);
void SkFontMgr_ref(SkFontMgr *font_mgr);
void SkFontMgr_unref(SkFontMgr *font_mgr);
// static
int SkFontMgr_RefDefault();
int SkFontMgr_RefEmpty();
}

#endif //RAIA_SKIA_SK_FONT_MGR_H
