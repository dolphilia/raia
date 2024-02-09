//
// Created by dolphilia on 2024/02/01.
//

#include "sk_icc.h"

extern "C" {

sk_data_t SkICC_SkWriteICCProfile(const skcms_TransferFunction* transferFunction, const skcms_Matrix3x3* toXYZD50) {
    return static_sk_data_make(SkWriteICCProfile(*transferFunction, *toXYZD50));
}

const_sk_data_t SkICC_SkWriteICCProfile_2(const skcms_ICCProfile* iccProfile, const char* description) {
    return static_const_sk_data_make(SkWriteICCProfile(iccProfile, description));
}

void SkICC_SkICCFloatXYZD50ToGrid16Lab(const float* float_xyz, uint8_t* grid16_lab) {
    SkICCFloatXYZD50ToGrid16Lab(float_xyz, grid16_lab);
}

void SkICC_SkICCFloatToTable16(const float f, uint8_t* table_16) {
    SkICCFloatToTable16(f, table_16);
}

}