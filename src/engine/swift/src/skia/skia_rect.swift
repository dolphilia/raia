extension Skia {
    class Rect {
        public var pointer: Skia.RectMutablePointer?
        public var handle: sk_rect_t?
        // void SkRect_delete(void *rect); // (SkRect *rect)
        deinit {
            SkRect_delete(self.pointer)
            if let handle = self.handle {
                static_sk_rect_delete(handle)
            }
        }
        // bool SkRect_isEmpty(void *rect); // (SkRect *rect) -> bool
        func isEmpty() -> Bool {
            return SkRect_isEmpty(self.pointer)
        }
        // bool SkRect_isSorted(void *rect); // (SkRect *rect) -> bool
        func isSorted() -> Bool {
            return SkRect_isSorted(self.pointer)
        }
        // bool SkRect_isFinite(void *rect); // (SkRect *rect) -> bool
        func isFinite() -> Bool {
            return SkRect_isFinite(self.pointer)
        }
        // float SkRect_x(void *rect); // (SkRect *rect) -> float
        func x() -> Float {
            return SkRect_x(self.pointer)
        }
        // float SkRect_y(void *rect); // (SkRect *rect) -> float
        func y() -> Float {
            return SkRect_y(self.pointer)
        }
        // float SkRect_left(void *rect); // (SkRect *rect) -> float
        func left() -> Float {
            return SkRect_left(self.pointer)
        }
        // float SkRect_top(void *rect); // (SkRect *rect) -> float
        func top() -> Float {
            return SkRect_top(self.pointer)
        }
        // float SkRect_right(void *rect); // (SkRect *rect) -> float
        func right() -> Float {
            return SkRect_right(self.pointer)
        }
        // float SkRect_bottom(void *rect); // (SkRect *rect) -> float
        func bottom() -> Float {
            return SkRect_bottom(self.pointer)
        }
        // float SkRect_width(void *rect); // (SkRect *rect) -> float
        func width() -> Float {
            return SkRect_width(self.pointer)
        }
        // float SkRect_height(void *rect); // (SkRect *rect) -> float
        func height() -> Float {
            return SkRect_height(self.pointer)
        }
        // float SkRect_centerX(void *rect); // (SkRect *rect) -> float
        func centerX() -> Float {
            return SkRect_centerX(self.pointer)
        }
        // float SkRect_centerY(void *rect); // (SkRect *rect) -> float
        func centerY() -> Float {
            return SkRect_centerY(self.pointer)
        }
        // int SkRect_center(void *rect); // (SkRect *rect) -> sk_point_t
        func center() -> Point {
            let handle = SkRect_center(self.pointer)
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // void SkRect_toQuad(void *rect, void * quad); // (SkRect *rect, SkPoint quad[4])
        func toQuad(quad: [Point]) {
            var quadPointers = quad.map({ $0.pointer })
            SkRect_toQuad(self.pointer, &quadPointers)
        }
        // void SkRect_setEmpty(void *rect); // (SkRect *rect)
        func setEmpty() {
            SkRect_setEmpty(self.pointer)
        }
        // void SkRect_set(void *rect, const void *src); // (SkRect *rect, const SkIRect *src)
        func set(src: IRect) {
            SkRect_set(self.pointer, src.pointer)
        }
        // void SkRect_setLTRB(void *rect, float left, float top, float right, float bottom); // (SkRect *rect, float left, float top, float right, float bottom)
        func setLTRB(left: Float, top: Float, right: Float, bottom: Float) {
            SkRect_setLTRB(self.pointer, left, top, right, bottom)
        }
        // void SkRect_setBounds(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
        func setBounds(pts: [Point]) {
            var pointPointers = pts.map({ $0.pointer })
            SkRect_setBounds(self.pointer, &pointPointers, Int32(pts.count))
        }
        // bool SkRect_setBoundsCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count) -> bool
        func setBoundsCheck(pts: [Point]) -> Bool {
            var pointPointers = pts.map({ $0.pointer })
            return SkRect_setBoundsCheck(self.pointer, &pointPointers, Int32(pts.count))
        }
        // void SkRect_setBoundsNoCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
        func setBoundsNoCheck(pts: [Point]) {
            var pointPointers = pts.map({ $0.pointer })
            SkRect_setBoundsNoCheck(self.pointer, &pointPointers, Int32(pts.count))
        }
        // void SkRect_set_2(void *rect, const void *p0, const void *p1); // (SkRect *rect, const SkPoint *p0, const SkPoint *p1)
        func set(p0: Point, p1: Point) {
            SkRect_set_2(self.pointer, p0.pointer, p1.pointer)
        }
        // void SkRect_setXYWH(void *rect, float x, float y, float width, float height); // (SkRect *rect, float x, float y, float width, float height)
        func setXYWH(x: Float, y: Float, width: Float, height: Float) {
            SkRect_setXYWH(self.pointer, x, y, width, height)
        }
        // void SkRect_setWH(void *rect, float width, float height); // (SkRect *rect, float width, float height)
        func setWH(width: Float, height: Float) {
            SkRect_setWH(self.pointer, width, height)
        }
        // void SkRect_setIWH(void *rect, int width, int height); // (SkRect *rect, int32_t width, int32_t height)
        func setIWH(width: Int, height: Int) {
            SkRect_setIWH(self.pointer, Int32(width), Int32(height))
        }
        // int SkRect_makeOffset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func makeOffset(dx: Float, dy: Float) -> Rect {
            let handle = SkRect_makeOffset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_makeOffset_2(void *rect, int v); // (SkRect *rect, sk_point_t v) -> sk_rect_t
        func makeOffset(v: Point) -> Rect {
            guard let handle_v = v.handle else {
                fatalError("SkRect makeOffset() handle is nil")
            }
            let handle = SkRect_makeOffset_2(self.pointer, handle_v);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_makeInset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func makeInset(dx: Float, dy: Float) -> Rect {
            let handle = SkRect_makeInset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_makeOutset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
        func makeOutset(dx: Float, dy: Float) -> Rect {
            let handle = SkRect_makeOutset(self.pointer, dx, dy);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // void SkRect_offset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func offset(dx: Float, dy: Float) {
            SkRect_offset(self.pointer, dx, dy)
        }
        // void SkRect_offset_2(void *rect, const void *delta); // (SkRect *rect, const SkPoint *delta)
        func offset(delta: Point) {
            SkRect_offset_2(self.pointer, delta.pointer)
        }
        // void SkRect_offsetTo(void *rect, float newX, float newY); // (SkRect *rect, float newX, float newY)
        func offsetTo(newX: Float, newY: Float) {
            SkRect_offsetTo(self.pointer, newX, newY)
        }
        // void SkRect_inset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func inset(dx: Float, dy: Float) {
            SkRect_inset(self.pointer, dx, dy)
        }
        // void SkRect_outset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
        func outset(dx: Float, dy: Float) {
            SkRect_outset(self.pointer, dx, dy)
        }
        // bool SkRect_intersect(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func intersect(r: Rect) -> Bool {
            return SkRect_intersect(self.pointer, r.pointer)
        }
        // bool SkRect_intersect_2(void *rect, const void *a, const void *b); // (SkRect *rect, const SkRect *a, const SkRect *b) -> bool
        func intersect(a: Rect, b: Rect) -> Bool {
            return SkRect_intersect_2(self.pointer, a.pointer, b.pointer)
        }
        // bool SkRect_intersects(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func intersects(r: Rect) -> Bool {
            return SkRect_intersects(self.pointer, r.pointer)
        }
        // void SkRect_join(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func join(r: Rect) {
            SkRect_join(self.pointer, r.pointer)
        }
        // void SkRect_joinNonEmptyArg(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func joinNonEmptyArg(r: Rect) {
            SkRect_joinNonEmptyArg(self.pointer, r.pointer)
        }
        // void SkRect_joinPossiblyEmptyRect(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
        func joinPossiblyEmptyRect(r: Rect) {
            SkRect_joinPossiblyEmptyRect(self.pointer, r.pointer)
        }
        // bool SkRect_contains(void *rect, float x, float y); // (SkRect *rect, float x, float y) -> bool
        func contains(x: Float, y: Float) -> Bool {
            return SkRect_contains(self.pointer, x, y)
        }
        // bool SkRect_contains_2(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
        func contains(r: Rect) -> Bool {
            return SkRect_contains_2(self.pointer, r.pointer)
        }
        // bool SkRect_contains_3(void *rect, const void *r); // (SkRect *rect, const SkIRect *r) -> bool
        func contains(r: IRect) -> Bool {
            return SkRect_contains_3(self.pointer, r.pointer)
        }
        // void SkRect_round(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func round(dst: IRect) {
            SkRect_round(self.pointer, dst.pointer)
        }
        // void SkRect_roundOut(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func roundOut(dst: IRect) {
            SkRect_roundOut(self.pointer, dst.pointer)
        }
        // void SkRect_roundOut_2(void *rect, void *dst); // (SkRect *rect, SkRect *dst)
        func roundOut(dst: Rect) {
            SkRect_roundOut_2(self.pointer, dst.pointer)
        }
        // void SkRect_roundIn(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
        func roundIn(dst: IRect) {
            SkRect_roundIn(self.pointer, dst.pointer)
        }
        // int SkRect_round_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func round() -> IRect {
            let handle = SkRect_round_2(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // int SkRect_roundOut_3(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func roundOut() -> IRect {
            let handle = SkRect_roundOut_3(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // int SkRect_roundIn_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
        func roundIn() -> IRect {
            let handle = SkRect_roundIn_2(self.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // void SkRect_sort(void *rect); // (SkRect *rect)
        func sort() {
            SkRect_sort(self.pointer)
        }
        // int SkRect_makeSorted(void *rect); // (SkRect *rect) -> sk_rect_t
        func makeSorted() -> Rect {
            let handle = SkRect_makeSorted(self.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // const float * SkRect_asScalars(void *rect); // (SkRect *rect) -> const float *
        func asScalars() -> [Float] {
            let scalars = SkRect_asScalars(self.pointer)
            let count = 4
            let buffer = UnsafeBufferPointer(start: scalars, count: count)
            return Array(buffer)
        }
        // void SkRect_dump(void *rect, bool asHex); // (SkRect *rect, bool asHex)
        func dump(asHex: Bool) {
            SkRect_dump(self.pointer, asHex)
        }
        // void SkRect_dump_2(void *rect); // (SkRect *rect)
        func dump() {
            SkRect_dump_2(self.pointer)
        }
        // void SkRect_dumpHex(void *rect); // (SkRect *rect)
        func dumpHex() {
            SkRect_dumpHex(self.pointer)
        }

        // // static

        init(pointer: Skia.RectMutablePointer?, handle: sk_rect_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkRect_MakeEmpty(); // () -> sk_rect_t
        static func MakeEmpty() -> Rect {
            let handle = SkRect_MakeEmpty();
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_MakeWH(float w, float h); // (float w, float h) -> sk_rect_t
        static func MakeWH(w: Float, h: Float) -> Rect {
            let handle = SkRect_MakeWH(w, h);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_MakeIWH(int w, int h); // (int w, int h) -> sk_rect_t
        static func MakeIWH(w: Int, h: Int) -> Rect {
            let handle = SkRect_MakeIWH(Int32(w), Int32(h))
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_MakeSize(const void *size); // (const SkSize *size) -> sk_rect_t
        static func MakeSize(size: Size) -> Rect {
            let handle = SkRect_MakeSize(size.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_MakeLTRB(float l, float t, float r, float b); // (float l, float t, float r, float b) -> sk_rect_t
        static func MakeLTRB(l: Float, t: Float, r: Float, b: Float) -> Rect {
            let handle = SkRect_MakeLTRB(l, t, r, b);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_MakeXYWH(float x, float y, float w, float h); // (float x, float y, float w, float h) -> sk_rect_t
        static func MakeXYWH(x: Float, y: Float, w: Float, h: Float) -> Rect {
            let handle = SkRect_MakeXYWH(x, y, w, h);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_Make(const void *size); // (const SkISize *size) -> sk_rect_t
        static func Make(size: ISize) -> Rect {
            let handle = SkRect_Make(size.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        // int SkRect_Make_2(const void *irect); // (const SkIRect *irect) -> sk_rect_t
        static func Make(irect: IRect) -> Rect {
            let handle = SkRect_Make_2(irect.pointer);
            let pointer = static_sk_rect_get_ptr(handle)
            return Rect(pointer: pointer, handle: handle)
        }
        //bool SkRect_Intersects(const void *a, const void *b); // (const SkRect *a, const SkRect *b) -> bool
        static func Intersects(a: Rect, b: Rect) -> Bool {
            return SkRect_Intersects(a.pointer, b.pointer)
        }
    }
}