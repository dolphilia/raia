//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_font_arguments_palette_t;
void static_sk_font_arguments_palette_delete(int key);
void * static_sk_font_arguments_palette_get_ptr(int key); // -> SkFontArguments::Palette *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
