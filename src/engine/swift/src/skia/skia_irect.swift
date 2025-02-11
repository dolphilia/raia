extension Skia {
    protocol SkIRectProtocol {
        var pointer: SkIRectMutablePointer? { get set }
        var handle: sk_i_rect_t { get set }
        // deinit // void SkIRect_delete(void *i_rect); // (SkIRect *i_rect)
        init(pointer: SkIRectMutablePointer?, handle: sk_i_rect_t)
        // Static Methods
        static func MakeEmpty() -> SkIRect // int SkIRect_MakeEmpty(); // () -> sk_i_rect_t
        static func MakeWH(w: Int, h: Int) -> SkIRect // int SkIRect_MakeWH(int w, int h); // (int32_t w, int32_t h) -> sk_i_rect_t
        static func MakeSize(size: SkISize) -> SkIRect // int SkIRect_MakeSize(const void *size); // (const SkISize *size) -> sk_i_rect_t
        static func MakePtSize(pt: SkIPoint, size: SkISize) -> SkIRect // int SkIRect_MakePtSize(int pt, int size); // (sk_i_point_t pt, sk_i_size_t size) -> sk_i_rect_t
        static func MakeLTRB(l: Int, t: Int, r: Int, b: Int) -> SkIRect // int SkIRect_MakeLTRB(int l, int t, int r, int b); // (int32_t l, int32_t t, int32_t r, int32_t b) -> sk_i_rect_t
        static func MakeXYWH(x: Int, y: Int, w: Int, h: Int) -> SkIRect // int SkIRect_MakeXYWH(int x, int y, int w, int h); // (int32_t x, int32_t y, int32_t w, int32_t h) -> sk_i_rect_t
        static func Intersects(a: SkIRect, b: SkIRect) -> Bool // bool SkIRect_Intersects(const void *a, const void *b); // (const SkIRect *a, const SkIRect *b) -> bool
        static func MakeOffset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect // int SkIRect_makeOffset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
        static func MakeOffset(i_rect: SkIRect, offset: SkIPoint) -> SkIRect // int SkIRect_makeOffset_2(void *i_rect, int offset); // (SkIRect *i_rect, sk_i_point_t offset) -> sk_i_rect_t
        static func MakeInset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect // int SkIRect_makeInset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
        static func MakeOutset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect // int SkIRect_makeOutset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
        // Methods
        func left() -> Int // int SkIRect_left(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func top() -> Int // int SkIRect_top(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func right() -> Int // int SkIRect_right(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func bottom() -> Int // int SkIRect_bottom(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func x() -> Int // int SkIRect_x(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func y() -> Int // int SkIRect_y(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func topLeft() -> SkIPoint // int SkIRect_topLeft(void *i_rect); // (SkIRect *i_rect) -> sk_i_point_t
        func width() -> Int // int SkIRect_width(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func height() -> Int // int SkIRect_height(void *i_rect); // (SkIRect *i_rect) -> int32_t
        func size() -> SkISize // int SkIRect_size(void *i_rect); // (SkIRect *i_rect) -> sk_i_size_t
        func width64() -> Int64 // long long SkIRect_width64(void *i_rect); // (SkIRect *i_rect) -> int64_t
        func height64() -> Int64 // long long SkIRect_height64(void *i_rect); // (SkIRect *i_rect) -> int64_t
        func isEmpty64() -> Bool // bool SkIRect_isEmpty64(void *i_rect); // (SkIRect *i_rect) -> bool
        func isEmpty() -> Bool // bool SkIRect_isEmpty(void *i_rect); // (SkIRect *i_rect) -> bool
        func setEmpty() // void SkIRect_setEmpty(void *i_rect); // (SkIRect *i_rect)
        func setLTRB(left: Int, top: Int, right: Int, bottom: Int) // void SkIRect_setLTRB(void *i_rect, int left, int top, int right, int bottom); // (SkIRect *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom)
        func setXYWH(x: Int, y: Int, width: Int, height: Int) // void SkIRect_setXYWH(void *i_rect, int x, int y, int width, int height); // (SkIRect *i_rect, int32_t x, int32_t y, int32_t width, int32_t height)
        func setWH(width: Int, height: Int) // void SkIRect_setWH(void *i_rect, int width, int height); // (SkIRect *i_rect, int32_t width, int32_t height)
        func setSize(size: SkISize) // void SkIRect_setSize(void *i_rect, int size); // (SkIRect *i_rect, sk_i_size_t size)
        func offset(dx: Int, dy: Int) // void SkIRect_offset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
        func offset(delta: SkIPoint) // void SkIRect_offset_2(void *i_rect, const void *delta); // (SkIRect *i_rect, const SkIPoint *delta)
        func offsetTo(newX: Int, newY: Int) // void SkIRect_offsetTo(void *i_rect, int newX, int newY); // (SkIRect *i_rect, int32_t newX, int32_t newY)
        func inset(dx: Int, dy: Int) // void SkIRect_inset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
        func outset(dx: Int, dy: Int) // void SkIRect_outset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
        func adjust(dL: Int, dT: Int, dR: Int, dB: Int) // void SkIRect_adjust(void *i_rect, int dL, int dT, int dR, int dB); // (SkIRect *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB)
        func contains(x: Int, y: Int) -> Bool // bool SkIRect_contains(void *i_rect, int x, int y); // (SkIRect *i_rect, int32_t x, int32_t y) -> bool
        func contains(r: SkIRect) -> Bool // bool SkIRect_contains_2(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
        func contains(r: SkRect) -> Bool // bool SkIRect_contains_3(void *i_rect, const void *r); // (SkIRect *i_rect, const SkRect *r) -> bool
        func containsNoEmptyCheck(r: SkIRect) -> Bool // bool SkIRect_containsNoEmptyCheck(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
        func intersect(r: SkIRect) -> Bool // bool SkIRect_intersect(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
        func intersect(a: SkIRect, b: SkIRect) -> Bool // bool SkIRect_intersect_2(void *i_rect, const void *a, const void *b); // (SkIRect *i_rect, const SkIRect *a, const SkIRect *b) -> bool
        func join(r: SkIRect) // void SkIRect_join(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r)
        func sort() // void SkIRect_sort(void *i_rect); // (SkIRect *i_rect)
        func makeSorted() -> SkIRect // int SkIRect_makeSorted(void *i_rect); // (SkIRect *i_rect) -> sk_i_rect_t
    }

    class SkIRect : SkIRectProtocol {
        public var pointer: SkIRectMutablePointer?
        public var handle: sk_i_rect_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_i_rect_delete(self.handle)
            } else {
                SkIRect_delete(self.pointer)
            }
        }

        required init(pointer: SkIRectMutablePointer?, handle: sk_i_rect_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeEmpty() -> SkIRect {
            let handle = SkIRect_MakeEmpty();
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeWH(w: Int, h: Int) -> SkIRect {
            let handle = SkIRect_MakeWH(Int32(w), Int32(h));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeSize(size: SkISize) -> SkIRect {
            let handle = SkIRect_MakeSize(size.pointer);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakePtSize(pt: SkIPoint, size: SkISize) -> SkIRect {
            let handle = SkIRect_MakePtSize(pt.handle, size.handle);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeLTRB(l: Int, t: Int, r: Int, b: Int) -> SkIRect {
            let handle = SkIRect_MakeLTRB(Int32(l), Int32(t), Int32(r), Int32(b));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeXYWH(x: Int, y: Int, w: Int, h: Int) -> SkIRect {
            let handle = SkIRect_MakeXYWH(Int32(x), Int32(y), Int32(w), Int32(h));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func Intersects(a: SkIRect, b: SkIRect) -> Bool {
            return SkIRect_Intersects(a.pointer, b.pointer)
        }

        static func MakeOffset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect {
            let handle = SkIRect_makeOffset(i_rect.pointer, Int32(dx), Int32(dy));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeOffset(i_rect: SkIRect, offset: SkIPoint) -> SkIRect {
            let handle = SkIRect_makeOffset_2(i_rect.pointer, offset.handle);
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeInset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect {
            let handle = SkIRect_makeInset(i_rect.pointer, Int32(dx), Int32(dy));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        static func MakeOutset(i_rect: SkIRect, dx: Int, dy: Int) -> SkIRect {
            let handle = SkIRect_makeOutset(i_rect.pointer, Int32(dx), Int32(dy));
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        // Methods

        func left() -> Int {
            return Int(SkIRect_left(self.pointer))
        }

        func top() -> Int {
            return Int(SkIRect_top(self.pointer))
        }

        func right() -> Int {
            return Int(SkIRect_right(self.pointer))
        }

        func bottom() -> Int {
            return Int(SkIRect_bottom(self.pointer))
        }

        func x() -> Int {
            return Int(SkIRect_x(self.pointer))
        }

        func y() -> Int {
            return Int(SkIRect_y(self.pointer))
        }

        func topLeft() -> SkIPoint {
            let handle = SkIRect_topLeft(self.pointer)
            let pointer = static_sk_i_point_get_ptr(handle)
            return SkIPoint(pointer: pointer, handle: handle)
        }

        func width() -> Int {
            return Int(SkIRect_width(self.pointer))
        }

        func height() -> Int {
            return Int(SkIRect_height(self.pointer))
        }

        func size() -> SkISize {
            let handle = SkIRect_size(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        func width64() -> Int64 {
            return Int64(SkIRect_width64(self.pointer))
        }

        func height64() -> Int64 {
            return Int64(SkIRect_height64(self.pointer))
        }

        func isEmpty64() -> Bool {
            return SkIRect_isEmpty64(self.pointer)
        }

        func isEmpty() -> Bool {
            return SkIRect_isEmpty(self.pointer)
        }

        func setEmpty() {
            SkIRect_setEmpty(self.pointer)
        }

        func setLTRB(left: Int, top: Int, right: Int, bottom: Int) {
            SkIRect_setLTRB(self.pointer, Int32(left), Int32(top), Int32(right), Int32(bottom))
        }

        func setXYWH(x: Int, y: Int, width: Int, height: Int) {
            SkIRect_setXYWH(self.pointer, Int32(x), Int32(y), Int32(width), Int32(height))
        }

        func setWH(width: Int, height: Int) {
            SkIRect_setWH(self.pointer, Int32(width), Int32(height))
        }

        func setSize(size: SkISize) {
            SkIRect_setSize(self.pointer, size.handle)
        }

        func offset(dx: Int, dy: Int) {
            SkIRect_offset(self.pointer, Int32(dx), Int32(dy))
        }

        func offset(delta: SkIPoint) {
            SkIRect_offset_2(self.pointer, delta.pointer)
        }

        func offsetTo(newX: Int, newY: Int) {
            SkIRect_offsetTo(self.pointer, Int32(newX), Int32(newY))
        }

        func inset(dx: Int, dy: Int) {
            SkIRect_inset(self.pointer, Int32(dx), Int32(dy))
        }

        func outset(dx: Int, dy: Int) {
            SkIRect_outset(self.pointer, Int32(dx), Int32(dy))
        }

        func adjust(dL: Int, dT: Int, dR: Int, dB: Int) {
            SkIRect_adjust(self.pointer, Int32(dL), Int32(dT), Int32(dR), Int32(dB))
        }

        func contains(x: Int, y: Int) -> Bool {
            return SkIRect_contains(self.pointer, Int32(x), Int32(y))
        }

        func contains(r: SkIRect) -> Bool {
            return SkIRect_contains_2(self.pointer, r.pointer)
        }

        func contains(r: SkRect) -> Bool {
            return SkIRect_contains_3(self.pointer, r.pointer)
        }

        func containsNoEmptyCheck(r: SkIRect) -> Bool {
            return SkIRect_containsNoEmptyCheck(self.pointer, r.pointer)
        }

        func intersect(r: SkIRect) -> Bool {
            return SkIRect_intersect(self.pointer, r.pointer)
        }

        func intersect(a: SkIRect, b: SkIRect) -> Bool {
            return SkIRect_intersect_2(self.pointer, a.pointer, b.pointer)
        }

        func join(r: SkIRect) {
            SkIRect_join(self.pointer, r.pointer)
        }

        func sort() {
            SkIRect_sort(self.pointer)
        }

        func makeSorted() -> SkIRect {
            let handle = SkIRect_makeSorted(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }
    }
}