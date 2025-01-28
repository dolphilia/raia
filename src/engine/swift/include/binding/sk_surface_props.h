//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SURFACE_PROPS_H
#define RAIA_SKIA_SK_SURFACE_PROPS_H

#include "include/core/SkSurfaceProps.h"
#include "../static/static_sk_surface_props.h"

extern "C" {
// SkSurfaceProps & operator=(const SkSurfaceProps &)
// bool operator==(const SkSurfaceProps &that)
// bool operator!=(const SkSurfaceProps &that)
SkSurfaceProps *SkSurfaceProps_new();
SkSurfaceProps *SkSurfaceProps_new_2(uint32_t flags, SkPixelGeometry geometry);
SkSurfaceProps *SkSurfaceProps_new_3(const SkSurfaceProps *props);
void SkSurfaceProps_delete(SkSurfaceProps *surface_props);
sk_surface_props_t SkSurfaceProps_cloneWithPixelGeometry(SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry);
uint32_t SkSurfaceProps_flags(SkSurfaceProps *surface_props);
SkPixelGeometry SkSurfaceProps_pixelGeometry(SkSurfaceProps *surface_props);
bool SkSurfaceProps_isUseDeviceIndependentFonts(SkSurfaceProps *surface_props);
bool SkSurfaceProps_isAlwaysDither(SkSurfaceProps *surface_props);
}

#endif //RAIA_SKIA_SK_SURFACE_PROPS_H
