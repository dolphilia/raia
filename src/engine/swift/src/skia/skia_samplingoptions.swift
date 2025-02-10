extension Skia {
    protocol SkSamplingOptionsProtocol {
        var pointer: Skia.SkSamplingOptionsMutablePointer? { get set }
        var handle: sk_sampling_options_t { get set }
        // deinit // void SkSamplingOptions_delete(void *sampling_options); // (SkSamplingOptions *sampling_options)
        init(pointer: Skia.SkSamplingOptionsMutablePointer?, handle: sk_sampling_options_t)
        init() // void *SkSamplingOptions_new(); // () -> SkSamplingOptions *
        init(options: SkSamplingOptions) // void *SkSamplingOptions_new_2(const void *options); // (const SkSamplingOptions *options) -> SkSamplingOptions *
        init(fm: FilterMode, mm: MipmapMode) // void *SkSamplingOptions_new_3(int fm, int mm); // (SkFilterMode fm, SkMipmapMode mm) -> SkSamplingOptions *
        init(fm: FilterMode) // void *SkSamplingOptions_new_4(int fm); // (SkFilterMode fm) -> SkSamplingOptions *
        init(c: CubicResampler) // void *SkSamplingOptions_new_5(const void *c); // (const SkCubicResampler *c) -> SkSamplingOptions *
        // Static Methods
        static func Aniso(maxAniso: Int) -> SkSamplingOptions // int SkSamplingOptions_Aniso(int maxAniso); // (int maxAniso) -> sk_sampling_options_t
        // Methods
        func isAniso() -> Bool // bool SkSamplingOptions_isAniso(void *sampling_options); // (SkSamplingOptions *sampling_options) -> bool
    }

    class SkSamplingOptions : SkSamplingOptionsProtocol {
        public var pointer: Skia.SkSamplingOptionsMutablePointer?
        public var handle: sk_sampling_options_t = -1

        deinit {
            SkSamplingOptions_delete(self.pointer)
            if self.handle > -1 {
                static_sk_sampling_options_delete(self.handle)
            }
        }

        required init(pointer: Skia.SkSamplingOptionsMutablePointer?, handle: sk_sampling_options_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkSamplingOptions_new();
            self.handle = -1
        }

        required init(options: SkSamplingOptions) {
            self.pointer = SkSamplingOptions_new_2(options.pointer);
            self.handle = -1
        }

        required init(fm: FilterMode, mm: MipmapMode) {
            self.pointer = SkSamplingOptions_new_3(Int32(fm.rawValue), Int32(mm.rawValue));
            self.handle = -1
        }

        required init(fm: FilterMode) {
            self.pointer = SkSamplingOptions_new_4(Int32(fm.rawValue));
            self.handle = -1
        }

        required init(c: CubicResampler) {
            self.pointer = SkSamplingOptions_new_5(c.pointer);
            self.handle = -1
        }

        // Static Methods

        static func Aniso(maxAniso: Int) -> SkSamplingOptions {
            let handle = SkSamplingOptions_Aniso(Int32(maxAniso));
            let pointer = static_sk_sampling_options_get_ptr(handle)
            return SkSamplingOptions(pointer: pointer, handle: handle)
        }

        // Methods

        func isAniso() -> Bool {
            return SkSamplingOptions_isAniso(self.pointer)
        }
    }
}