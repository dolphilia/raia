//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
#define RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_surface_props_t;
void static_sk_surface_props_delete(int key);
void * static_sk_surface_props_get_ptr(int key); // -> SkSurfaceProps *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
