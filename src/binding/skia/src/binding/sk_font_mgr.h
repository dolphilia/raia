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
void SkFontMgr_createStyleSet(const char *sk_font_style_set_out, SkFontMgr *font_mgr, int index);
void SkFontMgr_matchFamily(const char *sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[]);
void SkFontMgr_matchFamilyStyle(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style);
void SkFontMgr_matchFamilyStyleCharacter(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character);
void SkFontMgr_makeFromData(const char *sk_typeface_key_out, const char *sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex);
void SkFontMgr_makeFromStream(const char *sk_typeface_key_out, const char *sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex);
void SkFontMgr_makeFromStream_2(const char *sk_typeface_key_out, const char *sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments);
void SkFontMgr_makeFromFile(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char path[], int ttcIndex);
void SkFontMgr_legacyMakeTypeface(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], SkFontStyle style);
bool SkFontMgr_unique(SkFontMgr *font_mgr);
void SkFontMgr_ref(SkFontMgr *font_mgr);
void SkFontMgr_unref(SkFontMgr *font_mgr);
// static
void SkFontMgr_RefDefault(const char *sk_font_mgr_key_out);
void SkFontMgr_RefEmpty(const char *sk_font_mgr_key_out);
}

#endif //RAIA_SKIA_SK_FONT_MGR_H
