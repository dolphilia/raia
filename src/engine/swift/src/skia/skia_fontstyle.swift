extension Skia {
    enum SkFontStyleSlant: Int32 {
        case upright
        case italic
        case oblique
    }

    protocol SkFontStyleProtocol {
        var pointer: SkFontStyleMutablePointer? { get set }
        var handle: sk_font_style_t { get set }
        // deinit // void SkFontStyle_delete(void *font_style); // (SkFontStyle *font_style)
        init(pointer: SkFontStyleMutablePointer?, handle: sk_font_style_t)
        func weight() -> Int // int SkFontStyle_weight(void *font_style); // (SkFontStyle *font_style) -> int
        func width() -> Int // int SkFontStyle_width(void *font_style); // (SkFontStyle *font_style) -> int
        func slant() -> SkFontStyleSlant // int SkFontStyle_slant(void *font_style); // (SkFontStyle *font_style) -> SkFontStyle::Slant
    }

    class SkFontStyle : SkFontStyleProtocol {
        public var pointer: SkFontStyleMutablePointer?
        public var handle: sk_font_style_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_font_style_delete(self.handle)
            } else {
                SkFontStyle_delete(self.pointer)
            }
        }

        required init(pointer: SkFontStyleMutablePointer?, handle: sk_font_style_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Methods

        func weight() -> Int {
            return Int(SkFontStyle_weight(self.pointer))
        }

        func width() -> Int {
            return Int(SkFontStyle_width(self.pointer))
        }

        func slant() -> SkFontStyleSlant {
            return SkFontStyleSlant(rawValue: SkFontStyle_slant(self.pointer))!
        }
    }
}