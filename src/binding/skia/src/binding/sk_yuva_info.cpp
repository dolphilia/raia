//
// Created by dolphilia on 2024/01/11.
//

#include "sk_yuva_info.h"

extern "C" {

// SkYUVAInfo & operator=(const SkYUVAInfo &that)
// bool operator==(const SkYUVAInfo &that)
// bool operator!=(const SkYUVAInfo &that)

SkYUVAInfo *SkYUVAInfo_new() {
    return new SkYUVAInfo();
}

SkYUVAInfo *SkYUVAInfo_new_2(const SkYUVAInfo *info) {
    return new SkYUVAInfo(*info);
}

SkYUVAInfo *SkYUVAInfo_new_3(SkISize dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY) {
    return new SkYUVAInfo(dimensions, config, subsampling, space, origin, sitingX, sitingY);
}

SkYUVAInfo::PlaneConfig SkYUVAInfo_planeConfig(SkYUVAInfo * yuva_info) {
    return yuva_info->planeConfig();
}

SkYUVAInfo::Subsampling SkYUVAInfo_subsampling(SkYUVAInfo * yuva_info) {
    return yuva_info->subsampling();
}

void SkYUVAInfo_planeSubsamplingFactors(const char *tuple_int_int_key_out, SkYUVAInfo * yuva_info, int planeIdx) {
    static_tuple_int_int_set(tuple_int_int_key_out, yuva_info->planeSubsamplingFactors(planeIdx));
}

SkISize SkYUVAInfo_dimensions(SkYUVAInfo * yuva_info) {
    return yuva_info->dimensions();
}

int SkYUVAInfo_width(SkYUVAInfo * yuva_info) {
    return yuva_info->width();
}

int SkYUVAInfo_height(SkYUVAInfo * yuva_info) {
    return yuva_info->height();
}

SkYUVColorSpace SkYUVAInfo_yuvColorSpace(SkYUVAInfo * yuva_info) {
    return yuva_info->yuvColorSpace();
}

SkYUVAInfo::Siting SkYUVAInfo_sitingX(SkYUVAInfo * yuva_info) {
    return yuva_info->sitingX();
}

SkYUVAInfo::Siting SkYUVAInfo_sitingY(SkYUVAInfo * yuva_info) {
    return yuva_info->sitingY();
}

SkEncodedOrigin SkYUVAInfo_origin(SkYUVAInfo * yuva_info) {
    return yuva_info->origin();
}

void SkYUVAInfo_originMatrix(const char *sk_matrix_key_out, SkYUVAInfo * yuva_info) {
    static_sk_matrix_set(sk_matrix_key_out, yuva_info->originMatrix());
}

bool SkYUVAInfo_hasAlpha(SkYUVAInfo * yuva_info) {
    return yuva_info->hasAlpha();
}

int SkYUVAInfo_planeDimensions(SkYUVAInfo * yuva_info, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) {
    return yuva_info->planeDimensions(planeDimensions);
}

size_t SkYUVAInfo_computeTotalBytes(SkYUVAInfo * yuva_info, const size_t rowBytes[SkYUVAInfo::kMaxPlanes], size_t planeSizes[SkYUVAInfo::kMaxPlanes]) {
    return yuva_info->computeTotalBytes(rowBytes, planeSizes);
}

int SkYUVAInfo_numPlanes(SkYUVAInfo * yuva_info) {
    return yuva_info->numPlanes();
}

int SkYUVAInfo_numChannelsInPlane(SkYUVAInfo * yuva_info, int i) {
    return yuva_info->numChannelsInPlane(i);
}

//SkYUVAInfo::YUVALocations SkYUVAInfo_toYUVALocations(SkYUVAInfo * yuva_info, const uint32_t *channelFlags) {
//    return yuva_info->toYUVALocations(channelFlags);
//}

void SkYUVAInfo_makeSubsampling(const char *sk_yuva_info_key_out, SkYUVAInfo * yuva_info, SkYUVAInfo::Subsampling subsampling) {
    static_sk_yuva_info_set(sk_yuva_info_key_out, yuva_info->makeSubsampling(subsampling));
}

void SkYUVAInfo_makeDimensions(const char *sk_yuva_info_key_out, SkYUVAInfo * yuva_info, SkISize size) {
    static_sk_yuva_info_set(sk_yuva_info_key_out, yuva_info->makeDimensions(size));
}

bool SkYUVAInfo_isValid(SkYUVAInfo * yuva_info) {
    return yuva_info->isValid();
}

// static

void SkYUVAInfo_SubsamplingFactors(const char *tuple_int_int_key_out, SkYUVAInfo::Subsampling subsampling) {
    static_tuple_int_int_set(tuple_int_int_key_out, SkYUVAInfo::SubsamplingFactors(subsampling));
}

void SkYUVAInfo_PlaneSubsamplingFactors(const char *tuple_int_int_key_out, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx) {
    static_tuple_int_int_set(tuple_int_int_key_out, SkYUVAInfo::PlaneSubsamplingFactors(config, subsampling, planeIdx));
}

int SkYUVAInfo_PlaneDimensions(SkISize imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) {
    return SkYUVAInfo::PlaneDimensions(imageDimensions, plane, subsampling, origin, planeDimensions);
}

int SkYUVAInfo_NumPlanes(SkYUVAInfo::PlaneConfig config) {
    return SkYUVAInfo::NumPlanes(config);
}

int SkYUVAInfo_NumChannelsInPlane(SkYUVAInfo::PlaneConfig config, int i) {
    return SkYUVAInfo::NumChannelsInPlane(config, i);
}

//SkYUVAInfo::YUVALocations SkYUVAInfo_GetYUVALocations(SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags) {
//    return SkYUVAInfo::GetYUVALocations(config, planeChannelFlags);
//}

bool SkYUVAInfo_HasAlpha(SkYUVAInfo::PlaneConfig config) {
    return SkYUVAInfo::HasAlpha(config);
}

}