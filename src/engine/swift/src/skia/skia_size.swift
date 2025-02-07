extension Skia {
    class Size {
        public var pointer: Skia.SizeMutablePointer?
        public var handle: sk_size_t = -1
        // void SkSize_delete(void *size); // (SkSize *size)
        deinit {
            SkSize_delete(self.pointer)
            static_sk_rect_delete(self.handle)
        }
        // void SkSize_set(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h)
        func set(w: Float, h: Float) {
            SkSize_set(self.pointer, w, h)
        }
        // bool SkSize_isZero(void *size); // (SkSize *size) -> bool
        func isZero() -> Bool {
            return SkSize_isZero(self.pointer)
        }
        // bool SkSize_isEmpty(void *size); // (SkSize *size) -> bool
        func isEmpty() -> Bool {
            return SkSize_isEmpty(self.pointer)
        }
        // void SkSize_setEmpty(void *size); // (SkSize *size)
        func setEmpty() {
            SkSize_setEmpty(self.pointer)
        }
        // float SkSize_width(void *size); // (SkSize *size) -> SkScalar
        func width() -> Float {
            return SkSize_width(self.pointer)
        }
        // float SkSize_height(void *size); // (SkSize *size) -> SkScalar
        func height() -> Float {
            return SkSize_height(self.pointer)
        }
        // bool SkSize_equals(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h) -> bool
        func equals(w: Float, h: Float) -> Bool {
            return SkSize_equals(self.pointer, w, h)
        }
        // int SkSize_toRound(void *size); // (SkSize *size) -> sk_i_size_t
        func toRound() -> ISize {
            let handle = SkSize_toRound(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkSize_toCeil(void *size); // (SkSize *size) -> sk_i_size_t
        func toCeil() -> ISize {
            let handle = SkSize_toCeil(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkSize_toFloor(void *size); // (SkSize *size) -> sk_i_size_t
        func toFloor() -> ISize {
            let handle = SkSize_toFloor(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }

        // // static

        init(pointer: Skia.SizeMutablePointer?, handle: sk_size_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkSize_Make(float w, float h); // (SkScalar w, SkScalar h) -> sk_size_t
        static func Make(w: Float, h: Float) -> Size {
            let handle = SkSize_Make(w, h);
            let pointer = static_sk_size_get_ptr(handle)
            return Size(pointer: pointer, handle: handle)
        }
        // int SkSize_Make_2(const void *src); // (const SkISize *src) -> sk_size_t
        static func Make(src: Skia.ISizeConstPointer?) -> Size {
            let handle = SkSize_Make_2(src);
            let pointer = static_sk_size_get_ptr(handle)
            return Size(pointer: pointer, handle: handle)
        }
        // int SkSize_MakeEmpty(); // () -> sk_size_t
        static func MakeEmpty() -> Size {
            let handle = SkSize_MakeEmpty();
            let pointer = static_sk_size_get_ptr(handle)
            return Size(pointer: pointer, handle: handle)
        }
    }
}