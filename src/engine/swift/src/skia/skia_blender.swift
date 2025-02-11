extension Skia {
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
        // const char *SkBlender_getTypeName(void *blender); // (SkBlender *blender) -> const char *
        // void SkBlender_flatten(void *blender, void *write_buffer); // (SkBlender *blender, SkWriteBuffer *write_buffer)
        // int SkBlender_getFlattenableType(void *blender); // (SkBlender *blender) -> SkBlender::Type
        // int SkBlender_serialize(void *blender, const void *serial_procs); // (SkBlender *blender, const SkSerialProcs *serial_procs) -> sk_data_t
        // unsigned long SkBlender_serialize_2(void *blender, void *memory, unsigned long memory_size, const void *serial_procs); // (SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        // bool SkBlender_unique(void *blender); // (SkBlender *blender) -> bool
        // void SkBlender_ref(void *blender); // (SkBlender *blender)
        // void SkBlender_unref(void *blender); // (SkBlender *blender)

        // // static

        init(pointer: SkBlenderMutablePointer?, handle: sk_blender_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkBlender_Mode(int mode); // (SkBlendMode mode) -> sk_blender_t
        // int SkBlender_NameToFactory(const char * name); // (const char *name) -> sk_flattenable_factory_t
        // const char *SkBlender_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        // void SkBlender_Register(const char * name, int factory); // (const char *name, sk_flattenable_factory_t factory)
        // int SkBlender_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> sk_flattenable_t

    }
}