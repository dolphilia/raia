extension Skia {
    class Color4f {
        public var pointer: Skia.Color4fMutablePointer?
        public var handle: sk_color_4f_t = -1

        // void SkColor4f_delete(void *color);

        deinit {
            if self.handle > -1 {
                static_sk_color_4f_delete(self.handle)
            } else {
                SkColor4f_delete(self.pointer)
            }
        }

        // // Public Attributes

        // float SkColor4f_fR(void *color); // (SkColor4f *color) -> float

        func fR() -> Float {
            return SkColor4f_fR(self.pointer)
        }

        // float SkColor4f_fG(void *color); // (SkColor4f *color) -> float

        func fG() -> Float {
            return SkColor4f_fG(self.pointer)
        }

        // float SkColor4f_fB(void *color); // (SkColor4f *color) -> float

        func fB() -> Float {
            return SkColor4f_fB(self.pointer)
        }

        // float SkColor4f_fA(void *color); // (SkColor4f *color) -> float

        func fA() -> Float {
            return SkColor4f_fA(self.pointer)
        }

        // // Public Member Functions

        // //bool operator== (const SkRGBA4f &other);
        // //bool operator!= (const SkRGBA4f &other);
        // //SkRGBA4f operator* (float scale);
        // //SkRGBA4f operator* (const SkRGBA4f &scale);
        // //float operator[] (SkColor4f *color, int index);
        // //float & operator[] (SkColor4f *color, int index);

        // const float * SkColor4f_vec(void *color); // (SkColor4f *color) -> const float *

        func vec() -> [Float] {
            let pointer = SkColor4f_vec(self.pointer)
            let count = 4
            let buffer = UnsafeBufferPointer(start: pointer, count: count)
            return Array(buffer)
        }

        // float * SkColor4f_vec_2(void *color); // (SkColor4f *color) -> float *

        func vec_2() -> [Float] {
            let pointer = SkColor4f_vec_2(self.pointer)
            let count = 4
            let buffer = UnsafeMutableBufferPointer(start: pointer, count: count)
            return Array(buffer)
        }

        // // TODO
        // // std::array< float, 4 > SkColor4f_array (void *color);

        // bool SkColor4f_isOpaque (void *color); // (SkColor4f *color) -> bool

        func isOpaque() -> Bool {
            return SkColor4f_isOpaque(self.pointer)
        }

        // bool SkColor4f_fitsInBytes (void *color); // (SkColor4f *color) -> bool

        func fitsInBytes() -> Bool {
            return SkColor4f_fitsInBytes(self.pointer)
        }

        // unsigned int SkColor4f_toSkColor (void *color); // (SkColor4f *color) -> SkColor

        func toSkColor() -> ColorARGB8888 {
            return SkColor4f_toSkColor(self.pointer)
        }

        // // TODO
        // //SkRGBA4f< kPremul_SkAlphaType > premul (SkColor4f *color);
        // //SkRGBA4f< kUnpremul_SkAlphaType > unpremul (SkColor4f *color);

        // unsigned int SkColor4f_toBytes_RGBA (void *color); // (SkColor4f *color) -> uint32_t

        func toBytes_RGBA() -> ColorRGBA8888 {
            return SkColor4f_toBytes_RGBA(self.pointer)
        }

        // int SkColor4f_makeOpaque(void *color); //  (SkColor4f *color) -> SkColor4f

        func makeOpaque() -> Color4f {
            let handle = SkColor4f_makeOpaque(self.pointer);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }

        // // static

        init(pointer: Skia.Color4fMutablePointer?, handle: sk_color_4f_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // static int SkColor4f_FromColor (unsigned int color); // (SkColor color) -> SkColor4f

        static func FromColor(color: ColorARGB8888) -> Color4f {
            let handle = SkColor4f_FromColor(color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }

        // static int SkColor4f_FromPMColor (unsigned int color); // (SkPMColor color) -> SkColor4f

        static func FromPMColor(color: ColorARGB8888PM) -> Color4f {
            let handle = SkColor4f_FromPMColor(color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }
        // static int SkColor4f_FromBytes_RGBA (unsigned int color); // (uint32_t color) -> SkColor4f

        static func FromBytes_RGBA(color: ColorRGBA8888) -> Color4f {
            let handle = SkColor4f_FromBytes_RGBA(color);
            let pointer = static_sk_color_4f_get_ptr(handle)
            return Color4f(pointer: pointer, handle: handle)
        }
    }
}