//
// Created by dolphilia on 2024/01/11.
//

#include "sk_yuva_pixmaps.h"

extern "C" {

// SkYUVAPixmaps & operator=(SkYUVAPixmaps &&that)
// SkYUVAPixmaps & operator=(const SkYUVAPixmaps &that)

SkYUVAPixmaps *SkYUVAPixmaps_new() {
    return new SkYUVAPixmaps();
}

SkYUVAPixmaps *SkYUVAPixmaps_new_2(const SkYUVAPixmaps *pixmaps) {
    return new SkYUVAPixmaps(*pixmaps);
}

void SkYUVAPixmaps_delete(SkYUVAPixmaps *yuva_pixmaps) {
    delete yuva_pixmaps;
}

bool SkYUVAPixmaps_isValid(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->isValid();
}

const SkYUVAInfo * SkYUVAPixmaps_yuvaInfo(SkYUVAPixmaps *yuva_pixmaps) {
    return &yuva_pixmaps->yuvaInfo();
}

SkYUVAPixmaps::DataType SkYUVAPixmaps_dataType(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->dataType();
}

int SkYUVAPixmaps_pixmapsInfo(SkYUVAPixmaps *yuva_pixmaps) {
    return static_sk_yuva_pixmap_info_make(yuva_pixmaps->pixmapsInfo());
}

int SkYUVAPixmaps_numPlanes(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->numPlanes();
}

const std::array<SkPixmap, SkYUVAPixmaps::kMaxPlanes> * SkYUVAPixmaps_planes(SkYUVAPixmaps *yuva_pixmaps) {
    return &yuva_pixmaps->planes();
}

const SkPixmap * SkYUVAPixmaps_plane(SkYUVAPixmaps *yuva_pixmaps, int i) {
    return &yuva_pixmaps->plane(i);
}

//SkYUVAInfo::YUVALocations SkYUVAPixmaps_toYUVALocations(SkYUVAPixmaps *yuva_pixmaps) {
//    return yuva_pixmaps->toYUVALocations();
//}

bool SkYUVAPixmaps_ownsStorage(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->ownsStorage();
}

// static

SkColorType SkYUVAPixmaps_RecommendedRGBAColorType(SkYUVAPixmaps::DataType type) {
    return SkYUVAPixmaps::RecommendedRGBAColorType(type);
}

int SkYUVAPixmaps_Allocate(const SkYUVAPixmapInfo *yuvaPixmapInfo) {
    return static_sk_yuva_pixmaps_make(SkYUVAPixmaps::Allocate(*yuvaPixmapInfo));
}

int SkYUVAPixmaps_FromData(int sk_data_key_in,
                            const SkYUVAPixmapInfo *yuvaPixmapInfo) {
    return static_sk_yuva_pixmaps_make(SkYUVAPixmaps::FromData(*yuvaPixmapInfo, static_sk_data_move(sk_data_key_in)));
}

int SkYUVAPixmaps_MakeCopy(const SkYUVAPixmaps *src) {
    return static_sk_yuva_pixmaps_make(SkYUVAPixmaps::MakeCopy(*src));
}

int SkYUVAPixmaps_FromExternalMemory(const SkYUVAPixmapInfo *yuvaPixmapInfo, void *memory) {
    return static_sk_yuva_pixmaps_make(SkYUVAPixmaps::FromExternalMemory(*yuvaPixmapInfo, memory));
}

int SkYUVAPixmaps_FromExternalPixmaps(const SkYUVAInfo *yuvaInfo,
                                       const SkPixmap pixmaps[4]) {
    return static_sk_yuva_pixmaps_make(SkYUVAPixmaps::FromExternalPixmaps(*yuvaInfo, pixmaps));
}

}