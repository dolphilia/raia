extension Skia {
    protocol SkISizeProtocol {
        var pointer: SkISizeMutablePointer? { get set }
        var handle: sk_i_size_t { get set }
        // deinit // void SkISize_delete(void *i_size); // (SkISize *i_size)
        init(pointer: SkISizeMutablePointer?, handle: sk_i_size_t)
        // Static Methods
        static func Make(w: Int, h: Int) -> SkISize // int SkISize_Make(int w, int h); // (int32_t w, int32_t h) -> sk_i_size_t
        static func MakeEmpty() -> SkISize // int SkISize_MakeEmpty(); // () -> sk_i_size_t
        // Methods
        func set(w: Int, h: Int) // void SkISize_set(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h)
        func isZero() -> Bool // bool SkISize_isZero(void *i_size); // (SkISize *i_size) -> bool
        func isEmpty() -> Bool // bool SkISize_isEmpty(void *i_size); // (SkISize *i_size) -> bool
        func setEmpty() // void SkISize_setEmpty(void *i_size); // (SkISize *i_size)
        func width() -> Int // int SkISize_width(void *i_size); // (SkISize *i_size) -> int32_t
        func height() -> Int // int SkISize_height(void *i_size); // (SkISize *i_size) -> int32_t
        func area() -> Int64 // long long SkISize_area(void *i_size); // (SkISize *i_size) -> int64_t
        func equals(w: Int, h: Int) -> Bool // bool SkISize_equals(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h) -> bool
    }

    class SkISize : SkISizeProtocol {
        public var pointer: SkISizeMutablePointer?
        public var handle: sk_i_size_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_i_size_delete(self.handle)
            } else {
                SkISize_delete(self.pointer)
            }
        }

        required init(pointer: SkISizeMutablePointer?, handle: sk_i_size_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(w: Int, h: Int) -> SkISize {
            let handle = SkISize_Make(Int32(w), Int32(h));
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        static func MakeEmpty() -> SkISize {
            let handle = SkISize_MakeEmpty();
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        // Methods

        func set(w: Int, h: Int) {
            SkISize_set(self.pointer, Int32(w), Int32(h))
        }

        func isZero() -> Bool {
            return SkISize_isZero(self.pointer)
        }

        func isEmpty() -> Bool {
            return SkISize_isEmpty(self.pointer)
        }

        func setEmpty() {
            SkISize_setEmpty(self.pointer)
        }

        func width() -> Int {
            return Int(SkISize_width(self.pointer))
        }

        func height() -> Int {
            return Int(SkISize_height(self.pointer))
        }

        func area() -> Int64 {
            return SkISize_area(self.pointer)
        }

        func equals(w: Int, h: Int) -> Bool {
            return SkISize_equals(self.pointer, Int32(w), Int32(h))
        }
    }
}