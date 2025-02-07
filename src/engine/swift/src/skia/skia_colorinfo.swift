extension Skia {
    class ColorInfo {
        public var pointer: Skia.ColorInfoMutablePointer?
        public var handle: sk_color_info_t = -1

        // void *SkColorInfo_new(); // () -> SkColorInfo *
        init() {
            self.pointer = SkColorInfo_new()
            self.handle = -1
        }
        // void *SkColorInfo_new_2(int ct, int at, int color_space); // (SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> SkColorInfo *
        init(ct: ColorType, at: AlphaType, colorSpace: ColorSpace) {
            self.pointer = SkColorInfo_new_2(Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            self.handle = -1
        }
        // void *SkColorInfo_new_3(const void *color_info); // (const SkColorInfo *color_info) -> SkColorInfo *
        init(colorInfo: ColorInfo) {
            self.pointer = SkColorInfo_new_3(colorInfo.pointer)
            self.handle = -1
        }
        // void SkColorInfo_delete(void *color_info); // (SkColorInfo *color_info)
        deinit {
            SkColorInfo_delete(self.pointer)
            if handle > -1 {
                static_sk_color_info_delete(handle)
            }
        }
        // int SkColorInfo_alphaType(void *color_info); // (SkColorInfo *color_info) -> SkAlphaType
        func alphaType() -> AlphaType {
            return AlphaType(rawValue: Int32(SkColorInfo_alphaType(self.pointer)))!
        }
        // int SkColorInfo_bytesPerPixel(void *color_info); // (SkColorInfo *color_info) -> int
        func bytesPerPixel() -> Int {
            return Int(SkColorInfo_bytesPerPixel(self.pointer))
        }
        // void* SkColorInfo_colorSpace(void *color_info); // (SkColorInfo *color_info) -> SkColorSpace*
        func colorSpace() -> ColorSpace {
            let pointer = SkColorInfo_colorSpace(self.pointer)
            return ColorSpace(pointer: pointer, handle: -1)
        }
        // int SkColorInfo_colorType(void *color_info); // (SkColorInfo *color_info) -> SkColorType
        func colorType() -> ColorType {
            return ColorType(rawValue: Int32(SkColorInfo_colorType(self.pointer)))!
        }
        // bool SkColorInfo_gammaCloseToSRGB(void *color_info); // (SkColorInfo *color_info) -> bool
        func gammaCloseToSRGB() -> Bool {
            return SkColorInfo_gammaCloseToSRGB(self.pointer)
        }
        // bool SkColorInfo_isOpaque(void *color_info); // (SkColorInfo *color_info) -> bool
        func isOpaque() -> Bool {
            return SkColorInfo_isOpaque(self.pointer)
        }
        // int SkColorInfo_makeAlphaType(void *color_info, int newAlphaType); // (SkColorInfo *color_info, SkAlphaType newAlphaType) -> sk_color_info_t
        func makeAlphaType(newAlphaType: AlphaType) -> ColorInfo {
            let handle = SkColorInfo_makeAlphaType(self.pointer, Int32(newAlphaType.rawValue))
            let pointer = static_sk_color_info_get_ptr(handle)
            return ColorInfo(pointer: pointer, handle: handle)
        }
        // int SkColorInfo_makeColorSpace(void *color_info, int color_space); // (SkColorInfo *color_info, sk_color_space_t color_space) -> sk_color_info_t
        func makeColorSpace(colorSpace: ColorSpace) -> ColorInfo {
            let handle = SkColorInfo_makeColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_color_info_get_ptr(handle)
            return ColorInfo(pointer: pointer, handle: handle)
        }
        // int SkColorInfo_makeColorType(void *color_info, int newColorType); // (SkColorInfo *color_info, SkColorType newColorType) -> sk_color_info_t
        func makeColorType(newColorType: ColorType) -> ColorInfo {
            let handle = SkColorInfo_makeColorType(self.pointer, Int32(newColorType.rawValue))
            let pointer = static_sk_color_info_get_ptr(handle)
            return ColorInfo(pointer: pointer, handle: handle)
        }
        // int SkColorInfo_refColorSpace(void *color_info); // (SkColorInfo *color_info) -> sk_color_space_t
        func refColorSpace() -> ColorSpace {
            let handle = SkColorInfo_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // int SkColorInfo_shiftPerPixel(void *color_info); // (SkColorInfo *color_info) -> int
        func shiftPerPixel() -> Int {
            return Int(SkColorInfo_shiftPerPixel(self.pointer))
        }

        // static

        init(pointer: Skia.ColorInfoMutablePointer?, handle: sk_color_info_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}