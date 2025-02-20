extension Skia {
    class SkColor {
        public var color: UInt32 = 0

        deinit {}

        init(color: UInt32) {
            self.color = color
        }

        func setA(a: UInt32) {
            self.color = SkColor_SkColorSetA(self.color, a)
        }

        func setARGB(a: UInt32, r: UInt32, g: UInt32, b: UInt32) {
            self.color = SkColor_SkColorSetARGB(a, r, g, b)
        }

        func toHSV() -> [Float] {
            var dst = [Float](repeating: 0.0, count: 3)
            SkColor_SkColorToHSV(self.color, &dst)
            return dst
        }

        func setHSV(hsv: [Float]) {
            self.color = SkColor_SkHSVToColor(hsv)
        }

        func setHSV(alpha: UInt32, hsv: [Float]) {
            self.color = SkColor_SkHSVToColor_2(alpha, hsv)
        }

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
}