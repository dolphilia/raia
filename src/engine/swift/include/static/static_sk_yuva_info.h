//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_INFO_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_yuva_info_t;
void static_sk_yuva_info_delete(int key);
void * static_sk_yuva_info_get_ptr(int key); // -> SkYUVAInfo *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_YUVA_INFO_H
