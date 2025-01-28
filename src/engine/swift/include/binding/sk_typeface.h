//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TYPEFACE_H
#define RAIA_SKIA_SK_TYPEFACE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkTypeface_delete(void *typeface); // (SkTypeface *typeface)
int SkTypeface_fontStyle(void *typeface); // (SkTypeface *typeface) -> sk_font_style_t
bool SkTypeface_isBold(void *typeface); // (SkTypeface *typeface) -> bool
bool SkTypeface_isItalic(void *typeface); // (SkTypeface *typeface) -> bool
bool SkTypeface_isFixedPitch(void *typeface); // (SkTypeface *typeface) -> bool
int SkTypeface_getVariationDesignPosition(void *typeface, void * coordinates, int coordinateCount); // (SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount) -> int
int SkTypeface_getVariationDesignParameters(void *typeface, void * parameters, int parameterCount); // (SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount) -> int
unsigned int SkTypeface_uniqueID(void *typeface); // (SkTypeface *typeface) -> SkTypefaceID
int SkTypeface_makeClone(void *typeface, const void *arguments); // (SkTypeface *typeface, const SkFontArguments *arguments) -> sk_typeface_t
void SkTypeface_serialize(void *typeface, void *stream, int behavior); // (SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior)
int SkTypeface_serialize_2(void *typeface, int behavior); // (SkTypeface *typeface, SkTypeface::SerializeBehavior behavior) -> sk_data_t
void SkTypeface_unicharsToGlyphs(void *typeface, const void * uni, int count, void * glyphs); // (SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[])
int SkTypeface_textToGlyphs(void *typeface, const void *text, unsigned long byteLength, int encoding, void * glyphs, int maxGlyphCount); // (SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) -> int
unsigned short SkTypeface_unicharToGlyph(void *typeface, int unichar); // (SkTypeface *typeface, SkUnichar unichar) -> SkGlyphID
int SkTypeface_countGlyphs(void *typeface); // (SkTypeface *typeface) -> int
int SkTypeface_countTables(void *typeface); // (SkTypeface *typeface) -> int
int SkTypeface_getTableTags(void *typeface, void * tags); // (SkTypeface *typeface, SkFontTableTag tags[]) -> int
unsigned long SkTypeface_getTableSize(void *typeface, unsigned int tag); // (SkTypeface *typeface, SkFontTableTag tag) -> size_t
unsigned long SkTypeface_getTableData(void *typeface, unsigned int tag, unsigned long offset, unsigned long length, void *data); // (SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data) -> size_t
int SkTypeface_copyTableData(void *typeface, unsigned int tag); // (SkTypeface *typeface, SkFontTableTag tag) -> sk_data_t
int SkTypeface_getUnitsPerEm(void *typeface); // (SkTypeface *typeface) -> int
bool SkTypeface_getKerningPairAdjustments(void *typeface, const void * glyphs, int count, void * adjustments); // (SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]) -> bool
void * SkTypeface_createFamilyNameIterator(void *typeface); // (SkTypeface *typeface) -> SkTypeface::LocalizedStrings *
void SkTypeface_getFamilyName(void *typeface, void *name); // (SkTypeface *typeface, SkString *name)
bool SkTypeface_getPostScriptName(void *typeface, void *name); // (SkTypeface *typeface, SkString *name) -> bool
int SkTypeface_openStream(void *typeface, int *ttcIndex); // (SkTypeface *typeface, int *ttcIndex) -> sk_stream_asset_t
int SkTypeface_openExistingStream(void *typeface, int *ttcIndex); // (SkTypeface *typeface, int *ttcIndex) -> sk_stream_asset_t

// TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor);

int SkTypeface_getBounds(void *typeface); // (SkTypeface *typeface) -> sk_rect_t
void SkTypeface_filterRec(void *typeface, void *rec); // (SkTypeface *typeface, SkScalerContextRec *rec)
void SkTypeface_getFontDescriptor(void *typeface, void *desc, bool *isLocal); // (SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal)
void * SkTypeface_internal_private_getCTFontRef(void *typeface); // (SkTypeface *typeface) -> void *

// static

bool SkTypeface_Equal(const void *facea, const void *faceb); // (const SkTypeface *facea, const SkTypeface *faceb) -> bool
int SkTypeface_MakeEmpty(); // () -> sk_typeface_t
int SkTypeface_MakeDeserialize(void *stream, int font_mgr); // (SkStream *stream, sk_font_mgr_t font_mgr) -> sk_typeface_t

// TODO
//void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &)); // (SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &))

#if !defined(SK_DISABLE_LEGACY_FONTMGR_REFDEFAULT)

int SkTypeface_MakeDefault(); // () -> sk_typeface_t
int SkTypeface_MakeFromName(const char familyName[], int fontStyle); // (const char familyName[], sk_font_style_t fontStyle) -> sk_typeface_t
int SkTypeface_MakeFromFile(const char path[], int index); // (const char path[], int index) -> sk_typeface_t
int SkTypeface_MakeFromStream(int stream_asset, int index); // (sk_stream_asset_t stream_asset, int index) -> sk_typeface_t
int SkTypeface_MakeFromData(int data, int index); // (sk_data_t data, int index) -> sk_typeface_t
int SkTypeface_MakeDeserialize_2(void *stream); // (SkStream *stream) -> sk_typeface_t

#endif

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TYPEFACE_H
