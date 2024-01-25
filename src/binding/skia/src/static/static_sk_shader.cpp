//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_shader.h"

static std::map<int , sk_sp<SkShader>> static_sk_shader;

void static_sk_shader_delete(int key) {
    static_sk_shader[key].reset();
    static_sk_shader.erase(key);
}

SkShader *static_sk_shader_get(int key) {
    return static_sk_shader[key].get();
}

void static_sk_shader_set(int key, sk_sp<SkShader> value) {
    static_sk_shader[key] = std::move(value);
}

sk_sp<SkShader> static_sk_shader_move(int key) {
    return std::move(static_sk_shader[key]);
}