#ifndef STATIC_SK_MESH_VERTEX_BUFFER_INTERNAL_H
#define STATIC_SK_MESH_VERTEX_BUFFER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkMesh.h"
int static_sk_mesh_vertex_buffer_make(sk_sp<SkMesh::VertexBuffer> value);
void static_sk_mesh_vertex_buffer_set(int key, sk_sp<SkMesh::VertexBuffer> value);
sk_sp<SkMesh::VertexBuffer> static_sk_mesh_vertex_buffer_get_entity(int key);
#endif // STATIC_SK_MESH_VERTEX_BUFFER_INTERNAL_H
