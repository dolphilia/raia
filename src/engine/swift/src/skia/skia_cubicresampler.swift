extension Skia {
    class CubicResampler {
        public var pointer: Skia.CubicResamplerMutablePointer?
        public var handle: sk_cubic_resampler_t?

        // void SkCubicResampler_delete(void *cubicResampler); // (SkCubicResampler *cubicResampler)
        deinit {
            SkCubicResampler_delete(self.pointer)
            if let handle = self.handle {
                static_sk_cubic_resampler_delete(handle)
            }
        }

        // static

        init(pointer: Skia.CubicResamplerMutablePointer?, handle: sk_cubic_resampler_t?) {
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