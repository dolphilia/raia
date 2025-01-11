//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H

#include "include/core/SkYUVAPixmaps.h"
#include "../static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"
#include "export_api.h"

extern "C" {
// SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
// bool operator==(const SkYUVAPixmapInfo &)
// bool operator!=(const SkYUVAPixmapInfo &that)
RAIA_API SkYUVAPixmapInfo *SkYUVAPixmapInfo_new();
RAIA_API SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_2(const SkYUVAInfo *info, const SkColorType type[4], const size_t rowBytes[4]);
RAIA_API SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_3(const SkYUVAInfo *info, SkYUVAPixmapInfo::DataType type, const size_t rowBytes[4]);
RAIA_API SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_4(const SkYUVAPixmapInfo *info);
RAIA_API void SkYUVAPixmapInfo_delete(SkYUVAPixmapInfo *yuvaPixmapInfo);
RAIA_API const SkYUVAInfo * SkYUVAPixmapInfo_yuvaInfo(SkYUVAPixmapInfo *yuva_pixmap_info);
RAIA_API SkYUVColorSpace SkYUVAPixmapInfo_yuvColorSpace(SkYUVAPixmapInfo *yuva_pixmap_info);
RAIA_API int SkYUVAPixmapInfo_numPlanes(SkYUVAPixmapInfo *yuva_pixmap_info);
RAIA_API SkYUVAPixmapInfo::DataType SkYUVAPixmapInfo_dataType(SkYUVAPixmapInfo *yuva_pixmap_info);
RAIA_API size_t SkYUVAPixmapInfo_rowBytes(SkYUVAPixmapInfo *yuva_pixmap_info, int i);
RAIA_API const SkImageInfo * SkYUVAPixmapInfo_planeInfo(SkYUVAPixmapInfo *yuva_pixmap_info, int i);
RAIA_API size_t SkYUVAPixmapInfo_computeTotalBytes(SkYUVAPixmapInfo *yuva_pixmap_info, size_t planeSizes[SkYUVAPixmapInfo::kMaxPlanes]);
RAIA_API bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(SkYUVAPixmapInfo *yuva_pixmap_info, void *memory, SkPixmap pixmaps[SkYUVAPixmapInfo::kMaxPlanes]);
RAIA_API bool SkYUVAPixmapInfo_isValid(SkYUVAPixmapInfo *yuva_pixmap_info);
RAIA_API bool SkYUVAPixmapInfo_isSupported(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo::SupportedDataTypes *type);
// static
RAIA_API SkColorType SkYUVAPixmapInfo_DefaultColorTypeForDataType(SkYUVAPixmapInfo::DataType dataType, int numChannels);
RAIA_API tuple_int_sk_yuva_pixmap_info_data_type_t SkYUVAPixmapInfo_NumChannelsAndDataType(SkColorType type);
}

#endif //RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
