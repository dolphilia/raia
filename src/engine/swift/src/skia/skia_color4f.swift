extension Skia {
    protocol SkColor4fProtocol {
        var pointer: SkColor4fMutablePointer? { get set }
        var handle: sk_color_4f_t { get set }
        // deinit // void SkColor4f_delete(void *color); // (SkColor4f *color)
        init(pointer: SkColor4fMutablePointer?, handle: sk_color_4f_t)
        // Static Methods
        static func FromColor(color: SkColor) -> SkColor4f // int SkColor4f_FromColor (unsigned int color); // (SkColor color) -> SkColor4f
        static func FromPMColor(color: SkPMColor) -> SkColor4f // int SkColor4f_FromPMColor (unsigned int color); // (SkPMColor color) -> SkColor4f
        static func FromBytes_RGBA(color: ColorRGBA8888) -> SkColor4f // int SkColor4f_FromBytes_RGBA (unsigned int color); // (uint32_t color) -> SkColor4f
        // Methods
        func fR() -> Float // float SkColor4f_fR(void *color); // (SkColor4f *color) -> float
        func fG() -> Float // float SkColor4f_fG(void *color); // (SkColor4f *color) -> float
        func fB() -> Float // float SkColor4f_fB(void *color); // (SkColor4f *color) -> float
        func fA() -> Float // float SkColor4f_fA(void *color); // (SkColor4f *color) -> float
        func vec() -> [Float] // const float * SkColor4f_vec(void *color); // (SkColor4f *color) -> const float *
        func vec_2() -> [Float] // float * SkColor4f_vec_2(void *color); // (SkColor4f *color) -> float *
        // std::array< float, 4 > SkColor4f_array (void *color);
        func isOpaque() -> Bool // bool SkColor4f_isOpaque (void *color); // (SkColor4f *color) -> bool
        func fitsInBytes() -> Bool // bool SkColor4f_fitsInBytes (void *color); // (SkColor4f *color) -> bool
        func toSkColor() -> SkColor // unsigned int SkColor4f_toSkColor (void *color); // (SkColor4f *color) -> SkColor
        // SkRGBA4f< kPremul_SkAlphaType > premul (SkColor4f *color);
        // SkRGBA4f< kUnpremul_SkAlphaType > unpremul (SkColor4f *color);
        func toBytes_RGBA() -> ColorRGBA8888 // unsigned int SkColor4f_toBytes_RGBA (void *color); // (SkColor4f *color) -> uint32_t
        func makeOpaque() -> SkColor4f // int SkColor4f_makeOpaque(void *color); //  (SkColor4f *color) -> SkColor4f
    }

    class SkColor4f : SkColor4fProtocol {
        public var pointer: SkColor4fMutablePointer?
        public var handle: sk_color_4f_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_color_4f_delete(self.handle)
            } else {
                SkColor4f_delete(self.pointer)
            }
        }

        required init(pointer: SkColor4fMutablePointer?, handle: sk_color_4f_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func FromColor(color: SkColor) -> SkColor4f {
            let handle = SkColor4f_FromColor(color.color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        static func FromPMColor(color: SkPMColor) -> SkColor4f {
            let handle = SkColor4f_FromPMColor(color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        static func FromBytes_RGBA(color: ColorRGBA8888) -> SkColor4f {
            let handle = SkColor4f_FromBytes_RGBA(color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        // Methods

        func fR() -> Float {
            return SkColor4f_fR(self.pointer)
        }

        func fG() -> Float {
            return SkColor4f_fG(self.pointer)
        }

        func fB() -> Float {
            return SkColor4f_fB(self.pointer)
        }

        func fA() -> Float {
            return SkColor4f_fA(self.pointer)
        }

        func vec() -> [Float] {
            let pointer = SkColor4f_vec(self.pointer)
            let count = 4
            let buffer = UnsafeBufferPointer(start: pointer, count: count)
            return Array(buffer)
        }

        func vec_2() -> [Float] {
            let pointer = SkColor4f_vec_2(self.pointer)
            let count = 4
            let buffer = UnsafeMutableBufferPointer(start: pointer, count: count)
            return Array(buffer)
        }

        // std::array< float, 4 > SkColor4f_array (void *color);

        func isOpaque() -> Bool {
            return SkColor4f_isOpaque(self.pointer)
        }

        func fitsInBytes() -> Bool {
            return SkColor4f_fitsInBytes(self.pointer)
        }

        func toSkColor() -> SkColor {
            return SkColor(color: SkColor4f_toSkColor(self.pointer))
        }

        //SkRGBA4f< kPremul_SkAlphaType > premul (SkColor4f *color);
        //SkRGBA4f< kUnpremul_SkAlphaType > unpremul (SkColor4f *color);

        func toBytes_RGBA() -> ColorRGBA8888 {
            return SkColor4f_toBytes_RGBA(self.pointer)
        }

        func makeOpaque() -> SkColor4f {
            let handle = SkColor4f_makeOpaque(self.pointer);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }
    }
}