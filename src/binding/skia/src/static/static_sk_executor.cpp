//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_executor.h"

static std::map<std::string, std::unique_ptr<SkExecutor>> static_sk_executor;

void static_sk_executor_delete(const char *key) {
    static_sk_executor[key].reset();
    static_sk_executor.erase(key);
}

SkExecutor *static_sk_executor_get(const char *key) {
    return static_sk_executor[key].get();
}

void static_sk_executor_set(const char *key, std::unique_ptr<SkExecutor> value) {
    static_sk_executor[key] = std::move(value);
}

std::unique_ptr<SkExecutor> static_sk_executor_move(const char *key) {
    return std::move(static_sk_executor[key]);
}