//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SURFACES_H
#define RAIA_SKIA_SK_SURFACES_H

#include "include/core/SkSurface.h"
#include "../static/static_sk_surface.h"
#include "export_api.h"

extern "C" {
RAIA_API sk_surface_t SkSurfaces_Null(int width, int height);
RAIA_API sk_surface_t SkSurfaces_Raster(const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps);
RAIA_API sk_surface_t SkSurfaces_Raster_2(const SkImageInfo *imageInfo, const SkSurfaceProps *props);
RAIA_API sk_surface_t SkSurfaces_WrapPixels(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps);
RAIA_API sk_surface_t SkSurfaces_WrapPixels_2(const SkPixmap *pm, const SkSurfaceProps *props);
RAIA_API sk_surface_t SkSurfaces_WrapPixels_3(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps);
}

#endif //RAIA_SKIA_SK_SURFACES_H
