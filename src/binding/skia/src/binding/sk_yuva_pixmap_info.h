//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H

#include "include/core/SkYUVAPixmaps.h"
#include "../static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"

extern "C" {
// SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
// bool operator==(const SkYUVAPixmapInfo &)
// bool operator!=(const SkYUVAPixmapInfo &that)
SkYUVAPixmapInfo *SkYUVAPixmapInfo_new();
SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_2(const SkYUVAInfo *info, const SkColorType type[4], const size_t rowBytes[4]);
SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_3(const SkYUVAInfo *info, SkYUVAPixmapInfo::DataType type, const size_t rowBytes[4]);
SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_4(const SkYUVAPixmapInfo *info);
void SkYUVAPixmapInfo_delete(SkYUVAPixmapInfo *yuvaPixmapInfo);
const SkYUVAInfo * SkYUVAPixmapInfo_yuvaInfo(SkYUVAPixmapInfo *yuva_pixmap_info);
SkYUVColorSpace SkYUVAPixmapInfo_yuvColorSpace(SkYUVAPixmapInfo *yuva_pixmap_info);
int SkYUVAPixmapInfo_numPlanes(SkYUVAPixmapInfo *yuva_pixmap_info);
SkYUVAPixmapInfo::DataType SkYUVAPixmapInfo_dataType(SkYUVAPixmapInfo *yuva_pixmap_info);
size_t SkYUVAPixmapInfo_rowBytes(SkYUVAPixmapInfo *yuva_pixmap_info, int i);
const SkImageInfo * SkYUVAPixmapInfo_planeInfo(SkYUVAPixmapInfo *yuva_pixmap_info, int i);
size_t SkYUVAPixmapInfo_computeTotalBytes(SkYUVAPixmapInfo *yuva_pixmap_info, size_t planeSizes[SkYUVAPixmapInfo::kMaxPlanes]);
bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(SkYUVAPixmapInfo *yuva_pixmap_info, void *memory, SkPixmap pixmaps[SkYUVAPixmapInfo::kMaxPlanes]);
bool SkYUVAPixmapInfo_isValid(SkYUVAPixmapInfo *yuva_pixmap_info);
bool SkYUVAPixmapInfo_isSupported(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo::SupportedDataTypes *type);
// static
SkColorType SkYUVAPixmapInfo_DefaultColorTypeForDataType(SkYUVAPixmapInfo::DataType dataType, int numChannels);
tuple_int_sk_yuva_pixmap_info_data_type_t SkYUVAPixmapInfo_NumChannelsAndDataType(SkColorType type);
}

#endif //RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
