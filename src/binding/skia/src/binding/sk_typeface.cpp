//
// Created by dolphilia on 2024/01/11.
//

#include "sk_typeface.h"
#include "../static/static_sk_font_mgr.h"

extern "C" {

void SkTypeface_fontStyle(const char *sk_font_style_key_out, SkTypeface *typeface) {
    static_sk_font_style_set(sk_font_style_key_out, typeface->fontStyle());
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

void SkTypeface_makeClone(const char *sk_typeface_key_out, SkTypeface *typeface, const SkFontArguments *arguments) {
    static_sk_typeface_set(sk_typeface_key_out, typeface->makeClone(*arguments));
}

void SkTypeface_serialize(SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior) {
    typeface->serialize(stream, behavior);
}

void SkTypeface_serialize_2(const char *sk_data_key_out, SkTypeface *typeface, SkTypeface::SerializeBehavior behavior) {
    static_sk_data_set(sk_data_key_out, typeface->serialize(behavior));
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

void SkTypeface_copyTableData(const char *sk_data_key_out, SkTypeface *typeface, SkFontTableTag tag) {
    static_sk_data_set(sk_data_key_out, typeface->copyTableData(tag));
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

void SkTypeface_openStream(const char *sk_stream_asset_key_out, SkTypeface *typeface, int *ttcIndex) {
    static_sk_stream_asset_set(sk_stream_asset_key_out, typeface->openStream(ttcIndex));
}

void SkTypeface_openExistingStream(const char *sk_stream_asset_key_out, SkTypeface *typeface, int *ttcIndex) {
    static_sk_stream_asset_set(sk_stream_asset_key_out, typeface->openExistingStream(ttcIndex));
}

//@TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor) {
//    return typeface->createScalerContext(effects, descriptor);
//}

void SkTypeface_getBounds(const char *sk_rect_key_out, SkTypeface *typeface) {
    static_sk_rect_set(sk_rect_key_out, typeface->getBounds());
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

void SkTypeface_MakeEmpty(const char *sk_typeface_key_out) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeEmpty());
}

void SkTypeface_MakeFromName(const char *sk_typeface_key_out, const char familyName[], SkFontStyle fontStyle) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeFromName(familyName, fontStyle));
}

void SkTypeface_MakeFromFile(const char *sk_typeface_key_out, const char path[], int index) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeFromFile(path, index));
}

void SkTypeface_MakeFromStream(const char *sk_typeface_key_out, const char *sk_stream_asset_key_in, int index) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeFromStream(static_sk_stream_asset_move(sk_stream_asset_key_in), index));
}

void SkTypeface_MakeFromData(const char *sk_typeface_key_out, const char *sk_data_key_in, int index) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeFromData(static_sk_data_move(sk_data_key_in), index));
}

void SkTypeface_MakeDeserialize(const char *sk_typeface_key_out, SkStream *stream) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeDeserialize(stream));
}

void SkTypeface_MakeDeserialize_2(const char *sk_typeface_key_out, const char *sk_font_mgr_key_in, SkStream *stream) {
    static_sk_typeface_set(sk_typeface_key_out, SkTypeface::MakeDeserialize(stream, static_sk_font_mgr_move(sk_font_mgr_key_in)));
}

void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &)) {
    SkTypeface::Register(id, make);
}

}