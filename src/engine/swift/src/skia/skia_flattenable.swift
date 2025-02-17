extension Skia {
    enum SkFlattenableType: Int32 {
        case colorFilter
        case blender
        case drawable
        case imageFilter
        case maskFilter
        case pathEffect
        case shader
    }

    class SkFlattenableFactory {
        public var pointer: SkFlattenableFactoryMutablePointer?
        public var handle: sk_flattenable_factory_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_flattenable_factory_delete(self.handle)
            } else {
                // SkFlattenableFactory_delete(self.pointer)
            }
        }

        init(pointer: SkFlattenableFactoryMutablePointer?, handle: sk_flattenable_factory_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }

    class SkFlattenable {
        public var pointer: SkFlattenableMutablePointer?
        public var handle: sk_flattenable_t = -1

        // void SkFlattenable_delete(void *flattenable); // (SkFlattenable *flattenable)
        deinit {
            if self.handle > -1 {
                static_sk_flattenable_delete(self.handle)
            } else {
                SkFlattenable_delete(self.pointer)
            }
        }

        // int SkFlattenable_getFactory(void *flattenable); // (SkFlattenable *flattenable) -> sk_flattenable_factory_t
        func getFactory() -> SkFlattenable {
            let handle = SkFlattenable_getFactory(self.pointer)
            let pointer = static_sk_flattenable_get(handle)
            return SkFlattenable(pointer: pointer, handle: handle)
        }
        // const char * SkFlattenable_getTypeName(void *flattenable); // (SkFlattenable *flattenable) -> const char *
        func getTypeName() -> UnsafePointer<CChar>? {
            return SkFlattenable_getTypeName(self.pointer)
        }
        func getTypeName() -> String? {
            guard let cstr = SkFlattenable_getTypeName(self.pointer) else {
                return nil
            }
            return String(cString: cstr)
        }

        // void SkFlattenable_flatten(void *flattenable, void *write_buffer); // (SkFlattenable *flattenable, SkWriteBuffer *write_buffer)

        func flatten(writeBuffer: SkWriteBuffer) {
            SkFlattenable_flatten(self.pointer, writeBuffer.pointer)
        }
        // int SkFlattenable_getFlattenableType(void *flattenable); // (SkFlattenable *flattenable) -> SkFlattenable::Type

        func getFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkFlattenable_getFlattenableType(self.pointer))!
        }

        // int SkFlattenable_serialize(void *flattenable, const void * serial_procs); // (SkFlattenable *flattenable, const SkSerialProcs *serial_procs) -> sk_data_t

        func serialize(serialProcs: SkSerialProcs) -> SkData {
            let handle = SkFlattenable_serialize(self.pointer, serialProcs.pointer)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // unsigned long SkFlattenable_serialize_2(void *flattenable, void *memory, unsigned long memory_size, const void * serial_procs); // (SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t

        func serialize(memory: UnsafeMutableRawPointer, memorySize: UInt, serialProcs: SkSerialProcs) -> UInt {
            return UInt(SkFlattenable_serialize_2(self.pointer, memory, memorySize, serialProcs.pointer))
        }
        // bool SkFlattenable_unique(void *flattenable); // (SkFlattenable *flattenable) -> bool

        func unique() -> Bool {
            return SkFlattenable_unique(self.pointer)
        }
        // void SkFlattenable_ref(void *flattenable); // (SkFlattenable *flattenable)

        func ref() {
            SkFlattenable_ref(self.pointer)
        }
        // void SkFlattenable_unref(void *flattenable); // (SkFlattenable *flattenable)

        func unref() {
            SkFlattenable_unref(self.pointer)
        }

        // // static

        init(pointer: SkFlattenableMutablePointer?, handle: sk_flattenable_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkFlattenable_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        static func NameToFactory(name: UnsafePointer<CChar>?) -> Int32 {
            return SkFlattenable_NameToFactory(name)
        }
        static func NameToFactory(name: String) -> Int32 {
            return name.withCString { cstr in
                return SkFlattenable_NameToFactory(cstr)
            }
        }
        // const char * SkFlattenable_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func FactoryToName(factory: Int32) -> UnsafePointer<CChar>? {
            return SkFlattenable_FactoryToName(factory)
        }
        static func FactoryToName(factory: Int32) -> String? {
            guard let cstr = SkFlattenable_FactoryToName(factory) else {
                return nil
            }
            return String(cString: cstr)
        }
        // void SkFlattenable_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        static func Register(name: UnsafePointer<CChar>?, factory: Int32) {
            SkFlattenable_Register(name, factory)
        }
        static func Register(name: String, factory: Int32) {
            name.withCString { cstr in
                SkFlattenable_Register(cstr, factory)
            }
        }
        // int SkFlattenable_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> int
        static func Deserialize(type: Int32, data: UnsafeRawPointer, length: UInt, procs: UnsafeRawPointer) -> Int32 {
            return SkFlattenable_Deserialize(type, data, length, procs)
        }

    }
}