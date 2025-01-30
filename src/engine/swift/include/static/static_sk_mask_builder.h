//
// Created by dolphilia on 25/01/30.
//

#ifndef STATIC_SK_MASK_BUILDER_H
#define STATIC_SK_MASK_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_mask_builder_t;

void static_sk_mask_builder_delete(int key);
void * static_sk_mask_builder_get_ptr(int key);

#ifdef __cplusplus
}
#endif

#endif //STATIC_SK_MASK_BUILDER_H
