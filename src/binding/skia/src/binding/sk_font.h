//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_H
#define RAIA_SKIA_SK_FONT_H

#include "include/core/SkFont.h"
#include "../static/static_sk_typeface.h"

extern "C" {
SkFont *SkFont_new();
SkFont *SkFont_new_2(const char *sk_typeface_key_in, SkScalar size);
SkFont *SkFont_new_3(const char *sk_typeface_key_in);
SkFont *SkFont_new_4(const char *sk_typeface_key_in, SkScalar size, SkScalar scaleX, SkScalar skewX);
bool SkFont_isForceAutoHinting(SkFont *font);
bool SkFont_isEmbeddedBitmaps(SkFont *font);
bool SkFont_isSubpixel(SkFont *font);
bool SkFont_isLinearMetrics(SkFont *font);
bool SkFont_isEmbolden(SkFont *font);
bool SkFont_isBaselineSnap(SkFont *font);
void SkFont_setForceAutoHinting(SkFont *font, bool forceAutoHinting);
void SkFont_setEmbeddedBitmaps(SkFont *font, bool embeddedBitmaps);
void SkFont_setSubpixel(SkFont *font, bool subpixel);
void SkFont_setLinearMetrics(SkFont *font, bool linearMetrics);
void SkFont_setEmbolden(SkFont *font, bool embolden);
void SkFont_setBaselineSnap(SkFont *font, bool baselineSnap);
SkFont::Edging SkFont_getEdging(SkFont *font);
void SkFont_setEdging(SkFont *font, SkFont::Edging edging);
void SkFont_setHinting(SkFont *font, SkFontHinting hintingLevel);
SkFontHinting SkFont_getHinting(SkFont *font);
void SkFont_makeWithSize(const char *sk_font_key_out, SkFont *font, SkScalar size);
SkTypeface * SkFont_getTypeface(SkFont *font);
SkScalar SkFont_getSize(SkFont *font);
SkScalar SkFont_getScaleX(SkFont *font);
SkScalar SkFont_getSkewX(SkFont *font);
void SkFont_refTypeface(const char *sk_typeface_key_out, SkFont *font);
void SkFont_setTypeface(const char *sk_typeface_key_in, SkFont *font);
void SkFont_setSize(SkFont *font, SkScalar textSize);
void SkFont_setScaleX(SkFont *font, SkScalar scaleX);
void SkFont_setSkewX(SkFont *font, SkScalar skewX);
int SkFont_textToGlyphs(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount);
SkGlyphID SkFont_unicharToGlyph(SkFont *font, SkUnichar uni);
void SkFont_unicharsToGlyphs(SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[]);
int SkFont_countText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding);
SkScalar SkFont_measureText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds);
SkScalar SkFont_measureText_2(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint);
void SkFont_getWidths(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[]);
// @TODO
void SkFont_getWidths_2(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr);
void SkFont_getWidths_3(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[]);
void SkFont_getWidthsBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint);
void SkFont_getBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint);
void SkFont_getPos(SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], SkPoint origin);
void SkFont_getXPos(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin);
void SkFont_getIntercepts(const char* vector_sk_scalar_key_out, SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint);
bool SkFont_getPath(SkFont *font, SkGlyphID glyphID, SkPath *path);
// @TODO
void SkFont_getPaths(SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx);
SkScalar SkFont_getMetrics(SkFont *font, SkFontMetrics *metrics);
SkScalar SkFont_getSpacing(SkFont *font);
void SkFont_dump(SkFont *font);
}

#endif //RAIA_SKIA_SK_FONT_H