extension Skia {
    enum Color {
        static func colorSetA(c: UInt32, a: UInt32) -> UInt32 {
            return SkColor_SkColorSetA(c, a)
        }
        static func colorSetARGB(a: UInt32, r: UInt32, g: UInt32, b: UInt32) -> UInt32 {
            return SkColor_SkColorSetARGB(a, r, g, b)
        }
        static func colorToHSV(color: UInt32, hsv: inout [Float]) {
            SkColor_SkColorToHSV(color, &hsv)
        }
        static func hsvToColor(hsv: [Float]) -> UInt32 {
            return SkColor_SkHSVToColor(hsv)
        }
        static func hsvToColor(alpha: UInt32, hsv: [Float]) -> UInt32 {
            return SkColor_SkHSVToColor_2(alpha, hsv)
        }
        static func preMultiplyARGB(a: UInt32, r: UInt32, g: UInt32, b: UInt32) -> UInt32 {
            return SkColor_SkPreMultiplyARGB(a, r, g, b)
        }
        static func preMultiplyColor(c: UInt32) -> UInt32 {
            return SkColor_SkPreMultiplyColor(c)
        }
        static func rgbToHSV(red: UInt32, green: UInt32, blue: UInt32, hsv: inout [Float]) {
            SkColor_SkRGBToHSV(red, green, blue, &hsv)
        }
        private func test() {
            var hsv: [Float] = [0, 0, 0]
            let color = Skia.Color.colorSetARGB(a: 255, r: 255, g: 255, b: 255)
            Skia.Color.colorToHSV(color: color, hsv: &hsv)
            let newColor = Skia.Color.hsvToColor(hsv: hsv)
            let newColor2 = Skia.Color.hsvToColor(alpha: 255, hsv: hsv)
            let preColor = Skia.Color.preMultiplyARGB(a: 255, r: 255, g: 255, b: 255)
            let preColor2 = Skia.Color.preMultiplyColor(c: color)
            Skia.Color.rgbToHSV(red: 255, green: 255, blue: 255, hsv: &hsv)
            print("Skia.Color.test: \(color), \(newColor), \(newColor2), \(preColor), \(preColor2), \(hsv)")
        }
    }
}