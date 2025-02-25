#ifndef STATIC_SK_MESH_INDEX_BUFFER_INTERNAL_H
#define STATIC_SK_MESH_INDEX_BUFFER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkMesh.h"
int static_sk_mesh_index_buffer_make(sk_sp<SkMesh::IndexBuffer> value);
void static_sk_mesh_index_buffer_set(int key, sk_sp<SkMesh::IndexBuffer> value);
sk_sp<SkMesh::IndexBuffer> static_sk_mesh_index_buffer_get_entity(int key);
#endif // STATIC_SK_MESH_INDEX_BUFFER_INTERNAL_H
