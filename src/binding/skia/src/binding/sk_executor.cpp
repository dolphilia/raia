//
// Created by dolphilia on 2024/01/08.
//

#include "sk_executor.h"
#include "../static/static_std_function_void_void.h"

extern "C" {

void SkExecutor_add(int function_void_void_key_in, SkExecutor *executor) {
    executor->add(static_function_void_void_get(function_void_void_key_in));
}

void SkExecutor_borrow(SkExecutor *executor) {
    executor->borrow();
}

// static

void SkExecutor_MakeFIFOThreadPool(int sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor_set(sk_executor_key_out, SkExecutor::MakeFIFOThreadPool(threads, allowBorrowing));
}

void SkExecutor_MakeLIFOThreadPool(int sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor_set(sk_executor_key_out, SkExecutor::MakeLIFOThreadPool(threads, allowBorrowing));
}

SkExecutor *SkExecutor_GetDefault() {
    return &SkExecutor::GetDefault();
}

void SkExecutor_SetDefault(SkExecutor * executor) {
    SkExecutor::SetDefault(executor);
}

}