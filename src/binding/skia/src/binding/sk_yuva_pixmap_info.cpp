//
// Created by dolphilia on 2024/01/11.
//

#include "sk_yuva_pixmap_info.h"

extern "C" {

// SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
// bool operator==(const SkYUVAPixmapInfo &)
// bool operator!=(const SkYUVAPixmapInfo &that)

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new() {
    return new SkYUVAPixmapInfo();
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_2(const SkYUVAInfo *info, const SkColorType type[4], const size_t rowBytes[4]) {
    return new SkYUVAPixmapInfo(*info, type, rowBytes);
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_3(const SkYUVAInfo *info, SkYUVAPixmapInfo::DataType type, const size_t rowBytes[4]) {
    return new SkYUVAPixmapInfo(*info, type, rowBytes);
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_4(const SkYUVAPixmapInfo *info) {
    return new SkYUVAPixmapInfo(*info);
}

void SkYUVAPixmapInfo_delete(SkYUVAPixmapInfo *yuvaPixmapInfo) {
    delete yuvaPixmapInfo;
}

const SkYUVAInfo * SkYUVAPixmapInfo_yuvaInfo(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return &yuva_pixmap_info->yuvaInfo();
}

SkYUVColorSpace SkYUVAPixmapInfo_yuvColorSpace(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->yuvColorSpace();
}

int SkYUVAPixmapInfo_numPlanes(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->numPlanes();
}

SkYUVAPixmapInfo::DataType SkYUVAPixmapInfo_dataType(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->dataType();
}

size_t SkYUVAPixmapInfo_rowBytes(SkYUVAPixmapInfo *yuva_pixmap_info, int i) {
    return yuva_pixmap_info->rowBytes(i);
}

const SkImageInfo * SkYUVAPixmapInfo_planeInfo(SkYUVAPixmapInfo *yuva_pixmap_info, int i) {
    return &yuva_pixmap_info->planeInfo(i);
}

size_t SkYUVAPixmapInfo_computeTotalBytes(SkYUVAPixmapInfo *yuva_pixmap_info, size_t planeSizes[SkYUVAPixmapInfo::kMaxPlanes]) {
    return yuva_pixmap_info->computeTotalBytes(planeSizes);
}

bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(SkYUVAPixmapInfo *yuva_pixmap_info, void *memory, SkPixmap pixmaps[SkYUVAPixmapInfo::kMaxPlanes]) {
    return yuva_pixmap_info->initPixmapsFromSingleAllocation(memory, pixmaps);
}

bool SkYUVAPixmapInfo_isValid(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->isValid();
}

bool SkYUVAPixmapInfo_isSupported(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo::SupportedDataTypes *type) {
    return yuva_pixmap_info->isSupported(*type);
}

// static

SkColorType SkYUVAPixmapInfo_DefaultColorTypeForDataType(SkYUVAPixmapInfo::DataType dataType, int numChannels) {
    return SkYUVAPixmapInfo::DefaultColorTypeForDataType(dataType, numChannels);
}

tuple_int_sk_yuva_pixmap_info_data_type_t SkYUVAPixmapInfo_NumChannelsAndDataType(SkColorType type) {
    return static_tuple_int_sk_yuva_pixmap_info_data_type_make(SkYUVAPixmapInfo::NumChannelsAndDataType(type));
}

}