//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_executor.h"

static std::set<int> static_sk_executor_available_keys;
static std::map<int , std::unique_ptr<SkExecutor>> static_sk_executor;
static int static_sk_executor_index = 0;

int static_sk_executor_make(std::unique_ptr<SkExecutor> value) {
    int key;
    if (!static_sk_executor_available_keys.empty()) {
        auto it = static_sk_executor_available_keys.begin();
        key = *it;
        static_sk_executor_available_keys.erase(it);
    } else {
        key = static_sk_executor_index++;
    }
    static_sk_executor[key] = std::move(value);
    return key;
}

void static_sk_executor_delete(int key) {
    static_sk_executor[key].reset();
    static_sk_executor.erase(key);
    static_sk_executor_available_keys.insert(key);
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