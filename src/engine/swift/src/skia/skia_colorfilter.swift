extension Skia {
    class ColorFilter {
        public var pointer: Skia.ColorFilterMutablePointer?
        public var handle: sk_color_filter_t?

        // void SkColorFilter_delete(void *color_filter); // (SkColorFilter *color_filter)
        deinit {
            SkColorFilter_delete(self.pointer)
            if let handle = self.handle {
                static_sk_color_filter_delete(handle)
            }
        }
        // bool SkColorFilter_asAColorMode(void *color_filter, void *color, void *mode); // (SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode) -> bool
        // bool SkColorFilter_asAColorMatrix(void *color_filter, float matrix[20]); // (SkColorFilter *color_filter, float matrix[20]) -> bool
        // bool SkColorFilter_isAlphaUnchanged(void *color_filter); // (SkColorFilter *color_filter) -> bool
        // unsigned int  SkColorFilter_filterColor(void *color_filter, unsigned int  color); // (SkColorFilter *color_filter, SkColor color) -> SkColor
        // int SkColorFilter_filterColor4f(void *color_filter, const void *srcColor, void *srcCS, void *dstCS); // (SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) -> sk_color_4f_t
        // int SkColorFilter_makeComposed(void *color_filter, int inner); // (SkColorFilter *color_filter, sk_color_filter_t inner) -> sk_color_filter_t
        // int SkColorFilter_makeWithWorkingColorSpace(void *color_filter, int colorSpace); // (SkColorFilter *color_filter, sk_color_space_t colorSpace) -> sk_color_filter_t
        // int SkColorFilter_getFactory(void *color_filter); // (SkColorFilter *color_filter) -> sk_flattenable_factory_t
        // const char *SkColorFilter_getTypeName(void *color_filter); // (SkColorFilter *color_filter) -> const char *
        // void SkColorFilter_flatten(void *color_filter, void *write_buffer); // (SkColorFilter *color_filter, SkWriteBuffer *write_buffer)
        // int SkColorFilter_getFlattenableType(void *color_filter); // (SkColorFilter *color_filter) -> SkColorFilter::Type
        // int SkColorFilter_serialize(void *color_filter, const void *serial_procs); // (SkColorFilter *color_filter, const SkSerialProcs *serial_procs) -> sk_data_t
        // unsigned long SkColorFilter_serialize_2(void *color_filter, void *memory, unsigned long memory_size, const void *serial_procs); // (SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        // bool SkColorFilter_unique(void *color_filter); // (SkColorFilter *color_filter) -> bool
        // void SkColorFilter_ref(void *color_filter); // (SkColorFilter *color_filter)
        // void SkColorFilter_unref(void *color_filter); // (SkColorFilter *color_filter)

        // // static

        init(pointer: Skia.ColorFilterMutablePointer?, handle: sk_color_filter_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkColorFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_color_filter_t
        static func Deserialize(data: UnsafeRawPointer?, size: UInt, procs: UnsafeRawPointer?) -> ColorFilter {
            let handle = SkColorFilter_Deserialize(data, size, procs)
            let pointer = static_sk_color_filter_get(handle)
            return ColorFilter(pointer: pointer, handle: handle)
        }
        // int SkColorFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        static func NameToFactory(name: UnsafePointer<CChar>?) -> Flattenable {
            let handle = SkColorFilter_NameToFactory(name)
            let pointer = static_sk_flattenable_get(handle)
            return Flattenable(pointer: pointer, handle: handle)
        }
        // const char *SkColorFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func FactoryToName(factory: Flattenable) -> UnsafePointer<CChar>? {
            guard let handle = factory.handle else {
                return nil
            }
            return SkColorFilter_FactoryToName(handle)
        }
        static func FactoryToName(factory: Flattenable) -> String? {
            guard let handle = factory.handle else {
                return nil
            }
            guard let cstr = SkColorFilter_FactoryToName(handle) else {
                return nil
            }
            return String(cString: cstr)
        }
        // void SkColorFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        static func Register(name: UnsafePointer<CChar>?, factory: Flattenable) {
            guard let handle = factory.handle else {
                return
            }
            SkColorFilter_Register(name, handle)
        }
        static func Register(name: String, factory: Flattenable) {
            guard let handle = factory.handle else {
                return
            }
            name.withCString { cstr in
                SkColorFilter_Register(cstr, handle)
            }
        }

    }
}