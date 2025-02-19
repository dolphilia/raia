extension Skia {
    protocol SkColorSpaceProtocol {
        var pointer: SkColorSpaceMutablePointer? { get set }
        var handle: sk_color_space_t { get set }
        // deinit // void SkColorSpace_delete(void *color_space); // (SkColorSpace *color_space)
        init(pointer: SkColorSpaceMutablePointer?, handle: sk_color_space_t)
        static func MakeSRGB() -> SkColorSpace // int SkColorSpace_MakeSRGB(); // () -> sk_color_space_t
        static func MakeSRGBLinear() -> SkColorSpace // int SkColorSpace_MakeSRGBLinear(); // () -> sk_color_space_t
        // int SkColorSpace_MakeRGB(const void *transferFn, const void *toXYZ); // (const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) -> sk_color_space_t
        // int SkColorSpace_Make(const void * profile); // (const skcms_ICCProfile *profile) -> sk_color_space_t
        static func Deserialize(data: UnsafeRawPointer, length: UInt) -> SkColorSpace // int SkColorSpace_Deserialize(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_color_space_t
        static func Equals(x: SkColorSpace, y: SkColorSpace) -> Bool // bool SkColorSpace_Equals(void *color_space_1, const void *color_space_2); // (SkColorSpace *color_space_1, const SkColorSpace *color_space_2) -> bool
        // void SkColorSpace_toProfile(void *color_space, void *profile); // (SkColorSpace *color_space, skcms_ICCProfile *profile)
        func gammaCloseToSRGB() -> Bool // bool SkColorSpace_gammaCloseToSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
        func gammaIsLinear() -> Bool // bool SkColorSpace_gammaIsLinear(void *color_space); // (SkColorSpace *color_space) -> bool
        // bool SkColorSpace_isNumericalTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn) -> bool
        // bool SkColorSpace_toXYZD50(void *color_space, void *toXYZD50); // (SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) -> bool
        func toXYZD50Hash() -> UInt32 // unsigned int SkColorSpace_toXYZD50Hash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
        func makeLinearGamma() -> SkColorSpace // int SkColorSpace_makeLinearGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func makeSRGBGamma() -> SkColorSpace // int SkColorSpace_makeSRGBGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func makeColorSpin() -> SkColorSpace // int SkColorSpace_makeColorSpin(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
        func isSRGB() -> Bool // bool SkColorSpace_isSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
        func serialize() -> SkData // int SkColorSpace_serialize(void *color_space); // (SkColorSpace *color_space) -> sk_data_t
        func writeToMemory(memory: UnsafeMutableRawPointer?) -> UInt // unsigned long SkColorSpace_writeToMemory(void *color_space, void *memory); // (SkColorSpace *color_space, void *memory) -> size_t
        func transferFn() -> [Float] // void SkColorSpace_transferFn(void *color_space, float gabcdef[7]); // (SkColorSpace *color_space, float gabcdef[7])
        // void SkColorSpace_transferFn_2(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_invTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_gamutTransformTo(void *color_space, const void *dst, void *src_to_dst); // (SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst)
        func transferFnHash() -> UInt32 // unsigned int SkColorSpace_transferFnHash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
        func hash() -> UInt64 // unsigned long long SkColorSpace_hash(void *color_space); // (SkColorSpace *color_space) -> uint64_t
        func unique() -> Bool // bool SkColorSpace_unique(void *color_space); // (SkColorSpace *color_space) -> bool
        func ref() // void SkColorSpace_ref(void *color_space); // (SkColorSpace *color_space)
        func unref() // void SkColorSpace_unref(void *color_space); // (SkColorSpace *color_space)
        func deref() // void SkColorSpace_deref(void *color_space); // (SkColorSpace *color_space)
        func refCntGreaterThan(threadIsolatedTestCnt: Int) -> Bool // bool SkColorSpace_refCntGreaterThan(void *color_space, int threadIsolatedTestCnt); // (SkColorSpace *color_space, int32_t threadIsolatedTestCnt) -> bool
    }

    class SkColorSpace: SkColorSpaceProtocol {
        public var pointer: SkColorSpaceMutablePointer?
        public var handle: sk_color_space_t = -1

        deinit {
            if handle > -1 {
                static_sk_color_space_delete(handle)
            } else {
                SkColorSpace_delete(self.pointer)
            }
        }

        required init(pointer: SkColorSpaceMutablePointer?, handle: sk_color_space_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeSRGB() -> SkColorSpace {
            let handle = SkColorSpace_MakeSRGB();
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        static func MakeSRGBLinear() -> SkColorSpace {
            let handle = SkColorSpace_MakeSRGBLinear();
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        // int SkColorSpace_MakeRGB(const void *transferFn, const void *toXYZ); // (const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) -> sk_color_space_t
        // int SkColorSpace_Make(const void * profile); // (const skcms_ICCProfile *profile) -> sk_color_space_t

        static func Deserialize(data: UnsafeRawPointer, length: UInt) -> SkColorSpace {
            let handle = SkColorSpace_Deserialize(data, length);
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        static func Equals(x: SkColorSpace, y: SkColorSpace) -> Bool {
            return SkColorSpace_Equals(x.pointer, y.pointer)
        }

        // Methods

        // void SkColorSpace_toProfile(void *color_space, void *profile); // (SkColorSpace *color_space, skcms_ICCProfile *profile)

        func gammaCloseToSRGB() -> Bool {
            return SkColorSpace_gammaCloseToSRGB(self.pointer)
        }

        func gammaIsLinear() -> Bool {
            return SkColorSpace_gammaIsLinear(self.pointer)
        }

        // bool SkColorSpace_isNumericalTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn) -> bool
        // bool SkColorSpace_toXYZD50(void *color_space, void *toXYZD50); // (SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) -> bool

        func toXYZD50Hash() -> UInt32 {
            return SkColorSpace_toXYZD50Hash(self.pointer)
        }

        func makeLinearGamma() -> SkColorSpace {
            let handle = SkColorSpace_makeLinearGamma(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func makeSRGBGamma() -> SkColorSpace {
            let handle = SkColorSpace_makeSRGBGamma(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func makeColorSpin() -> SkColorSpace {
            let handle = SkColorSpace_makeColorSpin(self.pointer);
            let pointer = static_sk_color_space_get(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }

        func isSRGB() -> Bool {
            return SkColorSpace_isSRGB(self.pointer)
        }

        func serialize() -> SkData {
            let handle = SkColorSpace_serialize(self.pointer);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        func writeToMemory(memory: UnsafeMutableRawPointer?) -> UInt {
            return SkColorSpace_writeToMemory(self.pointer, memory)
        }

        func transferFn() -> [Float] {
            var gabcdef: [Float] = [0, 0, 0, 0, 0, 0, 0]
            SkColorSpace_transferFn(self.pointer, &gabcdef)
            return gabcdef
        }

        // void SkColorSpace_transferFn_2(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_invTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
        // void SkColorSpace_gamutTransformTo(void *color_space, const void *dst, void *src_to_dst); // (SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst)

        func transferFnHash() -> UInt32 {
            return SkColorSpace_transferFnHash(self.pointer)
        }

        func hash() -> UInt64 {
            return SkColorSpace_hash(self.pointer)
        }

        func unique() -> Bool {
            return SkColorSpace_unique(self.pointer)
        }

        func ref() {
            SkColorSpace_ref(self.pointer)
        }

        func unref() {
            SkColorSpace_unref(self.pointer)
        }

        func deref() {
            SkColorSpace_deref(self.pointer)
        }

        func refCntGreaterThan(threadIsolatedTestCnt: Int) -> Bool {
            return SkColorSpace_refCntGreaterThan(self.pointer, Int32(threadIsolatedTestCnt))
        }
    }
}