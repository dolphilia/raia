//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mesh_vertex_buffer.h"

static std::map<std::string, sk_sp<SkMesh::VertexBuffer>> static_sk_mesh_vertex_buffer;

void static_sk_mesh_vertex_buffer_delete(const char *key) {
    static_sk_mesh_vertex_buffer[key].reset();
    static_sk_mesh_vertex_buffer.erase(key);
}

SkMesh::VertexBuffer *static_sk_mesh_vertex_buffer_get(const char *key) {
    return static_sk_mesh_vertex_buffer[key].get();
}

void static_sk_mesh_vertex_buffer_set(const char *key, sk_sp<SkMesh::VertexBuffer> value) {
    static_sk_mesh_vertex_buffer[key] = std::move(value);
}

sk_sp<SkMesh::VertexBuffer> static_sk_mesh_vertex_buffer_move(const char *key) {
    return std::move(static_sk_mesh_vertex_buffer[key]);
}