extension Skia {
    public enum SkRRectType: Int32 {
        case kEmpty_Type
        case kRect_Type
        case kOval_Type
        case kSimple_Type
        case kNinePatch_Type
        case kComplex_Type
        case kLastType
    }

    public enum SkRRectCorner: Int32 {
        case kUpperLeft_Corner
        case kUpperRight_Corner
        case kLowerRight_Corner
        case kLowerLeft_Corner
    }

    protocol SkRRectProtocol {
        var pointer: SkRRectMutablePointer? { get set }
        var handle: sk_r_rect_t { get set }
        // deinit // void SkRRect_delete(void *rrect); // (SkRRect *rrect)
        init(pointer: SkRRectMutablePointer?, handle: sk_r_rect_t)
        init() // void *SkRRect_new(); // () -> SkRRect *
        init(rrect: SkRRect) // void *SkRRect_new_2(const void *rrect); // (const SkRRect *rrect) -> SkRRect *
        // Static Methods
        static func MakeEmpty() -> SkRRect // int SkRRect_MakeEmpty(); // () -> sk_r_rect_t
        static func MakeRect(r: SkRect) -> SkRRect // int SkRRect_MakeRect(const SkRect *r); // (const SkRect *r) -> sk_r_rect_t
        static func MakeOval(oval: SkRect) -> SkRRect // int SkRRect_MakeOval(const SkRect *oval); // (const SkRect *oval) -> sk_r_rect_t
        static func MakeRectXY(rect: SkRect, xRad: Float, yRad: Float) -> SkRRect // int SkRRect_MakeRectXY(const SkRect *rect, SkScalar xRad, SkScalar yRad); // (const SkRect *rect, SkScalar xRad, SkScalar yRad) -> sk_r_rect_t
        // Methods
        func getType() -> SkRRectType // int getType(void *rrect); // (SkRRect *rrect) -> SkRRect::Type
        func type() -> SkRRectType // int type(void *rrect); // (SkRRect *rrect) -> SkRRect::Type
        func isEmpty() -> Bool // bool SkRRect_isEmpty(void *rrect); // (SkRRect *rrect) -> bool
        func isRect() -> Bool // bool SkRRect_isRect(void *rrect); // (SkRRect *rrect) -> bool
        func isOval() -> Bool // bool SkRRect_isOval(void *rrect); // (SkRRect *rrect) -> bool
        func isSimple() -> Bool // bool SkRRect_isSimple(void *rrect); // (SkRRect *rrect) -> bool
        func isNinePatch() -> Bool // bool SkRRect_isNinePatch(void *rrect); // (SkRRect *rrect) -> bool
        func isComplex() -> Bool // bool SkRRect_isComplex(void *rrect); // (SkRRect *rrect) -> bool
        func width() -> Float // float SkRRect_width(void *rrect); // (SkRRect *rrect) -> SkScalar
        func height() -> Float // float SkRRect_height(void *rrect); // (SkRRect *rrect) -> SkScalar
        func getSimpleRadii() -> SkPoint // int SkRRect_getSimpleRadii(void *rrect); // (SkRRect *rrect) -> sk_point_t
        func setEmpty() // void SkRRect_setEmpty(void *rrect); // (SkRRect *rrect)
        func setRect(rect: SkRect) // void SkRRect_setRect(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect)
        func setOval(oval: SkRect) // void SkRRect_setOval(void *rrect, const void *oval); // (SkRRect *rrect, const SkRect *oval)
        func setRectXY(rect: SkRect, xRad: Float, yRad: Float) // void SkRRect_setRectXY(void *rrect, const void *rect, float xRad, float yRad); // (SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad)
        func setNinePatch(rect: SkRect, leftRad: Float, topRad: Float, rightRad: Float, bottomRad: Float) // void SkRRect_setNinePatch(void *rrect, const void *rect, float leftRad, float topRad, float rightRad, float bottomRad); // (SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad)
        func setRectRadii(rect: SkRect, radii: [SkVector]) // void SkRRect_setRectRadii(void *rrect, const void *rect, const void * radii); // (SkRRect *rrect, const SkRect *rect, const SkVector radii[4])
        func rect() -> SkRect // const void *SkRRect_rect(void *rrect); // (SkRRect *rrect) -> const SkRect *
        func radii(corner: SkRRectCorner) -> SkPoint // int SkRRect_radii(void *rrect, int corner); // (SkRRect *rrect, SkRRect::Corner corner) -> sk_point_t
        func getBounds() -> SkRect // const void *SkRRect_getBounds(void *rrect); // (SkRRect *rrect) -> const SkRect *
        func inset(dx: Float, dy: Float, dst: SkRRect) // void SkRRect_inset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)
        func inset(dx: Float, dy: Float) // void SkRRect_inset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
        func outset(dx: Float, dy: Float, dst: SkRRect) // void SkRRect_outset(void *rrect, float dx, float dy, void *dst); // (SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst)
        func outset(dx: Float, dy: Float) // void SkRRect_outset_2(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
        func offset(dx: Float, dy: Float) // void SkRRect_offset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy)
        func makeOffset(dx: Float, dy: Float) -> SkRRect // int SkRRect_makeOffset(void *rrect, float dx, float dy); // (SkRRect *rrect, SkScalar dx, SkScalar dy) -> sk_r_rect_t
        func contains(rect: SkRect) -> Bool // bool SkRRect_contains(void *rrect, const void *rect); // (SkRRect *rrect, const SkRect *rect) -> bool
        func isValid() -> Bool // bool SkRRect_isValid(void *rrect); // (SkRRect *rrect) -> bool
        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt // unsigned long SkRRect_writeToMemory(void *rrect, void *buffer); // (SkRRect *rrect, void *buffer) -> size_t
        func readFromMemory(buffer: UnsafeRawPointer?, length: UInt) -> UInt // unsigned long SkRRect_readFromMemory(void *rrect, const void *buffer, unsigned long length); // (SkRRect *rrect, const void *buffer, size_t length) -> size_t
        func transform(matrix: SkMatrix, dst: SkRRect) -> Bool // bool SkRRect_transform(void *rrect, const void *matrix, void *dst); // (SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst) -> bool
        func dump(asHex: Bool) // void SkRRect_dump(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex)
        func dumpToString(asHex: Bool) -> SkString // int SkRRect_dumpToString(void *rrect, bool asHex); // (SkRRect *rrect, bool asHex) -> sk_string_t
        func dump() // void SkRRect_dump_2(void *rrect); // (SkRRect *rrect)
        func dumpHex() // void SkRRect_dumpHex(void *rrect); // (SkRRect *rrect)
    }

    class SkRRect : SkRRectProtocol {
        public var pointer: SkRRectMutablePointer?
        public var handle: sk_r_rect_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_r_rect_delete(self.handle)
            } else {
                SkRRect_delete(self.pointer)
            }
        }

        required init (pointer: SkRRectMutablePointer?, handle: sk_r_rect_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkRRect_new()
            self.handle = -1
        }

        required init(rrect: SkRRect) {
            self.pointer = SkRRect_new_2(rrect.pointer)
            self.handle = -1
        }

        // Static Methods

        static func MakeEmpty() -> SkRRect {
            let handle = SkRRect_MakeEmpty()
            let pointer = static_sk_r_rect_get_ptr(handle)
            return SkRRect(pointer: pointer, handle: handle)
        }

        static func MakeRect(r: SkRect) -> SkRRect {
            let handle = SkRRect_MakeRect(r.pointer)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return SkRRect(pointer: pointer, handle: handle)
        }

        static func MakeOval(oval: SkRect) -> SkRRect {
            let handle = SkRRect_MakeOval(oval.pointer)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return SkRRect(pointer: pointer, handle: handle)
        }

        static func MakeRectXY(rect: SkRect, xRad: Float, yRad: Float) -> SkRRect {
            let handle = SkRRect_MakeRectXY(rect.pointer, xRad, yRad)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return SkRRect(pointer: pointer, handle: handle)
        }

        // Methods

        func getType() -> SkRRectType {
            return SkRRectType(rawValue: Int32(SkRRect_getType(self.pointer)))!
        }

        func type() -> SkRRectType {
            return SkRRectType(rawValue: Int32(SkRRect_type(self.pointer)))!
        }

        func isEmpty() -> Bool {
            return SkRRect_isEmpty(self.pointer)
        }

        func isRect() -> Bool {
            return SkRRect_isRect(self.pointer)
        }

        func isOval() -> Bool {
            return SkRRect_isOval(self.pointer)
        }

        func isSimple() -> Bool {
            return SkRRect_isSimple(self.pointer)
        }

        func isNinePatch() -> Bool {
            return SkRRect_isNinePatch(self.pointer)
        }

        func isComplex() -> Bool {
            return SkRRect_isComplex(self.pointer)
        }

        func width() -> Float {
            return SkRRect_width(self.pointer)
        }

        func height() -> Float {
            return SkRRect_height(self.pointer)
        }

        func getSimpleRadii() -> SkPoint {
            let handle = SkRRect_getSimpleRadii(self.pointer)
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func setEmpty() {
            SkRRect_setEmpty(self.pointer)
        }

        func setRect(rect: SkRect) {
            SkRRect_setRect(self.pointer, rect.pointer)
        }

        func setOval(oval: SkRect) {
            SkRRect_setOval(self.pointer, oval.pointer)
        }

        func setRectXY(rect: SkRect, xRad: Float, yRad: Float) {
            SkRRect_setRectXY(self.pointer, rect.pointer, xRad, yRad)
        }

        func setNinePatch(rect: SkRect, leftRad: Float, topRad: Float, rightRad: Float, bottomRad: Float) {
            SkRRect_setNinePatch(self.pointer, rect.pointer, leftRad, topRad, rightRad, bottomRad)
        }

        func setRectRadii(rect: SkRect, radii: [SkVector]) {
            let radiiPointer = radii.map { $0.pointer }
            SkRRect_setRectRadii(self.pointer, rect.pointer, radiiPointer)
        }

        func rect() -> SkRect {
            let pointer = SkRRect_rect(self.pointer)
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func radii(corner: SkRRectCorner) -> SkPoint {
            let handle = SkRRect_radii(self.pointer, corner.rawValue)
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func getBounds() -> SkRect {
            let pointer = SkRRect_getBounds(self.pointer)
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func inset(dx: Float, dy: Float, dst: SkRRect) {
            SkRRect_inset(self.pointer, dx, dy, dst.pointer)
        }

        func inset(dx: Float, dy: Float) {
            SkRRect_inset_2(self.pointer, dx, dy)
        }

        func outset(dx: Float, dy: Float, dst: SkRRect) {
            SkRRect_outset(self.pointer, dx, dy, dst.pointer)
        }

        func outset(dx: Float, dy: Float) {
            SkRRect_outset_2(self.pointer, dx, dy)
        }

        func offset(dx: Float, dy: Float) {
            SkRRect_offset(self.pointer, dx, dy)
        }

        func makeOffset(dx: Float, dy: Float) -> SkRRect {
            let handle = SkRRect_makeOffset(self.pointer, dx, dy)
            let pointer = static_sk_r_rect_get_ptr(handle)
            return SkRRect(pointer: pointer, handle: handle)
        }

        func contains(rect: SkRect) -> Bool {
            return SkRRect_contains(self.pointer, rect.pointer)
        }

        func isValid() -> Bool {
            return SkRRect_isValid(self.pointer)
        }

        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkRRect_writeToMemory(self.pointer, buffer)
        }

        func readFromMemory(buffer: UnsafeRawPointer?, length: UInt) -> UInt {
            return SkRRect_readFromMemory(self.pointer, buffer, length)
        }

        func transform(matrix: SkMatrix, dst: SkRRect) -> Bool {
            return SkRRect_transform(self.pointer, matrix.pointer, dst.pointer)
        }

        func dump(asHex: Bool) {
            SkRRect_dump(self.pointer, asHex)
        }

        func dumpToString(asHex: Bool) -> SkString {
            let handle = SkRRect_dumpToString(self.pointer, asHex)
            let pointer = static_sk_string_get_ptr(handle)
            return SkString(pointer: pointer, handle: handle)
        }

        func dump() {
            SkRRect_dump_2(self.pointer)
        }

        func dumpHex() {
            SkRRect_dumpHex(self.pointer)
        }
    }
}