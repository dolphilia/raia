extension Skia {
    public enum SkTypefaceSerializeBehavior: Int32 {
        case doIncludeData
        case dontIncludeData
        case includeDataIfLocal
    }
    class SkTypeface {
        public var pointer: SkTypefaceMutablePointer?
        public var handle: sk_typeface_t = -1
        // void SkTypeface_delete(void *typeface); // (SkTypeface *typeface)

        deinit {
            if self.handle > -1 {
                static_sk_typeface_delete(self.handle)
            } else {
                SkTypeface_delete(self.pointer)
            }
        }
        // int SkTypeface_fontStyle(void *typeface); // (SkTypeface *typeface) -> sk_font_style_t

        func fontStyle() -> SkFontStyle {
            let handle = SkTypeface_fontStyle(self.pointer)
            let pointer = static_sk_font_style_get_ptr(handle)
            return SkFontStyle(pointer: pointer, handle: handle)
        }
        // bool SkTypeface_isBold(void *typeface); // (SkTypeface *typeface) -> bool

        func isBold() -> Bool {
            return SkTypeface_isBold(self.pointer)
        }
        // bool SkTypeface_isItalic(void *typeface); // (SkTypeface *typeface) -> bool

        func isItalic() -> Bool {
            return SkTypeface_isItalic(self.pointer)
        }
        // bool SkTypeface_isFixedPitch(void *typeface); // (SkTypeface *typeface) -> bool

        func isFixedPitch() -> Bool {
            return SkTypeface_isFixedPitch(self.pointer)
        }
        // int SkTypeface_getVariationDesignPosition(void *typeface, void * coordinates, int coordinateCount); // (SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount) -> int
        // int SkTypeface_getVariationDesignParameters(void *typeface, void * parameters, int parameterCount); // (SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount) -> int
        // unsigned int SkTypeface_uniqueID(void *typeface); // (SkTypeface *typeface) -> SkTypefaceID

        func uniqueID() -> UInt {
            return UInt(SkTypeface_uniqueID(self.pointer))
        }
        // int SkTypeface_makeClone(void *typeface, const void *arguments); // (SkTypeface *typeface, const SkFontArguments *arguments) -> sk_typeface_t

        func makeClone(arguments: SkFontArguments) -> SkTypeface {
            let handle = SkTypeface_makeClone(self.pointer, arguments.pointer)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // void SkTypeface_serialize(void *typeface, void *stream, int behavior); // (SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior)
        // int SkTypeface_serialize_2(void *typeface, int behavior); // (SkTypeface *typeface, SkTypeface::SerializeBehavior behavior) -> sk_data_t

        func serialize(behavior: SkTypefaceSerializeBehavior) -> SkData {
            let handle = SkTypeface_serialize_2(self.pointer, behavior.rawValue)
            let pointer = static_sk_data_get_ptr(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // void SkTypeface_unicharsToGlyphs(void *typeface, const void * uni, int count, void * glyphs); // (SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[])

        func unicharsToGlyphs(uni: [UInt32], glyphs: inout [UInt16]) {
            SkTypeface_unicharsToGlyphs(self.pointer, uni, Int32(uni.count), &glyphs)
        }
        // int SkTypeface_textToGlyphs(void *typeface, const void *text, unsigned long byteLength, int encoding, void * glyphs, int maxGlyphCount); // (SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) -> int

        func textToGlyphs(text: String, encoding: SkTextEncoding, maxGlyphCount: Int) -> [UInt16] {
            var glyphs = [UInt16](repeating: 0, count: maxGlyphCount)
            let count = SkTypeface_textToGlyphs(self.pointer, text, UInt(text.utf8.count), Int32(encoding.rawValue), &glyphs, Int32(maxGlyphCount))
            return Array(glyphs[0..<Int(count)])
        }
        // unsigned short SkTypeface_unicharToGlyph(void *typeface, int unichar); // (SkTypeface *typeface, SkUnichar unichar) -> SkGlyphID

        func unicharToGlyph(unichar: Int) -> UInt16 {
            return UInt16(SkTypeface_unicharToGlyph(self.pointer, Int32(unichar)))
        }
        // int SkTypeface_countGlyphs(void *typeface); // (SkTypeface *typeface) -> int

        func countGlyphs() -> Int {
            return Int(SkTypeface_countGlyphs(self.pointer))
        }
        // int SkTypeface_countTables(void *typeface); // (SkTypeface *typeface) -> int

        func countTables() -> Int {
            return Int(SkTypeface_countTables(self.pointer))
        }
        // int SkTypeface_getTableTags(void *typeface, void * tags); // (SkTypeface *typeface, SkFontTableTag tags[]) -> int

        func getTableTags(tag: inout [UInt32]) -> Int {
            return tag.withUnsafeMutableBytes { buffer in
                return Int(SkTypeface_getTableTags(self.pointer, buffer.baseAddress))
            }
        }
        // unsigned long SkTypeface_getTableSize(void *typeface, unsigned int tag); // (SkTypeface *typeface, SkFontTableTag tag) -> size_t

        func getTableSize(tag: UInt32) -> UInt {
            return UInt(SkTypeface_getTableSize(self.pointer, tag))
        }
        // unsigned long SkTypeface_getTableData(void *typeface, unsigned int tag, unsigned long offset, unsigned long length, void *data); // (SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data) -> size_t

        func getTableData(tag: UInt32, offset: UInt, length: UInt, data: UnsafeMutableRawPointer?) -> UInt {
            return data!.assumingMemoryBound(to: UInt8.self).withMemoryRebound(to: UInt8.self, capacity: Int(length)) { buffer in
                return UInt(SkTypeface_getTableData(self.pointer, tag, offset, length, buffer))
            }
        }
        // int SkTypeface_copyTableData(void *typeface, unsigned int tag); // (SkTypeface *typeface, SkFontTableTag tag) -> sk_data_t

        func copyTableData(tag: UInt32) -> SkData {
            let handle = SkTypeface_copyTableData(self.pointer, tag)
            let pointer = static_sk_data_get_ptr(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // int SkTypeface_getUnitsPerEm(void *typeface); // (SkTypeface *typeface) -> int

        func getUnitsPerEm() -> Int {
            return Int(SkTypeface_getUnitsPerEm(self.pointer))
        }
        // bool SkTypeface_getKerningPairAdjustments(void *typeface, const void * glyphs, int count, void * adjustments); // (SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]) -> bool

        func getKerningPairAdjustments(glyphs: [UInt16], adjustments: inout [Int32]) -> Bool {
            return glyphs.withUnsafeBytes { buffer in
                return SkTypeface_getKerningPairAdjustments(self.pointer, buffer.baseAddress!.assumingMemoryBound(to: UInt16.self), Int32(glyphs.count), &adjustments)
            }
        }

        // void * SkTypeface_createFamilyNameIterator(void *typeface); // (SkTypeface *typeface) -> SkTypeface::LocalizedStrings *
        // void SkTypeface_getFamilyName(void *typeface, void *name); // (SkTypeface *typeface, SkString *name)

        func getFamilyName(name: SkString) {
            SkTypeface_getFamilyName(self.pointer, name.pointer)
        }
        // bool SkTypeface_getPostScriptName(void *typeface, void *name); // (SkTypeface *typeface, SkString *name) -> bool

        func getPostScriptName(name: SkString) -> Bool {
            return SkTypeface_getPostScriptName(self.pointer, name.pointer)
        }
        // int SkTypeface_openStream(void *typeface, int *ttcIndex); // (SkTypeface *typeface, int *ttcIndex) -> sk_stream_asset_t

        func openStream(ttcIndex: UnsafeMutablePointer<Int32>?) -> SkStreamAsset {
            let handle = SkTypeface_openStream(self.pointer, ttcIndex)
            let pointer = static_sk_stream_asset_get_ptr(handle)
            return SkStreamAsset(pointer: pointer, handle: handle)
        }
        // int SkTypeface_openExistingStream(void *typeface, int *ttcIndex); // (SkTypeface *typeface, int *ttcIndex) -> sk_stream_asset_t

        func openExistingStream(ttcIndex: UnsafeMutablePointer<Int32>?) -> SkStreamAsset {
            let handle = SkTypeface_openExistingStream(self.pointer, ttcIndex)
            let pointer = static_sk_stream_asset_get_ptr(handle)
            return SkStreamAsset(pointer: pointer, handle: handle)
        }
        // // TODO
        // //std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor);

        // int SkTypeface_getBounds(void *typeface); // (SkTypeface *typeface) -> sk_rect_t

        func getBounds() -> SkRect {
            let handle = SkTypeface_getBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }
        // void SkTypeface_filterRec(void *typeface, void *rec); // (SkTypeface *typeface, SkScalerContextRec *rec)
        // void SkTypeface_getFontDescriptor(void *typeface, void *desc, bool *isLocal); // (SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal)
        // void * SkTypeface_internal_private_getCTFontRef(void *typeface); // (SkTypeface *typeface) -> void *

        func internal_private_getCTFontRef() -> UnsafeMutableRawPointer? {
            return SkTypeface_internal_private_getCTFontRef(self.pointer)
        }

        // // static

        init(pointer: SkTypefaceMutablePointer?, handle: sk_typeface_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // bool SkTypeface_Equal(const void *facea, const void *faceb); // (const SkTypeface *facea, const SkTypeface *faceb) -> bool

        static func Equal(facea: SkTypeface, faceb: SkTypeface) -> Bool {
            return SkTypeface_Equal(facea.pointer, faceb.pointer)
        }
        // int SkTypeface_MakeEmpty(); // () -> sk_typeface_t

        static func MakeEmpty() -> SkTypeface {
            let handle = SkTypeface_MakeEmpty()
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeDeserialize(void *stream, int font_mgr); // (SkStream *stream, sk_font_mgr_t font_mgr) -> sk_typeface_t

        static func MakeDeserialize(stream: SkStream, font_mgr: SkFontMgr) -> SkTypeface {
            let handle = SkTypeface_MakeDeserialize(stream.pointer, font_mgr.handle)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // // TODO
        // //void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &)); // (SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &))

        // // Legacy
        // int SkTypeface_MakeDefault(); // () -> sk_typeface_t

        static func MakeDefault() -> SkTypeface {
            let handle = SkTypeface_MakeDefault()
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeFromName(const char familyName[], int fontStyle); // (const char familyName[], sk_font_style_t fontStyle) -> sk_typeface_t

        static func MakeFromName(familyName: String, fontStyle: SkFontStyle) -> SkTypeface {
            let handle = SkTypeface_MakeFromName(familyName, fontStyle.handle)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeFromFile(const char path[], int index); // (const char path[], int index) -> sk_typeface_t

        static func MakeFromFile(path: String, index: Int) -> SkTypeface {
            let handle = SkTypeface_MakeFromFile(path, Int32(index))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeFromStream(int stream_asset, int index); // (sk_stream_asset_t stream_asset, int index) -> sk_typeface_t

        static func MakeFromStream(stream_asset: SkStreamAsset, index: Int) -> SkTypeface {
            let handle = SkTypeface_MakeFromStream(stream_asset.handle, Int32(index))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeFromData(int data, int index); // (sk_data_t data, int index) -> sk_typeface_t

        static func MakeFromData(data: SkData, index: Int) -> SkTypeface {
            let handle = SkTypeface_MakeFromData(data.handle, Int32(index))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkTypeface_MakeDeserialize_2(void *stream); // (SkStream *stream) -> sk_typeface_t

        static func MakeDeserialize(stream: SkStream) -> SkTypeface {
            let handle = SkTypeface_MakeDeserialize_2(stream.pointer)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
    }
}