extension Skia {
    class Region {
        typealias sk_region_t = Int32
        public var pointer: Skia.RegionMutablePointer?
        public var handle: sk_region_t = -1

        // void *SkRegion_new(); // () -> SkRegion *
        init() {
            self.pointer = SkRegion_new();
            self.handle = -1
        }
        // void *SkRegion_new_2(const void *region); // (const SkRegion *region) -> SkRegion *
        init(region: Region) {
            self.pointer = SkRegion_new_2(region.pointer);
            self.handle = -1
        }
        // void *SkRegion_new_3(const void *rect); // (const SkIRect *rect) -> SkRegion *
        init(rect: Skia.IRect) {
            self.pointer = SkRegion_new_3(rect.pointer);
            self.handle = -1
        }
        // void SkRegion_delete(void *region); // (SkRegion *region)
        deinit {
            SkRegion_delete(self.pointer)
        }
        // bool SkRegion_set(void *region, const void *src); // (SkRegion *region, const SkRegion *src) -> bool
        func set(src: Region) -> Bool {
            return SkRegion_set(self.pointer, src.pointer)
        }
        // void SkRegion_swap(void *region, void *other); // (SkRegion *region, SkRegion *other)
        func swap(other: Region) {
            SkRegion_swap(self.pointer, other.pointer)
        }
        // bool SkRegion_isEmpty(void *region); // (SkRegion *region) -> bool
        func isEmpty() -> Bool {
            return SkRegion_isEmpty(self.pointer)
        }
        // bool SkRegion_isRect(void *region); // (SkRegion *region) -> bool
        func isRect() -> Bool {
            return SkRegion_isRect(self.pointer)
        }
        // bool SkRegion_isComplex(void *region); // (SkRegion *region) -> bool
        func isComplex() -> Bool {
            return SkRegion_isComplex(self.pointer)
        }
        // const void *SkRegion_getBounds(void *region); // (SkRegion *region) -> const SkIRect *
        func getBounds() -> Skia.IRect {
            let pointer = SkRegion_getBounds(self.pointer)
            return Skia.IRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // int SkRegion_computeRegionComplexity(void *region); // (SkRegion *region) -> int
        func computeRegionComplexity() -> Int {
            return Int(SkRegion_computeRegionComplexity(self.pointer))
        }
        // bool SkRegion_getBoundaryPath(void *region, void *path); // (SkRegion *region, SkPath *path) -> bool
        func getBoundaryPath(path: Skia.Path) -> Bool {
            return SkRegion_getBoundaryPath(self.pointer, path.pointer)
        }
        // bool SkRegion_setEmpty(void *region); // (SkRegion *region) -> bool
        func setEmpty() -> Bool {
            return SkRegion_setEmpty(self.pointer)
        }
        // bool SkRegion_setRect(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
        func setRect(rect: Skia.IRect) -> Bool {
            return SkRegion_setRect(self.pointer, rect.pointer)
        }
        // bool SkRegion_setRects(void *region, const void * rects, int count); // (SkRegion *region, const SkIRect rects[], int count) -> bool
        func setRects(rects: [Skia.IRect]) -> Bool {
            let rectsPointer = rects.map { $0.pointer }
            return rectsPointer.withUnsafeBufferPointer { rectsBuffer in
                return SkRegion_setRects(self.pointer, rectsBuffer.baseAddress, Int32(rectsBuffer.count))
            }
        }
        // bool SkRegion_setRegion(void *region, const void *region_2); // (SkRegion *region, const SkRegion *region_2) -> bool
        func setRegion(region: Region) -> Bool {
            return SkRegion_setRegion(self.pointer, region.pointer)
        }
        // bool SkRegion_setPath(void *region, const void *path, const void *clip); // (SkRegion *region, const SkPath *path, const SkRegion *clip) -> bool
        func setPath(path: Skia.Path, clip: Region) -> Bool {
            return SkRegion_setPath(self.pointer, path.pointer, clip.pointer)
        }
        // bool SkRegion_intersects(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
        func intersects(rect: Skia.IRect) -> Bool {
            return SkRegion_intersects(self.pointer, rect.pointer)
        }
        // bool SkRegion_intersects_2(void *region, const void *other); // (SkRegion *region, const SkRegion *other) -> bool
        func intersects(other: Region) -> Bool {
            return SkRegion_intersects_2(self.pointer, other.pointer)
        }
        // bool SkRegion_contains(void *region, int x, int y); // (SkRegion *region, int32_t x, int32_t y) -> bool
        func contains(x: Int, y: Int) -> Bool {
            return SkRegion_contains(self.pointer, Int32(x), Int32(y))
        }
        // bool SkRegion_contains_2(void *region, const void *other); // (SkRegion *region, const SkIRect *other) -> bool
        func contains(other: Skia.IRect) -> Bool {
            return SkRegion_contains_2(self.pointer, other.pointer)
        }
        // bool SkRegion_contains_3(void *region, const void *other); // (SkRegion *region, const SkRegion *other) -> bool
        func contains(other: Region) -> Bool {
            return SkRegion_contains_3(self.pointer, other.pointer)
        }
        // bool SkRegion_quickContains(void *region, const void *r); // (SkRegion *region, const SkIRect *r) -> bool
        func quickContains(r: Skia.IRect) -> Bool {
            return SkRegion_quickContains(self.pointer, r.pointer)
        }
        // bool SkRegion_quickReject(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
        func quickReject(rect: Skia.IRect) -> Bool {
            return SkRegion_quickReject(self.pointer, rect.pointer)
        }
        // bool SkRegion_quickReject_2(void *region, const void *rgn); // (SkRegion *region, const SkRegion *rgn) -> bool
        func quickReject(rgn: Region) -> Bool {
            return SkRegion_quickReject_2(self.pointer, rgn.pointer)
        }
        // void SkRegion_translate(void *region, int dx, int dy); // (SkRegion *region, int dx, int dy)
        func translate(dx: Int, dy: Int) {
            SkRegion_translate(self.pointer, Int32(dx), Int32(dy))
        }
        // void SkRegion_translate_2(void *region, int dx, int dy, void *dst); // (SkRegion *region, int dx, int dy, SkRegion *dst)
        func translate(dx: Int, dy: Int, dst: Region) {
            SkRegion_translate_2(self.pointer, Int32(dx), Int32(dy), dst.pointer)
        }
        // bool SkRegion_op(void *region, const void *rect, int op); // (SkRegion *region, const SkIRect *rect, SkRegion::Op op) -> bool
        func op(rect: Skia.IRect, op: Int) -> Bool {
            return SkRegion_op(self.pointer, rect.pointer, Int32(op))
        }
        // bool SkRegion_op_2(void *region, const void *rgn, int op); // (SkRegion *region, const SkRegion *rgn, SkRegion::Op op) -> bool
        func op(rgn: Region, op: Int) -> Bool {
            return SkRegion_op_2(self.pointer, rgn.pointer, Int32(op))
        }
        // bool SkRegion_op_3(void *region, const void *rect, const void *rgn, int op); // (SkRegion *region, const SkIRect *rect, const SkRegion *rgn, SkRegion::Op op) -> bool
        func op(rect: Skia.IRect, rgn: Region, op: Int) -> Bool {
            return SkRegion_op_3(self.pointer, rect.pointer, rgn.pointer, Int32(op))
        }
        // bool SkRegion_op_4(void *region, const void *rgn, const void *rect, int op); // (SkRegion *region, const SkRegion *rgn, const SkIRect *rect, SkRegion::Op op) -> bool
        func op(rgn: Region, rect: Skia.IRect, op: Int) -> Bool {
            return SkRegion_op_4(self.pointer, rgn.pointer, rect.pointer, Int32(op))
        }
        // bool SkRegion_op_5(void *region, const void *rgna, const void *rgnb, int op); // (SkRegion *region, const SkRegion *rgna, const SkRegion *rgnb, SkRegion::Op op) -> bool
        func op(rgna: Region, rgnb: Region, op: Int) -> Bool {
            return SkRegion_op_5(self.pointer, rgna.pointer, rgnb.pointer, Int32(op))
        }
        // unsigned long SkRegion_writeToMemory(void *region, void *buffer); // (SkRegion *region, void *buffer) -> size_t
        func writeToMemory(buffer: UnsafeMutableRawPointer) -> UInt {
            return SkRegion_writeToMemory(self.pointer, buffer)
        }
        // unsigned long SkRegion_readFromMemory(void *region, const void *buffer, unsigned long length); // (SkRegion *region, const void *buffer, size_t length) -> size_t
        func readFromMemory(buffer: UnsafeRawPointer, length: UInt) -> UInt {
            return SkRegion_readFromMemory(self.pointer, buffer, length)
        }

        // // static

        init(pointer: Skia.RegionMutablePointer?, handle: sk_region_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}