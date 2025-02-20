extension Skia {
    protocol SkM44Protocol {
        var pointer: SkM44MutablePointer? { get set }
        var handle: sk_m_44_t { get set }
        // deinit // void SkM44_delete(void *m44); // (SkM44 *m44)
        init(pointer: SkM44MutablePointer?, handle: sk_m_44_t)
        init(src: SkM44) // void *SkM44_new(const void *src); // (const SkM44 *src) -> SkM44 *
        init(src: SkMatrix) // void *SkM44_new_2(const void *src); // (const SkMatrix *src) -> SkM44 *
        init() // void *SkM44_new_3(); // () -> SkM44 *
        init(a: SkM44, b: SkM44) // void *SkM44_new_4(const void *a, const void *b); // (const SkM44 *a, const SkM44 *b) -> SkM44 *
        init(m0: Float, m4: Float, m8: Float, m12: Float, m1: Float, m5: Float, m9: Float, m13: Float, m2: Float, m6: Float, m10: Float, m14: Float, m3: Float, m7: Float, m11: Float, m15: Float) // void *SkM44_new_5(float m0, float m4, float m8, float m12, float m1, float m5, float m9, float m13, float m2, float m6, float m10, float m14, float m3, float m7, float m11, float m15); // (SkScalar m0, SkScalar m4, SkScalar m8, SkScalar m12, SkScalar m1, SkScalar m5, SkScalar m9, SkScalar m13, SkScalar m2, SkScalar m6, SkScalar m10, SkScalar m14, SkScalar m3, SkScalar m7, SkScalar m11, SkScalar m15) -> SkM44 *
        // Static Methods
        static func Rows(r0: SkV4, r1: SkV4, r2: SkV4, r3: SkV4) -> SkM44 // int SkM44_Rows(const void *r0, const void *r1, const void *r2, const void *r3); // (const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3) -> sk_m_44_t
        static func Cols(c0: SkV4, c1: SkV4, c2: SkV4, c3: SkV4) -> SkM44 // int SkM44_Cols(const void *c0, const void *c1, const void *c2, const void *c3); // (const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3) -> sk_m_44_t
        static func RowMajor(r: [Float]) -> SkM44 // int SkM44_RowMajor(const void * r); // (const SkScalar r[16]) -> sk_m_44_t
        static func ColMajor(c: [Float]) -> SkM44 // int SkM44_ColMajor(const void * c); // (const SkScalar c[16]) -> sk_m_44_t
        static func Translate(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_Translate(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        static func Scale(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_Scale(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        static func Rotate(axis: SkV3, radians: Float) -> SkM44 // int SkM44_Rotate(int axis, float radians); // (sk_v3_t axis, SkScalar radians) -> sk_m_44_t
        static func RectToRect(src: SkRect, dst: SkRect) -> SkM44 // int SkM44_RectToRect(const void *src, const void *dst); // (const SkRect *src, const SkRect *dst) -> sk_m_44_t
        static func LookAt(eye: SkV3, center: SkV3, up: SkV3) -> SkM44 // int SkM44_LookAt(const void *eye, const void *center, const void *up); // (const SkV3 *eye, const SkV3 *center, const SkV3 *up) -> sk_m_44_t
        static func Perspective(near: Float, far: Float, angle: Float) -> SkM44 // int SkM44_Perspective(float near, float far, float angle); // (float near, float far, float angle) -> sk_m_44_t
        // Methods
        func getColMajor(v: inout [Float]) // void SkM44_getColMajor(void *m44, void *v); // (SkM44 *m44, SkScalar v[])
        func getRowMajor(v: inout [Float]) // void SkM44_getRowMajor(void *m44, void *v); // (SkM44 *m44, SkScalar v[])
        func rc(r: Int, c: Int) -> Float // float SkM44_rc(void *m44, int r, int c); // (SkM44 *m44, int r, int c) -> SkScalar
        func setRC(r: Int, c: Int, value: Float) // void SkM44_setRC(void *m44, int r, int c, float value); // (SkM44 *m44, int r, int c, SkScalar value)
        func row(i: Int) -> SkV4 // int SkM44_row(void *m44, int i); // (SkM44 *m44, int i) -> sk_v4_t
        func col(i: Int) -> SkV4 // int SkM44_col(void *m44, int i); // (SkM44 *m44, int i) -> sk_v4_t
        func setRow(i: Int, v: SkV4) // void SkM44_setRow(void *m44, int i, const void *v); // (SkM44 *m44, int i, const SkV4 *v)
        func setCol(i: Int, v: SkV4) // void SkM44_setCol(void *m44, int i, const void *v); // (SkM44 *m44, int i, const SkV4 *v)
        func setIdentity() -> SkM44 // int SkM44_setIdentity(void *m44); // (SkM44 *m44) -> sk_m_44_t
        func setTranslate(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_setTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        func setScale(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_setScale(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        func setRotateUnitSinCos(axis: SkV3, sinAngle: Float, cosAngle: Float) -> SkM44 // int SkM44_setRotateUnitSinCos(void *m44, int axis, float sinAngle, float cosAngle); // (SkM44 *m44, sk_v3_t axis, SkScalar sinAngle, SkScalar cosAngle) -> sk_m_44_t
        func setRotateUnit(axis: SkV3, radians: Float) -> SkM44 // int SkM44_setRotateUnit(void *m44, int axis, float radians); // (SkM44 *m44, sk_v3_t axis, SkScalar radians) -> sk_m_44_t
        func setRotate(axis: SkV3, radians: Float) -> SkM44 // int SkM44_setRotate(void *m44, int axis, float radians); // (SkM44 *m44, sk_v3_t axis, SkScalar radians) -> sk_m_44_t
        func setConcat(a: SkM44, b: SkM44) -> SkM44 // int SkM44_setConcat(void *m44, const void *a, const void *b); // (SkM44 *m44, const SkM44 *a, const SkM44 *b) -> sk_m_44_t
        func preConcat(m: SkM44) -> SkM44 // int SkM44_preConcat(void *m44, const void *m); // (SkM44 *m44, const SkM44 *m) -> sk_m_44_t
        func preConcat(matrix: SkMatrix) -> SkM44 // int SkM44_preConcat_2(void *m44, const void *matrix); // (SkM44 *m44, const SkMatrix *matrix) -> sk_m_44_t
        func postConcat(m: SkM44) -> SkM44 // int SkM44_postConcat(void *m44, const void *m); // (SkM44 *m44, const SkM44 *m) -> sk_m_44_t
        func normalizePerspective() // void SkM44_normalizePerspective(void *m44); // (SkM44 *m44)
        func isFinite() -> Bool // bool SkM44_isFinite(void *m44); // (SkM44 *m44) -> bool
        func invert(inverse: SkM44) -> Bool // bool SkM44_invert(void *m44, void *inverse); // (SkM44 *m44, SkM44 *inverse) -> bool
        func transpose() -> SkM44 // int SkM44_transpose(void *m44); // (SkM44 *m44) -> sk_m_44_t
        func dump() // void SkM44_dump(void *m44); // (SkM44 *m44)
        func map(x: Float, y: Float, z: Float, w: Float) -> SkV4 // int SkM44_map(void *m44, float x, float y, float z, float w); // (SkM44 *m44, float x, float y, float z, float w) -> sk_v4_t
        func asM33() -> SkMatrix // int SkM44_asM33(void *m44); // (SkM44 *m44) -> sk_matrix_t
        func preTranslate(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_preTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        func postTranslate(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_postTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
        func preScale(x: Float, y: Float) -> SkM44 // int SkM44_preScale(void *m44, float x, float y); // (SkM44 *m44, SkScalar x, SkScalar y) -> sk_m_44_t
        func preScale(x: Float, y: Float, z: Float) -> SkM44 // int SkM44_preScale_2(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
    }

    class SkM44 : SkM44Protocol {
        public var pointer: SkM44MutablePointer?
        public var handle: sk_m_44_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_m_44_delete(self.handle)
            } else {
                SkM44_delete(self.pointer)
            }
        }

        required init(pointer: SkM44MutablePointer?, handle: sk_m_44_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init(src: SkM44) {
            self.pointer = SkM44_new(src.pointer)
            self.handle = -1
        }

        required init(src: SkMatrix) {
            self.pointer = SkM44_new_2(src.pointer)
            self.handle = -1
        }

        required init() {
            self.pointer = SkM44_new_3()
            self.handle = -1
        }

        required init(a: SkM44, b: SkM44) {
            self.pointer = SkM44_new_4(a.pointer, b.pointer)
            self.handle = -1
        }

        required init(m0: Float, m4: Float, m8: Float, m12: Float, m1: Float, m5: Float, m9: Float, m13: Float, m2: Float, m6: Float, m10: Float, m14: Float, m3: Float, m7: Float, m11: Float, m15: Float) {
            self.pointer = SkM44_new_5(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15)
            self.handle = -1
        }

        // Methods

        static func Rows(r0: SkV4, r1: SkV4, r2: SkV4, r3: SkV4) -> SkM44 {
            let handle = SkM44_Rows(r0.pointer, r1.pointer, r2.pointer, r3.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func Cols(c0: SkV4, c1: SkV4, c2: SkV4, c3: SkV4) -> SkM44 {
            let handle = SkM44_Cols(c0.pointer, c1.pointer, c2.pointer, c3.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func RowMajor(r: [Float]) -> SkM44 {
            let handle = SkM44_RowMajor(r)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func ColMajor(c: [Float]) -> SkM44 {
            let handle = SkM44_ColMajor(c)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func Translate(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_Translate(x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func Scale(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_Scale(x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func Rotate(axis: SkV3, radians: Float) -> SkM44 {
            let handle = SkM44_Rotate(axis.handle, radians)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func RectToRect(src: SkRect, dst: SkRect) -> SkM44 {
            let handle = SkM44_RectToRect(src.pointer, dst.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func LookAt(eye: SkV3, center: SkV3, up: SkV3) -> SkM44 {
            let handle = SkM44_LookAt(eye.pointer, center.pointer, up.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        static func Perspective(near: Float, far: Float, angle: Float) -> SkM44 {
            let handle = SkM44_Perspective(near, far, angle)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        // Methods

        func getColMajor(v: inout [Float]) {
            v.withUnsafeMutableBufferPointer { (buffer: inout UnsafeMutableBufferPointer<Float>) -> Void in
                SkM44_getColMajor(self.pointer, buffer.baseAddress)
            }
        }

        func getRowMajor(v: inout [Float]) {
            v.withUnsafeMutableBufferPointer { (buffer: inout UnsafeMutableBufferPointer<Float>) -> Void in
                SkM44_getRowMajor(self.pointer, buffer.baseAddress)
            }
        }

        func rc(r: Int, c: Int) -> Float {
            return SkM44_rc(self.pointer, Int32(r), Int32(c))
        }

        func setRC(r: Int, c: Int, value: Float) {
            SkM44_setRC(self.pointer, Int32(r), Int32(c), value)
        }

        func row(i: Int) -> SkV4 {
            let handle = SkM44_row(self.pointer, Int32(i))
            let pointer = static_sk_v4_get_ptr(handle)
            return SkV4(pointer: pointer, handle: handle)
        }

        func col(i: Int) -> SkV4 {
            let handle = SkM44_col(self.pointer, Int32(i))
            let pointer = static_sk_v4_get_ptr(handle)
            return SkV4(pointer: pointer, handle: handle)
        }

        func setRow(i: Int, v: SkV4) {
            SkM44_setRow(self.pointer, Int32(i), v.pointer)
        }

        func setCol(i: Int, v: SkV4) {
            SkM44_setCol(self.pointer, Int32(i), v.pointer)
        }

        func setIdentity() -> SkM44 {
            let handle = SkM44_setIdentity(self.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setTranslate(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_setTranslate(self.pointer, x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setScale(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_setScale(self.pointer, x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setRotateUnitSinCos(axis: SkV3, sinAngle: Float, cosAngle: Float) -> SkM44 {
            let handle = SkM44_setRotateUnitSinCos(self.pointer, axis.handle, sinAngle, cosAngle)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setRotateUnit(axis: SkV3, radians: Float) -> SkM44 {
            let handle = SkM44_setRotateUnit(self.pointer, axis.handle, radians)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setRotate(axis: SkV3, radians: Float) -> SkM44 {
            let handle = SkM44_setRotate(self.pointer, axis.handle, radians)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func setConcat(a: SkM44, b: SkM44) -> SkM44 {
            let handle = SkM44_setConcat(self.pointer, a.pointer, b.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func preConcat(m: SkM44) -> SkM44 {
            let handle = SkM44_preConcat(self.pointer, m.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func preConcat(matrix: SkMatrix) -> SkM44 {
            let handle = SkM44_preConcat_2(self.pointer, matrix.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func postConcat(m: SkM44) -> SkM44 {
            let handle = SkM44_postConcat(self.pointer, m.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func normalizePerspective() {
            SkM44_normalizePerspective(self.pointer)
        }

        func isFinite() -> Bool {
            return SkM44_isFinite(self.pointer)
        }

        func invert(inverse: SkM44) -> Bool {
            return SkM44_invert(self.pointer, inverse.pointer)
        }

        func transpose() -> SkM44 {
            let handle = SkM44_transpose(self.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func dump() {
            SkM44_dump(self.pointer)
        }

        func map(x: Float, y: Float, z: Float, w: Float) -> SkV4 {
            let handle = SkM44_map(self.pointer, x, y, z, w)
            let pointer = static_sk_v4_get_ptr(handle)
            return SkV4(pointer: pointer, handle: handle)
        }

        func asM33() -> SkMatrix {
            let handle = SkM44_asM33(self.pointer)
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preTranslate(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_preTranslate(self.pointer, x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func postTranslate(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_postTranslate(self.pointer, x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func preScale(x: Float, y: Float) -> SkM44 {
            let handle = SkM44_preScale(self.pointer, x, y)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }

        func preScale(x: Float, y: Float, z: Float) -> SkM44 {
            let handle = SkM44_preScale_2(self.pointer, x, y, z)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }
    }
}