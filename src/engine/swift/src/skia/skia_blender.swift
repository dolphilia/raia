extension Skia {
    enum SkBlenderType : Int32 {
        case SkColorFilter
        case SkBlender
        case SkDrawable
        case SkDrawLooper
        case SkImageFilter
        case SkMaskFilter
        case SkPathEffect
        case SkShader
    }

    class SkBlender {
        public var pointer: SkBlenderMutablePointer?
        public var handle: sk_blender_t = -1

        // void SkBlender_delete(void *blender); // (SkBlender *blender)
        deinit {
            if self.handle > -1 {
                static_sk_blender_delete(self.handle)
            } else {
                SkBlender_delete(self.pointer)
            }
        }

        // int SkBlender_getFactory(void *blender); // (SkBlender *blender) -> sk_flattenable_factory_t

        func getFactory() -> SkFlattenableFactory {
            let handle = SkBlender_getFactory(self.pointer)
            let pointer = static_sk_blender_get(handle)
            return SkFlattenableFactory(pointer: pointer, handle: handle)
        }

        // const char *SkBlender_getTypeName(void *blender); // (SkBlender *blender) -> const char *

        func getTypeName() -> String {
            return String(cString: SkBlender_getTypeName(self.pointer))
        }

        // void SkBlender_flatten(void *blender, void *write_buffer); // (SkBlender *blender, SkWriteBuffer *write_buffer)

        func flatten(buffer: SkWriteBuffer) {
            SkBlender_flatten(self.pointer, buffer.pointer)
        }

        // int SkBlender_getFlattenableType(void *blender); // (SkBlender *blender) -> SkBlender::Type

        func getFlattenableType() -> SkBlenderType {
            return SkBlenderType(rawValue: SkBlender_getFlattenableType(self.pointer))!
        }

        // int SkBlender_serialize(void *blender, const void *serial_procs); // (SkBlender *blender, const SkSerialProcs *serial_procs) -> sk_data_t

        func serialize(procs: SkSerialProcs) -> SkData {
            let handle = SkBlender_serialize(self.pointer, procs.pointer)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        // unsigned long SkBlender_serialize_2(void *blender, void *memory, unsigned long memory_size, const void *serial_procs); // (SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t

        func serialize(memory: UnsafeMutableRawPointer, memory_size: UInt, procs: SkSerialProcs) -> UInt {
            return UInt(SkBlender_serialize_2(self.pointer, memory, memory_size, procs.pointer))
        }
        // bool SkBlender_unique(void *blender); // (SkBlender *blender) -> bool

        func unique() -> Bool {
            return SkBlender_unique(self.pointer)
        }

        // void SkBlender_ref(void *blender); // (SkBlender *blender)

        func ref() {
            SkBlender_ref(self.pointer)
        }

        // void SkBlender_unref(void *blender); // (SkBlender *blender)

        func unref() {
            SkBlender_unref(self.pointer)
        }

        // // static

        init(pointer: SkBlenderMutablePointer?, handle: sk_blender_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkBlender_Mode(int mode); // (SkBlendMode mode) -> sk_blender_t
        static func Mode(mode: SkBlendMode) -> SkBlender {
            let handle = SkBlender_Mode(mode.rawValue)
            let pointer = static_sk_blender_get(handle)
            return SkBlender(pointer: pointer, handle: handle)
        }
        // int SkBlender_NameToFactory(const char * name); // (const char *name) -> sk_flattenable_factory_t

        static func NameToFactory(name: String) -> SkFlattenableFactory {
            return name.withCString { cstr in
                let handle = SkBlender_NameToFactory(cstr)
                // let pointer = static_sk_flattenable_factory_get_ptr(handle)
                return SkFlattenableFactory(pointer: nil, handle: handle)
            }
        }
        // const char *SkBlender_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *

        static func FactoryToName(factory: SkFlattenableFactory) -> String {
            return String(cString: SkBlender_FactoryToName(factory.handle))
        }
        // void SkBlender_Register(const char * name, int factory); // (const char *name, sk_flattenable_factory_t factory)


        static func Register(name: String, factory: SkFlattenableFactory) {
            name.withCString { cstr in
                SkBlender_Register(cstr, factory.handle)
            }
        }

        // int SkBlender_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> sk_flattenable_t

        static func Deserialize(type: SkBlenderType, data: UnsafeRawPointer, length: UInt, procs: SkDeserialProcs) -> SkBlender {
            let handle = SkBlender_Deserialize(type.rawValue, data, length, procs.pointer)
            let pointer = static_sk_blender_get(handle)
            return SkBlender(pointer: pointer, handle: handle)
        }
    }
}