extension Skia {
    protocol SKV4Protocol {
        var pointer: Skia.SkV4MutablePointer? { get set }
        var handle: sk_v4_t { get set }
        // deinit // void SkV4_delete(void *v4); // (SkV4 *v4)
        init(pointer: Skia.SkV4MutablePointer?, handle: sk_v4_t)
        // Static Methods
        static func Dot(a: Skia.SkV4, b: Skia.SkV4) -> Float // float SkV4_Dot(const void *a, const void *b); // (const SkV4 *a, const SkV4 *b) -> SkScalar
        static func Normalize(v: Skia.SkV4) -> Skia.SkV4 // int SkV4_Normalize(const void *v); // (const SkV4 *v) -> sk_v4_t
        // Methods
        func lengthSquared() -> Float // float SkV4_lengthSquared(void *v4); // (SkV4 *v4) -> SkScalar
        func length() -> Float // float SkV4_length(void *v4); // (SkV4 *v4) -> SkScalar
        func dot(v: Skia.SkV4) -> Float // float SkV4_dot(void *v4, const void *v); // (SkV4 *v4, const SkV4 *v) -> SkScalar
        func normalize() -> Skia.SkV4 // int SkV4_normalize(void *v4); // (SkV4 *v4) -> sk_v4_t
        func ptr() -> UnsafePointer<Float>? // const void * SkV4_ptr(void *v4); // (SkV4 *v4) -> const float *
        func ptr() -> UnsafeMutablePointer<Float>? // float * SkV4_ptr_2(void *v4); // (SkV4 *v4) -> float *
    }

    class SkV4 : SKV4Protocol {
        public var pointer: Skia.SkV4MutablePointer?
        public var handle: sk_v4_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_v4_delete(self.handle)
            } else {
                SkV4_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkV4MutablePointer?, handle: sk_v4_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Dot(a: Skia.SkV4, b: Skia.SkV4) -> Float {
            return SkV4_Dot(a.pointer, b.pointer)
        }

        static func Normalize(v: Skia.SkV4) -> Skia.SkV4 {
            let handle = SkV4_Normalize(v.pointer)
            let pointer = static_sk_v4_get_ptr(handle)
            return SkV4(pointer: pointer, handle: handle)
        }

        // Methods

        func lengthSquared() -> Float {
            return SkV4_lengthSquared(self.pointer)
        }

        func length() -> Float {
            return SkV4_length(self.pointer)
        }

        func dot(v: Skia.SkV4) -> Float {
            return SkV4_dot(self.pointer, v.pointer)
        }

        func normalize() -> Skia.SkV4 {
            let handle = SkV4_normalize(self.pointer)
            let pointer = static_sk_v4_get_ptr(handle)
            return SkV4(pointer: pointer, handle: handle)
        }

        func ptr() -> UnsafePointer<Float>? {
            return SkV4_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV4_ptr_2(self.pointer)
        }
    }
}