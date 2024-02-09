//
// Created by dolphilia on 2024/01/08.
//

#include "sk_executor.h"
#include "../static/static_std_function_void_void.h"

extern "C" {

void SkExecutor_delete(SkExecutor *executor) {
    delete executor;
}

void SkExecutor_add(int function_void_void_key_in, SkExecutor *executor) {
    executor->add(static_function_void_void_get(function_void_void_key_in));
}

void SkExecutor_borrow(SkExecutor *executor) {
    executor->borrow();
}

// static

sk_executor_t SkExecutor_MakeFIFOThreadPool(int threads, bool allowBorrowing) {
    return static_sk_executor_make(SkExecutor::MakeFIFOThreadPool(threads, allowBorrowing));
}

sk_executor_t SkExecutor_MakeLIFOThreadPool(int threads, bool allowBorrowing) {
    return static_sk_executor_make(SkExecutor::MakeLIFOThreadPool(threads, allowBorrowing));
}

SkExecutor *SkExecutor_GetDefault() {
    return &SkExecutor::GetDefault();
}

void SkExecutor_SetDefault(SkExecutor * executor) {
    SkExecutor::SetDefault(executor);
}

}