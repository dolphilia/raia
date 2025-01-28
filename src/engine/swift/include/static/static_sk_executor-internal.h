#ifndef STATIC_SK_EXECUTOR_INTERNAL_H
#define STATIC_SK_EXECUTOR_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkExecutor.h"
int static_sk_executor_make(std::unique_ptr<SkExecutor> value);
void static_sk_executor_set(int key, std::unique_ptr<SkExecutor> value);
std::unique_ptr<SkExecutor> static_sk_executor_move(int key);
#endif // STATIC_SK_EXECUTOR_INTERNAL_H
