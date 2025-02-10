extension Skia {
    class Matrix {
        enum ScaleToFit: Int32 {
            case fill
            case start
            case center
            case end
        }

        enum TypeMask: Int32 {
            case identity = 0
            case translate = 0x01
            case scale = 0x02
            case affine = 0x04
            case perspective = 0x08
        }

        public var pointer: Skia.MatrixMutablePointer?
        public var handle: sk_matrix_t = -1
        
        // void *SkMatrix_new(void *matrix); // (SkMatrix *matrix) -> SkMatrix *
        init(matrix: Matrix) {
            self.pointer = SkMatrix_new(matrix.pointer)
            self.handle = -1
        }
        // void SkMatrix_delete(void *matrix); // (SkMatrix *matrix)
        deinit {
            if self.handle > -1 {
                static_sk_matrix_delete(self.handle)
            } else {
                SkMatrix_delete(self.pointer)
            }
        }
        // int SkMatrix_getType(void *matrix); // (SkMatrix *matrix) -> SkMatrix::TypeMask
        func getType() -> TypeMask {
            return TypeMask(rawValue: SkMatrix_getType(self.pointer))!
        }

        // bool SkMatrix_isIdentity(void *matrix); // (SkMatrix *matrix) -> bool
        func isIdentity() -> Bool {
            return SkMatrix_isIdentity(self.pointer)
        }
        // bool SkMatrix_isScaleTranslate(void *matrix); // (SkMatrix *matrix) -> bool
        func isScaleTranslate() -> Bool {
            return SkMatrix_isScaleTranslate(self.pointer)
        }
        // bool SkMatrix_isTranslate(void *matrix); // (SkMatrix *matrix) -> bool
        func isTranslate() -> Bool {
            return SkMatrix_isTranslate(self.pointer)
        }
        // bool SkMatrix_rectStaysRect(void *matrix); // (SkMatrix *matrix) -> bool
        func rectStaysRect() -> Bool {
            return SkMatrix_rectStaysRect(self.pointer)
        }
        // bool SkMatrix_preservesAxisAlignment(void *matrix); // (SkMatrix *matrix) -> bool
        func preservesAxisAlignment() -> Bool {
            return SkMatrix_preservesAxisAlignment(self.pointer)
        }
        // bool SkMatrix_hasPerspective(void *matrix); // (SkMatrix *matrix) -> bool
        func hasPerspective() -> Bool {
            return SkMatrix_hasPerspective(self.pointer)
        }
        // bool SkMatrix_isSimilarity(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
        func isSimilarity(tol: Scalar) -> Bool {
            return SkMatrix_isSimilarity(self.pointer, tol)
        }
        // bool SkMatrix_preservesRightAngles(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
        func preservesRightAngles(tol: Scalar) -> Bool {
            return SkMatrix_preservesRightAngles(self.pointer, tol)
        }
        // float SkMatrix_get(void *matrix, int index); // (SkMatrix *matrix, int index) -> SkScalar
        func get(index: Int) -> Scalar {
            return SkMatrix_get(self.pointer, Int32(index))
        }
        // float SkMatrix_rc(void *matrix, int r, int c); // (SkMatrix *matrix, int r, int c) -> SkScalar
        func rc(r: Int, c: Int) -> Scalar {
            return SkMatrix_rc(self.pointer, Int32(r), Int32(c))
        }
        // float SkMatrix_getScaleX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getScaleX() -> Scalar {
            return SkMatrix_getScaleX(self.pointer)
        }
        // float SkMatrix_getScaleY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getScaleY() -> Scalar {
            return SkMatrix_getScaleY(self.pointer)
        }
        // float SkMatrix_getSkewY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getSkewY() -> Scalar {
            return SkMatrix_getSkewY(self.pointer)
        }
        // float SkMatrix_getSkewX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getSkewX() -> Scalar {
            return SkMatrix_getSkewX(self.pointer)
        }
        // float SkMatrix_getTranslateX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getTranslateX() -> Scalar {
            return SkMatrix_getTranslateX(self.pointer)
        }
        // float SkMatrix_getTranslateY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getTranslateY() -> Scalar {
            return SkMatrix_getTranslateY(self.pointer)
        }
        // float SkMatrix_getPerspX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getPerspX() -> Scalar {
            return SkMatrix_getPerspX(self.pointer)
        }
        // float SkMatrix_getPerspY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getPerspY() -> Scalar {
            return SkMatrix_getPerspY(self.pointer)
        }
        // int SkMatrix_set(void *matrix, int index, float value); // (SkMatrix *matrix, int index, SkScalar value) -> sk_matrix_t
        func set(index: Int, value: Scalar) -> Matrix {
            let handle = SkMatrix_set(self.pointer, Int32(index), value);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setScaleX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setScaleX(v: Scalar) -> Matrix {
            let handle = SkMatrix_setScaleX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setScaleY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setScaleY(v: Scalar) -> Matrix {
            let handle = SkMatrix_setScaleY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setSkewY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setSkewY(v: Scalar) -> Matrix {
            let handle = SkMatrix_setSkewY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setSkewX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setSkewX(v: Scalar) -> Matrix {
            let handle = SkMatrix_setSkewX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setTranslateX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setTranslateX(v: Scalar) -> Matrix {
            let handle = SkMatrix_setTranslateX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setTranslateY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setTranslateY(v: Scalar) -> Matrix {
            let handle = SkMatrix_setTranslateY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setPerspX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setPerspX(v: Scalar) -> Matrix {
            let handle = SkMatrix_setPerspX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setPerspY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setPerspY(v: Scalar) -> Matrix {
            let handle = SkMatrix_setPerspY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setAll(void *matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2); // (SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) -> sk_matrix_t
        func setAll(scaleX: Scalar, skewX: Scalar, transX: Scalar, skewY: Scalar, scaleY: Scalar, transY: Scalar, persp0: Scalar, persp1: Scalar, persp2: Scalar) -> Matrix {
            let handle = SkMatrix_setAll(self.pointer, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // void SkMatrix_get9(void *matrix, void * buffer); // (SkMatrix *matrix, SkScalar buffer[9])
        func get9(buffer: [Scalar]) {
            SkMatrix_get9(self.pointer, UnsafeMutablePointer(mutating: buffer))
        }
        // int SkMatrix_set9(void *matrix, const void * buffer); // (SkMatrix *matrix, const SkScalar buffer[9]) -> sk_matrix_t
        func set9(buffer: [Scalar]) -> Matrix {
            let handle = SkMatrix_set9(self.pointer, buffer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_reset(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
        func reset() -> Matrix {
            let handle = SkMatrix_reset(self.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setIdentity(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
        func setIdentity() -> Matrix {
            let handle = SkMatrix_setIdentity(self.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func setTranslate(dx: Scalar, dy: Scalar) -> Matrix {
            let handle = SkMatrix_setTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setTranslate_2(void *matrix, const void *v); // (SkMatrix *matrix, const SkVector *v) -> sk_matrix_t
        func setTranslate(v: Vector) -> Matrix {
            let handle = SkMatrix_setTranslate_2(self.pointer, v.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func setScale(sx: Scalar, sy: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_setScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func setScale(sx: Scalar, sy: Scalar) -> Matrix {
            let handle = SkMatrix_setScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func setRotate(degrees: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_setRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func setRotate(degrees: Scalar) -> Matrix {
            let handle = SkMatrix_setRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setSinCos(void *matrix, float sinValue, float cosValue, float px, float py); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) -> sk_matrix_t
        func setSinCos(sinValue: Scalar, cosValue: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_setSinCos(self.pointer, sinValue, cosValue, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setSinCos_2(void *matrix, float sinValue, float cosValue); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) -> sk_matrix_t
        func setSinCos(sinValue: Scalar, cosValue: Scalar) -> Matrix {
            let handle = SkMatrix_setSinCos_2(self.pointer, sinValue, cosValue);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setRSXform(void *matrix, const void *rsxForm); // (SkMatrix *matrix, const SkRSXform *rsxForm) -> sk_matrix_t
        func setRSXform(rsxForm: SkRSXform) -> Matrix {
            let handle = SkMatrix_setRSXform(self.pointer, rsxForm.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        
        // int SkMatrix_setSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func setSkew(kx: Scalar, ky: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_setSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func setSkew(kx: Scalar, ky: Scalar) -> Matrix {
            let handle = SkMatrix_setSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_setConcat(void *matrix, const void *a, const void *b); // (SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t
        func setConcat(a: Matrix, b: Matrix) -> Matrix {
            let handle = SkMatrix_setConcat(self.pointer, a.pointer, b.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func preTranslate(dx: Scalar, dy: Scalar) -> Matrix {
            let handle = SkMatrix_preTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func preScale(sx: Scalar, sy: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_preScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func preScale(sx: Scalar, sy: Scalar) -> Matrix {
            let handle = SkMatrix_preScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func preRotate(degrees: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_preRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func preRotate(degrees: Scalar) -> Matrix {
            let handle = SkMatrix_preRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func preSkew(kx: Scalar, ky: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_preSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func preSkew(kx: Scalar, ky: Scalar) -> Matrix {
            let handle = SkMatrix_preSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_preConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
        func preConcat(other: Matrix) -> Matrix {
            let handle = SkMatrix_preConcat(self.pointer, other.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func postTranslate(dx: Scalar, dy: Scalar) -> Matrix {
            let handle = SkMatrix_postTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func postScale(sx: Scalar, sy: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_postScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func postScale(sx: Scalar, sy: Scalar) -> Matrix {
            let handle = SkMatrix_postScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func postRotate(degrees: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_postRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func postRotate(degrees: Scalar) -> Matrix {
            let handle = SkMatrix_postRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func postSkew(kx: Scalar, ky: Scalar, px: Scalar, py: Scalar) -> Matrix {
            let handle = SkMatrix_postSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func postSkew(kx: Scalar, ky: Scalar) -> Matrix {
            let handle = SkMatrix_postSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_postConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
        func postConcat(other: Matrix) -> Matrix {
            let handle = SkMatrix_postConcat(self.pointer, other.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // bool SkMatrix_setRectToRect(void *matrix, const void * src, const void * dst, int stf); // (SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> bool
        func setRectToRect(src: SkRect, dst: SkRect, stf: ScaleToFit) -> Bool {
            return SkMatrix_setRectToRect(self.pointer, src.pointer, dst.pointer, stf.rawValue)
        }
        // bool SkMatrix_setPolyToPoly(void *matrix, const void * src, const void * dst, int count); // (SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count) -> bool
        func setPolyToPoly(src: [Point], dst: [Point], count: Int) -> Bool {
            return SkMatrix_setPolyToPoly(self.pointer, UnsafeRawPointer(src), UnsafeRawPointer(dst), Int32(count))
        }
        // bool SkMatrix_invert(void *matrix, void * inverse); // (SkMatrix *matrix, SkMatrix *inverse) -> bool
        func invert(inverse: Matrix) -> Bool {
            return SkMatrix_invert(self.pointer, inverse.pointer)
        }
        // bool SkMatrix_asAffine(void *matrix, void * affine); // (SkMatrix *matrix, SkScalar affine[6]) -> bool
        func asAffine(affine: [Scalar]) -> Bool {
            return SkMatrix_asAffine(self.pointer, UnsafeMutablePointer(mutating: affine))
        }
        // int SkMatrix_setAffine(void *matrix, const void * affine); // (SkMatrix *matrix, const SkScalar affine[6]) -> sk_matrix_t
        func setAffine(affine: [Scalar]) -> Matrix {
            let handle = SkMatrix_setAffine(self.pointer, affine);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // void SkMatrix_normalizePerspective(void *matrix); // (SkMatrix *matrix)
        func normalizePerspective() {
            SkMatrix_normalizePerspective(self.pointer)
        }
        // void SkMatrix_mapPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count)
        func mapPoints(dst: [Point], src: [Point], count: Int) {
            SkMatrix_mapPoints(self.pointer, UnsafeMutablePointer(mutating: dst), UnsafeRawPointer(src), Int32(count))
        }
        // void SkMatrix_mapPoints_2(void *matrix, void * pts, int count); // (SkMatrix *matrix, SkPoint pts[], int count)
        func mapPoints(pts: [Point], count: Int) {
            SkMatrix_mapPoints_2(self.pointer, UnsafeMutablePointer(mutating: pts), Int32(count))
        }
        // void SkMatrix_mapHomogeneousPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count)
        func mapHomogeneousPoints(dst: [SkPoint3], src: [SkPoint3], count: Int) {
            SkMatrix_mapHomogeneousPoints(self.pointer, UnsafeMutablePointer(mutating: dst), UnsafeRawPointer(src), Int32(count))
        }
        // void SkMatrix_mapHomogeneousPoints_2(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count)
        func mapHomogeneousPoints(dst: [SkPoint3], src: [Point], count: Int) {
            SkMatrix_mapHomogeneousPoints_2(self.pointer, UnsafeMutablePointer(mutating: dst), UnsafeRawPointer(src), Int32(count))
        }
        // int SkMatrix_mapPoint(void *matrix, int pt); // (SkMatrix *matrix, sk_point_t pt) -> sk_point_t
        func mapPoint(pt: Point) -> Point {
            let handle = SkMatrix_mapPoint(self.pointer, pt.handle);
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // void SkMatrix_mapXY(void *matrix, float x, float y, void * result); // (SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result)
        func mapXY(x: Scalar, y: Scalar, result: Point) {
            SkMatrix_mapXY(self.pointer, x, y, result.pointer)
        }
        // int SkMatrix_mapXY_2(void *matrix, float x, float y); // (SkMatrix *matrix, SkScalar x, SkScalar y) -> sk_point_t
        func mapXY(x: Scalar, y: Scalar) -> Point {
            let handle = SkMatrix_mapXY_2(self.pointer, x, y);
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // int SkMatrix_mapOrigin(void *matrix); // (SkMatrix *matrix) -> sk_point_t
        func mapOrigin() -> Point {
            let handle = SkMatrix_mapOrigin(self.pointer);
            let pointer = static_sk_point_get_ptr(handle)
            return Point(pointer: pointer, handle: handle)
        }
        // void SkMatrix_mapVectors(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkVector dst[], const SkVector src[], int count)
        func mapVectors(dst: [Vector], src: [Vector], count: Int) {
            SkMatrix_mapVectors(self.pointer, UnsafeMutablePointer(mutating: dst), UnsafeRawPointer(src), Int32(count))
        }
        // void SkMatrix_mapVectors_2(void *matrix, void * vecs, int count); // (SkMatrix *matrix, SkVector vecs[], int count)
        func mapVectors(vecs: [Vector], count: Int) {
            SkMatrix_mapVectors_2(self.pointer, UnsafeMutablePointer(mutating: vecs), Int32(count))
        }
        // void SkMatrix_mapVector(void *matrix, float dx, float dy, void * result); // (SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result)
        func mapVector(dx: Scalar, dy: Scalar, result: Vector) {
            SkMatrix_mapVector(self.pointer, dx, dy, result.pointer)
        }
        // int SkMatrix_mapVector_2(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_point_t
        func mapVector(dx: Scalar, dy: Scalar) -> Vector {
            let handle = SkMatrix_mapVector_2(self.pointer, dx, dy);
            let pointer = static_sk_point_get_ptr(handle)
            return Vector(pointer: pointer, handle: handle)
        }
        // bool SkMatrix_mapRect(void *matrix, void *dst, const void *src, int pc); // (SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) -> bool
        func mapRect(dst: SkRect, src: SkRect, pc: ApplyPerspectiveClip) -> Bool {
            return SkMatrix_mapRect(self.pointer, dst.pointer, src.pointer, pc.rawValue)
        }
        // bool SkMatrix_mapRect_2(void *matrix, void *rect, int pc); // (SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) -> bool
        func mapRect(rect: SkRect, pc: ApplyPerspectiveClip) -> Bool {
            return SkMatrix_mapRect_2(self.pointer, rect.pointer, pc.rawValue)
        }
        // int SkMatrix_mapRect_3(void *matrix, const void *src, int pc); // (SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) -> sk_matrix_t
        func mapRect(src: SkRect, pc: ApplyPerspectiveClip) -> Matrix {
            let handle = SkMatrix_mapRect_3(self.pointer, src.pointer, pc.rawValue);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // void SkMatrix_mapRectToQuad(void *matrix, void * dst, const void *rect); // (SkMatrix *matrix, SkPoint dst[4], const SkRect *rect)
        func mapRectToQuad(dst: [Point], rect: SkRect) {
            SkMatrix_mapRectToQuad(self.pointer, UnsafeMutablePointer(mutating: dst), rect.pointer)
        }
        // void SkMatrix_mapRectScaleTranslate(void *matrix, void *dst, const void *src); // (SkMatrix *matrix, SkRect *dst, const SkRect *src)
        func mapRectScaleTranslate(dst: SkRect, src: SkRect) {
            SkMatrix_mapRectScaleTranslate(self.pointer, dst.pointer, src.pointer)
        }
        // float SkMatrix_mapRadius(void *matrix, float radius); // (SkMatrix *matrix, SkScalar radius) -> SkScalar
        func mapRadius(radius: Scalar) -> Scalar {
            return SkMatrix_mapRadius(self.pointer, radius)
        }
        // void SkMatrix_dump(void *matrix); // (SkMatrix *matrix)
        func dump() {
            SkMatrix_dump(self.pointer)
        }
        // float SkMatrix_getMinScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getMinScale() -> Scalar {
            return SkMatrix_getMinScale(self.pointer)
        }
        // float SkMatrix_getMaxScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getMaxScale() -> Scalar {
            return SkMatrix_getMaxScale(self.pointer)
        }
        // bool SkMatrix_getMinMaxScales(void *matrix, void * scaleFactors); // (SkMatrix *matrix, SkScalar scaleFactors[2]) -> bool
        func getMinMaxScales(scaleFactors: [Scalar]) -> Bool {
            return SkMatrix_getMinMaxScales(self.pointer, UnsafeMutablePointer(mutating: scaleFactors))
        }
        // bool SkMatrix_decomposeScale(void *matrix, void * scale, void * remaining); // (SkMatrix *matrix, SkSize *scale, SkMatrix *remaining) -> bool
        func decomposeScale(scale: SkSize, remaining: Matrix) -> Bool {
            return SkMatrix_decomposeScale(self.pointer, scale.pointer, remaining.pointer)
        }
        // void SkMatrix_dirtyMatrixTypeCache(void *matrix); // (SkMatrix *matrix)
        func dirtyMatrixTypeCache() {
            SkMatrix_dirtyMatrixTypeCache(self.pointer)
        }
        // void SkMatrix_setScaleTranslate(void *matrix, float sx, float sy, float tx, float ty); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty)
        func setScaleTranslate(sx: Scalar, sy: Scalar, tx: Scalar, ty: Scalar) {
            SkMatrix_setScaleTranslate(self.pointer, sx, sy, tx, ty)
        }
        // bool SkMatrix_isFinite(void *matrix); // (SkMatrix *matrix) -> bool
        func isFinite() -> Bool {
            return SkMatrix_isFinite(self.pointer)
        }

        // // static

        init(pointer: Skia.MatrixMutablePointer?, handle: sk_matrix_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkMatrix_Scale(float sx, float sy); // (SkScalar sx, SkScalar sy) -> sk_matrix_t
        static func Scale(sx: Scalar, sy: Scalar) -> Matrix {
            let handle = SkMatrix_Scale(sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_Translate(float dx, float dy); // (SkScalar dx, SkScalar dy) -> sk_matrix_t
        static func Translate(dx: Scalar, dy: Scalar) -> Matrix {
            let handle = SkMatrix_Translate(dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_Translate_2(int t); // (sk_point_t t) -> sk_matrix_t
        static func Translate(t: Point) -> Matrix {
            let handle = SkMatrix_Translate_2(t.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_Translate_3(int t); // (sk_i_point_t t) -> sk_matrix_t
        static func Translate(t: IPoint) -> Matrix {
            let handle = SkMatrix_Translate_3(t.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_RotateDeg(float deg); // (SkScalar deg) -> sk_matrix_t
        static func RotateDeg(deg: Scalar) -> Matrix {
            let handle = SkMatrix_RotateDeg(deg);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_RotateDeg_2(float deg, int pt); // (SkScalar deg, sk_point_t pt) -> sk_matrix_t
        static func RotateDeg(deg: Scalar, pt: Point) -> Matrix {
            let handle = SkMatrix_RotateDeg_2(deg, pt.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_RotateRad(float rad); // (SkScalar rad) -> sk_matrix_t
        static func RotateRad(rad: Scalar) -> Matrix {
            let handle = SkMatrix_RotateRad(rad);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_Skew(float kx, float ky); // (SkScalar kx, SkScalar ky) -> sk_matrix_t
        static func Skew(kx: Scalar, ky: Scalar) -> Matrix {
            let handle = SkMatrix_Skew(kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_RectToRect(const void *src, const void *dst, int mode); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) -> sk_matrix_t
        static func RectToRect(src: SkRect, dst: SkRect, mode: ScaleToFit) -> Matrix {
            let handle = SkMatrix_RectToRect(src.pointer, dst.pointer, Int32(mode.rawValue));
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_MakeAll(float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float pers0, float pers1, float pers2); // (SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2) -> sk_matrix_t
        static func MakeAll(scaleX: Scalar, skewX: Scalar, transX: Scalar, skewY: Scalar, scaleY: Scalar, transY: Scalar, pers0: Scalar, pers1: Scalar, pers2: Scalar) -> Matrix {
            let handle = SkMatrix_MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_MakeRectToRect(const void *src, const void *dst, int stf); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> sk_matrix_t
        static func MakeRectToRect(src: SkRect, dst: SkRect, stf: ScaleToFit) -> Matrix {
            let handle = SkMatrix_MakeRectToRect(src.pointer, dst.pointer, Int32(stf.rawValue));
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // void SkMatrix_SetAffineIdentity(void * affine); // (SkScalar affine[6])
        static func SetAffineIdentity(affine: [Float]) {
            SkMatrix_SetAffineIdentity(UnsafeMutablePointer(mutating: affine))
        }
        // int SkMatrix_I(); // () -> sk_matrix_t
        static func I() -> Matrix {
            let handle = SkMatrix_I();
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_InvalidMatrix(); // () -> sk_matrix_t
        static func InvalidMatrix() -> Matrix {
            let handle = SkMatrix_InvalidMatrix();
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
        // int SkMatrix_Concat(const void *a, const void *b); // (const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t
        static func Concat(a: Matrix, b: Matrix) -> Matrix {
            let handle = SkMatrix_Concat(a.pointer, b.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return Matrix(pointer: pointer, handle: handle)
        }
    }
}