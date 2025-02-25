extension Skia {
    class SkBitmapAllocator {
        public var pointer: SkBitmapAllocatorMutablePointer?

        // void * SkBitmap_Allocator_new(void); // () -> SkBitmap::Allocator *
        init(pointer: SkBitmapAllocatorMutablePointer?) {
            self.pointer = pointer
        }

        // bool allocPixelRef (SkBitmap *bitmap)
    }

    typealias SkBitmapReleaseProc = @convention(c) (UnsafeMutableRawPointer?, UnsafeMutableRawPointer?) -> Void

    protocol SkBitmapProtocol {
        var pointer: SkBitmapMutablePointer? { get set }
        var handle: Int32 { get set }
        // deinit // void SkBitmap_delete(void *bitmap); // (SkBitmap *bitmap)
        init(pointer: SkBitmapMutablePointer?, handle: Int32)
        // Static Methods
        static func ComputeIsOpaque(bm: SkBitmap) -> Bool // bool SkBitmap_ComputeIsOpaque(const SkBitmap *bm); // (const SkBitmap *bm) -> bool
        // Methods
        func allocN32Pixels(width: Int, height: Int, isOpaque: Bool) // void SkBitmap_allocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque)
        func allocPixels() // void SkBitmap_allocPixels(void *bitmap); // (SkBitmap *bitmap)
        func allocPixels(allocator: SkBitmapAllocator) // void SkBitmap_allocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator)
        func allocPixels(info: SkImageInfo) // void SkBitmap_allocPixels_3(void *bitmap, const SkImageInfo *info); // (SkBitmap *bitmap, const SkImageInfo *info)
        func allocPixels(info: SkImageInfo, rowBytes: UInt) // void SkBitmap_allocPixels_4(void *bitmap, const SkImageInfo *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes)
        func allocPixelsFlags(info: SkImageInfo, flags: UInt) // void SkBitmap_allocPixelsFlags(void *bitmap, const SkImageInfo *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags)
        func alphaType() -> SkAlphaType // int SkBitmap_alphaType(void *bitmap); // (SkBitmap *bitmap) -> SkAlphaType
        func asImage() -> SkImage // int SkBitmap_asImage(void *bitmap); // (SkBitmap *bitmap) -> sk_image_t
        func bounds() -> SkIRect // int SkBitmap_bounds(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
        func bytesPerPixel() -> Int // int SkBitmap_bytesPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
        func colorSpace() -> SkColorSpace // void * SkBitmap_colorSpace(void *bitmap); // (SkBitmap *bitmap) -> SkColorSpace *
        func colorType() -> SkColorType // int SkBitmap_colorType(void *bitmap); // (SkBitmap *bitmap) -> SkColorType
        func computeByteSize() -> UInt // unsigned long SkBitmap_computeByteSize(void *bitmap); // (SkBitmap *bitmap) -> size_t
        func dimensions() -> SkISize // int SkBitmap_dimensions(void *bitmap); // (SkBitmap *bitmap) -> sk_i_size_t
        func drawsNothing() -> Bool // bool SkBitmap_drawsNothing(void *bitmap); // (SkBitmap *bitmap) -> bool
        func empty() -> Bool // bool SkBitmap_empty(void *bitmap); // (SkBitmap *bitmap) -> bool
        func erase(c: SkColor, area: SkIRect) // void SkBitmap_erase(void *bitmap, unsigned int c, const void *area); // (SkBitmap *bitmap, SkColor c, const SkIRect *area)
        func erase(c: SkColor4f, area: SkIRect) // void SkBitmap_erase_2(void *bitmap, int c, const void *area); // (SkBitmap *bitmap, sk_color_4f_t c, const SkIRect *area)
        func eraseArea(area: SkIRect, c: SkColor) // void SkBitmap_eraseArea(void *bitmap, const void *area, unsigned int c); // (SkBitmap *bitmap, const SkIRect *area, SkColor c)
        func eraseARGB(a: UInt, r: UInt, g: UInt, b: UInt) // void SkBitmap_eraseARGB(void *bitmap, unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b)
        func eraseColor(c: SkColor) // void SkBitmap_eraseColor(void *bitmap, unsigned int c); // (SkBitmap *bitmap, SkColor c)
        func eraseColor(c: SkColor4f) // void SkBitmap_eraseColor_2(void *bitmap, int c); // (SkBitmap *bitmap, sk_color_4f_t c)
        func extractAlpha(dst: SkBitmap) -> Bool // bool SkBitmap_extractAlpha(void *bitmap, void *dst); // (SkBitmap *bitmap, SkBitmap *dst) -> bool
        func extractAlpha(dst: SkBitmap, paint: SkPaint, allocator: SkBitmapAllocator, offset: SkIPoint) -> Bool // bool SkBitmap_extractAlpha_2(void *bitmap, void *dst, const void *paint, void *allocator, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset) -> bool
        func extractAlpha(dst: SkBitmap, paint: SkPaint, offset: SkIPoint) -> Bool // bool SkBitmap_extractAlpha_3(void *bitmap, void *dst, const void *paint, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset) -> bool
        func extractSubset(dst: SkBitmap, subset: SkIRect) -> Bool // bool SkBitmap_extractSubset(void *bitmap, void *dst, const void *subset); // (SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset) -> bool
        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? // void * SkBitmap_getAddr(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> void *
        func getAddr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? // void * SkBitmap_getAddr16(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint16_t *
        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? // void * SkBitmap_getAddr32(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint32_t *
        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? // void * SkBitmap_getAddr8(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint8_t *
        func getAlphaf(x: Int, y: Int) -> Float // float SkBitmap_getAlphaf(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> float
        func getBounds(bounds: inout SkIRect) // void SkBitmap_getBounds(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkIRect *bounds)
        func getBounds(bounds: inout SkRect) // void SkBitmap_getBounds2(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkRect *bounds)
        func getColor(x: Int, y: Int) -> SkColor // unsigned int SkBitmap_getColor(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> SkColor
        func getColor4f(x: Int, y: Int) -> SkColor4f // int SkBitmap_getColor4f(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> sk_color_4f_t
        func getGenerationID() -> UInt // unsigned int SkBitmap_getGenerationID(void *bitmap); // (SkBitmap *bitmap) -> uint32_t
        func getPixels() -> UnsafeMutablePointer<UInt8>? // void * SkBitmap_getPixels(void *bitmap); // (SkBitmap *bitmap) -> void *
        func getPixelsPtr() -> UnsafeMutableRawPointer?
        func getSubset() -> SkIRect // int SkBitmap_getSubset(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
        func height() -> Int // int SkBitmap_height(void *bitmap); // (SkBitmap *bitmap) -> int
        func info() -> SkImageInfo // int SkBitmap_info(void *bitmap); // (SkBitmap *bitmap) -> sk_image_info_t
        func installMaskPixels(mask: SkMaskBuilder) -> Bool // bool SkBitmap_installMaskPixels(void *bitmap, void *mask); // (SkBitmap *bitmap, SkMaskBuilder *mask) -> bool
        func installPixels(info: SkImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt) -> Bool // bool SkBitmap_installPixels(void *bitmap, const void *info, void *pixels, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) -> bool
        func installPixels(info: SkImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt, releaseProc: @escaping SkBitmapReleaseProc, context: UnsafeMutableRawPointer?) -> Bool // bool SkBitmap_installPixels_2(void *bitmap, const void *info, void *pixels, unsigned long rowBytes, void(*releaseProc)(void *addr, void *context), void *context); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context) -> bool
        func installPixels(pixmap: SkPixmap) -> Bool // bool SkBitmap_installPixels_3(void *bitmap, const void *pixmap); // (SkBitmap *bitmap, const SkPixmap *pixmap) -> bool
        func isImmutable() -> Bool // bool SkBitmap_isImmutable(void *bitmap); // (SkBitmap *bitmap) -> bool
        func isNull() -> Bool // bool SkBitmap_isNull(void *bitmap); // (SkBitmap *bitmap) -> bool
        func isOpaque() -> Bool // bool SkBitmap_isOpaque(void *bitmap); // (SkBitmap *bitmap) -> bool
        func makeShader(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader // int SkBitmap_makeShader(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func makeShader_2(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader // int SkBitmap_makeShader_2(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func makeShader_3(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, localMatrix: SkMatrix) -> SkShader // int SkBitmap_makeShader_3(void *bitmap, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t
        func makeShader_4(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader // int SkBitmap_makeShader_4(void *bitmap, int tmx, int tmy, const void *sampling, const void *lm); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func notifyPixelsChanged() // void SkBitmap_notifyPixelsChanged(void *bitmap); // (SkBitmap *bitmap)
        func peekPixels(pixmap: SkPixmap) -> Bool // bool SkBitmap_peekPixels(void *bitmap, void *pixmap); // (SkBitmap *bitmap, SkPixmap *pixmap) -> bool
        func pixelRef() -> SkPixelRef // void * SkBitmap_pixelRef(void *bitmap); // (SkBitmap *bitmap) -> SkPixelRef *
        func pixelRefOrigin() -> SkIPoint // int SkBitmap_pixelRefOrigin(void *bitmap); // (SkBitmap *bitmap) -> sk_i_point_t
        func pixmap() -> SkPixmap // int SkBitmap_pixmap(void *bitmap); // (SkBitmap *bitmap) -> sk_pixmap_t
        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutablePointer<UInt8>?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool // bool SkBitmap_readPixels(void *bitmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
        func readPixels(dst: SkPixmap) -> Bool // bool SkBitmap_readPixels_2(void *bitmap, const void *dst); // (SkBitmap *bitmap, const SkPixmap *dst) -> bool
        func readPixels(dst: SkPixmap, srcX: Int, srcY: Int) -> Bool // bool SkBitmap_readPixels_3(void *bitmap, const void *dst, int srcX, int srcY); // (SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY) -> bool
        func readyToDraw() -> Bool // bool SkBitmap_readyToDraw(void *bitmap); // (SkBitmap *bitmap) -> bool
        func refColorSpace() -> SkColorSpace // int SkBitmap_refColorSpace(void *bitmap); // (SkBitmap *bitmap) -> sk_color_space_t
        func reset() // void SkBitmap_reset(void *bitmap); // (SkBitmap *bitmap)
        func rowBytes() -> UInt // unsigned long SkBitmap_rowBytes(void *bitmap); // (SkBitmap *bitmap) -> size_t
        func rowBytesAsPixels() -> Int // int SkBitmap_rowBytesAsPixels(void *bitmap); // (SkBitmap *bitmap) -> int
        func setAlphaType(alphaType: SkAlphaType) -> Bool // bool SkBitmap_setAlphaType(void *bitmap, int alphaType); // (SkBitmap *bitmap, SkAlphaType alphaType) -> bool
        func setImmutable() // void SkBitmap_setImmutable(void *bitmap); // (SkBitmap *bitmap)
        func setInfo(imageInfo: SkImageInfo, rowBytes: UInt) -> Bool // bool SkBitmap_setInfo(void *bitmap, const void *imageInfo, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes) -> bool
        func setPixelRef(pixelRef: SkPixelRef, dx: Int, dy: Int) // void SkBitmap_setPixelRef(void *bitmap, int pixelRef, int dx, int dy); // (SkBitmap *bitmap, sk_pixel_ref_t pixelRef, int dx, int dy)
        func setPixels(pixels: UnsafeMutablePointer<UInt8>?) // void SkBitmap_setPixels(void *bitmap, void *pixels); // (SkBitmap *bitmap, void *pixels)
        func shiftPerPixel() -> Int // int SkBitmap_shiftPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
        func swap(other: SkBitmap) // void SkBitmap_swap(void *bitmap, void *other); // (SkBitmap *bitmap, SkBitmap *other)
        func tryAllocN32Pixels(width: Int, height: Int, isOpaque: Bool) -> Bool // bool SkBitmap_tryAllocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque) -> bool
        func tryAllocPixels() -> Bool // bool SkBitmap_tryAllocPixels(void *bitmap); // (SkBitmap *bitmap) -> bool
        func tryAllocPixels(allocator: SkBitmapAllocator) -> Bool // bool SkBitmap_tryAllocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator) -> bool
        func tryAllocPixels(info: SkImageInfo) -> Bool // bool SkBitmap_tryAllocPixels_3(void *bitmap, const void *info); // (SkBitmap *bitmap, const SkImageInfo *info) -> bool
        func tryAllocPixels(info: SkImageInfo, rowBytes: UInt) -> Bool // bool SkBitmap_tryAllocPixels_4(void *bitmap, const void *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes) -> bool
        func tryAllocPixelsFlags(info: SkImageInfo, flags: UInt) -> Bool // bool SkBitmap_tryAllocPixelsFlags(void *bitmap, const void *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags) -> bool
        func width() -> Int // int SkBitmap_width(void *bitmap); // (SkBitmap *bitmap) -> int
        func writePixels(src: SkPixmap) -> Bool // bool SkBitmap_writePixels(void *bitmap, const void *src); // (SkBitmap *bitmap, const SkPixmap *src) -> bool
        func writePixels(src: SkPixmap, dstX: Int, dstY: Int) -> Bool // bool SkBitmap_writePixels_2(void *bitmap, const void *src, int dstX, int dstY); // (SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY) -> bool
    }

    class SkBitmap : SkBitmapProtocol {
        public var pointer: SkBitmapMutablePointer?
        public var handle: Int32 = -1

        deinit {
            if self.handle > -1 {
                // static_sk_bitmap_delete(self.handle)
            } else {
                SkBitmap_delete(self.pointer)
            }
        }

        required init(pointer: SkBitmapMutablePointer?, handle: Int32) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkBitmap_new()
        }

        required init(src: SkBitmap) {
            self.pointer = SkBitmap_new_2(src.pointer)
        }

        // Static Methods

        static func ComputeIsOpaque(bm: SkBitmap) -> Bool {
            return SkBitmap_ComputeIsOpaque(bm.pointer)
        }

        // Methods

        func allocN32Pixels(width: Int, height: Int, isOpaque: Bool) {
            SkBitmap_allocN32Pixels(self.pointer, Int32(width), Int32(height), isOpaque)
        }

        func allocPixels() {
            SkBitmap_allocPixels(self.pointer)
        }

        func allocPixels(allocator: SkBitmapAllocator) {
            SkBitmap_allocPixels_2(self.pointer, allocator.pointer)
        }

        func allocPixels(info: SkImageInfo) {
            SkBitmap_allocPixels_3(self.pointer, info.pointer)
        }

        func allocPixels(info: SkImageInfo, rowBytes: UInt) {
            SkBitmap_allocPixels_4(self.pointer, info.pointer, rowBytes)
        }

        func allocPixelsFlags(info: SkImageInfo, flags: UInt) {
            SkBitmap_allocPixelsFlags(self.pointer, info.pointer, UInt32(flags))
        }

        func alphaType() -> SkAlphaType {
            return SkAlphaType(rawValue: SkBitmap_alphaType(self.pointer))!
        }

        func asImage() -> SkImage {
            let handle = SkBitmap_asImage(self.pointer)
            let pointer = static_sk_image_get_ptr(handle)
            return SkImage(pointer: pointer, handle: handle)
        }

        func bounds() -> SkIRect {
            let handle = SkBitmap_bounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        func bytesPerPixel() -> Int {
            return Int(SkBitmap_bytesPerPixel(self.pointer))
        }

        func colorSpace() -> SkColorSpace {
            let pointer = SkBitmap_colorSpace(self.pointer)
            return SkColorSpace(pointer: pointer, handle: -1)
        }

        func colorType() -> SkColorType {
            return SkColorType(rawValue: SkBitmap_colorType(self.pointer))!
        }

        func computeByteSize() -> UInt {
            return UInt(SkBitmap_computeByteSize(self.pointer))
        }

        func dimensions() -> SkISize {
            let handle = SkBitmap_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        func drawsNothing() -> Bool {
            return SkBitmap_drawsNothing(self.pointer)
        }

        func empty() -> Bool {
            return SkBitmap_empty(self.pointer)
        }

        func erase(c: SkColor, area: SkIRect) {
            SkBitmap_erase(self.pointer, c, area.pointer)
        }

        func erase(c: SkColor4f, area: SkIRect) {
            SkBitmap_erase_2(self.pointer, Int32(c.handle), area.pointer)
        }

        func eraseArea(area: SkIRect, c: SkColor) {
            SkBitmap_eraseArea(self.pointer, area.pointer, c)
        }

        func eraseARGB(a: UInt, r: UInt, g: UInt, b: UInt) {
            SkBitmap_eraseARGB(self.pointer, UInt32(a), UInt32(r), UInt32(g), UInt32(b))
        }

        func eraseColor(c: SkColor) {
            SkBitmap_eraseColor(self.pointer, c)
        }

        func eraseColor(c: SkColor4f) {
            SkBitmap_eraseColor_2(self.pointer, Int32(c.handle))
        }

        func extractAlpha(dst: SkBitmap) -> Bool {
            return SkBitmap_extractAlpha(self.pointer, dst.pointer)
        }

        func extractAlpha(dst: SkBitmap, paint: SkPaint, allocator: SkBitmapAllocator, offset: SkIPoint) -> Bool {
            return SkBitmap_extractAlpha_2(self.pointer, dst.pointer, paint.pointer, allocator.pointer, offset.pointer)
        }

        func extractAlpha(dst: SkBitmap, paint: SkPaint, offset: SkIPoint) -> Bool {
            return SkBitmap_extractAlpha_3(self.pointer, dst.pointer, paint.pointer, offset.pointer)
        }

        func extractSubset(dst: SkBitmap, subset: SkIRect) -> Bool {
            return SkBitmap_extractSubset(self.pointer, dst.pointer, subset.pointer)
        }

        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkBitmap_getAddr(self.pointer, Int32(x), Int32(y))
        }

        func getAddr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkBitmap_getAddr16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkBitmap_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }

        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkBitmap_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func getAlphaf(x: Int, y: Int) -> Float {
            return SkBitmap_getAlphaf(self.pointer, Int32(x), Int32(y))
        }

        func getBounds(bounds: inout SkIRect) {
            SkBitmap_getBounds(self.pointer, bounds.pointer)
        }

        func getBounds(bounds: inout SkRect) {
            SkBitmap_getBounds2(self.pointer, bounds.pointer)
        }

        func getColor(x: Int, y: Int) -> SkColor {
            return SkBitmap_getColor(self.pointer, Int32(x), Int32(y))
        }

        func getColor4f(x: Int, y: Int) -> SkColor4f {
            let handle = SkBitmap_getColor4f(self.pointer, Int32(x), Int32(y))
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        func getGenerationID() -> UInt {
            return UInt(SkBitmap_getGenerationID(self.pointer))
        }

        func getPixels() -> UnsafeMutablePointer<UInt8>? {
            return SkBitmap_getPixels(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }

        func getPixelsPtr() -> UnsafeMutableRawPointer? {
            return SkBitmap_getPixels(self.pointer)
        }

        func getSubset() -> SkIRect {
            let handle = SkBitmap_getSubset(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        func height() -> Int {
            return Int(SkBitmap_height(self.pointer))
        }

        func info() -> SkImageInfo {
            let handle = SkBitmap_info(self.pointer)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func installMaskPixels(mask: SkMaskBuilder) -> Bool {
            return SkBitmap_installMaskPixels(self.pointer, mask.pointer)
        }

        func installPixels(info: SkImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt) -> Bool {
            return SkBitmap_installPixels(self.pointer, info.pointer, pixels, rowBytes)
        }

        func installPixels(info: SkImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt, releaseProc: @escaping SkBitmapReleaseProc, context: UnsafeMutableRawPointer?) -> Bool {
            return SkBitmap_installPixels_2(self.pointer, info.pointer, pixels, rowBytes, releaseProc, context)
        }

        func installPixels(pixmap: SkPixmap) -> Bool {
            return SkBitmap_installPixels_3(self.pointer, pixmap.pointer)
        }

        func isImmutable() -> Bool {
            return SkBitmap_isImmutable(self.pointer)
        }

        func isNull() -> Bool {
            return SkBitmap_isNull(self.pointer)
        }

        func isOpaque() -> Bool {
            return SkBitmap_isOpaque(self.pointer)
        }

        func makeShader(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkBitmap_makeShader(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func makeShader_2(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkBitmap_makeShader_2(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func makeShader_3(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, localMatrix: SkMatrix) -> SkShader {
            let handle = SkBitmap_makeShader_3(self.pointer, Int32(tmx.rawValue), Int32(tmy.rawValue), sampling.pointer, localMatrix.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func makeShader_4(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkBitmap_makeShader_4(self.pointer, Int32(tmx.rawValue), Int32(tmy.rawValue), sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func notifyPixelsChanged() {
            SkBitmap_notifyPixelsChanged(self.pointer)
        }

        func peekPixels(pixmap: SkPixmap) -> Bool {
            return SkBitmap_peekPixels(self.pointer, pixmap.pointer)
        }

        func pixelRef() -> SkPixelRef {
            let pointer = SkBitmap_pixelRef(self.pointer)
            return SkPixelRef(pointer: pointer, handle: -1)
        }

        func pixelRefOrigin() -> SkIPoint {
            let handle = SkBitmap_pixelRefOrigin(self.pointer)
            let pointer = static_sk_i_point_get_ptr(handle)
            return SkIPoint(pointer: pointer, handle: handle)
        }

        func pixmap() -> SkPixmap {
            let handle = SkBitmap_pixmap(self.pointer)
            let pointer = static_sk_pixmap_get_ptr(handle)
            return SkPixmap(pointer: pointer, handle: handle)
        }

        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutablePointer<UInt8>?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool {
            return SkBitmap_readPixels(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes, Int32(srcX), Int32(srcY))
        }

        func readPixels(dst: SkPixmap) -> Bool {
            return SkBitmap_readPixels_2(self.pointer, dst.pointer)
        }

        func readPixels(dst: SkPixmap, srcX: Int, srcY: Int) -> Bool {
            return SkBitmap_readPixels_3(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }

        func readyToDraw() -> Bool {
            return SkBitmap_readyToDraw(self.pointer)
        }

        func refColorSpace() -> SkColorSpace {
            let handle = SkBitmap_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get_ptr(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func reset() {
            SkBitmap_reset(self.pointer)
        }

        func rowBytes() -> UInt {
            return UInt(SkBitmap_rowBytes(self.pointer))
        }

        func rowBytesAsPixels() -> Int {
            return Int(SkBitmap_rowBytesAsPixels(self.pointer))
        }

        func setAlphaType(alphaType: SkAlphaType) -> Bool {
            return SkBitmap_setAlphaType(self.pointer, alphaType.rawValue)
        }

        func setImmutable() {
            SkBitmap_setImmutable(self.pointer)
        }

        func setInfo(imageInfo: SkImageInfo, rowBytes: UInt) -> Bool {
            return SkBitmap_setInfo(self.pointer, imageInfo.pointer, rowBytes)
        }

        func setPixelRef(pixelRef: SkPixelRef, dx: Int, dy: Int) {
            SkBitmap_setPixelRef(self.pointer, pixelRef.handle, Int32(dx), Int32(dy))
        }

        func setPixels(pixels: UnsafeMutablePointer<UInt8>?) {
            SkBitmap_setPixels(self.pointer, pixels)
        }

        func shiftPerPixel() -> Int {
            return Int(SkBitmap_shiftPerPixel(self.pointer))
        }

        func swap(other: SkBitmap) {
            SkBitmap_swap(self.pointer, other.pointer)
        }

        func tryAllocN32Pixels(width: Int, height: Int, isOpaque: Bool) -> Bool {
            return SkBitmap_tryAllocN32Pixels(self.pointer, Int32(width), Int32(height), isOpaque)
        }

        func tryAllocPixels() -> Bool {
            return SkBitmap_tryAllocPixels(self.pointer)
        }

        func tryAllocPixels(allocator: SkBitmapAllocator) -> Bool {
            return SkBitmap_tryAllocPixels_2(self.pointer, allocator.pointer)
        }

        func tryAllocPixels(info: SkImageInfo) -> Bool {
            return SkBitmap_tryAllocPixels_3(self.pointer, info.pointer)
        }

        func tryAllocPixels(info: SkImageInfo, rowBytes: UInt) -> Bool {
            return SkBitmap_tryAllocPixels_4(self.pointer, info.pointer, rowBytes)
        }

        func tryAllocPixelsFlags(info: SkImageInfo, flags: UInt) -> Bool {
            return SkBitmap_tryAllocPixelsFlags(self.pointer, info.pointer, UInt32(flags))
        }

        func width() -> Int {
            return Int(SkBitmap_width(self.pointer))
        }

        func writePixels(src: SkPixmap) -> Bool {
            return SkBitmap_writePixels(self.pointer, src.pointer)
        }

        func writePixels(src: SkPixmap, dstX: Int, dstY: Int) -> Bool {
            return SkBitmap_writePixels_2(self.pointer, src.pointer, Int32(dstX), Int32(dstY))
        }
    }
}