//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_executor.h"

static std::map<int , std::unique_ptr<SkExecutor>> static_sk_executor;

void static_sk_executor_delete(int key) {
    static_sk_executor[key].reset();
    static_sk_executor.erase(key);
}

SkExecutor *static_sk_executor_get(int key) {
    return static_sk_executor[key].get();
}

void static_sk_executor_set(int key, std::unique_ptr<SkExecutor> value) {
    static_sk_executor[key] = std::move(value);
}

std::unique_ptr<SkExecutor> static_sk_executor_move(int key) {
    return std::move(static_sk_executor[key]);
}