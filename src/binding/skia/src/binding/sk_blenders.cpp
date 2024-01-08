//
// Created by dolphilia on 2024/01/05.
//

#include "sk_blenders.h"

extern "C" {

void SkBlenders_Arithmetic(const char *sk_blender_key_out, float k1, float k2, float k3, float k4, bool enforcePremul) {
    static_sk_blender_set(sk_blender_key_out, SkBlenders::Arithmetic(k1, k2, k3, k4, enforcePremul));
}

}