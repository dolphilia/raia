extension Skia {
    enum SkFontStyleSlant: Int32 {
        case upright
        case italic
        case oblique
    }

    class SkFontStyle {
        public var pointer: SkFontStyleMutablePointer?
        public var handle: sk_font_style_t = -1
        // void SkFontStyle_delete(void *font_style); // (SkFontStyle *font_style)

        deinit {
            if self.handle > -1 {
                static_sk_font_style_delete(self.handle)
            } else {
                SkFontStyle_delete(self.pointer)
            }
        }

        init(pointer: SkFontStyleMutablePointer?, handle: sk_font_style_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkFontStyle_weight(void *font_style); // (SkFontStyle *font_style) -> int

        func weight() -> Int {
            return Int(SkFontStyle_weight(self.pointer))
        }

        // int SkFontStyle_width(void *font_style); // (SkFontStyle *font_style) -> int

        func width() -> Int {
            return Int(SkFontStyle_width(self.pointer))
        }

        // int SkFontStyle_slant(void *font_style); // (SkFontStyle *font_style) -> SkFontStyle::Slant

        func slant() -> SkFontStyleSlant {
            return SkFontStyleSlant(rawValue: SkFontStyle_slant(self.pointer))!
        }
    }
}