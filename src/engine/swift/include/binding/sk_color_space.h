//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_SPACE_H
#define RAIA_SKIA_SK_COLOR_SPACE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorSpace_delete(void *color_space); // (SkColorSpace *color_space)
void SkColorSpace_toProfile(void *color_space, void *profile); // (SkColorSpace *color_space, skcms_ICCProfile *profile)
bool SkColorSpace_gammaCloseToSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
bool SkColorSpace_gammaIsLinear(void *color_space); // (SkColorSpace *color_space) -> bool
bool SkColorSpace_isNumericalTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn) -> bool
bool SkColorSpace_toXYZD50(void *color_space, void *toXYZD50); // (SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) -> bool
unsigned int SkColorSpace_toXYZD50Hash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
int SkColorSpace_makeLinearGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
int SkColorSpace_makeSRGBGamma(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
int SkColorSpace_makeColorSpin(void *color_space); // (SkColorSpace *color_space) -> sk_color_space_t
bool SkColorSpace_isSRGB(void *color_space); // (SkColorSpace *color_space) -> bool
int SkColorSpace_serialize(void *color_space); // (SkColorSpace *color_space) -> sk_data_t
unsigned long SkColorSpace_writeToMemory(void *color_space, void *memory); // (SkColorSpace *color_space, void *memory) -> size_t
void SkColorSpace_transferFn(void *color_space, float gabcdef[7]); // (SkColorSpace *color_space, float gabcdef[7])
void SkColorSpace_transferFn_2(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
void SkColorSpace_invTransferFn(void *color_space, void *fn); // (SkColorSpace *color_space, skcms_TransferFunction *fn)
void SkColorSpace_gamutTransformTo(void *color_space, const void *dst, void *src_to_dst); // (SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst)
unsigned int SkColorSpace_transferFnHash(void *color_space); // (SkColorSpace *color_space) -> uint32_t
unsigned long long SkColorSpace_hash(void *color_space); // (SkColorSpace *color_space) -> uint64_t
bool SkColorSpace_unique(void *color_space); // (SkColorSpace *color_space) -> bool
void SkColorSpace_ref(void *color_space); // (SkColorSpace *color_space)
void SkColorSpace_unref(void *color_space); // (SkColorSpace *color_space)
void SkColorSpace_deref(void *color_space); // (SkColorSpace *color_space)
bool SkColorSpace_refCntGreaterThan(void *color_space, int threadIsolatedTestCnt); // (SkColorSpace *color_space, int32_t threadIsolatedTestCnt) -> bool

// static

int SkColorSpace_MakeSRGB(); // () -> sk_color_space_t
int SkColorSpace_MakeSRGBLinear(); // () -> sk_color_space_t
int SkColorSpace_MakeRGB(const void *transferFn, const void *toXYZ); // (const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) -> sk_color_space_t
int SkColorSpace_Make(const void * profile); // (const skcms_ICCProfile *profile) -> sk_color_space_t
int SkColorSpace_Deserialize(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_color_space_t
bool SkColorSpace_Equals(void *color_space_1, const void *color_space_2); // (SkColorSpace *color_space_1, const SkColorSpace *color_space_2) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_SPACE_H
