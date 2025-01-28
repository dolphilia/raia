//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_font_arguments_variation_position_t;
void static_sk_font_arguments_variation_position_delete(int key);
void * static_sk_font_arguments_variation_position_get_ptr(int key); // -> SkFontArguments::VariationPosition *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H
