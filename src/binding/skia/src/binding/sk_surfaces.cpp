//
// Created by dolphilia on 2024/01/13.
//

#include "sk_surfaces.h"

extern "C" {

void SkSurfaces_Null(int sk_surface_key_out, int width, int height) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::Null(width, height));
}

void SkSurfaces_Raster(int sk_surface_key_out, const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::Raster(*imageInfo, rowBytes, surfaceProps));
}

void SkSurfaces_Raster_2(int sk_surface_key_out, const SkImageInfo *imageInfo, const SkSurfaceProps *props) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::Raster(*imageInfo, props));
}

void SkSurfaces_WrapPixels(int sk_surface_key_out, const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::WrapPixels(*imageInfo, pixels, rowBytes, surfaceProps));
}

void SkSurfaces_WrapPixels_2(int sk_surface_key_out, const SkPixmap *pm, const SkSurfaceProps *props) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::WrapPixels(*pm, props));
}

void SkSurfaces_WrapPixels_3(int sk_surface_key_out, const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps) {
    static_sk_surface_set(sk_surface_key_out, SkSurfaces::WrapPixels(*imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps));
}

}