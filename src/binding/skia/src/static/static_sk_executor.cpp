//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_executor.h"

static std::map<int , std::unique_ptr<SkExecutor>> static_sk_executor;
static int static_sk_executor_index = 0;

int static_sk_executor_make(std::unique_ptr<SkExecutor> value) {
    static_sk_executor[static_sk_executor_index] = std::move(value);
    static_sk_executor_index++;
    return static_sk_executor_index - 1;
}

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