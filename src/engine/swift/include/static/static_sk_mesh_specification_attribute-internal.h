//
// Created by dolphilia on 25/02/05.
//

#ifndef STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_INTERNAL_H
#define STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_INTERNAL_H
#include <string>
#include <set>
#include <map>
#include "include/core/SkMesh.h"
int static_sk_mesh_specification_attribute_make(SkSpan<const SkMeshSpecification::Attribute> value);
SkSpan<const SkMeshSpecification::Attribute> static_sk_mesh_specification_attribute_get_entity(int key);
void static_sk_mesh_specification_attribute_set(int key, SkSpan<const SkMeshSpecification::Attribute> value);
#endif //STATIC_SK_MESH_SPECIFICATION_ATTRIBUTE_INTERNAL_H
