//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H
#define RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

void static_gr_color_format_desc_delete(const char *key);
GrColorFormatDesc static_gr_color_format_desc_get(const char *key);
void static_gr_color_format_desc_set(const char *key, GrColorFormatDesc value);

#endif //RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H
