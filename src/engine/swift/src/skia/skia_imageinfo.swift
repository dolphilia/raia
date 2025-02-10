extension Skia {
    class ImageInfo {
        public var pointer: Skia.ImageInfoMutablePointer?
        public var handle: sk_image_info_t = -1

        // void SkImageInfo_delete(void *image_info); // (SkImageInfo *image_info)
        deinit {
            if self.handle > -1 {
                static_sk_image_info_delete(self.handle)
            } else {
                SkImageInfo_delete(self.pointer)
            }
        }

        // void *SkImageInfo_new(); // () -> SkImageInfo *
        init () {
            self.pointer = SkImageInfo_new()
            self.handle = -1
        }

        
        // int SkImageInfo_width(void *image_info); // (SkImageInfo *image_info) -> int
        func width() -> Int {
            return Int(SkImageInfo_width(self.pointer))
        }
        // int SkImageInfo_height(void *image_info); // (SkImageInfo *image_info) -> int
        func height() -> Int {
            return Int(SkImageInfo_height(self.pointer))
        }
        // int SkImageInfo_colorType(void *image_info); // (SkImageInfo *image_info) -> SkColorType
        func colorType() -> ColorType {
            return ColorType(rawValue: Int32(SkImageInfo_colorType(self.pointer)))!
        }
        // int SkImageInfo_alphaType(void *image_info); // (SkImageInfo *image_info) -> SkAlphaType
        func alphaType() -> AlphaType {
            return AlphaType(rawValue: Int32(SkImageInfo_alphaType(self.pointer)))!
        }
        // void *SkImageInfo_colorSpace(void *image_info); // (SkImageInfo *image_info) -> SkColorSpace *
        func colorSpace() -> ColorSpace {
            let pointer = SkImageInfo_colorSpace(self.pointer)
            return ColorSpace(pointer: pointer, handle: -1)
        }
        // int SkImageInfo_refColorSpace(void *image_info); // (SkImageInfo *image_info) -> sk_color_space_t
        func refColorSpace() -> ColorSpace {
            let handle = SkImageInfo_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // bool SkImageInfo_isEmpty(void *image_info); // (SkImageInfo *image_info) -> bool
        func isEmpty() -> Bool {
            return SkImageInfo_isEmpty(self.pointer)
        }
        // int SkImageInfo_colorInfo(void *image_info); // (SkImageInfo *image_info) -> sk_color_info_t
        func colorInfo() -> ColorInfo {
            let handle = SkImageInfo_colorInfo(self.pointer)
            let pointer = static_sk_color_info_get_ptr(handle)
            return ColorInfo(pointer: pointer, handle: handle)
        }
        // bool SkImageInfo_isOpaque(void *image_info); // (SkImageInfo *image_info) -> bool
        func isOpaque() -> Bool {
            return SkImageInfo_isOpaque(self.pointer)
        }
        // int SkImageInfo_dimensions(void *image_info); // (SkImageInfo *image_info) -> sk_i_size_t
        func dimensions() -> ISize {
            let handle = SkImageInfo_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_bounds(void *image_info); // (SkImageInfo *image_info) -> sk_i_rect_t
        func bounds() -> IRect {
            let handle = SkImageInfo_bounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // bool SkImageInfo_gammaCloseToSRGB(void *image_info); // (SkImageInfo *image_info) -> bool
        func gammaCloseToSRGB() -> Bool {
            return SkImageInfo_gammaCloseToSRGB(self.pointer)
        }
        // int SkImageInfo_makeWH(void *image_info, int newWidth, int newHeight); // (SkImageInfo *image_info, int newWidth, int newHeight) -> sk_image_info_t
        func makeWH(newWidth: Int, newHeight: Int) -> ImageInfo {
            let handle = SkImageInfo_makeWH(self.pointer, Int32(newWidth), Int32(newHeight))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_makeDimensions(void *image_info, int newSize); // (SkImageInfo *image_info, sk_i_size_t newSize) -> sk_image_info_t
        func makeDimensions(newSize: ISize) -> ImageInfo {
            let handle = SkImageInfo_makeDimensions(self.pointer, newSize.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_makeAlphaType(void *image_info, int newAlphaType); // (SkImageInfo *image_info, SkAlphaType newAlphaType) -> sk_image_info_t
        func makeAlphaType(newAlphaType: AlphaType) -> ImageInfo {
            let handle = SkImageInfo_makeAlphaType(self.pointer, Int32(newAlphaType.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_makeColorType(void *image_info, int newColorType); // (SkImageInfo *image_info, SkColorType newColorType) -> sk_image_info_t
        func makeColorType(newColorType: ColorType) -> ImageInfo {
            let handle = SkImageInfo_makeColorType(self.pointer, Int32(newColorType.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_makeColorSpace(void *image_info, int color_space); // (SkImageInfo *image_info, sk_color_space_t color_space) -> sk_image_info_t
        func makeColorSpace(colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_makeColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_bytesPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
        func bytesPerPixel() -> Int {
            return Int(SkImageInfo_bytesPerPixel(self.pointer))
        }
        // int SkImageInfo_shiftPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
        func shiftPerPixel() -> Int {
            return Int(SkImageInfo_shiftPerPixel(self.pointer))
        }
        // unsigned long long SkImageInfo_minRowBytes64(void *image_info); // (SkImageInfo *image_info) -> uint64_t
        func minRowBytes64() -> UInt64 {
            return SkImageInfo_minRowBytes64(self.pointer)
        }
        // unsigned long SkImageInfo_minRowBytes(void *image_info); // (SkImageInfo *image_info) -> size_t
        func minRowBytes() -> UInt {
            return SkImageInfo_minRowBytes(self.pointer)
        }
        // unsigned long SkImageInfo_computeOffset(void *image_info, int x, int y, unsigned long rowBytes); // (SkImageInfo *image_info, int x, int y, size_t rowBytes) -> size_t
        func computeOffset(x: Int, y: Int, rowBytes: UInt) -> UInt {
            return SkImageInfo_computeOffset(self.pointer, Int32(x), Int32(y), rowBytes)
        }
        // unsigned long SkImageInfo_computeByteSize(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> size_t
        func computeByteSize(rowBytes: UInt) -> UInt {
            return SkImageInfo_computeByteSize(self.pointer, rowBytes)
        }
        // unsigned long SkImageInfo_computeMinByteSize(void *image_info); // (SkImageInfo *image_info) -> size_t
        func computeMinByteSize() -> UInt {
            return SkImageInfo_computeMinByteSize(self.pointer)
        }
        // bool SkImageInfo_validRowBytes(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> bool
        func validRowBytes(rowBytes: UInt) -> Bool {
            return SkImageInfo_validRowBytes(self.pointer, rowBytes)
        }
        // void SkImageInfo_reset(void *image_info); // (SkImageInfo *image_info)
        func reset() {
            SkImageInfo_reset(self.pointer)
        }

        // // static

        init(pointer: Skia.ImageInfoMutablePointer?, handle: sk_image_info_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkImageInfo_Make(int width, int height, int ct, int at); // (int width, int height, SkColorType ct, SkAlphaType at) -> sk_image_info_t

        static func Make(width: Int, height: Int, ct: ColorType, at: AlphaType) -> ImageInfo {
            let handle = SkImageInfo_Make(Int32(width), Int32(height), Int32(ct.rawValue), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_Make_2(int width, int height, int ct, int at, int color_space); // (int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t

        static func Make(width: Int, height: Int, ct: ColorType, at: AlphaType, colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_Make_2(Int32(width), Int32(height), Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_Make_3(int dimensions, int ct, int at); // (sk_i_size_t dimensions, SkColorType ct, SkAlphaType at) -> sk_image_info_t

        static func Make(dimensions: ISize, ct: ColorType, at: AlphaType) -> ImageInfo {
            let handle = SkImageInfo_Make_3(dimensions.handle, Int32(ct.rawValue), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_Make_4(int dimensions, int ct, int at, int color_space); // (sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t

        static func Make(dimensions: ISize, ct: ColorType, at: AlphaType, colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_Make_4(dimensions.handle, Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_Make_5(int dimensions, const void *colorInfo); // (sk_i_size_t dimensions, const SkColorInfo *colorInfo) -> sk_image_info_t

        static func Make(dimensions: ISize, colorInfo: ColorInfo) -> ImageInfo {
            let handle = SkImageInfo_Make_5(dimensions.handle, colorInfo.pointer);
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32(int width, int height, int at); // (int width, int height, SkAlphaType at) -> sk_image_info_t

        static func MakeN32(width: Int, height: Int, at: AlphaType) -> ImageInfo {
            let handle = SkImageInfo_MakeN32(Int32(width), Int32(height), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32_2(int width, int height, int at, int color_space); // (int width, int height, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeN32(width: Int, height: Int, at: AlphaType, colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_MakeN32_2(Int32(width), Int32(height), Int32(at.rawValue), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeS32(int width, int height, int at); // (int width, int height, SkAlphaType at) -> sk_image_info_t
        static func MakeS32(width: Int, height: Int, at: AlphaType) -> ImageInfo {
            let handle = SkImageInfo_MakeS32(Int32(width), Int32(height), Int32(at.rawValue))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32Premul(int width, int height); // (int width, int height) -> sk_image_info_t
        static func MakeN32Premul(width: Int, height: Int) -> ImageInfo {
            let handle = SkImageInfo_MakeN32Premul(Int32(width), Int32(height))
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32Premul_2(int width, int height, int color_space); // (int width, int height, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeN32Premul(width: Int, height: Int, colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_MakeN32Premul_2(Int32(width), Int32(height), colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32Premul_3(int dimensions); // (sk_i_size_t dimensions) -> sk_image_info_t
        static func MakeN32Premul(dimensions: ISize) -> ImageInfo {
            let handle = SkImageInfo_MakeN32Premul_3(dimensions.handle);
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeN32Premul_4(int dimensions, int color_space); // (sk_i_size_t dimensions, sk_color_space_t color_space) -> sk_image_info_t
        static func MakeN32Premul(dimensions: ISize, colorSpace: ColorSpace) -> ImageInfo {
            let handle = SkImageInfo_MakeN32Premul_4(dimensions.handle, colorSpace.handle)
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeA8(int width, int height); // (int width, int height) -> sk_image_info_t
        static func MakeA8(width: Int, height: Int) -> ImageInfo {
            let handle = SkImageInfo_MakeA8(Int32(width), Int32(height));
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeA8_2(int dimensions); // (sk_i_size_t dimensions) -> sk_image_info_t
        static func MakeA8(dimensions: ISize) -> ImageInfo {
            let handle = SkImageInfo_MakeA8_2(dimensions.handle);
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeUnknown(int width, int height); // (int width, int height) -> sk_image_info_t
        static func MakeUnknown(width: Int, height: Int) -> ImageInfo {
            let handle = SkImageInfo_MakeUnknown(Int32(width), Int32(height));
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // int SkImageInfo_MakeUnknown_2(); // () -> sk_image_info_t
        static func MakeUnknown() -> ImageInfo {
            let handle = SkImageInfo_MakeUnknown_2();
            let pointer = static_sk_image_info_get_ptr(handle)
            return ImageInfo(pointer: pointer, handle: handle)
        }
        // bool SkImageInfo_ByteSizeOverflowed(unsigned long byteSize); // (size_t byteSize) -> bool
        static func ByteSizeOverflowed(byteSize: UInt) -> Bool {
            return SkImageInfo_ByteSizeOverflowed(byteSize)
        }

    }
}