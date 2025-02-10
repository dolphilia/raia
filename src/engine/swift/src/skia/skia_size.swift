extension Skia {
    protocol SkSizeProtocol {
        var pointer: Skia.SkSizeMutablePointer? { get set }
        var handle: sk_size_t { get set }
        // deinit // void SkSize_delete(void *size); // (SkSize *size)
        init(pointer: Skia.SkSizeMutablePointer?, handle: sk_size_t)
        // Static Methods
        static func Make(w: Float, h: Float) -> SkSize // int SkSize_Make(float w, float h); // (SkScalar w, SkScalar h) -> sk_size_t
        static func Make(src: Skia.ISizeConstPointer?) -> SkSize // int SkSize_Make_2(const void *src); // (const SkISize *src) -> sk_size_t
        static func MakeEmpty() -> SkSize // int SkSize_MakeEmpty(); // () -> sk_size_t
        // Methods
        func set(w: Float, h: Float) // void SkSize_set(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h)
        func isZero() -> Bool // bool SkSize_isZero(void *size); // (SkSize *size) -> bool
        func isEmpty() -> Bool // bool SkSize_isEmpty(void *size); // (SkSize *size) -> bool
        func setEmpty() // void SkSize_setEmpty(void *size); // (SkSize *size)
        func width() -> Float // float SkSize_width(void *size); // (SkSize *size) -> SkScalar
        func height() -> Float // float SkSize_height(void *size); // (SkSize *size) -> SkScalar
        func equals(w: Float, h: Float) -> Bool // bool SkSize_equals(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h) -> bool
        func toRound() -> ISize // int SkSize_toRound(void *size); // (SkSize *size) -> sk_i_size_t
        func toCeil() -> ISize // int SkSize_toCeil(void *size); // (SkSize *size) -> sk_i_size_t
        func toFloor() -> ISize // int SkSize_toFloor(void *size); // (SkSize *size) -> sk_i_size_t
    }

    class SkSize : SkSizeProtocol {
        public var pointer: Skia.SkSizeMutablePointer?
        public var handle: sk_size_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_size_delete(self.handle)
            } else {
                SkSize_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkSizeMutablePointer?, handle: sk_size_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(w: Float, h: Float) -> SkSize {
            let handle = SkSize_Make(w, h);
            let pointer = static_sk_size_get_ptr(handle)
            return SkSize(pointer: pointer, handle: handle)
        }

        static func Make(src: Skia.ISizeConstPointer?) -> SkSize {
            let handle = SkSize_Make_2(src);
            let pointer = static_sk_size_get_ptr(handle)
            return SkSize(pointer: pointer, handle: handle)
        }

        static func MakeEmpty() -> SkSize {
            let handle = SkSize_MakeEmpty();
            let pointer = static_sk_size_get_ptr(handle)
            return SkSize(pointer: pointer, handle: handle)
        }

        // Methods

        func set(w: Float, h: Float) {
            SkSize_set(self.pointer, w, h)
        }

        func isZero() -> Bool {
            return SkSize_isZero(self.pointer)
        }

        func isEmpty() -> Bool {
            return SkSize_isEmpty(self.pointer)
        }

        func setEmpty() {
            SkSize_setEmpty(self.pointer)
        }

        func width() -> Float {
            return SkSize_width(self.pointer)
        }

        func height() -> Float {
            return SkSize_height(self.pointer)
        }

        func equals(w: Float, h: Float) -> Bool {
            return SkSize_equals(self.pointer, w, h)
        }

        func toRound() -> ISize {
            let handle = SkSize_toRound(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }

        func toCeil() -> ISize {
            let handle = SkSize_toCeil(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }

        func toFloor() -> ISize {
            let handle = SkSize_toFloor(self.pointer);
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
    }
}