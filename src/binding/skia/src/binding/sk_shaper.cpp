//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shaper.h"
#include "../static/static_sk_font_mgr.h"

extern "C" {

void SkShaper_delete(SkShaper *shaper) {
    delete shaper;
}

void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont *srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, *srcFont, leftToRight, width, handler);
}

void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, *font, *bidi, *script, *language, width, handler);
}

void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, *font, *bidi, *script, *language, features, featuresSize, width, handler);
}

// static

void SkShaper_MakePrimitive(int sk_shaper_key_out) {
    static_sk_shaper_set(sk_shaper_key_out, SkShaper::MakePrimitive());
}

void SkShaper_Make(int sk_shaper_key_out, int sk_font_mgr_key_in) {
    static_sk_shaper_set(sk_shaper_key_out, SkShaper::Make(static_sk_font_mgr_move(sk_font_mgr_key_in)));
}

void SkShaper_PurgeCaches() {
    SkShaper::PurgeCaches();
}

void SkShaper_MakeFontMgrRunIterator(int sk_shaper_font_run_iterator_key_out, int sk_font_mgr_key_in,
                                     const char *utf8, size_t utf8Bytes, const SkFont *font) {
    static_sk_shaper_font_run_iterator_set(sk_shaper_font_run_iterator_key_out, SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, *font, static_sk_font_mgr_move(sk_font_mgr_key_in)));
}

void SkShaper_MakeFontMgrRunIterator_2(int sk_shaper_font_run_iterator_key_out, int sk_font_mgr_key_in,
                                       const char *utf8, size_t utf8Bytes, const SkFont *font, const char *requestName,
                                       SkFontStyle requestStyle,
                                       const SkShaper::LanguageRunIterator *language_run_iterator) {
    static_sk_shaper_font_run_iterator_set(sk_shaper_font_run_iterator_key_out, SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, *font, static_sk_font_mgr_move(sk_font_mgr_key_in), requestName, requestStyle, language_run_iterator));
}

void SkShaper_MakeBiDiRunIterator(int sk_shaper_bi_di_run_iterator_key_out, const char *utf8, size_t utf8Bytes, uint8_t bidiLevel) {
    static_sk_shaper_bi_di_run_iterator_set(sk_shaper_bi_di_run_iterator_key_out, SkShaper::MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel));
}

void SkShaper_MakeScriptRunIterator(int sk_shaper_script_run_iterator_key_out, const char *utf8, size_t utf8Bytes, SkFourByteTag script) {
    static_sk_shaper_script_run_iterator_set(sk_shaper_script_run_iterator_key_out, SkShaper::MakeScriptRunIterator(utf8, utf8Bytes, script));
}

void SkShaper_MakeStdLanguageRunIterator(int sk_shaper_language_run_iterator_key_out, const char *utf8, size_t utf8Bytes) {
    static_sk_shaper_language_run_iterator_set(sk_shaper_language_run_iterator_key_out, SkShaper::MakeStdLanguageRunIterator(utf8, utf8Bytes));
}

}