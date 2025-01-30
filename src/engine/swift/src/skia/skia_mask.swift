extension Skia {
    class Mask {
        public var pointer: MaskMutablePointer?
        public var handle: sk_mask_t

        deinit {
            SkMask_delete(self.pointer)
            static_sk_mask_delete(self.handle)
        }

        // int SkMask_new(const void * img, const void * bounds, unsigned int rowBytes, int format); // (const uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> sk_mask_t
        init (img: UnsafeRawPointer?, bounds: IRect, rowBytes: UInt32, format: Int32) {
            let handle = SkMask_new(img, bounds.pointer, rowBytes, format)
            let pointer = static_sk_mask_get_ptr(handle)
            self.pointer = pointer
            self.handle = handle
        }

        // // member

        // const void * SkMask_fImage(void *mask); // (SkMask *mask) -> const uint8_t *
        func fImage() -> UnsafePointer<UInt8>? {
            return SkMask_fImage(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }
        // int SkMask_fBounds(void *mask); // (SkMask *mask) -> sk_i_rect_t
        func fBounds() -> IRect {
            let handle = SkMask_fBounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return IRect(pointer: pointer, handle: handle)
        }
        // unsigned int SkMask_fRowBytes(void *mask); // (SkMask *mask) -> uint32_t
        func fRowBytes() -> UInt {
            return UInt(SkMask_fRowBytes(self.pointer))
        }
        // int SkMask_fFormat(void *mask); // (SkMask *mask) -> SkMask::Format
        func fFormat() -> Int {
            return Int(SkMask_fFormat(self.pointer))
        }

        // // Method
        // bool SkMask_isEmpty(void *mask); // (SkMask *mask) -> bool
        func isEmpty() -> Bool {
            return SkMask_isEmpty(self.pointer)
        }
        // unsigned long SkMask_computeImageSize(void *mask); // (SkMask *mask) -> size_t
        func computeImageSize() -> UInt {
            return UInt(SkMask_computeImageSize(self.pointer))
        }
        // unsigned long SkMask_computeTotalImageSize(void *mask); // (SkMask *mask) -> size_t
        func computeTotalImageSize() -> UInt {
            return UInt(SkMask_computeTotalImageSize(self.pointer))
        }
        // const void* SkMask_getAddr1(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
        func getAddr1(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkMask_getAddr1(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // const void* SkMask_getAddr8(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
        func getAddr8(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkMask_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // const void* SkMask_getAddrLCD16(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint16_t*
        func getAddrLCD16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkMask_getAddrLCD16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // const void* SkMask_getAddr32(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint32_t*
        func getAddr32(x: Int, y: Int) -> UnsafePointer<UInt32>? {
            return SkMask_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }
        // const void* SkMask_getAddr(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const void*
        func getAddr(x: Int, y: Int) -> UnsafeRawPointer? {
            return SkMask_getAddr(self.pointer, Int32(x), Int32(y))
        }

        // // static

        init(pointer: MaskMutablePointer?, handle: sk_mask_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // static bool SkMask_IsValidFormat(unsigned int format); // (uint8_t format) -> bool
        static func IsValidFormat(format: UInt) -> Bool {
            return SkMask_IsValidFormat(UInt32(format))
        }
    }
}