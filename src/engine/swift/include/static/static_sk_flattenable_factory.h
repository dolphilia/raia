//
// Created by dolphilia on 2024/04/02.
//

#ifndef RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
#define RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_flattenable_factory_t;
void static_sk_flattenable_factory_delete(int key);
void * static_sk_flattenable_factory_get_ptr(int key);
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
