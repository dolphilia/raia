//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_arguments.h"

extern "C" {

SkFontArguments *SkFontArguments_new() {
    return new SkFontArguments();
}

void SkFontArguments_delete(SkFontArguments *font_arguments) {
    delete font_arguments;
}

sk_font_arguments_t SkFontArguments_setCollectionIndex(SkFontArguments *font_argments, int collectionIndex) {
    return static_sk_font_arguments_make(font_argments->setCollectionIndex(collectionIndex));
}

sk_font_arguments_t SkFontArguments_setVariationDesignPosition(SkFontArguments *font_argments, sk_font_arguments_variation_position_t position) {
    return static_sk_font_arguments_make(font_argments->setVariationDesignPosition(static_sk_font_arguments_variation_position_get(position)));
}

int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments) {
    return font_argments->getCollectionIndex();
}

sk_font_arguments_variation_position_t SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments) {
    return static_sk_font_arguments_variation_position_make(font_argments->getVariationDesignPosition());
}

sk_font_arguments_t SkFontArguments_setPalette(SkFontArguments *font_argments, sk_font_arguments_palette_t palette) {
    return static_sk_font_arguments_make(font_argments->setPalette(static_sk_font_arguments_palette_get(palette)));
}

sk_font_arguments_palette_t SkFontArguments_getPalette(SkFontArguments *font_argments) {
    return static_sk_font_arguments_palette_make(font_argments->getPalette());
}

}