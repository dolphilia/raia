extension Skia {
    public enum SkMaskBuilderAllocType: Int32 {
        case kUninit_Alloc
        case kZeroInit_Alloc
    }

    protocol SkMaskBuilderProtocol {
        var pointer: SkMaskBuilderMutablePointer? { get set }
        var handle: sk_mask_builder_t { get set }
        // deinit // void SkMaskBuilder_delete(void * maskBuilder); // (SkMaskBuilder* maskBuilder)
        init(pointer: SkMaskBuilderMutablePointer?, handle: sk_mask_builder_t)
        init() // void * SkMaskBuilder_new(); // () -> SkMaskBuilder *
        init(img: UnsafeMutablePointer<UInt8>?, bounds: SkIRect, rowBytes: UInt32, format: Int32) // void * SkMaskBuilder_new_2(void * img, const void * bounds, unsigned int rowBytes, int format); // (uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> SkMaskBuilder *
        // Static Methods
        static func AllocImage(bytes: UInt, alloc: SkMaskBuilderAllocType) -> UnsafeMutableRawPointer? // static void * SkMaskBuilder_AllocImage(unsigned long bytes, int alloc); // (size_t bytes, SkMaskBuilder::AllocType alloc) -> uint8_t*
        static func FreeImage(image: UnsafeMutableRawPointer?) // static void SkMaskBuilder_FreeImage(void * image); // (void* image)
        static func PrepareDestination(radiusX: Int, radiusY: Int, src: SkMask) -> SkMaskBuilder // static int SkMaskBuilder_PrepareDestination(int radiusX, int radiusY, const void * src); // (int radiusX, int radiusY, const SkMask * src) -> sk_mask_builder_t
        // Methods
        func image() -> UnsafeMutablePointer<UInt8>? // void * SkMaskBuilder_image(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint8_t*
        func bounds() -> SkIRect // void * SkMaskBuilder_bounds(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkIRect *
        func rowBytes() -> UInt // unsigned int SkMaskBuilder_rowBytes(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint32_t
        func format() -> Int // int SkMaskBuilder_format(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkMask::Format
        func getAddr1(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? // void * SkMaskBuilder_getAddr1(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? // void * SkMaskBuilder_getAddr8(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
        func getAddrLCD16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? // void * SkMaskBuilder_getAddrLCD16(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint16_t*
        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? // void * SkMaskBuilder_getAddr32(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint32_t*
        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? // void * SkMaskBuilder_getAddr(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> void*
    }

    class SkMaskBuilder : SkMaskBuilderProtocol {
        public var pointer: SkMaskBuilderMutablePointer?
        public var handle: sk_mask_builder_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_mask_builder_delete(self.handle)
            } else {
                SkMaskBuilder_delete(self.pointer)
            }
        }

        required init(pointer: SkMaskBuilderMutablePointer?, handle: sk_mask_builder_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            let pointer = SkMaskBuilder_new()
            self.pointer = pointer
            self.handle = -1
        }

        required init(img: UnsafeMutablePointer<UInt8>?, bounds: SkIRect, rowBytes: UInt32, format: Int32) {
            let pointer = SkMaskBuilder_new_2(img, bounds.pointer, rowBytes, format)
            self.pointer = pointer
            self.handle = -1
        }

        // Static Methods

        static func AllocImage(bytes: UInt, alloc: SkMaskBuilderAllocType) -> UnsafeMutableRawPointer? {
            return SkMaskBuilder_AllocImage(bytes, alloc.rawValue)
        }

        static func FreeImage(image: UnsafeMutableRawPointer?) {
            SkMaskBuilder_FreeImage(image)
        }

        static func PrepareDestination(radiusX: Int, radiusY: Int, src: SkMask) -> SkMaskBuilder {
            let handle = SkMaskBuilder_PrepareDestination(Int32(radiusX), Int32(radiusY), src.pointer)
            let pointer = static_sk_mask_builder_get_ptr(handle)
            return SkMaskBuilder(pointer: pointer, handle: handle)
        }

        // Methods

        func image() -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_image(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }

        func bounds() -> SkIRect {
            let pointer = SkMaskBuilder_bounds(self.pointer)
            return SkIRect(pointer: pointer, handle: -1)
        }

        func rowBytes() -> UInt {
            return UInt(SkMaskBuilder_rowBytes(self.pointer))
        }

        func format() -> Int {
            return Int(SkMaskBuilder_format(self.pointer))
        }

        func getAddr1(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_getAddr1(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }

        func getAddrLCD16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkMaskBuilder_getAddrLCD16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }

        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkMaskBuilder_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }

        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkMaskBuilder_getAddr(self.pointer, Int32(x), Int32(y))
        }
    }
}