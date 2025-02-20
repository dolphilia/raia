extension Skia {
    protocol SkPixmapProtocol {
        var pointer: SkPixmapMutablePointer? { get set }
        var handle: sk_pixmap_t { get set }
        // deinit // void SkPixmap_delete(void *pixmap); // (SkPixmap *pixmap)
        init(pointer: SkPixmapMutablePointer?, handle: sk_pixmap_t)
        init () // void *SkPixmap_new(); // () -> SkPixmap *
        init(info: SkImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) // void *SkPixmap_new_2(const void *info, const void *addr, unsigned long rowBytes); // (const SkImageInfo *info, const void *addr, size_t rowBytes) -> SkPixmap *
        // Methods
        func reset() // void SkPixmap_reset(void *pixmap); // (SkPixmap *pixmap)
        func reset(info: SkImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) // void SkPixmap_reset_2(void *pixmap, const void *info, const void *addr, unsigned long rowBytes); // (SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes)
        func reset(mask: SkMask) -> Bool // bool SkPixmap_reset_3(void *pixmap, const void *mask); // (SkPixmap *pixmap, const SkMask *mask) -> bool
        func setColorSpace(colorSpace: SkColorSpace) // void SkPixmap_setColorSpace(void *pixmap, int color_space); // (SkPixmap *pixmap, sk_color_space_t color_space)
        func extractSubset(subset: SkPixmap, area: SkIRect) -> Bool // bool SkPixmap_extractSubset(void *pixmap, void *subset, const void *area); // (SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area) -> bool
        func info() -> SkImageInfo // const void *SkPixmap_info(void *pixmap); // (SkPixmap *pixmap) -> const SkImageInfo *
        func rowBytes() -> UInt // unsigned long SkPixmap_rowBytes(void *pixmap); // (SkPixmap *pixmap) -> size_t
        func addr() -> UnsafeRawPointer? // const void *SkPixmap_addr(void *pixmap); // (SkPixmap *pixmap) -> const void *
        func width() -> Int // int SkPixmap_width(void *pixmap); // (SkPixmap *pixmap) -> int
        func height() -> Int // int SkPixmap_height(void *pixmap); // (SkPixmap *pixmap) -> int
        func dimensions() -> SkISize // int SkPixmap_dimensions(void *pixmap); // (SkPixmap *pixmap) -> sk_i_size_t
        func colorType() -> SkColorType // int SkPixmap_colorType(void *pixmap); // (SkPixmap *pixmap) -> SkColorType
        func alphaType() -> SkAlphaType // int SkPixmap_alphaType(void *pixmap); // (SkPixmap *pixmap) -> SkAlphaType
        func colorSpace() -> SkColorSpace // void *SkPixmap_colorSpace(void *pixmap); // (SkPixmap *pixmap) -> SkColorSpace *
        func refColorSpace() -> SkColorSpace // int SkPixmap_refColorSpace(void *pixmap); // (SkPixmap *pixmap) -> sk_color_space_t
        func isOpaque() -> Bool // bool SkPixmap_isOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
        func bounds() -> SkIRect // int SkPixmap_bounds(void *pixmap); // (SkPixmap *pixmap) -> sk_i_rect_t
        func rowBytesAsPixels() -> Int // int SkPixmap_rowBytesAsPixels(void *pixmap); // (SkPixmap *pixmap) -> int
        func shiftPerPixel() -> Int // int SkPixmap_shiftPerPixel(void *pixmap); // (SkPixmap *pixmap) -> int
        func computeByteSize() -> UInt // unsigned long SkPixmap_computeByteSize(void *pixmap); // (SkPixmap *pixmap) -> size_t
        func computeIsOpaque() -> Bool // bool SkPixmap_computeIsOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
        func getColor(x: Int, y: Int) -> SkColor // unsigned int SkPixmap_getColor(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> SkColor
        func getColor4f(x: Int, y: Int) -> SkColor4f // int SkPixmap_getColor4f(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> sk_color_4f_t
        func getAlphaf(x: Int, y: Int) -> Float // float SkPixmap_getAlphaf(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> float
        func addr(x: Int, y: Int) -> UnsafeRawPointer? // const void *SkPixmap_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const void *
        func addr8() -> UnsafePointer<UInt8>? // const void *SkPixmap_addr8(void *pixmap); // (SkPixmap *pixmap) -> const uint8_t *
        func addr16() -> UnsafePointer<UInt16>? // const void *SkPixmap_addr16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
        func addr32() -> UnsafePointer<UInt32>? // const void *SkPixmap_addr32(void *pixmap); // (SkPixmap *pixmap) -> const uint32_t *
        func addr64() -> UnsafePointer<UInt64>? // const void *SkPixmap_addr64(void *pixmap); // (SkPixmap *pixmap) -> const uint64_t *
        func addrF16() -> UnsafePointer<UInt16>? // const void *SkPixmap_addrF16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
        func addr8(x: Int, y: Int) -> UnsafePointer<UInt8>? // const void *SkPixmap_addr8_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint8_t *
        func addr16(x: Int, y: Int) -> UnsafePointer<UInt16>? // const void *SkPixmap_addr16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
        func addr32(x: Int, y: Int) -> UnsafePointer<UInt32>? // const void *SkPixmap_addr32_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint32_t *
        func addr64(x: Int, y: Int) -> UnsafePointer<UInt64>? // const void *SkPixmap_addr64_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint64_t *
        func addrF16(x: Int, y: Int) -> UnsafePointer<UInt16>? // const void *SkPixmap_addrF16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
        func writable_addr() -> UnsafeMutableRawPointer? // void *SkPixmap_writable_addr(void *pixmap); // (SkPixmap *pixmap) -> void *
        func writable_addr(x: Int, y: Int) -> UnsafeMutableRawPointer? // void *SkPixmap_writable_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> void *
        func writable_addr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? // void *SkPixmap_writable_addr8(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint8_t *
        func writable_addr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? // void *SkPixmap_writable_addr16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
        func writable_addr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? // void *SkPixmap_writable_addr32(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint32_t *
        func writable_addr64(x: Int, y: Int) -> UnsafeMutablePointer<UInt64>? // void *SkPixmap_writable_addr64(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint64_t *
        func writable_addrF16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? // void *SkPixmap_writable_addrF16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt) -> Bool // bool SkPixmap_readPixels(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes) -> bool
        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool // bool SkPixmap_readPixels_2(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
        func readPixels(dst: SkPixmap, srcX: Int, srcY: Int) -> Bool // bool SkPixmap_readPixels_3(void *pixmap, const void *dst, int srcX, int srcY); // (SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY) -> bool
        func readPixels(dst: SkPixmap) -> Bool // bool SkPixmap_readPixels_4(void *pixmap, const void *dst); // (SkPixmap *pixmap, const SkPixmap *dst) -> bool
        func scalePixels(dst: SkPixmap, options: SkSamplingOptions) -> Bool // bool SkPixmap_scalePixels(void *pixmap, const void *dst, const void *options); // (SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options) -> bool
        func erase(color: SkColor, subset: SkIRect) -> Bool // bool SkPixmap_erase(void *pixmap, unsigned int color, const void *subset); // (SkPixmap *pixmap, SkColor color, const SkIRect *subset) -> bool
        func erase(color: SkColor) -> Bool // bool SkPixmap_erase_2(void *pixmap, unsigned int color); // (SkPixmap *pixmap, SkColor color) -> bool
        func erase(color: SkColor4f, subset: SkIRect) -> Bool // bool SkPixmap_erase_3(void *pixmap, const void *color, const void *subset); // (SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset) -> bool
    }

    class SkPixmap : SkPixmapProtocol {
        public var pointer: SkPixmapMutablePointer?
        public var handle: sk_pixmap_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_pixmap_delete(self.handle)
            } else {
                SkPixmap_delete(self.pointer)
            }
        }

        required init(pointer: SkPixmapMutablePointer?, handle: sk_pixmap_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init () {
            self.pointer = SkPixmap_new()
            self.handle = -1
        }

        required init(info: SkImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) {
            self.pointer = SkPixmap_new_2(info.pointer, addr, rowBytes)
            self.handle = -1
        }

        // Methods

        func reset() {
            SkPixmap_reset(self.pointer)
        }

        func reset(info: SkImageInfo, addr: UnsafeRawPointer?, rowBytes: UInt) {
            SkPixmap_reset_2(self.pointer, info.pointer, addr, rowBytes)
        }

        func reset(mask: SkMask) -> Bool {
            return SkPixmap_reset_3(self.pointer, mask.pointer)
        }

        func setColorSpace(colorSpace: SkColorSpace) {
            SkPixmap_setColorSpace(self.pointer, colorSpace.handle)
        }

        func extractSubset(subset: SkPixmap, area: SkIRect) -> Bool {
            return SkPixmap_extractSubset(self.pointer, subset.pointer, area.pointer)
        }

        func info() -> SkImageInfo {
            let pointer = SkPixmap_info(self.pointer)
            return SkImageInfo(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func rowBytes() -> UInt {
            return SkPixmap_rowBytes(self.pointer)
        }

        func addr() -> UnsafeRawPointer? {
            return SkPixmap_addr(self.pointer)
        }

        func width() -> Int {
            return Int(SkPixmap_width(self.pointer))
        }

        func height() -> Int {
            return Int(SkPixmap_height(self.pointer))
        }

        func dimensions() -> SkISize {
            let handle = SkPixmap_dimensions(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        func colorType() -> SkColorType {
            return SkColorType(rawValue: SkPixmap_colorType(self.pointer)) ?? .unknown
        }

        func alphaType() -> SkAlphaType {
            return SkAlphaType(rawValue: SkPixmap_alphaType(self.pointer)) ?? .unknown
        }

        func colorSpace() -> SkColorSpace {
            let pointer = SkPixmap_colorSpace(self.pointer)
            return SkColorSpace(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func refColorSpace() -> SkColorSpace {
            let handle = SkPixmap_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func isOpaque() -> Bool {
            return SkPixmap_isOpaque(self.pointer)
        }

        func bounds() -> SkIRect {
            let handle = SkPixmap_bounds(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        func rowBytesAsPixels() -> Int {
            return Int(SkPixmap_rowBytesAsPixels(self.pointer))
        }

        func shiftPerPixel() -> Int {
            return Int(SkPixmap_shiftPerPixel(self.pointer))
        }

        func computeByteSize() -> UInt {
            return SkPixmap_computeByteSize(self.pointer)
        }

        func computeIsOpaque() -> Bool {
            return SkPixmap_computeIsOpaque(self.pointer)
        }

        func getColor(x: Int, y: Int) -> SkColor {
            return SkColor(color: SkPixmap_getColor(self.pointer, Int32(x), Int32(y)))
        }

        func getColor4f(x: Int, y: Int) -> SkColor4f {
            let handle = SkPixmap_getColor4f(self.pointer, Int32(x), Int32(y));
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        func getAlphaf(x: Int, y: Int) -> Float {
            return SkPixmap_getAlphaf(self.pointer, Int32(x), Int32(y))
        }

        func addr(x: Int, y: Int) -> UnsafeRawPointer? {
            return SkPixmap_addr_2(self.pointer, Int32(x), Int32(y))
        }

        func addr8() -> UnsafePointer<UInt8>? {
            return SkPixmap_addr8(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }

        func addr16() -> UnsafePointer<UInt16>? {
            return SkPixmap_addr16(self.pointer)?.assumingMemoryBound(to: UInt16.self)
        }

        func addr32() -> UnsafePointer<UInt32>? {
            return SkPixmap_addr32(self.pointer)?.assumingMemoryBound(to: UInt32.self)
        }

        func addr64() -> UnsafePointer<UInt64>? {
            return SkPixmap_addr64(self.pointer)?.assumingMemoryBound(to: UInt64.self)
        }

        func addrF16() -> UnsafePointer<UInt16>? {
            return SkPixmap_addrF16(self.pointer)?.assumingMemoryBound(to: UInt16.self)
        }

        func addr8(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkPixmap_addr8_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func addr16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkPixmap_addr16_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func addr32(x: Int, y: Int) -> UnsafePointer<UInt32>? {
            return SkPixmap_addr32_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }

        func addr64(x: Int, y: Int) -> UnsafePointer<UInt64>? {
            return SkPixmap_addr64_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt64.self)
        }

        func addrF16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkPixmap_addrF16_2(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func writable_addr() -> UnsafeMutableRawPointer? {
            return SkPixmap_writable_addr(self.pointer)
        }

        func writable_addr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkPixmap_writable_addr_2(self.pointer, Int32(x), Int32(y))
        }

        func writable_addr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkPixmap_writable_addr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func writable_addr16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkPixmap_writable_addr16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func writable_addr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkPixmap_writable_addr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }

        func writable_addr64(x: Int, y: Int) -> UnsafeMutablePointer<UInt64>? {
            return SkPixmap_writable_addr64(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt64.self)
        }

        func writable_addrF16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkPixmap_writable_addrF16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt) -> Bool {
            return SkPixmap_readPixels(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes)
        }

        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer?, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool {
            return SkPixmap_readPixels_2(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes, Int32(srcX), Int32(srcY))
        }

        func readPixels(dst: SkPixmap, srcX: Int, srcY: Int) -> Bool {
            return SkPixmap_readPixels_3(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }

        func readPixels(dst: SkPixmap) -> Bool {
            return SkPixmap_readPixels_4(self.pointer, dst.pointer)
        }

        func scalePixels(dst: SkPixmap, options: SkSamplingOptions) -> Bool {
            return SkPixmap_scalePixels(self.pointer, dst.pointer, options.pointer)
        }

        func erase(color: SkColor, subset: SkIRect) -> Bool {
            return SkPixmap_erase(self.pointer, color.color, subset.pointer)
        }

        func erase(color: SkColor) -> Bool {
            return SkPixmap_erase_2(self.pointer, color.color)
        }

        func erase(color: SkColor4f, subset: SkIRect) -> Bool {
            return SkPixmap_erase_3(self.pointer, color.pointer, subset.pointer)
        }
    }
}