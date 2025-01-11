//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_R_RECT_H
#define RAIA_SKIA_STATIC_SK_R_RECT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRRect.h"
#include "export_api.h"

typedef int sk_r_rect_t;

extern "C" {
RAIA_API void static_sk_r_rect_delete(int key);
RAIA_API SkRRect * static_sk_r_rect_get_ptr(int key);
}

int static_sk_r_rect_make(SkRRect value);
SkRRect static_sk_r_rect_get(int key);
void static_sk_r_rect_set(int key, SkRRect value);

#endif //RAIA_SKIA_STATIC_SK_R_RECT_H
