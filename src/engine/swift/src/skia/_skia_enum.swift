extension Skia {
    enum AlphaType: Int32 {
        case unknown
        case opaque
        case premul
        case unpremul
    }

    enum ColorType: Int32 {
        case unknown
        case alpha8
        case rgb565
        case argb4444
        case rgba8888
        case rgb888x
        case bgra8888
        case rgba1010102
        case bgra1010102
        case rgb101010x
        case bgr101010x
        case bgr101010xXR
        case rgba10x6
        case gray8
        case rgbaF16Norm
        case rgbaF16
        case rgbaF32
        case r8G8Unorm
        case a16Float
        case r16G16Float
        case a16Unorm
        case r16G16Unorm
        case r16G16B16A16Unorm
        case srgba8888
        case r8Unorm
        case lastEnum
        case n32
    }
}