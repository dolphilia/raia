extension Skia {
    protocol SkV3Protocol {
        var pointer: Skia.SkV3MutablePointer? { get set }
        var handle: sk_v3_t { get set }
        // deinit // void SkV3_delete(void *v3); // (SkV3 *v3)
        init(pointer: Skia.SkV3MutablePointer?, handle: sk_v3_t)
        // Static Methods
        static func Dot(a: Skia.SkV3, b: Skia.SkV3) -> Float // float SkV3_Dot(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> SkScalar
        static func Cross(a: Skia.SkV3, b: Skia.SkV3) -> Skia.SkV3 // int SkV3_Cross(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> sk_v3_t
        static func Normalize(v: Skia.SkV3) -> Skia.SkV3 // int SkV3_Normalize(const void *v); // (const SkV3 *v) -> sk_v3_t
        // Methods
        func lengthSquared() -> Float // float SkV3_lengthSquared(void *v3); // (SkV3 *v3) -> SkScalar
        func length() -> Float // float SkV3_length(void *v3); // (SkV3 *v3) -> SkScalar
        func dot(v: Skia.SkV3) -> Float // float SkV3_dot(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> SkScalar
        func cross(v: Skia.SkV3) -> Skia.SkV3 // int SkV3_cross(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> sk_v3_t
        func normalize() -> Skia.SkV3 // int SkV3_normalize(void *v3); // (SkV3 *v3) -> sk_v3_t
        func ptr() -> UnsafePointer<Float>? // const void * SkV3_ptr(void *v3); // (SkV3 *v3) -> const float *
        func ptr() -> UnsafeMutablePointer<Float>? // float * SkV3_ptr_2(void *v3); // (SkV3 *v3) -> float *
    }

    class SkV3 : SkV3Protocol {
        public var pointer: Skia.SkV3MutablePointer?
        public var handle: sk_v3_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_v3_delete(self.handle)
            } else {
                SkV3_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkV3MutablePointer?, handle: sk_v3_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Dot(a: Skia.SkV3, b: Skia.SkV3) -> Float {
            return SkV3_Dot(a.pointer, b.pointer)
        }

        static func Cross(a: Skia.SkV3, b: Skia.SkV3) -> Skia.SkV3 {
            let handle = SkV3_Cross(a.pointer, b.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return SkV3(pointer: pointer, handle: handle)
        }

        static func Normalize(v: Skia.SkV3) -> Skia.SkV3 {
            let handle = SkV3_Normalize(v.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return SkV3(pointer: pointer, handle: handle)
        }

        // Methods

        func lengthSquared() -> Float {
            return SkV3_lengthSquared(self.pointer)
        }

        func length() -> Float {
            return SkV3_length(self.pointer)
        }

        func dot(v: Skia.SkV3) -> Float {
            return SkV3_dot(self.pointer, v.pointer)
        }

        func cross(v: Skia.SkV3) -> Skia.SkV3 {
            let handle = SkV3_cross(self.pointer, v.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return SkV3(pointer: pointer, handle: handle)
        }

        func normalize() -> Skia.SkV3 {
            let handle = SkV3_normalize(self.pointer)
            let pointer = static_sk_v3_get_ptr(handle)
            return SkV3(pointer: pointer, handle: handle)
        }

        func ptr() -> UnsafePointer<Float>? {
            return SkV3_ptr(self.pointer)?.assumingMemoryBound(to: Float.self)
        }

        func ptr() -> UnsafeMutablePointer<Float>? {
            return SkV3_ptr_2(self.pointer)
        }
    }
}