//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_YUVA_PIXMAPS_H
#define RAIA_SKIA_SK_YUVA_PIXMAPS_H

#ifdef __cplusplus
extern "C" {
#endif

// SkYUVAPixmaps & operator=(SkYUVAPixmaps &&that)
// SkYUVAPixmaps & operator=(const SkYUVAPixmaps &that)

void *SkYUVAPixmaps_new(); // () -> SkYUVAPixmaps *
void *SkYUVAPixmaps_new_2(const void *pixmaps); // (const SkYUVAPixmaps *pixmaps) -> SkYUVAPixmaps *
void SkYUVAPixmaps_delete(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps)
bool SkYUVAPixmaps_isValid(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> bool
const void * SkYUVAPixmaps_yuvaInfo(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> const SkYUVAInfo *
int SkYUVAPixmaps_dataType(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> SkYUVAPixmaps::DataType
int SkYUVAPixmaps_pixmapsInfo(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> sk_yuva_pixmap_info_t
int SkYUVAPixmaps_numPlanes(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> int
const void * SkYUVAPixmaps_planes(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> const std::array<SkPixmap, SkYUVAPixmaps::kMaxPlanes> *
const void * SkYUVAPixmaps_plane(void *yuva_pixmaps, int i); // (SkYUVAPixmaps *yuva_pixmaps, int i) -> const SkPixmap *
// SkYUVAInfo::YUVALocations SkYUVAPixmaps_toYUVALocations(SkYUVAPixmaps *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> SkYUVAInfo::YUVALocations
bool SkYUVAPixmaps_ownsStorage(void *yuva_pixmaps); // (SkYUVAPixmaps *yuva_pixmaps) -> bool

// static

int SkYUVAPixmaps_RecommendedRGBAColorType(int type); // (SkYUVAPixmaps::DataType type) -> SkColorType
int SkYUVAPixmaps_Allocate(const void *yuvaPixmapInfo); // (const SkYUVAPixmapInfo *yuvaPixmapInfo) -> sk_yuva_pixmaps_t
int SkYUVAPixmaps_FromData(const void *yuvaPixmapInfo, int data); // (const SkYUVAPixmapInfo *yuvaPixmapInfo, sk_data_t data) -> sk_yuva_pixmaps_t
int SkYUVAPixmaps_MakeCopy(const void *src); // (const SkYUVAPixmaps *src) -> sk_yuva_pixmaps_t
int SkYUVAPixmaps_FromExternalMemory(const void *yuvaPixmapInfo, void *memory); // (const SkYUVAPixmapInfo *yuvaPixmapInfo, void *memory) -> sk_yuva_pixmaps_t
int SkYUVAPixmaps_FromExternalPixmaps(const void *yuvaInfo, const void * pixmaps); // (const SkYUVAInfo *yuvaInfo, const SkPixmap pixmaps[4]) -> sk_yuva_pixmaps_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_YUVA_PIXMAPS_H
