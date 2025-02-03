extension Skia {
    class SurfaceProps {
        public var pointer: Skia.SurfacePropsMutablePointer?
        public var handle: sk_surface_props_t?

        // void *SkSurfaceProps_new(); // () -> SkSurfaceProps *

        init() {
            self.pointer = SkSurfaceProps_new();
            self.handle = nil
        }
        // void *SkSurfaceProps_new_2(unsigned int flags, int geometry); // (uint32_t flags, SkPixelGeometry geometry) -> SkSurfaceProps *

        init(flags: UInt, geometry: PixelGeometry) {
            self.pointer = SkSurfaceProps_new_2(UInt32(flags), Int32(geometry.rawValue));
            self.handle = nil
        }
        // void *SkSurfaceProps_new_3(const void *props); // (const SkSurfaceProps *props) -> SkSurfaceProps *

        init(props: SurfaceProps) {
            self.pointer = SkSurfaceProps_new_3(props.pointer);
            self.handle = nil
        }
        // void SkSurfaceProps_delete(void *surface_props); // (SkSurfaceProps *surface_props)

        deinit {
            SkSurfaceProps_delete(self.pointer)
            if let handle = self.handle {
                static_sk_surface_props_delete(handle)
            }
        }
        // int SkSurfaceProps_cloneWithPixelGeometry(void *surface_props, int newPixelGeometry); // (SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry) -> sk_surface_props_t

        func cloneWithPixelGeometry(newPixelGeometry: PixelGeometry) -> SurfaceProps {
            let handle = SkSurfaceProps_cloneWithPixelGeometry(self.pointer, Int32(newPixelGeometry.rawValue));
            let pointer = static_sk_surface_props_get_ptr(handle)
            return SurfaceProps(pointer: pointer, handle: handle)
        }
        // unsigned int SkSurfaceProps_flags(void *surface_props); // (SkSurfaceProps *surface_props) -> uint32_t

        func flags() -> UInt {
            return UInt(SkSurfaceProps_flags(self.pointer))
        }
        // int SkSurfaceProps_pixelGeometry(void *surface_props); // (SkSurfaceProps *surface_props) -> SkPixelGeometry

        func pixelGeometry() -> PixelGeometry {
            return PixelGeometry(rawValue: Int32(SkSurfaceProps_pixelGeometry(self.pointer)))!
        }
        // bool SkSurfaceProps_isUseDeviceIndependentFonts(void *surface_props); // (SkSurfaceProps *surface_props) -> bool

        func isUseDeviceIndependentFonts() -> Bool {
            return SkSurfaceProps_isUseDeviceIndependentFonts(self.pointer)
        }
        // bool SkSurfaceProps_isAlwaysDither(void *surface_props); // (SkSurfaceProps *surface_props) -> bool

        func isAlwaysDither() -> Bool {
            return SkSurfaceProps_isAlwaysDither(self.pointer)
        }

        // static

        init(pointer: Skia.SurfacePropsMutablePointer?, handle: sk_surface_props_t?) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}