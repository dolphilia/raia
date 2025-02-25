//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_BLENDER_H
#define RAIA_SKIA_STATIC_SK_BLENDER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_blender_t;

void static_sk_blender_delete(int key);
void *static_sk_blender_get_ptr(int key); // -> SkBlender *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_BLENDER_H
