//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mesh_child_ptr.h"

#include <string>
#include <map>
#include "include/core/SkMesh.h"
#include "static_sk_mesh_child_ptr-internal.h"

static std::map<int , SkSpan<SkMesh::ChildPtr>> static_sk_mesh_child_ptr;
static std::map<int , SkSpan<const SkMesh::ChildPtr>> static_const_sk_mesh_child_ptr;

