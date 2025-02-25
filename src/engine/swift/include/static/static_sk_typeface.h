//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TYPEFACE_H
#define RAIA_SKIA_STATIC_SK_TYPEFACE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_typeface_t;
void static_sk_typeface_delete(int key);
void * static_sk_typeface_get_ptr(int key); // -> SkTypeface *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_TYPEFACE_H
