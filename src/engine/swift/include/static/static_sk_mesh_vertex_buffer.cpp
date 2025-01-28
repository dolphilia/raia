//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mesh_vertex_buffer.h"

#include <utility>
#include "static_sk_mesh_vertex_buffer-internal.h"

static std::set<int> static_sk_mesh_vertex_buffer_available_keys;
static std::map<int , sk_sp<SkMesh::VertexBuffer>> static_sk_mesh_vertex_buffer;
static int static_sk_mesh_vertex_buffer_index = 0;

int static_sk_mesh_vertex_buffer_make(sk_sp<SkMesh::VertexBuffer> value) {
    int key;
    if (!static_sk_mesh_vertex_buffer_available_keys.empty()) {
        auto it = static_sk_mesh_vertex_buffer_available_keys.begin();
        key = *it;
        static_sk_mesh_vertex_buffer_available_keys.erase(it);
    } else {
        key = static_sk_mesh_vertex_buffer_index++;
    }
    static_sk_mesh_vertex_buffer[key] = std::move(value);
    return key;
}

void static_sk_mesh_vertex_buffer_delete(int key) {
    static_sk_mesh_vertex_buffer[key].reset();
    static_sk_mesh_vertex_buffer.erase(key);
    static_sk_mesh_vertex_buffer_available_keys.insert(key);
}

void *static_sk_mesh_vertex_buffer_get(int key) { // -> SkMesh::VertexBuffer *
    return static_sk_mesh_vertex_buffer[key].get();
}

void static_sk_mesh_vertex_buffer_set(int key, sk_sp<SkMesh::VertexBuffer> value) {
    static_sk_mesh_vertex_buffer[key] = std::move(value);
}

sk_sp<SkMesh::VertexBuffer> static_sk_mesh_vertex_buffer_move(int key) {
    return std::move(static_sk_mesh_vertex_buffer[key]);
}
