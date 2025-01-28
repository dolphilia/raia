#ifndef STATIC_SK_SHADER_INTERNAL_H
#define STATIC_SK_SHADER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkShader.h"
int static_sk_shader_make(sk_sp<SkShader> value);
void static_sk_shader_set(int key, sk_sp<SkShader> value);
sk_sp<SkShader> static_sk_shader_move(int key);
#endif // STATIC_SK_SHADER_INTERNAL_H
