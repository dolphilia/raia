#ifndef STATIC_SK_YUVA_PIXMAP_INFO_INTERNAL_H
#define STATIC_SK_YUVA_PIXMAP_INFO_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkYUVAPixmaps.h"
int static_sk_yuva_pixmap_info_make(SkYUVAPixmapInfo value);
SkYUVAPixmapInfo static_sk_yuva_pixmap_info_get_entity(int key);
void static_sk_yuva_pixmap_info_set(int key, SkYUVAPixmapInfo value);
#endif // STATIC_SK_YUVA_PIXMAP_INFO_INTERNAL_H
