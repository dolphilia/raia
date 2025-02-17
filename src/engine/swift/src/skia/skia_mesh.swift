extension Skia {
    typealias sk_mesh_t = Int32
    class SkMesh {
        
        public var pointer: SkMeshMutablePointer?
        public var handle: sk_mesh_t = -1

        // void SkMesh_delete(void * mesh); // (SkMesh * mesh)
        deinit {
            if self.handle > -1 {
                //static_sk_mesh_delete(self.handle)
            } else {
                SkMesh_delete(self.pointer)
            }
        }
        // int SkMesh_refSpec(void * mesh); // (SkMesh *mesh) -> sk_mesh_specification_t
        // void * SkMesh_spec(void * mesh); // (SkMesh *mesh) -> SkMeshSpecification*
        // int SkMesh_mode(void * mesh); // (SkMesh *mesh) -> SkMesh::Mode
        // int SkMesh_refVertexBuffer(void * mesh); // (SkMesh *mesh) -> sk_mesh_vertex_buffer_t
        // void * SkMesh_vertexBuffer(void * mesh); // (SkMesh *mesh) -> SkMesh::VertexBuffer*
        // unsigned long SkMesh_vertexOffset(void * mesh); // (SkMesh *mesh) -> size_t

        func vertexOffset() -> UInt {
            return UInt(SkMesh_vertexOffset(self.pointer))
        }
        // unsigned long SkMesh_vertexCount(void * mesh); // (SkMesh *mesh) -> size_t

        func vertexCount() -> UInt {
            return UInt(SkMesh_vertexCount(self.pointer))
        }
        // int SkMesh_refIndexBuffer(void * mesh); // (SkMesh *mesh) -> sk_mesh_index_buffer_t
        // void * SkMesh_indexBuffer(void * mesh); // (SkMesh *mesh) -> SkMesh::IndexBuffer*
        // unsigned long SkMesh_indexOffset(void * mesh); // (SkMesh *mesh) -> size_t

        func indexOffset() -> UInt {
            return UInt(SkMesh_indexOffset(self.pointer))
        }
        // unsigned long SkMesh_indexCount(void * mesh); // (SkMesh *mesh) -> size_t

        func indexCount() -> UInt {
            return UInt(SkMesh_indexCount(self.pointer))
        }
        // int SkMesh_refUniforms(void * mesh); // (SkMesh *mesh) -> const_sk_data_t

        func refUniforms() -> SkData {
            let handle = SkMesh_refUniforms(self.pointer)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // const void * SkMesh_uniforms(void * mesh); // (SkMesh *mesh) -> const SkData*

        func uniforms() -> SkData {
            let pointer = SkMesh_uniforms(self.pointer)
            return SkData(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // int SkMesh_children(void * mesh); // (SkMesh *mesh) -> const_sk_mesh_child_ptr_t
        // int SkMesh_bounds(void * mesh); // (SkMesh *mesh) -> sk_rect_t

        func bounds() -> SkRect {
            let handle = SkMesh_bounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }
        // bool SkMesh_isValid(void * mesh); // (SkMesh *mesh) -> bool

        func isValid() -> Bool {
            return SkMesh_isValid(self.pointer)
        }
        // // static

        init(pointer: SkMeshMutablePointer?, handle: sk_mesh_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkMesh_Make(int spec, int mode, int vBuffer, unsigned long vertexCount, unsigned long vertexOffset, int uniforms, int children, const void * bounds); // (sk_mesh_specification_t spec, SkMesh::Mode mode, sk_mesh_vertex_buffer_t vBuffer, size_t vertexCount, size_t vertexOffset, const_sk_data_t uniforms, sk_mesh_child_ptr_t children, const SkRect *bounds) -> sk_mesh_result_t
        // int SkMesh_MakeIndexed(int spec, int mode, int vBuffer, unsigned long vertexCount, unsigned long vertexOffset, int iBuffer, unsigned long indexCount, unsigned long indexOffset, int uniforms, int children, const void * bounds); // (sk_mesh_specification_t spec, SkMesh::Mode mode, sk_mesh_vertex_buffer_t vBuffer, size_t vertexCount, size_t vertexOffset, sk_mesh_index_buffer_t iBuffer, size_t indexCount, size_t indexOffset, const_sk_data_t uniforms, sk_mesh_child_ptr_t children, const SkRect *bounds) -> sk_mesh_result_t

    }
}