//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_H
#define RAIA_SKIA_SK_FONT_H

#include "include/core/SkFont.h"
#include "../static/static_sk_typeface.h"
#include "../static/static_std_vector_sk_scalar.h"
#include "../static/static_sk_font.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
RAIA_API SkFont *SkFont_new();
RAIA_API SkFont *SkFont_new_2(sk_typeface_t typeface, SkScalar size);
RAIA_API SkFont *SkFont_new_3(sk_typeface_t typeface);
RAIA_API SkFont *SkFont_new_4(sk_typeface_t typeface, SkScalar size, SkScalar scaleX, SkScalar skewX);
RAIA_API void SkFont_delete(SkFont *font);
RAIA_API bool SkFont_isForceAutoHinting(SkFont *font);
RAIA_API bool SkFont_isEmbeddedBitmaps(SkFont *font);
RAIA_API bool SkFont_isSubpixel(SkFont *font);
RAIA_API bool SkFont_isLinearMetrics(SkFont *font);
RAIA_API bool SkFont_isEmbolden(SkFont *font);
RAIA_API bool SkFont_isBaselineSnap(SkFont *font);
RAIA_API void SkFont_setForceAutoHinting(SkFont *font, bool forceAutoHinting);
RAIA_API void SkFont_setEmbeddedBitmaps(SkFont *font, bool embeddedBitmaps);
RAIA_API void SkFont_setSubpixel(SkFont *font, bool subpixel);
RAIA_API void SkFont_setLinearMetrics(SkFont *font, bool linearMetrics);
RAIA_API void SkFont_setEmbolden(SkFont *font, bool embolden);
RAIA_API void SkFont_setBaselineSnap(SkFont *font, bool baselineSnap);
RAIA_API SkFont::Edging SkFont_getEdging(SkFont *font);
RAIA_API void SkFont_setEdging(SkFont *font, SkFont::Edging edging);
RAIA_API void SkFont_setHinting(SkFont *font, SkFontHinting hintingLevel);
RAIA_API SkFontHinting SkFont_getHinting(SkFont *font);
RAIA_API sk_font_t SkFont_makeWithSize(SkFont *font, SkScalar size);
RAIA_API SkTypeface * SkFont_getTypeface(SkFont *font);
RAIA_API SkScalar SkFont_getSize(SkFont *font);
RAIA_API SkScalar SkFont_getScaleX(SkFont *font);
RAIA_API SkScalar SkFont_getSkewX(SkFont *font);
RAIA_API sk_typeface_t SkFont_refTypeface(SkFont *font);
RAIA_API void SkFont_setTypeface(SkFont *font, sk_typeface_t typeface);
RAIA_API void SkFont_setSize(SkFont *font, SkScalar textSize);
RAIA_API void SkFont_setScaleX(SkFont *font, SkScalar scaleX);
RAIA_API void SkFont_setSkewX(SkFont *font, SkScalar skewX);
RAIA_API int SkFont_textToGlyphs(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount);
RAIA_API SkGlyphID SkFont_unicharToGlyph(SkFont *font, SkUnichar uni);
RAIA_API void SkFont_unicharsToGlyphs(SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[]);
RAIA_API int SkFont_countText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding);
RAIA_API SkScalar SkFont_measureText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds);
RAIA_API SkScalar SkFont_measureText_2(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint);
RAIA_API void SkFont_getWidths(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[]);
// @TODO
RAIA_API void SkFont_getWidths_2(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr);
RAIA_API void SkFont_getWidths_3(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[]);
RAIA_API void SkFont_getWidthsBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint);
RAIA_API void SkFont_getBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint);
RAIA_API void SkFont_getPos(SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], sk_point_t origin);
RAIA_API void SkFont_getXPos(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin);
RAIA_API int SkFont_getIntercepts(SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint);
RAIA_API bool SkFont_getPath(SkFont *font, SkGlyphID glyphID, SkPath *path);
// @TODO
RAIA_API void SkFont_getPaths(SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx);
RAIA_API SkScalar SkFont_getMetrics(SkFont *font, SkFontMetrics *metrics);
RAIA_API SkScalar SkFont_getSpacing(SkFont *font);
RAIA_API void SkFont_dump(SkFont *font);
}

#endif //RAIA_SKIA_SK_FONT_H
