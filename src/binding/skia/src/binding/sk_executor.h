//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_EXECUTOR_H
#define RAIA_SKIA_SK_EXECUTOR_H

#include "include/core/SkExecutor.h"
#include "../static/static_sk_executor.h"

extern "C" {
void SkExecutor_add(const char *function_void_void_key_in, SkExecutor *executor);
void SkExecutor_borrow(SkExecutor *executor);
// static
void SkExecutor_MakeFIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing);
void SkExecutor_MakeLIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing);
SkExecutor *SkExecutor_GetDefault();
void SkExecutor_SetDefault(SkExecutor * executor);
}

#endif //RAIA_SKIA_SK_EXECUTOR_H
