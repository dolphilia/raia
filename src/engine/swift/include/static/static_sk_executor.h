//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_EXECUTOR_H
#define RAIA_SKIA_STATIC_SK_EXECUTOR_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_executor_t;
void static_sk_executor_delete(int key);
void *static_sk_executor_get(int key); // -> SkExecutor *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_EXECUTOR_H
