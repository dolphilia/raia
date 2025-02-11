extension Skia {
    protocol SkImageInfoProtocol {
        var pointer: SkImageInfoMutablePointer? { get set }
        var handle: sk_image_info_t { get set }
        // deinit // void SkImageInfo_delete(void *image_info); // (SkImageInfo *image_info)
        init(pointer: SkImageInfoMutablePointer?, handle: sk_image_info_t)
        init() // void *SkImageInfo_new(); // () -> SkImageInfo *
        // Static Methods
        static func Make(width: Int, height: Int, ct: SkColorType, at: SkAlphaType) -> SkImageInfo // int SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at) -> sk_image_info_t
        static func Make(width: Int, height: Int, ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_Make_2(int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
        static func Make(dimensions: SkISize, ct: SkColorType, at: SkAlphaType) -> SkImageInfo // int SkImageInfo_Make_3(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at) -> sk_image_info_t
        static func Make(dimensions: SkISize, ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_Make_4(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
        static func Make(dimensions: SkISize, colorInfo: SkColorInfo) -> SkImageInfo // int SkImageInfo_Make_5(sk_i_size_t dimensions, const SkColorInfo *colorInfo) -> sk_image_info_t
        static func MakeN32(width: Int, height: Int, at: SkAlphaType) -> SkImageInfo // int SkImageInfo_MakeN32(int width, int height, SkAlphaType at) -> sk_image_info_t
        static func MakeN32(width: Int, height: Int, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_MakeN32_2(int width, int height, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeS32(width: Int, height: Int, at: SkAlphaType) -> SkImageInfo // int SkImageInfo_MakeS32(int width, int height, SkAlphaType at) -> sk_image_info_t
        static func MakeN32Premul(width: Int, height: Int) -> SkImageInfo // int SkImageInfo_MakeN32Premul(int width, int height) -> sk_image_info_t
        static func MakeN32Premul(width: Int, height: Int, colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_MakeN32Premul_2(int width, int height, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeN32Premul(dimensions: SkISize) -> SkImageInfo // int SkImageInfo_MakeN32Premul_3(sk_i_size_t dimensions) -> sk_image_info_t
        static func MakeN32Premul(dimensions: SkISize, colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_MakeN32Premul_4(sk_i_size_t dimensions, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeA8(width: Int, height: Int) -> SkImageInfo // int SkImageInfo_MakeA8(int width, int height) -> sk_image_info_t
        static func MakeA8(dimensions: SkISize) -> SkImageInfo // int SkImageInfo_MakeA8_2(sk_i_size_t dimensions) -> sk_image_info_t
        static func MakeUnknown(width: Int, height: Int) -> SkImageInfo // int SkImageInfo_MakeUnknown(int width, int height) -> sk_image_info_t
        static func MakeUnknown() -> SkImageInfo // int SkImageInfo_MakeUnknown_2(); // () -> sk_image_info_t
        static func ByteSizeOverflowed(byteSize: UInt) -> Bool // bool SkImageInfo_ByteSizeOverflowed(size_t byteSize) -> bool
        // Methods
        func width() -> Int // int SkImageInfo_width(void *image_info); // (SkImageInfo *image_info) -> int
        func height() -> Int // int SkImageInfo_height(void *image_info); // (SkImageInfo *image_info) -> int
        func colorType() -> SkColorType // int SkImageInfo_colorType(void *image_info); // (SkImageInfo *image_info) -> SkColorType
        func alphaType() -> SkAlphaType // int SkImageInfo_alphaType(void *image_info); // (SkImageInfo *image_info) -> SkAlphaType
        func colorSpace() -> SkColorSpace // void *SkImageInfo_colorSpace(void *image_info); // (SkImageInfo *image_info) -> SkColorSpace *
        func refColorSpace() -> SkColorSpace // int SkImageInfo_refColorSpace(void *image_info); // (SkImageInfo *image_info) -> sk_color_space_t
        func isEmpty() -> Bool // bool SkImageInfo_isEmpty(void *image_info); // (SkImageInfo *image_info) -> bool
        func colorInfo() -> SkColorInfo // int SkImageInfo_colorInfo(void *image_info); // (SkImageInfo *image_info) -> sk_color_info_t
        func isOpaque() -> Bool // bool SkImageInfo_isOpaque(void *image_info); // (SkImageInfo *image_info) -> bool
        func dimensions() -> SkISize // int SkImageInfo_dimensions(void *image_info); // (SkImageInfo *image_info) -> sk_i_size_t
        func bounds() -> SkIRect // int SkImageInfo_bounds(void *image_info); // (SkImageInfo *image_info) -> sk_i_rect_t
        func gammaCloseToSRGB() -> Bool // bool SkImageInfo_gammaCloseToSRGB(void *image_info); // (SkImageInfo *image_info) -> bool
        func makeWH(newWidth: Int, newHeight: Int) -> SkImageInfo // int SkImageInfo_makeWH(void *image_info, int newWidth, int newHeight); // (SkImageInfo *image_info, int newWidth, int newHeight) -> sk_image_info_t
        func makeDimensions(newSize: SkISize) -> SkImageInfo // int SkImageInfo_makeDimensions(void *image_info, int newSize); // (SkImageInfo *image_info, sk_i_size_t newSize) -> sk_image_info_t
        func makeAlphaType(newAlphaType: SkAlphaType) -> SkImageInfo // int SkImageInfo_makeAlphaType(void *image_info, int newAlphaType); // (SkImageInfo *image_info, SkAlphaType newAlphaType) -> sk_image_info_t
        func makeColorType(newColorType: SkColorType) -> SkImageInfo // int SkImageInfo_makeColorType(void *image_info, int newColorType); // (SkImageInfo *image_info, SkColorType newColorType) -> sk_image_info_t
        func makeColorSpace(colorSpace: SkColorSpace) -> SkImageInfo // int SkImageInfo_makeColorSpace(void *image_info, int color_space); // (SkImageInfo *image_info, sk_color_space_t color_space) -> sk_image_info_t
        func bytesPerPixel() -> Int // int SkImageInfo_bytesPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
        func shiftPerPixel() -> Int // int SkImageInfo_shiftPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
        func minRowBytes64() -> UInt64 // unsigned long long SkImageInfo_minRowBytes64(void *image_info); // (SkImageInfo *image_info) -> uint64_t
        func minRowBytes() -> UInt // unsigned long SkImageInfo_minRowBytes(void *image_info); // (SkImageInfo *image_info) -> size_t
        func computeOffset(x: Int, y: Int, rowBytes: UInt) -> UInt // unsigned long SkImageInfo_computeOffset(void *image_info, int x, int y, unsigned long rowBytes); // (SkImageInfo *image_info, int x, int y, size_t rowBytes) -> size_t
        func computeByteSize(rowBytes: UInt) -> UInt // unsigned long SkImageInfo_computeByteSize(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> size_t
        func computeMinByteSize() -> UInt // unsigned long SkImageInfo_computeMinByteSize(void *image_info); // (SkImageInfo *image_info) -> size_t
        func validRowBytes(rowBytes: UInt) -> Bool // bool SkImageInfo_validRowBytes(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> bool
        func reset() // void SkImageInfo_reset(void *image_info); // (SkImageInfo *image_info)
    }

    class SkImageInfo : SkImageInfoProtocol {
        public var pointer: SkImageInfoMutablePointer?
        public var handle: sk_image_info_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_image_info_delete(self.handle)
            } else {
                SkImageInfo_delete(self.pointer)
            }
        }

        required init(pointer: SkImageInfoMutablePointer?, handle: sk_image_info_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkImageInfo_new()
            self.handle = -1
        }

        // Static Methods

        static func Make(width: Int, height: Int, ct: SkColorType, at: SkAlphaType) -> SkImageInfo {
            let handle = SkImageInfo_Make(Int32(width), Int32(height), Int32(ct.rawValue), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func Make(width: Int, height: Int, ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_Make_2(Int32(width), Int32(height), Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func Make(dimensions: SkISize, ct: SkColorType, at: SkAlphaType) -> SkImageInfo {
            let handle = SkImageInfo_Make_3(dimensions.handle, Int32(ct.rawValue), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func Make(dimensions: SkISize, ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_Make_4(dimensions.handle, Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func Make(dimensions: SkISize, colorInfo: SkColorInfo) -> SkImageInfo {
            let handle = SkImageInfo_Make_5(dimensions.handle, colorInfo.pointer);
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32(width: Int, height: Int, at: SkAlphaType) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32(Int32(width), Int32(height), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32(width: Int, height: Int, at: SkAlphaType, colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32_2(Int32(width), Int32(height), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeS32(width: Int, height: Int, at: SkAlphaType) -> SkImageInfo {
            let handle = SkImageInfo_MakeS32(Int32(width), Int32(height), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32Premul(width: Int, height: Int) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32Premul(Int32(width), Int32(height))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32Premul(width: Int, height: Int, colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32Premul_2(Int32(width), Int32(height), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32Premul(dimensions: SkISize) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32Premul_3(dimensions.handle);
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeN32Premul(dimensions: SkISize, colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_MakeN32Premul_4(dimensions.handle, colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeA8(width: Int, height: Int) -> SkImageInfo {
            let handle = SkImageInfo_MakeA8(Int32(width), Int32(height));
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeA8(dimensions: SkISize) -> SkImageInfo {
            let handle = SkImageInfo_MakeA8_2(dimensions.handle);
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeUnknown(width: Int, height: Int) -> SkImageInfo {
            let handle = SkImageInfo_MakeUnknown(Int32(width), Int32(height));
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func MakeUnknown() -> SkImageInfo {
            let handle = SkImageInfo_MakeUnknown_2();
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        static func ByteSizeOverflowed(byteSize: UInt) -> Bool {
            return SkImageInfo_ByteSizeOverflowed(byteSize)
        }

        // Methods

        func width() -> Int {
            return Int(SkImageInfo_width(self.pointer))
        }

        func height() -> Int {
            return Int(SkImageInfo_height(self.pointer))
        }

        func colorType() -> SkColorType {
            return SkColorType(rawValue: Int32(SkImageInfo_colorType(self.pointer)))!
        }

        func alphaType() -> SkAlphaType {
            return SkAlphaType(rawValue: Int32(SkImageInfo_alphaType(self.pointer)))!
        }

        func colorSpace() -> SkColorSpace {
            let pointer = SkImageInfo_colorSpace(self.pointer)
            return SkColorSpace(pointer: pointer, handle: -1)
        }

        func refColorSpace() -> SkColorSpace {
            let handle = SkImageInfo_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func isEmpty() -> Bool {
            return SkImageInfo_isEmpty(self.pointer)
        }

        func colorInfo() -> SkColorInfo {
            let handle = SkImageInfo_colorInfo(self.pointer)
            let pointer = static_sk_color_info_get_ptr(handle)
            return SkColorInfo(pointer: pointer, handle: handle)
        }

        func isOpaque() -> Bool {
            return SkImageInfo_isOpaque(self.pointer)
        }

        func dimensions() -> SkISize {
            let handle = SkImageInfo_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        func bounds() -> SkIRect {
            let handle = SkImageInfo_bounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        func gammaCloseToSRGB() -> Bool {
            return SkImageInfo_gammaCloseToSRGB(self.pointer)
        }

        func makeWH(newWidth: Int, newHeight: Int) -> SkImageInfo {
            let handle = SkImageInfo_makeWH(self.pointer, Int32(newWidth), Int32(newHeight))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func makeDimensions(newSize: SkISize) -> SkImageInfo {
            let handle = SkImageInfo_makeDimensions(self.pointer, newSize.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func makeAlphaType(newAlphaType: SkAlphaType) -> SkImageInfo {
            let handle = SkImageInfo_makeAlphaType(self.pointer, Int32(newAlphaType.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func makeColorType(newColorType: SkColorType) -> SkImageInfo {
            let handle = SkImageInfo_makeColorType(self.pointer, Int32(newColorType.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func makeColorSpace(colorSpace: SkColorSpace) -> SkImageInfo {
            let handle = SkImageInfo_makeColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }

        func bytesPerPixel() -> Int {
            return Int(SkImageInfo_bytesPerPixel(self.pointer))
        }

        func shiftPerPixel() -> Int {
            return Int(SkImageInfo_shiftPerPixel(self.pointer))
        }

        func minRowBytes64() -> UInt64 {
            return SkImageInfo_minRowBytes64(self.pointer)
        }

        func minRowBytes() -> UInt {
            return SkImageInfo_minRowBytes(self.pointer)
        }

        func computeOffset(x: Int, y: Int, rowBytes: UInt) -> UInt {
            return SkImageInfo_computeOffset(self.pointer, Int32(x), Int32(y), rowBytes)
        }

        func computeByteSize(rowBytes: UInt) -> UInt {
            return SkImageInfo_computeByteSize(self.pointer, rowBytes)
        }

        func computeMinByteSize() -> UInt {
            return SkImageInfo_computeMinByteSize(self.pointer)
        }

        func validRowBytes(rowBytes: UInt) -> Bool {
            return SkImageInfo_validRowBytes(self.pointer, rowBytes)
        }

        func reset() {
            SkImageInfo_reset(self.pointer)
        }
    }
}