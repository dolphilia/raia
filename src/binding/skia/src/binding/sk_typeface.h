//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TYPEFACE_H
#define RAIA_SKIA_SK_TYPEFACE_H

#include "include/core/SkTypeface.h"
#include "include/core/SkFontMgr.h"
#include "include/core/SkStream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_stream_asset.h"
#include "../static/static_sk_typeface.h"
#include "../static/static_sk_font_style.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_font_mgr.h"

extern "C" {
void SkTypeface_delete(SkTypeface *typeface);
sk_font_style_t SkTypeface_fontStyle(SkTypeface *typeface);
bool SkTypeface_isBold(SkTypeface *typeface);
bool SkTypeface_isItalic(SkTypeface *typeface);
bool SkTypeface_isFixedPitch(SkTypeface *typeface);
int SkTypeface_getVariationDesignPosition(SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount);
int SkTypeface_getVariationDesignParameters(SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount);
SkTypefaceID SkTypeface_uniqueID(SkTypeface *typeface);
sk_typeface_t SkTypeface_makeClone(SkTypeface *typeface, const SkFontArguments *arguments);
void SkTypeface_serialize(SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior);
sk_data_t SkTypeface_serialize_2(SkTypeface *typeface, SkTypeface::SerializeBehavior behavior);
void SkTypeface_unicharsToGlyphs(SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[]);
int SkTypeface_textToGlyphs(SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount);
SkGlyphID SkTypeface_unicharToGlyph(SkTypeface *typeface, SkUnichar unichar);
int SkTypeface_countGlyphs(SkTypeface *typeface);
int SkTypeface_countTables(SkTypeface *typeface);
int SkTypeface_getTableTags(SkTypeface *typeface, SkFontTableTag tags[]);
size_t SkTypeface_getTableSize(SkTypeface *typeface, SkFontTableTag tag);
size_t SkTypeface_getTableData(SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data);
sk_data_t SkTypeface_copyTableData(SkTypeface *typeface, SkFontTableTag tag);
int SkTypeface_getUnitsPerEm(SkTypeface *typeface);
bool SkTypeface_getKerningPairAdjustments(SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]);
SkTypeface::LocalizedStrings * SkTypeface_createFamilyNameIterator(SkTypeface *typeface);
void SkTypeface_getFamilyName(SkTypeface *typeface, SkString *name);
bool SkTypeface_getPostScriptName(SkTypeface *typeface, SkString *name);
sk_stream_asset_t SkTypeface_openStream(SkTypeface *typeface, int *ttcIndex);
sk_stream_asset_t SkTypeface_openExistingStream(SkTypeface *typeface, int *ttcIndex);
//@TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor);
sk_rect_t SkTypeface_getBounds(SkTypeface *typeface);
void SkTypeface_filterRec(SkTypeface *typeface, SkScalerContextRec *rec);
void SkTypeface_getFontDescriptor(SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal);
void * SkTypeface_internal_private_getCTFontRef(SkTypeface *typeface);
// static
bool SkTypeface_Equal(const SkTypeface *facea, const SkTypeface *faceb);
sk_typeface_t SkTypeface_MakeEmpty();
sk_typeface_t SkTypeface_MakeDeserialize(SkStream *stream, sk_font_mgr_t font_mgr);
void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &));
#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)
sk_typeface_t SkTypeface_MakeDefault();
sk_typeface_t SkTypeface_MakeFromName(const char familyName[], sk_font_style_t fontStyle);
sk_typeface_t SkTypeface_MakeFromFile(const char path[], int index);
sk_typeface_t SkTypeface_MakeFromStream(sk_stream_asset_t stream_asset, int index);
sk_typeface_t SkTypeface_MakeFromData(sk_data_t data, int index);
sk_typeface_t SkTypeface_MakeDeserialize_2(SkStream *stream);
#endif
}

#endif //RAIA_SKIA_SK_TYPEFACE_H
