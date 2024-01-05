//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
#define RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H

#include <string>
#include <map>
#include "include/core/SkMesh.h"

void static_sk_mesh_index_buffer_delete(const char *key);
SkMesh::IndexBuffer *static_sk_mesh_index_buffer_get(const char *key);
void static_sk_mesh_index_buffer_set(const char *key, sk_sp<SkMesh::IndexBuffer> value);
sk_sp<SkMesh::IndexBuffer> static_sk_mesh_index_buffer_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_MESH_INDEX_BUFFER_H
