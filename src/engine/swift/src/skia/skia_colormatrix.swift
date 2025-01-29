extension Skia {
    class ColorMatrix {
        private var pointer: ColorMatrixMutablePointer?

        init() {
            self.pointer = SkColorMatrix_new()
        }
        
        init(m00: Float, m01: Float, m02: Float, m03: Float, m04: Float, m10: Float, m11: Float, m12: Float, m13: Float, m14: Float, m20: Float, m21: Float, m22: Float, m23: Float, m24: Float, m30: Float, m31: Float, m32: Float, m33: Float, m34: Float) {
            self.pointer = SkColorMatrix_new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)
        }

        deinit {
            SkColorMatrix_delete(self.pointer)
        }

        // void SkColorMatrix_setIdentity(void *color_matrix); // (SkColorMatrix *color_matrix)
        func setIdentity() {
            SkColorMatrix_setIdentity(self.pointer)
        }
        // void SkColorMatrix_setScale(void *color_matrix, float rScale, float gScale, float bScale, float aScale); // (SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale)
        func setScale(rScale: Float, gScale: Float, bScale: Float, aScale: Float) {
            SkColorMatrix_setScale(self.pointer, rScale, gScale, bScale, aScale)
        }
        // void SkColorMatrix_postTranslate(void *color_matrix, float dr, float dg, float db, float da); // (SkColorMatrix *color_matrix, float dr, float dg, float db, float da)
        func postTranslate(dr: Float, dg: Float, db: Float, da: Float) {
            SkColorMatrix_postTranslate(self.pointer, dr, dg, db, da)
        }
        // void SkColorMatrix_setConcat(void *color_matrix, const void *a, const void *b); // (SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b)
        func setConcat(a: Skia.ColorMatrixConstPointer?, b: Skia.ColorMatrixConstPointer?) {
            SkColorMatrix_setConcat(self.pointer, a, b)
        }
        // void SkColorMatrix_preConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
        func preConcat(mat: Skia.ColorMatrixConstPointer?) {
            SkColorMatrix_preConcat(self.pointer, mat)
        }
        // void SkColorMatrix_postConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
        func postConcat(mat: Skia.ColorMatrixConstPointer?) {
            SkColorMatrix_postConcat(self.pointer, mat)
        }
        // void SkColorMatrix_setSaturation(void *color_matrix, float sat); // (SkColorMatrix *color_matrix, float sat)
        func setSaturation(sat: Float) {
            SkColorMatrix_setSaturation(self.pointer, sat)
        }
        // void SkColorMatrix_setRowMajor(void *color_matrix, const void * src); // (SkColorMatrix *color_matrix, const float src[20])
        func setRowMajor(src: [Float]) {
            src.withUnsafeBufferPointer { bufferPointer in
                let rawPointer = UnsafeRawPointer(bufferPointer.baseAddress)
                SkColorMatrix_setRowMajor(self.pointer, rawPointer)
            }
        }
        // void SkColorMatrix_getRowMajor(void *color_matrix, void * dst); // (SkColorMatrix *color_matrix, float dst[20])
        func getRowMajor(dst: inout [Float]) {
            dst.withUnsafeMutableBufferPointer { bufferPointer in
                let rawPointer = UnsafeMutableRawPointer(bufferPointer.baseAddress)
                SkColorMatrix_getRowMajor(self.pointer, rawPointer)
            }
        }
        
        // static

        //int SkColorMatrix_RGBtoYUV(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t
        static func RGBtoYUV(colorSpace: Int) -> Skia.ColorMatrixType {
            let handle = SkColorMatrix_RGBtoYUV(Int32(colorSpace))
            return Skia.ColorMatrixType(handle: handle)
        }
        // int SkColorMatrix_YUVtoRGB(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t
        static func YUVtoRGB(colorSpace: Int) -> Skia.ColorMatrixType {
            let handle = SkColorMatrix_YUVtoRGB(Int32(colorSpace))
            return Skia.ColorMatrixType(handle: handle)
        }
    }
}