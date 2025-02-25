//
// Created by dolphilia on 25/02/04.
//

#ifndef STATIC_SK_MESH_SPECIFICATION_INTERNAL_H
#define STATIC_SK_MESH_SPECIFICATION_INTERNAL_H
#include <map>
#include <set>
#include <utility>
#include "include/core/SkMesh.h"
int static_sk_mesh_specification_make(sk_sp<SkMeshSpecification> value);
void static_sk_mesh_specification_set(int key, sk_sp<SkMeshSpecification> value);
sk_sp<SkMeshSpecification> static_sk_mesh_specification_get_entity(int key);
#endif //STATIC_SK_MESH_SPECIFICATION_INTERNAL_H
