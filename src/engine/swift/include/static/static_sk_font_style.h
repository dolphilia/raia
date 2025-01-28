//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_font_style_t;
void static_sk_font_style_delete(int key);
void * static_sk_font_style_get_ptr(int key); // -> SkFontStyle *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_H
