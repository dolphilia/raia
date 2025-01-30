extension Skia {
    class MaskBuilder {

        public enum AllocType: Int32 {
            case kUninit_Alloc
            case kZeroInit_Alloc
        }


        public var pointer: MaskBuilderMutablePointer?
        public var handle: sk_mask_builder_t?

        // void SkMaskBuilder_delete(void * maskBuilder); // (SkMaskBuilder* maskBuilder)

        deinit {
            SkMaskBuilder_delete(self.pointer)
            if let handle = self.handle {
                static_sk_mask_builder_delete(handle)
            }
        }

        // void * SkMaskBuilder_new(); // () -> SkMaskBuilder *
        init() {
            let pointer = SkMaskBuilder_new()
            //let pointer = static_sk_mask_builder_get_ptr(handle)
            self.pointer = pointer
            self.handle = nil
        }
        // void * SkMaskBuilder_new_2(void * img, const void * bounds, unsigned int rowBytes, int format); // (uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> SkMaskBuilder *
        init(img: UnsafeMutablePointer<UInt8>?, bounds: IRect, rowBytes: UInt32, format: Int32) {
            let pointer = SkMaskBuilder_new_2(img, bounds.pointer, rowBytes, format)
            self.pointer = pointer
            self.handle = nil
        }
        
        // void * SkMaskBuilder_image(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint8_t*
        func image() -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_image(self.pointer)?.assumingMemoryBound(to: UInt8.self)
        }
        // void * SkMaskBuilder_bounds(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkIRect *
        func bounds() -> IRect {
            let pointer = SkMaskBuilder_bounds(self.pointer)
            return IRect(pointer: pointer, handle: nil)
        }
        // unsigned int SkMaskBuilder_rowBytes(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint32_t
        func rowBytes() -> UInt {
            return UInt(SkMaskBuilder_rowBytes(self.pointer))
        }
        // int SkMaskBuilder_format(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkMask::Format
        func format() -> Int {
            return Int(SkMaskBuilder_format(self.pointer))
        }
        // void * SkMaskBuilder_getAddr1(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
        func getAddr1(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_getAddr1(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // void * SkMaskBuilder_getAddr8(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
        func getAddr8(x: Int, y: Int) -> UnsafeMutablePointer<UInt8>? {
            return SkMaskBuilder_getAddr8(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt8.self)
        }
        // void * SkMaskBuilder_getAddrLCD16(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint16_t*
        func getAddrLCD16(x: Int, y: Int) -> UnsafeMutablePointer<UInt16>? {
            return SkMaskBuilder_getAddrLCD16(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt16.self)
        }
        // void * SkMaskBuilder_getAddr32(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint32_t*
        func getAddr32(x: Int, y: Int) -> UnsafeMutablePointer<UInt32>? {
            return SkMaskBuilder_getAddr32(self.pointer, Int32(x), Int32(y))?.assumingMemoryBound(to: UInt32.self)
        }
        // void * SkMaskBuilder_getAddr(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> void*
        func getAddr(x: Int, y: Int) -> UnsafeMutableRawPointer? {
            return SkMaskBuilder_getAddr(self.pointer, Int32(x), Int32(y))
        }
        // // static

        init(pointer: MaskBuilderMutablePointer?, handle: sk_mask_builder_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // static void * SkMaskBuilder_AllocImage(unsigned long bytes, int alloc); // (size_t bytes, SkMaskBuilder::AllocType alloc) -> uint8_t*

        static func AllocImage(bytes: UInt, alloc: AllocType) -> UnsafeMutableRawPointer? {
            return SkMaskBuilder_AllocImage(bytes, alloc.rawValue)
        }

        // static void SkMaskBuilder_FreeImage(void * image); // (void* image)

        static func FreeImage(image: UnsafeMutableRawPointer?) {
            SkMaskBuilder_FreeImage(image)
        }

        // static int SkMaskBuilder_PrepareDestination(int radiusX, int radiusY, const void * src); // (int radiusX, int radiusY, const SkMask * src) -> sk_mask_builder_t

        static func PrepareDestination(radiusX: Int, radiusY: Int, src: Mask) -> MaskBuilder {
            let handle = SkMaskBuilder_PrepareDestination(Int32(radiusX), Int32(radiusY), src.pointer)
            let pointer = static_sk_mask_builder_get_ptr(handle)
            return MaskBuilder(pointer: pointer, handle: handle)
        }

    }
}