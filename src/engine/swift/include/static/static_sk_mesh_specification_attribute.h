//
// Created by dolphilia on 25/02/05.
//

#ifndef STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_H
#define STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_mesh_specification_attribute_t;

void static_sk_mesh_specification_attribute_delete(int key);
const void * static_sk_mesh_specification_attribute_get_ptr(int key, int index);

#ifdef __cplusplus
}
#endif

#endif //STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_H
