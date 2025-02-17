extension Skia {
    class SkFontArguments {
        public var pointer: SkFontArgumentsMutablePointer?
        public var handle: sk_font_arguments_t = -1

        // void *SkFontArguments_new(); // () -> SkFontArguments *

        init() {
            self.pointer = SkFontArguments_new()
            self.handle = -1
        }
        // void SkFontArguments_delete(void *font_arguments); // (SkFontArguments *font_arguments)

        deinit {
            if self.handle > -1 {
                static_sk_font_arguments_delete(self.handle)
            } else {
                SkFontArguments_delete(self.pointer)
            }
        }
        // int SkFontArguments_setCollectionIndex(void *font_arguments, int collectionIndex); // (SkFontArguments *font_arguments, int collectionIndex) -> sk_font_arguments_t

        func setCollectionIndex(collectionIndex: Int) -> SkFontArguments {
            let handle = SkFontArguments_setCollectionIndex(self.pointer, Int32(collectionIndex))
            let pointer = static_sk_font_arguments_get_ptr(handle)
            return SkFontArguments(pointer: pointer, handle: handle)
        }
        // int SkFontArguments_setVariationDesignPosition(void *font_arguments, int position); // (SkFontArguments *font_arguments, sk_font_arguments_variation_position_t position) -> sk_font_arguments_t
        // int SkFontArguments_getCollectionIndex(void *font_arguments); // (SkFontArguments *font_arguments) -> int

        func getCollectionIndex() -> Int {
            return Int(SkFontArguments_getCollectionIndex(self.pointer))
        }
        // int SkFontArguments_getVariationDesignPosition(void *font_arguments); // (SkFontArguments *font_arguments) -> sk_font_arguments_variation_position_t
        // int SkFontArguments_setPalette(void *font_arguments, int palette); // (SkFontArguments *font_arguments, sk_font_arguments_palette_t palette) -> sk_font_arguments_t
        // int SkFontArguments_getPalette(void *font_arguments); // (SkFontArguments *font_arguments) -> sk_font_arguments_palette_t

        // static

        init(pointer: SkFontArgumentsMutablePointer?, handle: sk_font_arguments_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}