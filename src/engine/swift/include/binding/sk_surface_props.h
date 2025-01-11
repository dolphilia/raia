//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SURFACE_PROPS_H
#define RAIA_SKIA_SK_SURFACE_PROPS_H

#include "include/core/SkSurfaceProps.h"
#include "../static/static_sk_surface_props.h"
#include "export_api.h"

extern "C" {
// SkSurfaceProps & operator=(const SkSurfaceProps &)
// bool operator==(const SkSurfaceProps &that)
// bool operator!=(const SkSurfaceProps &that)
RAIA_API SkSurfaceProps *SkSurfaceProps_new();
RAIA_API SkSurfaceProps *SkSurfaceProps_new_2(uint32_t flags, SkPixelGeometry geometry);
RAIA_API SkSurfaceProps *SkSurfaceProps_new_3(const SkSurfaceProps *props);
RAIA_API void SkSurfaceProps_delete(SkSurfaceProps *surface_props);
RAIA_API sk_surface_props_t SkSurfaceProps_cloneWithPixelGeometry(SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry);
RAIA_API uint32_t SkSurfaceProps_flags(SkSurfaceProps *surface_props);
RAIA_API SkPixelGeometry SkSurfaceProps_pixelGeometry(SkSurfaceProps *surface_props);
RAIA_API bool SkSurfaceProps_isUseDeviceIndependentFonts(SkSurfaceProps *surface_props);
RAIA_API bool SkSurfaceProps_isAlwaysDither(SkSurfaceProps *surface_props);
}

#endif //RAIA_SKIA_SK_SURFACE_PROPS_H
