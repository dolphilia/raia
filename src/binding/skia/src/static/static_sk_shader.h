//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SHADER_H
#define RAIA_SKIA_STATIC_SK_SHADER_H

#include <string>
#include <map>
#include "include/core/SkShader.h"

void static_sk_shader_delete(const char *key);
SkShader *static_sk_shader_get(const char *key);
void static_sk_shader_set(const char *key, sk_sp<SkShader> value);
sk_sp<SkShader> static_sk_shader_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_SHADER_H
