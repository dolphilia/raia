//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_vertices.h"

static std::map<std::string, sk_sp<SkVertices>> static_sk_vertices;

void static_sk_vertices_delete(const char *key) {
    static_sk_vertices[key].reset();
    static_sk_vertices.erase(key);
}

SkVertices *static_sk_vertices_get(const char *key) {
    return static_sk_vertices[key].get();
}

void static_sk_vertices_set(const char *key, sk_sp<SkVertices> value) {
    static_sk_vertices[key] = std::move(value);
}

sk_sp<SkVertices> static_sk_vertices_move(const char *key) {
    return std::move(static_sk_vertices[key]);
}