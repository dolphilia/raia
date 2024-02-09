//
// Created by dolphilia on 2024/01/11.
//

#include "sk_surface_props.h"

extern "C" {

// SkSurfaceProps & operator=(const SkSurfaceProps &)
// bool operator==(const SkSurfaceProps &that)
// bool operator!=(const SkSurfaceProps &that)

SkSurfaceProps *SkSurfaceProps_new() {
    return new SkSurfaceProps();
}

SkSurfaceProps *SkSurfaceProps_new_2(uint32_t flags, SkPixelGeometry geometry) {
    return new SkSurfaceProps(flags, geometry);
}

SkSurfaceProps *SkSurfaceProps_new_3(const SkSurfaceProps *props) {
    return new SkSurfaceProps(*props);
}

void SkSurfaceProps_delete(SkSurfaceProps *surface_props) {
    delete surface_props;
}

sk_surface_props_t SkSurfaceProps_cloneWithPixelGeometry(SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry) {
    return static_sk_surface_props_make(surface_props->cloneWithPixelGeometry(newPixelGeometry));
}

uint32_t SkSurfaceProps_flags(SkSurfaceProps *surface_props) {
    return surface_props->flags();
}

SkPixelGeometry SkSurfaceProps_pixelGeometry(SkSurfaceProps *surface_props) {
    return surface_props->pixelGeometry();
}

bool SkSurfaceProps_isUseDeviceIndependentFonts(SkSurfaceProps *surface_props) {
    return surface_props->isUseDeviceIndependentFonts();
}

bool SkSurfaceProps_isAlwaysDither(SkSurfaceProps *surface_props) {
    return surface_props->isAlwaysDither();
}

}