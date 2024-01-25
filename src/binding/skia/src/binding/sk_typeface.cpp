//
// Created by dolphilia on 2024/01/11.
//

#include "sk_typeface.h"
#include "../static/static_sk_font_mgr.h"

extern "C" {

int SkTypeface_fontStyle(SkTypeface *typeface) {
    return static_sk_font_style_make(typeface->fontStyle());
}

bool SkTypeface_isBold(SkTypeface *typeface) {
    return typeface->isBold();
}

bool SkTypeface_isItalic(SkTypeface *typeface) {
    return typeface->isItalic();
}

bool SkTypeface_isFixedPitch(SkTypeface *typeface) {
    return typeface->isFixedPitch();
}

int SkTypeface_getVariationDesignPosition(SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount) {
    return typeface->getVariationDesignPosition(coordinates, coordinateCount);
}

int SkTypeface_getVariationDesignParameters(SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount) {
    return typeface->getVariationDesignParameters(parameters, parameterCount);
}

SkTypefaceID SkTypeface_uniqueID(SkTypeface *typeface) {
    return typeface->uniqueID();
}

int SkTypeface_makeClone(SkTypeface *typeface, const SkFontArguments *arguments) {
    return static_sk_typeface_make(typeface->makeClone(*arguments));
}

void SkTypeface_serialize(SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior) {
    typeface->serialize(stream, behavior);
}

int SkTypeface_serialize_2(SkTypeface *typeface, SkTypeface::SerializeBehavior behavior) {
    return static_sk_data_make(typeface->serialize(behavior));
}

void SkTypeface_unicharsToGlyphs(SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[]) {
    typeface->unicharsToGlyphs(uni, count, glyphs);
}

int SkTypeface_textToGlyphs(SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) {
    return typeface->textToGlyphs(text, byteLength, encoding, glyphs, maxGlyphCount);
}

SkGlyphID SkTypeface_unicharToGlyph(SkTypeface *typeface, SkUnichar unichar) {
    return typeface->unicharToGlyph(unichar);
}

int SkTypeface_countGlyphs(SkTypeface *typeface) {
    return typeface->countGlyphs();
}

int SkTypeface_countTables(SkTypeface *typeface) {
    return typeface->countTables();
}

int SkTypeface_getTableTags(SkTypeface *typeface, SkFontTableTag tags[]) {
    return typeface->getTableTags(tags);
}

size_t SkTypeface_getTableSize(SkTypeface *typeface, SkFontTableTag tag) {
    return typeface->getTableSize(tag);
}

size_t SkTypeface_getTableData(SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data) {
    return typeface->getTableData(tag, offset, length, data);
}

int SkTypeface_copyTableData(SkTypeface *typeface, SkFontTableTag tag) {
    return static_sk_data_make(typeface->copyTableData(tag));
}

int SkTypeface_getUnitsPerEm(SkTypeface *typeface) {
    return typeface->getUnitsPerEm();
}

bool SkTypeface_getKerningPairAdjustments(SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]) {
    return typeface->getKerningPairAdjustments(glyphs, count, adjustments);
}

SkTypeface::LocalizedStrings * SkTypeface_createFamilyNameIterator(SkTypeface *typeface) {
    return typeface->createFamilyNameIterator();
}

void SkTypeface_getFamilyName(SkTypeface *typeface, SkString *name) {
    typeface->getFamilyName(name);
}

bool SkTypeface_getPostScriptName(SkTypeface *typeface, SkString *name) {
    return typeface->getPostScriptName(name);
}

int SkTypeface_openStream(SkTypeface *typeface, int *ttcIndex) {
    return static_sk_stream_asset_make(typeface->openStream(ttcIndex));
}

int SkTypeface_openExistingStream(SkTypeface *typeface, int *ttcIndex) {
    return static_sk_stream_asset_make(typeface->openExistingStream(ttcIndex));
}

//@TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor) {
//    return typeface->createScalerContext(effects, descriptor);
//}

int SkTypeface_getBounds(SkTypeface *typeface) {
    return static_sk_rect_make(typeface->getBounds());
}

void SkTypeface_filterRec(SkTypeface *typeface, SkScalerContextRec *rec) {
    typeface->filterRec(rec);
}

void SkTypeface_getFontDescriptor(SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal) {
    typeface->getFontDescriptor(desc, isLocal);
}

void * SkTypeface_internal_private_getCTFontRef(SkTypeface *typeface) {
    return typeface->internal_private_getCTFontRef();
}

// static

bool SkTypeface_Equal(const SkTypeface *facea, const SkTypeface *faceb) {
    return SkTypeface::Equal(facea, faceb);
}

// @TODO
//sk_sp<SkTypeface> SkTypeface_MakeDefault() {
//    return SkTypeface::MakeDefault();
//}

int SkTypeface_MakeEmpty() {
    return static_sk_typeface_make(SkTypeface::MakeEmpty());
}

int SkTypeface_MakeFromName(const char familyName[], SkFontStyle fontStyle) {
    return static_sk_typeface_make(SkTypeface::MakeFromName(familyName, fontStyle));
}

int SkTypeface_MakeFromFile(const char path[], int index) {
    return static_sk_typeface_make(SkTypeface::MakeFromFile(path, index));
}

int SkTypeface_MakeFromStream(int sk_stream_asset_key_in, int index) {
    return static_sk_typeface_make(SkTypeface::MakeFromStream(static_sk_stream_asset_move(sk_stream_asset_key_in), index));
}

int SkTypeface_MakeFromData(int sk_data_key_in, int index) {
    return static_sk_typeface_make(SkTypeface::MakeFromData(static_sk_data_move(sk_data_key_in), index));
}

int SkTypeface_MakeDeserialize(SkStream *stream) {
    return static_sk_typeface_make(SkTypeface::MakeDeserialize(stream));
}

int SkTypeface_MakeDeserialize_2(int sk_font_mgr_key_in, SkStream *stream) {
    return static_sk_typeface_make(SkTypeface::MakeDeserialize(stream, static_sk_font_mgr_move(sk_font_mgr_key_in)));
}

void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &)) {
    SkTypeface::Register(id, make);
}

}