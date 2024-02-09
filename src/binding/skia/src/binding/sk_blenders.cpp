//
// Created by dolphilia on 2024/01/05.
//

#include "sk_blenders.h"

extern "C" {

sk_blender_t SkBlenders_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePremul) {
    return static_sk_blender_make(SkBlenders::Arithmetic(k1, k2, k3, k4, enforcePremul));
}

}