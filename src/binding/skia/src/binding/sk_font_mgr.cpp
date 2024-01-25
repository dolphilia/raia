//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_mgr.h"

extern "C" {

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

void SkFontMgr_matchFamilyStyle(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->matchFamilyStyle(familyName, *font_style));
}

void SkFontMgr_matchFamilyStyleCharacter(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->matchFamilyStyleCharacter(familyName, *font_style, bcp47, bcp47Count, character));
}

void SkFontMgr_makeFromData(int sk_typeface_key_out, int sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->makeFromData(static_sk_data_move(sk_data_key_in), ttcIndex));
}

void SkFontMgr_makeFromStream(int sk_typeface_key_out, int sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->makeFromStream(
            static_cast<std::unique_ptr<SkStreamAsset>>(static_sk_stream_asset_get(sk_stream_asset_key_in)), ttcIndex));
}

void SkFontMgr_makeFromStream_2(int sk_typeface_key_out, int sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->makeFromStream(
            static_cast<std::unique_ptr<SkStreamAsset>>(static_sk_stream_asset_get(sk_stream_asset_key_in)), *font_argments));
}

void SkFontMgr_makeFromFile(int sk_typeface_key_out, SkFontMgr *font_mgr, const char path[], int ttcIndex) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->makeFromFile(path, ttcIndex));
}

void SkFontMgr_legacyMakeTypeface(int sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], SkFontStyle style) {
    static_sk_typeface_set(sk_typeface_key_out, font_mgr->legacyMakeTypeface(familyName, style));
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

void SkFontMgr_RefDefault(int sk_font_mgr_key_out) {
    static_sk_font_mgr_set(sk_font_mgr_key_out, SkFontMgr::RefDefault());
}

void SkFontMgr_RefEmpty(int sk_font_mgr_key_out) {
    static_sk_font_mgr_set(sk_font_mgr_key_out, SkFontMgr::RefEmpty());
}

}