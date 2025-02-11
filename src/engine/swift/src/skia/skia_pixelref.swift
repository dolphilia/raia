extension Skia {
    protocol SkPixelRefProtocol {
        var pointer: SkPixelRefMutablePointer? { get set }
        var handle: sk_pixel_ref_t { get set }
        // deinit // void SkPixelRef_delete(void *pixel_ref); // (SkPixelRef *pixel_ref)
        init(pointer: SkPixelRefMutablePointer?, handle: sk_pixel_ref_t)
        init(width: Int32, height: Int32, addr: UnsafeMutableRawPointer?, rowBytes: UInt) // void *SkPixelRef_new(int width, int height, void *addr, unsigned long rowBytes); // (int width, int height, void *addr, size_t rowBytes) -> SkPixelRef *
        // Methods
        func dimensions() -> SkISize // int SkPixelRef_dimensions(void *pixel_ref); // (SkPixelRef *pixel_ref) -> sk_i_size_t
        func width() -> Int // int SkPixelRef_width(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
        func height() -> Int // int SkPixelRef_height(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
        func pixels() -> UnsafeMutableRawPointer? // void * SkPixelRef_pixels(void *pixel_ref); // (SkPixelRef *pixel_ref) -> void *
        func rowBytes() -> UInt // unsigned long SkPixelRef_rowBytes(void *pixel_ref); // (SkPixelRef *pixel_ref) -> size_t
        func getGenerationID() -> UInt // unsigned int SkPixelRef_getGenerationID(void *pixel_ref); // (SkPixelRef *pixel_ref) -> uint32_t
        func notifyPixelsChanged() // void SkPixelRef_notifyPixelsChanged(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func isImmutable() -> Bool // bool SkPixelRef_isImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
        func setImmutable() // void SkPixelRef_setImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref)
        // void SkPixelRef_addGenIDChangeListener(void *pixel_ref, int id_change_listener); // (SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener)
        func notifyAddedToCache() // void SkPixelRef_notifyAddedToCache(void *pixel_ref); // (SkPixelRef *pixel_ref)
        // void * SkPixelRef_diagnostic_only_getDiscardable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> SkDiscardableMemory *
        func unique() -> Bool // bool SkPixelRef_unique(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
        func ref() // void SkPixelRef_ref(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func unref() // void SkPixelRef_unref(void *pixel_ref); // (SkPixelRef *pixel_ref)
    }

    class SkPixelRef : SkPixelRefProtocol {
        public var pointer: SkPixelRefMutablePointer?
        public var handle: sk_pixel_ref_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_pixel_ref_delete(self.handle)
            } else {
                SkPixelRef_delete(self.pointer)
            }
        }

        required init(pointer: SkPixelRefMutablePointer?, handle: sk_pixel_ref_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init(width: Int32, height: Int32, addr: UnsafeMutableRawPointer?, rowBytes: UInt) {
            self.pointer = SkPixelRef_new(width, height, addr, rowBytes)
            self.handle = -1
        }

        // Methods

        func dimensions() -> SkISize {
            let handle = SkPixelRef_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }

        func width() -> Int {
            return Int(SkPixelRef_width(self.pointer))
        }

        func height() -> Int {
            return Int(SkPixelRef_height(self.pointer))
        }

        func pixels() -> UnsafeMutableRawPointer? {
            return SkPixelRef_pixels(self.pointer)
        }

        func rowBytes() -> UInt {
            return SkPixelRef_rowBytes(self.pointer)
        }

        func getGenerationID() -> UInt {
            return UInt(SkPixelRef_getGenerationID(self.pointer))
        }

        func notifyPixelsChanged() {
            SkPixelRef_notifyPixelsChanged(self.pointer)
        }

        func isImmutable() -> Bool {
            return SkPixelRef_isImmutable(self.pointer)
        }

        func setImmutable() {
            SkPixelRef_setImmutable(self.pointer)
        }

        // void SkPixelRef_addGenIDChangeListener(void *pixel_ref, int id_change_listener); // (SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener)

        func notifyAddedToCache() {
            SkPixelRef_notifyAddedToCache(self.pointer)
        }

        // void * SkPixelRef_diagnostic_only_getDiscardable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> SkDiscardableMemory *

        func unique() -> Bool {
            return SkPixelRef_unique(self.pointer)
        }

        func ref() {
            SkPixelRef_ref(self.pointer)
        }

        func unref() {
            SkPixelRef_unref(self.pointer)
        }
        
    }
}