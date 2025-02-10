extension Skia {
    typealias Vector = Skia.Point
    class Point {
        public var pointer: Skia.SkPointMutablePointer?
        public var handle: sk_point_t = -1
        // void SkPoint_delete(void *point); // (SkPoint *point)
        deinit {
            SkPoint_delete(self.pointer)
            if handle > -1 {
                static_sk_point_delete(handle)
            }
        }
        init(pointer: Skia.SkPointMutablePointer?, handle: sk_point_t) {
            self.pointer = pointer
            self.handle = handle
        }
        // int SkPoint_Make(float x, float y); // (float x, float y) -> sk_point_t
        static func Make(x: Float, y: Float) -> Point {
            let handle = SkPoint_Make(x, y);
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // float SkPoint_Normalize(void *vec); // (SkVector *vec) -> float
        static func Normalize(vec: Skia.Vector) -> Float {
            return SkPoint_Normalize(vec.pointer)
        }
        // float SkPoint_Length(float x, float y); // (float x, float y) -> float
        static func Length(x: Float, y: Float) -> Float {
            return SkPoint_Length(x, y)
        }
        // float SkPoint_CrossProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
        static func CrossProduct(a: Skia.Vector, b: Skia.Vector) -> Float {
            return SkPoint_CrossProduct(a.pointer, b.pointer)
        }
        // float SkPoint_DotProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
        static func DotProduct(a: Skia.Vector, b: Skia.Vector) -> Float {
            return SkPoint_DotProduct(a.pointer, b.pointer)
        }
        // float SkPoint_Distance(const void *a, const void *b); // (const SkPoint *a, const SkPoint *b) -> float
        static func Distance(a: Point, b: Point) -> Float {
            return SkPoint_Distance(a.pointer, b.pointer)
        }
        // void SkPoint_Offset(void *points, int count, float dx, float dy); // (SkPoint *points, int count, float dx, float dy)
        static func Offset(points: Point, count: Int, dx: Float, dy: Float) {
            SkPoint_Offset(points.pointer, Int32(count), dx, dy)
        }
        // void SkPoint_Offset_2(void *points, int count, const void *offset); // (SkPoint *points, int count, const SkVector *offset)
        static func Offset(points: Point, count: Int, offset: Skia.Vector) {
            SkPoint_Offset_2(points.pointer, Int32(count), offset.pointer)
        }
        // float SkPoint_x(int point); // (sk_point_t point) -> float
        func x() -> Float {
            return SkPoint_x(self.handle)
        }
        // float SkPoint_y(int point); // (sk_point_t point) -> float
        func y() -> Float {
            return SkPoint_y(self.handle)
        }
        // float SkPoint_dot(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
        func dot(vec: Skia.Vector) -> Float {
            return SkPoint_dot(self.handle, vec.pointer)
        }
        // float SkPoint_length(int point); // (sk_point_t point) -> float
        func length() -> Float {
            return SkPoint_length(self.handle)
        }
        // float SkPoint_cross(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
        func cross(vec: Skia.Vector) -> Float {
            return SkPoint_cross(self.handle, vec.pointer)
        }
        // void SkPoint_set(int point, float x, float y); // (sk_point_t point, float x, float y)
        func set(x: Float, y: Float) {
            SkPoint_set(self.handle, x, y)
        }
        // bool SkPoint_equals(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
        func equals(x: Float, y: Float) -> Bool {
            return SkPoint_equals(self.handle, x, y)
        }
        // bool SkPoint_isZero(int point); // (sk_point_t point) -> bool
        func isZero() -> Bool {
            return SkPoint_isZero(self.handle)
        }
        // void SkPoint_scale(int point, float value); // (sk_point_t point, float value)
        func scale(value: Float) {
            SkPoint_scale(self.handle, value)
        }
        // void SkPoint_scale_2(int point, float scale, void *dst); // (sk_point_t point, float scale, SkPoint *dst)
        func scale(scale: Float, dst: Point) {
            SkPoint_scale_2(self.handle, scale, dst.pointer)
        }
        // bool SkPoint_isFinite(int point); // (sk_point_t point) -> bool
        func isFinite() -> Bool {
            return SkPoint_isFinite(self.handle)
        }
        // float SkPoint_distanceToOrigin(int point); // (sk_point_t point) -> float
        func distanceToOrigin() -> Float {
            return SkPoint_distanceToOrigin(self.handle)
        }
        // void SkPoint_iset(int point, const void *p); // (sk_point_t point, const SkIPoint *p)
        func iset(p: Skia.IPoint) {
            SkPoint_iset(self.handle, p.pointer)
        }
        // void SkPoint_iset_2(int point, int x, int y); // (sk_point_t point, int32_t x, int32_t y)
        func iset(x: Int, y: Int) {
            SkPoint_iset_2(self.handle, Int32(x), Int32(y))
        }
        // void SkPoint_negate(int point); // (sk_point_t point)
        func negate() {
            SkPoint_negate(self.handle)
        }
        // void SkPoint_setAbs(int point, const void *pt); // (sk_point_t point, const SkPoint *pt)
        func setAbs(pt: Point) {
            SkPoint_setAbs(self.handle, pt.pointer)
        }
        // bool SkPoint_setLength(int point, float length); // (sk_point_t point, float length) -> bool
        func setLength(length: Float) -> Bool {
            return SkPoint_setLength(self.handle, length)
        }
        // bool SkPoint_setNormalize(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
        func setNormalize(x: Float, y: Float) -> Bool {
            return SkPoint_setNormalize(self.handle, x, y)
        }
    }
}