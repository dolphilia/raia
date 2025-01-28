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
#include "../static/static_sk_font_style.h"

extern "C" {
void SkFontMgr_delete(SkFontMgr *font_mgr);
int SkFontMgr_countFamilies(SkFontMgr *font_mgr);
void SkFontMgr_getFamilyName(SkFontMgr *font_mgr, int index, SkString *familyName);
void SkFontMgr_createStyleSet(int sk_font_style_set_out, SkFontMgr *font_mgr, int index);
void SkFontMgr_matchFamily(int sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[]);
sk_typeface_t SkFontMgr_matchFamilyStyle(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style);
sk_typeface_t SkFontMgr_matchFamilyStyleCharacter(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character);
sk_typeface_t SkFontMgr_makeFromData(SkFontMgr *font_mgr, sk_data_t data, int ttcIndex);
sk_typeface_t SkFontMgr_makeFromStream(SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, int ttcIndex);
sk_typeface_t SkFontMgr_makeFromStream_2(SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, const SkFontArguments *font_argments);
sk_typeface_t SkFontMgr_makeFromFile(SkFontMgr *font_mgr, const char path[], int ttcIndex);
sk_typeface_t SkFontMgr_legacyMakeTypeface(SkFontMgr *font_mgr, const char familyName[], sk_font_style_t style);
bool SkFontMgr_unique(SkFontMgr *font_mgr);
void SkFontMgr_ref(SkFontMgr *font_mgr);
void SkFontMgr_unref(SkFontMgr *font_mgr);
// static
sk_font_mgr_t SkFontMgr_RefEmpty();
#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)
sk_font_mgr_t SkFontMgr_RefDefault();
#endif
}

#endif //RAIA_SKIA_SK_FONT_MGR_H
