//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_shader.h"

#include <utility>

static std::map<int , sk_sp<SkShader>> static_sk_shader;
static int static_sk_shader_index = 0;

int static_sk_shader_make(sk_sp<SkShader> value) {
    static_sk_shader[static_sk_shader_index] = std::move(value);
    static_sk_shader_index++;
    return static_sk_shader_index - 1;
}

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