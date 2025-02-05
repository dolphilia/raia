//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_CHILD_PTR_H
#define RAIA_SKIA_STATIC_SK_MESH_CHILD_PTR_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_mesh_child_ptr_t;
typedef int const_sk_mesh_child_ptr_t;
void static_sk_mesh_child_ptr_delete(int key);
void * static_sk_mesh_child_ptr_get_ptr(int key, int index);
void static_const_sk_mesh_child_ptr_delete(int key);
void * static_const_sk_mesh_child_ptr_get_ptr(int key, int index);
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_MESH_CHILD_PTR_H
