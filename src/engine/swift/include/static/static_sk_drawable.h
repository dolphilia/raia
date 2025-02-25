//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_drawable_t;
void static_sk_drawable_delete(int key);
void *static_sk_drawable_get_ptr(int key); // -> SkDrawable *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_H
