//
// Created by dolphilia on 2024/01/09.
//

#include "sk_op_builder.h"

extern "C" {

void SkOpBuilder_delete(SkOpBuilder *opBuilder) {
    delete opBuilder;
}

void SkOpBuilder_add(SkOpBuilder *op_builder, const SkPath *path, SkPathOp path_operator) {
    op_builder->add(*path, path_operator);
}

bool SkOpBuilder_resolve(SkOpBuilder *op_builder, SkPath *result) {
    return op_builder->resolve(result);
}

}