extension Skia {
    protocol SkRSXformProtocol {
        var pointer: SkRSXformMutablePointer? { get set }
        var handle: sk_rsx_form_t { get set }
        // deinit // void SkRSXform_delete(void *rsx_form); // (SkRSXform *rsx_form)
        init(pointer: SkRSXformMutablePointer?, handle: sk_rsx_form_t)
        // Static Methods
        static func Make(scos: Float, ssin: Float, tx: Float, ty: Float) -> SkRSXform // int SkRSXform_Make(float scos, float ssin, float tx, float ty); // (SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) -> sk_rsx_form_t
        static func MakeFromRadians(scale: Float, radians: Float, tx: Float, ty: Float, ax: Float, ay: Float) -> SkRSXform // int SkRSXform_MakeFromRadians(float scale, float radians, float tx, float ty, float ax, float ay); // (SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) -> sk_rsx_form_t
        // Methods
        func rectStaysRect() -> Bool // bool SkRSXform_rectStaysRect(void *rsx_form); // (SkRSXform *rsx_form) -> bool
        func setIdentity() // void SkRSXform_setIdentity(void *rsx_form); // (SkRSXform *rsx_form)
        func set(scos: Float, ssin: Float, tx: Float, ty: Float) // void SkRSXform_set(void *rsx_form, float scos, float ssin, float tx, float ty); // (SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
        func toQuad(width: Float, height: Float, quad: inout [SkPoint]) // void SkRSXform_toQuad(void *rsx_form, float width, float height, void * quad); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4])
        func toQuad(size: SkSize, quad: inout [SkPoint]) // void SkRSXform_toQuad_2(void *rsx_form, const void *size, void * quad); // (SkRSXform *rsx_form, const SkSize *size, SkPoint quad[4])
        func toTriStrip(width: Float, height: Float, strip: inout [SkPoint]) // void SkRSXform_toTriStrip(void *rsx_form, float width, float height, void * strip); // (SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4])
    }

    class SkRSXform : SkRSXformProtocol {
        public var pointer: SkRSXformMutablePointer?
        public var handle: sk_rsx_form_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_rsx_form_delete(self.handle)
            } else {
                SkRSXform_delete(self.pointer)
            }
        }

        required init(pointer: SkRSXformMutablePointer?, handle: sk_rsx_form_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Make(scos: Float, ssin: Float, tx: Float, ty: Float) -> SkRSXform {
            let handle = SkRSXform_Make(scos, ssin, tx, ty);
            let pointer = static_sk_rsx_form_get_ptr(handle)
            return SkRSXform(pointer: pointer, handle: handle)
        }

        static func MakeFromRadians(scale: Float, radians: Float, tx: Float, ty: Float, ax: Float, ay: Float) -> SkRSXform {
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

        func set(scos: Float, ssin: Float, tx: Float, ty: Float) {
            SkRSXform_set(self.pointer, scos, ssin, tx, ty)
        }

        func toQuad(width: Float, height: Float, quad: inout [SkPoint]) {
            quad.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toQuad(self.pointer, width, height, bufferPointer.baseAddress)
            }
        }

        func toQuad(size: SkSize, quad: inout [SkPoint]) {
            quad.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toQuad_2(self.pointer, size.pointer, bufferPointer.baseAddress)
            }
        }

        func toTriStrip(width: Float, height: Float, strip: inout [SkPoint]) {
            strip.withUnsafeMutableBufferPointer { bufferPointer in
                SkRSXform_toTriStrip(self.pointer, width, height, bufferPointer.baseAddress)
            }
        }
    }
}