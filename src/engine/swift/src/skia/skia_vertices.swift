extension Skia {
    class SkVertices {
        public var pointer: SkVerticesMutablePointer?
        public var handle: sk_vertices_t = -1

        // void SkVertices_delete(void *vertices); // (SkVertices *vertices)
        // unsigned int SkVertices_uniqueID(void *vertices); // (SkVertices *vertices) -> uint32_t
        // const void * SkVertices_bounds(void *vertices); // (SkVertices *vertices) -> const SkRect *
        // unsigned long SkVertices_approximateSize(void *vertices); // (SkVertices *vertices) -> size_t

        // // SkVerticesPriv SkVertices_priv(SkVertices *vertices); // (SkVertices *vertices) -> SkVerticesPriv
        // // const SkVerticesPriv SkVertices_priv_2(SkVertices *vertices); // (SkVertices *vertices) -> const SkVerticesPriv

        // bool SkVertices_unique(void *vertices); // (SkVertices *vertices) -> bool
        // void SkVertices_ref(void *vertices); // (SkVertices *vertices)
        // void SkVertices_unref(void *vertices); // (SkVertices *vertices)
        // void SkVertices_deref(void *vertices); // (SkVertices *vertices)
        // bool SkVertices_refCntGreaterThan(void *vertices, int threadIsolatedTestCnt); // (SkVertices *vertices, int32_t threadIsolatedTestCnt) -> bool

        // // static

        init(pointer: SkVerticesMutablePointer?, handle: sk_vertices_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkVertices_MakeCopy(int mode, int vertexCount, const void * positions, const void * texs, const void * colors, int indexCount, const void * indices); // (SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[]) -> sk_vertices_t
        // int SkVertices_MakeCopy_2(int mode, int vertexCount, const void * positions, const void * texs, const void * colors); // (SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[]) -> sk_vertices_t

    }
}