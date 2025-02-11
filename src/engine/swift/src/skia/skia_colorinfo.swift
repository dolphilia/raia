extension Skia {
    protocol SkColorInfoProtocol {
        var pointer: SkColorInfoMutablePointer? { get set }
        var handle: sk_color_info_t { get set }
        // deinit // void SkColorInfo_delete(void *color_info); // (SkColorInfo *color_info)
        init(pointer: SkColorInfoMutablePointer?, handle: sk_color_info_t)
        init() // void *SkColorInfo_new(); // () -> SkColorInfo *
        init(ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) // void *SkColorInfo_new_2(int ct, int at, int color_space); // (SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> SkColorInfo *
        init(colorInfo: SkColorInfo) // void *SkColorInfo_new_3(const void *color_info); // (const SkColorInfo *color_info) -> SkColorInfo *
        // Methods
        func alphaType() -> SkAlphaType // int SkColorInfo_alphaType(void *color_info); // (SkColorInfo *color_info) -> SkAlphaType
        func bytesPerPixel() -> Int // int SkColorInfo_bytesPerPixel(void *color_info); // (SkColorInfo *color_info) -> int
        func colorSpace() -> SkColorSpace // void* SkColorInfo_colorSpace(void *color_info); // (SkColorInfo *color_info) -> SkColorSpace*
        func colorType() -> SkColorType // int SkColorInfo_colorType(void *color_info); // (SkColorInfo *color_info) -> SkColorType
        func gammaCloseToSRGB() -> Bool // bool SkColorInfo_gammaCloseToSRGB(void *color_info); // (SkColorInfo *color_info) -> bool
        func isOpaque() -> Bool // bool SkColorInfo_isOpaque(void *color_info); // (SkColorInfo *color_info) -> bool
        func makeAlphaType(newAlphaType: SkAlphaType) -> SkColorInfo // int SkColorInfo_makeAlphaType(void *color_info, int newAlphaType); // (SkColorInfo *color_info, SkAlphaType newAlphaType) -> sk_color_info_t
        func makeColorSpace(colorSpace: SkColorSpace) -> SkColorInfo // int SkColorInfo_makeColorSpace(void *color_info, int color_space); // (SkColorInfo *color_info, sk_color_space_t color_space) -> sk_color_info_t
        func makeColorType(newColorType: SkColorType) -> SkColorInfo // int SkColorInfo_makeColorType(void *color_info, int newColorType); // (SkColorInfo *color_info, SkColorType newColorType) -> sk_color_info_t
        func refColorSpace() -> SkColorSpace // int SkColorInfo_refColorSpace(void *color_info); // (SkColorInfo *color_info) -> sk_color_space_t
        func shiftPerPixel() -> Int // int SkColorInfo_shiftPerPixel(void *color_info); // (SkColorInfo *color_info) -> int
    }

    class SkColorInfo : SkColorInfoProtocol {
        public var pointer: SkColorInfoMutablePointer?
        public var handle: sk_color_info_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_color_info_delete(self.handle)
            } else {
                SkColorInfo_delete(self.pointer)
            }
        }

        required init(pointer: SkColorInfoMutablePointer?, handle: sk_color_info_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkColorInfo_new()
            self.handle = -1
        }

        required init(ct: SkColorType, at: SkAlphaType, colorSpace: SkColorSpace) {
            self.pointer = SkColorInfo_new_2(Int32(ct.rawValue), Int32(at.rawValue), colorSpace.handle)
            self.handle = -1
        }

        required init(colorInfo: SkColorInfo) {
            self.pointer = SkColorInfo_new_3(colorInfo.pointer)
            self.handle = -1
        }

        func alphaType() -> SkAlphaType {
            return SkAlphaType(rawValue: Int32(SkColorInfo_alphaType(self.pointer)))!
        }

        func bytesPerPixel() -> Int {
            return Int(SkColorInfo_bytesPerPixel(self.pointer))
        }

        func colorSpace() -> SkColorSpace {
            let pointer = SkColorInfo_colorSpace(self.pointer)
            return SkColorSpace(pointer: pointer, handle: -1)
        }

        func colorType() -> SkColorType {
            return SkColorType(rawValue: Int32(SkColorInfo_colorType(self.pointer)))!
        }

        func gammaCloseToSRGB() -> Bool {
            return SkColorInfo_gammaCloseToSRGB(self.pointer)
        }

        func isOpaque() -> Bool {
            return SkColorInfo_isOpaque(self.pointer)
        }

        func makeAlphaType(newAlphaType: SkAlphaType) -> SkColorInfo {
            let handle = SkColorInfo_makeAlphaType(self.pointer, Int32(newAlphaType.rawValue))
            let pointer = static_sk_color_info_get_ptr(handle)
            return SkColorInfo(pointer: pointer, handle: handle)
        }

        func makeColorSpace(colorSpace: SkColorSpace) -> SkColorInfo {
            let handle = SkColorInfo_makeColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_color_info_get_ptr(handle)
            return SkColorInfo(pointer: pointer, handle: handle)
        }

        func makeColorType(newColorType: SkColorType) -> SkColorInfo {
            let handle = SkColorInfo_makeColorType(self.pointer, Int32(newColorType.rawValue))
            let pointer = static_sk_color_info_get_ptr(handle)
            return SkColorInfo(pointer: pointer, handle: handle)
        }

        func refColorSpace() -> SkColorSpace {
            let handle = SkColorInfo_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func shiftPerPixel() -> Int {
            return Int(SkColorInfo_shiftPerPixel(self.pointer))
        }
    }
}