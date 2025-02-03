extension Skia {
    class Point3 {
        public var pointer: Skia.Point3MutablePointer?
        public var handle: sk_point_3_t?

        // void SkPoint3_delete(void *point3); // (SkPoint3 *point3)
        deinit {
            SkPoint3_delete(self.pointer)
            if let handle = self.handle {
                static_sk_point_3_delete(handle)
            }
        }
        // float SkPoint3_x(void *point3); // (SkPoint3 *point3) -> SkScalar
        func x() -> Scalar {
            return SkPoint3_x(self.pointer)
        }
        // float SkPoint3_y(void *point3); // (SkPoint3 *point3) -> SkScalar
        func y() -> Scalar {
            return SkPoint3_y(self.pointer)
        }
        // float SkPoint3_z(void *point3); // (SkPoint3 *point3) -> SkScalar
        func z() -> Scalar {
            return SkPoint3_z(self.pointer)
        }
        // void SkPoint3_set(void *point3, float x, float y, float z); // (SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z)
        func set(x: Scalar, y: Scalar, z: Scalar) {
            SkPoint3_set(self.pointer, x, y, z)
        }
        // float SkPoint3_length(void *point3); // (SkPoint3 *point3) -> SkScalar
        func length() -> Scalar {
            return SkPoint3_length(self.pointer)
        }
        // bool SkPoint3_normalize(void *point3); // (SkPoint3 *point3) -> bool
        func normalize() -> Bool {
            return SkPoint3_normalize(self.pointer)
        }
        // int SkPoint3_makeScale(void *point3, float scale); // (SkPoint3 *point3, SkScalar scale) -> sk_point_3_t
        func makeScale(scale: Scalar) -> Point3 {
            let handle = SkPoint3_makeScale(self.pointer, scale);
            let pointer = static_sk_point_3_get_ptr(handle)
            return Point3(pointer: pointer, handle: handle)
        }
        // void SkPoint3_scale(void *point3, float value); // (SkPoint3 *point3, SkScalar value)
        func scale(value: Scalar) {
            SkPoint3_scale(self.pointer, value)
        }
        // bool SkPoint3_isFinite(void *point3); // (SkPoint3 *point3) -> bool
        func isFinite() -> Bool {
            return SkPoint3_isFinite(self.pointer)
        }
        // float SkPoint3_dot(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> SkScalar
        func dot(vec: Point3) -> Scalar {
            return SkPoint3_dot(self.pointer, vec.pointer)
        }
        // int SkPoint3_cross(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> sk_point_3_t
        func cross(vec: Point3) -> Point3 {
            let handle = SkPoint3_cross(self.pointer, vec.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return Point3(pointer: pointer, handle: handle)
        }

        // // static

        init(pointer: Skia.Point3MutablePointer?, handle: sk_point_3_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkPoint3_Make(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_point_3_t
        static func Make(x: Scalar, y: Scalar, z: Scalar) -> Point3 {
            let handle = SkPoint3_Make(x, y, z);
            let pointer = static_sk_point_3_get_ptr(handle)
            return Point3(pointer: pointer, handle: handle)
        }
        // float SkPoint3_Length(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> SkScalar
        static func Length(x: Scalar, y: Scalar, z: Scalar) -> Scalar {
            return SkPoint3_Length(x, y, z)
        }
        // float SkPoint3_DotProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> SkScalar
        static func DotProduct(a: Point3, b: Point3) -> Scalar {
            return SkPoint3_DotProduct(a.pointer, b.pointer)
        }
        // int SkPoint3_CrossProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> sk_point_3_t
        static func CrossProduct(a: Point3, b: Point3) -> Point3 {
            let handle = SkPoint3_CrossProduct(a.pointer, b.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return Point3(pointer: pointer, handle: handle)
        }

    }
}