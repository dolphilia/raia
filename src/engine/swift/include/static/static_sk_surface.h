//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_H
#define RAIA_SKIA_STATIC_SK_SURFACE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_surface_t;
void static_sk_surface_delete(int key);
void * static_sk_surface_get_ptr(int key); // -> SkSurface *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_SURFACE_H
