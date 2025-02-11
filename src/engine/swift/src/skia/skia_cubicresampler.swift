extension Skia {
    protocol SkCubicResamplerProtocol {
        var pointer: SkCubicResamplerMutablePointer? { get set }
        var handle: sk_cubic_resampler_t { get set }
        // deinit // void SkCubicResampler_delete(void *cubicResampler); // (SkCubicResampler *cubicResampler)
        init(pointer: SkCubicResamplerMutablePointer?, handle: sk_cubic_resampler_t)
        // Methods
        func Mitchell() -> SkCubicResampler // int SkCubicResampler_Mitchell(); // () -> sk_cubic_resampler_t
        func CatmullRom() -> SkCubicResampler // int SkCubicResampler_CatmullRom(); // () -> sk_cubic_resampler_t
    }

    class SkCubicResampler : SkCubicResamplerProtocol {
        public var pointer: SkCubicResamplerMutablePointer?
        public var handle: sk_cubic_resampler_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_cubic_resampler_delete(self.handle)
            } else {
                SkCubicResampler_delete(self.pointer)
            }
        }

        required init(pointer: SkCubicResamplerMutablePointer?, handle: sk_cubic_resampler_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Methods

        func Mitchell() -> SkCubicResampler {
            let handle = SkCubicResampler_Mitchell();
            let pointer = static_sk_cubic_resampler_get_ptr(handle)
            return SkCubicResampler(pointer: pointer, handle: handle)
        }

        func CatmullRom() -> SkCubicResampler {
            let handle = SkCubicResampler_CatmullRom();
            let pointer = static_sk_cubic_resampler_get_ptr(handle)
            return SkCubicResampler(pointer: pointer, handle: handle)
        }
    }
}