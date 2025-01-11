//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ICC_H
#define RAIA_SKIA_SK_ICC_H

#include "include/encode/SkICC.h"
#include "../static/static_sk_data.h"
#include "export_api.h"

extern "C" {
RAIA_API sk_data_t SkICC_SkWriteICCProfile(const skcms_TransferFunction* transferFunction, const skcms_Matrix3x3* toXYZD50);
RAIA_API const_sk_data_t SkICC_SkWriteICCProfile_2(const skcms_ICCProfile* iccProfile, const char* description);
RAIA_API void SkICC_SkICCFloatXYZD50ToGrid16Lab(const float* float_xyz, uint8_t* grid16_lab);
RAIA_API void SkICC_SkICCFloatToTable16(const float f, uint8_t* table_16);
}

#endif //RAIA_SKIA_SK_ICC_H
