//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
#define RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkMesh.h"

typedef int sk_mesh_index_buffer_t;

int static_sk_mesh_index_buffer_make(sk_sp<SkMesh::IndexBuffer> value);
extern "C" void static_sk_mesh_index_buffer_delete(int key);
extern "C" SkMesh::IndexBuffer *static_sk_mesh_index_buffer_get(int key);
void static_sk_mesh_index_buffer_set(int key, sk_sp<SkMesh::IndexBuffer> value);
sk_sp<SkMesh::IndexBuffer> static_sk_mesh_index_buffer_move(int key);

#endif //RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
