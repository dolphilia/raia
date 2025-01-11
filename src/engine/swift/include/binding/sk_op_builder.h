//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OP_BUILDER_H
#define RAIA_SKIA_SK_OP_BUILDER_H

#include "include/pathops/SkPathOps.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkOpBuilder_delete(SkOpBuilder *opBuilder);
RAIA_API void SkOpBuilder_add(SkOpBuilder *op_builder, const SkPath *path, SkPathOp path_operator);
RAIA_API bool SkOpBuilder_resolve(SkOpBuilder *op_builder, SkPath *result);
}

#endif //RAIA_SKIA_SK_OP_BUILDER_H
