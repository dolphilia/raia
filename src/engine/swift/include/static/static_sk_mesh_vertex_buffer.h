//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H
#define RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_mesh_vertex_buffer_t;
void static_sk_mesh_vertex_buffer_delete(int key);
void *static_sk_mesh_vertex_buffer_get_ptr(int key); // -> SkMesh::VertexBuffer *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_MESH_VERTEX_BUFFER_H
