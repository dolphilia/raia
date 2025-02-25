#ifndef STATIC_SK_VERTICES_INTERNAL_H
#define STATIC_SK_VERTICES_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkVertices.h"
int static_sk_vertices_make(sk_sp<SkVertices> value);
void static_sk_vertices_set(int key, sk_sp<SkVertices> value);
sk_sp<SkVertices> static_sk_vertices_get_entity(int key);
#endif // STATIC_SK_VERTICES_INTERNAL_H
