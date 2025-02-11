extension Skia {
    protocol SkMaskProtocol {
        var pointer: SkMaskMutablePointer? { get set }
        var handle: sk_mask_t { get set }
        // deinit
        init(pointer: SkMaskMutablePointer?, handle: sk_mask_t)
        init (img: UnsafeRawPointer?, bounds: SkIRect, rowBytes: UInt32, format: Int32) // int SkMask_new(const void * img, const void * bounds, unsigned int rowBytes, int format); // (const uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> sk_mask_t
        // Static Methods
        static func IsValidFormat(format: UInt) -> Bool // static bool SkMask_IsValidFormat(unsigned int format); // (uint8_t format) -> bool
        // Methods
        func fImage() -> UnsafePointer<UInt8>? // const void * SkMask_fImage(void *mask); // (SkMask *mask) -> const uint8_t *
        func fBounds() -> SkIRect // int SkMask_fBounds(void *mask); // (SkMask *mask) -> sk_i_rect_t
        func fRowBytes() -> UInt // unsigned int SkMask_fRowBytes(void *mask); // (SkMask *mask) -> uint32_t
        func fFormat() -> Int // int SkMask_fFormat(void *mask); // (SkMask *mask) -> SkMask::Format
        func isEmpty() -> Bool // bool SkMask_isEmpty(void *mask); // (SkMask *mask) -> bool
        func computeImageSize() -> UInt // unsigned long SkMask_computeImageSize(void *mask); // (SkMask *mask) -> size_t
        func computeTotalImageSize() -> UInt // unsigned long SkMask_computeTotalImageSize(void *mask); // (SkMask *mask) -> size_t
        func getAddr1(x: Int, y: Int) -> UnsafePointer<UInt8>? // const void* SkMask_getAddr1(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
        func getAddr8(x: Int, y: Int) -> UnsafePointer<UInt8>? // const void* SkMask_getAddr8(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
        func getAddrLCD16(x: Int, y: Int) -> UnsafePointer<UInt16>? // const void* SkMask_getAddrLCD16(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint16_t*
        func getAddr32(x: Int, y: Int) -> UnsafePointer<UInt32>? // const void* SkMask_getAddr32(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint32_t*
        func getAddr(x: Int, y: Int) -> UnsafeRawPointer? // const void* SkMask_getAddr(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const void*
    }

    class SkMask : SkMaskProtocol {
        public var pointer: SkMaskMutablePointer?
        public var handle: sk_mask_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_mask_delete(self.handle)
            } else {
                SkMask_delete(self.pointer)
            }
        }

        required init(pointer: SkMaskMutablePointer?, handle: sk_mask_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init (img: UnsafeRawPointer?, bounds: SkIRect, rowBytes: UInt32, format: Int32) {
            let handle = SkMask_new(img, bounds.pointer, rowBytes, format)
            let pointer = static_sk_mask_get_ptr(handle)
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func IsValidFormat(format: UInt) -> Bool {
            return SkMask_IsValidFormat(UInt32(format))
        }

        // Methods

        func fImage() -> UnsafePointer<UInt8>? {
            return SkMask_fImage(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }

        func fBounds() -> SkIRect {
            let handle = SkMask_fBounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        func fRowBytes() -> UInt {
            return UInt(SkMask_fRowBytes(self.pointer))
        }

        func fFormat() -> Int {
            return Int(SkMask_fFormat(self.pointer))
        }

        func isEmpty() -> Bool {
            return SkMask_isEmpty(self.pointer)
        }

        func computeImageSize() -> UInt {
            return UInt(SkMask_computeImageSize(self.pointer))
        }

        func computeTotalImageSize() -> UInt {
            return UInt(SkMask_computeTotalImageSize(self.pointer))
        }

        func getAddr1(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkMask_getAddr1(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func getAddr8(x: Int, y: Int) -> UnsafePointer<UInt8>? {
            return SkMask_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func getAddrLCD16(x: Int, y: Int) -> UnsafePointer<UInt16>? {
            return SkMask_getAddrLCD16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func getAddr32(x: Int, y: Int) -> UnsafePointer<UInt32>? {
            return SkMask_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }

        func getAddr(x: Int, y: Int) -> UnsafeRawPointer? {
            return SkMask_getAddr(self.pointer, Int32(x), Int32(y))
        }
    }
}