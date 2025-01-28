//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_BLEND_MODE_H
#define RAIA_SKIA_STATIC_SK_BLEND_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int optional_sk_blend_mode_t;

void static_optional_sk_blend_mode_delete(int key);
int static_optional_sk_blend_mode_get(int key); // -> (int)SkBlendMode

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_BLEND_MODE_H
