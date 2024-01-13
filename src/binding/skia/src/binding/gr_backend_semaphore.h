//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_BACKEND_SEMAPHORE_H
#define RAIA_SKIA_GR_BACKEND_SEMAPHORE_H

#include "include/gpu/GrBackendSemaphore.h"

extern "C" {
// GrBackendSemaphore & operator= (const GrBackendSemaphore &)
GrBackendSemaphore *GrBackendSemaphore_new();
GrBackendSemaphore *GrBackendSemaphore_new_2(const GrBackendSemaphore *semaphore);
void GrBackendSemaphore_delete(GrBackendSemaphore *backend_semaphore);
bool GrBackendSemaphore_isInitialized(GrBackendSemaphore *backend_semaphore);
GrBackendApi GrBackendSemaphore_backend(GrBackendSemaphore *backend_semaphore);
}

#endif //RAIA_SKIA_GR_BACKEND_SEMAPHORE_H
