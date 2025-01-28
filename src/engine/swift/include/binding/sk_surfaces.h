//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SURFACES_H
#define RAIA_SKIA_SK_SURFACES_H

#ifdef __cplusplus
extern "C" {
#endif

int SkSurfaces_Null(int width, int height); // (int width, int height) -> sk_surface_t
int SkSurfaces_Raster(const void *imageInfo, unsigned long rowBytes, const void *surfaceProps); // (const SkImageInfo *imageInfo, size_t rowBytes, const SkSurfaceProps *surfaceProps) -> sk_surface_t
int SkSurfaces_Raster_2(const void *imageInfo, const void *props); // (const SkImageInfo *imageInfo, const SkSurfaceProps *props) -> sk_surface_t
int SkSurfaces_WrapPixels(const void *imageInfo, void *pixels, unsigned long rowBytes, const void *surfaceProps); // (const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, const SkSurfaceProps *surfaceProps) -> sk_surface_t
int SkSurfaces_WrapPixels_2(const void *pm, const void *props); // (const SkPixmap *pm, const SkSurfaceProps *props) -> sk_surface_t
int SkSurfaces_WrapPixels_3(const void *imageInfo, void *pixels, unsigned long rowBytes, void(* pixelsReleaseProc)(void *, void *), void *context, const void *surfaceProps); // (const SkImageInfo *imageInfo, void *pixels, size_t rowBytes, SkSurfaces::PixelsReleaseProc pixelsReleaseProc, void *context, const SkSurfaceProps *surfaceProps) -> sk_surface_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SURFACES_H
