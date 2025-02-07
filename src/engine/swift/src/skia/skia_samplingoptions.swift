extension Skia {
    class SamplingOptions {
        public var pointer: Skia.SamplingOptionsMutablePointer?
        public var handle: sk_sampling_options_t = -1

        // void *SkSamplingOptions_new(); // () -> SkSamplingOptions *
        init() {
            self.pointer = SkSamplingOptions_new();
            self.handle = -1
        }
        // void *SkSamplingOptions_new_2(const void *options); // (const SkSamplingOptions *options) -> SkSamplingOptions *
        init(options: SamplingOptions) {
            self.pointer = SkSamplingOptions_new_2(options.pointer);
            self.handle = -1
        }
        // void *SkSamplingOptions_new_3(int fm, int mm); // (SkFilterMode fm, SkMipmapMode mm) -> SkSamplingOptions *
        init(fm: FilterMode, mm: MipmapMode) {
            self.pointer = SkSamplingOptions_new_3(Int32(fm.rawValue), Int32(mm.rawValue));
            self.handle = -1
        }

        // void *SkSamplingOptions_new_4(int fm); // (SkFilterMode fm) -> SkSamplingOptions *
        init(fm: FilterMode) {
            self.pointer = SkSamplingOptions_new_4(Int32(fm.rawValue));
            self.handle = -1
        }
        // void *SkSamplingOptions_new_5(const void *c); // (const SkCubicResampler *c) -> SkSamplingOptions *
        init(c: CubicResampler) {
            self.pointer = SkSamplingOptions_new_5(c.pointer);
            self.handle = -1
        }

        // void SkSamplingOptions_delete(void *sampling_options); // (SkSamplingOptions *sampling_options)
        deinit {
            SkSamplingOptions_delete(self.pointer)
            if self.handle > -1 {
                static_sk_sampling_options_delete(self.handle)
            }
        }
        // bool SkSamplingOptions_isAniso(void *sampling_options); // (SkSamplingOptions *sampling_options) -> bool
        func isAniso() -> Bool {
            return SkSamplingOptions_isAniso(self.pointer)
        }

        // // static

        init(pointer: Skia.SamplingOptionsMutablePointer?, handle: sk_sampling_options_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkSamplingOptions_Aniso(int maxAniso); // (int maxAniso) -> sk_sampling_options_t
        static func Aniso(maxAniso: Int) -> SamplingOptions {
            let handle = SkSamplingOptions_Aniso(Int32(maxAniso));
            let pointer = static_sk_sampling_options_get_ptr(handle)
            return SamplingOptions(pointer: pointer, handle: handle)
        }
    }
}