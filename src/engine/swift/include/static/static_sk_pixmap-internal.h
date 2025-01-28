#ifndef STATIC_SK_PIXMAP_INTERNAL_H
#define STATIC_SK_PIXMAP_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPixmap.h"
int static_sk_pixmap_make(SkPixmap value);
SkPixmap static_sk_pixmap_get(int key) ;
void static_sk_pixmap_set(int key, SkPixmap value);
#endif // STATIC_SK_PIXMAP_INTERNAL_H
