extension Skia {
    class SkFontArguments {
        public var pointer: SkFontArgumentsMutablePointer?
        public var handle: sk_font_arguments_t = -1
        // void *SkFontArguments_new(); // () -> SkFontArguments *
        // void SkFontArguments_delete(void *font_arguments); // (SkFontArguments *font_arguments)
        // int SkFontArguments_setCollectionIndex(void *font_arguments, int collectionIndex); // (SkFontArguments *font_arguments, int collectionIndex) -> sk_font_arguments_t
        // int SkFontArguments_setVariationDesignPosition(void *font_arguments, int position); // (SkFontArguments *font_arguments, sk_font_arguments_variation_position_t position) -> sk_font_arguments_t
        // int SkFontArguments_getCollectionIndex(void *font_arguments); // (SkFontArguments *font_arguments) -> int
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