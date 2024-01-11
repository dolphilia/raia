//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_VERTICES_H
#define RAIA_SKIA_SK_VERTICES_H

#include "include/core/SkVertices.h"
#include "../static/static_sk_vertices.h"

extern "C" {
uint32_t SkVertices_uniqueID(SkVertices *vertices);
const SkRect * SkVertices_bounds(SkVertices *vertices);
size_t SkVertices_approximateSize(SkVertices *vertices);
//SkVerticesPriv SkVertices_priv(SkVertices *vertices);
//const SkVerticesPriv SkVertices_priv_2(SkVertices *vertices);
bool SkVertices_unique(SkVertices *vertices);
void SkVertices_ref(SkVertices *vertices);
void SkVertices_unref(SkVertices *vertices);
void SkVertices_deref(SkVertices *vertices);
bool SkVertices_refCntGreaterThan(SkVertices *vertices, int32_t threadIsolatedTestCnt);
// static
void SkVertices_MakeCopy(const char *sk_vertices_key_out, SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[]);
void SkVertices_MakeCopy_2(const char *sk_vertices_key_out, SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[]);
}

#endif //RAIA_SKIA_SK_VERTICES_H
