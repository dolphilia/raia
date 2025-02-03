extension Skia {
    class RRect {
        public enum RRectType: Int32 {
            case kEmpty_Type
            case kRect_Type
            case kOval_Type
            case kSimple_Type
            case kNinePatch_Type
            case kComplex_Type
            case kLastType
        }

        public enum RRectCorner: Int32 {
            case kUpperLeft_Corner
            case kUpperRight_Corner
            case kLowerRight_Corner
            case kLowerLeft_Corner
        }
    
        public var pointer: Skia.RRectMutablePointer?
        public var handle: sk_r_rect_t?

        // void *SkRRect_new(); // () -> SkRRect *

        init() {
            self.pointer = SkRRect_new()
            self.handle = nil
        }
        // void *SkRRect_new_2(const void *rrect); // (const SkRRect *rrect) -> SkRRect *

        init(rrect: RRect) {
            self.pointer = SkRRect_new_2(rrect.pointer)
            self.handle = nil
        }
        // void SkRRect_delete(void *rrect); // (SkRRect *rrect)

        deinit {
            SkRRect_delete(self.pointer)
            if let handle = self.handle {
                static_sk_r_rect_delete(handle)
            }
        }
        // int getType(void *rrect); // (SkRRect *rrect) -> SkRRect::Type

        func getType() -> RRectType {
            return RRectType(rawValue: Int32(SkRRect_getType(self.pointer)))!
        }
        // int type(void *rrect); // (SkRRect *rrect) -> SkRRect::Type
        
        func type() -> RRectType {
            return RRectType(rawValue: Int32(SkRRect_type(self.pointer)))!
        }
        // bool SkRRect_isEmpty(void *rrect); // (SkRRect *rrect) -> bool

        func isEmpty() -> Bool {
            return SkRRect_isEmpty(self.pointer)
        }
        // bool SkRRect_isRect(void *rrect); // (SkRRect *rrect) -> bool

        func isRect() -> Bool {
            return SkRRect_isRect(self.pointer)
        }
        // bool SkRRect_isOval(void *rrect); // (SkRRect *rrect) -> bool

        func isOval() -> Bool {
            return SkRRect_isOval(self.pointer)
        }
        // bool SkRRect_isSimple(void *rrect); // (SkRRect *rrect) -> bool

        func isSimple() -> Bool {
            return SkRRect_isSimple(self.pointer)
        }
        // bool SkRRect_isNinePatch(void *rrect); // (SkRRect *rrect) -> bool

        func isNinePatch() -> Bool {
            return SkRRect_isNinePatch(self.pointer)
        }
        // bool SkRRect_isComplex(void *rrect); // (SkRRect *rrect) -> bool

        func isComplex() -> Bool {
            return SkRRect_isComplex(self.pointer)
        }
        // float SkRRect_width(void *rrect); // (SkRRect *rrect) -> SkScalar

        func width() -> Scalar {
            return SkRRect_width(self.pointer)
        }
        // float SkRRect_height(void *rrect); // (SkRRect *rrect) -> SkScalar

        func height() -> Scalar {
            return SkRRect_height(self.pointer)
        }
        // int SkRRect_getSimpleRadii(void *rrect); // (SkRRect *rrect) -> sk_point_t

        func getSimpleRadii() -> Point {
            let handle = SkRRect_getSimpleRadii(self.pointer)
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // void SkRRect_setEmpty(void *rrect); // (SkRRect *rrect)

        func setEmpty() {
            SkRRect_setEmpty(self.pointer)
        }
        // void SkRRect_setRect(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect)

        func setRect(rect: Skia.Rect) {
            SkRRect_setRect(self.pointer, rect.pointer)
        }
        // void SkRRect_setOval(void *rrect, const void *oval); // (SkRRect *rrect, const SkRect *oval)

        func setOval(oval: Skia.Rect) {
            SkRRect_setOval(self.pointer, oval.pointer)
        }
        // void SkRRect_setRectXY(void *rrect, const void *rect, float xRad, float yRad); // (SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad)

        func setRectXY(rect: Skia.Rect, xRad: Float, yRad: Float) {
            SkRRect_setRectXY(self.pointer, rect.pointer, xRad, yRad)
        }
        // void SkRRect_setNinePatch(void *rrect, const void *rect, float leftRad, float topRad, float rightRad, float bottomRad); // (SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad)
        
        func setNinePatch(rect: Skia.Rect, leftRad: Float, topRad: Float, rightRad: Float, bottomRad: Float) {
            SkRRect_setNinePatch(self.pointer, rect.pointer, leftRad, topRad, rightRad, bottomRad)
        }
        // void SkRRect_setRectRadii(void *rrect, const void *rect, const void * radii); // (SkRRect *rrect, const SkRect *rect, const SkVector radii[4])

        func setRectRadii(rect: Skia.Rect, radii: [Vector]) {
            let radiiPointer = radii.map { $0.pointer }
            SkRRect_setRectRadii(self.pointer, rect.pointer, radiiPointer)
        }
        // const void *SkRRect_rect(void *rrect); // (SkRRect *rrect) -> const SkRect *

        func rect() -> Skia.Rect {
            let pointer = SkRRect_rect(self.pointer)
            return Skia.Rect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: nil)
        }
        // int SkRRect_radii(void *rrect, int corner); // (SkRRect *rrect, SkRRect::Corner corner) -> sk_point_t

        func radii(corner: RRectCorner) -> Point {
            let handle = SkRRect_radii(self.pointer, corner.rawValue)
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // const void *SkRRect_getBounds(void *rrect); // (SkRRect *rrect) -> const SkRect *

        func getBounds() -> Skia.Rect {
            let pointer = SkRRect_getBounds(self.pointer)
            return Skia.Rect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: nil)
        }
        // void SkRRect_inset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)

        func inset(dx: Float, dy: Float, dst: RRect) {
            SkRRect_inset(self.pointer, dx, dy, dst.pointer)
        }
        // void SkRRect_inset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)

        func inset(dx: Float, dy: Float) {
            SkRRect_inset_2(self.pointer, dx, dy)
        }
        // void SkRRect_outset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)

        func outset(dx: Float, dy: Float, dst: RRect) {
            SkRRect_outset(self.pointer, dx, dy, dst.pointer)
        }
        // void SkRRect_outset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)

        func outset(dx: Float, dy: Float) {
            SkRRect_outset_2(self.pointer, dx, dy)
        }
        // void SkRRect_offset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)

        func offset(dx: Float, dy: Float) {
            SkRRect_offset(self.pointer, dx, dy)
        }
        // int SkRRect_makeOffset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy) -> sk_r_rect_t

        func makeOffset(dx: Float, dy: Float) -> RRect {
            let handle = SkRRect_makeOffset(self.pointer, dx, dy)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return RRect(pointer: pointer, handle: handle)
        }
        // bool SkRRect_contains(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect) -> bool

        func contains(rect: Skia.Rect) -> Bool {
            return SkRRect_contains(self.pointer, rect.pointer)
        }
        // bool SkRRect_isValid(void *rrect); // (SkRRect *rrect) -> bool

        func isValid() -> Bool {
            return SkRRect_isValid(self.pointer)
        }
        // unsigned long SkRRect_writeToMemory(void *rrect, void *buffer); // (SkRRect *rrect, void *buffer) -> size_t
        
        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkRRect_writeToMemory(self.pointer, buffer)
        }
        // unsigned long SkRRect_readFromMemory(void *rrect, const void *buffer, unsigned long length); // (SkRRect *rrect, const void *buffer, size_t length) -> size_t

        func readFromMemory(buffer: UnsafeRawPointer?, length: UInt) -> UInt {
            return SkRRect_readFromMemory(self.pointer, buffer, length)
        }
        // bool SkRRect_transform(void *rrect, const void *matrix, void *dst); // (SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst) -> bool

        func transform(matrix: Skia.Matrix, dst: RRect) -> Bool {
            return SkRRect_transform(self.pointer, matrix.pointer, dst.pointer)
        }
        // void SkRRect_dump(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex)

        func dump(asHex: Bool) {
            SkRRect_dump(self.pointer, asHex)
        }
        // int SkRRect_dumpToString(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex) -> sk_string_t

        func dumpToString(asHex: Bool) -> SkString {
            let handle = SkRRect_dumpToString(self.pointer, asHex)
            let pointer = static_sk_string_get_ptr(handle)
            return SkString(pointer: pointer, handle: handle)
        }
        // void SkRRect_dump_2(void *rrect); // (SkRRect *rrect)

        func dump() {
            SkRRect_dump_2(self.pointer)
        }
        // void SkRRect_dumpHex(void *rrect); // (SkRRect *rrect)

        func dumpHex() {
            SkRRect_dumpHex(self.pointer)
        }

        // // static

        init (pointer: Skia.RRectMutablePointer?, handle: sk_r_rect_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkRRect_MakeEmpty(); // () -> sk_r_rect_t

        static func MakeEmpty() -> RRect {
            let handle = SkRRect_MakeEmpty()
            let pointer = static_sk_r_rect_get_ptr(handle)
            return RRect(pointer: pointer, handle: handle)
        }

        // int SkRRect_MakeRect(const void *r); // (const SkRect *r) -> sk_r_rect_t

        static func MakeRect(r: Skia.Rect) -> RRect {
            let handle = SkRRect_MakeRect(r.pointer)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return RRect(pointer: pointer, handle: handle)
        }

        // int SkRRect_MakeOval(const void *oval); // (const SkRect *oval) -> sk_r_rect_t

        static func MakeOval(oval: Skia.Rect) -> RRect {
            let handle = SkRRect_MakeOval(oval.pointer)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return RRect(pointer: pointer, handle: handle)
        }

        // int SkRRect_MakeRectXY(const void *rect, float xRad, float yRad); // (const SkRect *rect, SkScalar xRad, SkScalar yRad) -> sk_r_rect_t

        static func MakeRectXY(rect: Skia.Rect, xRad: Float, yRad: Float) -> RRect {
            let handle = SkRRect_MakeRectXY(rect.pointer, xRad, yRad)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return RRect(pointer: pointer, handle: handle)
        }

    }
}