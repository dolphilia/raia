//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_EXECUTOR_H
#define RAIA_SKIA_SK_EXECUTOR_H

#include "include/core/SkExecutor.h"
#include "../static/static_sk_executor.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkExecutor_delete(SkExecutor *executor);
RAIA_API void SkExecutor_add(int function_void_void_key_in, SkExecutor *executor);
RAIA_API void SkExecutor_borrow(SkExecutor *executor);
// static
RAIA_API sk_executor_t SkExecutor_MakeFIFOThreadPool(int threads, bool allowBorrowing);
RAIA_API sk_executor_t SkExecutor_MakeLIFOThreadPool(int threads, bool allowBorrowing);
RAIA_API SkExecutor *SkExecutor_GetDefault();
RAIA_API void SkExecutor_SetDefault(SkExecutor * executor);
}

#endif //RAIA_SKIA_SK_EXECUTOR_H
