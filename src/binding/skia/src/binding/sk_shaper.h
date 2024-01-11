//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SHAPER_H
#define RAIA_SKIA_SK_SHAPER_H

#include <utility>
#include "modules/skshaper/include/SkShaper.h"
#include "../static/static_sk_shaper.h"
#include "../static/static_sk_shaper_font_run_iterator.h"
#include "../static/static_sk_shaper_bi_di_run_iterator.h"
#include "../static/static_sk_shaper_script_run_iterator.h"
#include "../static/static_sk_shaper_language_run_iterator.h"

extern "C" {
void SkShaper_delete(SkShaper *shaper);
void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont &srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler);
// static
void SkShaper_MakePrimitive(const char *sk_shaper_key_out);
void SkShaper_Make(const char *sk_shaper_key_out, sk_sp<SkFontMgr> font_mgr);
void SkShaper_PurgeCaches();
void SkShaper_MakeFontMgrRunIterator(const char *sk_shaper_font_run_iterator_key_out, const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback);
void SkShaper_MakeFontMgrRunIterator_2(const char *sk_shaper_font_run_iterator_key_out, const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback, const char *requestName, SkFontStyle requestStyle, const SkShaper::LanguageRunIterator *language_run_iterator);
void SkShaper_MakeBiDiRunIterator(const char *sk_shaper_bi_di_run_iterator_key_out, const char *utf8, size_t utf8Bytes, uint8_t bidiLevel);
void SkShaper_MakeScriptRunIterator(const char *sk_shaper_script_run_iterator_key_out, const char *utf8, size_t utf8Bytes, SkFourByteTag script);
void SkShaper_MakeStdLanguageRunIterator(const char *sk_shaper_language_run_iterator_key_out, const char *utf8, size_t utf8Bytes);
}

#endif //RAIA_SKIA_SK_SHAPER_H
