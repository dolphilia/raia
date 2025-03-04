extension Skia {
    class SkPathEffect {
        public var pointer: SkPathEffectMutablePointer?
        public var handle: sk_path_effect_t = -1

        // void SkPathEffect_delete(void * pathEffect);
        deinit {
            SkPathEffect_delete(pointer)
        }
        // int SkPathEffect_asADash(void *path_effect, void *info); // (void *path_effect, void *info) -> int

        func asADash(info: UnsafeMutableRawPointer) -> Int {
            return Int(SkPathEffect_asADash(pointer, info))
        }
        
        // bool SkPathEffect_filterPath(void *path_effect, void *dst, const void *src, void *rec, const void *cullR); // (void *path_effect, void *dst, const void *src, void *rec, const void *cullR) -> bool

        func filterPath(dst: UnsafeMutableRawPointer, src: UnsafeRawPointer, rec: UnsafeMutableRawPointer, cullR: UnsafeRawPointer) -> Bool {
            return SkPathEffect_filterPath(pointer, dst, src, rec, cullR)
        }
        // bool SkPathEffect_filterPath_2(void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm); // (void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm) -> bool

        func filterPath(dst: UnsafeMutableRawPointer, src: UnsafeRawPointer, rec: UnsafeMutableRawPointer, cullR: UnsafeRawPointer, ctm: UnsafeRawPointer) -> Bool {
            return SkPathEffect_filterPath_2(pointer, dst, src, rec, cullR, ctm)
        }
        // bool SkPathEffect_needsCTM(void *path_effect); // (void *path_effect) -> bool

        func needsCTM() -> Bool {
            return SkPathEffect_needsCTM(pointer)
        }
        // int SkPathEffect_getFactory(void *path_effect); // (void *path_effect) -> sk_flattenable_factory_t
        // const char * SkPathEffect_getTypeName(void *path_effect); // (void *path_effect) -> const char *

        func getTypeName() -> String {
            return String(cString: SkPathEffect_getTypeName(pointer))
        }
        // void SkPathEffect_flatten(void *path_effect, void *buffer); // (void *path_effect, void *buffer)

        func flatten(buffer: UnsafeMutableRawPointer) {
            SkPathEffect_flatten(pointer, buffer)
        }
        // int SkPathEffect_getFlattenableType(void *path_effect); // (void *path_effect) -> int

        func getFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkPathEffect_getFlattenableType(pointer))!
        }
        // int SkPathEffect_serialize(void *path_effect, const void *procs); // (void *path_effect, const void *procs) -> sk_data_t

        func serialize(procs: UnsafeRawPointer) -> SkData {
            let handle = SkPathEffect_serialize(pointer, procs)
            let pointer = static_sk_data_get_ptr(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // unsigned long SkPathEffect_serialize_2(void *path_effect, void *memory, unsigned long memory_size, const void *procs); // void *path_effect, void *memory, size_t memory_size, const void *procs) -> size_t

        func serialize(memory: UnsafeMutableRawPointer, memory_size: UInt, procs: UnsafeRawPointer) -> UInt {
            return UInt(SkPathEffect_serialize_2(pointer, memory, memory_size, procs))
        }
        // bool SkPathEffect_unique(void *path_effect); // (void *path_effect) -> bool

        func unique() -> Bool {
            return SkPathEffect_unique(pointer)
        }
        // void SkPathEffect_ref(void *path_effect); // (void *path_effect)
        func ref() {
            SkPathEffect_ref(pointer)
        }
        // void SkPathEffect_unref(void *path_effect); // (void *path_effect)

        func unref() {
            SkPathEffect_unref(pointer)
        }
        // // static
        init(pointer: SkPathEffectMutablePointer?, handle: Int32) {
            self.pointer = pointer
            self.handle = handle
        }
        // int SkPathEffect_MakeSum(int first, int second); // (sk_path_effect_t first, sk_path_effect_t second) -> sk_path_effect_t
        static func MakeSum(first: SkPathEffect, second: SkPathEffect) -> SkPathEffect {
           let handle = SkPathEffect_MakeSum(first.handle, second.handle)
           let pointer = static_sk_path_effect_get_ptr(handle)
           return SkPathEffect(pointer: pointer, handle: handle)
            //return SkPathEffect(pointer: , handle: -1)
        }
        // int SkPathEffect_MakeCompose(int outer, int inner); //  (sk_path_effect_t outer, sk_path_effect_t inner) -> sk_path_effect_t
        static func MakeCompose(outer: SkPathEffect, inner: SkPathEffect) -> SkPathEffect {
            let handle = SkPathEffect_MakeCompose(outer.handle, inner.handle)
            let pointer = static_sk_path_effect_get_ptr(handle)
            return SkPathEffect(pointer: pointer, handle: handle)
        }
        // int SkPathEffect_GetFlattenableType(); // () -> int
        static func GetFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkPathEffect_GetFlattenableType())!
        }
        // int SkPathEffect_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const void *procs) -> sk_path_effect_t
        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: UnsafeRawPointer) -> SkPathEffect {
            let handle = SkPathEffect_Deserialize(data, size, procs)
            let pointer = static_sk_path_effect_get_ptr(handle)
            return SkPathEffect(pointer: pointer, handle: handle)
        }
        // int SkPathEffect_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t

        
        // const char * SkPathEffect_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        // void SkPathEffect_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)


    }
}