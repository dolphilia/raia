//
// Created by dolphilia on 25/02/04.
//

#ifndef SK_MESH_SPECIFICATION_H
#define SK_MESH_SPECIFICATION_H

#ifdef __cplusplus
extern "C" {
#endif

int SkMeshSpecification_attributes(void* spec); // (SkMeshSpecification* spec) -> sk_mesh_specification_attribute_t
unsigned long SkMeshSpecification_uniformSize(void* spec); // (SkMeshSpecification* spec) -> size_t
int SkMeshSpecification_uniforms(void* spec); // (SkMeshSpecification* spec) -> const_sk_runtime_effect_uniform_t
int SkMeshSpecification_children(void* spec); // (SkMeshSpecification* spec) -> const_sk_runtime_effect_child_t
const void * SkMeshSpecification_findChild(void* spec, void * name); // (SkMeshSpecification* spec, std::string_view* name) -> const SkRuntimeEffect::Child*
const void * SkMeshSpecification_findUniform(void* spec, void * name); // (SkMeshSpecification* spec, std::string_view* name) -> const SkRuntimeEffect::Uniform*
const void * SkMeshSpecification_findAttribute(void* spec, void * name); // (SkMeshSpecification* spec, std::string_view* name) -> const SkMeshSpecification::Attribute*
const void * SkMeshSpecification_findVarying(void* spec, void * name); // (SkMeshSpecification* spec, std::string_view* name) -> const SkMeshSpecification::Varying*
unsigned long SkMeshSpecification_stride(void* spec); // (SkMeshSpecification* spec) -> size_t
// static
int SkMeshSpecification_Make(void * attributes, unsigned long vertexStride, void * varyings, const void * vs, const void * fs); // (SkSpan<const SkMeshSpecification::Attribute>* attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying>* varyings, const SkString* vs, const SkString* fs) -> sk_mesh_specification_result_t
int SkMeshSpecification_Make_2(void * attributes, unsigned long vertexStride, void * varyings, const void * vs, const void * fs, void * cs); // (SkSpan<const SkMeshSpecification::Attribute>* attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying>* varyings, const SkString* vs, const SkString* fs, sk_sp<SkColorSpace>* cs) -> sk_mesh_specification_result_t
int SkMeshSpecification_Make_3(void * attributes, unsigned long vertexStride, void * varyings, const void * vs, const void * fs, void * cs, int at); // (SkSpan<const SkMeshSpecification::Attribute>* attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying>* varyings, const SkString* vs, const SkString* fs, sk_sp<SkColorSpace>* cs, SkAlphaType at) -> sk_mesh_specification_result_t

#ifdef __cplusplus
}
#endif

#endif //SK_MESH_SPECIFICATION_H
