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
#include "export_api.h"

extern "C" {
RAIA_API void SkTypeface_delete(SkTypeface *typeface);
RAIA_API sk_font_style_t SkTypeface_fontStyle(SkTypeface *typeface);
RAIA_API bool SkTypeface_isBold(SkTypeface *typeface);
RAIA_API bool SkTypeface_isItalic(SkTypeface *typeface);
RAIA_API bool SkTypeface_isFixedPitch(SkTypeface *typeface);
RAIA_API int SkTypeface_getVariationDesignPosition(SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount);
RAIA_API int SkTypeface_getVariationDesignParameters(SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount);
RAIA_API SkTypefaceID SkTypeface_uniqueID(SkTypeface *typeface);
RAIA_API sk_typeface_t SkTypeface_makeClone(SkTypeface *typeface, const SkFontArguments *arguments);
RAIA_API void SkTypeface_serialize(SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior);
RAIA_API sk_data_t SkTypeface_serialize_2(SkTypeface *typeface, SkTypeface::SerializeBehavior behavior);
RAIA_API void SkTypeface_unicharsToGlyphs(SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[]);
RAIA_API int SkTypeface_textToGlyphs(SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount);
RAIA_API SkGlyphID SkTypeface_unicharToGlyph(SkTypeface *typeface, SkUnichar unichar);
RAIA_API int SkTypeface_countGlyphs(SkTypeface *typeface);
RAIA_API int SkTypeface_countTables(SkTypeface *typeface);
RAIA_API int SkTypeface_getTableTags(SkTypeface *typeface, SkFontTableTag tags[]);
RAIA_API size_t SkTypeface_getTableSize(SkTypeface *typeface, SkFontTableTag tag);
RAIA_API size_t SkTypeface_getTableData(SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data);
RAIA_API sk_data_t SkTypeface_copyTableData(SkTypeface *typeface, SkFontTableTag tag);
RAIA_API int SkTypeface_getUnitsPerEm(SkTypeface *typeface);
RAIA_API bool SkTypeface_getKerningPairAdjustments(SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]);
RAIA_API SkTypeface::LocalizedStrings * SkTypeface_createFamilyNameIterator(SkTypeface *typeface);
RAIA_API void SkTypeface_getFamilyName(SkTypeface *typeface, SkString *name);
RAIA_API bool SkTypeface_getPostScriptName(SkTypeface *typeface, SkString *name);
RAIA_API sk_stream_asset_t SkTypeface_openStream(SkTypeface *typeface, int *ttcIndex);
RAIA_API sk_stream_asset_t SkTypeface_openExistingStream(SkTypeface *typeface, int *ttcIndex);
//@TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor);
RAIA_API sk_rect_t SkTypeface_getBounds(SkTypeface *typeface);
RAIA_API void SkTypeface_filterRec(SkTypeface *typeface, SkScalerContextRec *rec);
RAIA_API void SkTypeface_getFontDescriptor(SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal);
RAIA_API void * SkTypeface_internal_private_getCTFontRef(SkTypeface *typeface);
// static
RAIA_API bool SkTypeface_Equal(const SkTypeface *facea, const SkTypeface *faceb);
RAIA_API sk_typeface_t SkTypeface_MakeEmpty();
RAIA_API sk_typeface_t SkTypeface_MakeDeserialize(SkStream *stream, sk_font_mgr_t font_mgr);
RAIA_API void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &));
#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)
RAIA_API sk_typeface_t SkTypeface_MakeDefault();
RAIA_API sk_typeface_t SkTypeface_MakeFromName(const char familyName[], sk_font_style_t fontStyle);
RAIA_API sk_typeface_t SkTypeface_MakeFromFile(const char path[], int index);
RAIA_API sk_typeface_t SkTypeface_MakeFromStream(sk_stream_asset_t stream_asset, int index);
RAIA_API sk_typeface_t SkTypeface_MakeFromData(sk_data_t data, int index);
RAIA_API sk_typeface_t SkTypeface_MakeDeserialize_2(SkStream *stream);
#endif
}

#endif //RAIA_SKIA_SK_TYPEFACE_H
