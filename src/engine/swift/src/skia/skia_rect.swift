extension Skia {
    protocol SkRectProtocol {
        var pointer: Skia.SkRectMutablePointer? { get set }
        var handle: sk_rect_t { get set }
        // void SkRect_delete(void *rect); // (SkRect *rect)
        init(pointer: Skia.SkRectMutablePointer?, handle: sk_rect_t)
        // Static Methods
        static func MakeEmpty() -> SkRect // int SkRect_MakeEmpty(); // () -> sk_rect_t
        static func MakeWH(w: Float, h: Float) -> SkRect // int SkRect_MakeWH(float w, float h); // (float w, float h) -> sk_rect_t
        static func MakeIWH(w: Int, h: Int) -> SkRect // int SkRect_MakeIWH(int w, int h); // (int w, int h) -> sk_rect_t
        static func MakeSize(size: SkSize) -> SkRect // int SkRect_MakeSize(const void *size); // (const SkSize *size) -> sk_rect_t
        static func MakeLTRB(l: Float, t: Float, r: Float, b: Float) -> SkRect // int SkRect_MakeLTRB(float l, float t, float r, float b); // (float l, float t, float r, float b) -> sk_rect_t
        static func MakeXYWH(x: Float, y: Float, w: Float, h: Float) -> SkRect // int SkRect_MakeXYWH(float x, float y, float w, float h); // (float x, float y, float w, float h) -> sk_rect_t
        static func Make(size: ISize) -> SkRect // int SkRect_Make(const void *size); // (const SkISize *size) -> sk_rect_t
        static func Make(irect: IRect) -> SkRect // int SkRect_Make_2(const void *irect); // (const SkIRect *irect) -> sk_rect_t
        static func Intersects(a: SkRect, b: SkRect) -> Bool // bool SkRect_Intersects(const void *a, const void *b); // (const SkRect *a, const SkRect *b) -> bool
        // Methods
        func isEmpty() -> Bool // bool SkRect_isEmpty(void *rect); // (SkRect *rect) -> bool
        func isSorted() -> Bool // bool SkRect_isSorted(void *rect); // (SkRect *rect) -> bool
        func isFinite() -> Bool // bool SkRect_isFinite(void *rect); // (SkRect *rect) -> bool
        func x() -> Float // float SkRect_x(void *rect); // (SkRect *rect) -> float
        func y() -> Float // float SkRect_y(void *rect); // (SkRect *rect) -> float
        func left() -> Float // float SkRect_left(void *rect); // (SkRect *rect) -> float
        func top() -> Float // float SkRect_top(void *rect); // (SkRect *rect) -> float
        func right() -> Float // float SkRect_right(void *rect); // (SkRect *rect) -> float
        func bottom() -> Float // float SkRect_bottom(void *rect); // (SkRect *rect) -> float
        func width() -> Float // float SkRect_width(void *rect); // (SkRect *rect) -> float
        func height() -> Float // float SkRect_height(void *rect); // (SkRect *rect) -> float
        func centerX() -> Float // float SkRect_centerX(void *rect); // (SkRect *rect) -> float
        func centerY() -> Float // float SkRect_centerY(void *rect); // (SkRect *rect) -> float
        func center() -> SkPoint // int SkRect_center(void *rect); // (SkRect *rect) -> sk_point_t
        func toQuad(quad: [SkPoint]) // void SkRect_toQuad(void *rect, void * quad); // (SkRect *rect, SkPoint quad[4])
        func setEmpty() // void SkRect_setEmpty(void *rect); // (SkRect *rect)
        func set(src: IRect) // void SkRect_set(void *rect, const void *src); // (SkRect *rect, const SkIRect *src)
        func setLTRB(left: Float, top: Float, right: Float, bottom: Float) // void SkRect_setLTRB(void *rect, float left, float top, float right, float bottom); // (SkRect *rect, float left, float top, float right, float bottom)
        func setBounds(pts: [SkPoint]) // void SkRect_setBounds(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
        func setBoundsCheck(pts: [SkPoint]) -> Bool // bool SkRect_setBoundsCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count) -> bool
        func setBoundsNoCheck(pts: [SkPoint]) // void SkRect_setBoundsNoCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
        func set(p0: SkPoint, p1: SkPoint) // void SkRect_set_2(void *rect, const void *p0, const void *p1); // (SkRect *rect, const SkPoint *p0, const SkPoint *p1)
        func setXYWH(x: Float, y: Float, width: Float, height: Float) // void SkRect_setXYWH(void *rect, float x, float y, float width, float height); // (SkRect *rect, float x, float y, float width, float height)
        func setWH(width: Float, height: Float) // void SkRect_setWH(void *rect, float width, float height); // (SkRect *rect, float width, float height)
        func setIWH(width: Int, height: Int) // void SkRect_setIWH(void *rect, int width, int height); // (SkRect *rect, int32_t width, int32_t height)
        func makeOffset(dx: Float, dy: Float) -> SkRect // int SkRect_makeOffset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func makeOffset(v: SkPoint) -> SkRect // int SkRect_makeOffset_2(void *rect, int v); // (SkRect *rect, sk_point_t v) -> sk_rect_t
        func makeInset(dx: Float, dy: Float) -> SkRect // int SkRect_makeInset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func makeOutset(dx: Float, dy: Float) -> SkRect // int SkRect_makeOutset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func offset(dx: Float, dy: Float) // void SkRect_offset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func offset(delta: SkPoint) // void SkRect_offset_2(void *rect, const void *delta); // (SkRect *rect, const SkPoint *delta)
        func offsetTo(newX: Float, newY: Float) // void SkRect_offsetTo(void *rect, float newX, float newY); // (SkRect *rect, float newX, float newY)
        func inset(dx: Float, dy: Float) // void SkRect_inset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func outset(dx: Float, dy: Float) // void SkRect_outset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func intersect(r: SkRect) -> Bool // bool SkRect_intersect(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func intersect(a: SkRect, b: SkRect) -> Bool // bool SkRect_intersect_2(void *rect, const void *a, const void *b); // (SkRect *rect, const SkRect *a, const SkRect *b) -> bool
        func intersects(r: SkRect) -> Bool // bool SkRect_intersects(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func join(r: SkRect) // void SkRect_join(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func joinNonEmptyArg(r: SkRect) // void SkRect_joinNonEmptyArg(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func joinPossiblyEmptyRect(r: SkRect) // void SkRect_joinPossiblyEmptyRect(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func contains(x: Float, y: Float) -> Bool // bool SkRect_contains(void *rect, float x, float y); // (SkRect *rect, float x, float y) -> bool
        func contains(r: SkRect) -> Bool // bool SkRect_contains_2(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func contains(r: IRect) -> Bool // bool SkRect_contains_3(void *rect, const void *r); // (SkRect *rect, const SkIRect *r) -> bool
        func round(dst: IRect) // void SkRect_round(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func roundOut(dst: IRect) // void SkRect_roundOut(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func roundOut(dst: SkRect) // void SkRect_roundOut_2(void *rect, void *dst); // (SkRect *rect, SkRect *dst)
        func roundIn(dst: IRect) // void SkRect_roundIn(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func round() -> IRect // int SkRect_round_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func roundOut() -> IRect // int SkRect_roundOut_3(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func roundIn() -> IRect // int SkRect_roundIn_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func sort() // void SkRect_sort(void *rect); // (SkRect *rect)
        func makeSorted() -> SkRect // int SkRect_makeSorted(void *rect); // (SkRect *rect) -> sk_rect_t
        func asScalars() -> [Float] // const float * SkRect_asScalars(void *rect); // (SkRect *rect) -> const float *
        func dump(asHex: Bool) // void SkRect_dump(void *rect, bool asHex); // (SkRect *rect, bool asHex)
        func dump() // void SkRect_dump_2(void *rect); // (SkRect *rect)
        func dumpHex() // void SkRect_dumpHex(void *rect); // (SkRect *rect)
    }
    class SkRect : SkRectProtocol {
        public var pointer: Skia.SkRectMutablePointer?
        public var handle: sk_rect_t = -1

        deinit {
            if handle > -1 {
                static_sk_rect_delete(handle)
            } else {
                SkRect_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkRectMutablePointer?, handle: sk_rect_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeEmpty() -> SkRect {
            let handle = SkRect_MakeEmpty();
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func MakeWH(w: Float, h: Float) -> SkRect {
            let handle = SkRect_MakeWH(w, h);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func MakeIWH(w: Int, h: Int) -> SkRect {
            let handle = SkRect_MakeIWH(Int32(w), Int32(h))
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func MakeSize(size: SkSize) -> SkRect {
            let handle = SkRect_MakeSize(size.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func MakeLTRB(l: Float, t: Float, r: Float, b: Float) -> SkRect {
            let handle = SkRect_MakeLTRB(l, t, r, b);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func MakeXYWH(x: Float, y: Float, w: Float, h: Float) -> SkRect {
            let handle = SkRect_MakeXYWH(x, y, w, h);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func Make(size: ISize) -> SkRect {
            let handle = SkRect_Make(size.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func Make(irect: IRect) -> SkRect {
            let handle = SkRect_Make_2(irect.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        static func Intersects(a: SkRect, b: SkRect) -> Bool {
            return SkRect_Intersects(a.pointer, b.pointer)
        }

        // Methods

        func isEmpty() -> Bool {
            return SkRect_isEmpty(self.pointer)
        }

        func isSorted() -> Bool {
            return SkRect_isSorted(self.pointer)
        }

        func isFinite() -> Bool {
            return SkRect_isFinite(self.pointer)
        }

        func x() -> Float {
            return SkRect_x(self.pointer)
        }

        func y() -> Float {
            return SkRect_y(self.pointer)
        }

        func left() -> Float {
            return SkRect_left(self.pointer)
        }

        func top() -> Float {
            return SkRect_top(self.pointer)
        }

        func right() -> Float {
            return SkRect_right(self.pointer)
        }

        func bottom() -> Float {
            return SkRect_bottom(self.pointer)
        }

        func width() -> Float {
            return SkRect_width(self.pointer)
        }

        func height() -> Float {
            return SkRect_height(self.pointer)
        }

        func centerX() -> Float {
            return SkRect_centerX(self.pointer)
        }

        func centerY() -> Float {
            return SkRect_centerY(self.pointer)
        }

        func center() -> SkPoint {
            let handle = SkRect_center(self.pointer)
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func toQuad(quad: [SkPoint]) {
            var quadPointers = quad.map({ $0.pointer })
            SkRect_toQuad(self.pointer, &quadPointers)
        }

        func setEmpty() {
            SkRect_setEmpty(self.pointer)
        }

        func set(src: IRect) {
            SkRect_set(self.pointer, src.pointer)
        }

        func setLTRB(left: Float, top: Float, right: Float, bottom: Float) {
            SkRect_setLTRB(self.pointer, left, top, right, bottom)
        }

        func setBounds(pts: [SkPoint]) {
            var pointPointers = pts.map({ $0.pointer })
            SkRect_setBounds(self.pointer, &pointPointers, Int32(pts.count))
        }

        func setBoundsCheck(pts: [SkPoint]) -> Bool {
            var pointPointers = pts.map({ $0.pointer })
            return SkRect_setBoundsCheck(self.pointer, &pointPointers, Int32(pts.count))
        }

        func setBoundsNoCheck(pts: [SkPoint]) {
            var pointPointers = pts.map({ $0.pointer })
            SkRect_setBoundsNoCheck(self.pointer, &pointPointers, Int32(pts.count))
        }

        func set(p0: SkPoint, p1: SkPoint) {
            SkRect_set_2(self.pointer, p0.pointer, p1.pointer)
        }

        func setXYWH(x: Float, y: Float, width: Float, height: Float) {
            SkRect_setXYWH(self.pointer, x, y, width, height)
        }

        func setWH(width: Float, height: Float) {
            SkRect_setWH(self.pointer, width, height)
        }

        func setIWH(width: Int, height: Int) {
            SkRect_setIWH(self.pointer, Int32(width), Int32(height))
        }

        func makeOffset(dx: Float, dy: Float) -> SkRect {
            let handle = SkRect_makeOffset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func makeOffset(v: SkPoint) -> SkRect {
            let handle = SkRect_makeOffset_2(self.pointer, v.handle);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func makeInset(dx: Float, dy: Float) -> SkRect {
            let handle = SkRect_makeInset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func makeOutset(dx: Float, dy: Float) -> SkRect {
            let handle = SkRect_makeOutset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func offset(dx: Float, dy: Float) {
            SkRect_offset(self.pointer, dx, dy)
        }

        func offset(delta: SkPoint) {
            SkRect_offset_2(self.pointer, delta.pointer)
        }

        func offsetTo(newX: Float, newY: Float) {
            SkRect_offsetTo(self.pointer, newX, newY)
        }

        func inset(dx: Float, dy: Float) {
            SkRect_inset(self.pointer, dx, dy)
        }

        func outset(dx: Float, dy: Float) {
            SkRect_outset(self.pointer, dx, dy)
        }

        func intersect(r: SkRect) -> Bool {
            return SkRect_intersect(self.pointer, r.pointer)
        }

        func intersect(a: SkRect, b: SkRect) -> Bool {
            return SkRect_intersect_2(self.pointer, a.pointer, b.pointer)
        }

        func intersects(r: SkRect) -> Bool {
            return SkRect_intersects(self.pointer, r.pointer)
        }

        func join(r: SkRect) {
            SkRect_join(self.pointer, r.pointer)
        }

        func joinNonEmptyArg(r: SkRect) {
            SkRect_joinNonEmptyArg(self.pointer, r.pointer)
        }

        func joinPossiblyEmptyRect(r: SkRect) {
            SkRect_joinPossiblyEmptyRect(self.pointer, r.pointer)
        }

        func contains(x: Float, y: Float) -> Bool {
            return SkRect_contains(self.pointer, x, y)
        }

        func contains(r: SkRect) -> Bool {
            return SkRect_contains_2(self.pointer, r.pointer)
        }

        func contains(r: IRect) -> Bool {
            return SkRect_contains_3(self.pointer, r.pointer)
        }

        func round(dst: IRect) {
            SkRect_round(self.pointer, dst.pointer)
        }

        func roundOut(dst: IRect) {
            SkRect_roundOut(self.pointer, dst.pointer)
        }

        func roundOut(dst: SkRect) {
            SkRect_roundOut_2(self.pointer, dst.pointer)
        }

        func roundIn(dst: IRect) {
            SkRect_roundIn(self.pointer, dst.pointer)
        }

        func round() -> IRect {
            let handle = SkRect_round_2(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }

        func roundOut() -> IRect {
            let handle = SkRect_roundOut_3(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }

        func roundIn() -> IRect {
            let handle = SkRect_roundIn_2(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }

        func sort() {
            SkRect_sort(self.pointer)
        }

        func makeSorted() -> SkRect {
            let handle = SkRect_makeSorted(self.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func asScalars() -> [Float] {
            let scalars = SkRect_asScalars(self.pointer)
            let count = 4
            let buffer = UnsafeBufferPointer<Float>(start: scalars, count: count)
            return Array(buffer)
        }

        func dump(asHex: Bool) {
            SkRect_dump(self.pointer, asHex)
        }

        func dump() {
            SkRect_dump_2(self.pointer)
        }

        func dumpHex() {
            SkRect_dumpHex(self.pointer)
        }
    }
}