extension Skia {
    class SkPathEffect {
        public var pointer: SkPathEffectMutablePointer?
        public var handle: sk_path_effect_t = -1

        // void SkPathEffect_delete(void * pathEffect);
        deinit {
            SkPathEffect_delete(pointer)
        }
        // int SkPathEffect_asADash(void *path_effect, void *info); // (void *path_effect, void *info) -> int
        
        // bool SkPathEffect_filterPath(void *path_effect, void *dst, const void *src, void *rec, const void *cullR); // (void *path_effect, void *dst, const void *src, void *rec, const void *cullR) -> bool
        // bool SkPathEffect_filterPath_2(void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm); // (void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm) -> bool
        // bool SkPathEffect_needsCTM(void *path_effect); // (void *path_effect) -> bool
        // int SkPathEffect_getFactory(void *path_effect); // (void *path_effect) -> sk_flattenable_factory_t
        // const char * SkPathEffect_getTypeName(void *path_effect); // (void *path_effect) -> const char *
        // void SkPathEffect_flatten(void *path_effect, void *buffer); // (void *path_effect, void *buffer)
        // int SkPathEffect_getFlattenableType(void *path_effect); // (void *path_effect) -> int
        // int SkPathEffect_serialize(void *path_effect, const void *procs); // (void *path_effect, const void *procs) -> sk_data_t
        // unsigned long SkPathEffect_serialize_2(void *path_effect, void *memory, unsigned long memory_size, const void *procs); // void *path_effect, void *memory, size_t memory_size, const void *procs) -> size_t
        // bool SkPathEffect_unique(void *path_effect); // (void *path_effect) -> bool
        // void SkPathEffect_ref(void *path_effect); // (void *path_effect)
        // void SkPathEffect_unref(void *path_effect); // (void *path_effect)
        // // static
        init(pointer: SkPathEffectMutablePointer?, handle: Int32) {
            self.pointer = pointer
            self.handle = handle
        }
        // int SkPathEffect_MakeSum(int first, int second); // (sk_path_effect_t first, sk_path_effect_t second) -> sk_path_effect_t
        static func MakeSum(first: SkPathEffect, second: SkPathEffect) -> SkPathEffect {
           let handle = SkPathEffect_MakeSum(first.handle, second.handle)
           let pointer = static_sk_path_effect_get(handle)
           return SkPathEffect(pointer: pointer, handle: handle)
            //return SkPathEffect(pointer: , handle: -1)
        }
        // int SkPathEffect_MakeCompose(int outer, int inner); //  (sk_path_effect_t outer, sk_path_effect_t inner) -> sk_path_effect_t
        static func MakeCompose(outer: SkPathEffect, inner: SkPathEffect) -> SkPathEffect {
            let handle = SkPathEffect_MakeCompose(outer.handle, inner.handle)
            let pointer = static_sk_path_effect_get(handle)
            return SkPathEffect(pointer: pointer, handle: handle)
        }
        // int SkPathEffect_GetFlattenableType(); // () -> int
        static func GetFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkPathEffect_GetFlattenableType())!
        }
        // int SkPathEffect_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const void *procs) -> sk_path_effect_t
        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: UnsafeRawPointer) -> SkPathEffect {
            let handle = SkPathEffect_Deserialize(data, size, procs)
            let pointer = static_sk_path_effect_get(handle)
            return SkPathEffect(pointer: pointer, handle: handle)
        }
        // int SkPathEffect_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        // const char * SkPathEffect_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        // void SkPathEffect_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)


    }
}