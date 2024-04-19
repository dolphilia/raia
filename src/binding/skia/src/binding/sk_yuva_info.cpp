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

SkYUVAInfo *SkYUVAInfo_new_3(sk_i_size_t dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY) {
    return new SkYUVAInfo(static_sk_i_size_get(dimensions), config, subsampling, space, origin, sitingX, sitingY);
}

void SkYUVAInfo_delete(SkYUVAInfo *yuvaInfo) {
    delete yuvaInfo;
}

SkYUVAInfo::PlaneConfig SkYUVAInfo_planeConfig(SkYUVAInfo * yuva_info) {
    return yuva_info->planeConfig();
}

SkYUVAInfo::Subsampling SkYUVAInfo_subsampling(SkYUVAInfo * yuva_info) {
    return yuva_info->subsampling();
}

tuple_int_int_t SkYUVAInfo_planeSubsamplingFactors(SkYUVAInfo * yuva_info, int planeIdx) {
    return static_tuple_int_int_make(yuva_info->planeSubsamplingFactors(planeIdx));
}

sk_i_size_t SkYUVAInfo_dimensions(SkYUVAInfo * yuva_info) {
    return static_sk_i_size_make(yuva_info->dimensions());
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

sk_matrix_t SkYUVAInfo_originMatrix(SkYUVAInfo * yuva_info) {
    return static_sk_matrix_make(yuva_info->originMatrix());
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

sk_yuva_info_t SkYUVAInfo_makeSubsampling(SkYUVAInfo * yuva_info, SkYUVAInfo::Subsampling subsampling) {
    return static_sk_yuva_info_make(yuva_info->makeSubsampling(subsampling));
}

sk_yuva_info_t SkYUVAInfo_makeDimensions(SkYUVAInfo * yuva_info, sk_i_size_t size) {
    return static_sk_yuva_info_make(yuva_info->makeDimensions(static_sk_i_size_get(size)));
}

bool SkYUVAInfo_isValid(SkYUVAInfo * yuva_info) {
    return yuva_info->isValid();
}

// static

tuple_int_int_t SkYUVAInfo_SubsamplingFactors(SkYUVAInfo::Subsampling subsampling) {
    return static_tuple_int_int_make(SkYUVAInfo::SubsamplingFactors(subsampling));
}

tuple_int_int_t SkYUVAInfo_PlaneSubsamplingFactors(SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx) {
    return static_tuple_int_int_make(SkYUVAInfo::PlaneSubsamplingFactors(config, subsampling, planeIdx));
}

int SkYUVAInfo_PlaneDimensions(sk_i_size_t imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) {
    return SkYUVAInfo::PlaneDimensions(static_sk_i_size_get(imageDimensions), plane, subsampling, origin, planeDimensions);
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