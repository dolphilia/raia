//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_EXECUTOR_H
#define RAIA_SKIA_STATIC_SK_EXECUTOR_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkExecutor.h"

typedef int sk_executor_t;

int static_sk_executor_make(std::unique_ptr<SkExecutor> value);
extern "C" void static_sk_executor_delete(int key);
extern "C" SkExecutor *static_sk_executor_get(int key);
void static_sk_executor_set(int key, std::unique_ptr<SkExecutor> value);
std::unique_ptr<SkExecutor> static_sk_executor_move(int key);

#endif //RAIA_SKIA_STATIC_SK_EXECUTOR_H
