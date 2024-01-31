//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H
#define RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

int static_gr_backend_format_make(GrBackendFormat value);
extern "C" {
void static_gr_backend_format_delete(int key);
}
GrBackendFormat static_gr_backend_format_get(int key);
void static_gr_backend_format_set(int key, GrBackendFormat value);


#endif //RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H