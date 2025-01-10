//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ICC_H
#define RAIA_SKIA_SK_ICC_H

#include "include/encode/SkICC.h"
#include "../static/static_sk_data.h"

extern "C" {
sk_data_t SkICC_SkWriteICCProfile(const skcms_TransferFunction* transferFunction, const skcms_Matrix3x3* toXYZD50);
const_sk_data_t SkICC_SkWriteICCProfile_2(const skcms_ICCProfile* iccProfile, const char* description);
void SkICC_SkICCFloatXYZD50ToGrid16Lab(const float* float_xyz, uint8_t* grid16_lab);
void SkICC_SkICCFloatToTable16(const float f, uint8_t* table_16);
}

#endif //RAIA_SKIA_SK_ICC_H
