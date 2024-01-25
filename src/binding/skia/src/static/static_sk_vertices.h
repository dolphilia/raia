//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_VERTICES_H
#define RAIA_SKIA_STATIC_SK_VERTICES_H

#include <string>
#include <map>
#include "include/core/SkVertices.h"

void static_sk_vertices_delete(int key);
SkVertices *static_sk_vertices_get(int key);
void static_sk_vertices_set(int key, sk_sp<SkVertices> value);
sk_sp<SkVertices> static_sk_vertices_move(int key);

#endif //RAIA_SKIA_STATIC_SK_VERTICES_H
