extension Skia {
    // ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

    enum AlphaType: Int32 {
        case unknown
        case opaque
        case premul
        case unpremul
    }

    enum ApplyPerspectiveClip: Int32 {
        case no
        case yes
    }

    enum ClipOp: Int32 {
        case difference
        case intersect
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

    enum FilterMode: Int32 {
        case nearest
        case linear
    }

    enum MipmapMode: Int32 {
        case none
        case nearest
        case linear
    }
    
    enum PathFillType: Int32 {
        case winding
        case evenOdd
        case inverseWinding
        case inverseEvenOdd
    }

    enum PathDirection: Int32 {
        case cw
        case ccw
    }

    enum PathSegmentMask: Int32 {
        case line
        case quad
        case conic
        case cubic
    }

    enum PathVerb: Int32 {
        case move
        case line
        case quad
        case conic
        case cubic
        case close
    }

    enum PixelGeometry: Int32 {
        case unknown
        case rgbH
        case bgrH
        case rgbV
        case bgrV
    }

    enum TileMode: Int32 {
        case clamp
        case kRepeat
        case mirror
        case decal
    }

    enum YUVColorSpace: Int32 {
        case identity
        case ituRec601
        case ituRec709
        case ituRec2020
    }
}