//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H
#define RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

void static_gr_backend_format_delete(const char *key);
GrBackendFormat static_gr_backend_format_get(const char *key);
void static_gr_backend_format_set(const char *key, GrBackendFormat value);

#endif //RAIA_SKIA_STATIC_GR_BACKEND_FORMAT_H
