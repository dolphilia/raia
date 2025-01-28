//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
#define RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

// SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
// bool operator==(const SkYUVAPixmapInfo &)
// bool operator!=(const SkYUVAPixmapInfo &that)

void * SkYUVAPixmapInfo_new(); // () -> SkYUVAPixmapInfo *
void * SkYUVAPixmapInfo_new_2(const void *info, const void * type, const void * rowBytes); // (const SkYUVAInfo *info, const SkColorType type[4], const size_t rowBytes[4]) -> SkYUVAPixmapInfo *
void * SkYUVAPixmapInfo_new_3(const void *info, int type, const void * rowBytes); // (const SkYUVAInfo *info, SkYUVAPixmapInfo::DataType type, const size_t rowBytes[4]) -> SkYUVAPixmapInfo *
void * SkYUVAPixmapInfo_new_4(const void *info); // (const SkYUVAPixmapInfo *info) -> SkYUVAPixmapInfo *
void SkYUVAPixmapInfo_delete(void *yuvaPixmapInfo); // (SkYUVAPixmapInfo *yuvaPixmapInfo)
const void * SkYUVAPixmapInfo_yuvaInfo(void *yuva_pixmap_info); // (SkYUVAPixmapInfo *yuva_pixmap_info) -> const SkYUVAInfo *
int SkYUVAPixmapInfo_yuvColorSpace(void *yuva_pixmap_info); // (SkYUVAPixmapInfo *yuva_pixmap_info) -> SkYUVColorSpace
int SkYUVAPixmapInfo_numPlanes(void *yuva_pixmap_info); // (SkYUVAPixmapInfo *yuva_pixmap_info) -> int
int SkYUVAPixmapInfo_dataType(void *yuva_pixmap_info); // (SkYUVAPixmapInfo *yuva_pixmap_info) -> SkYUVAPixmapInfo::DataType
unsigned long SkYUVAPixmapInfo_rowBytes(void *yuva_pixmap_info, int i); // (SkYUVAPixmapInfo *yuva_pixmap_info, int i) -> size_t
const void * SkYUVAPixmapInfo_planeInfo(void *yuva_pixmap_info, int i); // (SkYUVAPixmapInfo *yuva_pixmap_info, int i) -> const SkImageInfo *
unsigned long SkYUVAPixmapInfo_computeTotalBytes(void *yuva_pixmap_info, void * planeSizes); // (SkYUVAPixmapInfo *yuva_pixmap_info, size_t planeSizes[SkYUVAPixmapInfo::kMaxPlanes]) -> size_t
bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(void *yuva_pixmap_info, void *memory, void * pixmaps); // (SkYUVAPixmapInfo *yuva_pixmap_info, void *memory, SkPixmap pixmaps[SkYUVAPixmapInfo::kMaxPlanes]) -> bool
bool SkYUVAPixmapInfo_isValid(void *yuva_pixmap_info); // (SkYUVAPixmapInfo *yuva_pixmap_info) -> bool
bool SkYUVAPixmapInfo_isSupported(void *yuva_pixmap_info, const void *type); // (SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo::SupportedDataTypes *type) -> bool

// static

int SkYUVAPixmapInfo_DefaultColorTypeForDataType(int dataType, int numChannels); // (SkYUVAPixmapInfo::DataType dataType, int numChannels) -> SkColorType
int SkYUVAPixmapInfo_NumChannelsAndDataType(int type); // (SkColorType type) -> tuple_int_sk_yuva_pixmap_info_data_type_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_YUVA_PIXMAP_INFO_H
