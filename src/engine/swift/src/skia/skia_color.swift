extension Skia {
    static func SkColorSetA(c: UInt32, a: UInt32) -> UInt32 {
        return SkColor_SkColorSetA(c, a)
    }
    
    static func SkColorSetARGB(a: UInt32, r: UInt32, g: UInt32, b: UInt32) -> UInt32 {
        return SkColor_SkColorSetARGB(a, r, g, b)
    }

    static func SkColorToHSV(color: UInt32, hsv: inout [Float]) {
        SkColor_SkColorToHSV(color, &hsv)
    }

    static func SkHSVToColor(hsv: [Float]) -> UInt32 {
        return SkColor_SkHSVToColor(hsv)
    }

    static func SkHSVToColor(alpha: UInt32, hsv: [Float]) -> UInt32 {
        return SkColor_SkHSVToColor_2(alpha, hsv)
    }

    static func SkPreMultiplyARGB(a: UInt32, r: UInt32, g: UInt32, b: UInt32) -> UInt32 {
        return SkColor_SkPreMultiplyARGB(a, r, g, b)
    }

    static func SkPreMultiplyColor(c: UInt32) -> UInt32 {
        return SkColor_SkPreMultiplyColor(c)
    }

    static func SkRGBToHSV(red: UInt32, green: UInt32, blue: UInt32, hsv: inout [Float]) {
        SkColor_SkRGBToHSV(red, green, blue, &hsv)
    }
}