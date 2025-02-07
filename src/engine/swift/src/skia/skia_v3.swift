extension Skia {
    class V3 {
        public var pointer: Skia.V3MutablePointer?
        public var handle: sk_v3_t = -1

        // void SkV3_delete(void *v3); // (SkV3 *v3)

        deinit {
            SkV3_delete(self.pointer)
            if self.handle > -1 {
                static_sk_v3_delete(self.handle)
            }
        }
        // float SkV3_lengthSquared(void *v3); // (SkV3 *v3) -> SkScalar

        func lengthSquared() -> Float {
            return SkV3_lengthSquared(self.pointer)
        }
        // float SkV3_length(void *v3); // (SkV3 *v3) -> SkScalar

        func length() -> Float {
            return SkV3_length(self.pointer)
        }
        // float SkV3_dot(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> SkScalar

        func dot(v: Skia.V3) -> Float {
            return SkV3_dot(self.pointer, v.pointer)
        }
        // int SkV3_cross(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> sk_v3_t

        func cross(v: Skia.V3) -> Skia.V3 {
            let handle = SkV3_cross(self.pointer, v.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return V3(pointer: pointer, handle: handle)
        }
        // int SkV3_normalize(void *v3); // (SkV3 *v3) -> sk_v3_t

        func normalize() -> Skia.V3 {
            let handle = SkV3_normalize(self.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return V3(pointer: pointer, handle: handle)
        }
        // const void * SkV3_ptr(void *v3); // (SkV3 *v3) -> const float *

        func ptr() -> UnsafePointer<Float>? {
            return SkV3_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }
        // float * SkV3_ptr_2(void *v3); // (SkV3 *v3) -> float *

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV3_ptr_2(self.pointer)
        }

        // // static

        init(pointer: Skia.V3MutablePointer?, handle: sk_v3_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // float SkV3_Dot(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> SkScalar

        func Dot(a: Skia.V3, b: Skia.V3) -> Float {
            return SkV3_Dot(a.pointer, b.pointer)
        }
        // int SkV3_Cross(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> sk_v3_t

        func Cross(a: Skia.V3, b: Skia.V3) -> Skia.V3 {
            let handle = SkV3_Cross(a.pointer, b.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return V3(pointer: pointer, handle: handle)
        }
        // int SkV3_Normalize(const void *v); // (const SkV3 *v) -> sk_v3_t

        func Normalize(v: Skia.V3) -> Skia.V3 {
            let handle = SkV3_Normalize(v.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return V3(pointer: pointer, handle: handle)
        }
    }
}