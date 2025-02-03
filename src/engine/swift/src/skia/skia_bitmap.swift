extension Skia {
    class Bitmap {
        class Allocator {
            public var pointer: Skia.BitmapAllocatorMutablePointer?

            // void * SkBitmap_Allocator_new(void); // () -> SkBitmap::Allocator *
            init(pointer: Skia.BitmapAllocatorMutablePointer?) {
                self.pointer = pointer
            }

            // bool allocPixelRef (SkBitmap *bitmap)
            
        }

        public var pointer: Skia.BitmapMutablePointer?
        public var handle: Int32?

        // void * SkBitmap_new(void); // () -> SkBitmap *
        init() {
            self.pointer = SkBitmap_new()
        }

        // void * SkBitmap_new_2(const void *src); // (const SkBitmap *src) -> SkBitmap *

        init(src: Bitmap) {
            self.pointer = SkBitmap_new_2(src.pointer)
        }

        // void SkBitmap_delete(void *bitmap); // (SkBitmap *bitmap)
        deinit {
            SkBitmap_delete(self.pointer)
        }
        // void SkBitmap_allocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque)
        func allocN32Pixels(width: Int, height: Int, isOpaque: Bool) {
            SkBitmap_allocN32Pixels(self.pointer, Int32(width), Int32(height), isOpaque)
        }
        // void SkBitmap_allocPixels(void *bitmap); // (SkBitmap *bitmap)
        func allocPixels() {
            SkBitmap_allocPixels(self.pointer)
        }
        // void SkBitmap_allocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator)
        func allocPixels(allocator: Allocator) {
            SkBitmap_allocPixels_2(self.pointer, allocator.pointer)
        }
        // void SkBitmap_allocPixels_3(void *bitmap, const void *info); // (SkBitmap *bitmap, const SkImageInfo *info)
        func allocPixels(info: ImageInfo) {
            SkBitmap_allocPixels_3(self.pointer, info.pointer)
        }
        // void SkBitmap_allocPixels_4(void *bitmap, const void *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes)
        func allocPixels(info: ImageInfo, rowBytes: UInt) {
            SkBitmap_allocPixels_4(self.pointer, info.pointer, rowBytes)
        }
        // void SkBitmap_allocPixelsFlags(void *bitmap, const void *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags)
        func allocPixelsFlags(info: ImageInfo, flags: UInt) {
            SkBitmap_allocPixelsFlags(self.pointer, info.pointer, UInt32(flags))
        }
        // int SkBitmap_alphaType(void *bitmap); // (SkBitmap *bitmap) -> SkAlphaType
        func alphaType() -> AlphaType {
            return Skia.AlphaType(rawValue: SkBitmap_alphaType(self.pointer))!
        }
        // int SkBitmap_asImage(void *bitmap); // (SkBitmap *bitmap) -> sk_image_t
        func asImage() -> Image {
            let handle = SkBitmap_asImage(self.pointer)
            let pointer = static_sk_image_get(handle)
            return Skia.Image(pointer: pointer, handle: handle)
        }
        // int SkBitmap_bounds(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
        func bounds() -> IRect {
            let handle = SkBitmap_bounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // int SkBitmap_bytesPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
        func bytesPerPixel() -> Int {
            return Int(SkBitmap_bytesPerPixel(self.pointer))
        }
        // void * SkBitmap_colorSpace(void *bitmap); // (SkBitmap *bitmap) -> SkColorSpace *
        func colorSpace() -> ColorSpace {
            let pointer = SkBitmap_colorSpace(self.pointer)
            return ColorSpace(pointer: pointer, handle: nil)
        }
        // int SkBitmap_colorType(void *bitmap); // (SkBitmap *bitmap) -> SkColorType
        func colorType() -> ColorType {
            return Skia.ColorType(rawValue: SkBitmap_colorType(self.pointer))!
        }
        // unsigned long SkBitmap_computeByteSize(void *bitmap); // (SkBitmap *bitmap) -> size_t
        func computeByteSize() -> UInt {
            return UInt(SkBitmap_computeByteSize(self.pointer))
        }
        // int SkBitmap_dimensions(void *bitmap); // (SkBitmap *bitmap) -> sk_i_size_t
        func dimensions() -> ISize {
            let handle = SkBitmap_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // bool SkBitmap_drawsNothing(void *bitmap); // (SkBitmap *bitmap) -> bool
        func drawsNothing() -> Bool {
            return SkBitmap_drawsNothing(self.pointer)
        }
        // bool SkBitmap_empty(void *bitmap); // (SkBitmap *bitmap) -> bool
        func empty() -> Bool {
            return SkBitmap_empty(self.pointer)
        }
        // void SkBitmap_erase(void *bitmap, unsigned int c, const void *area); // (SkBitmap *bitmap, SkColor c, const SkIRect *area)
        func erase(c: Skia.ColorARGB8888, area: IRect) {
            SkBitmap_erase(self.pointer, UInt32(c), area.pointer)
        }
        // void SkBitmap_erase_2(void *bitmap, int c, const void *area); // (SkBitmap *bitmap, sk_color_4f_t c, const SkIRect *area)
        func erase(c: Skia.Color4fType, area: IRect) {
            SkBitmap_erase_2(self.pointer, Int32(c.handle), area.pointer)
        }
        // void SkBitmap_eraseArea(void *bitmap, const void *area, unsigned int c); // (SkBitmap *bitmap, const SkIRect *area, SkColor c)
        func eraseArea(area: IRect, c: Skia.ColorARGB8888) {
            SkBitmap_eraseArea(self.pointer, area.pointer, UInt32(c))
        }
        // void SkBitmap_eraseARGB(void *bitmap, unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b)
        func eraseARGB(a: UInt, r: UInt, g: UInt, b: UInt) {
            SkBitmap_eraseARGB(self.pointer, UInt32(a), UInt32(r), UInt32(g), UInt32(b))
        }
        // void SkBitmap_eraseColor(void *bitmap, unsigned int c); // (SkBitmap *bitmap, SkColor c)
        func eraseColor(c: Skia.ColorARGB8888) {
            SkBitmap_eraseColor(self.pointer, UInt32(c))
        }
        // void SkBitmap_eraseColor_2(void *bitmap, int c); // (SkBitmap *bitmap, sk_color_4f_t c)
        func eraseColor(c: Skia.Color4fType) {
            SkBitmap_eraseColor_2(self.pointer, Int32(c.handle))
        }
        // bool SkBitmap_extractAlpha(void *bitmap, void *dst); // (SkBitmap *bitmap, SkBitmap *dst) -> bool
        func extractAlpha(dst: Bitmap) -> Bool {
            return SkBitmap_extractAlpha(self.pointer, dst.pointer)
        }
        // bool SkBitmap_extractAlpha_2(void *bitmap, void *dst, const void *paint, void *allocator, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset) -> bool
        func extractAlpha(dst: Bitmap, paint: Paint, allocator: Allocator, offset: IPoint) -> Bool {
            return SkBitmap_extractAlpha_2(self.pointer, dst.pointer, paint.pointer, allocator.pointer, offset.pointer)
        }
        // bool SkBitmap_extractAlpha_3(void *bitmap, void *dst, const void *paint, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset) -> bool
        func extractAlpha(dst: Bitmap, paint: Paint, offset: IPoint) -> Bool {
            return SkBitmap_extractAlpha_3(self.pointer, dst.pointer, paint.pointer, offset.pointer)
        }
        // bool SkBitmap_extractSubset(void *bitmap, void *dst, const void *subset); // (SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset) -> bool
        func extractSubset(dst: Bitmap, subset: IRect) -> Bool {
            return SkBitmap_extractSubset(self.pointer, dst.pointer, subset.pointer)
        }
        // void * SkBitmap_getAddr(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> void *
        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkBitmap_getAddr(self.pointer, Int32(x), Int32(y))
        }
        // void * SkBitmap_getAddr16(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint16_t *
        func getAddr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkBitmap_getAddr16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // void * SkBitmap_getAddr32(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint32_t *
        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkBitmap_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }
        // void * SkBitmap_getAddr8(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint8_t *
        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkBitmap_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // float SkBitmap_getAlphaf(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> float
        func getAlphaf(x: Int, y: Int) -> Float {
            return SkBitmap_getAlphaf(self.pointer, Int32(x), Int32(y))
        }
        // void SkBitmap_getBounds(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkIRect *bounds)
        func getBounds(bounds: inout IRect) {
            SkBitmap_getBounds(self.pointer, bounds.pointer)
        }
        // void SkBitmap_getBounds2(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkRect *bounds)
        func getBounds(bounds: inout Rect) {
            SkBitmap_getBounds2(self.pointer, bounds.pointer)
        }
        // unsigned int SkBitmap_getColor(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> SkColor
        func getColor(x: Int, y: Int) -> Skia.ColorARGB8888 {
            return SkBitmap_getColor(self.pointer, Int32(x), Int32(y))
        }
        // int SkBitmap_getColor4f(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> sk_color_4f_t
        func getColor4f(x: Int, y: Int) -> Color4f {
            let handle = SkBitmap_getColor4f(self.pointer, Int32(x), Int32(y))
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }
        // unsigned int SkBitmap_getGenerationID(void *bitmap); // (SkBitmap *bitmap) -> uint32_t
        func getGenerationID() -> UInt {
            return UInt(SkBitmap_getGenerationID(self.pointer))
        }
        // void * SkBitmap_getPixels(void *bitmap); // (SkBitmap *bitmap) -> void *
        func getPixels() -> UnsafeMutablePointer<UInt8>? {
            return SkBitmap_getPixels(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }
        func getPixelsPtr() -> UnsafeMutableRawPointer? {
            return SkBitmap_getPixels(self.pointer)
        }
        // int SkBitmap_getSubset(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
        func getSubset() -> IRect {
            let handle = SkBitmap_getSubset(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // int SkBitmap_height(void *bitmap); // (SkBitmap *bitmap) -> int
        func height() -> Int {
            return Int(SkBitmap_height(self.pointer))
        }
        // int SkBitmap_info(void *bitmap); // (SkBitmap *bitmap) -> sk_image_info_t
        func info() -> ImageInfo {
            let handle = SkBitmap_info(self.pointer)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // bool SkBitmap_installMaskPixels(void *bitmap, void *mask); // (SkBitmap *bitmap, SkMaskBuilder *mask) -> bool
        func installMaskPixels(mask: MaskBuilder) -> Bool {
            return SkBitmap_installMaskPixels(self.pointer, mask.pointer)
        }
        // bool SkBitmap_installPixels(void *bitmap, const void *info, void *pixels, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) -> bool
        func installPixels(info: ImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt) -> Bool {
            return SkBitmap_installPixels(self.pointer, info.pointer, pixels, rowBytes)
        }
        // bool SkBitmap_installPixels_2(void *bitmap, const void *info, void *pixels, unsigned long rowBytes, void(*releaseProc)(void *addr, void *context), void *context); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context) -> bool
        typealias ReleaseProc = @convention(c) (UnsafeMutableRawPointer?, UnsafeMutableRawPointer?) -> Void
        func installPixels(info: ImageInfo, pixels: UnsafeMutablePointer<UInt8>?, rowBytes: UInt, releaseProc: @escaping ReleaseProc, context: UnsafeMutableRawPointer?) -> Bool {
            return SkBitmap_installPixels_2(self.pointer, info.pointer, pixels, rowBytes, releaseProc, context)
        }
        // bool SkBitmap_installPixels_3(void *bitmap, const void *pixmap); // (SkBitmap *bitmap, const SkPixmap *pixmap) -> bool
        func installPixels(pixmap: Pixmap) -> Bool {
            return SkBitmap_installPixels_3(self.pointer, pixmap.pointer)
        }
        // bool SkBitmap_isImmutable(void *bitmap); // (SkBitmap *bitmap) -> bool

        func isImmutable() -> Bool {
            return SkBitmap_isImmutable(self.pointer)
        }
        // bool SkBitmap_isNull(void *bitmap); // (SkBitmap *bitmap) -> bool
        func isNull() -> Bool {
            return SkBitmap_isNull(self.pointer)
        }
        // bool SkBitmap_isOpaque(void *bitmap); // (SkBitmap *bitmap) -> bool
        func isOpaque() -> Bool {
            return SkBitmap_isOpaque(self.pointer)
        }
        // int SkBitmap_makeShader(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func makeShader(sampling: SamplingOptions, lm: Matrix) -> Shader {
            let handle = SkBitmap_makeShader(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkBitmap_makeShader_2(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func makeShader_2(sampling: SamplingOptions, lm: Matrix) -> Shader {
            let handle = SkBitmap_makeShader_2(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkBitmap_makeShader_3(void *bitmap, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t
        func makeShader_3(tmx: TileMode, tmy: TileMode, sampling: SamplingOptions, localMatrix: Matrix) -> Shader {
            let handle = SkBitmap_makeShader_3(self.pointer, Int32(tmx.rawValue), Int32(tmy.rawValue), sampling.pointer, localMatrix.pointer)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkBitmap_makeShader_4(void *bitmap, int tmx, int tmy, const void *sampling, const void *lm); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        func makeShader_4(tmx: TileMode, tmy: TileMode, sampling: SamplingOptions, lm: Matrix) -> Shader {
            let handle = SkBitmap_makeShader_4(self.pointer, Int32(tmx.rawValue), Int32(tmy.rawValue), sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // void SkBitmap_notifyPixelsChanged(void *bitmap); // (SkBitmap *bitmap)
        func notifyPixelsChanged() {
            SkBitmap_notifyPixelsChanged(self.pointer)
        }
        // bool SkBitmap_peekPixels(void *bitmap, void *pixmap); // (SkBitmap *bitmap, SkPixmap *pixmap) -> bool
        func peekPixels(pixmap: Pixmap) -> Bool {
            return SkBitmap_peekPixels(self.pointer, pixmap.pointer)
        }
        // void * SkBitmap_pixelRef(void *bitmap); // (SkBitmap *bitmap) -> SkPixelRef *
        func pixelRef() -> PixelRef {
            let pointer = SkBitmap_pixelRef(self.pointer)
            return PixelRef(pointer: pointer, handle: nil)
        }
        // int SkBitmap_pixelRefOrigin(void *bitmap); // (SkBitmap *bitmap) -> sk_i_point_t
        func pixelRefOrigin() -> IPoint {
            let handle = SkBitmap_pixelRefOrigin(self.pointer)
            let pointer = static_sk_i_point_get_ptr(handle)
            return IPoint(pointer: pointer, handle: handle)
        }
        // int SkBitmap_pixmap(void *bitmap); // (SkBitmap *bitmap) -> sk_pixmap_t
        func pixmap() -> Pixmap {
            let handle = SkBitmap_pixmap(self.pointer)
            let pointer = static_sk_pixmap_get_ptr(handle)
            return Pixmap(pointer: pointer, handle: handle)
        }
        // bool SkBitmap_readPixels(void *bitmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
        func readPixels(dstInfo: ImageInfo, dstPixels: UnsafeMutablePointer<UInt8>?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool {
            return SkBitmap_readPixels(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes, Int32(srcX), Int32(srcY))
        }
        // bool SkBitmap_readPixels_2(void *bitmap, const void *dst); // (SkBitmap *bitmap, const SkPixmap *dst) -> bool
        func readPixels(dst: Pixmap) -> Bool {
            return SkBitmap_readPixels_2(self.pointer, dst.pointer)
        }
        // bool SkBitmap_readPixels_3(void *bitmap, const void *dst, int srcX, int srcY); // (SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY) -> bool
        func readPixels(dst: Pixmap, srcX: Int, srcY: Int) -> Bool {
            return SkBitmap_readPixels_3(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }
        // bool SkBitmap_readyToDraw(void *bitmap); // (SkBitmap *bitmap) -> bool
        func readyToDraw() -> Bool {
            return SkBitmap_readyToDraw(self.pointer)
        }
        // int SkBitmap_refColorSpace(void *bitmap); // (SkBitmap *bitmap) -> sk_color_space_t
        func refColorSpace() -> ColorSpace {
            let handle = SkBitmap_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // void SkBitmap_reset(void *bitmap); // (SkBitmap *bitmap)
        func reset() {
            SkBitmap_reset(self.pointer)
        }
        // unsigned long SkBitmap_rowBytes(void *bitmap); // (SkBitmap *bitmap) -> size_t
        func rowBytes() -> UInt {
            return UInt(SkBitmap_rowBytes(self.pointer))
        }
        // int SkBitmap_rowBytesAsPixels(void *bitmap); // (SkBitmap *bitmap) -> int
        func rowBytesAsPixels() -> Int {
            return Int(SkBitmap_rowBytesAsPixels(self.pointer))
        }
        // bool SkBitmap_setAlphaType(void *bitmap, int alphaType); // (SkBitmap *bitmap, SkAlphaType alphaType) -> bool
        func setAlphaType(alphaType: AlphaType) -> Bool {
            return SkBitmap_setAlphaType(self.pointer, alphaType.rawValue)
        }
        // void SkBitmap_setImmutable(void *bitmap); // (SkBitmap *bitmap)
        func setImmutable() {
            SkBitmap_setImmutable(self.pointer)
        }
        // bool SkBitmap_setInfo(void *bitmap, const void *imageInfo, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes) -> bool
        func setInfo(imageInfo: ImageInfo, rowBytes: UInt) -> Bool {
            return SkBitmap_setInfo(self.pointer, imageInfo.pointer, rowBytes)
        }
        // void SkBitmap_setPixelRef(void *bitmap, int pixelRef, int dx, int dy); // (SkBitmap *bitmap, sk_pixel_ref_t pixelRef, int dx, int dy)
        func setPixelRef(pixelRef: PixelRef, dx: Int, dy: Int) {
            guard let handle = pixelRef.handle else {
                fatalError("PixelRef handle is nil")
            }
            SkBitmap_setPixelRef(self.pointer, handle, Int32(dx), Int32(dy))
        }
        // void SkBitmap_setPixels(void *bitmap, void *pixels); // (SkBitmap *bitmap, void *pixels)
        func setPixels(pixels: UnsafeMutablePointer<UInt8>?) {
            SkBitmap_setPixels(self.pointer, pixels)
        }
        // int SkBitmap_shiftPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
        func shiftPerPixel() -> Int {
            return Int(SkBitmap_shiftPerPixel(self.pointer))
        }
        // void SkBitmap_swap(void *bitmap, void *other); // (SkBitmap *bitmap, SkBitmap *other)
        func swap(other: Bitmap) {
            SkBitmap_swap(self.pointer, other.pointer)
        }
        // bool SkBitmap_tryAllocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque) -> bool
        func tryAllocN32Pixels(width: Int, height: Int, isOpaque: Bool) -> Bool {
            return SkBitmap_tryAllocN32Pixels(self.pointer, Int32(width), Int32(height), isOpaque)
        }
        // bool SkBitmap_tryAllocPixels(void *bitmap); // (SkBitmap *bitmap) -> bool
        func tryAllocPixels() -> Bool {
            return SkBitmap_tryAllocPixels(self.pointer)
        }
        // bool SkBitmap_tryAllocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator) -> bool
        func tryAllocPixels(allocator: Allocator) -> Bool {
            return SkBitmap_tryAllocPixels_2(self.pointer, allocator.pointer)
        }
        // bool SkBitmap_tryAllocPixels_3(void *bitmap, const void *info); // (SkBitmap *bitmap, const SkImageInfo *info) -> bool
        func tryAllocPixels(info: ImageInfo) -> Bool {
            return SkBitmap_tryAllocPixels_3(self.pointer, info.pointer)
        }
        // bool SkBitmap_tryAllocPixels_4(void *bitmap, const void *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes) -> bool
        func tryAllocPixels(info: ImageInfo, rowBytes: UInt) -> Bool {
            return SkBitmap_tryAllocPixels_4(self.pointer, info.pointer, rowBytes)
        }
        // bool SkBitmap_tryAllocPixelsFlags(void *bitmap, const void *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags) -> bool
        func tryAllocPixelsFlags(info: ImageInfo, flags: UInt) -> Bool {
            return SkBitmap_tryAllocPixelsFlags(self.pointer, info.pointer, UInt32(flags))
        }
        // int SkBitmap_width(void *bitmap); // (SkBitmap *bitmap) -> int
        func width() -> Int {
            return Int(SkBitmap_width(self.pointer))
        }
        // bool SkBitmap_writePixels(void *bitmap, const void *src); // (SkBitmap *bitmap, const SkPixmap *src) -> bool
        func writePixels(src: Pixmap) -> Bool {
            return SkBitmap_writePixels(self.pointer, src.pointer)
        }
        // bool SkBitmap_writePixels_2(void *bitmap, const void *src, int dstX, int dstY); // (SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY) -> bool
        func writePixels(src: Pixmap, dstX: Int, dstY: Int) -> Bool {
            return SkBitmap_writePixels_2(self.pointer, src.pointer, Int32(dstX), Int32(dstY))
        }
        // // static

        init(pointer: Skia.BitmapMutablePointer?, handle: Int32?) {
            self.pointer = pointer
            self.handle = handle
        }

        
        // bool SkBitmap_ComputeIsOpaque(const void *bm); // (const SkBitmap *bm) -> bool
        static func ComputeIsOpaque(bm: Bitmap) -> Bool {
            return SkBitmap_ComputeIsOpaque(bm.pointer)
        }

    }
}