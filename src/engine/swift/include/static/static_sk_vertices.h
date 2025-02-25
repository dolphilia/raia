//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_VERTICES_H
#define RAIA_SKIA_STATIC_SK_VERTICES_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_vertices_t;
void static_sk_vertices_delete(int key);
void * static_sk_vertices_get_ptr(int key); // -> SkVertices *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_VERTICES_H
