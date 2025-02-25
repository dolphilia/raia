//
// Created by dolphilia on 25/02/05.
//

#ifndef STATIC_SK_MESH_SPECIFICATION_RESULT_INTERNAL_H
#define STATIC_SK_MESH_SPECIFICATION_RESULT_INTERNAL_H
#include <map>
#include <set>
#include <utility>
#include "include/core/SkMesh.h"
int static_sk_mesh_specification_result_make(SkMeshSpecification::Result value);
SkMeshSpecification::Result static_sk_mesh_specification_result_get_entity(int key);
void static_sk_mesh_specification_result_set(int key, SkMeshSpecification::Result value);
#endif //STATIC_SK_MESH_SPECIFICATION_RESULT_INTERNAL_H
