//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_SPACE_H
#define RAIA_SKIA_SK_COLOR_SPACE_H

#include "include/core/SkColorSpace.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_data.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkColorSpace_delete(SkColorSpace *color_space);
RAIA_API void SkColorSpace_toProfile(SkColorSpace *color_space, skcms_ICCProfile *profile);
RAIA_API bool SkColorSpace_gammaCloseToSRGB(SkColorSpace *color_space);
RAIA_API bool SkColorSpace_gammaIsLinear(SkColorSpace *color_space);
RAIA_API bool SkColorSpace_isNumericalTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn);
RAIA_API bool SkColorSpace_toXYZD50(SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50);
RAIA_API uint32_t SkColorSpace_toXYZD50Hash(SkColorSpace *color_space);
RAIA_API sk_color_space_t SkColorSpace_makeLinearGamma(SkColorSpace *color_space);
RAIA_API sk_color_space_t SkColorSpace_makeSRGBGamma(SkColorSpace *color_space);
RAIA_API sk_color_space_t SkColorSpace_makeColorSpin(SkColorSpace *color_space);
RAIA_API bool SkColorSpace_isSRGB(SkColorSpace *color_space);
RAIA_API sk_data_t SkColorSpace_serialize(SkColorSpace *color_space);
RAIA_API size_t SkColorSpace_writeToMemory(SkColorSpace *color_space, void *memory);
RAIA_API void SkColorSpace_transferFn(SkColorSpace *color_space, float gabcdef[7]);
RAIA_API void SkColorSpace_transferFn_2(SkColorSpace *color_space, skcms_TransferFunction *fn);
RAIA_API void SkColorSpace_invTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn);
RAIA_API void SkColorSpace_gamutTransformTo(SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst);
RAIA_API uint32_t SkColorSpace_transferFnHash(SkColorSpace *color_space);
RAIA_API uint64_t SkColorSpace_hash(SkColorSpace *color_space);
RAIA_API bool SkColorSpace_unique(SkColorSpace *color_space);
RAIA_API void SkColorSpace_ref(SkColorSpace *color_space);
RAIA_API void SkColorSpace_unref(SkColorSpace *color_space);
RAIA_API void SkColorSpace_deref(SkColorSpace *color_space);
RAIA_API bool SkColorSpace_refCntGreaterThan(SkColorSpace *color_space, int32_t threadIsolatedTestCnt);
// static
RAIA_API sk_color_space_t SkColorSpace_MakeSRGB();
RAIA_API sk_color_space_t SkColorSpace_MakeSRGBLinear();
RAIA_API sk_color_space_t SkColorSpace_MakeRGB(const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ);
RAIA_API sk_color_space_t SkColorSpace_Make(const skcms_ICCProfile * profile);
RAIA_API sk_color_space_t SkColorSpace_Deserialize(const void *data, size_t length);
RAIA_API bool SkColorSpace_Equals(SkColorSpace *color_space_1, const SkColorSpace *color_space_2);
}

#endif //RAIA_SKIA_SK_COLOR_SPACE_H
