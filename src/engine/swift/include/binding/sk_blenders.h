//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BLENDERS_H
#define RAIA_SKIA_SK_BLENDERS_H

#include "include/effects/SkBlenders.h"
#include "../static/static_sk_blender.h"
#include "export_api.h"

extern "C" {
RAIA_API sk_blender_t SkBlenders_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePremul);
}

#endif //RAIA_SKIA_SK_BLENDERS_H
