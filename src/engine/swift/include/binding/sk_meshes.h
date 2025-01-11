//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_MESHES_H
#define RAIA_SKIA_SK_MESHES_H

#include "include/core/SkMesh.h"
#include "../static/static_sk_mesh_index_buffer.h"
#include "../static/static_sk_mesh_vertex_buffer.h"
#include "export_api.h"

extern "C" {
RAIA_API sk_mesh_index_buffer_t SkMeshes_MakeIndexBuffer(const void *data, size_t size);
RAIA_API sk_mesh_index_buffer_t SkMeshes_CopyIndexBuffer(const sk_sp< SkMesh::IndexBuffer > *indexBuffer);
RAIA_API sk_mesh_index_buffer_t SkMeshes_MakeVertexBuffer(const void *data, size_t size);
RAIA_API sk_mesh_index_buffer_t SkMeshes_CopyVertexBuffer(const sk_sp< SkMesh::VertexBuffer > *vertexBuffer);
}

#endif //RAIA_SKIA_SK_MESHES_H
