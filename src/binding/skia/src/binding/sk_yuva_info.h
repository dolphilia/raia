//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_INFO_H
#define RAIA_SKIA_SK_YUVA_INFO_H

#include "include/core/SkYUVAInfo.h"
#include "../static/static_std_tuple_int_int.h"
#include "../static/static_sk_matrix.h"
#include "../static/static_sk_yuva_info.h"

extern "C" {
// SkYUVAInfo & operator=(const SkYUVAInfo &that)
// bool operator==(const SkYUVAInfo &that)
// bool operator!=(const SkYUVAInfo &that)
SkYUVAInfo *SkYUVAInfo_new();
SkYUVAInfo *SkYUVAInfo_new_2(const SkYUVAInfo *info);
SkYUVAInfo *SkYUVAInfo_new_3(SkISize dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY);
SkYUVAInfo::PlaneConfig SkYUVAInfo_planeConfig(SkYUVAInfo * yuva_info);
SkYUVAInfo::Subsampling SkYUVAInfo_subsampling(SkYUVAInfo * yuva_info);
void SkYUVAInfo_planeSubsamplingFactors(int tuple_int_int_key_out, SkYUVAInfo * yuva_info, int planeIdx);
SkISize SkYUVAInfo_dimensions(SkYUVAInfo * yuva_info);
int SkYUVAInfo_width(SkYUVAInfo * yuva_info);
int SkYUVAInfo_height(SkYUVAInfo * yuva_info);
SkYUVColorSpace SkYUVAInfo_yuvColorSpace(SkYUVAInfo * yuva_info);
SkYUVAInfo::Siting SkYUVAInfo_sitingX(SkYUVAInfo * yuva_info);
SkYUVAInfo::Siting SkYUVAInfo_sitingY(SkYUVAInfo * yuva_info);
SkEncodedOrigin SkYUVAInfo_origin(SkYUVAInfo * yuva_info);
void SkYUVAInfo_originMatrix(int sk_matrix_key_out, SkYUVAInfo * yuva_info);
bool SkYUVAInfo_hasAlpha(SkYUVAInfo * yuva_info);
int SkYUVAInfo_planeDimensions(SkYUVAInfo * yuva_info, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]);
size_t SkYUVAInfo_computeTotalBytes(SkYUVAInfo * yuva_info, const size_t rowBytes[SkYUVAInfo::kMaxPlanes], size_t planeSizes[SkYUVAInfo::kMaxPlanes]);
int SkYUVAInfo_numPlanes(SkYUVAInfo * yuva_info);
int SkYUVAInfo_numChannelsInPlane(SkYUVAInfo * yuva_info, int i);
//SkYUVAInfo::YUVALocations SkYUVAInfo_toYUVALocations(SkYUVAInfo * yuva_info, const uint32_t *channelFlags);
void SkYUVAInfo_makeSubsampling(int sk_yuva_info_key_out, SkYUVAInfo * yuva_info, SkYUVAInfo::Subsampling subsampling);
void SkYUVAInfo_makeDimensions(int sk_yuva_info_key_out, SkYUVAInfo * yuva_info, SkISize size);
bool SkYUVAInfo_isValid(SkYUVAInfo * yuva_info);
// static
void SkYUVAInfo_SubsamplingFactors(int tuple_int_int_key_out, SkYUVAInfo::Subsampling subsampling);
void SkYUVAInfo_PlaneSubsamplingFactors(int tuple_int_int_key_out, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx);
int SkYUVAInfo_PlaneDimensions(SkISize imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]);
int SkYUVAInfo_NumPlanes(SkYUVAInfo::PlaneConfig config);
int SkYUVAInfo_NumChannelsInPlane(SkYUVAInfo::PlaneConfig config, int i);
//SkYUVAInfo::YUVALocations SkYUVAInfo_GetYUVALocations(SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags);
bool SkYUVAInfo_HasAlpha(SkYUVAInfo::PlaneConfig config);
}

#endif //RAIA_SKIA_SK_YUVA_INFO_H
