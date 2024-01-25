//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SURFACES_H
#define RAIA_SKIA_SK_SURFACES_H

#include "include/core/SkSurface.h"
#include "../static/static_sk_surface.h"

extern "C" {
int SkSurfaces_Null(int width, int height);
int SkSurfaces_Raster(const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps);
int SkSurfaces_Raster_2(const SkImageInfo *imageInfo, const SkSurfaceProps *props);
int SkSurfaces_WrapPixels(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps);
int SkSurfaces_WrapPixels_2(const SkPixmap *pm, const SkSurfaceProps *props);
int SkSurfaces_WrapPixels_3(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps);
}

#endif //RAIA_SKIA_SK_SURFACES_H
