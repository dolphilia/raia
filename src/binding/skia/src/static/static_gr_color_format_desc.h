//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H
#define RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H

#include <set>
#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

typedef int gr_color_format_desc_t;

int static_gr_color_format_desc_make(GrColorFormatDesc value);
extern "C" void static_gr_color_format_desc_delete(int key);
GrColorFormatDesc static_gr_color_format_desc_get(int key);
void static_gr_color_format_desc_set(int key, GrColorFormatDesc value);

#endif //RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H
