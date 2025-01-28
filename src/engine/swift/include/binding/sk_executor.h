//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_EXECUTOR_H
#define RAIA_SKIA_SK_EXECUTOR_H

#ifdef __cplusplus
extern "C" {
#endif

void SkExecutor_delete(void *executor); // (SkExecutor *executor)
void SkExecutor_add(int function_void_void_key_in, void *executor); // (int function_void_void_key_in, SkExecutor *executor)
void SkExecutor_borrow(void *executor); // (SkExecutor *executor)

// static

int SkExecutor_MakeFIFOThreadPool(int threads, bool allowBorrowing); // (int threads, bool allowBorrowing) -> sk_executor_t
int SkExecutor_MakeLIFOThreadPool(int threads, bool allowBorrowing); // (int threads, bool allowBorrowing) -> sk_executor_t
void *SkExecutor_GetDefault(); // () -> SkExecutor *
void SkExecutor_SetDefault(void * executor); // (SkExecutor *executor)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_EXECUTOR_H
