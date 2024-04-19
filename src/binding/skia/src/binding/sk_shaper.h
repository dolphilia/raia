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
#include "../static/static_sk_font_mgr.h"
#include "../static/static_sk_font_style.h"

extern "C" {
void SkShaper_delete(SkShaper *shaper);
void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont *srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler);
// static
sk_shaper_t SkShaper_MakePrimitive();
sk_shaper_t SkShaper_Make(sk_font_mgr_t font_mgr);
void SkShaper_PurgeCaches();
sk_shaper_font_run_iterator_t SkShaper_MakeFontMgrRunIterator(const char *utf8, size_t utf8Bytes, const SkFont *font, sk_font_mgr_t font_mgr);
sk_shaper_font_run_iterator_t SkShaper_MakeFontMgrRunIterator_2(const char *utf8, size_t utf8Bytes, const SkFont *font, sk_font_mgr_t font_mgr, const char *requestName, sk_font_style_t requestStyle, const SkShaper::LanguageRunIterator *language_run_iterator);
sk_shaper_bi_di_run_iterator_t SkShaper_MakeBiDiRunIterator(const char *utf8, size_t utf8Bytes, uint8_t bidiLevel);
sk_shaper_script_run_iterator_t SkShaper_MakeScriptRunIterator(const char *utf8, size_t utf8Bytes, SkFourByteTag script);
sk_shaper_language_run_iterator_t SkShaper_MakeStdLanguageRunIterator(const char *utf8, size_t utf8Bytes);
}

#endif //RAIA_SKIA_SK_SHAPER_H
