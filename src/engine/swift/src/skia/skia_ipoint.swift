extension Skia {
    protocol SkIPointProtocol {
        var pointer: SkIPointMutablePointer? { get set }
        var handle: sk_i_point_t { get set }
        // deinit // void SkIPoint_delete(void *i_point); // (SkIPoint *i_point)
        init(pointer: SkIPointMutablePointer?, handle: sk_i_point_t)
        // Static Methods
        static func Make(x: Int, y: Int) -> SkIPoint // int SkIPoint_Make(int x, int y); // (int x, int y) -> sk_i_point_t
        // Methods
        func x() -> Int // int x(int i_point); // () -> int32_t
        func y() -> Int // int y(int i_point); // () -> int32_t
        func isZero() -> Bool // bool isZero(int i_point); // () -> bool
        func set(x: Int, y: Int) // void set(int i_point, int x, int y); // (int32_t x, int32_t y)
        func equals(x: Int, y: Int) -> Bool // bool equals(int i_point, int x, int y); // (int32_t x, int32_t y)
    }

    class SkIPoint : SkIPointProtocol {
        public var pointer: SkIPointMutablePointer?
        public var handle: sk_i_point_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_i_point_delete(self.handle)
            } else {
                SkIPoint_delete(self.pointer)
            }
        }

        required init(pointer: SkIPointMutablePointer?, handle: sk_i_point_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(x: Int, y: Int) -> SkIPoint {
            let handle = SkIPoint_Make(Int32(x), Int32(y));
            let pointer = static_sk_i_point_get_ptr(handle)
            return SkIPoint(pointer: pointer, handle: handle)
        }

        // Methods

        func x() -> Int {
            return Int(SkIPoint_x(self.pointer))
        }

        func y() -> Int {
            return Int(SkIPoint_y(self.pointer))
        }

        func isZero() -> Bool {
            return SkIPoint_isZero(self.pointer)
        }

        func set(x: Int, y: Int) {
            SkIPoint_set(self.pointer, Int32(x), Int32(y))
        }

        func equals(x: Int, y: Int) -> Bool {
            return SkIPoint_equals(self.pointer, Int32(x), Int32(y))
        }
    }
}