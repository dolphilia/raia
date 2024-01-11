//
// Created by dolphilia on 2024/01/08.
//

#include "sk_executor.h"

extern "C" {

void SkExecutor_add(SkExecutor *executor, std::function<void(void)> fn) { // @TODO
    executor->add(std::move(fn));
}

void SkExecutor_borrow(SkExecutor *executor) {
    executor->borrow();
}

// static

void SkExecutor_MakeFIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor_set(sk_executor_key_out, SkExecutor::MakeFIFOThreadPool(threads, allowBorrowing));
}

void SkExecutor_MakeLIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor_set(sk_executor_key_out, SkExecutor::MakeLIFOThreadPool(threads, allowBorrowing));
}

SkExecutor *SkExecutor_GetDefault() {
    return &SkExecutor::GetDefault();
}

void SkExecutor_SetDefault(SkExecutor * executor) {
    SkExecutor::SetDefault(executor);
}

}