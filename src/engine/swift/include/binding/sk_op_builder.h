//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OP_BUILDER_H
#define RAIA_SKIA_SK_OP_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkOpBuilder_delete(void *opBuilder); // // (SkOpBuilder *opBuilder)
void SkOpBuilder_add(void *op_builder, const void *path, int path_operator); // // (SkOpBuilder *op_builder, const SkPath *path, SkPathOp path_operator)
bool SkOpBuilder_resolve(void *op_builder, void *result); // // (SkOpBuilder *op_builder, SkPath *result) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_OP_BUILDER_H
