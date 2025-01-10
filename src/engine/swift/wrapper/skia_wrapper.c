#include "raia_skia_sk_bitmap.h"

void *my_SkBitmap_new() {
    return (void *)SkBitmap_new();
}

void my_SkBitmap_delete(void *bmp) {
    SkBitmap_delete((SkBitmap*)bmp);
}