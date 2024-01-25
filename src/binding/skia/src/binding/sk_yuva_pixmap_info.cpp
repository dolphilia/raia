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

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_3(const SkYUVAInfo *info, SkYUVAPixmapInfo::DataType type,
                                         const size_t rowBytes[4]) {
    return new SkYUVAPixmapInfo(*info, type, rowBytes);
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_4(const SkYUVAPixmapInfo *info) {
    return new SkYUVAPixmapInfo(*info);
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

void SkYUVAPixmapInfo_NumChannelsAndDataType(int tuple_int_sk_yuva_pixmap_info_data_type_key_out, SkColorType type) {
    static_tuple_int_sk_yuva_pixmap_info_data_type_set(tuple_int_sk_yuva_pixmap_info_data_type_key_out, SkYUVAPixmapInfo::NumChannelsAndDataType(type));
}

}