extension Skia {
    class RSXform {
        public var pointer: Skia.RSXformMutablePointer?
        public var handle: sk_rsx_form_t?

        // void SkRSXform_delete(void *rsx_form); // (SkRSXform *rsx_form)
        deinit {
            SkRSXform_delete(self.pointer)
            if let handle = self.handle {
                static_sk_rsx_form_delete(handle)
            }
        }
        // bool SkRSXform_rectStaysRect(void *rsx_form); // (SkRSXform *rsx_form) -> bool
        func rectStaysRect() -> Bool {
            return SkRSXform_rectStaysRect(self.pointer)
        }
        // void SkRSXform_setIdentity(void *rsx_form); // (SkRSXform *rsx_form)
        func setIdentity() {
            SkRSXform_setIdentity(self.pointer)
        }
        // void SkRSXform_set(void *rsx_form, float scos, float ssin, float tx, float ty); // (SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
        func set(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) {
            SkRSXform_set(self.pointer, scos, ssin, tx, ty)
        }
        // void SkRSXform_toQuad(void *rsx_form, float width, float height, void * quad); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4])
        func toQuad(width: Scalar, height: Scalar, quad: UnsafeMutablePointer<Point>?) {
            SkRSXform_toQuad(self.pointer, width, height, quad)
        }
        // void SkRSXform_toQuad_2(void *rsx_form, const void *size, void * quad); // (SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4])
        func toQuad(size: Size, quad: UnsafeMutablePointer<Point>?) {
            SkRSXform_toQuad_2(self.pointer, size.pointer, quad)
        }
        // void SkRSXform_toTriStrip(void *rsx_form, float width, float height, void * strip); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4])
        func toTriStrip(width: Scalar, height: Scalar, strip: UnsafeMutablePointer<Point>?) {
            SkRSXform_toTriStrip(self.pointer, width, height, strip)
        }

        // // static

        init(pointer: Skia.RSXformMutablePointer?, handle: sk_rsx_form_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkRSXform_Make(float scos, float ssin, float tx, float ty); // (SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) -> sk_rsx_form_t
        static func Make(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) -> RSXform {
            let handle = SkRSXform_Make(scos, ssin, tx, ty);
            let pointer = static_sk_rsx_form_get_ptr(handle)
            return RSXform(pointer: pointer, handle: handle)
        }
        // int SkRSXform_MakeFromRadians(float scale, float radians, float tx, float ty, float ax, float ay); // (SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) -> sk_rsx_form_t
        static func MakeFromRadians(scale: Scalar, radians: Scalar, tx: Scalar, ty: Scalar, ax: Scalar, ay: Scalar) -> RSXform {
            let handle = SkRSXform_MakeFromRadians(scale, radians, tx, ty, ax, ay);
            let pointer = static_sk_rsx_form_get_ptr(handle)
            return RSXform(pointer: pointer, handle: handle)
        }

    }
}