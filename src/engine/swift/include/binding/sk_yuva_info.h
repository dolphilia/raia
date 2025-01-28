//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_INFO_H
#define RAIA_SKIA_SK_YUVA_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

// SkYUVAInfo & operator=(const SkYUVAInfo &that)
// bool operator==(const SkYUVAInfo &that)
// bool operator!=(const SkYUVAInfo &that)

void *SkYUVAInfo_new(); // () -> SkYUVAInfo *
void *SkYUVAInfo_new_2(const void *info); // (const SkYUVAInfo *info) -> SkYUVAInfo *
void *SkYUVAInfo_new_3(int dimensions, int config, int subsampling, int space, int origin, int sitingX, int sitingY); // (sk_i_size_t dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY) -> SkYUVAInfo *
void SkYUVAInfo_delete(void *yuvaInfo); // (SkYUVAInfo *yuvaInfo)
int SkYUVAInfo_planeConfig(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkYUVAInfo::PlaneConfig
int SkYUVAInfo_subsampling(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkYUVAInfo::Subsampling
int SkYUVAInfo_planeSubsamplingFactors(void *yuva_info, int planeIdx); // (SkYUVAInfo *yuva_info, int planeIdx) -> tuple_int_int_t
int SkYUVAInfo_dimensions(void *yuva_info); // (SkYUVAInfo *yuva_info) -> sk_i_size_t
int SkYUVAInfo_width(void *yuva_info); // (SkYUVAInfo *yuva_info) -> int
int SkYUVAInfo_height(void *yuva_info); // (SkYUVAInfo *yuva_info) -> int
int SkYUVAInfo_yuvColorSpace(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkYUVColorSpace
int SkYUVAInfo_sitingX(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkYUVAInfo::Siting
int SkYUVAInfo_sitingY(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkYUVAInfo::Siting
int SkYUVAInfo_origin(void *yuva_info); // (SkYUVAInfo *yuva_info) -> SkEncodedOrigin
int SkYUVAInfo_originMatrix(void *yuva_info); // (SkYUVAInfo *yuva_info) -> sk_matrix_t
bool SkYUVAInfo_hasAlpha(void *yuva_info); // (SkYUVAInfo *yuva_info) -> bool
int SkYUVAInfo_planeDimensions(void *yuva_info, void * planeDimensions); // (SkYUVAInfo *yuva_info, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) -> int
unsigned long SkYUVAInfo_computeTotalBytes(void *yuva_info, const void * rowBytes, void * planeSizes); // (SkYUVAInfo *yuva_info, const size_t rowBytes[SkYUVAInfo::kMaxPlanes], size_t planeSizes[SkYUVAInfo::kMaxPlanes]) -> size_t
int SkYUVAInfo_numPlanes(void *yuva_info); // (SkYUVAInfo *yuva_info) -> int
int SkYUVAInfo_numChannelsInPlane(void *yuva_info, int i); // (SkYUVAInfo *yuva_info, int i) -> int
// SkYUVAInfo::YUVALocations SkYUVAInfo_toYUVALocations(SkYUVAInfo *yuva_info, const uint32_t *channelFlags); // (SkYUVAInfo *yuva_info, const uint32_t *channelFlags) -> SkYUVAInfo::YUVALocations
int SkYUVAInfo_makeSubsampling(void *yuva_info, int subsampling); // (SkYUVAInfo *yuva_info, SkYUVAInfo::Subsampling subsampling) -> sk_yuva_info_t
int SkYUVAInfo_makeDimensions(void *yuva_info, int size); // (SkYUVAInfo *yuva_info, sk_i_size_t size) -> sk_yuva_info_t
bool SkYUVAInfo_isValid(void *yuva_info); // (SkYUVAInfo *yuva_info) -> bool

// static

int SkYUVAInfo_SubsamplingFactors(int subsampling); // (SkYUVAInfo::Subsampling subsampling) -> tuple_int_int_t
int SkYUVAInfo_PlaneSubsamplingFactors(int config, int subsampling, int planeIdx); // (SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx) -> tuple_int_int_t
int SkYUVAInfo_PlaneDimensions(int imageDimensions, int plane, int subsampling, int origin, void * planeDimensions); // (sk_i_size_t imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) -> int
int SkYUVAInfo_NumPlanes(int config); // (SkYUVAInfo::PlaneConfig config) -> int
int SkYUVAInfo_NumChannelsInPlane(int config, int i); // (SkYUVAInfo::PlaneConfig config, int i) -> int
// SkYUVAInfo::YUVALocations SkYUVAInfo_GetYUVALocations(SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags); // (SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags) -> SkYUVAInfo::YUVALocations
bool SkYUVAInfo_HasAlpha(int config); // (SkYUVAInfo::PlaneConfig config) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_YUVA_INFO_H
