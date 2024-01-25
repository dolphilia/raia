//
// Created by dolphilia on 2024/01/13.
//

#include "sk_meshes.h"

extern "C" {

int SkMeshes_MakeIndexBuffer(const void *data, size_t size) {
    return static_sk_mesh_index_buffer_make(SkMeshes::MakeIndexBuffer(data, size));
}

int SkMeshes_CopyIndexBuffer(const sk_sp< SkMesh::IndexBuffer > *indexBuffer) {
    return static_sk_mesh_index_buffer_make(SkMeshes::CopyIndexBuffer(*indexBuffer));
}

int SkMeshes_MakeVertexBuffer(const void *data, size_t size) {
    return static_sk_mesh_vertex_buffer_make(SkMeshes::MakeVertexBuffer(data, size));
}

int SkMeshes_CopyVertexBuffer(const sk_sp< SkMesh::VertexBuffer > *vertexBuffer) {
    return static_sk_mesh_vertex_buffer_make(SkMeshes::CopyVertexBuffer(*vertexBuffer));
}

}