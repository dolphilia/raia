//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_MGR_H
#define RAIA_SKIA_SK_FONT_MGR_H

#ifdef __cplusplus
extern "C" {
#endif

void SkFontMgr_delete(void *font_mgr); // (SkFontMgr *font_mgr)
int SkFontMgr_countFamilies(void *font_mgr); // (SkFontMgr *font_mgr) -> int
void SkFontMgr_getFamilyName(void *font_mgr, int index, void *familyName); // (SkFontMgr *font_mgr, int index, SkString *familyName)
void SkFontMgr_createStyleSet(int sk_font_style_set_out, void *font_mgr, int index); // (int sk_font_style_set_out, SkFontMgr *font_mgr, int index)
void SkFontMgr_matchFamily(int sk_font_style_set_out, void *font_mgr, const char familyName[]); // (int sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[])
int SkFontMgr_matchFamilyStyle(void *font_mgr, const char familyName[], const void *font_style); // (SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style) -> sk_typeface_t
int SkFontMgr_matchFamilyStyleCharacter(void *font_mgr, const char familyName[], const void *font_style, const char *bcp47[], int bcp47Count, int character); // (SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character) -> sk_typeface_t
int SkFontMgr_makeFromData(void *font_mgr, int data, int ttcIndex); // (SkFontMgr *font_mgr, sk_data_t data, int ttcIndex) -> sk_typeface_t
int SkFontMgr_makeFromStream(void *font_mgr, int stream_asset, int ttcIndex); // (SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, int ttcIndex) -> sk_typeface_t
int SkFontMgr_makeFromStream_2(void *font_mgr, int stream_asset, const void *font_argments); // (SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, const SkFontArguments *font_argments) -> sk_typeface_t
int SkFontMgr_makeFromFile(void *font_mgr, const char path[], int ttcIndex); // (SkFontMgr *font_mgr, const char path[], int ttcIndex) -> sk_typeface_t
int SkFontMgr_legacyMakeTypeface(void *font_mgr, const char familyName[], int style); // (SkFontMgr *font_mgr, const char familyName[], sk_font_style_t style) -> sk_typeface_t
bool SkFontMgr_unique(void *font_mgr); // (SkFontMgr *font_mgr) -> bool
void SkFontMgr_ref(void *font_mgr); // (SkFontMgr *font_mgr)
void SkFontMgr_unref(void *font_mgr); // (SkFontMgr *font_mgr)
// static
int SkFontMgr_RefEmpty(); // () -> sk_font_mgr_t
#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)
int SkFontMgr_RefDefault(); // () -> sk_font_mgr_t
#endif

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FONT_MGR_H
