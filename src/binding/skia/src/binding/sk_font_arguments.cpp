//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_arguments.h"

extern "C" {

SkFontArguments *SkFontArguments_new() {
    return new SkFontArguments();
}

void SkFontArguments_setCollectionIndex(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, int collectionIndex) {
    static_sk_font_arguments_set(sk_font_arguments_key_out, font_argments->setCollectionIndex(collectionIndex));
}

void SkFontArguments_setVariationDesignPosition(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, SkFontArguments::VariationPosition position) {
    static_sk_font_arguments_set(sk_font_arguments_key_out, font_argments->setVariationDesignPosition(position));
}

int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments) {
    return font_argments->getCollectionIndex();
}

SkFontArguments::VariationPosition SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments) {
    return font_argments->getVariationDesignPosition();
}

void SkFontArguments_setPalette(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, SkFontArguments::Palette palette) {
    static_sk_font_arguments_set(sk_font_arguments_key_out, font_argments->setPalette(palette));
}

SkFontArguments::Palette SkFontArguments_getPalette(SkFontArguments *font_argments) {
    return font_argments->getPalette();
}

}