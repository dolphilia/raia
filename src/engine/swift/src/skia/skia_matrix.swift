extension Skia {
    enum SkMatrixScaleToFit: Int32 {
        case fill
        case start
        case center
        case end
    }

    enum SkMatrixTypeMask: Int32 {
        case identity = 0
        case translate = 0x01
        case scale = 0x02
        case affine = 0x04
        case perspective = 0x08
    }

    protocol SkMatrixProtocol {
        var pointer: SkMatrixMutablePointer? { get set }
        var handle: sk_matrix_t { get set }
        // deinit // void SkMatrix_delete(void *matrix); // (SkMatrix *matrix)
        init(pointer: SkMatrixMutablePointer?, handle: sk_matrix_t)
        init(matrix: SkMatrix)
        // Static Methods
        static func Scale(sx: Float, sy: Float) -> SkMatrix // int SkMatrix_Scale(float sx, float sy); // (SkScalar sx, SkScalar sy) -> sk_matrix_t
        static func Translate(dx: Float, dy: Float) -> SkMatrix // int SkMatrix_Translate(float dx, float dy); // (SkScalar dx, SkScalar dy) -> sk_matrix_t
        static func Translate(t: SkPoint) -> SkMatrix // int SkMatrix_Translate_2(int t); // (sk_point_t t) -> sk_matrix_t
        static func Translate(t: SkIPoint) -> SkMatrix // int SkMatrix_Translate_3(int t); // (sk_i_point_t t) -> sk_matrix_t
        static func RotateDeg(deg: Float) -> SkMatrix // int SkMatrix_RotateDeg(float deg); // (SkScalar deg) -> sk_matrix_t
        static func RotateDeg(deg: Float, pt: SkPoint) -> SkMatrix // int SkMatrix_RotateDeg_2(float deg, int pt); // (SkScalar deg, sk_point_t pt) -> sk_matrix_t 
        static func RotateRad(rad: Float) -> SkMatrix // int SkMatrix_RotateRad(float rad); // (SkScalar rad) -> sk_matrix_t
        static func Skew(kx: Float, ky: Float) -> SkMatrix // int SkMatrix_Skew(float kx, float ky); // (SkScalar kx, SkScalar ky) -> sk_matrix_t
        static func RectToRect(src: SkRect, dst: SkRect, mode: SkMatrixScaleToFit) -> SkMatrix // int SkMatrix_RectToRect(const void *src, const void *dst, int mode); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) -> sk_matrix_t
        static func MakeAll(scaleX: Float, skewX: Float, transX: Float, skewY: Float, scaleY: Float, transY: Float, pers0: Float, pers1: Float, pers2: Float) -> SkMatrix // int SkMatrix_MakeAll(float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float pers0, float pers1, float pers2); // (SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar
        static func MakeRectToRect(src: SkRect, dst: SkRect, stf: SkMatrixScaleToFit) -> SkMatrix // int SkMatrix_MakeRectToRect(const void *src, const void *dst, int stf); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> sk_matrix_t
        static func SetAffineIdentity(affine: inout [Float]) // void SkMatrix_SetAffineIdentity(void * affine); // (SkScalar affine[6])
        static func I() -> SkMatrix // int SkMatrix_I(); // () -> sk_matrix_t
        static func InvalidMatrix() -> SkMatrix // int SkMatrix_InvalidMatrix(); // () -> sk_matrix_t
        static func Concat(a: SkMatrix, b: SkMatrix) -> SkMatrix // int SkMatrix_Concat(const void *a, const void *b); // (const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t
        // Methods
        func getType() -> SkMatrixTypeMask // int SkMatrix_getType(void *matrix); // (SkMatrix *matrix) -> SkMatrix::TypeMask
        func isIdentity() -> Bool // bool SkMatrix_isIdentity(void *matrix); // (SkMatrix *matrix) -> bool
        func isScaleTranslate() -> Bool // bool SkMatrix_isScaleTranslate(void *matrix); // (SkMatrix *matrix) -> bool
        func isTranslate() -> Bool // bool SkMatrix_isTranslate(void *matrix); // (SkMatrix *matrix) -> bool
        func rectStaysRect() -> Bool // bool SkMatrix_rectStaysRect(void *matrix); // (SkMatrix *matrix) -> bool
        func preservesAxisAlignment() -> Bool // bool SkMatrix_preservesAxisAlignment(void *matrix); // (SkMatrix *matrix) -> bool
        func hasPerspective() -> Bool // bool SkMatrix_hasPerspective(void *matrix); // (SkMatrix *matrix) -> bool
        func isSimilarity(tol: Float) -> Bool // bool SkMatrix_isSimilarity(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
        func preservesRightAngles(tol: Float) -> Bool // bool SkMatrix_preservesRightAngles(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
        func get(index: Int) -> Float // float SkMatrix_get(void *matrix, int index); // (SkMatrix *matrix, int index) -> SkScalar
        func rc(r: Int, c: Int) -> Float // float SkMatrix_rc(void *matrix, int r, int c); // (SkMatrix *matrix, int r, int c) -> SkScalar
        func getScaleX() -> Float // float SkMatrix_getScaleX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getScaleY() -> Float // float SkMatrix_getScaleY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getSkewY() -> Float // float SkMatrix_getSkewY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getSkewX() -> Float // float SkMatrix_getSkewX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getTranslateX() -> Float // float SkMatrix_getTranslateX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getTranslateY() -> Float // float SkMatrix_getTranslateY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getPerspX() -> Float // float SkMatrix_getPerspX(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getPerspY() -> Float // float SkMatrix_getPerspY(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func set(index: Int, value: Float) -> SkMatrix // int SkMatrix_set(void *matrix, int index, float value); // (SkMatrix *matrix, int index, SkScalar value) -> sk_matrix_t
        func setScaleX(v: Float) -> SkMatrix // int SkMatrix_setScaleX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setScaleY(v: Float) -> SkMatrix // int SkMatrix_setScaleY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setSkewY(v: Float) -> SkMatrix // int SkMatrix_setSkewY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setSkewX(v: Float) -> SkMatrix // int SkMatrix_setSkewX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setTranslateX(v: Float) -> SkMatrix // int SkMatrix_setTranslateX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setTranslateY(v: Float) -> SkMatrix // int SkMatrix_setTranslateY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setPerspX(v: Float) -> SkMatrix // int SkMatrix_setPerspX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setPerspY(v: Float) -> SkMatrix // int SkMatrix_setPerspY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
        func setAll(scaleX: Float, skewX: Float, transX: Float, skewY: Float, scaleY: Float, transY: Float, persp0: Float, persp1: Float, persp2: Float) -> SkMatrix // int SkMatrix_setAll(void *matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2); // (SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) -> sk_matrix_t
        func get9(buffer: inout [Float]) // void SkMatrix_get9(void *matrix, void * buffer); // (SkMatrix *matrix, SkScalar buffer[9])
        func set9(buffer: [Float]) -> SkMatrix // int SkMatrix_set9(void *matrix, const void * buffer); // (SkMatrix *matrix, const SkScalar buffer[9]) -> sk_matrix_t
        func reset() -> SkMatrix // int SkMatrix_reset(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
        func setIdentity() -> SkMatrix // int SkMatrix_setIdentity(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
        func setTranslate(dx: Float, dy: Float) -> SkMatrix // int SkMatrix_setTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func setTranslate(v: SkVector) -> SkMatrix // int SkMatrix_setTranslate_2(void *matrix, const void *v); // (SkMatrix *matrix, const SkVector *v) -> sk_matrix_t
        func setScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_setScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func setScale(sx: Float, sy: Float) -> SkMatrix // int SkMatrix_setScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func setRotate(degrees: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_setRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func setRotate(degrees: Float) -> SkMatrix // int SkMatrix_setRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func setSinCos(sinValue: Float, cosValue: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_setSinCos(void *matrix, float sinValue, float cosValue, float px, float py); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) -> sk_matrix_t
        func setSinCos(sinValue: Float, cosValue: Float) -> SkMatrix // int SkMatrix_setSinCos_2(void *matrix, float sinValue, float cosValue); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) -> sk_matrix_t
        func setRSXform(rsxForm: SkRSXform) -> SkMatrix // int SkMatrix_setRSXform(void *matrix, const void *rsxForm); // (SkMatrix *matrix, const SkRSXform *rsxForm) -> sk_matrix_t
        func setSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_setSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func setSkew(kx: Float, ky: Float) -> SkMatrix // int SkMatrix_setSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func setConcat(a: SkMatrix, b: SkMatrix) -> SkMatrix // int SkMatrix_setConcat(void *matrix, const void *a, const void *b); // (SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t
        func preTranslate(dx: Float, dy: Float) -> SkMatrix // int SkMatrix_preTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func preScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_preScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func preScale(sx: Float, sy: Float) -> SkMatrix // int SkMatrix_preScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func preRotate(degrees: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_preRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func preRotate(degrees: Float) -> SkMatrix // int SkMatrix_preRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func preSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_preSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func preSkew(kx: Float, ky: Float) -> SkMatrix // int SkMatrix_preSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func preConcat(other: SkMatrix) -> SkMatrix // int SkMatrix_preConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
        func postTranslate(dx: Float, dy: Float) -> SkMatrix // int SkMatrix_postTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
        func postScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_postScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
        func postScale(sx: Float, sy: Float) -> SkMatrix // int SkMatrix_postScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
        func postRotate(degrees: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_postRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
        func postRotate(degrees: Float) -> SkMatrix // int SkMatrix_postRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
        func postSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix // int SkMatrix_postSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
        func postSkew(kx: Float, ky: Float) -> SkMatrix // int SkMatrix_postSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
        func postConcat(other: SkMatrix) -> SkMatrix // int SkMatrix_postConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
        func setRectToRect(src: SkRect, dst: SkRect, stf: SkMatrixScaleToFit) -> Bool // bool SkMatrix_setRectToRect(void *matrix, const void * src, const void * dst, int stf); // (SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> bool
        func setPolyToPoly(src: [SkPoint], dst: [SkPoint], count: Int) -> Bool // bool SkMatrix_setPolyToPoly(void *matrix, const void * src, const void * dst, int count); // (SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count) -> bool
        func invert(inverse: SkMatrix) -> Bool // bool SkMatrix_invert(void *matrix, void * inverse); // (SkMatrix *matrix, SkMatrix *inverse) -> bool
        func asAffine(affine: [Float]) -> Bool // bool SkMatrix_asAffine(void *matrix, void * affine); // (SkMatrix *matrix, SkScalar affine[6]) -> bool
        func setAffine(affine: [Float]) -> SkMatrix // int SkMatrix_setAffine(void *matrix, const void * affine); // (SkMatrix *matrix, const SkScalar affine[6]) -> sk_matrix_t
        func normalizePerspective() // void SkMatrix_normalizePerspective(void *matrix); // (SkMatrix *matrix)
        func mapPoints(dst: inout [SkPoint], src: [SkPoint], count: Int) // void SkMatrix_mapPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count)
        func mapPoints(pts: inout [SkPoint], count: Int) // void SkMatrix_mapPoints_2(void *matrix, void * pts, int count); // (SkMatrix *matrix, SkPoint pts[], int count)
        func mapHomogeneousPoints(dst: inout [SkPoint3], src: [SkPoint3], count: Int) // void SkMatrix_mapHomogeneousPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count)
        func mapHomogeneousPoints(dst: inout [SkPoint3], src: inout [SkPoint], count: Int) // void SkMatrix_mapHomogeneousPoints_2(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count)
        func mapPoint(pt: SkPoint) -> SkPoint // int SkMatrix_mapPoint(void *matrix, int pt); // (SkMatrix *matrix, sk_point_t pt) -> sk_point_t
        func mapXY(x: Float, y: Float, result: SkPoint) // void SkMatrix_mapXY(void *matrix, float x, float y, void * result); // (SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result)
        func mapXY(x: Float, y: Float) -> SkPoint // int SkMatrix_mapXY_2(void *matrix, float x, float y); // (SkMatrix *matrix, SkScalar x, SkScalar y) -> sk_point_t
        func mapOrigin() -> SkPoint // int SkMatrix_mapOrigin(void *matrix); // (SkMatrix *matrix) -> sk_point_t
        func mapVectors(dst: inout [SkVector], src: [SkVector], count: Int) // void SkMatrix_mapVectors(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkVector dst[], const SkVector src[], int count)
        func mapVectors(vecs: inout [SkVector], count: Int) // void SkMatrix_mapVectors_2(void *matrix, void * vecs, int count); // (SkMatrix *matrix, SkVector vecs[], int count)
        func mapVector(dx: Float, dy: Float, result: SkVector) // void SkMatrix_mapVector(void *matrix, float dx, float dy, void * result); // (SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result)
        func mapVector(dx: Float, dy: Float) -> SkVector // int SkMatrix_mapVector_2(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_point_t
        func mapRect(dst: SkRect, src: SkRect, pc: SkApplyPerspectiveClip) -> Bool // bool SkMatrix_mapRect(void *matrix, void *dst, const void *src, int pc); // (SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) -> bool
        func mapRect(rect: SkRect, pc: SkApplyPerspectiveClip) -> Bool // bool SkMatrix_mapRect_2(void *matrix, void *rect, int pc); // (SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) -> bool
        func mapRect(src: SkRect, pc: SkApplyPerspectiveClip) -> SkMatrix // int SkMatrix_mapRect_3(void *matrix, const void *src, int pc); // (SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) -> sk_matrix_t
        func mapRectToQuad(dst: inout [SkPoint], rect: SkRect) // void SkMatrix_mapRectToQuad(void *matrix, void * dst, const void *rect); // (SkMatrix *matrix, SkPoint dst[4], const SkRect *rect)
        func mapRectScaleTranslate(dst: SkRect, src: SkRect) // void SkMatrix_mapRectScaleTranslate(void *matrix, void *dst, const void *src); // (SkMatrix *matrix, SkRect *dst, const SkRect *src)
        func mapRadius(radius: Float) -> Float // float SkMatrix_mapRadius(void *matrix, float radius); // (SkMatrix *matrix, SkScalar radius) -> SkScalar
        func dump() // void SkMatrix_dump(void *matrix); // (SkMatrix *matrix)
        func getMinScale() -> Float // float SkMatrix_getMinScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getMaxScale() -> Float // float SkMatrix_getMaxScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
        func getMinMaxScales(scaleFactors: inout [Float]) -> Bool // bool SkMatrix_getMinMaxScales(void *matrix, void * scaleFactors); // (SkMatrix *matrix, SkScalar scaleFactors[2]) -> bool
        func decomposeScale(scale: SkSize, remaining: SkMatrix) -> Bool // bool SkMatrix_decomposeScale(void *matrix, void * scale, void * remaining); // (SkMatrix *matrix, SkSize *scale, SkMatrix *remaining) -> bool
        func dirtyMatrixTypeCache() // void SkMatrix_dirtyMatrixTypeCache(void *matrix); // (SkMatrix *matrix)
        func setScaleTranslate(sx: Float, sy: Float, tx: Float, ty: Float) // void SkMatrix_setScaleTranslate(void *matrix, float sx, float sy, float tx, float ty); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty)
        func isFinite() -> Bool // bool SkMatrix_isFinite(void *matrix); // (SkMatrix *matrix) -> bool
    }

    class SkMatrix : SkMatrixProtocol {
        public var pointer: SkMatrixMutablePointer?
        public var handle: sk_matrix_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_matrix_delete(self.handle)
            } else {
                SkMatrix_delete(self.pointer)
            }
        }

        required init(pointer: SkMatrixMutablePointer?, handle: sk_matrix_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init(matrix: SkMatrix) {
            self.pointer = SkMatrix_new(matrix.pointer)
            self.handle = -1
        }

        // Static Methods

        static func Scale(sx: Float, sy: Float) -> SkMatrix {
            let handle = SkMatrix_Scale(sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func Translate(dx: Float, dy: Float) -> SkMatrix {
            let handle = SkMatrix_Translate(dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func Translate(t: SkPoint) -> SkMatrix {
            let handle = SkMatrix_Translate_2(t.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func Translate(t: SkIPoint) -> SkMatrix {
            let handle = SkMatrix_Translate_3(t.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func RotateDeg(deg: Float) -> SkMatrix {
            let handle = SkMatrix_RotateDeg(deg);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func RotateDeg(deg: Float, pt: SkPoint) -> SkMatrix {
            let handle = SkMatrix_RotateDeg_2(deg, pt.handle);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func RotateRad(rad: Float) -> SkMatrix {
            let handle = SkMatrix_RotateRad(rad);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func Skew(kx: Float, ky: Float) -> SkMatrix {
            let handle = SkMatrix_Skew(kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func RectToRect(src: SkRect, dst: SkRect, mode: SkMatrixScaleToFit) -> SkMatrix {
            let handle = SkMatrix_RectToRect(src.pointer, dst.pointer, Int32(mode.rawValue));
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func MakeAll(scaleX: Float, skewX: Float, transX: Float, skewY: Float, scaleY: Float, transY: Float, pers0: Float, pers1: Float, pers2: Float) -> SkMatrix {
            let handle = SkMatrix_MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func MakeRectToRect(src: SkRect, dst: SkRect, stf: SkMatrixScaleToFit) -> SkMatrix {
            let handle = SkMatrix_MakeRectToRect(src.pointer, dst.pointer, Int32(stf.rawValue));
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func SetAffineIdentity(affine: inout [Float]) {
            affine.withUnsafeMutableBufferPointer { buffer in
                SkMatrix_SetAffineIdentity(buffer.baseAddress)
            }
        }

        static func I() -> SkMatrix {
            let handle = SkMatrix_I();
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func InvalidMatrix() -> SkMatrix {
            let handle = SkMatrix_InvalidMatrix();
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        static func Concat(a: SkMatrix, b: SkMatrix) -> SkMatrix {
            let handle = SkMatrix_Concat(a.pointer, b.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        // Methods

        func getType() -> SkMatrixTypeMask {
            return SkMatrixTypeMask(rawValue: SkMatrix_getType(self.pointer))!
        }

        func isIdentity() -> Bool {
            return SkMatrix_isIdentity(self.pointer)
        }

        func isScaleTranslate() -> Bool {
            return SkMatrix_isScaleTranslate(self.pointer)
        }

        func isTranslate() -> Bool {
            return SkMatrix_isTranslate(self.pointer)
        }

        func rectStaysRect() -> Bool {
            return SkMatrix_rectStaysRect(self.pointer)
        }

        func preservesAxisAlignment() -> Bool {
            return SkMatrix_preservesAxisAlignment(self.pointer)
        }

        func hasPerspective() -> Bool {
            return SkMatrix_hasPerspective(self.pointer)
        }

        func isSimilarity(tol: Float) -> Bool {
            return SkMatrix_isSimilarity(self.pointer, tol)
        }

        func preservesRightAngles(tol: Float) -> Bool {
            return SkMatrix_preservesRightAngles(self.pointer, tol)
        }

        func get(index: Int) -> Float {
            return SkMatrix_get(self.pointer, Int32(index))
        }

        func rc(r: Int, c: Int) -> Float {
            return SkMatrix_rc(self.pointer, Int32(r), Int32(c))
        }

        func getScaleX() -> Float {
            return SkMatrix_getScaleX(self.pointer)
        }

        func getScaleY() -> Float {
            return SkMatrix_getScaleY(self.pointer)
        }

        func getSkewY() -> Float {
            return SkMatrix_getSkewY(self.pointer)
        }

        func getSkewX() -> Float {
            return SkMatrix_getSkewX(self.pointer)
        }

        func getTranslateX() -> Float {
            return SkMatrix_getTranslateX(self.pointer)
        }

        func getTranslateY() -> Float {
            return SkMatrix_getTranslateY(self.pointer)
        }

        func getPerspX() -> Float {
            return SkMatrix_getPerspX(self.pointer)
        }

        func getPerspY() -> Float {
            return SkMatrix_getPerspY(self.pointer)
        }

        func set(index: Int, value: Float) -> SkMatrix {
            let handle = SkMatrix_set(self.pointer, Int32(index), value);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setScaleX(v: Float) -> SkMatrix {
            let handle = SkMatrix_setScaleX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setScaleY(v: Float) -> SkMatrix {
            let handle = SkMatrix_setScaleY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSkewY(v: Float) -> SkMatrix {
            let handle = SkMatrix_setSkewY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSkewX(v: Float) -> SkMatrix {
            let handle = SkMatrix_setSkewX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setTranslateX(v: Float) -> SkMatrix {
            let handle = SkMatrix_setTranslateX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setTranslateY(v: Float) -> SkMatrix {
            let handle = SkMatrix_setTranslateY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setPerspX(v: Float) -> SkMatrix {
            let handle = SkMatrix_setPerspX(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setPerspY(v: Float) -> SkMatrix {
            let handle = SkMatrix_setPerspY(self.pointer, v);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setAll(scaleX: Float, skewX: Float, transX: Float, skewY: Float, scaleY: Float, transY: Float, persp0: Float, persp1: Float, persp2: Float) -> SkMatrix {
            let handle = SkMatrix_setAll(self.pointer, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func get9(buffer: inout [Float]) {
            buffer.withUnsafeMutableBufferPointer { buf in
                SkMatrix_get9(self.pointer, buf.baseAddress)
            }
        }

        func set9(buffer: [Float]) -> SkMatrix {
            let handle = SkMatrix_set9(self.pointer, buffer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func reset() -> SkMatrix {
            let handle = SkMatrix_reset(self.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setIdentity() -> SkMatrix {
            let handle = SkMatrix_setIdentity(self.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setTranslate(dx: Float, dy: Float) -> SkMatrix {
            let handle = SkMatrix_setTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setTranslate(v: SkVector) -> SkMatrix {
            let handle = SkMatrix_setTranslate_2(self.pointer, v.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_setScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setScale(sx: Float, sy: Float) -> SkMatrix {
            let handle = SkMatrix_setScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setRotate(degrees: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_setRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setRotate(degrees: Float) -> SkMatrix {
            let handle = SkMatrix_setRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSinCos(sinValue: Float, cosValue: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_setSinCos(self.pointer, sinValue, cosValue, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSinCos(sinValue: Float, cosValue: Float) -> SkMatrix {
            let handle = SkMatrix_setSinCos_2(self.pointer, sinValue, cosValue);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setRSXform(rsxForm: SkRSXform) -> SkMatrix {
            let handle = SkMatrix_setRSXform(self.pointer, rsxForm.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_setSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setSkew(kx: Float, ky: Float) -> SkMatrix {
            let handle = SkMatrix_setSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setConcat(a: SkMatrix, b: SkMatrix) -> SkMatrix {
            let handle = SkMatrix_setConcat(self.pointer, a.pointer, b.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preTranslate(dx: Float, dy: Float) -> SkMatrix {
            let handle = SkMatrix_preTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_preScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preScale(sx: Float, sy: Float) -> SkMatrix {
            let handle = SkMatrix_preScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preRotate(degrees: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_preRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preRotate(degrees: Float) -> SkMatrix {
            let handle = SkMatrix_preRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_preSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preSkew(kx: Float, ky: Float) -> SkMatrix {
            let handle = SkMatrix_preSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func preConcat(other: SkMatrix) -> SkMatrix {
            let handle = SkMatrix_preConcat(self.pointer, other.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postTranslate(dx: Float, dy: Float) -> SkMatrix {
            let handle = SkMatrix_postTranslate(self.pointer, dx, dy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postScale(sx: Float, sy: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_postScale(self.pointer, sx, sy, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postScale(sx: Float, sy: Float) -> SkMatrix {
            let handle = SkMatrix_postScale_2(self.pointer, sx, sy);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postRotate(degrees: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_postRotate(self.pointer, degrees, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postRotate(degrees: Float) -> SkMatrix {
            let handle = SkMatrix_postRotate_2(self.pointer, degrees);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postSkew(kx: Float, ky: Float, px: Float, py: Float) -> SkMatrix {
            let handle = SkMatrix_postSkew(self.pointer, kx, ky, px, py);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postSkew(kx: Float, ky: Float) -> SkMatrix {
            let handle = SkMatrix_postSkew_2(self.pointer, kx, ky);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func postConcat(other: SkMatrix) -> SkMatrix {
            let handle = SkMatrix_postConcat(self.pointer, other.pointer);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func setRectToRect(src: SkRect, dst: SkRect, stf: SkMatrixScaleToFit) -> Bool {
            return SkMatrix_setRectToRect(self.pointer, src.pointer, dst.pointer, stf.rawValue)
        }

        func setPolyToPoly(src: [SkPoint], dst: [SkPoint], count: Int) -> Bool {
            return src.withUnsafeBufferPointer { srcBuf in
                return dst.withUnsafeBufferPointer { dstBuf in
                    return SkMatrix_setPolyToPoly(self.pointer, srcBuf.baseAddress, dstBuf.baseAddress, Int32(count))
                }
            }
        }

        func invert(inverse: SkMatrix) -> Bool {
            return SkMatrix_invert(self.pointer, inverse.pointer)
        }

        func asAffine(affine: [Float]) -> Bool {
            var affineCopy = affine
            return affineCopy.withUnsafeMutableBufferPointer { buffer in
                return SkMatrix_asAffine(self.pointer, buffer.baseAddress)
            }
        }

        func setAffine(affine: [Float]) -> SkMatrix {
            let handle = SkMatrix_setAffine(self.pointer, affine);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func normalizePerspective() {
            SkMatrix_normalizePerspective(self.pointer)
        }

        func mapPoints(dst: inout [SkPoint], src: [SkPoint], count: Int) {
            dst.withUnsafeMutableBufferPointer { dBuf in
                src.withUnsafeBufferPointer { sBuf in
                    SkMatrix_mapPoints(self.pointer, dBuf.baseAddress, UnsafeRawPointer(sBuf.baseAddress), Int32(count))
                }
            }
        }

        func mapPoints(pts: inout [SkPoint], count: Int) {
            pts.withUnsafeMutableBufferPointer { buffer in
                SkMatrix_mapPoints_2(self.pointer, buffer.baseAddress, Int32(count))
            }
        }

        func mapHomogeneousPoints(dst: inout [SkPoint3], src: [SkPoint3], count: Int) {
            dst.withUnsafeMutableBufferPointer { dstBuffer in
                src.withUnsafeBufferPointer { srcBuffer in
                    SkMatrix_mapHomogeneousPoints(self.pointer, dstBuffer.baseAddress, UnsafeRawPointer(srcBuffer.baseAddress), Int32(count))
                }
            }
        }

        func mapHomogeneousPoints(dst: inout [SkPoint3], src: inout [SkPoint], count: Int) {
            dst.withUnsafeMutableBufferPointer { dstBuffer in
                src.withUnsafeBufferPointer { srcBuffer in
                    SkMatrix_mapHomogeneousPoints_2(self.pointer, dstBuffer.baseAddress, UnsafeRawPointer(srcBuffer.baseAddress), Int32(count))
                }
            }
        }

        func mapPoint(pt: SkPoint) -> SkPoint {
            let handle = SkMatrix_mapPoint(self.pointer, pt.handle);
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func mapXY(x: Float, y: Float, result: SkPoint) {
            SkMatrix_mapXY(self.pointer, x, y, result.pointer)
        }

        func mapXY(x: Float, y: Float) -> SkPoint {
            let handle = SkMatrix_mapXY_2(self.pointer, x, y);
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func mapOrigin() -> SkPoint {
            let handle = SkMatrix_mapOrigin(self.pointer);
            let pointer = static_sk_point_get_ptr(handle)
            return SkPoint(pointer: pointer, handle: handle)
        }

        func mapVectors(dst: inout [SkVector], src: [SkVector], count: Int) {
            dst.withUnsafeMutableBufferPointer { dBuf in
                src.withUnsafeBufferPointer { sBuf in
                    SkMatrix_mapVectors(self.pointer, dBuf.baseAddress, sBuf.baseAddress, Int32(count))
                }
            }
        }

        func mapVectors(vecs: inout [SkVector], count: Int) {
            vecs.withUnsafeMutableBufferPointer { buffer in
                SkMatrix_mapVectors_2(self.pointer, buffer.baseAddress, Int32(count))
            }
        }

        func mapVector(dx: Float, dy: Float, result: SkVector) {
            SkMatrix_mapVector(self.pointer, dx, dy, result.pointer)
        }

        func mapVector(dx: Float, dy: Float) -> SkVector {
            let handle = SkMatrix_mapVector_2(self.pointer, dx, dy);
            let pointer = static_sk_point_get_ptr(handle)
            return SkVector(pointer: pointer, handle: handle)
        }

        func mapRect(dst: SkRect, src: SkRect, pc: SkApplyPerspectiveClip) -> Bool {
            return SkMatrix_mapRect(self.pointer, dst.pointer, src.pointer, pc.rawValue)
        }

        func mapRect(rect: SkRect, pc: SkApplyPerspectiveClip) -> Bool {
            return SkMatrix_mapRect_2(self.pointer, rect.pointer, pc.rawValue)
        }

        func mapRect(src: SkRect, pc: SkApplyPerspectiveClip) -> SkMatrix {
            let handle = SkMatrix_mapRect_3(self.pointer, src.pointer, pc.rawValue);
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }

        func mapRectToQuad(dst: inout [SkPoint], rect: SkRect) {
            dst.withUnsafeMutableBufferPointer { dBuf in
                SkMatrix_mapRectToQuad(self.pointer, dBuf.baseAddress, rect.pointer)
            }
        }

        func mapRectScaleTranslate(dst: SkRect, src: SkRect) {
            SkMatrix_mapRectScaleTranslate(self.pointer, dst.pointer, src.pointer)
        }

        func mapRadius(radius: Float) -> Float {
            return SkMatrix_mapRadius(self.pointer, radius)
        }

        func dump() {
            SkMatrix_dump(self.pointer)
        }

        func getMinScale() -> Float {
            return SkMatrix_getMinScale(self.pointer)
        }

        func getMaxScale() -> Float {
            return SkMatrix_getMaxScale(self.pointer)
        }

        func getMinMaxScales(scaleFactors: inout [Float]) -> Bool {
            return scaleFactors.withUnsafeMutableBufferPointer { ptr in
                return SkMatrix_getMinMaxScales(self.pointer, ptr.baseAddress)
            }
        }

        func decomposeScale(scale: SkSize, remaining: SkMatrix) -> Bool {
            return SkMatrix_decomposeScale(self.pointer, scale.pointer, remaining.pointer)
        }

        func dirtyMatrixTypeCache() {
            SkMatrix_dirtyMatrixTypeCache(self.pointer)
        }

        func setScaleTranslate(sx: Float, sy: Float, tx: Float, ty: Float) {
            SkMatrix_setScaleTranslate(self.pointer, sx, sy, tx, ty)
        }

        func isFinite() -> Bool {
            return SkMatrix_isFinite(self.pointer)
        }
    }
}