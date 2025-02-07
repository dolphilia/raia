extension Skia {
    class PixelRef {
        public var pointer: Skia.PixelRefMutablePointer?
        public var handle: sk_pixel_ref_t = -1

        // void *SkPixelRef_new(int width, int height, void *addr, unsigned long rowBytes); // (int width, int height, void *addr, size_t rowBytes) -> SkPixelRef *
        init(width: Int32, height: Int32, addr: UnsafeMutableRawPointer?, rowBytes: UInt) {
            self.pointer = SkPixelRef_new(width, height, addr, rowBytes)
            self.handle = -1
        }
        // void SkPixelRef_delete(void *pixel_ref); // (SkPixelRef *pixel_ref)
        deinit {
            SkPixelRef_delete(self.pointer)
            if handle > -1 {
                static_sk_pixel_ref_delete(handle)
            }
        }
        // int SkPixelRef_dimensions(void *pixel_ref); // (SkPixelRef *pixel_ref) -> sk_i_size_t
        func dimensions() -> ISize {
            let handle = SkPixelRef_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return ISize(pointer: pointer, handle: handle)
        }
        // int SkPixelRef_width(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
        func width() -> Int {
            return Int(SkPixelRef_width(self.pointer))
        }
        // int SkPixelRef_height(void *pixel_ref); // (SkPixelRef *pixel_ref) -> int
        func height() -> Int {
            return Int(SkPixelRef_height(self.pointer))
        }
        // void * SkPixelRef_pixels(void *pixel_ref); // (SkPixelRef *pixel_ref) -> void *
        func pixels() -> UnsafeMutableRawPointer? {
            return SkPixelRef_pixels(self.pointer)
        }
        // unsigned long SkPixelRef_rowBytes(void *pixel_ref); // (SkPixelRef *pixel_ref) -> size_t
        func rowBytes() -> UInt {
            return SkPixelRef_rowBytes(self.pointer)
        }
        // unsigned int SkPixelRef_getGenerationID(void *pixel_ref); // (SkPixelRef *pixel_ref) -> uint32_t
        func getGenerationID() -> UInt {
            return UInt(SkPixelRef_getGenerationID(self.pointer))
        }
        // void SkPixelRef_notifyPixelsChanged(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func notifyPixelsChanged() {
            SkPixelRef_notifyPixelsChanged(self.pointer)
        }
        // bool SkPixelRef_isImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
        func isImmutable() -> Bool {
            return SkPixelRef_isImmutable(self.pointer)
        }
        // void SkPixelRef_setImmutable(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func setImmutable() {
            SkPixelRef_setImmutable(self.pointer)
        }
        // void SkPixelRef_addGenIDChangeListener(void *pixel_ref, int id_change_listener); // (SkPixelRef *pixel_ref, sk_id_change_listener_t id_change_listener)
        // void SkPixelRef_notifyAddedToCache(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func notifyAddedToCache() {
            SkPixelRef_notifyAddedToCache(self.pointer)
        }
        // void * SkPixelRef_diagnostic_only_getDiscardable(void *pixel_ref); // (SkPixelRef *pixel_ref) -> SkDiscardableMemory *
        // bool SkPixelRef_unique(void *pixel_ref); // (SkPixelRef *pixel_ref) -> bool
        func unique() -> Bool {
            return SkPixelRef_unique(self.pointer)
        }
        // void SkPixelRef_ref(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func ref() {
            SkPixelRef_ref(self.pointer)
        }
        // void SkPixelRef_unref(void *pixel_ref); // (SkPixelRef *pixel_ref)
        func unref() {
            SkPixelRef_unref(self.pointer)
        }
        
        // static

        init(pointer: Skia.PixelRefMutablePointer?, handle: sk_pixel_ref_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}