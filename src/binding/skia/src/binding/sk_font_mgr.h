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
void SkFontMgr_matchFamilyStyle(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style);
void SkFontMgr_matchFamilyStyleCharacter(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character);
void SkFontMgr_makeFromData(int sk_typeface_key_out, int sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex);
void SkFontMgr_makeFromStream(int sk_typeface_key_out, int sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex);
void SkFontMgr_makeFromStream_2(int sk_typeface_key_out, int sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments);
void SkFontMgr_makeFromFile(int sk_typeface_key_out, SkFontMgr *font_mgr, const char path[], int ttcIndex);
void SkFontMgr_legacyMakeTypeface(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], SkFontStyle style);
bool SkFontMgr_unique(SkFontMgr *font_mgr);
void SkFontMgr_ref(SkFontMgr *font_mgr);
void SkFontMgr_unref(SkFontMgr *font_mgr);
// static
void SkFontMgr_RefDefault(int sk_font_mgr_key_out);
void SkFontMgr_RefEmpty(int sk_font_mgr_key_out);
}

#endif //RAIA_SKIA_SK_FONT_MGR_H
