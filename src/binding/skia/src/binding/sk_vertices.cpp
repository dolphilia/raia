//
// Created by dolphilia on 2024/01/11.
//

#include "sk_vertices.h"

extern "C" {

void SkVertices_delete(SkVertices * vertices) {
    delete &vertices;
}

uint32_t SkVertices_uniqueID(SkVertices *vertices) {
    return vertices->uniqueID();
}

const SkRect * SkVertices_bounds(SkVertices *vertices) {
    return &vertices->bounds();
}

size_t SkVertices_approximateSize(SkVertices *vertices) {
    return vertices->approximateSize();
}

//SkVerticesPriv SkVertices_priv(SkVertices *vertices) {
//    return vertices->priv();
//}

//const SkVerticesPriv SkVertices_priv_2(SkVertices *vertices) {
//    return vertices->priv();
//}

bool SkVertices_unique(SkVertices *vertices) {
    return vertices->unique();
}

void SkVertices_ref(SkVertices *vertices) {
    vertices->ref();
}

void SkVertices_unref(SkVertices *vertices) {
    vertices->unref();
}

void SkVertices_deref(SkVertices *vertices) {
    vertices->deref();
}

bool SkVertices_refCntGreaterThan(SkVertices *vertices, int32_t threadIsolatedTestCnt) {
    return vertices->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

sk_vertices_t SkVertices_MakeCopy(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[]) {
    return static_sk_vertices_make(SkVertices::MakeCopy(mode, vertexCount, positions, texs, colors, indexCount, indices));
}

sk_vertices_t SkVertices_MakeCopy_2(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[]) {
    return static_sk_vertices_make(SkVertices::MakeCopy(mode, vertexCount, positions, texs, colors));
}

}