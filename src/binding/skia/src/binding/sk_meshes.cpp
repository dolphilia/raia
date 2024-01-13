//
// Created by dolphilia on 2024/01/13.
//

#include "sk_meshes.h"

extern "C" {

void SkMeshes_MakeIndexBuffer(const char *sk_mesh_index_buffer_key_out, const void *data, size_t size) {
    static_sk_mesh_index_buffer_set(sk_mesh_index_buffer_key_out, SkMeshes::MakeIndexBuffer(data, size));
}

void SkMeshes_CopyIndexBuffer(const char *sk_mesh_index_buffer_key_out, const sk_sp< SkMesh::IndexBuffer > *indexBuffer) {
    static_sk_mesh_index_buffer_set(sk_mesh_index_buffer_key_out, SkMeshes::CopyIndexBuffer(*indexBuffer));
}

void SkMeshes_MakeVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, const void *data, size_t size) {
    static_sk_mesh_vertex_buffer_set(sk_mesh_vertex_buffer_key_out, SkMeshes::MakeVertexBuffer(data, size));
}

void SkMeshes_CopyVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, const sk_sp< SkMesh::VertexBuffer > *vertexBuffer) {
    static_sk_mesh_vertex_buffer_set(sk_mesh_vertex_buffer_key_out, SkMeshes::CopyVertexBuffer(*vertexBuffer));
}

}