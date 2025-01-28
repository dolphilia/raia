//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_MESHES_H
#define RAIA_SKIA_SK_MESHES_H

#ifdef __cplusplus
extern "C" {
#endif

// static

int SkMeshes_MakeIndexBuffer(const void *data, unsigned long size); // // (const void *data, size_t size) -> sk_mesh_index_buffer_t
int SkMeshes_CopyIndexBuffer(const void *indexBuffer); // // (const sk_sp< SkMesh::IndexBuffer > *indexBuffer) -> sk_mesh_index_buffer_t
int SkMeshes_MakeVertexBuffer(const void *data, unsigned long size); // // (const void *data, size_t size) -> sk_mesh_index_buffer_t
int SkMeshes_CopyVertexBuffer(const void *vertexBuffer); // // (const sk_sp< SkMesh::VertexBuffer > *vertexBuffer) -> sk_mesh_index_buffer_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_MESHES_H
