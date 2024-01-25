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
void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont *srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, SkScalar width, SkShaper::RunHandler *handler);
void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator *font, SkShaper::BiDiRunIterator *bidi, SkShaper::ScriptRunIterator *script, SkShaper::LanguageRunIterator *language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler);
// static
int SkShaper_MakePrimitive();
int SkShaper_Make(int sk_font_mgr_key_in);
void SkShaper_PurgeCaches();
int SkShaper_MakeFontMgrRunIterator(int sk_font_mgr_key_in,
                                     const char *utf8, size_t utf8Bytes, const SkFont *font);
int SkShaper_MakeFontMgrRunIterator_2(int sk_font_mgr_key_in,
                                       const char *utf8, size_t utf8Bytes, const SkFont *font, const char *requestName,
                                       SkFontStyle requestStyle,
                                       const SkShaper::LanguageRunIterator *language_run_iterator);
int SkShaper_MakeBiDiRunIterator(const char *utf8, size_t utf8Bytes, uint8_t bidiLevel);
int SkShaper_MakeScriptRunIterator(const char *utf8, size_t utf8Bytes, SkFourByteTag script);
int SkShaper_MakeStdLanguageRunIterator(const char *utf8, size_t utf8Bytes);
}

#endif //RAIA_SKIA_SK_SHAPER_H
