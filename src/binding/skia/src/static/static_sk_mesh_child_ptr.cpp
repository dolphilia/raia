//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mesh_child_ptr.h"

#include <string>
#include <map>
#include "include/core/SkMesh.h"

static std::map<std::string, SkSpan<SkMesh::ChildPtr>> static_sk_mesh_child_ptr;
static std::map<std::string, SkSpan<const SkMesh::ChildPtr>> static_const_sk_mesh_child_ptr;

