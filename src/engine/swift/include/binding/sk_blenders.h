//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BLENDERS_H
#define RAIA_SKIA_SK_BLENDERS_H

#ifdef __cplusplus
extern "C" {
#endif

int SkBlenders_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePremul); // (float k1, float k2, float k3, float k4, bool enforcePremul) -> sk_blender_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_BLENDERS_H
