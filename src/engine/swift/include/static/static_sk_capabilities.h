//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CAPABILITIES_H
#define RAIA_SKIA_STATIC_SK_CAPABILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int const_sk_capabilities_t;

void static_const_sk_capabilities_delete(int key);
const void *static_const_sk_capabilities_get(int key); // -> const SkCapabilities *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_CAPABILITIES_H
