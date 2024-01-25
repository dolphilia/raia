//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mesh_index_buffer.h"

static std::map<int , sk_sp<SkMesh::IndexBuffer>> static_sk_mesh_index_buffer;

void static_sk_mesh_index_buffer_delete(int key) {
    static_sk_mesh_index_buffer[key].reset();
    static_sk_mesh_index_buffer.erase(key);
}

SkMesh::IndexBuffer *static_sk_mesh_index_buffer_get(int key) {
    return static_sk_mesh_index_buffer[key].get();
}

void static_sk_mesh_index_buffer_set(int key, sk_sp<SkMesh::IndexBuffer> value) {
    static_sk_mesh_index_buffer[key] = std::move(value);
}

sk_sp<SkMesh::IndexBuffer> static_sk_mesh_index_buffer_move(int key) {
    return std::move(static_sk_mesh_index_buffer[key]);
}