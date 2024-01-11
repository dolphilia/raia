//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H
#define RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H

#include <string>
#include <map>
#include "include/core/SkMesh.h"

void static_sk_mesh_vertex_buffer_delete(const char *key);
SkMesh::VertexBuffer *static_sk_mesh_vertex_buffer_get(const char *key);
void static_sk_mesh_vertex_buffer_set(const char *key, sk_sp<SkMesh::VertexBuffer> value);
sk_sp<SkMesh::VertexBuffer> static_sk_mesh_vertex_buffer_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H
