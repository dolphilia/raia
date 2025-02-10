extension Skia {
    class CubicResampler {
        public var pointer: Skia.CubicResamplerMutablePointer?
        public var handle: sk_cubic_resampler_t = -1

        // void SkCubicResampler_delete(void *cubicResampler); // (SkCubicResampler *cubicResampler)
        deinit {
            if self.handle > -1 {
                static_sk_cubic_resampler_delete(self.handle)
            } else {
                SkCubicResampler_delete(self.pointer)
            }
        }

        // static

        init(pointer: Skia.CubicResamplerMutablePointer?, handle: sk_cubic_resampler_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkCubicResampler_Mitchell(); // () -> sk_cubic_resampler_t
        func Mitchell() -> CubicResampler {
            let handle = SkCubicResampler_Mitchell();
            let pointer = static_sk_cubic_resampler_get_ptr(handle)
            return CubicResampler(pointer: pointer, handle: handle)
        }

        // int SkCubicResampler_CatmullRom(); // () -> sk_cubic_resampler_t
        func CatmullRom() -> CubicResampler {
            let handle = SkCubicResampler_CatmullRom();
            let pointer = static_sk_cubic_resampler_get_ptr(handle)
            return CubicResampler(pointer: pointer, handle: handle)
        }
    }
}