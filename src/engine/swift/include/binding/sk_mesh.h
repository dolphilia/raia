//
// Created by dolphilia on 25/02/04.
//

#ifndef SK_MESH_H
#define SK_MESH_H

#ifdef __cplusplus
extern "C" {
#endif

void SkMesh_delete(void * mesh); // (SkMesh * mesh)
int SkMesh_refSpec(void * mesh); // (SkMesh *mesh) -> sk_mesh_specification_t
void * SkMesh_spec(void * mesh); // (SkMesh *mesh) -> SkMeshSpecification*
int SkMesh_mode(void * mesh); // (SkMesh *mesh) -> SkMesh::Mode
int SkMesh_refVertexBuffer(void * mesh); // (SkMesh *mesh) -> sk_mesh_vertex_buffer_t
void * SkMesh_vertexBuffer(void * mesh); // (SkMesh *mesh) -> SkMesh::VertexBuffer*
unsigned long SkMesh_vertexOffset(void * mesh); // (SkMesh *mesh) -> size_t
unsigned long SkMesh_vertexCount(void * mesh); // (SkMesh *mesh) -> size_t
int SkMesh_refIndexBuffer(void * mesh); // (SkMesh *mesh) -> sk_mesh_index_buffer_t
void * SkMesh_indexBuffer(void * mesh); // (SkMesh *mesh) -> SkMesh::IndexBuffer*
unsigned long SkMesh_indexOffset(void * mesh); // (SkMesh *mesh) -> size_t
unsigned long SkMesh_indexCount(void * mesh); // (SkMesh *mesh) -> size_t
int SkMesh_refUniforms(void * mesh); // (SkMesh *mesh) -> const_sk_data_t
const void * SkMesh_uniforms(void * mesh); // (SkMesh *mesh) -> const SkData*
int SkMesh_children(void * mesh); // (SkMesh *mesh) -> const_sk_mesh_child_ptr_t
int SkMesh_bounds(void * mesh); // (SkMesh *mesh) -> sk_rect_t
bool SkMesh_isValid(void * mesh); // (SkMesh *mesh) -> bool
// static
int SkMesh_Make(int spec, int mode, int vBuffer, unsigned long vertexCount, unsigned long vertexOffset, int uniforms, int children, const void * bounds); // (sk_mesh_specification_t spec, SkMesh::Mode mode, sk_mesh_vertex_buffer_t vBuffer, size_t vertexCount, size_t vertexOffset, const_sk_data_t uniforms, sk_mesh_child_ptr_t children, const SkRect *bounds) -> sk_mesh_result_t
int SkMesh_MakeIndexed(int spec, int mode, int vBuffer, unsigned long vertexCount, unsigned long vertexOffset, int iBuffer, unsigned long indexCount, unsigned long indexOffset, int uniforms, int children, const void * bounds); // (sk_mesh_specification_t spec, SkMesh::Mode mode, sk_mesh_vertex_buffer_t vBuffer, size_t vertexCount, size_t vertexOffset, sk_mesh_index_buffer_t iBuffer, size_t indexCount, size_t indexOffset, const_sk_data_t uniforms, sk_mesh_child_ptr_t children, const SkRect *bounds) -> sk_mesh_result_t

#ifdef __cplusplus
}
#endif

#endif //SK_MESH_H
