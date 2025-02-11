extension Skia {
    protocol SkColorMatrixProtocol {
        var pointer: SkColorMatrixMutablePointer? { get set }
        var handle: sk_color_matrix_t { get set }
        // deinit // void SkColorMatrix_delete(void *color_matrix); // (SkColorMatrix *color_matrix)
        init(pointer: SkColorMatrixMutablePointer?, handle: sk_color_matrix_t)
        init() // void *SkColorMatrix_new(); // () -> SkColorMatrix *
        init(m00: Float, m01: Float, m02: Float, m03: Float, m04: Float, m10: Float, m11: Float, m12: Float, m13: Float, m14: Float, m20: Float, m21: Float, m22: Float, m23: Float, m24: Float, m30: Float, m31: Float, m32: Float, m33: Float, m34: Float) // void *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34); // (float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34) -> SkColorMatrix *
        // Static Methods
        static func RGBtoYUV(colorSpace: Int) -> SkColorMatrix // int SkColorMatrix_RGBtoYUV(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t
        static func YUVtoRGB(colorSpace: Int) -> SkColorMatrix // int SkColorMatrix_YUVtoRGB(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t
        // Methods
        func setIdentity() // void SkColorMatrix_setIdentity(void *color_matrix); // (SkColorMatrix *color_matrix)
        func setScale(rScale: Float, gScale: Float, bScale: Float, aScale: Float) // void SkColorMatrix_setScale(void *color_matrix, float rScale, float gScale, float bScale, float aScale); // (SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale)
        func postTranslate(dr: Float, dg: Float, db: Float, da: Float) // void SkColorMatrix_postTranslate(void *color_matrix, float dr, float dg, float db, float da); // (SkColorMatrix *color_matrix, float dr, float dg, float db, float da)
        func setConcat(a: SkColorMatrixConstPointer?, b: SkColorMatrixConstPointer?) // void SkColorMatrix_setConcat(void *color_matrix, const void *a, const void *b); // (SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b)
        func preConcat(mat: SkColorMatrixConstPointer?) // void SkColorMatrix_preConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
        func postConcat(mat: SkColorMatrixConstPointer?) // void SkColorMatrix_postConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
        func setSaturation(sat: Float) // void SkColorMatrix_setSaturation(void *color_matrix, float sat); // (SkColorMatrix *color_matrix, float sat)
        func setRowMajor(src: [Float]) // void SkColorMatrix_setRowMajor(void *color_matrix, const float src[20]); // (SkColorMatrix *color_matrix, const float src[20])
        func getRowMajor(dst: inout [Float]) // void SkColorMatrix_getRowMajor(void *color_matrix, float dst[20]); // (SkColorMatrix *color_matrix, float dst[20])
    }

    class SkColorMatrix : SkColorMatrixProtocol {
        public var pointer: SkColorMatrixMutablePointer?
        public var handle: sk_color_matrix_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_color_matrix_delete(self.handle)
            } else {
                SkColorMatrix_delete(self.pointer)
            }
        }

        required init(pointer: SkColorMatrixMutablePointer?, handle: sk_color_matrix_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkColorMatrix_new()
        }
        
        required init(m00: Float, m01: Float, m02: Float, m03: Float, m04: Float, m10: Float, m11: Float, m12: Float, m13: Float, m14: Float, m20: Float, m21: Float, m22: Float, m23: Float, m24: Float, m30: Float, m31: Float, m32: Float, m33: Float, m34: Float) {
            self.pointer = SkColorMatrix_new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)            
            self.handle = -1
        }

        // Static Methods

        static func RGBtoYUV(colorSpace: Int) -> SkColorMatrix {
            let handle = SkColorMatrix_RGBtoYUV(Int32(colorSpace))
            let pointer = static_sk_color_matrix_get_ptr(handle)
            return SkColorMatrix(pointer: pointer, handle: handle)
        }

        static func YUVtoRGB(colorSpace: Int) -> SkColorMatrix {
            let handle = SkColorMatrix_YUVtoRGB(Int32(colorSpace))
            let pointer = static_sk_color_matrix_get_ptr(handle)
            return SkColorMatrix(pointer: pointer, handle: handle)
        }

        // Methods

        func setIdentity() {
            SkColorMatrix_setIdentity(self.pointer)
        }

        func setScale(rScale: Float, gScale: Float, bScale: Float, aScale: Float) {
            SkColorMatrix_setScale(self.pointer, rScale, gScale, bScale, aScale)
        }

        func postTranslate(dr: Float, dg: Float, db: Float, da: Float) {
            SkColorMatrix_postTranslate(self.pointer, dr, dg, db, da)
        }

        func setConcat(a: SkColorMatrixConstPointer?, b: SkColorMatrixConstPointer?) {
            SkColorMatrix_setConcat(self.pointer, a, b)
        }

        func preConcat(mat: SkColorMatrixConstPointer?) {
            SkColorMatrix_preConcat(self.pointer, mat)
        }

        func postConcat(mat: SkColorMatrixConstPointer?) {
            SkColorMatrix_postConcat(self.pointer, mat)
        }

        func setSaturation(sat: Float) {
            SkColorMatrix_setSaturation(self.pointer, sat)
        }

        func setRowMajor(src: [Float]) {
            src.withUnsafeBufferPointer { bufferPointer in
                let rawPointer = UnsafeRawPointer(bufferPointer.baseAddress)
                SkColorMatrix_setRowMajor(self.pointer, rawPointer)
            }
        }

        func getRowMajor(dst: inout [Float]) {
            dst.withUnsafeMutableBufferPointer { bufferPointer in
                let rawPointer = UnsafeMutableRawPointer(bufferPointer.baseAddress)
                SkColorMatrix_getRowMajor(self.pointer, rawPointer)
            }
        }
    }
}