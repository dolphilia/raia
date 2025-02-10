extension Skia {
    protocol SkSurfacePropsProtocol {
        var pointer: Skia.SkSurfacePropsMutablePointer? { get set }
        var handle: sk_surface_props_t { get set }
        // deinit // void SkSurfaceProps_delete(void *surface_props); // (SkSurfaceProps *surface_props)
        init(pointer: Skia.SkSurfacePropsMutablePointer?, handle: sk_surface_props_t)
        init() // void *SkSurfaceProps_new(); // () -> SkSurfaceProps *
        init(flags: UInt, geometry: PixelGeometry) // void *SkSurfaceProps_new_2(unsigned int flags, int geometry); // (uint32_t flags, SkPixelGeometry geometry) -> SkSurfaceProps *
        init(props: SkSurfaceProps) // void *SkSurfaceProps_new_3(const void *props); // (const SkSurfaceProps *props) -> SkSurfaceProps *
        func cloneWithPixelGeometry(newPixelGeometry: PixelGeometry) -> SkSurfaceProps // int SkSurfaceProps_cloneWithPixelGeometry(void *surface_props, int newPixelGeometry); // (SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry) -> sk_surface_props_t
        func flags() -> UInt // unsigned int SkSurfaceProps_flags(void *surface_props); // (SkSurfaceProps *surface_props) -> uint32_t
        func pixelGeometry() -> PixelGeometry // int SkSurfaceProps_pixelGeometry(void *surface_props); // (SkSurfaceProps *surface_props) -> SkPixelGeometry
        func isUseDeviceIndependentFonts() -> Bool // bool SkSurfaceProps_isUseDeviceIndependentFonts(void *surface_props); // (SkSurfaceProps *surface_props) -> bool
        func isAlwaysDither() -> Bool // bool SkSurfaceProps_isAlwaysDither(void *surface_props); // (SkSurfaceProps *surface_props) -> bool
    }

    class SkSurfaceProps: SkSurfacePropsProtocol {
        public var pointer: Skia.SkSurfacePropsMutablePointer?
        public var handle: sk_surface_props_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_surface_props_delete(self.handle)
            } else {
                SkSurfaceProps_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkSurfacePropsMutablePointer?, handle: sk_surface_props_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkSurfaceProps_new();
            self.handle = -1
        }
        
        required init(flags: UInt, geometry: PixelGeometry) {
            self.pointer = SkSurfaceProps_new_2(UInt32(flags), Int32(geometry.rawValue));
            self.handle = -1
        }
        
        required init(props: SkSurfaceProps) {
            self.pointer = SkSurfaceProps_new_3(props.pointer);
            self.handle = -1
        }

        // Methods

        func cloneWithPixelGeometry(newPixelGeometry: PixelGeometry) -> SkSurfaceProps {
            let handle = SkSurfaceProps_cloneWithPixelGeometry(self.pointer, Int32(newPixelGeometry.rawValue));
            let pointer = static_sk_surface_props_get_ptr(handle)
            return SkSurfaceProps(pointer: pointer, handle: handle)
        }

        func flags() -> UInt {
            return UInt(SkSurfaceProps_flags(self.pointer))
        }

        func pixelGeometry() -> PixelGeometry {
            return PixelGeometry(rawValue: Int32(SkSurfaceProps_pixelGeometry(self.pointer)))!
        }

        func isUseDeviceIndependentFonts() -> Bool {
            return SkSurfaceProps_isUseDeviceIndependentFonts(self.pointer)
        }

        func isAlwaysDither() -> Bool {
            return SkSurfaceProps_isAlwaysDither(self.pointer)
        }
    }
}