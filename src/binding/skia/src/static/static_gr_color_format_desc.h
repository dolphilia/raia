//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H
#define RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

int static_gr_color_format_desc_make(GrColorFormatDesc value);
void static_gr_color_format_desc_delete(int key);
GrColorFormatDesc static_gr_color_format_desc_get(int key);
void static_gr_color_format_desc_set(int key, GrColorFormatDesc value);

#endif //RAIA_SKIA_STATIC_GR_COLOR_FORMAT_DESC_H