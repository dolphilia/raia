//
// Created by dolphilia on 25/02/05.
//

#ifndef STATIC_SK_MESH_SPECIFICATION_RESULT_H
#define STATIC_SK_MESH_SPECIFICATION_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_mesh_specification_result_t;

void static_sk_mesh_specification_result_delete(int key);
void * static_sk_mesh_specification_result_get_ptr(int key);

#ifdef __cplusplus
}
#endif

#endif //STATIC_SK_MESH_SPECIFICATION_RESULT_H
