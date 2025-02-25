extension Skia {
    class SkImageFilter {

        public var pointer: SkImageFilterMutablePointer?
        public var handle: sk_image_filter_t = -1
        
        // void SkImageFilter_delete(void *image_filter); // (SkImageFilter *image_filter)

        deinit {
            if self.handle > -1 {
                static_sk_image_filter_delete(self.handle)
            } else {
                SkImageFilter_delete(self.pointer)
            }
        }
        // int SkImageFilter_filterBounds(void *image_filter, const void *src, const void *ctm, int direction, const void *inputRect); // (SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect) -> sk_i_rect_t
        // bool SkImageFilter_isColorFilterNode(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool

        func isColorFilterNode(filterPtr: UnsafeMutablePointer<UnsafeMutableRawPointer?>) -> Bool {
            return SkImageFilter_isColorFilterNode(self.pointer, filterPtr)
        }
        
        // bool SkImageFilter_asColorFilter(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool

        func asColorFilter(filterPtr: UnsafeMutablePointer<UnsafeMutableRawPointer?>) -> Bool {
            return SkImageFilter_asColorFilter(self.pointer, filterPtr)
        }

        // bool SkImageFilter_asAColorFilter(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool

        func asAColorFilter(filterPtr: UnsafeMutablePointer<UnsafeMutableRawPointer?>) -> Bool {
            return SkImageFilter_asAColorFilter(self.pointer, filterPtr)
        }
        // int SkImageFilter_countInputs(void *image_filter); // (SkImageFilter *image_filter) -> int

        func countInputs() -> Int {
            return Int(SkImageFilter_countInputs(self.pointer))
        }
        // const void *SkImageFilter_getInput(void *image_filter, int i); // (SkImageFilter *image_filter, int i) -> const SkImageFilter *

        func getInput(i: Int) -> SkImageFilter {
            let pointer = SkImageFilter_getInput(self.pointer, Int32(i))
            return SkImageFilter(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // int SkImageFilter_computeFastBounds(void *image_filter, const void *bounds); // (SkImageFilter *image_filter, const SkRect *bounds) -> sk_rect_t
        
        func computeFastBounds(bounds: SkRect) -> SkRect {
            let handle = SkImageFilter_computeFastBounds(self.pointer, bounds.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }
        
        // bool SkImageFilter_canComputeFastBounds(void *image_filter); // (SkImageFilter *image_filter) -> bool

        func canComputeFastBounds() -> Bool {
            return SkImageFilter_canComputeFastBounds(self.pointer)
        }
        // int SkImageFilter_makeWithLocalMatrix(void *image_filter, const void *matrix); // (SkImageFilter *image_filter, const SkMatrix *matrix) -> sk_image_filter_t

        func makeWithLocalMatrix(matrix: SkMatrix) -> SkImageFilter {
            let handle = SkImageFilter_makeWithLocalMatrix(self.pointer, matrix.pointer)
            let pointer = static_sk_image_filter_get_ptr(handle)
            return SkImageFilter(pointer: pointer, handle: handle)
        }
        // int SkImageFilter_getFactory(void *image_filter); // (SkImageFilter *image_filter) -> sk_flattenable_factory_t
        // const char *SkImageFilter_getTypeName(void *image_filter); // (SkImageFilter *image_filter) -> const char *

        func getTypeName() -> String {
            return String(cString: SkImageFilter_getTypeName(self.pointer))
        }
        // void SkImageFilter_flatten(void *image_filter, void *buffer); // (SkImageFilter *image_filter, SkWriteBuffer *buffer)
        // int SkImageFilter_getFlattenableType(void *image_filter); // (SkImageFilter *image_filter) -> SkImageFilter::Type
        // int SkImageFilter_serialize(void *image_filter, const void *procs); // (SkImageFilter *image_filter, const SkSerialProcs *procs) -> sk_data_t
        // unsigned long SkImageFilter_serialize_2(void *image_filter, void *memory, unsigned long memory_size, const void *procs); // (SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
        // bool SkImageFilter_unique(void *image_filter); // (SkImageFilter *image_filter) -> bool

        func unique() -> Bool {
            return SkImageFilter_unique(self.pointer)
        }
        // void SkImageFilter_ref(void *image_filter); // (SkImageFilter *image_filter)

        func ref() {
            SkImageFilter_ref(self.pointer)
        }
        // void SkImageFilter_unref(void *image_filter); // (SkImageFilter *image_filter)

        func unref() {
            SkImageFilter_unref(self.pointer)
        }

        // // static

        init(pointer: SkImageFilterMutablePointer?, handle: sk_image_filter_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkImageFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_image_filter_t
        // int SkImageFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        // const char *SkImageFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        // void SkImageFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)

    }
}