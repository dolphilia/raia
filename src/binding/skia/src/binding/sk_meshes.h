//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_MESHES_H
#define RAIA_SKIA_SK_MESHES_H

#include "include/core/SkMesh.h"
#include "../static/static_sk_mesh_index_buffer.h"
#include "../static/static_sk_mesh_vertex_buffer.h"

extern "C" {
void SkMeshes_MakeIndexBuffer(const char *sk_mesh_index_buffer_key_out, const void *data, size_t size);
void SkMeshes_CopyIndexBuffer(const char *sk_mesh_index_buffer_key_out, const sk_sp< SkMesh::IndexBuffer > *indexBuffer);
void SkMeshes_MakeVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, const void *data, size_t size);
void SkMeshes_CopyVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, const sk_sp< SkMesh::VertexBuffer > *vertexBuffer);
}

#endif //RAIA_SKIA_SK_MESHES_H
