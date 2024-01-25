//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_vertices.h"

static std::map<int , sk_sp<SkVertices>> static_sk_vertices;

void static_sk_vertices_delete(int key) {
    static_sk_vertices[key].reset();
    static_sk_vertices.erase(key);
}

SkVertices *static_sk_vertices_get(int key) {
    return static_sk_vertices[key].get();
}

void static_sk_vertices_set(int key, sk_sp<SkVertices> value) {
    static_sk_vertices[key] = std::move(value);
}

sk_sp<SkVertices> static_sk_vertices_move(int key) {
    return std::move(static_sk_vertices[key]);
}