extension Skia {
    class Path {
        public enum AddPathMode: Int32 {
            case append
            case extend
        }

        public enum ArcSize: Int32 {
            case small
            case large
        }

        public var pointer: Skia.PathMutablePointer?
        public var handle: sk_path_t = -1

        // void *SkPath_new(); // () -> SkPath *

        init() {
            self.pointer = SkPath_new();
            self.handle = -1
        }
        // void *SkPath_new_2(const void *path); // (const SkPath *path) -> SkPath *

        init(path: Path) {
            self.pointer = SkPath_new_2(path.pointer);
            self.handle = -1
        }
        // void SkPath_delete(void *path); // (SkPath *path)

        deinit {
            SkPath_delete(self.pointer)
            if handle > -1 {
                static_sk_path_delete(handle)
            }
        }
        // bool SkPath_isInterpolatable(void *path, const void *compare); // (SkPath *path, const SkPath *compare) -> bool

        func isInterpolatable(compare: Path) -> Bool {
            return SkPath_isInterpolatable(self.pointer, compare.pointer)
        }
        // bool SkPath_interpolate(void *path, const void *ending, float weight, void *out); // (SkPath *path, const SkPath *ending, SkScalar weight, SkPath *out) -> bool

        func interpolate(ending: Path, weight: Float, out: Path) -> Bool {
            return SkPath_interpolate(self.pointer, ending.pointer, weight, out.pointer)
        }
        // int SkPath_getFillType(void *path); // (SkPath *path) -> SkPathFillType

        func getFillType() -> PathFillType {
            return PathFillType(rawValue: SkPath_getFillType(self.pointer))!
        }
        // void SkPath_setFillType(void *path, int ft); // (SkPath *path, SkPathFillType ft)

        func setFillType(ft: PathFillType) {
            SkPath_setFillType(self.pointer, ft.rawValue)
        }
        // bool SkPath_isInverseFillType(void *path); // (SkPath *path) -> bool

        func isInverseFillType() -> Bool {
            return SkPath_isInverseFillType(self.pointer)
        }
        // void SkPath_toggleInverseFillType(void *path); // (SkPath *path)

        func toggleInverseFillType() {
            SkPath_toggleInverseFillType(self.pointer)
        }
        // bool SkPath_isConvex(void *path); // (SkPath *path) -> bool

        func isConvex() -> Bool {
            return SkPath_isConvex(self.pointer)
        }
        // bool SkPath_isOval(void *path, void *bounds); // (SkPath *path, SkRect *bounds) -> bool

        func isOval(bounds: Rect) -> Bool {
            return SkPath_isOval(self.pointer, bounds.pointer)
        }
        // bool SkPath_isRRect(void *path, void *rrect); // (SkPath *path, SkRRect *rrect) -> bool

        func isRRect(rrect: RRect) -> Bool {
            return SkPath_isRRect(self.pointer, rrect.pointer)
        }
        // void *SkPath_reset(void *path); // (SkPath *path) -> SkPath *

        func reset() -> Path {
            let pointer = SkPath_reset(self.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rewind(void *path); // (SkPath *path) -> SkPath *

        func rewind() -> Path {
            let pointer = SkPath_rewind(self.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // bool SkPath_isEmpty(void *path); // (SkPath *path) -> bool

        func isEmpty() -> Bool {
            return SkPath_isEmpty(self.pointer)
        }
        // bool SkPath_isLastContourClosed(void *path); // (SkPath *path) -> bool

        func isLastContourClosed() -> Bool {
            return SkPath_isLastContourClosed(self.pointer)
        }
        // bool SkPath_isFinite(void *path); // (SkPath *path) -> bool

        func isFinite() -> Bool {
            return SkPath_isFinite(self.pointer)
        }
        // bool SkPath_isVolatile(void *path); // (SkPath *path) -> bool

        func isVolatile() -> Bool {
            return SkPath_isVolatile(self.pointer)
        }
        // void *SkPath_setIsVolatile(void *path, bool isVolatile); // (SkPath *path, bool isVolatile) -> SkPath *

        func setIsVolatile(isVolatile: Bool) -> Path {
            let pointer = SkPath_setIsVolatile(self.pointer, isVolatile);
            return Path(pointer: pointer, handle: -1)
        }
        // bool SkPath_isLine(void *path, void * line); // (SkPath *path, SkPoint line[2]) -> bool

        func isLine(line: [Point]) -> Bool {
            return line.withUnsafeBufferPointer { buffer in
                SkPath_isLine(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress))
            }
        }
        // int SkPath_countPoints(void *path); // (SkPath *path) -> int

        func countPoints() -> Int {
            return Int(SkPath_countPoints(self.pointer))
        }
        // int SkPath_getPoint(void *path, int index); // (SkPath *path, int index) -> sk_point_t

        func getPoint(index: Int) -> Point {
            let handle = SkPath_getPoint(self.pointer, Int32(index))
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // int SkPath_getPoints(void *path, void * points, int max); // (SkPath *path, SkPoint points[], int max) -> int

        func getPoints(points: [Point], max: Int) -> Int {
            return points.withUnsafeBufferPointer { (buffer: UnsafeBufferPointer<Point>) -> Int in
                return Int(SkPath_getPoints(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(max)))
            }
        }
        // int SkPath_countVerbs(void *path); // (SkPath *path) -> int

        func countVerbs() -> Int {
            return Int(SkPath_countVerbs(self.pointer))
        }
        // int SkPath_getVerbs(void *path, void * verbs, int max); // (SkPath *path, uint8_t verbs[], int max) -> int

        func getVerbs(verbs: [UInt8], max: Int) -> Int {
            return verbs.withUnsafeBufferPointer { (buffer: UnsafeBufferPointer<UInt8>) -> Int in
                return Int(SkPath_getVerbs(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(max)))
            }
        }
        // unsigned long SkPath_approximateBytesUsed(void *path); // (SkPath *path) -> size_t

        func approximateBytesUsed() -> UInt {
            return SkPath_approximateBytesUsed(self.pointer)
        }
        // void SkPath_swap(void *path, void *other); // (SkPath *path, SkPath *other)

        func swap(other: Path) {
            SkPath_swap(self.pointer, other.pointer)
        }
        // const void *SkPath_getBounds(void *path); // (SkPath *path) -> const SkRect *

        func getBounds() -> Rect {
            let pointer = SkPath_getBounds(self.pointer)
            // guard let pointer = pointer else {
            //     return Rect(pointer: nil, handle: nil)
            // }
            // let rectPointer: Skia.RectMutablePointer = pointer.assumingMemoryBound(to: Skia.RectMutablePointer.self).pointee
            return Skia.Rect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // void SkPath_updateBoundsCache(void *path); // (SkPath *path)

        func updateBoundsCache() {
            SkPath_updateBoundsCache(self.pointer)
        }
        // int SkPath_computeTightBounds(void *path); // (SkPath *path) -> sk_rect_t

        func computeTightBounds() -> Rect {
            let handle = SkPath_computeTightBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return Skia.Rect(pointer: pointer, handle: handle)
        }
        // bool SkPath_conservativelyContainsRect(void *path, const void *rect); // (SkPath *path, const SkRect *rect) -> bool

        func conservativelyContainsRect(rect: Rect) -> Bool {
            return SkPath_conservativelyContainsRect(self.pointer, rect.pointer)
        }
        // void SkPath_incReserve(void *path, int extraPtCount); // (SkPath *path, int extraPtCount)

        func incReserve(extraPtCount: Int) {
            SkPath_incReserve(self.pointer, Int32(extraPtCount))
        }
        // void *SkPath_moveTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *

        func moveTo(x: Float, y: Float) -> Path {
            let pointer = SkPath_moveTo(self.pointer, x, y);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_moveTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *

        func moveTo(p: Point) -> Path {
            let pointer = SkPath_moveTo_2(self.pointer, p.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rMoveTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *

        func rMoveTo(dx: Float, dy: Float) -> Path {
            let pointer = SkPath_rMoveTo(self.pointer, dx, dy);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_lineTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *

        func lineTo(x: Float, y: Float) -> Path {
            let pointer = SkPath_lineTo(self.pointer, x, y);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_lineTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *

        func lineTo(p: Point) -> Path {
            let pointer = SkPath_lineTo_2(self.pointer, p.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rLineTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *

        func rLineTo(dx: Float, dy: Float) -> Path {
            let pointer = SkPath_rLineTo(self.pointer, dx, dy);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_quadTo(void *path, float x1, float y1, float x2, float y2); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) -> SkPath *

        func quadTo(x1: Float, y1: Float, x2: Float, y2: Float) -> Path {
            let pointer = SkPath_quadTo(self.pointer, x1, y1, x2, y2);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_quadTo_2(void *path, const void *p1, const void *p2); // (SkPath *path, const SkPoint *p1, const SkPoint *p2) -> SkPath *

        func quadTo(p1: Point, p2: Point) -> Path {
            let pointer = SkPath_quadTo_2(self.pointer, p1.pointer, p2.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rQuadTo(void *path, float dx1, float dy1, float dx2, float dy2); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2) -> SkPath *

        func rQuadTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float) -> Path {
            let pointer = SkPath_rQuadTo(self.pointer, dx1, dy1, dx2, dy2);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_conicTo(void *path, float x1, float y1, float x2, float y2, float w); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) -> SkPath *

        func conicTo(x1: Float, y1: Float, x2: Float, y2: Float, w: Float) -> Path {
            let pointer = SkPath_conicTo(self.pointer, x1, y1, x2, y2, w);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_conicTo_2(void *path, const void *p1, const void *p2, float w); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, SkScalar w) -> SkPath *

        func conicTo(p1: Point, p2: Point, w: Float) -> Path {
            let pointer = SkPath_conicTo_2(self.pointer, p1.pointer, p2.pointer, w);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rConicTo(void *path, float dx1, float dy1, float dx2, float dy2, float w); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w) -> SkPath *

        func rConicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, w: Float) -> Path {
            let pointer = SkPath_rConicTo(self.pointer, dx1, dy1, dx2, dy2, w);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_cubicTo(void *path, float x1, float y1, float x2, float y2, float x3, float y3); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) -> SkPath *

        func cubicTo(x1: Float, y1: Float, x2: Float, y2: Float, x3: Float, y3: Float) -> Path {
            let pointer = SkPath_cubicTo(self.pointer, x1, y1, x2, y2, x3, y3);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_cubicTo_2(void *path, const void *p1, const void *p2, const void *p3); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, const SkPoint *p3) -> SkPath *

        func cubicTo(p1: Point, p2: Point, p3: Point) -> Path {
            let pointer = SkPath_cubicTo_2(self.pointer, p1.pointer, p2.pointer, p3.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rCubicTo(void *path, float dx1, float dy1, float dx2, float dy2, float dx3, float dy3); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3) -> SkPath *

        func rCubicTo(dx1: Float, dy1: Float, dx2: Float, dy2: Float, dx3: Float, dy3: Float) -> Path {
            let pointer = SkPath_rCubicTo(self.pointer, dx1, dy1, dx2, dy2, dx3, dy3);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_arcTo(void *path, const void *oval, float startAngle, float sweepAngle, bool forceMoveTo); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo) -> SkPath *

        func arcTo(oval: Rect, startAngle: Float, sweepAngle: Float, forceMoveTo: Bool) -> Path {
            let pointer = SkPath_arcTo(self.pointer, oval.pointer, startAngle, sweepAngle, forceMoveTo);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_arcTo_2(void *path, float x1, float y1, float x2, float y2, float radius); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius) -> SkPath *

        func arcTo(x1: Float, y1: Float, x2: Float, y2: Float, radius: Float) -> Path {
            let pointer = SkPath_arcTo_2(self.pointer, x1, y1, x2, y2, radius);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_arcTo_3(void *path, int p1, int p2, float radius); // (SkPath *path, sk_point_t p1, sk_point_t p2, SkScalar radius) -> SkPath *

        func arcTo(p1: Point, p2: Point, radius: Float) -> Path {
            let pointer = SkPath_arcTo_3(self.pointer, p1.handle, p2.handle, radius);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_arcTo_4(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float x, float y); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y) -> SkPath *

        func arcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: ArcSize, sweep: PathDirection, x: Float, y: Float) -> Path {
            let pointer = SkPath_arcTo_4(self.pointer, rx, ry, xAxisRotate, largeArc.rawValue, sweep.rawValue, x, y);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_arcTo_5(void *path, int r, float xAxisRotate, int largeArc, int sweep, int xy); // (SkPath *path, sk_point_t r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) -> SkPath *

        func arcTo(r: Point, xAxisRotate: Float, largeArc: ArcSize, sweep: PathDirection, xy: Point) -> Path {
            let pointer = SkPath_arcTo_5(self.pointer, r.handle, xAxisRotate, largeArc.rawValue, sweep.rawValue, xy.handle);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_rArcTo(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float dx, float dy); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy) -> SkPath *

        func rArcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: ArcSize, sweep: PathDirection, dx: Float, dy: Float) -> Path {
            let pointer = SkPath_rArcTo(self.pointer, rx, ry, xAxisRotate, largeArc.rawValue, sweep.rawValue, dx, dy);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_close(void *path); // (SkPath *path) -> SkPath *

        func close() -> Path {
            let pointer = SkPath_close(self.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // bool SkPath_isRect(void *path, void *rect, void *isClosed, void *direction); // (SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction) -> bool

        func isRect(rect: Rect, isClosed: UnsafeMutablePointer<Bool>?, direction: [PathDirection]) -> Bool {
            return direction.withUnsafeBufferPointer { buffer in
                SkPath_isRect(self.pointer, rect.pointer, isClosed, UnsafeMutableRawPointer(mutating: buffer.baseAddress))
            }
        }

        // void *SkPath_addRect(void *path, const void *rect, int dir, unsigned start); // (SkPath *path, const SkRect *rect, SkPathDirection dir, unsigned start) -> SkPath *

        func addRect(rect: Rect, dir: PathDirection, start: UInt) -> Path {
            let pointer = SkPath_addRect(self.pointer, rect.pointer, dir.rawValue, UInt32(start));
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addRect_2(void *path, const void *rect, int dir); // (SkPath *path, const SkRect *rect, SkPathDirection dir) -> SkPath *

        func addRect(rect: Rect, dir: PathDirection) -> Path {
            let pointer = SkPath_addRect_2(self.pointer, rect.pointer, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addRect_3(void *path, float left, float top, float right, float bottom, int dir); // (SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir) -> SkPath *

        func addRect(left: Float, top: Float, right: Float, bottom: Float, dir: PathDirection) -> Path {
            let pointer = SkPath_addRect_3(self.pointer, left, top, right, bottom, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addOval(void *path, const void *oval, int dir); // (SkPath *path, const SkRect *oval, SkPathDirection dir) -> SkPath *

        func addOval(oval: Rect, dir: PathDirection) -> Path {
            let pointer = SkPath_addOval(self.pointer, oval.pointer, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addOval_2(void *path, const void *oval, int dir, unsigned start); // (SkPath *path, const SkRect *oval, SkPathDirection dir, unsigned start) -> SkPath *

        func addOval(oval: Rect, dir: PathDirection, start: UInt) -> Path {
            let pointer = SkPath_addOval_2(self.pointer, oval.pointer, dir.rawValue, UInt32(start));
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addCircle(void *path, float x, float y, float radius, int dir); // (SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir) -> SkPath *

        func addCircle(x: Float, y: Float, radius: Float, dir: PathDirection) -> Path {
            let pointer = SkPath_addCircle(self.pointer, x, y, radius, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addArc(void *path, const void *oval, float startAngle, float sweepAngle); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle) -> SkPath *

        func addArc(oval: Rect, startAngle: Float, sweepAngle: Float) -> Path {
            let pointer = SkPath_addArc(self.pointer, oval.pointer, startAngle, sweepAngle);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addRoundRect(void *path, const void *rect, float rx, float ry, int dir); // (SkPath *path, const SkRect *rect, SkScalar rx, SkScalar ry, SkPathDirection dir) -> SkPath *

        func addRoundRect(rect: Rect, rx: Float, ry: Float, dir: PathDirection) -> Path {
            let pointer = SkPath_addRoundRect(self.pointer, rect.pointer, rx, ry, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addRoundRect_2(void *path, const void *rect, const void * radii, int dir); // (SkPath *path, const SkRect *rect, const SkScalar radii[], SkPathDirection dir) -> SkPath *

        func addRoundRect(rect: Rect, radii: [Float], dir: PathDirection) -> Path {
            return radii.withUnsafeBufferPointer { buffer in
                let pointer = SkPath_addRoundRect_2(self.pointer, rect.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), dir.rawValue);
                return Path(pointer: pointer, handle: -1)
            }
        }
        // void *SkPath_addRRect(void *path, const void *rrect, int dir); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir) -> SkPath *

        func addRRect(rrect: RRect, dir: PathDirection) -> Path {
            let pointer = SkPath_addRRect(self.pointer, rrect.pointer, dir.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addRRect_2(void *path, const void *rrect, int dir, unsigned start); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir, unsigned start) -> SkPath *

        func addRRect(rrect: RRect, dir: PathDirection, start: UInt) -> Path {
            let pointer = SkPath_addRRect_2(self.pointer, rrect.pointer, dir.rawValue, UInt32(start));
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addPoly(void *path, const void * pts, int count, bool close); // (SkPath *path, const SkPoint pts[], int count, bool close) -> SkPath *

        func addPoly(pts: [Point], close: Bool) -> Path {
            return pts.withUnsafeBufferPointer { buffer in
                let pointer = SkPath_addPoly(self.pointer, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pts.count), close);
                return Path(pointer: pointer, handle: -1)
            }
        }
        // void *SkPath_addPoly_2(void *path, const void *list, bool close); // (SkPath *path, const std::initializer_list<SkPoint> *list, bool close) -> SkPath *
        // void *SkPath_addPath(void *path, const void *src, float dx, float dy, int mode); // (SkPath *path, const SkPath *src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode) -> SkPath *

        func addPath(src: Path, dx: Float, dy: Float, mode: AddPathMode) -> Path {
            let pointer = SkPath_addPath(self.pointer, src.pointer, dx, dy, mode.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addPath_2(void *path, const void *src, int modeSkPath); // (SkPath *path, const SkPath *src, SkPath::AddPathMode modeSkPath) -> SkPath *

        func addPath(src: Path, modeSkPath: AddPathMode) -> Path {
            let pointer = SkPath_addPath_2(self.pointer, src.pointer, modeSkPath.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_addPath_3(void *path, const void *src, const void *matrix, int mode); // (SkPath *path, const SkPath *src, const SkMatrix *matrix, SkPath::AddPathMode mode) -> SkPath *

        func addPath(src: Path, matrix: Matrix, mode: AddPathMode) -> Path {
            let pointer = SkPath_addPath_3(self.pointer, src.pointer, matrix.pointer, mode.rawValue);
            return Path(pointer: pointer, handle: -1)
        }
        // void *SkPath_reverseAddPath(void *path, const void *src); // (SkPath *path, const SkPath *src) -> SkPath *

        func reverseAddPath(src: Path) -> Path {
            let pointer = SkPath_reverseAddPath(self.pointer, src.pointer);
            return Path(pointer: pointer, handle: -1)
        }
        // void SkPath_offset(void *path, float dx, float dy, void *dst); // (SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst)

        func offset(dx: Float, dy: Float, dst: Path) {
            SkPath_offset(self.pointer, dx, dy, dst.pointer)
        }
        // void SkPath_offset_2(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy)

        func offset(dx: Float, dy: Float) {
            SkPath_offset_2(self.pointer, dx, dy)
        }
        // void SkPath_transform(void *path, const void *matrix, void *dst, int pc); // (SkPath *path, const SkMatrix *matrix, SkPath *dst, SkApplyPerspectiveClip pc)

        func transform(matrix: Matrix, dst: Path, pc: ApplyPerspectiveClip) {
            SkPath_transform(self.pointer, matrix.pointer, dst.pointer, pc.rawValue)
        }
        // void SkPath_transform_2(void *path, const void *matrix, int pc); // (SkPath *path, const SkMatrix *matrix, SkApplyPerspectiveClip pc)

        func transform(matrix: Matrix, pc: ApplyPerspectiveClip) {
            SkPath_transform_2(self.pointer, matrix.pointer, pc.rawValue)
        }
        // int SkPath_makeTransform(void *path, const void *m, int pc); // (SkPath *path, const SkMatrix *m, SkApplyPerspectiveClip pc) -> sk_path_t

        func makeTransform(m: Matrix, pc: ApplyPerspectiveClip) -> Path {
            let handle = SkPath_makeTransform(self.pointer, m.pointer, pc.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_makeScale(void *path, float sx, float sy); // (SkPath *path, SkScalar sx, SkScalar sy) -> sk_path_t

        func makeScale(sx: Float, sy: Float) -> Path {
            let handle = SkPath_makeScale(self.pointer, sx, sy)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // bool SkPath_getLastPt(void *path, void *lastPt); // (SkPath *path, SkPoint *lastPt) -> bool

        func getLastPt(lastPt: Point) -> Bool {
            return SkPath_getLastPt(self.pointer, lastPt.pointer)
        }
        // void SkPath_setLastPt(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y)

        func setLastPt(x: Float, y: Float) {
            SkPath_setLastPt(self.pointer, x, y)
        }
        // void SkPath_setLastPt_2(void *path, const void *p); // (SkPath *path, const SkPoint *p)

        func setLastPt(p: Point) {
            SkPath_setLastPt_2(self.pointer, p.pointer)
        }
        // unsigned int SkPath_getSegmentMasks(void *path); // (SkPath *path) -> uint32_t

        func getSegmentMasks() -> UInt {
            return UInt(SkPath_getSegmentMasks(self.pointer))
        }
        // bool SkPath_contains(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> bool

        func contains(x: Float, y: Float) -> Bool {
            return SkPath_contains(self.pointer, x, y)
        }
        // void SkPath_dump(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)

        func dump(stream: WStream, dumpAsHex: Bool) {
            SkPath_dump(self.pointer, stream.pointer, dumpAsHex)
        }
        // void SkPath_dump_2(void *path); // (SkPath *path)

        func dump() {
            SkPath_dump_2(self.pointer)
        }
        // void SkPath_dumpHex(void *path); // (SkPath *path)

        func dumpHex() {
            SkPath_dumpHex(self.pointer)
        }
        // void SkPath_dumpArrays(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)

        func dumpArrays(stream: WStream, dumpAsHex: Bool) {
            SkPath_dumpArrays(self.pointer, stream.pointer, dumpAsHex)
        }
        // void SkPath_dumpArrays_2(void *path); // (SkPath *path)

        func dumpArrays() {
            SkPath_dumpArrays_2(self.pointer)
        }
        // unsigned long SkPath_writeToMemory(void *path, void *buffer); // (SkPath *path, void *buffer) -> size_t

        func writeToMemory(buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkPath_writeToMemory(self.pointer, buffer)
        }
        // int SkPath_serialize(void *path); // (SkPath *path) -> sk_data_t

        func serialize() -> Skia.Data {
            let handle = SkPath_serialize(self.pointer)
            let pointer = static_sk_data_get(handle)
            return Skia.Data(pointer: pointer, handle: handle)
        }
        // unsigned long SkPath_readFromMemory(void *path, const void *buffer, unsigned long length); // (SkPath *path, const void *buffer, size_t length) -> size_t

        func readFromMemory(buffer: UnsafeRawPointer, length: UInt) -> UInt {
            return SkPath_readFromMemory(self.pointer, buffer, length)
        }
        // unsigned int SkPath_getGenerationID(void *path); // (SkPath *path) -> uint32_t

        func getGenerationID() -> UInt {
            return UInt(SkPath_getGenerationID(self.pointer))
        }
        // bool SkPath_isValid(void *path); // (SkPath *path) -> bool

        func isValid() -> Bool {
            return SkPath_isValid(self.pointer)
        }

        // // static

        init(pointer: Skia.PathMutablePointer?, handle: sk_path_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkPath_Make(const void * point, int pointCount, const void * i, int verbCount, const void * v, int conicWeightCount, int type, bool isVolatile); // (const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile) -> sk_path_t

        static func Make(point: [Point], i: [UInt8], v: [Float], conicWeightCount: Int, type: PathFillType, isVolatile: Bool) -> Path {
            return point.withUnsafeBufferPointer { pointBuffer in
                i.withUnsafeBufferPointer { iBuffer in
                    v.withUnsafeBufferPointer { vBuffer in
                        let handle = SkPath_Make(UnsafeMutableRawPointer(mutating: pointBuffer.baseAddress), Int32(point.count), UnsafeMutableRawPointer(mutating: iBuffer.baseAddress), Int32(i.count), UnsafeMutableRawPointer(mutating: vBuffer.baseAddress), Int32(conicWeightCount), type.rawValue, isVolatile)
                        let pointer = static_sk_path_get_ptr(handle)
                        return Path(pointer: pointer, handle: handle)
                    }
                }
            }
        }


        // int SkPath_Rect(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t

        static func Rect(rect: Rect, dir: PathDirection, startIndex: UInt) -> Path {
            let handle = SkPath_Rect(rect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_Oval(const void *rect, int dir); // (const SkRect *rect, SkPathDirection dir) -> sk_path_t

        static func Oval(rect: Rect, dir: PathDirection) -> Path {
            let handle = SkPath_Oval(rect.pointer, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_Oval_2(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t

        static func Oval(rect: Rect, dir: PathDirection, startIndex: UInt) -> Path {
            let handle = SkPath_Oval_2(rect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_Circle(float center_x, float center_y, float radius, int dir); // (SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) -> sk_path_t

        static func Circle(center_x: Float, center_y: Float, radius: Float, dir: PathDirection) -> Path {
            let handle = SkPath_Circle(center_x, center_y, radius, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_RRect(const void *rrect, int dir); // (const SkRRect *rrect, SkPathDirection dir) -> sk_path_t

        static func RRect(rrect: RRect, dir: PathDirection) -> Path {
            let handle = SkPath_RRect(rrect.pointer, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_RRect_2(const void *rrect, int dir, unsigned startIndex); // (const SkRRect *rrect, SkPathDirection dir, unsigned startIndex) -> sk_path_t

        static func RRect(rrect: RRect, dir: PathDirection, startIndex: UInt) -> Path {
            let handle = SkPath_RRect_2(rrect.pointer, dir.rawValue, UInt32(startIndex))
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_RRect_3(const void *bounds, float rx, float ry, int dir); // (const SkRect *bounds, SkScalar rx, SkScalar ry, SkPathDirection dir) -> sk_path_t

        static func RRect(bounds: Rect, rx: Float, ry: Float, dir: PathDirection) -> Path {
            let handle = SkPath_RRect_3(bounds.pointer, rx, ry, dir.rawValue)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // int SkPath_Polygon(const void * pts, int count, bool isClosed, int type, bool isVolatile); // (const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile) -> sk_path_t

        static func Polygon(pts: [Point], isClosed: Bool, type: PathFillType, isVolatile: Bool) -> Path {
            return pts.withUnsafeBufferPointer { buffer in
                let handle = SkPath_Polygon(UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pts.count), isClosed, type.rawValue, isVolatile)
                let pointer = static_sk_path_get_ptr(handle)
                return Path(pointer: pointer, handle: handle)
            }
        }
        // int SkPath_Polygon_2(const void *list, bool isClosed, int fillType, bool isVolatile); // (const std::initializer_list<SkPoint> *list, bool isClosed, SkPathFillType fillType, bool isVolatile) -> sk_path_t

        static func Polygon(list: [Point], isClosed: Bool, fillType: PathFillType, isVolatile: Bool) -> Path {
            return list.withUnsafeBufferPointer { buffer in
                let handle = SkPath_Polygon_2(UnsafeMutableRawPointer(mutating: buffer.baseAddress), isClosed, fillType.rawValue, isVolatile)
                let pointer = static_sk_path_get_ptr(handle)
                return Path(pointer: pointer, handle: handle)
            }
        }
        // int SkPath_Line(int a, int b); // (sk_point_t a, sk_point_t b) -> sk_path_t

        static func Line(a: Point, b: Point) -> Path {
            let handle = SkPath_Line(a.handle, b.handle)
            let pointer = static_sk_path_get_ptr(handle)
            return Path(pointer: pointer, handle: handle)
        }
        // bool SkPath_IsLineDegenerate(const void *p1, const void *p2, bool exact); // (const SkPoint *p1, const SkPoint *p2, bool exact) -> bool

        static func IsLineDegenerate(p1: Point, p2: Point, exact: Bool) -> Bool {
            return SkPath_IsLineDegenerate(p1.pointer, p2.pointer, exact)
        }
        // bool SkPath_IsQuadDegenerate(const void *p1, const void *p2, const void *p3, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, bool exact) -> bool

        static func IsQuadDegenerate(p1: Point, p2: Point, p3: Point, exact: Bool) -> Bool {
            return SkPath_IsQuadDegenerate(p1.pointer, p2.pointer, p3.pointer, exact)
        }
        // bool SkPath_IsCubicDegenerate(const void *p1, const void *p2, const void *p3, const void *p4, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, const SkPoint *p4, bool exact) -> bool

        static func IsCubicDegenerate(p1: Point, p2: Point, p3: Point, p4: Point, exact: Bool) -> Bool {
            return SkPath_IsCubicDegenerate(p1.pointer, p2.pointer, p3.pointer, p4.pointer, exact)
        }
        // int SkPath_ConvertConicToQuads(const void *p0, const void *p1, const void *p2, float w, void * pts, int pow2); // (const SkPoint *p0, const SkPoint *p1, const SkPoint *p2, SkScalar w, SkPoint pts[], int pow2) -> int

        static func ConvertConicToQuads(p0: Point, p1: Point, p2: Point, w: Float, pts: [Point], pow2: Int) -> Int {
            return pts.withUnsafeBufferPointer { buffer in
                return Int(SkPath_ConvertConicToQuads(p0.pointer, p1.pointer, p2.pointer, w, UnsafeMutableRawPointer(mutating: buffer.baseAddress), Int32(pow2)))
            }
        }
    }
}