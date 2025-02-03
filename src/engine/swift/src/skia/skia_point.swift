extension Skia {
    typealias Vector = Skia.Point
    class Point {
        public var pointer: Skia.PointMutablePointer?
        public var handle: sk_point_t?
        // void SkPoint_delete(void *point); // (SkPoint *point)
        deinit {
            SkPoint_delete(self.pointer)
            if let handle = self.handle {
                static_sk_point_delete(handle)
            }
        }
        // float SkPoint_x(int point); // (sk_point_t point) -> float
        func x() -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint x() handle is nil")
            }
            return SkPoint_x(handle)
        }
        // float SkPoint_y(int point); // (sk_point_t point) -> float
        func y() -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint y() handle is nil")
            }
            return SkPoint_y(handle)
        }
        // float SkPoint_dot(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
        func dot(vec: Skia.Vector) -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint dot() handle is nil")
            }
            return SkPoint_dot(handle, vec.pointer)
        }
        // float SkPoint_length(int point); // (sk_point_t point) -> float
        func length() -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint length() handle is nil")
            }
            return SkPoint_length(handle)
        }
        // float SkPoint_cross(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
        func cross(vec: Skia.Vector) -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint cross() handle is nil")
            }
            return SkPoint_cross(handle, vec.pointer)
        }
        // void SkPoint_set(int point, float x, float y); // (sk_point_t point, float x, float y)
        func set(x: Float, y: Float) {
            guard let handle = self.handle else {
                fatalError("SkPoint set() handle is nil")
            }
            SkPoint_set(handle, x, y)
        }
        // bool SkPoint_equals(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
        func equals(x: Float, y: Float) -> Bool {
            guard let handle = self.handle else {
                fatalError("SkPoint equals() handle is nil")
            }
            return SkPoint_equals(handle, x, y)
        }
        // bool SkPoint_isZero(int point); // (sk_point_t point) -> bool
        func isZero() -> Bool {
            guard let handle = self.handle else {
                fatalError("SkPoint isZero() handle is nil")
            }
            return SkPoint_isZero(handle)
        }
        // void SkPoint_scale(int point, float value); // (sk_point_t point, float value)
        func scale(value: Float) {
            guard let handle = self.handle else {
                fatalError("SkPoint scale() handle is nil")
            }
            SkPoint_scale(handle, value)
        }
        // void SkPoint_scale_2(int point, float scale, void *dst); // (sk_point_t point, float scale, SkPoint *dst)
        func scale(scale: Float, dst: Point) {
            guard let handle = self.handle else {
                fatalError("SkPoint scale() handle is nil")
            }
            SkPoint_scale_2(handle, scale, dst.pointer)
        }
        // bool SkPoint_isFinite(int point); // (sk_point_t point) -> bool
        func isFinite() -> Bool {
            guard let handle = self.handle else {
                fatalError("SkPoint isFinite() handle is nil")
            }
            return SkPoint_isFinite(handle)
        }
        // float SkPoint_distanceToOrigin(int point); // (sk_point_t point) -> float
        func distanceToOrigin() -> Float {
            guard let handle = self.handle else {
                fatalError("SkPoint distanceToOrigin() handle is nil")
            }
            return SkPoint_distanceToOrigin(handle)
        }
        // void SkPoint_iset(int point, const void *p); // (sk_point_t point, const SkIPoint *p)
        func iset(p: Skia.IPoint) {
            guard let handle = self.handle else {
                fatalError("SkPoint iset() handle is nil")
            }
            SkPoint_iset(handle, p.pointer)
        }
        // void SkPoint_iset_2(int point, int x, int y); // (sk_point_t point, int32_t x, int32_t y)
        func iset(x: Int, y: Int) {
            guard let handle = self.handle else {
                fatalError("SkPoint iset() handle is nil")
            }
            SkPoint_iset_2(handle, Int32(x), Int32(y))
        }
        // void SkPoint_negate(int point); // (sk_point_t point)
        func negate() {
            guard let handle = self.handle else {
                fatalError("SkPoint negate() handle is nil")
            }
            SkPoint_negate(handle)
        }
        // void SkPoint_setAbs(int point, const void *pt); // (sk_point_t point, const SkPoint *pt)
        func setAbs(pt: Point) {
            guard let handle = self.handle else {
                fatalError("SkPoint setAbs() handle is nil")
            }
            SkPoint_setAbs(handle, pt.pointer)
        }
        // bool SkPoint_setLength(int point, float length); // (sk_point_t point, float length) -> bool
        func setLength(length: Float) -> Bool {
            guard let handle = self.handle else {
                fatalError("SkPoint setLength() handle is nil")
            }
            return SkPoint_setLength(handle, length)
        }
        // bool SkPoint_setNormalize(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
        func setNormalize(x: Float, y: Float) -> Bool {
            guard let handle = self.handle else {
                fatalError("SkPoint setNormalize() handle is nil")
            }
            return SkPoint_setNormalize(handle, x, y)
        }

        // // static

        init(pointer: Skia.PointMutablePointer?, handle: sk_point_t?) {
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

    }
}