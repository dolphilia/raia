//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MASK_FILTER_H
#define RAIA_SKIA_STATIC_SK_MASK_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_mask_filter_t;
void static_sk_mask_filter_delete(int key);
void *static_sk_mask_filter_get_ptr(int key); // -> SkMaskFilter *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_MASK_FILTER_H
