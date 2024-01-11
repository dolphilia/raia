//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shaper.h"

extern "C" {

void SkShaper_delete(SkShaper *shaper) {
    delete shaper;
}

void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont &srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, srcFont, leftToRight, width, handler);
}

void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, font, bidi, script, language, width, handler);
}

void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, font, bidi, script, language, features, featuresSize, width, handler);
}

// static

void SkShaper_MakePrimitive(const char *sk_shaper_key_out) {
    static_sk_shaper_set(sk_shaper_key_out, SkShaper::MakePrimitive());
}

void SkShaper_Make(const char *sk_shaper_key_out, sk_sp<SkFontMgr> font_mgr) {
    static_sk_shaper_set(sk_shaper_key_out, SkShaper::Make(std::move(font_mgr)));
}

void SkShaper_PurgeCaches() {
    SkShaper::PurgeCaches();
}

void SkShaper_MakeFontMgrRunIterator(const char *sk_shaper_font_run_iterator_key_out, const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback) {
    static_sk_shaper_font_run_iterator_set(sk_shaper_font_run_iterator_key_out, SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, font, std::move(fallback)));
}

void SkShaper_MakeFontMgrRunIterator_2(const char *sk_shaper_font_run_iterator_key_out, const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback, const char *requestName, SkFontStyle requestStyle, const SkShaper::LanguageRunIterator *language_run_iterator) {
    static_sk_shaper_font_run_iterator_set(sk_shaper_font_run_iterator_key_out, SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, font, std::move(fallback), requestName, requestStyle, language_run_iterator));
}

void SkShaper_MakeBiDiRunIterator(const char *sk_shaper_bi_di_run_iterator_key_out, const char *utf8, size_t utf8Bytes, uint8_t bidiLevel) {
    static_sk_shaper_bi_di_run_iterator_set(sk_shaper_bi_di_run_iterator_key_out, SkShaper::MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel));
}

void SkShaper_MakeScriptRunIterator(const char *sk_shaper_script_run_iterator_key_out, const char *utf8, size_t utf8Bytes, SkFourByteTag script) {
    static_sk_shaper_script_run_iterator_set(sk_shaper_script_run_iterator_key_out, SkShaper::MakeScriptRunIterator(utf8, utf8Bytes, script));
}

void SkShaper_MakeStdLanguageRunIterator(const char *sk_shaper_language_run_iterator_key_out, const char *utf8, size_t utf8Bytes) {
    static_sk_shaper_language_run_iterator_set(sk_shaper_language_run_iterator_key_out, SkShaper::MakeStdLanguageRunIterator(utf8, utf8Bytes));
}

}