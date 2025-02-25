//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
#define RAIA_SKIA_STATIC_SK_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_path_effect_t;
void static_sk_path_effect_delete(int key);
void *static_sk_path_effect_get_ptr(int key); // -> SkPathEffect *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
