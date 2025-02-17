extension Skia {
    // ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

    enum SkAlphaType: Int32 {
        case unknown
        case opaque
        case premul
        case unpremul
    }

    enum SkApplyPerspectiveClip: Int32 {
        case no
        case yes
    }

    enum SkBlendMode: Int32 {
        case clear
        case src
        case dst
        case srcOver
        case dstOver
        case srcIn
        case dstIn
        case srcOut
        case dstOut
        case srcATop
        case dstATop
        case xor
        case plus
        case modulate
        case screen
        case overlay
        case darken
        case lighten
        case colorDodge
        case colorBurn
        case hardLight
        case softLight
        case difference
        case exclusion
        case multiply
        case hue
        case saturation
        case color
        case luminosity
    }

    enum SkClipOp: Int32 {
        case difference
        case intersect
    }

    enum SkColorType: Int32 {
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

    enum SkFilterMode: Int32 {
        case nearest
        case linear
    }

    enum SkFontHinting: Int32 {
        case none
        case slight
        case normal
        case full
    }

    enum SkMipmapMode: Int32 {
        case none
        case nearest
        case linear
    }
    
    enum SkPathFillType: Int32 {
        case winding
        case evenOdd
        case inverseWinding
        case inverseEvenOdd
    }

    enum SkPathDirection: Int32 {
        case cw
        case ccw
    }

    enum SkPathSegmentMask: Int32 {
        case line
        case quad
        case conic
        case cubic
    }

    enum SkPathVerb: Int32 {
        case move
        case line
        case quad
        case conic
        case cubic
        case close
    }

    enum SkPixelGeometry: Int32 {
        case unknown
        case rgbH
        case bgrH
        case rgbV
        case bgrV
    }

    enum SkTextEncoding: Int32 {
        case utf8
        case utf16
        case utf32
        case glyphID
    }

    enum SkTileMode: Int32 {
        case clamp
        case kRepeat
        case mirror
        case decal
    }

    enum SkYUVColorSpace: Int32 {
        case identity
        case ituRec601
        case ituRec709
        case ituRec2020
    }
}