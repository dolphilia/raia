//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font.h"

extern "C" {

SkFont *SkFont_new() {
    return new SkFont();
}

SkFont *SkFont_new_2(sk_typeface_t typeface, SkScalar size) {
    return new SkFont(static_sk_typeface_move(typeface), size);
}

SkFont *SkFont_new_3(sk_typeface_t typeface) {
    return new SkFont(static_sk_typeface_move(typeface));
}

SkFont *SkFont_new_4(sk_typeface_t typeface, SkScalar size, SkScalar scaleX, SkScalar skewX) {
    return new SkFont(static_sk_typeface_move(typeface), size, scaleX, skewX);
}

void SkFont_delete(SkFont *font) {
    delete font;
}

bool SkFont_isForceAutoHinting(SkFont *font) {
    return font->isForceAutoHinting();
}

bool SkFont_isEmbeddedBitmaps(SkFont *font) {
    return font->isEmbeddedBitmaps();
}

bool SkFont_isSubpixel(SkFont *font) {
    return font->isSubpixel();
}

bool SkFont_isLinearMetrics(SkFont *font) {
    return font->isLinearMetrics();
}

bool SkFont_isEmbolden(SkFont *font) {
    return font->isEmbolden();
}

bool SkFont_isBaselineSnap(SkFont *font) {
    return font->isBaselineSnap();
}

void SkFont_setForceAutoHinting(SkFont *font, bool forceAutoHinting) {
    font->setForceAutoHinting(forceAutoHinting);
}

void SkFont_setEmbeddedBitmaps(SkFont *font, bool embeddedBitmaps) {
    font->setEmbeddedBitmaps(embeddedBitmaps);
}

void SkFont_setSubpixel(SkFont *font, bool subpixel) {
    font->setSubpixel(subpixel);
}

void SkFont_setLinearMetrics(SkFont *font, bool linearMetrics) {
    font->setLinearMetrics(linearMetrics);
}

void SkFont_setEmbolden(SkFont *font, bool embolden) {
    font->setEmbolden(embolden);
}

void SkFont_setBaselineSnap(SkFont *font, bool baselineSnap) {
    font->setBaselineSnap(baselineSnap);
}

SkFont::Edging SkFont_getEdging(SkFont *font) {
    return font->getEdging();
}

void SkFont_setEdging(SkFont *font, SkFont::Edging edging) {
    font->setEdging(edging);
}

void SkFont_setHinting(SkFont *font, SkFontHinting hintingLevel) {
    font->setHinting(hintingLevel);
}

SkFontHinting SkFont_getHinting(SkFont *font) {
    return font->getHinting();
}

sk_font_t SkFont_makeWithSize(SkFont *font, SkScalar size) {
    return static_sk_font_make(font->makeWithSize(size));
}

SkTypeface * SkFont_getTypeface(SkFont *font) {
    return font->getTypeface();
}

SkScalar SkFont_getSize(SkFont *font) {
    return font->getSize();
}

SkScalar SkFont_getScaleX(SkFont *font) {
    return font->getScaleX();
}

SkScalar SkFont_getSkewX(SkFont *font) {
    return font->getSkewX();
}

sk_typeface_t SkFont_refTypeface(SkFont *font) {
    return static_sk_typeface_make(font->refTypeface());
}

void SkFont_setTypeface(SkFont *font, sk_typeface_t typeface) {
    //font->setTypeface(static_sk_typeface_move(typeface));
}

void SkFont_setSize(SkFont *font, SkScalar textSize) {
    font->setSize(textSize);
}

void SkFont_setScaleX(SkFont *font, SkScalar scaleX) {
    font->setScaleX(scaleX);
}

void SkFont_setSkewX(SkFont *font, SkScalar skewX) {
    font->setSkewX(skewX);
}

int SkFont_textToGlyphs(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) {
    return font->textToGlyphs(text, byteLength, encoding, glyphs, maxGlyphCount);
}

SkGlyphID SkFont_unicharToGlyph(SkFont *font, SkUnichar uni) {
    return font->unicharToGlyph(uni);
}

void SkFont_unicharsToGlyphs(SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[]) {
    font->unicharsToGlyphs(uni, count, glyphs);
}

int SkFont_countText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding) {
    return font->countText(text, byteLength, encoding);
}

SkScalar SkFont_measureText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds) {
    return font->measureText(text, byteLength, encoding, bounds);
}

SkScalar SkFont_measureText_2(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint) {
    return font->measureText(text, byteLength, encoding, bounds, paint);
}

void SkFont_getWidths(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[]) {
    font->getWidths(glyphs, count, widths, bounds);
}

void SkFont_getWidths_2(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr) { // @TODO
    font->getWidths(glyphs, count, widths, ptr);
}

void SkFont_getWidths_3(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[]) {
    font->getWidths(glyphs, count, widths);
}

void SkFont_getWidthsBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint) {
    font->getWidthsBounds(glyphs, count, widths, bounds, paint);
}

void SkFont_getBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint) {
    font->getBounds(glyphs, count, bounds, paint);
}

void SkFont_getPos(SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], sk_point_t origin) {
    font->getPos(glyphs, count, pos, static_sk_point_get(origin));
}

void SkFont_getXPos(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin) {
    font->getXPos(glyphs, count, xpos, origin);
}

int SkFont_getIntercepts(SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint) { // @TODO
    return static_vector_sk_scalar_make(font->getIntercepts(glyphs, count, pos, top, bottom, paint));
}

bool SkFont_getPath(SkFont *font, SkGlyphID glyphID, SkPath *path) {
    return font->getPath(glyphID, path);
}

void SkFont_getPaths(SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx) { // @TODO
    font->getPaths(glyphIDs, count, glyphPathProc, ctx);
}

SkScalar SkFont_getMetrics(SkFont *font, SkFontMetrics *metrics) {
    return font->getMetrics(metrics);
}

SkScalar SkFont_getSpacing(SkFont *font) {
    return font->getSpacing();
}

void SkFont_dump(SkFont *font) {
    font->dump();
}

}