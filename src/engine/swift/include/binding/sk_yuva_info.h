//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_INFO_H
#define RAIA_SKIA_SK_YUVA_INFO_H

#include "include/core/SkYUVAInfo.h"
#include "../static/static_std_tuple_int_int.h"
#include "../static/static_sk_matrix.h"
#include "../static/static_sk_yuva_info.h"
#include "../static/static_sk_i_size.h"
#include "export_api.h"

extern "C" {
// SkYUVAInfo & operator=(const SkYUVAInfo &that)
// bool operator==(const SkYUVAInfo &that)
// bool operator!=(const SkYUVAInfo &that)
RAIA_API SkYUVAInfo *SkYUVAInfo_new();
RAIA_API SkYUVAInfo *SkYUVAInfo_new_2(const SkYUVAInfo *info);
RAIA_API SkYUVAInfo *SkYUVAInfo_new_3(sk_i_size_t dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY);
RAIA_API void SkYUVAInfo_delete(SkYUVAInfo *yuvaInfo);
RAIA_API SkYUVAInfo::PlaneConfig SkYUVAInfo_planeConfig(SkYUVAInfo * yuva_info);
RAIA_API SkYUVAInfo::Subsampling SkYUVAInfo_subsampling(SkYUVAInfo * yuva_info);
RAIA_API tuple_int_int_t SkYUVAInfo_planeSubsamplingFactors(SkYUVAInfo * yuva_info, int planeIdx);
RAIA_API sk_i_size_t SkYUVAInfo_dimensions(SkYUVAInfo * yuva_info);
RAIA_API int SkYUVAInfo_width(SkYUVAInfo * yuva_info);
RAIA_API int SkYUVAInfo_height(SkYUVAInfo * yuva_info);
RAIA_API SkYUVColorSpace SkYUVAInfo_yuvColorSpace(SkYUVAInfo * yuva_info);
RAIA_API SkYUVAInfo::Siting SkYUVAInfo_sitingX(SkYUVAInfo * yuva_info);
RAIA_API SkYUVAInfo::Siting SkYUVAInfo_sitingY(SkYUVAInfo * yuva_info);
RAIA_API SkEncodedOrigin SkYUVAInfo_origin(SkYUVAInfo * yuva_info);
RAIA_API sk_matrix_t SkYUVAInfo_originMatrix(SkYUVAInfo * yuva_info);
RAIA_API bool SkYUVAInfo_hasAlpha(SkYUVAInfo * yuva_info);
RAIA_API int SkYUVAInfo_planeDimensions(SkYUVAInfo * yuva_info, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]);
RAIA_API size_t SkYUVAInfo_computeTotalBytes(SkYUVAInfo * yuva_info, const size_t rowBytes[SkYUVAInfo::kMaxPlanes], size_t planeSizes[SkYUVAInfo::kMaxPlanes]);
RAIA_API int SkYUVAInfo_numPlanes(SkYUVAInfo * yuva_info);
RAIA_API int SkYUVAInfo_numChannelsInPlane(SkYUVAInfo * yuva_info, int i);
//SkYUVAInfo::YUVALocations SkYUVAInfo_toYUVALocations(SkYUVAInfo * yuva_info, const uint32_t *channelFlags);
RAIA_API sk_yuva_info_t SkYUVAInfo_makeSubsampling(SkYUVAInfo * yuva_info, SkYUVAInfo::Subsampling subsampling);
RAIA_API sk_yuva_info_t SkYUVAInfo_makeDimensions(SkYUVAInfo * yuva_info, sk_i_size_t size);
RAIA_API bool SkYUVAInfo_isValid(SkYUVAInfo * yuva_info);
// static
RAIA_API tuple_int_int_t SkYUVAInfo_SubsamplingFactors(SkYUVAInfo::Subsampling subsampling);
RAIA_API tuple_int_int_t SkYUVAInfo_PlaneSubsamplingFactors(SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx);
RAIA_API int SkYUVAInfo_PlaneDimensions(sk_i_size_t imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]);
RAIA_API int SkYUVAInfo_NumPlanes(SkYUVAInfo::PlaneConfig config);
RAIA_API int SkYUVAInfo_NumChannelsInPlane(SkYUVAInfo::PlaneConfig config, int i);
//SkYUVAInfo::YUVALocations SkYUVAInfo_GetYUVALocations(SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags);
RAIA_API bool SkYUVAInfo_HasAlpha(SkYUVAInfo::PlaneConfig config);
}

#endif //RAIA_SKIA_SK_YUVA_INFO_H
