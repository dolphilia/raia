//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_mgr.h"

extern "C" {

void SkFontMgr_delete(SkFontMgr *font_mgr) {
    delete font_mgr;
}

int SkFontMgr_countFamilies(SkFontMgr *font_mgr) {
    return font_mgr->countFamilies();
}
void SkFontMgr_getFamilyName(SkFontMgr *font_mgr, int index, SkString *familyName) {
    font_mgr->getFamilyName(index, familyName);
}

void SkFontMgr_createStyleSet(int sk_font_style_set_out, SkFontMgr *font_mgr, int index) {
    static_sk_font_style_set_set(sk_font_style_set_out, font_mgr->createStyleSet(index));
}

void SkFontMgr_matchFamily(int sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[]) {
    static_sk_font_style_set_set(sk_font_style_set_out, font_mgr->matchFamily(familyName));
}

int SkFontMgr_matchFamilyStyle(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style) {
    return static_sk_typeface_make(font_mgr->matchFamilyStyle(familyName, *font_style));
}

int SkFontMgr_matchFamilyStyleCharacter(SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character) {
    return static_sk_typeface_make(font_mgr->matchFamilyStyleCharacter(familyName, *font_style, bcp47, bcp47Count, character));
}

int SkFontMgr_makeFromData(int sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex) {
    return static_sk_typeface_make(font_mgr->makeFromData(static_sk_data_move(sk_data_key_in), ttcIndex));
}

int SkFontMgr_makeFromStream(int sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex) {
    return static_sk_typeface_make(font_mgr->makeFromStream(
            static_cast<std::unique_ptr<SkStreamAsset>>(static_sk_stream_asset_get(sk_stream_asset_key_in)), ttcIndex));
}

int SkFontMgr_makeFromStream_2(int sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments) {
    return static_sk_typeface_make(font_mgr->makeFromStream(
            static_cast<std::unique_ptr<SkStreamAsset>>(static_sk_stream_asset_get(sk_stream_asset_key_in)), *font_argments));
}

int SkFontMgr_makeFromFile(SkFontMgr *font_mgr, const char path[], int ttcIndex) {
    return static_sk_typeface_make(font_mgr->makeFromFile(path, ttcIndex));
}

int SkFontMgr_legacyMakeTypeface(SkFontMgr *font_mgr, const char familyName[], SkFontStyle style) {
    return static_sk_typeface_make(font_mgr->legacyMakeTypeface(familyName, style));
}

bool SkFontMgr_unique(SkFontMgr *font_mgr) {
    return font_mgr->unique();
}

void SkFontMgr_ref(SkFontMgr *font_mgr) {
    font_mgr->ref();
}

void SkFontMgr_unref(SkFontMgr *font_mgr) {
    font_mgr->unref();
}

// static

int SkFontMgr_RefEmpty() {
    return static_sk_font_mgr_make(SkFontMgr::RefEmpty());
}

#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)
int SkFontMgr_RefDefault() {
    return static_sk_font_mgr_make(SkFontMgr::RefDefault());
}
#endif

}