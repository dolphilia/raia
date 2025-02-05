//
// Created by dolphilia on 25/02/04.
//

#ifndef STATIC_SK_MESH_RESULT_H
#define STATIC_SK_MESH_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_mesh_result_t;
void static_sk_mesh_result_delete(int key);
void * static_sk_mesh_result_get_ptr(int key);
#ifdef __cplusplus
}
#endif

#endif //STATIC_SK_MESH_RESULT_H
