//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_VERTICES_H
#define RAIA_SKIA_SK_VERTICES_H

#include "include/core/SkVertices.h"
#include "../static/static_sk_vertices.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkVertices_delete(SkVertices * vertices);
RAIA_API uint32_t SkVertices_uniqueID(SkVertices *vertices);
RAIA_API const SkRect * SkVertices_bounds(SkVertices *vertices);
RAIA_API size_t SkVertices_approximateSize(SkVertices *vertices);
//SkVerticesPriv SkVertices_priv(SkVertices *vertices);
//const SkVerticesPriv SkVertices_priv_2(SkVertices *vertices);
RAIA_API bool SkVertices_unique(SkVertices *vertices);
RAIA_API void SkVertices_ref(SkVertices *vertices);
RAIA_API void SkVertices_unref(SkVertices *vertices);
RAIA_API void SkVertices_deref(SkVertices *vertices);
RAIA_API bool SkVertices_refCntGreaterThan(SkVertices *vertices, int32_t threadIsolatedTestCnt);
// static
RAIA_API sk_vertices_t SkVertices_MakeCopy(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[]);
RAIA_API sk_vertices_t SkVertices_MakeCopy_2(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[]);
}

#endif //RAIA_SKIA_SK_VERTICES_H
