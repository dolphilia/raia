//
// Created by dolphilia on 25/02/04.
//

#ifndef STATIC_SK_MESH_RESULT_INTERNAL_H
#define STATIC_SK_MESH_RESULT_INTERNAL_H
#include <map>
#include <set>
#include <utility>
#include "include/core/SkMesh.h"
int static_sk_mesh_result_make(SkMesh::Result value);
SkMesh::Result static_sk_mesh_result_get(int key);
void static_sk_mesh_result_set(int key, SkMesh::Result value);
#endif //STATIC_SK_MESH_RESULT_INTERNAL_H
