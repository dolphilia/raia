//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_VERTICES_H
#define RAIA_SKIA_STATIC_SK_VERTICES_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkVertices.h"
#include "export_api.h"

typedef int sk_vertices_t;

extern "C" {
RAIA_API void static_sk_vertices_delete(int key);
RAIA_API SkVertices *static_sk_vertices_get(int key);
}

int static_sk_vertices_make(sk_sp<SkVertices> value);
void static_sk_vertices_set(int key, sk_sp<SkVertices> value);
sk_sp<SkVertices> static_sk_vertices_move(int key);

#endif //RAIA_SKIA_STATIC_SK_VERTICES_H
