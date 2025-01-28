//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_vertices.h"

#include <utility>
#include "static_sk_vertices-internal.h"

static std::set<int> static_sk_vertices_available_keys;
static std::map<int , sk_sp<SkVertices>> static_sk_vertices;
static int static_sk_vertices_index = 0;

int static_sk_vertices_make(sk_sp<SkVertices> value) {
    int key;
    if (!static_sk_vertices_available_keys.empty()) {
        auto it = static_sk_vertices_available_keys.begin();
        key = *it;
        static_sk_vertices_available_keys.erase(it);
    } else {
        key = static_sk_vertices_index++;
    }
    static_sk_vertices[key] = std::move(value);
    return key;
}

void static_sk_vertices_delete(int key) {
    static_sk_vertices[key].reset();
    static_sk_vertices.erase(key);
    static_sk_vertices_available_keys.insert(key);
}

void * static_sk_vertices_get(int key) { // -> SkVertices *
    return static_sk_vertices[key].get();
}

void static_sk_vertices_set(int key, sk_sp<SkVertices> value) {
    static_sk_vertices[key] = std::move(value);
}

sk_sp<SkVertices> static_sk_vertices_move(int key) {
    return std::move(static_sk_vertices[key]);
}
