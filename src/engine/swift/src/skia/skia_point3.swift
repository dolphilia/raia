extension Skia {
    protocol SkPoint3Protocol {
        var pointer: Skia.SkPoint3MutablePointer? { get set }
        var handle: sk_point_3_t { get set }
        // deinit // void SkPoint3_delete(void *point3); // (SkPoint3 *point3)
        init(pointer: Skia.SkPoint3MutablePointer?, handle: sk_point_3_t)
        // Static Methods
        static func Make(x: Float, y: Float, z: Float) -> SkPoint3 // int SkPoint3_Make(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_point_3_t
        static func Length(x: Float, y: Float, z: Float) -> Float // float SkPoint3_Length(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> SkScalar
        static func DotProduct(a: SkPoint3, b: SkPoint3) -> Float // float SkPoint3_DotProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> SkScalar
        static func CrossProduct(a: SkPoint3, b: SkPoint3) -> SkPoint3 // int SkPoint3_CrossProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> sk_point_3_t
        // Methods
        func x() -> Float // float SkPoint3_x(void *point3); // (SkPoint3 *point3) -> SkScalar
        func y() -> Float // float SkPoint3_y(void *point3); // (SkPoint3 *point3) -> SkScalar
        func z() -> Float // float SkPoint3_z(void *point3); // (SkPoint3 *point3) -> SkScalar
        func set(x: Float, y: Float, z: Float) // void SkPoint3_set(void *point3, float x, float y, float z); // (SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z)
        func length() -> Float // float SkPoint3_length(void *point3); // (SkPoint3 *point3) -> SkScalar
        func normalize() -> Bool // bool SkPoint3_normalize(void *point3); // (SkPoint3 *point3) -> bool
        func makeScale(scale: Float) -> SkPoint3 // int SkPoint3_makeScale(void *point3, float scale); // (SkPoint3 *point3, SkScalar scale) -> sk_point_3_t
        func scale(value: Float) // void SkPoint3_scale(void *point3, float value); // (SkPoint3 *point3, SkScalar value)
        func isFinite() -> Bool // bool SkPoint3_isFinite(void *point3); // (SkPoint3 *point3) -> bool
        func dot(vec: SkPoint3) -> Float // float SkPoint3_dot(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> SkScalar
        func cross(vec: SkPoint3) -> SkPoint3 // int SkPoint3_cross(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> sk_point_3_t
    }

    class SkPoint3 : SkPoint3Protocol {
        public var pointer: Skia.SkPoint3MutablePointer?
        public var handle: sk_point_3_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_point_3_delete(self.handle)
            } else {
                SkPoint3_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkPoint3MutablePointer?, handle: sk_point_3_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(x: Float, y: Float, z: Float) -> SkPoint3 {
            let handle = SkPoint3_Make(x, y, z);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        static func Length(x: Float, y: Float, z: Float) -> Float {
            return SkPoint3_Length(x, y, z)
        }

        static func DotProduct(a: SkPoint3, b: SkPoint3) -> Float {
            return SkPoint3_DotProduct(a.pointer, b.pointer)
        }

        static func CrossProduct(a: SkPoint3, b: SkPoint3) -> SkPoint3 {
            let handle = SkPoint3_CrossProduct(a.pointer, b.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        // Methods

        func x() -> Float {
            return SkPoint3_x(self.pointer)
        }

        func y() -> Float {
            return SkPoint3_y(self.pointer)
        }

        func z() -> Float {
            return SkPoint3_z(self.pointer)
        }

        func set(x: Float, y: Float, z: Float) {
            SkPoint3_set(self.pointer, x, y, z)
        }

        func length() -> Float {
            return SkPoint3_length(self.pointer)
        }

        func normalize() -> Bool {
            return SkPoint3_normalize(self.pointer)
        }

        func makeScale(scale: Float) -> SkPoint3 {
            let handle = SkPoint3_makeScale(self.pointer, scale);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }

        func scale(value: Float) {
            SkPoint3_scale(self.pointer, value)
        }

        func isFinite() -> Bool {
            return SkPoint3_isFinite(self.pointer)
        }

        func dot(vec: SkPoint3) -> Float {
            return SkPoint3_dot(self.pointer, vec.pointer)
        }

        func cross(vec: SkPoint3) -> SkPoint3 {
            let handle = SkPoint3_cross(self.pointer, vec.pointer);
            let pointer = static_sk_point_3_get_ptr(handle)
            return SkPoint3(pointer: pointer, handle: handle)
        }
    }
}