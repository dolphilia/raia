extension Skia {
    protocol SkRSXformProtocol {
        var pointer: Skia.SkRSXformMutablePointer? { get set }
        var handle: sk_rsx_form_t { get set }
        // deinit // void SkRSXform_delete(void *rsx_form); // (SkRSXform *rsx_form)
        init(pointer: Skia.SkRSXformMutablePointer?, handle: sk_rsx_form_t)
        // Static Methods
        static func Make(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) -> SkRSXform // int SkRSXform_Make(float scos, float ssin, float tx, float ty); // (SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) -> sk_rsx_form_t
        static func MakeFromRadians(scale: Scalar, radians: Scalar, tx: Scalar, ty: Scalar, ax: Scalar, ay: Scalar) -> SkRSXform // int SkRSXform_MakeFromRadians(float scale, float radians, float tx, float ty, float ax, float ay); // (SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) -> sk_rsx_form_t
        // Methods
        func rectStaysRect() -> Bool // bool SkRSXform_rectStaysRect(void *rsx_form); // (SkRSXform *rsx_form) -> bool
        func setIdentity() // void SkRSXform_setIdentity(void *rsx_form); // (SkRSXform *rsx_form)
        func set(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) // void SkRSXform_set(void *rsx_form, float scos, float ssin, float tx, float ty); // (SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
        func toQuad(width: Scalar, height: Scalar, quad: inout [Point]) // void SkRSXform_toQuad(void *rsx_form, float width, float height, void * quad); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4])
        func toQuad(size: SkSize, quad: inout [Point]) // void SkRSXform_toQuad_2(void *rsx_form, const void *size, void * quad); // (SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4])
        func toTriStrip(width: Scalar, height: Scalar, strip: inout [Point]) // void SkRSXform_toTriStrip(void *rsx_form, float width, float height, void * strip); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4])
    }

    class SkRSXform : SkRSXformProtocol {
        public var pointer: Skia.SkRSXformMutablePointer?
        public var handle: sk_rsx_form_t = -1

        deinit {
            SkRSXform_delete(self.pointer)
            if self.handle > -1 {
                static_sk_rsx_form_delete(self.handle)
            }
        }

        required init(pointer: Skia.SkRSXformMutablePointer?, handle: sk_rsx_form_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) -> SkRSXform {
            let handle = SkRSXform_Make(scos, ssin, tx, ty);
            let pointer = static_sk_rsx_form_get_ptr(handle)
            return SkRSXform(pointer: pointer, handle: handle)
        }

        static func MakeFromRadians(scale: Scalar, radians: Scalar, tx: Scalar, ty: Scalar, ax: Scalar, ay: Scalar) -> SkRSXform {
            let handle = SkRSXform_MakeFromRadians(scale, radians, tx, ty, ax, ay);
            let pointer = static_sk_rsx_form_get_ptr(handle)
            return SkRSXform(pointer: pointer, handle: handle)
        }

        // Methods

        func rectStaysRect() -> Bool {
            return SkRSXform_rectStaysRect(self.pointer)
        }

        func setIdentity() {
            SkRSXform_setIdentity(self.pointer)
        }

        func set(scos: Scalar, ssin: Scalar, tx: Scalar, ty: Scalar) {
            SkRSXform_set(self.pointer, scos, ssin, tx, ty)
        }

        func toQuad(width: Scalar, height: Scalar, quad: inout [Point]) {
            quad.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toQuad(self.pointer, width, height, bufferPointer.baseAddress)
            }
        }

        func toQuad(size: SkSize, quad: inout [Point]) {
            quad.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toQuad_2(self.pointer, size.pointer, bufferPointer.baseAddress)
            }
        }

        func toTriStrip(width: Scalar, height: Scalar, strip: inout [Point]) {
            strip.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toTriStrip(self.pointer, width, height, bufferPointer.baseAddress)
            }
        }
    }
}