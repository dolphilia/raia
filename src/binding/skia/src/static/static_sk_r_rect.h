//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_R_RECT_H
#define RAIA_SKIA_STATIC_SK_R_RECT_H

#include <string>
#include <map>
#include "include/core/SkRRect.h"

void static_sk_r_rect_delete(int key);
SkRRect static_sk_r_rect_get(int key);
void static_sk_r_rect_set(int key, SkRRect value);

#endif //RAIA_SKIA_STATIC_SK_R_RECT_H
