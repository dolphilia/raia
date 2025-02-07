extension Skia {
    class IPoint {
        public var pointer: Skia.IPointMutablePointer?
        public var handle: sk_i_point_t = -1

        deinit {
            SkIPoint_delete(self.pointer)
            if handle > -1 {
                static_sk_i_point_delete(handle)
            }
        }

        // int x(int i_point); // () -> int32_t
        func x() -> Int {
            return Int(SkIPoint_x(self.pointer))
        }
        // int y(int i_point); // () -> int32_t
        func y() -> Int {
            return Int(SkIPoint_y(self.pointer))
        }
        // bool isZero(int i_point); // () -> bool
        func isZero() -> Bool {
            return SkIPoint_isZero(self.pointer)
        }
        // void set(int i_point, int x, int y); // (int32_t x, int32_t y)
        func set(x: Int, y: Int) {
            SkIPoint_set(self.pointer, Int32(x), Int32(y))
        }
        // bool equals(int i_point, int x, int y); // (int32_t x, int32_t y)
        func equals(x: Int, y: Int) -> Bool {
            return SkIPoint_equals(self.pointer, Int32(x), Int32(y))
        }

        // // static

        init(pointer: Skia.IPointMutablePointer?, handle: sk_i_point_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkIPoint_Make(int x, int y); // (int x, int y) -> sk_i_point_t
        static func Make(x: Int, y: Int) -> IPoint {
            let handle = SkIPoint_Make(Int32(x), Int32(y));
            let pointer = static_sk_i_point_get_ptr(handle)
            return IPoint(pointer: pointer, handle: handle)
        }
    }
}