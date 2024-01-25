//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_PIXMAPS_H
#define RAIA_SKIA_SK_YUVA_PIXMAPS_H

#include "include/core/SkYUVAPixmaps.h"
#include "../static/static_sk_yuva_pixmap_info.h"
#include "../static/static_sk_yuva_pixmaps.h"
#include "../static/static_sk_data.h"

extern "C" {
// SkYUVAPixmaps & operator=(SkYUVAPixmaps &&that)
// SkYUVAPixmaps & operator=(const SkYUVAPixmaps &that)
SkYUVAPixmaps *SkYUVAPixmaps_new();
SkYUVAPixmaps *SkYUVAPixmaps_new_2(const SkYUVAPixmaps *pixmaps);
void SkYUVAPixmaps_delete(SkYUVAPixmaps *yuva_pixmaps);
bool SkYUVAPixmaps_isValid(SkYUVAPixmaps *yuva_pixmaps);
const SkYUVAInfo * SkYUVAPixmaps_yuvaInfo(SkYUVAPixmaps *yuva_pixmaps);
SkYUVAPixmaps::DataType SkYUVAPixmaps_dataType(SkYUVAPixmaps *yuva_pixmaps);
int SkYUVAPixmaps_pixmapsInfo(SkYUVAPixmaps *yuva_pixmaps);
int SkYUVAPixmaps_numPlanes(SkYUVAPixmaps *yuva_pixmaps);
const std::array<SkPixmap, SkYUVAPixmaps::kMaxPlanes> * SkYUVAPixmaps_planes(SkYUVAPixmaps *yuva_pixmaps);
const SkPixmap * SkYUVAPixmaps_plane(SkYUVAPixmaps *yuva_pixmaps, int i);
//SkYUVAInfo::YUVALocations SkYUVAPixmaps_toYUVALocations(SkYUVAPixmaps *yuva_pixmaps);
bool SkYUVAPixmaps_ownsStorage(SkYUVAPixmaps *yuva_pixmaps);
// static
SkColorType SkYUVAPixmaps_RecommendedRGBAColorType(SkYUVAPixmaps::DataType type);
int SkYUVAPixmaps_Allocate(const SkYUVAPixmapInfo *yuvaPixmapInfo);
int SkYUVAPixmaps_FromData(int sk_data_key_in,
                            const SkYUVAPixmapInfo *yuvaPixmapInfo);
int SkYUVAPixmaps_MakeCopy(const SkYUVAPixmaps *src);
int SkYUVAPixmaps_FromExternalMemory(const SkYUVAPixmapInfo *yuvaPixmapInfo, void *memory);
int SkYUVAPixmaps_FromExternalPixmaps(const SkYUVAInfo *yuvaInfo,
                                       const SkPixmap pixmaps[4]);
}

#endif //RAIA_SKIA_SK_YUVA_PIXMAPS_H
