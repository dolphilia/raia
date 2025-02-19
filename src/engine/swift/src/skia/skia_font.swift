extension Skia {
    public enum SkFontEdging: Int32 {
        case alias
        case antiAlias
        case subpixelAntiAlias
    }

    protocol SkFontProtocol {
        var pointer: SkFontMutablePointer? { get set }
        var handle: sk_font_t { get set }
        // deinit // void SkFont_delete(void *font); // (SkFont *font)
        init(pointer: SkFontMutablePointer?, handle: sk_font_t)
        init() // void *SkFont_new(); // () -> SkFont *
        init(typeface: SkTypeface, size: Float) // void *SkFont_new_2(int typeface, float size); // (sk_typeface_t typeface, SkScalar size) -> SkFont *
        init(typeface: SkTypeface) // void *SkFont_new_3(int typeface); // (sk_typeface_t typeface) -> SkFont *
        init(typeface: SkTypeface, size: Float, scaleX: Float, skewX: Float) // void *SkFont_new_4(int typeface, float size, float scaleX, float skewX); // (sk_typeface_t typeface, SkScalar size, SkScalar scaleX, SkScalar skewX) -> SkFont *
        // Methods
        func isForceAutoHinting() -> Bool // bool SkFont_isForceAutoHinting(void *font); // (SkFont *font) -> bool
        func isEmbeddedBitmaps() -> Bool // bool SkFont_isEmbeddedBitmaps(void *font); // (SkFont *font) -> bool
        func isSubpixel() -> Bool // bool SkFont_isSubpixel(void *font); // (SkFont *font) -> bool
        func isLinearMetrics() -> Bool // bool SkFont_isLinearMetrics(void *font); // (SkFont *font) -> bool
        func isEmbolden() -> Bool // bool SkFont_isEmbolden(void *font); // (SkFont *font) -> bool
        func isBaselineSnap() -> Bool // bool SkFont_isBaselineSnap(void *font); // (SkFont *font) -> bool
        func setForceAutoHinting(forceAutoHinting: Bool) // void SkFont_setForceAutoHinting(void *font, bool forceAutoHinting); // (SkFont *font, bool forceAutoHinting)
        func setEmbeddedBitmaps(embeddedBitmaps: Bool) // void SkFont_setEmbeddedBitmaps(void *font, bool embeddedBitmaps); // (SkFont *font, bool embeddedBitmaps)
        func setSubpixel(subpixel: Bool) // void SkFont_setSubpixel(void *font, bool subpixel); // (SkFont *font, bool subpixel)
        func setLinearMetrics(linearMetrics: Bool) // void SkFont_setLinearMetrics(void *font, bool linearMetrics); // (SkFont *font, bool linearMetrics)
        func setEmbolden(embolden: Bool) // void SkFont_setEmbolden(void *font, bool embolden); // (SkFont *font, bool embolden)
        func setBaselineSnap(baselineSnap: Bool) // void SkFont_setBaselineSnap(void *font, bool baselineSnap); // (SkFont *font, bool baselineSnap)
        func getEdging() -> SkFontEdging // int SkFont_getEdging(void *font); // (SkFont *font) -> SkFont::Edging
        func setEdging(edging: SkFontEdging) // void SkFont_setEdging(void *font, int edging); // (SkFont *font, SkFont::Edging edging)
        func setHinting(hintingLevel: SkFontHinting) // void SkFont_setHinting(void *font, int hintingLevel); // (SkFont *font, SkFontHinting hintingLevel)
        func getHinting() -> SkFontHinting // int SkFont_getHinting(void *font); // (SkFont *font) -> SkFontHinting
        func makeWithSize(size: Float) -> SkFont // int SkFont_makeWithSize(void *font, float size); // (SkFont *font, SkScalar size) -> sk_font_t
        func getTypeface() -> SkTypeface // void * SkFont_getTypeface(void *font); // (SkFont *font) -> SkTypeface *
        func getSize() -> Float // float SkFont_getSize(void *font); // (SkFont *font) -> SkScalar
        func getScaleX() -> Float // float SkFont_getScaleX(void *font); // (SkFont *font) -> SkScalar
        func getSkewX() -> Float // float SkFont_getSkewX(void *font); // (SkFont *font) -> SkScalar
        func refTypeface() -> SkTypeface // int SkFont_refTypeface(void *font); // (SkFont *font) -> sk_typeface_t
        // void SkFont_setTypeface(void *font, sk_typeface_t typeface); // (SkFont *font, sk_typeface_t typeface)
        func setSize(textSize: Float) // void SkFont_setSize(void *font, float textSize); // (SkFont *font, SkScalar textSize)
        func setScaleX(scaleX: Float) // void SkFont_setScaleX(void *font, float scaleX); // (SkFont *font, SkScalar scaleX)
        func setSkewX(skewX: Float) // void SkFont_setSkewX(void *font, float skewX); // (SkFont *font, SkScalar skewX)
        func textToGlyphs(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, glyphs: inout [UInt16], maxGlyphCount: Int) -> Int // int SkFont_textToGlyphs(void *font, const void *text, unsigned long byteLength, int encoding, void * glyphs, int maxGlyphCount); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) -> int
        func unicharToGlyph(uni: Int) -> UInt16 // unsigned short SkFont_unicharToGlyph(void *font, int uni); // (SkFont *font, SkUnichar uni) -> SkGlyphID
        func unicharsToGlyphs(uni: [Int], glyphs: inout [UInt16]) // void SkFont_unicharsToGlyphs(void *font, const void * uni, int count, void * glyphs); // (SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[])
        func countText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding) -> Int // int SkFont_countText(void *font, const void *text, unsigned long byteLength, int encoding); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding) -> int
        func measureText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, bounds: SkRect) -> Float // float SkFont_measureText(void *font, const void *text, unsigned long byteLength, int encoding, void *bounds); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds) -> SkScalar
        func measureText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, bounds: SkRect, paint: SkPaint) -> Float // float SkFont_measureText_2(void *font, const void *text, unsigned long byteLength, int encoding, void *bounds, const void *paint); // (SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint) -> SkScalar
        func getWidths(glyphs: [UInt16], count: Int, widths: inout [Float], bounds: SkRect) // void SkFont_getWidths(void *font, const void * glyphs, int count, void * widths, void * bounds); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[])
        // void SkFont_getWidths_2(void *font, const void * glyphs, int count, void * widths, std::nullptr_t ptr); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr)
        func getWidths(glyphs: [UInt16], count: Int, widths: inout [Float]) // void SkFont_getWidths_3(void *font, const void * glyphs, int count, void * widths); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[])
        func getWidthsBounds(glyphs: [UInt16], count: Int, widths: inout [Float], bounds: SkRect, paint: SkPaint) // void SkFont_getWidthsBounds(void *font, const void * glyphs, int count, void * widths, void * bounds, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint)
        func getBounds(glyphs: [UInt16], count: Int, bounds: SkRect, paint: SkPaint) // void SkFont_getBounds(void *font, const void * glyphs, int count, void * bounds, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint)
        func getPos(glyphs: [UInt16], count: Int, pos: SkPoint, origin: SkPoint) // void SkFont_getPos(void *font, const void * glyphs, int count, void * pos, int origin); // (SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], sk_point_t origin)
        func getXPos(glyphs: [UInt16], count: Int, xpos: inout [Float], origin: Float) // void SkFont_getXPos(void *font, const void * glyphs, int count, void * xpos, float origin); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin)
        func getIntercepts(glyphs: [UInt16], count: Int, pos: SkPoint, top: Float, bottom: Float, paint: SkPaint) -> Int // int SkFont_getIntercepts(void *font, const void * glyphs, int count, const void * pos, float top, float bottom, const void *paint); // (SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint) -> int
        func getPath(glyphID: UInt16, path: SkPath) -> Bool // bool SkFont_getPath(void *font, unsigned short glyphID, void*path); // (SkFont *font, SkGlyphID glyphID, SkPath *path) -> bool
        // void SkFont_getPaths(void *font, const void * glyphIDs, int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx); // (SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx)
        // float SkFont_getMetrics(void *font, void * metrics); // (SkFont *font, SkFontMetrics *metrics) -> SkScalar
        func getSpacing() -> Float // float SkFont_getSpacing(void *font); // (SkFont *font) -> SkScalar
        func dump() // void SkFont_dump(void *font); // (SkFont *font)

    }

    class SkFont : SkFontProtocol {
        public var pointer: SkFontMutablePointer?
        public var handle: sk_font_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_font_delete(self.handle)
            } else {
                SkFont_delete(self.pointer)
            }
        }

        required init(pointer: SkFontMutablePointer?, handle: sk_font_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkFont_new()
            self.handle = -1
        }

        required init(typeface: SkTypeface, size: Float) {
            self.pointer = SkFont_new_2(typeface.handle, size)
            self.handle = -1
        }

        required init(typeface: SkTypeface) {
            self.pointer = SkFont_new_3(typeface.handle)
            self.handle = -1
        }

        required init(typeface: SkTypeface, size: Float, scaleX: Float, skewX: Float) {
            self.pointer = SkFont_new_4(typeface.handle, size, scaleX, skewX)
            self.handle = -1
        }

        // Methods

        func isForceAutoHinting() -> Bool {
            return SkFont_isForceAutoHinting(self.pointer)
        }

        func isEmbeddedBitmaps() -> Bool {
            return SkFont_isEmbeddedBitmaps(self.pointer)
        }

        func isSubpixel() -> Bool {
            return SkFont_isSubpixel(self.pointer)
        }

        func isLinearMetrics() -> Bool {
            return SkFont_isLinearMetrics(self.pointer)
        }

        func isEmbolden() -> Bool {
            return SkFont_isEmbolden(self.pointer)
        }

        func isBaselineSnap() -> Bool {
            return SkFont_isBaselineSnap(self.pointer)
        }

        func setForceAutoHinting(forceAutoHinting: Bool) {
            SkFont_setForceAutoHinting(self.pointer, forceAutoHinting)
        }

        func setEmbeddedBitmaps(embeddedBitmaps: Bool) {
            SkFont_setEmbeddedBitmaps(self.pointer, embeddedBitmaps)
        }

        func setSubpixel(subpixel: Bool) {
            SkFont_setSubpixel(self.pointer, subpixel)
        }

        func setLinearMetrics(linearMetrics: Bool) {
            SkFont_setLinearMetrics(self.pointer, linearMetrics)
        }

        func setEmbolden(embolden: Bool) {
            SkFont_setEmbolden(self.pointer, embolden)
        }

        func setBaselineSnap(baselineSnap: Bool) {
            SkFont_setBaselineSnap(self.pointer, baselineSnap)
        }

        func getEdging() -> SkFontEdging {
            return SkFontEdging(rawValue: SkFont_getEdging(self.pointer))!
        }

        func setEdging(edging: SkFontEdging) {
            SkFont_setEdging(self.pointer, edging.rawValue)
        }

        func setHinting(hintingLevel: SkFontHinting) {
            SkFont_setHinting(self.pointer, hintingLevel.rawValue)
        }

        func getHinting() -> SkFontHinting {
            return SkFontHinting(rawValue: SkFont_getHinting(self.pointer))!
        }

        func makeWithSize(size: Float) -> SkFont {
            let handle = SkFont_makeWithSize(self.pointer, size)
            return SkFont(pointer: nil, handle: handle)
        }

        func getTypeface() -> SkTypeface {
            let pointer = SkFont_getTypeface(self.pointer)
            return SkTypeface(pointer: pointer, handle: -1)
        }

        func getSize() -> Float {
            return SkFont_getSize(self.pointer)
        }

        func getScaleX() -> Float {
            return SkFont_getScaleX(self.pointer)
        }

        func getSkewX() -> Float {
            return SkFont_getSkewX(self.pointer)
        }

        func refTypeface() -> SkTypeface {
            let handle = SkFont_refTypeface(self.pointer)
            let pointer = static_sk_typeface_get(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        
        // void SkFont_setTypeface(void *font, sk_typeface_t typeface); // (SkFont *font, sk_typeface_t typeface)

        func setSize(textSize: Float) {
            SkFont_setSize(self.pointer, textSize)
        }

        func setScaleX(scaleX: Float) {
            SkFont_setScaleX(self.pointer, scaleX)
        }

        func setSkewX(skewX: Float) {
            SkFont_setSkewX(self.pointer, skewX)
        }

        func textToGlyphs(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, glyphs: inout [UInt16], maxGlyphCount: Int) -> Int {
            return Int(SkFont_textToGlyphs(self.pointer, text, byteLength, encoding.rawValue, &glyphs, Int32(maxGlyphCount)))
        }

        func unicharToGlyph(uni: Int) -> UInt16 {
            return SkFont_unicharToGlyph(self.pointer, Int32(uni))
        }

        func unicharsToGlyphs(uni: [Int], glyphs: inout [UInt16]) {
            SkFont_unicharsToGlyphs(self.pointer, uni, Int32(uni.count), &glyphs)
        }

        func countText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding) -> Int {
            return Int(SkFont_countText(self.pointer, text, byteLength, encoding.rawValue))
        }

        func measureText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, bounds: SkRect) -> Float {
            return SkFont_measureText(self.pointer, text, byteLength, encoding.rawValue, bounds.pointer)
        }

        func measureText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, bounds: SkRect, paint: SkPaint) -> Float {
            return SkFont_measureText_2(self.pointer, text, byteLength, encoding.rawValue, bounds.pointer, paint.pointer)
        }

        func getWidths(glyphs: [UInt16], count: Int, widths: inout [Float], bounds: SkRect) {
            SkFont_getWidths(self.pointer, glyphs, Int32(count), &widths, bounds.pointer)
        }

        // void SkFont_getWidths_2(void *font, const void * glyphs, int count, void * widths, std::nullptr_t ptr); // (SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr)

        func getWidths(glyphs: [UInt16], count: Int, widths: inout [Float]) {
            SkFont_getWidths_3(self.pointer, glyphs, Int32(count), &widths)
        }

        func getWidthsBounds(glyphs: [UInt16], count: Int, widths: inout [Float], bounds: SkRect, paint: SkPaint) {
            SkFont_getWidthsBounds(self.pointer, glyphs, Int32(count), &widths, bounds.pointer, paint.pointer)
        }

        func getBounds(glyphs: [UInt16], count: Int, bounds: SkRect, paint: SkPaint) {
            SkFont_getBounds(self.pointer, glyphs, Int32(count), bounds.pointer, paint.pointer)
        }

        func getPos(glyphs: [UInt16], count: Int, pos: SkPoint, origin: SkPoint) {
            SkFont_getPos(self.pointer, glyphs, Int32(count), pos.pointer, origin.handle)
        }

        func getXPos(glyphs: [UInt16], count: Int, xpos: inout [Float], origin: Float) {
            SkFont_getXPos(self.pointer, glyphs, Int32(count), &xpos, origin)
        }

        func getIntercepts(glyphs: [UInt16], count: Int, pos: SkPoint, top: Float, bottom: Float, paint: SkPaint) -> Int {
            return Int(SkFont_getIntercepts(self.pointer, glyphs, Int32(count), pos.pointer, top, bottom, paint.pointer))
        }

        func getPath(glyphID: UInt16, path: SkPath) -> Bool {
            return SkFont_getPath(self.pointer, glyphID, path.pointer)
        }

        // void SkFont_getPaths(void *font, const void * glyphIDs, int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx); // (SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx)
        // float SkFont_getMetrics(void *font, void * metrics); // (SkFont *font, SkFontMetrics *metrics) -> SkScalar

        func getSpacing() -> Float {
            return SkFont_getSpacing(self.pointer)
        }

        func dump() {
            SkFont_dump(self.pointer)
        }
    }
}