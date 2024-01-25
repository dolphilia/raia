//
// Created by dolphilia on 2024/01/13.
//

#include "sk_surfaces.h"

extern "C" {

int SkSurfaces_Null(int width, int height) {
    return static_sk_surface_make(SkSurfaces::Null(width, height));
}

int SkSurfaces_Raster(const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps) {
    return static_sk_surface_make(SkSurfaces::Raster(*imageInfo, rowBytes, surfaceProps));
}

int SkSurfaces_Raster_2(const SkImageInfo *imageInfo, const SkSurfaceProps *props) {
    return static_sk_surface_make(SkSurfaces::Raster(*imageInfo, props));
}

int SkSurfaces_WrapPixels(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps) {
    return static_sk_surface_make(SkSurfaces::WrapPixels(*imageInfo, pixels, rowBytes, surfaceProps));
}

int SkSurfaces_WrapPixels_2(const SkPixmap *pm, const SkSurfaceProps *props) {
    return static_sk_surface_make(SkSurfaces::WrapPixels(*pm, props));
}

int SkSurfaces_WrapPixels_3(const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps) {
    return static_sk_surface_make(SkSurfaces::WrapPixels(*imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps));
}

}