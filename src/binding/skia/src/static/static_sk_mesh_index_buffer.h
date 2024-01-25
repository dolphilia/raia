//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
#define RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H

#include <string>
#include <map>
#include "include/core/SkMesh.h"

void static_sk_mesh_index_buffer_delete(int key);
SkMesh::IndexBuffer *static_sk_mesh_index_buffer_get(int key);
void static_sk_mesh_index_buffer_set(int key, sk_sp<SkMesh::IndexBuffer> value);
sk_sp<SkMesh::IndexBuffer> static_sk_mesh_index_buffer_move(int key);

#endif //RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
