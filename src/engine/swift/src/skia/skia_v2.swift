extension Skia {
    protocol SkV2Protocol {
        var pointer: Skia.SkV2MutablePointer? { get set }
        var handle: sk_v2_t { get set }
        // deinit // void SkV2_delete(void *v2); // (SkV2 *v2)
        init(pointer: Skia.SkV2MutablePointer?, handle: sk_v2_t)
        // Static Methods
        static func Dot(a: Skia.SkV2, b: Skia.SkV2) -> Float // float SkV2_Dot(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar
        static func Cross(a: Skia.SkV2, b: Skia.SkV2) -> Float // float SkV2_Cross(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar
        static func Normalize(v: Skia.SkV2) -> Skia.SkV2 // int SkV2_Normalize(int v); // (sk_v2_t v) -> sk_v2_t
        // Methods
        func lengthSquared() -> Float // float SkV2_lengthSquared(void *v2); // (SkV2 *v2) -> SkScalar
        func length() -> Float // float SkV2_length(void *v2); // (SkV2 *v2) -> SkScalar
        func dot(v: Skia.SkV2) -> Float // float SkV2_dot(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar
        func cross(v: Skia.SkV2) -> Float // float SkV2_cross(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar
        func normalize() -> Skia.SkV2 // int SkV2_normalize(void *v2); // (SkV2 *v2) -> sk_v2_t
        func ptr() -> UnsafePointer<Float>? // const void * SkV2_ptr(void *v2); // (SkV2 *v2) -> const float *
        func ptr() -> UnsafeMutablePointer<Float>? // float * SkV2_ptr_2(void *v2); // (SkV2 *v2) -> float *
    }

    class SkV2 : SkV2Protocol {
        public var pointer: Skia.SkV2MutablePointer?
        public var handle: sk_v2_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_v2_delete(self.handle)
            } else {
                SkV2_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkV2MutablePointer?, handle: sk_v2_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Dot(a: Skia.SkV2, b: Skia.SkV2) -> Float {
            return SkV2_Dot(a.handle, b.handle)
        }

        static func Cross(a: Skia.SkV2, b: Skia.SkV2) -> Float {
            return SkV2_Cross(a.handle, b.handle)
        }

        static func Normalize(v: Skia.SkV2) -> Skia.SkV2 {
            let handle = SkV2_Normalize(v.handle)
            let pointer = static_sk_v2_get_ptr(handle)
            return SkV2(pointer: pointer, handle: handle)
        }

        // Methods

        func lengthSquared() -> Float {
            return SkV2_lengthSquared(self.pointer)
        }

        func length() -> Float {
            return SkV2_length(self.pointer)
        }

        func dot(v: Skia.SkV2) -> Float {
            return SkV2_dot(self.pointer, v.handle)
        }

        func cross(v: Skia.SkV2) -> Float {
            return SkV2_cross(self.pointer, v.handle)
        }

        func normalize() -> Skia.SkV2 {
            let handle = SkV2_normalize(self.pointer)
            let pointer = static_sk_v2_get_ptr(handle)
            return SkV2(pointer: pointer, handle: handle)
        }

        func ptr() -> UnsafePointer<Float>? {
            return SkV2_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV2_ptr_2(self.pointer)
        }
    }
}