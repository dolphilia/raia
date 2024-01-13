//
// Created by dolphilia on 2024/01/12.
//

#include "gr_backend_semaphore.h"

extern "C" {

// GrBackendSemaphore & 	operator= (const GrBackendSemaphore &)

GrBackendSemaphore *GrBackendSemaphore_new() {
    return new GrBackendSemaphore();
}

GrBackendSemaphore *GrBackendSemaphore_new_2(const GrBackendSemaphore *semaphore) {
    return new GrBackendSemaphore(*semaphore);
}

void GrBackendSemaphore_delete(GrBackendSemaphore *backend_semaphore) {
    delete backend_semaphore;
}

bool GrBackendSemaphore_isInitialized(GrBackendSemaphore *backend_semaphore) {
    return backend_semaphore->isInitialized();
}

GrBackendApi GrBackendSemaphore_backend(GrBackendSemaphore *backend_semaphore) {
    return backend_semaphore->backend();
}

}