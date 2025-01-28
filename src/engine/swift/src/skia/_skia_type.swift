extension Skia {
    public final class ColorMatrixType {
        public let handle: sk_color_matrix_t

        public init(handle: sk_color_matrix_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_matrix_delete(handle)
        }
    }

    public final class ColorSpaceType {
        public let handle: sk_color_space_t

        public init(handle: sk_color_space_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_space_delete(handle)
        }
    }
}