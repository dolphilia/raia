//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_arguments.h"

extern "C" {

SkFontArguments *SkFontArguments_new() {
    return new SkFontArguments();
}

int SkFontArguments_setCollectionIndex(SkFontArguments *font_argments, int collectionIndex) {
    return static_sk_font_arguments_make(font_argments->setCollectionIndex(collectionIndex));
}

int SkFontArguments_setVariationDesignPosition(SkFontArguments *font_argments, SkFontArguments::VariationPosition position) {
    return static_sk_font_arguments_make(font_argments->setVariationDesignPosition(position));
}

int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments) {
    return font_argments->getCollectionIndex();
}

SkFontArguments::VariationPosition SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments) {
    return font_argments->getVariationDesignPosition();
}

int SkFontArguments_setPalette(SkFontArguments *font_argments, SkFontArguments::Palette palette) {
    return static_sk_font_arguments_make(font_argments->setPalette(palette));
}

SkFontArguments::Palette SkFontArguments_getPalette(SkFontArguments *font_argments) {
    return font_argments->getPalette();
}

}