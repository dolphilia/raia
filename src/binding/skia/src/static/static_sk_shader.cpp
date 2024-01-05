//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_shader.h"

static std::map<std::string, sk_sp<SkShader>> static_sk_shader;

void static_sk_shader_delete(const char *key) {
    static_sk_shader[key].reset();
    static_sk_shader.erase(key);
}

SkShader *static_sk_shader_get(const char *key) {
    return static_sk_shader[key].get();
}

void static_sk_shader_set(const char *key, sk_sp<SkShader> value) {
    static_sk_shader[key] = std::move(value);
}

sk_sp<SkShader> static_sk_shader_move(const char *key) {
    return std::move(static_sk_shader[key]);
}