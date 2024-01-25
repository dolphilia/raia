//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SURFACES_H
#define RAIA_SKIA_SK_SURFACES_H

#include "include/core/SkSurface.h"
#include "../static/static_sk_surface.h"

extern "C" {
void SkSurfaces_Null(int sk_surface_key_out, int width, int height);
void SkSurfaces_Raster(int sk_surface_key_out, const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps);
void SkSurfaces_Raster_2(int sk_surface_key_out, const SkImageInfo *imageInfo, const SkSurfaceProps *props);
void SkSurfaces_WrapPixels(int sk_surface_key_out, const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps);
void SkSurfaces_WrapPixels_2(int sk_surface_key_out, const SkPixmap *pm, const SkSurfaceProps *props);
void SkSurfaces_WrapPixels_3(int sk_surface_key_out, const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps);
}

#endif //RAIA_SKIA_SK_SURFACES_H
