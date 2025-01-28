//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ICC_H
#define RAIA_SKIA_SK_ICC_H

#ifdef __cplusplus
extern "C" {
#endif

int SkICC_SkWriteICCProfile(const void * transferFunction, const void * toXYZD50); // (const skcms_TransferFunction* transferFunction, const skcms_Matrix3x3* toXYZD50) -> sk_data_t
int SkICC_SkWriteICCProfile_2(const void * iccProfile, const char* description); // (const skcms_ICCProfile* iccProfile, const char* description) -> const_sk_data_t
void SkICC_SkICCFloatXYZD50ToGrid16Lab(const float* float_xyz, void * grid16_lab); // (const float* float_xyz, uint8_t* grid16_lab)
void SkICC_SkICCFloatToTable16(const float f, void * table_16); // (const float f, uint8_t* table_16)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_ICC_H
