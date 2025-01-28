//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_H
#define RAIA_SKIA_STATIC_SK_PATH_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_path_t;
void static_sk_path_delete(int key);
void * static_sk_path_get_ptr(int key); // -> SkPath *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_PATH_H
