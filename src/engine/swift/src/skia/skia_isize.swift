extension Skia {
    class ISize {
        public var pointer: Skia.ISizeMutablePointer?
        public var handle: sk_i_size_t = -1

        // void SkISize_delete(void *i_size); // (SkISize *i_size)
        deinit {
            if self.handle > -1 {
                static_sk_i_size_delete(self.handle)
            } else {
                SkISize_delete(self.pointer)
            }
        }
        // void SkISize_set(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h)
        func set(w: Int, h: Int) {
            SkISize_set(self.pointer, Int32(w), Int32(h))
        }
        // bool SkISize_isZero(void *i_size); // (SkISize *i_size) -> bool
        func isZero() -> Bool {
            return SkISize_isZero(self.pointer)
        }
        // bool SkISize_isEmpty(void *i_size); // (SkISize *i_size) -> bool
        func isEmpty() -> Bool {
            return SkISize_isEmpty(self.pointer)
        }
        // void SkISize_setEmpty(void *i_size); // (SkISize *i_size)
        func setEmpty() {
            SkISize_setEmpty(self.pointer)
        }
        // int SkISize_width(void *i_size); // (SkISize *i_size) -> int32_t
        func width() -> Int {
            return Int(SkISize_width(self.pointer))
        }
        // int SkISize_height(void *i_size); // (SkISize *i_size) -> int32_t
        func height() -> Int {
            return Int(SkISize_height(self.pointer))
        }
        // long long SkISize_area(void *i_size); // (SkISize *i_size) -> int64_t
        func area() -> Int64 {
            return SkISize_area(self.pointer)
        }
        // bool SkISize_equals(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h) -> bool
        func equals(w: Int, h: Int) -> Bool {
            return SkISize_equals(self.pointer, Int32(w), Int32(h))
        }

        // // static

        init(pointer: Skia.ISizeMutablePointer?, handle: sk_i_size_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkISize_Make(int w, int h); // (int32_t w, int32_t h) -> sk_i_size_t
        static func Make(w: Int, h: Int) -> ISize {
            let handle = SkISize_Make(Int32(w), Int32(h));
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkISize_MakeEmpty(); // () -> sk_i_size_t
        static func MakeEmpty() -> ISize {
            let handle = SkISize_MakeEmpty();
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
    }
}