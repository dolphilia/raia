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

void SkYUVAPixmaps_pixmapsInfo(int sk_yuva_pixmap_info_key_out, SkYUVAPixmaps *yuva_pixmaps) {
    static_sk_yuva_pixmap_info_set(sk_yuva_pixmap_info_key_out, yuva_pixmaps->pixmapsInfo());
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

void SkYUVAPixmaps_Allocate(int sk_yuva_pixmaps_key_out, const SkYUVAPixmapInfo *yuvaPixmapInfo) {
    static_sk_yuva_pixmaps_set(sk_yuva_pixmaps_key_out, SkYUVAPixmaps::Allocate(*yuvaPixmapInfo));
}

void SkYUVAPixmaps_FromData(int sk_yuva_pixmaps_key_out, int sk_data_key_in,
                            const SkYUVAPixmapInfo *yuvaPixmapInfo) {
    static_sk_yuva_pixmaps_set(sk_yuva_pixmaps_key_out, SkYUVAPixmaps::FromData(*yuvaPixmapInfo, static_sk_data_move(sk_data_key_in)));
}

void SkYUVAPixmaps_MakeCopy(int sk_yuva_pixmaps_key_out, const SkYUVAPixmaps *src) {
    static_sk_yuva_pixmaps_set(sk_yuva_pixmaps_key_out, SkYUVAPixmaps::MakeCopy(*src));
}

void SkYUVAPixmaps_FromExternalMemory(int sk_yuva_pixmaps_key_out, const SkYUVAPixmapInfo *yuvaPixmapInfo, void *memory) {
    static_sk_yuva_pixmaps_set(sk_yuva_pixmaps_key_out, SkYUVAPixmaps::FromExternalMemory(*yuvaPixmapInfo, memory));
}

void SkYUVAPixmaps_FromExternalPixmaps(int sk_yuva_pixmaps_key_out, const SkYUVAInfo *yuvaInfo,
                                       const SkPixmap pixmaps[4]) {
    static_sk_yuva_pixmaps_set(sk_yuva_pixmaps_key_out, SkYUVAPixmaps::FromExternalPixmaps(*yuvaInfo, pixmaps));
}

}