extension Skia {
    class V4 {
        public var pointer: Skia.V4MutablePointer?
        public var handle: sk_v4_t?

        // void SkV4_delete(void *v4); // (SkV4 *v4)

        deinit {
            SkV4_delete(pointer)
            if let handle = handle {
                static_sk_v4_delete(handle)
            }
        }
        // float SkV4_lengthSquared(void *v4); // (SkV4 *v4) -> SkScalar

        func lengthSquared() -> Float {
            return SkV4_lengthSquared(self.pointer)
        }
        // float SkV4_length(void *v4); // (SkV4 *v4) -> SkScalar

        func length() -> Float {
            return SkV4_length(self.pointer)
        }
        // float SkV4_dot(void *v4, const void *v); // (SkV4 *v4, const SkV4 *v) -> SkScalar

        func dot(v: Skia.V4) -> Float {
            return SkV4_dot(self.pointer, v.pointer)
        }
        // int SkV4_normalize(void *v4); // (SkV4 *v4) -> sk_v4_t

        func normalize() -> Skia.V4 {
            let handle = SkV4_normalize(self.pointer)
            let pointer = static_sk_v4_get_ptr(handle)
            return V4(pointer: pointer, handle: handle)
        }
        // const void * SkV4_ptr(void *v4); // (SkV4 *v4) -> const float *

        func ptr() -> UnsafePointer<Float>? {
            return SkV4_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }
        // float * SkV4_ptr_2(void *v4); // (SkV4 *v4) -> float *

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV4_ptr_2(self.pointer)
        }

        // // static

        init(pointer: Skia.V4MutablePointer?, handle: sk_v4_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // float SkV4_Dot(const void *a, const void *b); // (const SkV4 *a, const SkV4 *b) -> SkScalar
        func Dot(a: Skia.V4, b: Skia.V4) -> Float {
            return SkV4_Dot(a.pointer, b.pointer)
        }
        // int SkV4_Normalize(const void *v); // (const SkV4 *v) -> sk_v4_t
        func Normalize(v: Skia.V4) -> Skia.V4 {
            let handle = SkV4_Normalize(v.pointer)
            let pointer = static_sk_v4_get_ptr(handle)
            return V4(pointer: pointer, handle: handle)
        }
    }
}