extension Skia {
    class V2 {
        public var pointer: Skia.V2MutablePointer?
        public var handle: sk_v2_t = -1

        // void SkV2_delete(void *v2); // (SkV2 *v2)

        deinit {
            SkV2_delete(self.pointer)
            if self.handle > -1 {
                static_sk_v2_delete(self.handle)
            }
        }
        // float SkV2_lengthSquared(void *v2); // (SkV2 *v2) -> SkScalar

        func lengthSquared() -> Float {
            return SkV2_lengthSquared(self.pointer)
        }
        // float SkV2_length(void *v2); // (SkV2 *v2) -> SkScalar

        func length() -> Float {
            return SkV2_length(self.pointer)
        }
        // float SkV2_dot(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar

        func dot(v: Skia.V2) -> Float {
            return SkV2_dot(self.pointer, v.handle)
        }
        // float SkV2_cross(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar

        func cross(v: Skia.V2) -> Float {
            return SkV2_cross(self.pointer, v.handle)
        }
        // int SkV2_normalize(void *v2); // (SkV2 *v2) -> sk_v2_t

        func normalize() -> Skia.V2 {
            let handle = SkV2_normalize(self.pointer)
            let pointer = static_sk_v2_get_ptr(handle)
            return V2(pointer: pointer, handle: handle)
        }
        // const void * SkV2_ptr(void *v2); // (SkV2 *v2) -> const float *

        func ptr() -> UnsafePointer<Float>? {
            return SkV2_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }
        // float * SkV2_ptr_2(void *v2); // (SkV2 *v2) -> float *

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV2_ptr_2(self.pointer)
        }

        // // static

        init(pointer: Skia.V2MutablePointer?, handle: sk_v2_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // float SkV2_Dot(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar

        static func Dot(a: Skia.V2, b: Skia.V2) -> Float {
            return SkV2_Dot(a.handle, b.handle)
        }
        // float SkV2_Cross(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar

        static func Cross(a: Skia.V2, b: Skia.V2) -> Float {
            return SkV2_Cross(a.handle, b.handle)
        }
        // int SkV2_Normalize(int v); // (sk_v2_t v) -> sk_v2_t

        static func Normalize(v: Skia.V2) -> Skia.V2 {
            let handle = SkV2_Normalize(v.handle)
            let pointer = static_sk_v2_get_ptr(handle)
            return V2(pointer: pointer, handle: handle)
        }
    }
}