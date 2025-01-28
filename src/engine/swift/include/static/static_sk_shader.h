//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SHADER_H
#define RAIA_SKIA_STATIC_SK_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_shader_t;
void static_sk_shader_delete(int key);
void * static_sk_shader_get(int key); // -> SkShader *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_SHADER_H
