//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_space.h"

extern "C" {

void SkColorSpace_delete(SkColorSpace *color_space) {
    delete color_space;
}

void SkColorSpace_toProfile(SkColorSpace *color_space, skcms_ICCProfile *profile) {
    color_space->toProfile(profile);
}

bool SkColorSpace_gammaCloseToSRGB(SkColorSpace *color_space) {
    return color_space->gammaCloseToSRGB();
}

bool SkColorSpace_gammaIsLinear(SkColorSpace *color_space) {
    return color_space->gammaIsLinear();
}

bool SkColorSpace_isNumericalTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    return color_space->isNumericalTransferFn(fn);
}

bool SkColorSpace_toXYZD50(SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) {
    return color_space->toXYZD50(toXYZD50);
}

uint32_t SkColorSpace_toXYZD50Hash(SkColorSpace *color_space) {
    return color_space->toXYZD50Hash();
}

sk_color_space_t SkColorSpace_makeLinearGamma(SkColorSpace *color_space) {
    return static_sk_color_space_make(color_space->makeLinearGamma());
}

sk_color_space_t SkColorSpace_makeSRGBGamma(SkColorSpace *color_space) {
    return static_sk_color_space_make(color_space->makeSRGBGamma());
}

sk_color_space_t SkColorSpace_makeColorSpin(SkColorSpace *color_space) {
    return static_sk_color_space_make(color_space->makeColorSpin());
}

bool SkColorSpace_isSRGB(SkColorSpace *color_space) {
    return color_space->isSRGB();
}

sk_data_t SkColorSpace_serialize(SkColorSpace *color_space) {
    return static_sk_data_make(color_space->serialize());
}

size_t SkColorSpace_writeToMemory(SkColorSpace *color_space, void *memory) {
    return color_space->writeToMemory(memory);
}

void SkColorSpace_transferFn(SkColorSpace *color_space, float gabcdef[7]) {
    color_space->transferFn(gabcdef);
}

void SkColorSpace_transferFn_2(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    color_space->transferFn(fn);
}

void SkColorSpace_invTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    color_space->invTransferFn(fn);
}

void SkColorSpace_gamutTransformTo(SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst) {
    color_space->gamutTransformTo(dst, src_to_dst);
}

uint32_t SkColorSpace_transferFnHash(SkColorSpace *color_space) {
    return color_space->transferFnHash();
}

uint64_t SkColorSpace_hash(SkColorSpace *color_space) {
    return color_space->hash();
}

bool SkColorSpace_unique(SkColorSpace *color_space) {
    return color_space->unique();
}

void SkColorSpace_ref(SkColorSpace *color_space) {
    color_space->ref();
}

void SkColorSpace_unref(SkColorSpace *color_space) {
    color_space->unref();
}

void SkColorSpace_deref(SkColorSpace *color_space) {
    color_space->deref();
}

bool SkColorSpace_refCntGreaterThan(SkColorSpace *color_space, int32_t threadIsolatedTestCnt) {
    return color_space->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

sk_color_space_t SkColorSpace_MakeSRGB() {
    return static_sk_color_space_make(SkColorSpace::MakeSRGB());
}

sk_color_space_t SkColorSpace_MakeSRGBLinear() {
    return static_sk_color_space_make(SkColorSpace::MakeSRGBLinear());
}

sk_color_space_t SkColorSpace_MakeRGB(const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) {
    return static_sk_color_space_make(SkColorSpace::MakeRGB(*transferFn, *toXYZ));
}

sk_color_space_t SkColorSpace_Make(const skcms_ICCProfile * profile) {
    return static_sk_color_space_make(SkColorSpace::Make(*profile));
}

sk_color_space_t SkColorSpace_Deserialize(const void *data, size_t length) {
    return static_sk_color_space_make(SkColorSpace::Deserialize(data, length));
}

bool SkColorSpace_Equals(SkColorSpace *color_space_1, const SkColorSpace *color_space_2) {
    return SkColorSpace::Equals(color_space_1, color_space_2);
}

}