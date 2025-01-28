//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_font_style_set_t;
void static_sk_font_style_set_delete(int key);
void *static_sk_font_style_set_get(int key); // -> SkFontStyleSet *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
