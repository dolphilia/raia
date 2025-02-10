extension Skia {
    protocol SkPoint3Protocol {
        var pointer: Skia.SkPoint3MutablePointer? { get set }
        var handle: sk_point_3_t { get set }
        // deinit // void SkPoint3_delete(void *point3); // (SkPoint3 *point3)
        init(pointer: Skia.SkPoint3MutablePointer?, handle: sk_point_3_t)
        // Static Methods
        static func Make(x: Scalar, y: Scalar, z: Scalar) -> SkPoint3 // int SkPoint3_Make(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_point_3_t
        static func Length(x: Scalar, y: Scalar, z: Scalar) -> Scalar // float SkPoint3_Length(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> SkScalar
        static func DotProduct(a: SkPoint3, b: SkPoint3) -> Scalar // float SkPoint3_DotProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> SkScalar
        static func CrossProduct(a: SkPoint3, b: SkPoint3) -> SkPoint3 // int SkPoint3_CrossProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> sk_point_3_t
        // Methods
        func x() -> Scalar // float SkPoint3_x(void *point3); // (SkPoint3 *point3) -> SkScalar
        func y() -> Scalar // float SkPoint3_y(void *point3); // (SkPoint3 *point3) -> SkScalar
        func z() -> Scalar // float SkPoint3_z(void *point3); // (SkPoint3 *point3) -> SkScalar
        func set(x: Scalar, y: Scalar, z: Scalar) // void SkPoint3_set(void *point3, float x, float y, float z); // (SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z)
        func length() -> Scalar // float SkPoint3_length(void *point3); // (SkPoint3 *point3) -> SkScalar
        func normalize() -> Bool // bool SkPoint3_normalize(void *point3); // (SkPoint3 *point3) -> bool
        func makeScale(scale: Scalar) -> SkPoint3 // int SkPoint3_makeScale(void *point3, float scale); // (SkPoint3 *point3, SkScalar scale) -> sk_point_3_t
        func scale(value: Scalar) // void SkPoint3_scale(void *point3, float value); // (SkPoint3 *point3, SkScalar value)
        func isFinite() -> Bool // bool SkPoint3_isFinite(void *point3); // (SkPoint3 *point3) -> bool
        func dot(vec: SkPoint3) -> Scalar // float SkPoint3_dot(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> SkScalar
        func cross(vec: SkPoint3) -> SkPoint3 // int SkPoint3_cross(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> sk_point_3_t
    }

    class SkPoint3 : SkPoint3Protocol {
        public var pointer: Skia.SkPoint3MutablePointer?
        public var handle: sk_point_3_t = -1

        deinit {
            SkPoint3_delete(self.pointer)
            if handle > -1 {
                static_sk_point_3_delete(handle)
            }
        }

        required init(pointer: Skia.SkPoint3MutablePointer?, handle: sk_point_3_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(x: Scalar, y: Scalar, z: Scalar) -> SkPoint3 {
            let handle = SkPoint3_Make(x, y, z);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        static func Length(x: Scalar, y: Scalar, z: Scalar) -> Scalar {
            return SkPoint3_Length(x, y, z)
        }

        static func DotProduct(a: SkPoint3, b: SkPoint3) -> Scalar {
            return SkPoint3_DotProduct(a.pointer, b.pointer)
        }

        static func CrossProduct(a: SkPoint3, b: SkPoint3) -> SkPoint3 {
            let handle = SkPoint3_CrossProduct(a.pointer, b.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        // Methods

        func x() -> Scalar {
            return SkPoint3_x(self.pointer)
        }

        func y() -> Scalar {
            return SkPoint3_y(self.pointer)
        }

        func z() -> Scalar {
            return SkPoint3_z(self.pointer)
        }

        func set(x: Scalar, y: Scalar, z: Scalar) {
            SkPoint3_set(self.pointer, x, y, z)
        }

        func length() -> Scalar {
            return SkPoint3_length(self.pointer)
        }

        func normalize() -> Bool {
            return SkPoint3_normalize(self.pointer)
        }

        func makeScale(scale: Scalar) -> SkPoint3 {
            let handle = SkPoint3_makeScale(self.pointer, scale);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        func scale(value: Scalar) {
            SkPoint3_scale(self.pointer, value)
        }

        func isFinite() -> Bool {
            return SkPoint3_isFinite(self.pointer)
        }

        func dot(vec: SkPoint3) -> Scalar {
            return SkPoint3_dot(self.pointer, vec.pointer)
        }

        func cross(vec: SkPoint3) -> SkPoint3 {
            let handle = SkPoint3_cross(self.pointer, vec.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }
    }
}