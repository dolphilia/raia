//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PICTURE_H
#define RAIA_SKIA_STATIC_SK_PICTURE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_picture_t;
void static_sk_picture_delete(int key);
void *static_sk_picture_get(int key); // -> SkPicture *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_PICTURE_H
