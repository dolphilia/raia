extension Skia {
    public enum SkFontEdging: Int32 {
        case alias
        case antiAlias
        case subpixelAntiAlias
    }

    class SkFont {
        public var pointer: SkFontMutablePointer?
        public var handle: sk_font_t = -1

        // void SkFont_delete(void *font); // (SkFont *font)

        deinit {
            if self.handle > -1 {
                static_sk_font_delete(self.handle)
            } else {
                SkFont_delete(self.pointer)
            }
        }

        // void *SkFont_new(); // () -> SkFont *

        init() {
            self.pointer = SkFont_new()
            self.handle = -1
        }
        // void *SkFont_new_2(int typeface, float size); // (sk_typeface_t typeface, SkScalar size) -> SkFont *

        init(typeface: SkTypeface, size: Float) {
            self.pointer = SkFont_new_2(typeface.handle, size)
            self.handle = -1
        }
        // void *SkFont_new_3(int typeface); // (sk_typeface_t typeface) -> SkFont *

        init(typeface: SkTypeface) {
            self.pointer = SkFont_new_3(typeface.handle)
            self.handle = -1
        }
        // void *SkFont_new_4(int typeface, float size, float scaleX, float skewX); // (sk_typeface_t typeface, SkScalar size, SkScalar scaleX, SkScalar skewX) -> SkFont *

        init(typeface: SkTypeface, size: Float, scaleX: Float, skewX: Float) {
            self.pointer = SkFont_new_4(typeface.handle, size, scaleX, skewX)
            self.handle = -1
        }
        
        // bool SkFont_isForceAutoHinting(void *font); // (SkFont *font) -> bool

        func isForceAutoHinting() -> Bool {
            return SkFont_isForceAutoHinting(self.pointer)
        }
        // bool SkFont_isEmbeddedBitmaps(void *font); // (SkFont *font) -> bool

        func isEmbeddedBitmaps() -> Bool {
            return SkFont_isEmbeddedBitmaps(self.pointer)
        }
        // bool SkFont_isSubpixel(void *font); // (SkFont *font) -> bool

        func isSubpixel() -> Bool {
            return SkFont_isSubpixel(self.pointer)
        }
        // bool SkFont_isLinearMetrics(void *font); // (SkFont *font) -> bool

        func isLinearMetrics() -> Bool {
            return SkFont_isLinearMetrics(self.pointer)
        }
        // bool SkFont_isEmbolden(void *font); // (SkFont *font) -> bool

        func isEmbolden() -> Bool {
            return SkFont_isEmbolden(self.pointer)
        }
        // bool SkFont_isBaselineSnap(void *font); // (SkFont *font) -> bool

        func isBaselineSnap() -> Bool {
            return SkFont_isBaselineSnap(self.pointer)
        }
        // void SkFont_setForceAutoHinting(void *font, bool forceAutoHinting); // (SkFont *font, bool forceAutoHinting)

        func setForceAutoHinting(forceAutoHinting: Bool) {
            SkFont_setForceAutoHinting(self.pointer, forceAutoHinting)
        }
        // void SkFont_setEmbeddedBitmaps(void *font, bool embeddedBitmaps); // (SkFont *font, bool embeddedBitmaps)

        func setEmbeddedBitmaps(embeddedBitmaps: Bool) {
            SkFont_setEmbeddedBitmaps(self.pointer, embeddedBitmaps)
        }
        // void SkFont_setSubpixel(void *font, bool subpixel); // (SkFont *font, bool subpixel)

        func setSubpixel(subpixel: Bool) {
            SkFont_setSubpixel(self.pointer, subpixel)
        }
        // void SkFont_setLinearMetrics(void *font, bool linearMetrics); // (SkFont *font, bool linearMetrics)

        func setLinearMetrics(linearMetrics: Bool) {
            SkFont_setLinearMetrics(self.pointer, linearMetrics)
        }
        // void SkFont_setEmbolden(void *font, bool embolden); // (SkFont *font, bool embolden)

        func setEmbolden(embolden: Bool) {
            SkFont_setEmbolden(self.pointer, embolden)
        }
        // void SkFont_setBaselineSnap(void *font, bool baselineSnap); // (SkFont *font, bool baselineSnap)

        func setBaselineSnap(baselineSnap: Bool) {
            SkFont_setBaselineSnap(self.pointer, baselineSnap)
        }
        // int SkFont_getEdging(void *font); // (SkFont *font) -> SkFont::Edging

        func getEdging() -> SkFontEdging {
            return SkFontEdging(rawValue: SkFont_getEdging(self.pointer))!
        }
        // void SkFont_setEdging(void *font, int edging); // (SkFont *font, SkFont::Edging edging)

        func setEdging(edging: SkFontEdging) {
            SkFont_setEdging(self.pointer, edging.rawValue)
        }
        // void SkFont_setHinting(void *font, int hintingLevel); // (SkFont *font, SkFontHinting hintingLevel)

        func setHinting(hintingLevel: SkFontHinting) {
            SkFont_setHinting(self.pointer, hintingLevel.rawValue)
        }
        // int SkFont_getHinting(void *font); // (SkFont *font) -> SkFontHinting

        func getHinting() -> SkFontHinting {
            return SkFontHinting(rawValue: SkFont_getHinting(self.pointer))!
        }
        // int SkFont_makeWithSize(void *font, float size); // (SkFont *font, SkScalar size) -> sk_font_t

        func makeWithSize(size: Float) -> SkFont {
            let handle = SkFont_makeWithSize(self.pointer, size)
            return SkFont(pointer: nil, handle: handle)
        }
        // void * SkFont_getTypeface(void *font); // (SkFont *font) -> SkTypeface *

        func getTypeface() -> SkTypeface {
            let pointer = SkFont_getTypeface(self.pointer)
            return SkTypeface(pointer: pointer, handle: -1)
        }
        // float SkFont_getSize(void *font); // (SkFont *font) -> SkScalar

        func getSize() -> Float {
            return SkFont_getSize(self.pointer)
        }
        // float SkFont_getScaleX(void *font); // (SkFont *font) -> SkScalar

        func getScaleX() -> Float {
            return SkFont_getScaleX(self.pointer)
        }
        // float SkFont_getSkewX(void *font); // (SkFont *font) -> SkScalar

        func getSkewX() -> Float {
            return SkFont_getSkewX(self.pointer)
        }
        // int SkFont_refTypeface(void *font); // (SkFont *font) -> sk_typeface_t

        func refTypeface() -> SkTypeface {
            let handle = SkFont_refTypeface(self.pointer)
            let pointer = static_sk_typeface_get(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // // TODO
        // //void SkFont_setTypeface(void *font, sk_typeface_t typeface); // (SkFont *font, sk_typeface_t typeface)
        // void SkFont_setSize(void *font, float textSize); // (SkFont *font, SkScalar textSize)
        // void SkFont_setScaleX(void *font, float scaleX); // (SkFont *font, SkScalar scaleX)
        // void SkFont_setSkewX(void *font, float skewX); // (SkFont *font, SkScalar skewX)
        // int SkFont_textToGlyphs(void *font, const void *text, unsigned long byteLength, int encoding, void * glyphs, int maxGlyphCount); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) -> int
        // unsigned short SkFont_unicharToGlyph(void *font, int uni); // (SkFont *font, SkUnichar uni) -> SkGlyphID
        // void SkFont_unicharsToGlyphs(void *font, const void * uni, int count, void * glyphs); // (SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[])
        // int SkFont_countText(void *font, const void *text, unsigned long byteLength, int encoding); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding) -> int
        // float SkFont_measureText(void *font, const void *text, unsigned long byteLength, int encoding, void *bounds); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds) -> SkScalar
        // float SkFont_measureText_2(void *font, const void *text, unsigned long byteLength, int encoding, void *bounds, const void *paint); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint) -> SkScalar
        // void SkFont_getWidths(void *font, const void * glyphs, int count, void * widths, void * bounds); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[])

        // // TODO
        // //void SkFont_getWidths_2(void *font, const void * glyphs, int count, void * widths, std::nullptr_t ptr); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr)
        // void SkFont_getWidths_3(void *font, const void * glyphs, int count, void * widths); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[])
        // void SkFont_getWidthsBounds(void *font, const void * glyphs, int count, void * widths, void * bounds, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint)
        // void SkFont_getBounds(void *font, const void * glyphs, int count, void * bounds, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint)
        // void SkFont_getPos(void *font, const void * glyphs, int count, void * pos, int origin); // (SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], sk_point_t origin)
        // void SkFont_getXPos(void *font, const void * glyphs, int count, void * xpos, float origin); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin)
        // int SkFont_getIntercepts(void *font, const void * glyphs, int count, const void * pos, float top, float bottom, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint) -> int
        // bool SkFont_getPath(void *font, unsigned short glyphID, void*path); // (SkFont *font, SkGlyphID glyphID, SkPath *path) -> bool

        // // TODO
        // //void SkFont_getPaths(void *font, const void * glyphIDs, int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx); // (SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx)
        // float SkFont_getMetrics(void *font, void * metrics); // (SkFont *font, SkFontMetrics *metrics) -> SkScalar
        // float SkFont_getSpacing(void *font); // (SkFont *font) -> SkScalar
        // void SkFont_dump(void *font); // (SkFont *font)

        // // static

        init(pointer: SkFontMutablePointer?, handle: sk_font_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}