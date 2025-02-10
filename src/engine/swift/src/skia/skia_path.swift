extension Skia {
    public enum SkPathAddPathMode: Int32 {
       case append
       case extend
    }

    public enum SkPathArcSize: Int32 {
        case small
        case large
    }

    protocol SkPathProtocol {
        var pointer: Skia.SkPathMutablePointer? { get set }
        var handle: sk_path_t { get set }
        // deinit // void SkPath_delete(void *path); // (SkPath *path)
        init(pointer: Skia.SkPathMutablePointer?, handle: sk_path_t)
        init() // void *SkPath_new(); // () -> SkPath *
        init(path: SkPath) // void *SkPath_new_2(const void *path); // (const SkPath *path) -> SkPath *
        // Static Methods
        static func Make(point: [SkPoint], i: [UInt8], v: [Float], conicWeightCount: Int, type: SkPathFillType, isVolatile: Bool) -> SkPath // int SkPath_Make(const void * point, int pointCount, const void * i, int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile); // (const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile) -> sk_path_t
        static func Rect(rect: SkRect, dir: SkPathDirection, startIndex: UInt) -> SkPath // int SkPath_Rect(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
        static func Oval(rect: SkRect, dir: SkPathDirection) -> SkPath // int SkPath_Oval(const void *rect, int dir); // (const SkRect *rect, SkPathDirection dir) -> sk_path_t
        static func Oval(rect: SkRect, dir: SkPathDirection, startIndex: UInt) -> SkPath // int SkPath_Oval_2(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
        static func Circle(center_x: Float, center_y: Float, radius: Float, dir: SkPathDirection) -> SkPath // int SkPath_Circle(float center_x, float center_y, float radius, int dir); // (SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) -> sk_path_t
        static func RRect(rrect: SkRRect, dir: SkPathDirection) -> SkPath // int SkPath_RRect(const void *rrect, int dir); // (const SkRRect *rrect, SkPathDirection dir) -> sk_path_t
        static func RRect(rrect: SkRRect, dir: SkPathDirection, startIndex: UInt) -> SkPath // int SkPath_RRect_2(const void *rrect, int dir, unsigned startIndex); // (const SkRRect *rrect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
        static func RRect(bounds: SkRect, rx: Float, ry: Float, dir: SkPathDirection) -> SkPath // int SkPath_RRect_3(const void *bounds, float rx, float ry, int dir); // (const SkRect *bounds, SkScalar rx, SkScalar ry, SkPathDirection dir) -> sk_path_t
        static func Polygon(pts: [SkPoint], isClosed: Bool, type: SkPathFillType, isVolatile: Bool) -> SkPath // int SkPath_Polygon(const void * pts, int count, bool isClosed, int type, bool isVolatile); // (const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile) -> sk_path_t
        static func Polygon(list: [SkPoint], isClosed: Bool, fillType: SkPathFillType, isVolatile: Bool) -> SkPath // int SkPath_Polygon_2(const void *list, bool isClosed, int fillType, bool isVolatile); // (const std::initializer_list<SkPoint> *list, bool isClosed, SkPathFillType fillType, bool isVolatile) -> sk_path_t
        static func Line(a: SkPoint, b: SkPoint) -> SkPath // int SkPath_Line(int a, int b); // (sk_point_t a, sk_point_t b) -> sk_path_t
        static func IsLineDegenerate(p1: SkPoint, p2: SkPoint, exact: Bool) -> Bool // bool SkPath_IsLineDegenerate(const void *p1, const void *p2, bool exact); // (const SkPoint *p1, const SkPoint *p2, bool exact) -> bool
        static func IsQuadDegenerate(p1: SkPoint, p2: SkPoint, p3: SkPoint, exact: Bool) -> Bool // bool SkPath_IsQuadDegenerate(const void *p1, const void *p2, const void *p3, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, bool exact) -> bool
        static func IsCubicDegenerate(p1: SkPoint, p2: SkPoint, p3: SkPoint, p4: SkPoint, exact: Bool) -> Bool // bool SkPath_IsCubicDegenerate(const void *p1, const void *p2, const void *p3, const void *p4, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, const SkPoint *p4, bool exact) -> bool
        static func ConvertConicToQuads(p0: SkPoint, p1: SkPoint, p2: SkPoint, w: Float, pts: [SkPoint], pow2: Int) -> Int // int SkPath_ConvertConicToQuads(const void *p0, const void *p1, const void *p2, float w, void * pts, int pow2); // (const SkPoint *p0, const SkPoint *p1, const SkPoint *p2, SkScalar w, SkPoint pts[], int pow2) -> int
        // Methods
        func isInterpolatable(compare: SkPath) -> Bool // bool SkPath_isInterpolatable(void *path, const void *compare); // (SkPath *path, const SkPath *compare) -> bool
        func interpolate(ending: SkPath, weight: Float, out: SkPath) -> Bool // bool SkPath_interpolate(void *path, const void *ending, float weight, void *out); // (SkPath *path, const SkPath *ending, SkScalar weight, SkPath *out) -> bool
        func getFillType() -> SkPathFillType // int SkPath_getFillType(void *path); // (SkPath *path) -> SkPathFillType
        func setFillType(ft: SkPathFillType) // void SkPath_setFillType(void *path, int ft); // (SkPath *path, SkPathFillType ft)
        func isInverseFillType() -> Bool // bool SkPath_isInverseFillType(void *path); // (SkPath *path) -> bool
        func toggleInverseFillType() // void SkPath_toggleInverseFillType(void *path); // (SkPath *path)
        func isConvex() -> Bool // bool SkPath_isConvex(void *path); // (SkPath *path) -> bool
        func isOval(bounds: SkRect) -> Bool // bool SkPath_isOval(void *path, void *bounds); // (SkPath *path, SkRect *bounds) -> bool
        func isRRect(rrect: SkRRect) -> Bool // bool SkPath_isRRect(void *path, void *rrect); // (SkPath *path, SkRRect *rrect) -> bool
        func reset() -> SkPath // void *SkPath_reset(void *path); // (SkPath *path) -> SkPath *
        func rewind() -> SkPath // void *SkPath_rewind(void *path); // (SkPath *path) -> SkPath *
        func isEmpty() -> Bool // bool SkPath_isEmpty(void *path); // (SkPath *path) -> bool
        func isLastContourClosed() -> Bool // bool SkPath_isLastContourClosed(void *path); // (SkPath *path) -> bool
        func isFinite() -> Bool // bool SkPath_isFinite(void *path); // (SkPath *path) -> bool
        func isVolatile() -> Bool // bool SkPath_isVolatile(void *path); // (SkPath *path) -> bool
        func setIsVolatile(isVolatile: Bool) -> SkPath // void *SkPath_setIsVolatile(void *path, bool isVolatile); // (SkPath *path, bool isVolatile) -> SkPath *
        func isLine(line: [SkPoint]) -> Bool // bool SkPath_isLine(void *path, void * line); // (SkPath *path, SkPoint line[2]) -> bool
        func countPoints() -> Int // int SkPath_countPoints(void *path); // (SkPath *path) -> int
        func getPoint(index: Int) -> SkPoint // int SkPath_getPoint(void *path, int index); // (SkPath *path, int index) -> sk_point_t
        func getPoints(points: [SkPoint], max: Int) -> Int // int SkPath_getPoints(void *path, void * points, int max); // (SkPath *path, SkPoint points[], int max) -> int
        func countVerbs() -> Int // int SkPath_countVerbs(void *path); // (SkPath *path) -> int
        func getVerbs(verbs: [UInt8], max: Int) -> Int // int SkPath_getVerbs(void *path, void * verbs, int max); // (SkPath *path, uint8_t verbs[], int max) -> int
        func approximateBytesUsed() -> UInt // unsigned long SkPath_approximateBytesUsed(void *path); // (SkPath *path) -> size_t
        func swap(other: SkPath) // void SkPath_swap(void *path, void *other); // (SkPath *path, SkPath *other)
        func getBounds() -> SkRect // const void *SkPath_getBounds(void *path); // (SkPath *path) -> const SkRect *
        func updateBoundsCache() // void SkPath_updateBoundsCache(void *path); // (SkPath *path)
        func computeTightBounds() -> SkRect // int SkPath_computeTightBounds(void *path); // (SkPath *path) -> sk_rect_t
        func conservativelyContainsRect(rect: SkRect) -> Bool // bool SkPath_conservativelyContainsRect(void *path, const void *rect); // (SkPath *path, const SkRect *rect) -> bool
        func incReserve(extraPtCount: Int) // void SkPath_incReserve(void *path, int extraPtCount); // (SkPath *path, int extraPtCount)
        func moveTo(x: Float, y: Float) -> SkPath // void *SkPath_moveTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *
        func moveTo(p: SkPoint) -> SkPath // void *SkPath_moveTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *
        func rMoveTo(dx: Float, dy: Float) -> SkPath // void *SkPath_rMoveTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *
        func lineTo(x: Float, y: Float) -> SkPath // void *SkPath_lineTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *
        func lineTo(p: SkPoint) -> SkPath // void *SkPath_lineTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *
        func rLineTo(dx: Float, dy: Float) -> SkPath // void *SkPath_rLineTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *
        func quadTo(x1: Float, y1: Float, x2: Float, y2: Float) -> SkPath // void *SkPath_quadTo(void *path, float x1, float y1, float x2, float y2); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) -> SkPath *
        func quadTo(p1: SkPoint, p2: SkPoint) -> SkPath // void *SkPath_quadTo_2(void *path, const void *p1, const void *p2); // (SkPath *path, const SkPoint *p1, const SkPoint *p2) -> SkPath *
        func rQuadTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float) -> SkPath // void *SkPath_rQuadTo(void *path, float dx1, float dy1, float dx2, float dy2); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2) -> SkPath *
        func conicTo(x1: Float, y1: Float, x2: Float, y2: Float, w: Float) -> SkPath // void *SkPath_conicTo(void *path, float x1, float y1, float x2, float y2, float w); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) -> SkPath *
        func conicTo(p1: SkPoint, p2: SkPoint, w: Float) -> SkPath // void *SkPath_conicTo_2(void *path, const void *p1, const void *p2, float w); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, SkScalar w) -> SkPath *
        func rConicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, w: Float) -> SkPath // void *SkPath_rConicTo(void *path, float dx1, float dy1, float dx2, float dy2, float w); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w) -> SkPath *
        func cubicTo(x1: Float, y1: Float, x2: Float, y2: Float, x3: Float, y3: Float) -> SkPath // void *SkPath_cubicTo(void *path, float x1, float y1, float x2, float y2, float x3, float y3); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) -> SkPath *
        func cubicTo(p1: SkPoint, p2: SkPoint, p3: SkPoint) -> SkPath // void *SkPath_cubicTo_2(void *path, const void *p1, const void *p2, const void *p3); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, const SkPoint *p3) -> SkPath *
        func rCubicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, dx3: Float, dy3: Float) -> SkPath // void *SkPath_rCubicTo(void *path, float dx1, float dy1, float dx2, float dy2, float dx3, float dy3); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3) -> SkPath *
        func arcTo(oval: SkRect, startAngle: Float, sweepAngle: Float, forceMoveTo: Bool) -> SkPath // void *SkPath_arcTo(void *path, const void *oval, float startAngle, float sweepAngle, bool forceMoveTo); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo) -> SkPath *
        func arcTo(x1: Float, y1: Float, x2: Float, y2: Float, radius: Float) -> SkPath // void *SkPath_arcTo_2(void *path, float x1, float y1, float x2, float y2, float radius); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius) -> SkPath *
        func arcTo(p1: SkPoint, p2: SkPoint, radius: Float) -> SkPath // void *SkPath_arcTo_3(void *path, int p1, int p2, float radius); // (SkPath *path, sk_point_t p1, sk_point_t p2, SkScalar radius) -> SkPath *
        func arcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, x: Float, y: Float) -> SkPath // void *SkPath_arcTo_4(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float x, float y); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y) -> SkPath *
        func arcTo(r: SkPoint, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, xy: SkPoint) -> SkPath // void *SkPath_arcTo_5(void *path, int r, float xAxisRotate, int largeArc, int sweep, int xy); // (SkPath *path, sk_point_t r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) -> SkPath *
        func rArcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, dx: Float, dy: Float) -> SkPath // void *SkPath_rArcTo(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float dx, float dy); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy) -> SkPath *
        func close() -> SkPath // void *SkPath_close(void *path); // (SkPath *path) -> SkPath *
        func isRect(rect: SkRect, isClosed: UnsafeMutablePointer<Bool>?, direction: [SkPathDirection]) -> Bool // bool SkPath_isRect(void *path, void *rect, void *isClosed, void *direction); // (SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction) -> bool
        func addRect(rect: SkRect, dir: SkPathDirection, start: UInt) -> SkPath // void *SkPath_addRect(void *path, const void *rect, int dir, unsigned start); // (SkPath *path, const SkRect *rect, SkPathDirection dir, unsigned start) -> SkPath *
        func addRect(rect: SkRect, dir: SkPathDirection) -> SkPath // void *SkPath_addRect_2(void *path, const void *rect, int dir); // (SkPath *path, const SkRect *rect, SkPathDirection dir) -> SkPath *
        func addRect(left: Float, top: Float, right: Float, bottom: Float, dir: SkPathDirection) -> SkPath // void *SkPath_addRect_3(void *path, float left, float top, float right, float bottom, int dir); // (SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir) -> SkPath *
        func addOval(oval: SkRect, dir: SkPathDirection) -> SkPath // void *SkPath_addOval(void *path, const void *oval, int dir); // (SkPath *path, const SkRect *oval, SkPathDirection dir) -> SkPath *
        func addOval(oval: SkRect, dir: SkPathDirection, start: UInt) -> SkPath // void *SkPath_addOval_2(void *path, const void *oval, int dir, unsigned start); // (SkPath *path, const SkRect *oval, SkPathDirection dir, unsigned start) -> SkPath *
        func addCircle(x: Float, y: Float, radius: Float, dir: SkPathDirection) -> SkPath // void *SkPath_addCircle(void *path, float x, float y, float radius, int dir); // (SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir) -> SkPath *
        func addArc(oval: SkRect, startAngle: Float, sweepAngle: Float) -> SkPath // void *SkPath_addArc(void *path, const void *oval, float startAngle, float sweepAngle); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle) -> SkPath *
        func addRoundRect(rect: SkRect, rx: Float, ry: Float, dir: SkPathDirection) -> SkPath // void *SkPath_addRoundRect(void *path, const void *rect, float rx, float ry, int dir); // (SkPath *path, const SkRect *rect, SkScalar rx, SkScalar ry, SkPathDirection dir) -> SkPath *
        func addRoundRect(rect: SkRect, radii: [Float], dir: SkPathDirection) -> SkPath // void *SkPath_addRoundRect_2(void *path, const void *rect, const void * radii, int dir); // (SkPath *path, const SkRect *rect, const SkScalar radii[], SkPathDirection dir) -> SkPath *
        func addRRect(rrect: SkRRect, dir: SkPathDirection) -> SkPath // void *SkPath_addRRect(void *path, const void *rrect, int dir); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir) -> SkPath *
        func addRRect(rrect: SkRRect, dir: SkPathDirection, start: UInt) -> SkPath // void *SkPath_addRRect_2(void *path, const void *rrect, int dir, unsigned start); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir, unsigned start) -> SkPath *
        func addPoly(pts: [SkPoint], close: Bool) -> SkPath // void *SkPath_addPoly(void *path, const void * pts, int count, bool close); // (SkPath *path, const SkPoint pts[], int count, bool close) -> SkPath *
        // void *SkPath_addPoly_2(void *path, const void *list, bool close); // (SkPath *path, const std::initializer_list<SkPoint> *list, bool close) -> SkPath *
        func addPath(src: SkPath, dx: Float, dy: Float, mode: SkPathAddPathMode) -> SkPath // void *SkPath_addPath(void *path, const void *src, float dx, float dy, int mode); // (SkPath *path, const SkPath *src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode) -> SkPath *
        func addPath(src: SkPath, modeSkPath: SkPathAddPathMode) -> SkPath // void *SkPath_addPath_2(void *path, const void *src, int modeSkPath); // (SkPath *path, const SkPath *src, SkPath::AddPathMode modeSkPath) -> SkPath *
        func addPath(src: SkPath, matrix: SkMatrix, mode: SkPathAddPathMode) -> SkPath // void *SkPath_addPath_3(void *path, const void *src, const void *matrix, int mode); // (SkPath *path, const SkPath *src, const SkMatrix *matrix, SkPath::AddPathMode mode) -> SkPath *
        func reverseAddPath(src: SkPath) -> SkPath // void *SkPath_reverseAddPath(void *path, const void *src); // (SkPath *path, const SkPath *src) -> SkPath *
        func offset(dx: Float, dy: Float, dst: SkPath) // void SkPath_offset(void *path, float dx, float dy, void *dst); // (SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst)
        func offset(dx: Float, dy: Float) // void SkPath_offset_2(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy)
        func transform(matrix: SkMatrix, dst: SkPath, pc: SkApplyPerspectiveClip) // void SkPath_transform(void *path, const void *matrix, void *dst, int pc); // (SkPath *path, const SkMatrix *matrix, SkPath *dst, SkApplyPerspectiveClip pc)
        func transform(matrix: SkMatrix, pc: SkApplyPerspectiveClip) // void SkPath_transform_2(void *path, const void *matrix, int pc); // (SkPath *path, const SkMatrix *matrix, SkApplyPerspectiveClip pc)
        func makeTransform(m: SkMatrix, pc: SkApplyPerspectiveClip) -> SkPath // int SkPath_makeTransform(void *path, const void *m, int pc); // (SkPath *path, const SkMatrix *m, SkApplyPerspectiveClip pc) -> sk_path_t
        func makeScale(sx: Float, sy: Float) -> SkPath // int SkPath_makeScale(void *path, float sx, float sy); // (SkPath *path, SkScalar sx, SkScalar sy) -> sk_path_t
        func getLastPt(lastPt: SkPoint) -> Bool // bool SkPath_getLastPt(void *path, void *lastPt); // (SkPath *path, SkPoint *lastPt) -> bool
        func setLastPt(x: Float, y: Float) // void SkPath_setLastPt(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y)
        func setLastPt(p: SkPoint) // void SkPath_setLastPt_2(void *path, const void *p); // (SkPath *path, const SkPoint *p)
        func getSegmentMasks() -> UInt // unsigned int SkPath_getSegmentMasks(void *path); // (SkPath *path) -> uint32_t
        func contains(x: Float, y: Float) -> Bool // bool SkPath_contains(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> bool
        func dump(stream: SkWStream, dumpAsHex: Bool) // void SkPath_dump(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)
        func dump() // void SkPath_dump_2(void *path); // (SkPath *path)
        func dumpHex() // void SkPath_dumpHex(void *path); // (SkPath *path)
        func dumpArrays(stream: SkWStream, dumpAsHex: Bool) // void SkPath_dumpArrays(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)
        func dumpArrays() // void SkPath_dumpArrays_2(void *path); // (SkPath *path)
        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt // unsigned long SkPath_writeToMemory(void *path, void *buffer); // (SkPath *path, void *buffer) -> size_t
        func serialize() -> Skia.Data // int SkPath_serialize(void *path); // (SkPath *path) -> sk_data_t
        func readFromMemory(buffer: UnsafeRawPointer, length: UInt) -> UInt // unsigned long SkPath_readFromMemory(void *path, const void *buffer, unsigned long length); // (SkPath *path, const void *buffer, size_t length) -> size_t
        func getGenerationID() -> UInt // unsigned int SkPath_getGenerationID(void *path); // (SkPath *path) -> uint32_t
        func isValid() -> Bool // bool SkPath_isValid(void *path); // (SkPath *path) -> bool
    }

    class SkPath : SkPathProtocol {
        public var pointer: Skia.SkPathMutablePointer?
        public var handle: sk_path_t = -1

        deinit {
            SkPath_delete(self.pointer)
            if handle > -1 {
                static_sk_path_delete(handle)
            }
        }

        required init(pointer: Skia.SkPathMutablePointer?, handle: sk_path_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkPath_new();
            self.handle = -1
        }

        required init(path: SkPath) {
            self.pointer = SkPath_new_2(path.pointer);
            self.handle = -1
        }

        // Static Methods

        static func Make(point: [SkPoint], i: [UInt8], v: [Float], conicWeightCount: Int, type: SkPathFillType, isVolatile: Bool) -> SkPath {
            return point.withUnsafeBufferPointer { pointBuffer in
                i.withUnsafeBufferPointer { iBuffer in
                    v.withUnsafeBufferPointer { vBuffer in
                        let handle = SkPath_Make(UnsafeMutableRawPointer(mutating: pointBuffer.baseAddress), Int32(point.count), UnsafeMutableRawPointer(mutating: iBuffer.baseAddress), Int32(i.count), UnsafeMutableRawPointer(mutating: vBuffer.baseAddress), Int32(conicWeightCount), type.rawValue, isVolatile)
                        let pointer = static_sk_path_get_ptr(handle)
                        return SkPath(pointer: pointer, handle: handle)
                    }
                }
            }
        }

        static func Rect(rect: SkRect, dir: SkPathDirection, startIndex: UInt) -> SkPath {
            let handle = SkPath_Rect(rect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func Oval(rect: SkRect, dir: SkPathDirection) -> SkPath {
            let handle = SkPath_Oval(rect.pointer, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func Oval(rect: SkRect, dir: SkPathDirection, startIndex: UInt) -> SkPath {
            let handle = SkPath_Oval_2(rect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func Circle(center_x: Float, center_y: Float, radius: Float, dir: SkPathDirection) -> SkPath {
            let handle = SkPath_Circle(center_x, center_y, radius, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func RRect(rrect: SkRRect, dir: SkPathDirection) -> SkPath {
            let handle = SkPath_RRect(rrect.pointer, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func RRect(rrect: SkRRect, dir: SkPathDirection, startIndex: UInt) -> SkPath {
            let handle = SkPath_RRect_2(rrect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func RRect(bounds: SkRect, rx: Float, ry: Float, dir: SkPathDirection) -> SkPath {
            let handle = SkPath_RRect_3(bounds.pointer, rx, ry, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func Polygon(pts: [SkPoint], isClosed: Bool, type: SkPathFillType, isVolatile: Bool) -> SkPath {
            return pts.withUnsafeBufferPointer { buffer in
                let handle = SkPath_Polygon(UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pts.count), isClosed, type.rawValue, isVolatile)
                let pointer = static_sk_path_get_ptr(handle)
                return SkPath(pointer: pointer, handle: handle)
            }
        }

        static func Polygon(list: [SkPoint], isClosed: Bool, fillType: SkPathFillType, isVolatile: Bool) -> SkPath {
            return list.withUnsafeBufferPointer { buffer in
                let handle = SkPath_Polygon_2(UnsafeMutableRawPointer(mutating: buffer.baseAddress), isClosed, fillType.rawValue, isVolatile)
                let pointer = static_sk_path_get_ptr(handle)
                return SkPath(pointer: pointer, handle: handle)
            }
        }

        static func Line(a: SkPoint, b: SkPoint) -> SkPath {
            let handle = SkPath_Line(a.handle, b.handle)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        static func IsLineDegenerate(p1: SkPoint, p2: SkPoint, exact: Bool) -> Bool {
            return SkPath_IsLineDegenerate(p1.pointer, p2.pointer, exact)
        }

        static func IsQuadDegenerate(p1: SkPoint, p2: SkPoint, p3: SkPoint, exact: Bool) -> Bool {
            return SkPath_IsQuadDegenerate(p1.pointer, p2.pointer, p3.pointer, exact)
        }

        static func IsCubicDegenerate(p1: SkPoint, p2: SkPoint, p3: SkPoint, p4: SkPoint, exact: Bool) -> Bool {
            return SkPath_IsCubicDegenerate(p1.pointer, p2.pointer, p3.pointer, p4.pointer, exact)
        }

        static func ConvertConicToQuads(p0: SkPoint, p1: SkPoint, p2: SkPoint, w: Float, pts: [SkPoint], pow2: Int) -> Int {
            return pts.withUnsafeBufferPointer { buffer in
                return Int(SkPath_ConvertConicToQuads(p0.pointer, p1.pointer, p2.pointer, w, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pow2)))
            }
        }

        // Methods

        func isInterpolatable(compare: SkPath) -> Bool {
            return SkPath_isInterpolatable(self.pointer, compare.pointer)
        }

        func interpolate(ending: SkPath, weight: Float, out: SkPath) -> Bool {
            return SkPath_interpolate(self.pointer, ending.pointer, weight, out.pointer)
        }

        func getFillType() -> SkPathFillType {
            return SkPathFillType(rawValue: SkPath_getFillType(self.pointer))!
        }

        func setFillType(ft: SkPathFillType) {
            SkPath_setFillType(self.pointer, ft.rawValue)
        }

        func isInverseFillType() -> Bool {
            return SkPath_isInverseFillType(self.pointer)
        }

        func toggleInverseFillType() {
            SkPath_toggleInverseFillType(self.pointer)
        }

        func isConvex() -> Bool {
            return SkPath_isConvex(self.pointer)
        }

        func isOval(bounds: SkRect) -> Bool {
            return SkPath_isOval(self.pointer, bounds.pointer)
        }

        func isRRect(rrect: SkRRect) -> Bool {
            return SkPath_isRRect(self.pointer, rrect.pointer)
        }

        func reset() -> SkPath {
            let pointer = SkPath_reset(self.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rewind() -> SkPath {
            let pointer = SkPath_rewind(self.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func isEmpty() -> Bool {
            return SkPath_isEmpty(self.pointer)
        }

        func isLastContourClosed() -> Bool {
            return SkPath_isLastContourClosed(self.pointer)
        }

        func isFinite() -> Bool {
            return SkPath_isFinite(self.pointer)
        }

        func isVolatile() -> Bool {
            return SkPath_isVolatile(self.pointer)
        }

        func setIsVolatile(isVolatile: Bool) -> SkPath {
            let pointer = SkPath_setIsVolatile(self.pointer, isVolatile);
            return SkPath(pointer: pointer, handle: -1)
        }

        func isLine(line: [SkPoint]) -> Bool {
            return line.withUnsafeBufferPointer { buffer in
                SkPath_isLine(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress))
            }
        }

        func countPoints() -> Int {
            return Int(SkPath_countPoints(self.pointer))
        }

        func getPoint(index: Int) -> SkPoint {
            let handle = SkPath_getPoint(self.pointer, Int32(index))
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func getPoints(points: [SkPoint], max: Int) -> Int {
            return points.withUnsafeBufferPointer { (buffer: UnsafeBufferPointer<SkPoint>) -> Int in
                return Int(SkPath_getPoints(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(max)))
            }
        }

        func countVerbs() -> Int {
            return Int(SkPath_countVerbs(self.pointer))
        }

        func getVerbs(verbs: [UInt8], max: Int) -> Int {
            return verbs.withUnsafeBufferPointer { (buffer: UnsafeBufferPointer<UInt8>) -> Int in
                return Int(SkPath_getVerbs(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(max)))
            }
        }

        func approximateBytesUsed() -> UInt {
            return SkPath_approximateBytesUsed(self.pointer)
        }

        func swap(other: SkPath) {
            SkPath_swap(self.pointer, other.pointer)
        }

        func getBounds() -> SkRect {
            let pointer = SkPath_getBounds(self.pointer)
            return Skia.SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func updateBoundsCache() {
            SkPath_updateBoundsCache(self.pointer)
        }

        func computeTightBounds() -> SkRect {
            let handle = SkPath_computeTightBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return Skia.SkRect(pointer: pointer, handle: handle)
        }

        func conservativelyContainsRect(rect: SkRect) -> Bool {
            return SkPath_conservativelyContainsRect(self.pointer, rect.pointer)
        }

        func incReserve(extraPtCount: Int) {
            SkPath_incReserve(self.pointer, Int32(extraPtCount))
        }

        func moveTo(x: Float, y: Float) -> SkPath {
            let pointer = SkPath_moveTo(self.pointer, x, y);
            return SkPath(pointer: pointer, handle: -1)
        }

        func moveTo(p: SkPoint) -> SkPath {
            let pointer = SkPath_moveTo_2(self.pointer, p.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rMoveTo(dx: Float, dy: Float) -> SkPath {
            let pointer = SkPath_rMoveTo(self.pointer, dx, dy);
            return SkPath(pointer: pointer, handle: -1)
        }

        func lineTo(x: Float, y: Float) -> SkPath {
            let pointer = SkPath_lineTo(self.pointer, x, y);
            return SkPath(pointer: pointer, handle: -1)
        }

        func lineTo(p: SkPoint) -> SkPath {
            let pointer = SkPath_lineTo_2(self.pointer, p.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rLineTo(dx: Float, dy: Float) -> SkPath {
            let pointer = SkPath_rLineTo(self.pointer, dx, dy);
            return SkPath(pointer: pointer, handle: -1)
        }

        func quadTo(x1: Float, y1: Float, x2: Float, y2: Float) -> SkPath {
            let pointer = SkPath_quadTo(self.pointer, x1, y1, x2, y2);
            return SkPath(pointer: pointer, handle: -1)
        }

        func quadTo(p1: SkPoint, p2: SkPoint) -> SkPath {
            let pointer = SkPath_quadTo_2(self.pointer, p1.pointer, p2.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rQuadTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float) -> SkPath {
            let pointer = SkPath_rQuadTo(self.pointer, dx1, dy1, dx2, dy2);
            return SkPath(pointer: pointer, handle: -1)
        }

        func conicTo(x1: Float, y1: Float, x2: Float, y2: Float, w: Float) -> SkPath {
            let pointer = SkPath_conicTo(self.pointer, x1, y1, x2, y2, w);
            return SkPath(pointer: pointer, handle: -1)
        }

        func conicTo(p1: SkPoint, p2: SkPoint, w: Float) -> SkPath {
            let pointer = SkPath_conicTo_2(self.pointer, p1.pointer, p2.pointer, w);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rConicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, w: Float) -> SkPath {
            let pointer = SkPath_rConicTo(self.pointer, dx1, dy1, dx2, dy2, w);
            return SkPath(pointer: pointer, handle: -1)
        }

        func cubicTo(x1: Float, y1: Float, x2: Float, y2: Float, x3: Float, y3: Float) -> SkPath {
            let pointer = SkPath_cubicTo(self.pointer, x1, y1, x2, y2, x3, y3);
            return SkPath(pointer: pointer, handle: -1)
        }

        func cubicTo(p1: SkPoint, p2: SkPoint, p3: SkPoint) -> SkPath {
            let pointer = SkPath_cubicTo_2(self.pointer, p1.pointer, p2.pointer, p3.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rCubicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, dx3: Float, dy3: Float) -> SkPath {
            let pointer = SkPath_rCubicTo(self.pointer, dx1, dy1, dx2, dy2, dx3, dy3);
            return SkPath(pointer: pointer, handle: -1)
        }

        func arcTo(oval: SkRect, startAngle: Float, sweepAngle: Float, forceMoveTo: Bool) -> SkPath {
            let pointer = SkPath_arcTo(self.pointer, oval.pointer, startAngle, sweepAngle, forceMoveTo);
            return SkPath(pointer: pointer, handle: -1)
        }

        func arcTo(x1: Float, y1: Float, x2: Float, y2: Float, radius: Float) -> SkPath {
            let pointer = SkPath_arcTo_2(self.pointer, x1, y1, x2, y2, radius);
            return SkPath(pointer: pointer, handle: -1)
        }

        func arcTo(p1: SkPoint, p2: SkPoint, radius: Float) -> SkPath {
            let pointer = SkPath_arcTo_3(self.pointer, p1.handle, p2.handle, radius);
            return SkPath(pointer: pointer, handle: -1)
        }

        func arcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, x: Float, y: Float) -> SkPath {
            let pointer = SkPath_arcTo_4(self.pointer, rx, ry, xAxisRotate, largeArc.rawValue, sweep.rawValue, x, y);
            return SkPath(pointer: pointer, handle: -1)
        }

        func arcTo(r: SkPoint, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, xy: SkPoint) -> SkPath {
            let pointer = SkPath_arcTo_5(self.pointer, r.handle, xAxisRotate, largeArc.rawValue, sweep.rawValue, xy.handle);
            return SkPath(pointer: pointer, handle: -1)
        }

        func rArcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: SkPathArcSize, sweep: SkPathDirection, dx: Float, dy: Float) -> SkPath {
            let pointer = SkPath_rArcTo(self.pointer, rx, ry, xAxisRotate, largeArc.rawValue, sweep.rawValue, dx, dy);
            return SkPath(pointer: pointer, handle: -1)
        }

        func close() -> SkPath {
            let pointer = SkPath_close(self.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func isRect(rect: SkRect, isClosed: UnsafeMutablePointer<Bool>?, direction: [SkPathDirection]) -> Bool {
            return direction.withUnsafeBufferPointer { buffer in
                SkPath_isRect(self.pointer, rect.pointer, isClosed, UnsafeMutableRawPointer(mutating: buffer.baseAddress))
            }
        }

        func addRect(rect: SkRect, dir: SkPathDirection, start: UInt) -> SkPath {
            let pointer = SkPath_addRect(self.pointer, rect.pointer, dir.rawValue, UInt32(start));
            return SkPath(pointer: pointer, handle: -1)
        }

        func addRect(rect: SkRect, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addRect_2(self.pointer, rect.pointer, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addRect(left: Float, top: Float, right: Float, bottom: Float, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addRect_3(self.pointer, left, top, right, bottom, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addOval(oval: SkRect, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addOval(self.pointer, oval.pointer, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addOval(oval: SkRect, dir: SkPathDirection, start: UInt) -> SkPath {
            let pointer = SkPath_addOval_2(self.pointer, oval.pointer, dir.rawValue, UInt32(start));
            return SkPath(pointer: pointer, handle: -1)
        }

        func addCircle(x: Float, y: Float, radius: Float, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addCircle(self.pointer, x, y, radius, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addArc(oval: SkRect, startAngle: Float, sweepAngle: Float) -> SkPath {
            let pointer = SkPath_addArc(self.pointer, oval.pointer, startAngle, sweepAngle);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addRoundRect(rect: SkRect, rx: Float, ry: Float, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addRoundRect(self.pointer, rect.pointer, rx, ry, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addRoundRect(rect: SkRect, radii: [Float], dir: SkPathDirection) -> SkPath {
            return radii.withUnsafeBufferPointer { buffer in
                let pointer = SkPath_addRoundRect_2(self.pointer, rect.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), dir.rawValue);
                return SkPath(pointer: pointer, handle: -1)
            }
        }

        func addRRect(rrect: SkRRect, dir: SkPathDirection) -> SkPath {
            let pointer = SkPath_addRRect(self.pointer, rrect.pointer, dir.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addRRect(rrect: SkRRect, dir: SkPathDirection, start: UInt) -> SkPath {
            let pointer = SkPath_addRRect_2(self.pointer, rrect.pointer, dir.rawValue, UInt32(start));
            return SkPath(pointer: pointer, handle: -1)
        }

        func addPoly(pts: [SkPoint], close: Bool) -> SkPath {
            return pts.withUnsafeBufferPointer { buffer in
                let pointer = SkPath_addPoly(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pts.count), close);
                return SkPath(pointer: pointer, handle: -1)
            }
        }

        // void *SkPath_addPoly_2(void *path, const void *list, bool close); // (SkPath *path, const std::initializer_list<SkPoint> *list, bool close) -> SkPath *

        func addPath(src: SkPath, dx: Float, dy: Float, mode: SkPathAddPathMode) -> SkPath {
            let pointer = SkPath_addPath(self.pointer, src.pointer, dx, dy, mode.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addPath(src: SkPath, modeSkPath: SkPathAddPathMode) -> SkPath {
            let pointer = SkPath_addPath_2(self.pointer, src.pointer, modeSkPath.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }

        func addPath(src: SkPath, matrix: SkMatrix, mode: SkPathAddPathMode) -> SkPath {
            let pointer = SkPath_addPath_3(self.pointer, src.pointer, matrix.pointer, mode.rawValue);
            return SkPath(pointer: pointer, handle: -1)
        }
 
        func reverseAddPath(src: SkPath) -> SkPath {
            let pointer = SkPath_reverseAddPath(self.pointer, src.pointer);
            return SkPath(pointer: pointer, handle: -1)
        }

        func offset(dx: Float, dy: Float, dst: SkPath) {
            SkPath_offset(self.pointer, dx, dy, dst.pointer)
        }

        func offset(dx: Float, dy: Float) {
            SkPath_offset_2(self.pointer, dx, dy)
        }

        func transform(matrix: SkMatrix, dst: SkPath, pc: SkApplyPerspectiveClip) {
            SkPath_transform(self.pointer, matrix.pointer, dst.pointer, pc.rawValue)
        }

        func transform(matrix: SkMatrix, pc: SkApplyPerspectiveClip) {
            SkPath_transform_2(self.pointer, matrix.pointer, pc.rawValue)
        }

        func makeTransform(m: SkMatrix, pc: SkApplyPerspectiveClip) -> SkPath {
            let handle = SkPath_makeTransform(self.pointer, m.pointer, pc.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        func makeScale(sx: Float, sy: Float) -> SkPath {
            let handle = SkPath_makeScale(self.pointer, sx, sy)
            let pointer = static_sk_path_get_ptr(handle)
            return SkPath(pointer: pointer, handle: handle)
        }

        func getLastPt(lastPt: SkPoint) -> Bool {
            return SkPath_getLastPt(self.pointer, lastPt.pointer)
        }

        func setLastPt(x: Float, y: Float) {
            SkPath_setLastPt(self.pointer, x, y)
        }

        func setLastPt(p: SkPoint) {
            SkPath_setLastPt_2(self.pointer, p.pointer)
        }

        func getSegmentMasks() -> UInt {
            return UInt(SkPath_getSegmentMasks(self.pointer))
        }

        func contains(x: Float, y: Float) -> Bool {
            return SkPath_contains(self.pointer, x, y)
        }

        func dump(stream: SkWStream, dumpAsHex: Bool) {
            SkPath_dump(self.pointer, stream.pointer, dumpAsHex)
        }

        func dump() {
            SkPath_dump_2(self.pointer)
        }

        func dumpHex() {
            SkPath_dumpHex(self.pointer)
        }

        func dumpArrays(stream: SkWStream, dumpAsHex: Bool) {
            SkPath_dumpArrays(self.pointer, stream.pointer, dumpAsHex)
        }

        func dumpArrays() {
            SkPath_dumpArrays_2(self.pointer)
        }

        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkPath_writeToMemory(self.pointer, buffer)
        }

        func serialize() -> Skia.Data {
            let handle = SkPath_serialize(self.pointer)
            let pointer = static_sk_data_get(handle)
            return Skia.Data(pointer: pointer, handle: handle)
        }

        func readFromMemory(buffer: UnsafeRawPointer, length: UInt) -> UInt {
            return SkPath_readFromMemory(self.pointer, buffer, length)
        }

        func getGenerationID() -> UInt {
            return UInt(SkPath_getGenerationID(self.pointer))
        }

        func isValid() -> Bool {
            return SkPath_isValid(self.pointer)
        }
    }
}