//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SURFACE_PROPS_H
#define RAIA_SKIA_SK_SURFACE_PROPS_H

#ifdef __cplusplus
extern "C" {
#endif

// SkSurfaceProps & operator=(const SkSurfaceProps &)
// bool operator==(const SkSurfaceProps &that)
// bool operator!=(const SkSurfaceProps &that)

void *SkSurfaceProps_new(); // () -> SkSurfaceProps *
void *SkSurfaceProps_new_2(unsigned int flags, int geometry); // (uint32_t flags, SkPixelGeometry geometry) -> SkSurfaceProps *
void *SkSurfaceProps_new_3(const void *props); // (const SkSurfaceProps *props) -> SkSurfaceProps *
void SkSurfaceProps_delete(void *surface_props); // (SkSurfaceProps *surface_props)
int SkSurfaceProps_cloneWithPixelGeometry(void *surface_props, int newPixelGeometry); // (SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry) -> sk_surface_props_t
unsigned int SkSurfaceProps_flags(void *surface_props); // (SkSurfaceProps *surface_props) -> uint32_t
int SkSurfaceProps_pixelGeometry(void *surface_props); // (SkSurfaceProps *surface_props) -> SkPixelGeometry
bool SkSurfaceProps_isUseDeviceIndependentFonts(void *surface_props); // (SkSurfaceProps *surface_props) -> bool
bool SkSurfaceProps_isAlwaysDither(void *surface_props); // (SkSurfaceProps *surface_props) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SURFACE_PROPS_H
