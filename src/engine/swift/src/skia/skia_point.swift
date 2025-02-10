extension Skia {
    typealias SkVector = Skia.SkPoint

    protocol SkPointProtocol {
        var pointer: Skia.SkPointMutablePointer? { get set }
        var handle: sk_point_t { get set }
        // deinit // void SkPoint_delete(void *point); // (SkPoint *point)
        init(pointer: Skia.SkPointMutablePointer?, handle: sk_point_t)
        // Static Methods
        static func Make(x: Float, y: Float) -> SkPoint // int SkPoint_Make(float x, float y); // (float x, float y) -> sk_point_t
        static func Normalize(vec: Skia.SkVector) -> Float // float SkPoint_Normalize(void *vec); // (SkVector *vec) -> float
        static func Length(x: Float, y: Float) -> Float // float SkPoint_Length(float x, float y); // (float x, float y) -> float
        static func CrossProduct(a: Skia.SkVector, b: Skia.SkVector) -> Float // float SkPoint_CrossProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
        static func DotProduct(a: Skia.SkVector, b: Skia.SkVector) -> Float // float SkPoint_DotProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
        static func Distance(a: SkPoint, b: SkPoint) -> Float // float SkPoint_Distance(const void *a, const void *b); // (const SkPoint *a, const SkPoint *b) -> float
        static func Offset(points: SkPoint, count: Int, dx: Float, dy: Float) // void SkPoint_Offset(void *points, int count, float dx, float dy); // (SkPoint *points, int count, float dx, float dy)
        static func Offset(points: SkPoint, count: Int, offset: Skia.SkVector) // void SkPoint_Offset_2(void *points, int count, const void *offset); // (SkPoint *points, int count, const SkVector *offset)
        // Methods
        func x() -> Float // float SkPoint_x(int point); // (sk_point_t point) -> float
        func y() -> Float // float SkPoint_y(int point); // (sk_point_t point) -> float
        func equals(x: Float, y: Float) -> Bool // bool SkPoint_equals(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
        func isZero() -> Bool // bool SkPoint_isZero(int point); // (sk_point_t point) -> bool
        func scale(value: Float) // void SkPoint_scale(int point, float value); // (sk_point_t point, float value)
        func scale(scale: Float, dst: SkPoint) // void SkPoint_scale_2(int point, float scale, void *dst); // (sk_point_t point, float scale, SkPoint *dst)
        func isFinite() -> Bool // bool SkPoint_isFinite(int point); // (sk_point_t point) -> bool
        func distanceToOrigin() -> Float // float SkPoint_distanceToOrigin(int point); // (sk_point_t point) -> float
        func iset(p: Skia.IPoint) // void SkPoint_iset(int point, const void *p); // (sk_point_t point, const SkIPoint *p)
        func iset(x: Int, y: Int) // void SkPoint_iset_2(int point, int x, int y); // (sk_point_t point, int32_t x, int32_t y)
        func negate() // void SkPoint_negate(int point); // (sk_point_t point)
        func setAbs(pt: SkPoint) // void SkPoint_setAbs(int point, const void *pt); // (sk_point_t point, const SkPoint *pt)
        func setLength(length: Float) -> Bool // bool SkPoint_setLength(int point, float length); // (sk_point_t point, float length) -> bool
        func setNormalize(x: Float, y: Float) -> Bool // bool SkPoint_setNormalize(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
    }

    class SkPoint  : SkPointProtocol {
        public var pointer: Skia.SkPointMutablePointer?
        public var handle: sk_point_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_point_delete(self.handle)
            } else {
                SkPoint_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkPointMutablePointer?, handle: sk_point_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(x: Float, y: Float) -> SkPoint {
            let handle = SkPoint_Make(x, y);
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        static func Normalize(vec: Skia.SkVector) -> Float {
            return SkPoint_Normalize(vec.pointer)
        }

        static func Length(x: Float, y: Float) -> Float {
            return SkPoint_Length(x, y)
        }

        static func CrossProduct(a: Skia.SkVector, b: Skia.SkVector) -> Float {
            return SkPoint_CrossProduct(a.pointer, b.pointer)
        }

        static func DotProduct(a: Skia.SkVector, b: Skia.SkVector) -> Float {
            return SkPoint_DotProduct(a.pointer, b.pointer)
        }

        static func Distance(a: SkPoint, b: SkPoint) -> Float {
            return SkPoint_Distance(a.pointer, b.pointer)
        }

        static func Offset(points: SkPoint, count: Int, dx: Float, dy: Float) {
            SkPoint_Offset(points.pointer, Int32(count), dx, dy)
        }

        static func Offset(points: SkPoint, count: Int, offset: Skia.SkVector) {
            SkPoint_Offset_2(points.pointer, Int32(count), offset.pointer)
        }

        // Methods

        func x() -> Float {
            return SkPoint_x(self.handle)
        }

        func y() -> Float {
            return SkPoint_y(self.handle)
        }

        func dot(vec: Skia.SkVector) -> Float {
            return SkPoint_dot(self.handle, vec.pointer)
        }

        func length() -> Float {
            return SkPoint_length(self.handle)
        }

        func cross(vec: Skia.SkVector) -> Float {
            return SkPoint_cross(self.handle, vec.pointer)
        }

        func set(x: Float, y: Float) {
            SkPoint_set(self.handle, x, y)
        }

        func equals(x: Float, y: Float) -> Bool {
            return SkPoint_equals(self.handle, x, y)
        }

        func isZero() -> Bool {
            return SkPoint_isZero(self.handle)
        }

        func scale(value: Float) {
            SkPoint_scale(self.handle, value)
        }

        func scale(scale: Float, dst: SkPoint) {
            SkPoint_scale_2(self.handle, scale, dst.pointer)
        }

        func isFinite() -> Bool {
            return SkPoint_isFinite(self.handle)
        }

        func distanceToOrigin() -> Float {
            return SkPoint_distanceToOrigin(self.handle)
        }

        func iset(p: Skia.IPoint) {
            SkPoint_iset(self.handle, p.pointer)
        }

        func iset(x: Int, y: Int) {
            SkPoint_iset_2(self.handle, Int32(x), Int32(y))
        }

        func negate() {
            SkPoint_negate(self.handle)
        }

        func setAbs(pt: SkPoint) {
            SkPoint_setAbs(self.handle, pt.pointer)
        }

        func setLength(length: Float) -> Bool {
            return SkPoint_setLength(self.handle, length)
        }

        func setNormalize(x: Float, y: Float) -> Bool {
            return SkPoint_setNormalize(self.handle, x, y)
        }
    }
}