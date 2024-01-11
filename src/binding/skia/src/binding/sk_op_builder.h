//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OP_BUILDER_H
#define RAIA_SKIA_SK_OP_BUILDER_H

#include "include/pathops/SkPathOps.h"

extern "C" {
void SkOpBuilder_add(SkOpBuilder *op_builder, const SkPath &path, SkPathOp _operator);
bool SkOpBuilder_resolve(SkOpBuilder *op_builder, SkPath *result);
}

#endif //RAIA_SKIA_SK_OP_BUILDER_H
