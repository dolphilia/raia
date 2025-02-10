extension Skia {
    class ColorSpace {
        public var pointer: Skia.ColorSpaceMutablePointer?
        public var handle: sk_color_space_t = -1
        // void SkColorSpace_delete(void *color_space); // (SkColorSpace *color_space)
        deinit {
            if handle > -1 {
                static_sk_color_space_delete(handle)
            } else {
                SkColorSpace_delete(self.pointer)
            }
        }

        // void SkColorSpace_toProfile(void *color_space, void *profile); // (SkColorSpace *color_space, skcms_ICCProfile *profile)
        // bool SkColorSpace_gammaCloseToSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
        func gammaCloseToSRGB() -> Bool {
            return SkColorSpace_gammaCloseToSRGB(self.pointer)
        }
        // bool SkColorSpace_gammaIsLinear(void *color_space); // (SkColorSpace *color_space) -> bool
        func gammaIsLinear() -> Bool {
            return SkColorSpace_gammaIsLinear(self.pointer)
        }
        // bool SkColorSpace_isNumericalTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn) -> bool
        // bool SkColorSpace_toXYZD50(void *color_space, void *toXYZD50); // (SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) -> bool
        // unsigned int SkColorSpace_toXYZD50Hash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
        func toXYZD50Hash() -> UInt32 {
            return SkColorSpace_toXYZD50Hash(self.pointer)
        }
        // int SkColorSpace_makeLinearGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func makeLinearGamma() -> ColorSpace {
            let handle = SkColorSpace_makeLinearGamma(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // int SkColorSpace_makeSRGBGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func makeSRGBGamma() -> ColorSpace {
            let handle = SkColorSpace_makeSRGBGamma(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // int SkColorSpace_makeColorSpin(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func makeColorSpin() -> ColorSpace {
            let handle = SkColorSpace_makeColorSpin(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // bool SkColorSpace_isSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
        func isSRGB() -> Bool {
            return SkColorSpace_isSRGB(self.pointer)
        }
        // int SkColorSpace_serialize(void *color_space); // (SkColorSpace *color_space) -> sk_data_t
        func serialize() -> Data {
            let handle = SkColorSpace_serialize(self.pointer);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // unsigned long SkColorSpace_writeToMemory(void *color_space, void *memory); // (SkColorSpace *color_space, void *memory) -> size_t
        func writeToMemory(memory: UnsafeMutableRawPointer?) -> UInt {
            return SkColorSpace_writeToMemory(self.pointer, memory)
        }
        // void SkColorSpace_transferFn(void *color_space, float gabcdef[7]); // (SkColorSpace *color_space, float gabcdef[7])
        func transferFn() -> [Float] {
            var gabcdef: [Float] = [0, 0, 0, 0, 0, 0, 0]
            SkColorSpace_transferFn(self.pointer, &gabcdef)
            return gabcdef
        }
        // void SkColorSpace_transferFn_2(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_invTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_gamutTransformTo(void *color_space, const void *dst, void *src_to_dst); // (SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst)
        // unsigned int SkColorSpace_transferFnHash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
        func transferFnHash() -> UInt32 {
            return SkColorSpace_transferFnHash(self.pointer)
        }
        // unsigned long long SkColorSpace_hash(void *color_space); // (SkColorSpace *color_space) -> uint64_t
        func hash() -> UInt64 {
            return SkColorSpace_hash(self.pointer)
        }
        // bool SkColorSpace_unique(void *color_space); // (SkColorSpace *color_space) -> bool
        func unique() -> Bool {
            return SkColorSpace_unique(self.pointer)
        }
        // void SkColorSpace_ref(void *color_space); // (SkColorSpace *color_space)
        func ref() {
            SkColorSpace_ref(self.pointer)
        }
        // void SkColorSpace_unref(void *color_space); // (SkColorSpace *color_space)
        func unref() {
            SkColorSpace_unref(self.pointer)
        }
        // void SkColorSpace_deref(void *color_space); // (SkColorSpace *color_space)
        func deref() {
            SkColorSpace_deref(self.pointer)
        }
        // bool SkColorSpace_refCntGreaterThan(void *color_space, int threadIsolatedTestCnt); // (SkColorSpace *color_space, int32_t threadIsolatedTestCnt) -> bool
        func refCntGreaterThan(threadIsolatedTestCnt: Int) -> Bool {
            return SkColorSpace_refCntGreaterThan(self.pointer, Int32(threadIsolatedTestCnt))
        }

        // // static

        init(pointer: Skia.ColorSpaceMutablePointer?, handle: sk_color_space_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkColorSpace_MakeSRGB(); // () -> sk_color_space_t
        static func MakeSRGB() -> ColorSpace {
            let handle = SkColorSpace_MakeSRGB();
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // int SkColorSpace_MakeSRGBLinear(); // () -> sk_color_space_t
        static func MakeSRGBLinear() -> ColorSpace {
            let handle = SkColorSpace_MakeSRGBLinear();
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }

        // int SkColorSpace_MakeRGB(const void *transferFn, const void *toXYZ); // (const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) -> sk_color_space_t
        // int SkColorSpace_Make(const void * profile); // (const skcms_ICCProfile *profile) -> sk_color_space_t

        // int SkColorSpace_Deserialize(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_color_space_t
        static func Deserialize(data: UnsafeRawPointer, length: UInt) -> ColorSpace {
            let handle = SkColorSpace_Deserialize(data, length);
            let pointer = static_sk_color_space_get(handle)
            return ColorSpace(pointer: pointer, handle: handle)
        }
        // bool SkColorSpace_Equals(void *color_space_1, const void *color_space_2); // (SkColorSpace *color_space_1, const SkColorSpace *color_space_2) -> bool
        static func Equals(x: ColorSpace, y: ColorSpace) -> Bool {
            return SkColorSpace_Equals(x.pointer, y.pointer)
        }

    }
}