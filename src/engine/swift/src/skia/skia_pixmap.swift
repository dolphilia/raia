extension Skia {
    class Pixmap {
        public var pointer: Skia.PixmapMutablePointer?
        public var handle: sk_pixmap_t = -1

        // void *SkPixmap_new(); // () -> SkPixmap *

        init () {
            self.pointer = SkPixmap_new()
            self.handle = -1
        }
        // void *SkPixmap_new_2(const void *info, const void *addr, unsigned long rowBytes); // (const SkImageInfo *info, const void *addr, size_t rowBytes) -> SkPixmap *
        init(info: Skia.ImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) {
            self.pointer = SkPixmap_new_2(info.pointer, addr, rowBytes)
            self.handle = -1
        }
        // void SkPixmap_delete(void *pixmap); // (SkPixmap *pixmap)
        deinit {
            SkPixmap_delete(self.pointer)
            if handle > -1 {
                static_sk_pixmap_delete(handle)
            }
        }
        // void SkPixmap_reset(void *pixmap); // (SkPixmap *pixmap)
        func reset() {
            SkPixmap_reset(self.pointer)
        }
        // void SkPixmap_reset_2(void *pixmap, const void *info, const void *addr, unsigned long rowBytes); // (SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes)
        func reset(info: ImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) {
            SkPixmap_reset_2(self.pointer, info.pointer, addr, rowBytes)
        }
        // bool SkPixmap_reset_3(void *pixmap, const void *mask); // (SkPixmap *pixmap, const SkMask *mask) -> bool
        func reset(mask: Mask) -> Bool {
            return SkPixmap_reset_3(self.pointer, mask.pointer)
        }
        // void SkPixmap_setColorSpace(void *pixmap, int color_space); // (SkPixmap *pixmap, sk_color_space_t color_space)
        func setColorSpace(colorSpace: ColorSpace) {
            SkPixmap_setColorSpace(self.pointer, colorSpace.handle)
        }
        // bool SkPixmap_extractSubset(void *pixmap, void *subset, const void *area); // (SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area) -> bool
        func extractSubset(subset: Pixmap, area: IRect) -> Bool {
            return SkPixmap_extractSubset(self.pointer, subset.pointer, area.pointer)
        }
        // const void *SkPixmap_info(void *pixmap); // (SkPixmap *pixmap) -> const SkImageInfo *
        func info() -> ImageInfo {
            let pointer = SkPixmap_info(self.pointer)
            return ImageInfo(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // unsigned long SkPixmap_rowBytes(void *pixmap); // (SkPixmap *pixmap) -> size_t
        func rowBytes() -> UInt {
            return SkPixmap_rowBytes(self.pointer)
        }
        // const void *SkPixmap_addr(void *pixmap); // (SkPixmap *pixmap) -> const void *
        func addr() -> UnsafeRawPointer? {
            return SkPixmap_addr(self.pointer)
        }
        // int SkPixmap_width(void *pixmap); // (SkPixmap *pixmap) -> int
        func width() -> Int {
            return Int(SkPixmap_width(self.pointer))
        }
        // int SkPixmap_height(void *pixmap); // (SkPixmap *pixmap) -> int
        func height() -> Int {
            return Int(SkPixmap_height(self.pointer))
        }
        // int SkPixmap_dimensions(void *pixmap); // (SkPixmap *pixmap) -> sk_i_size_t
        func dimensions() -> ISize {
            let handle = SkPixmap_dimensions(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkPixmap_colorType(void *pixmap); // (SkPixmap *pixmap) -> SkColorType
        func colorType() -> ColorType {
            return ColorType(rawValue: SkPixmap_colorType(self.pointer)) ?? .unknown
        }
        // int SkPixmap_alphaType(void *pixmap); // (SkPixmap *pixmap) -> SkAlphaType
        func alphaType() -> AlphaType {
            return AlphaType(rawValue: SkPixmap_alphaType(self.pointer)) ?? .unknown
        }
        // void *SkPixmap_colorSpace(void *pixmap); // (SkPixmap *pixmap) -> SkColorSpace *
        func colorSpace() -> ColorSpace {
            let pointer = SkPixmap_colorSpace(self.pointer)
            return ColorSpace(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // int SkPixmap_refColorSpace(void *pixmap); // (SkPixmap *pixmap) -> sk_color_space_t
        func refColorSpace() -> ColorSpace {
            let handle = SkPixmap_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // bool SkPixmap_isOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
        func isOpaque() -> Bool {
            return SkPixmap_isOpaque(self.pointer)
        }
        // int SkPixmap_bounds(void *pixmap); // (SkPixmap *pixmap) -> sk_i_rect_t
        func bounds() -> IRect {
            let handle = SkPixmap_bounds(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // int SkPixmap_rowBytesAsPixels(void *pixmap); // (SkPixmap *pixmap) -> int
        func rowBytesAsPixels() -> Int {
            return Int(SkPixmap_rowBytesAsPixels(self.pointer))
        }
        // int SkPixmap_shiftPerPixel(void *pixmap); // (SkPixmap *pixmap) -> int
        func shiftPerPixel() -> Int {
            return Int(SkPixmap_shiftPerPixel(self.pointer))
        }
        // unsigned long SkPixmap_computeByteSize(void *pixmap); // (SkPixmap *pixmap) -> size_t
        func computeByteSize() -> UInt {
            return SkPixmap_computeByteSize(self.pointer)
        }
        // bool SkPixmap_computeIsOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
        func computeIsOpaque() -> Bool {
            return SkPixmap_computeIsOpaque(self.pointer)
        }
        // unsigned int SkPixmap_getColor(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> SkColor
        func getColor(x: Int, y: Int) -> ColorARGB8888 {
            return SkPixmap_getColor(self.pointer, Int32(x), Int32(y))
        }
        // int SkPixmap_getColor4f(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> sk_color_4f_t
        func getColor4f(x: Int, y: Int) -> Color4f {
            let handle = SkPixmap_getColor4f(self.pointer, Int32(x), Int32(y));
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }
        // float SkPixmap_getAlphaf(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> float
        func getAlphaf(x: Int, y: Int) -> Float {
            return SkPixmap_getAlphaf(self.pointer, Int32(x), Int32(y))
        }
        // const void *SkPixmap_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const void *
        func addr(x: Int, y: Int) -> UnsafeRawPointer? {
            return SkPixmap_addr_2(self.pointer, Int32(x), Int32(y))
        }
        // const void *SkPixmap_addr8(void *pixmap); // (SkPixmap *pixmap) -> const uint8_t *
        func addr8() -> UnsafePointer<UInt8>? {
            return SkPixmap_addr8(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }
        // const void *SkPixmap_addr16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
        func addr16() -> UnsafePointer<UInt16>? {
            return SkPixmap_addr16(self.pointer)?.assumingMemoryBound(to: UInt16.self)
        }
        // const void *SkPixmap_addr32(void *pixmap); // (SkPixmap *pixmap) -> const uint32_t *
        func addr32() -> UnsafePointer<UInt32>? {
            return SkPixmap_addr32(self.pointer)?.assumingMemoryBound(to: UInt32.self)
        }
        // const void *SkPixmap_addr64(void *pixmap); // (SkPixmap *pixmap) -> const uint64_t *
        func addr64() -> UnsafePointer<UInt64>? {
            return SkPixmap_addr64(self.pointer)?.assumingMemoryBound(to: UInt64.self)
        }
        // const void *SkPixmap_addrF16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
        func addrF16() -> UnsafePointer<UInt16>? {
            return SkPixmap_addrF16(self.pointer)?.assumingMemoryBound(to: UInt16.self)
        }
        // const void *SkPixmap_addr8_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint8_t *
        func addr8(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkPixmap_addr8_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // const void *SkPixmap_addr16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
        func addr16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkPixmap_addr16_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // const void *SkPixmap_addr32_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint32_t *
        func addr32(x: Int, y: Int) -> UnsafePointer<UInt32>? {
            return SkPixmap_addr32_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }
        // const void *SkPixmap_addr64_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint64_t *
        func addr64(x: Int, y: Int) -> UnsafePointer<UInt64>? {
            return SkPixmap_addr64_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt64.self)
        }
        // const void *SkPixmap_addrF16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
        func addrF16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkPixmap_addrF16_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // void *SkPixmap_writable_addr(void *pixmap); // (SkPixmap *pixmap) -> void *
        func writable_addr() -> UnsafeMutableRawPointer? {
            return SkPixmap_writable_addr(self.pointer)
        }
        // void *SkPixmap_writable_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> void *
        func writable_addr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkPixmap_writable_addr_2(self.pointer, Int32(x), Int32(y))
        }
        // void *SkPixmap_writable_addr8(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint8_t *
        func writable_addr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkPixmap_writable_addr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // void *SkPixmap_writable_addr16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
        func writable_addr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkPixmap_writable_addr16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // void *SkPixmap_writable_addr32(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint32_t *
        func writable_addr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkPixmap_writable_addr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }
        // void *SkPixmap_writable_addr64(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint64_t *
        func writable_addr64(x: Int, y: Int) -> UnsafeMutablePointer<UInt64>? {
            return SkPixmap_writable_addr64(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt64.self)
        }
        // void *SkPixmap_writable_addrF16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
        func writable_addrF16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkPixmap_writable_addrF16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // bool SkPixmap_readPixels(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes) -> bool
        func readPixels(dstInfo: ImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt) -> Bool {
            return SkPixmap_readPixels(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes)
        }
        // bool SkPixmap_readPixels_2(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
        func readPixels(dstInfo: ImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool {
            return SkPixmap_readPixels_2(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes, Int32(srcX), Int32(srcY))
        }
        // bool SkPixmap_readPixels_3(void *pixmap, const void *dst, int srcX, int srcY); // (SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY) -> bool
        func readPixels(dst: Pixmap, srcX: Int, srcY: Int) -> Bool {
            return SkPixmap_readPixels_3(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }
        // bool SkPixmap_readPixels_4(void *pixmap, const void *dst); // (SkPixmap *pixmap, const SkPixmap *dst) -> bool
        func readPixels(dst: Pixmap) -> Bool {
            return SkPixmap_readPixels_4(self.pointer, dst.pointer)
        }
        // bool SkPixmap_scalePixels(void *pixmap, const void *dst, const void *options); // (SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options) -> bool
        func scalePixels(dst: Pixmap, options: SamplingOptions) -> Bool {
            return SkPixmap_scalePixels(self.pointer, dst.pointer, options.pointer)
        }
        // bool SkPixmap_erase(void *pixmap, unsigned int color, const void *subset); // (SkPixmap *pixmap, SkColor color, const SkIRect *subset) -> bool
        func erase(color: ColorARGB8888, subset: IRect) -> Bool {
            return SkPixmap_erase(self.pointer, color, subset.pointer)
        }
        // bool SkPixmap_erase_2(void *pixmap, unsigned int color); // (SkPixmap *pixmap, SkColor color) -> bool
        func erase(color: ColorARGB8888) -> Bool {
            return SkPixmap_erase_2(self.pointer, color)
        }
        // bool SkPixmap_erase_3(void *pixmap, const void *color, const void *subset); // (SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset) -> bool
        func erase(color: Color4f, subset: IRect) -> Bool {
            return SkPixmap_erase_3(self.pointer, color.pointer, subset.pointer)
        }

        // static

        init(pointer: Skia.PixmapMutablePointer?, handle: sk_pixmap_t) {
            self.pointer = pointer
            self.handle = handle
        }

    }
}